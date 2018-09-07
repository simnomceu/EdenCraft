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
#include "renderer/x11/data_context_opengl.hpp"

#include "renderer/opengl/opengl.hpp"
#include "renderer/x11/glx_extension.hpp"
#include "renderer/rendering/render_window.hpp"
#include "window/common/window_adapter.hpp"
#include "window/x11/data_window_adapter.hpp"
#include "utility/log/service_logger.hpp"
#include "renderer/debug/debugging.hpp"

namespace ece
{
	namespace renderer
	{
		namespace opengl
		{
			using utility::log::ServiceLoggerLocator;
			using utility::debug::AssertionException;
			using utility::pattern::makePimpl;

			ContextOpenGL::ContextOpenGL() noexcept: RenderContext(), _data(makePimpl<DataContextOpenGL>()), _currentVersion()
			{
			}

			ContextOpenGL::~ContextOpenGL() noexcept
			{
				if (this->_data->_context) {
					if (this->isCurrent()) {
						glXMakeCurrent(this->_data->_display, 0, 0);
					}
					glXDestroyContext(this->_data->_display, this->_data->_context);

					// ERROR: crash with RootWindow (for dummy context)
					/*if (this->_data->_windowHandle) {
						XUnmapWindow(this->_data->_display, this->_data->_windowHandle);
						XDestroyWindow(this->_data->_display, this->_data->_windowHandle);
						XCloseDisplay(this->_data->_display);
						this->_data->_windowHandle = 0;
						this->_data->_display = nullptr;
					}*/
				}
			}

			void ContextOpenGL::createOldContext()
			{
				this->_data->_display = XOpenDisplay(nullptr);

				int nbFBConfig = 0;
				GLXFBConfig * FBConfig = nullptr;

				int glxMajor = 0, glxMinor = 0;
				glXQueryVersion(this->_data->_display, &glxMajor, &glxMinor);

				if ((glxMajor == 1 && glxMinor < 3) || glxMajor < 1) {
					ServiceLoggerLocator::getService().logWarning("GLX 1.3 or greater is not available. Most recent version is GLX " + std::to_string(glxMajor) + "." + std::to_string(glxMinor));
					const int visual_attribs[] = {
						GLX_RENDER_TYPE, GLX_RGBA_BIT,
						GLX_DRAWABLE_TYPE, GLX_WINDOW_BIT,
						GLX_DEPTH_SIZE, 24,
						GLX_STENCIL_SIZE, 8,
						None
					};
					FBConfig = glXChooseFBConfig(this->_data->_display, DefaultScreen(this->_data->_display), visual_attribs, &nbFBConfig);
				}
				/*	else {
						ServiceLoggerLocator::getService().logInfo("GLX version: " + std::to_string(glxMajor) + "." + std::to_string(glxMinor));
						const int visual_attribs[] = {
							GLX_X_RENDERABLE, GL_TRUE,
							GLX_RENDER_TYPE, GLX_RGBA_BIT,
							GLX_DRAWABLE_TYPE, GLX_WINDOW_BIT,
							GLX_X_VISUAL_TYPE, GLX_TRUE_COLOR,
							GLX_DOUBLEBUFFER, true,
							GLX_RED_SIZE, 8,
							GLX_GREEN_SIZE, 8,
							GLX_BLUE_SIZE, 8,
							GLX_ALPHA_SIZE, 8,
							GLX_DEPTH_SIZE, 24,
							GLX_STENCIL_SIZE, 8,
							None
						};
						FBConfig = glXChooseFBConfig(this->_dummy.display, DefaultScreen(this->_dummy.display), visual_attribs, &nbFBConfig);
					}*/

				if (!FBConfig) {
					throw std::runtime_error("No frame buffer configuration choosen for OpenGL dummy context.");
				}
				//XVisualInfo * visualInfo = glXGetVisualFromFBConfig(this->_dummy.display, FBConfig[0]);

				this->_data->_windowHandle = RootWindow(this->_data->_display, DefaultScreen(this->_data->_display));
				XMapWindow(this->_data->_display, this->_data->_windowHandle);

				this->_data->_context = glXCreateNewContext(this->_data->_display, FBConfig[0], GLX_RGBA_TYPE, nullptr, true);

				glXMakeCurrent(this->_data->_display, this->_data->_windowHandle, this->_data->_context);
				glXCreateContextAttribs(nullptr, 0, nullptr, false, nullptr); //dummy call

				XFree(FBConfig);
			}

			void ContextOpenGL::createModernContext(const ContextSettings & settings)
			{
				this->_data->_windowHandle = settings.window.lock()->getAdapter().lock()->getImpl()->_api->getWindowHandle();
				this->_data->_display = settings.window.lock()->getAdapter().lock()->getImpl()->_api->getDevice();

				int nbFramebufferConfigs = 0;
				GLXFBConfig * framebufferConfig = nullptr;

				int glxMajor = 0, glxMinor = 0;
				glXQueryVersion(this->_data->_display, &glxMajor, &glxMinor);
				if ((glxMajor == 1 && glxMinor < 3) || glxMajor < 1) {
					const int visualAttribs[] = {
						GLX_X_RENDERABLE, GL_TRUE,
						GLX_RENDER_TYPE, GLX_RGBA_BIT,
						GLX_DRAWABLE_TYPE, GLX_WINDOW_BIT,
						GLX_X_VISUAL_TYPE, GLX_TRUE_COLOR,
						GLX_DOUBLEBUFFER, settings.doubleBuffering ? GL_TRUE : GL_FALSE,
						GLX_RED_SIZE, 8,
						GLX_GREEN_SIZE, 8,
						GLX_BLUE_SIZE, 8,
						GLX_DEPTH_SIZE, 24,
						GLX_STENCIL_SIZE, 8,
						None
					};
					framebufferConfig = glXChooseFBConfig(this->_data->_display, DefaultScreen(this->_data->_display), visualAttribs, &nbFramebufferConfigs);
				}
				else {
					const int visualAttribs[] = {
						GLX_X_RENDERABLE, GL_TRUE,
						GLX_RENDER_TYPE, GLX_RGBA_BIT,
						GLX_DRAWABLE_TYPE, GLX_WINDOW_BIT,
						GLX_X_VISUAL_TYPE, GLX_TRUE_COLOR,
						GLX_DOUBLEBUFFER, true,
						GLX_BUFFER_SIZE, 32,
						GLX_ALPHA_SIZE, 8,
						GLX_RED_SIZE, 8,
						GLX_GREEN_SIZE, 8,
						GLX_BLUE_SIZE, 8,
						GLX_DEPTH_SIZE, 24,
						GLX_STENCIL_SIZE, 8,
						GLX_SAMPLE_BUFFERS, GL_TRUE, // Enable MSAA or not
						GLX_SAMPLES, static_cast<int>(settings.antialiasingSamples), // Number of samples,
						None
					};
					framebufferConfig = glXChooseFBConfig(this->_data->_display, DefaultScreen(this->_data->_display), visualAttribs, &nbFramebufferConfigs);
				}

				if (!framebufferConfig) {
					throw std::runtime_error("There is no video mode available for this device.");
				}

				auto glxExts = std::string(glXQueryExtensionsString(this->_data->_display, DefaultScreen(this->_data->_display)));
				if (glxExts.find("GLX_ARB_create_context") == std::string::npos) {
					this->_data->_context = glXCreateNewContext(this->_data->_display, framebufferConfig[0], GLX_RGBA_TYPE, nullptr, true);
				}
				else {
					auto latestVersion = ContextOpenGL::_maxVersionAvailable;
					const int glVersion[] = {
						GLX_CONTEXT_MAJOR_VERSION_ARB, latestVersion[0],
						GLX_CONTEXT_MINOR_VERSION_ARB, latestVersion[1],
						GLX_CONTEXT_PROFILE_MASK_ARB, GLX_CONTEXT_CORE_PROFILE_BIT_ARB,
						None
					};
					this->_data->_context = glXCreateContextAttribs(this->_data->_display, framebufferConfig[0], nullptr, true, glVersion);
				}

				if (this->_data->_context == nullptr) {
					throw std::runtime_error("The context cannot be created.");
				}
			}

			void ContextOpenGL::terminate()
			{
				this->_created = false;
			}

			void ContextOpenGL::swapBuffers()
			{
				glXSwapBuffers(this->_data->_display, this->_data->_windowHandle);
			}

			void ContextOpenGL::setCurrent()
			{
				RenderContext::setCurrent();
				if (!glXMakeCurrent(this->_data->_display, this->_data->_windowHandle, this->_data->_context)) {
					throw std::runtime_error("The context cannot be used.");
				}
			}
		} // namespace opengl
	} // namespace renderer
} // namespace ece
