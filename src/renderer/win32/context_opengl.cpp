/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

															ooooooooo.                               .o8
															`888   `Y88.                            "888
															 888   .d88'  .ooooo.  ooo. .oo.    .oooo888   .ooooo.  oooo d8b  .ooooo.  oooo d8b
															 888ooo88P'  d88' `88b `888P"Y88b  d88' `888  d88' `88b `888""8P d88' `88b `888""8P
															 888`88b.    888ooo888  888   888  888   888  888ooo888  888     888ooo888  888
															 888  `88b.  888    .o  888   888  888   888  888    .o  888     888    .o  888
															o888o  o888o `Y8bod8P' o888o o888o `Y8bod88P" `Y8bod8P' d888b    `Y8bod8P' d888b



				This file is part of EdenCraft Engine - Renderer module.
				Copyright(C) 2018 Pierre Casati (@IsilinBN)

				This program is free software : you can redistribute it and/or modify
				it under the terms of the GNU General Public License as published by
				the Free Software Foundation, either version 3 of the License, or
				(at your option) any later version.

				This program is distributed in the hope that it will be useful,
				but WITHOUT ANY WARRANTY; without even the implied warranty of
				MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
				GNU General Public License for more details.

				You should have received a copy of the GNU General Public License
				along with this program.If not, see <http://www.gnu.org/licenses/>.

*/

#include "renderer/opengl/context_opengl.hpp"
#include "renderer/win32/data_context_opengl.hpp"

#include "renderer/opengl/opengl.hpp"
#include "renderer/win32/wgl_extension.hpp"
#include "renderer/rendering/render_window.hpp"
#include "window/common/window_adapter.hpp"
#include "window/win32/data_window_adapter.hpp"
#include "utility/log/service_logger.hpp"

namespace ece
{
	namespace renderer
	{
		namespace opengl
		{
			using utility::log::ServiceLoggerLocator;
			using utility::debug::AssertionException;
			using utility::pattern::makePimpl;

			HMODULE DataContextOpenGL::_openglLib = nullptr;

			FARPROC DataContextOpenGL::getProcAddress(const std::string & name)
			{
				return GetProcAddress(DataContextOpenGL::_openglLib, name.data());
			}

			ContextOpenGL::ContextOpenGL() noexcept : RenderContext(), _data(makePimpl<DataContextOpenGL>(nullptr, nullptr, nullptr)), _currentVersion()
			{
			}

			ContextOpenGL::~ContextOpenGL() noexcept
			{
				if (this->_data->_context != nullptr) {
					if (this->isCurrent()) {
						wglMakeCurrent(nullptr, nullptr);
					}
					wglDeleteContext(this->_data->_context);
					this->_data->_context = nullptr;
				}
				if (this->_data->_device != nullptr) {
					ReleaseDC(this->_data->_windowHandle, this->_data->_device);
					this->_data->_device = nullptr;
				}
				this->_data->_windowHandle = nullptr;
			}

			void ContextOpenGL::createOldContext()
			{
				this->_data->_windowHandle = CreateWindow(L"Static", L"", WS_DISABLED, 0, 0, 1, 1, nullptr, nullptr, nullptr, nullptr);
				this->_data->_device = GetDC(this->_data->_windowHandle);
				if (!this->_data->_device) {
					throw std::runtime_error("OpenGL cannot be initialized beacause no device is currently available.");
				}

				PIXELFORMATDESCRIPTOR pixelFormat;
				ZeroMemory(&pixelFormat, sizeof(pixelFormat));
				pixelFormat.nSize = sizeof(pixelFormat);
				pixelFormat.nVersion = 1;
				pixelFormat.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
				pixelFormat.iPixelType = PFD_TYPE_RGBA;
				pixelFormat.cColorBits = 24;

				if (!ChoosePixelFormat(this->_data->_device, &pixelFormat)) {
					throw std::runtime_error("No pixel format choosen for OpenGL dummy context.");
				}

				if (!SetPixelFormat(this->_data->_device, 1, &pixelFormat)) {
					throw std::runtime_error("OpenGL cannot be initialized because no video mode fit with.");
				}

				this->_data->_context = wglCreateContext(this->_data->_device);
				if (!this->_data->_context) {
					throw std::runtime_error("OpenGL cannot be initialized because it is not possible to create a context.");
				}
				if (!wglMakeCurrent(this->_data->_device, this->_data->_context)) {
					throw std::runtime_error("OpenGL cannot be initialized because it is not possible to use a context.");
				}

				if (DataContextOpenGL::_openglLib == nullptr) {
					DataContextOpenGL::_openglLib = LoadLibrary(L"opengl32.dll");
					// TODO: it is never correctly "unloaded", need to be done.
				}

				wglChoosePixelFormat(nullptr, nullptr, nullptr, 0, nullptr, nullptr); // dummy call
				wglCreateContextAttribs(nullptr, nullptr, nullptr); // dummy call
			}

			void ContextOpenGL::createModernContext(const ContextSettings & settings)
			{
				// Create real context
				this->_data->_windowHandle = settings.window.lock()->getAdapter().lock()->getImpl()->_windowId;
				this->_data->_device = GetDC(this->_data->_windowHandle);
				if (!this->_data->_device) {
					throw std::runtime_error("The device associated to that window cannot be used or there is not device.");
				}

				const int pixelAttribs[] = {
					WGL_DRAW_TO_WINDOW_ARB, GL_TRUE,
					WGL_SUPPORT_OPENGL_ARB, GL_TRUE,
					WGL_DOUBLE_BUFFER_ARB, settings.doubleBuffering ? GL_TRUE : GL_FALSE,
					WGL_PIXEL_TYPE_ARB, WGL_TYPE_RGBA_ARB,
					WGL_COLOR_BITS_ARB, 32,
					WGL_DEPTH_BITS_ARB, 24,
					WGL_STENCIL_BITS_ARB, 8,
					WGL_SAMPLE_BUFFERS_ARB, GL_TRUE, // Enable MSAA or not
					WGL_SAMPLES_ARB, static_cast<int>(settings.antialiasingSamples), // Number of samples
					0
				};

				int iPF = 0;
				UINT num_formats_choosen;
				if (!wglChoosePixelFormat(this->_data->_device, pixelAttribs, NULL, 1, &iPF, &num_formats_choosen) || !num_formats_choosen) {
					throw std::runtime_error("There is no video mode available for this device.");
				}

				PIXELFORMATDESCRIPTOR pfd;
				memset(&pfd, 0, sizeof(pfd));
				DescribePixelFormat(this->_data->_device, iPF, sizeof(pfd), &pfd);

				if (!SetPixelFormat(this->_data->_device, iPF, &pfd)) {
					throw std::runtime_error("The video mode cannot be used.");
				}

				auto latestVersion = ContextOpenGL::_maxVersionAvailable;

				const int glVersion[] = {
					WGL_CONTEXT_MAJOR_VERSION_ARB, latestVersion[0],
					WGL_CONTEXT_MINOR_VERSION_ARB, latestVersion[1],
					WGL_CONTEXT_FLAGS_ARB, WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB,
					WGL_CONTEXT_PROFILE_MASK_ARB, WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
					0
				};
				// TODO: deal with shared context, like for restarting window (MSAA requirements)
				this->_data->_context = wglCreateContextAttribs(this->_data->_device, nullptr, glVersion);
				if (this->_data->_context == nullptr) {
					throw std::runtime_error("The context cannot be created.");
				}
			}

			void ContextOpenGL::terminate()
			{
				// TODO To be completed.
				this->_created = false;
			}

			void ContextOpenGL::swapBuffers()
			{
				if (!SwapBuffers(this->_data->_device)) {
					ServiceLoggerLocator::getService().logError("Buffers not swapped !");
				}
			}

			void ContextOpenGL::setCurrent()
			{
				make_assert(this->isCreated(), "only an existing context can be used.");
				RenderContext::setCurrent();
				if (wglMakeCurrent(this->_data->_device, this->_data->_context) == FALSE) {
					throw std::runtime_error("The context cannot be used.");
				}
			}
		} // namespace opengl
	} // namespace renderer
} // namespace ece
