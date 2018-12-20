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

#include "renderer/pch.hpp"
#include "renderer/opengl/context_opengl.hpp"
#include "renderer/x11/data_context_opengl.hpp"

#include "renderer/x11/glx_extension.hpp"
#include "window/x11/data_window_adapter.hpp"

namespace ece
{
	namespace renderer
	{
		namespace opengl
		{
			ContextOpenGL::ContextOpenGL() noexcept: RenderContext(), _data(makePimpl<DataContextOpenGL>()), _currentVersion()
			{
			}

			ContextOpenGL::~ContextOpenGL() noexcept
			{
				if (this->_data->context) {
					if (this->isCurrent()) {
						glXMakeCurrent(this->_data->display, 0, 0);
					}
					glXDestroyContext(this->_data->display, this->_data->context);

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
				this->_data->display = XOpenDisplay(nullptr);

				auto nbFBConfig = 0;

				auto glxMajor = 0;
				auto glxMinor = 0;
				glXQueryVersion(this->_data->display, &glxMajor, &glxMinor);

				if ((glxMajor == 1 && glxMinor < 3) || glxMajor < 1) {
					ServiceLoggerLocator::getService().logWarning("GLX 1.3 or greater is not available. Most recent version is GLX " + std::to_string(glxMajor) + "." + std::to_string(glxMinor));
                }
                else {
						ServiceLoggerLocator::getService().logInfo("GLX version: " + std::to_string(glxMajor) + "." + std::to_string(glxMinor));
                }

            	const auto visual_attribs = std::array{
					GLX_RENDER_TYPE, GLX_RGBA_BIT,
					GLX_DRAWABLE_TYPE, GLX_WINDOW_BIT,
					GLX_DEPTH_SIZE, 24,
					GLX_STENCIL_SIZE, 8,
						static_cast<int>(None)
				};
				auto FBConfig = glXChooseFBConfig(this->_data->display, DefaultScreen(this->_data->display), visual_attribs.data(), &nbFBConfig);

				if (!FBConfig) {
					throw std::runtime_error("No frame buffer configuration choosen for OpenGL dummy context.");
				}
				//XVisualInfo * visualInfo = glXGetVisualFromFBConfig(this->_dummy.display, FBConfig[0]);

				this->_data->windowHandle = RootWindow(this->_data->display, DefaultScreen(this->_data->display));
				XMapWindow(this->_data->display, this->_data->windowHandle);

				this->_data->context = glXCreateNewContext(this->_data->display, FBConfig[0], GLX_RGBA_TYPE, nullptr, true);

				glXMakeCurrent(this->_data->display, this->_data->windowHandle, this->_data->context);
				glXCreateContextAttribs(nullptr, 0, nullptr, false, nullptr); //dummy call

				XFree(FBConfig);
			}

			void ContextOpenGL::createModernContext(const ContextSettings & settings)
			{
				this->_data->windowHandle = settings.window.lock()->getAdapter()->getImpl()->api->getWindowHandle();
				this->_data->display = settings.window.lock()->getAdapter()->getImpl()->api->getDevice();

				auto nbFramebufferConfigs = 0;
				GLXFBConfig * framebufferConfig = nullptr;

				auto glxMajor = 0;
				auto glxMinor = 0;
				glXQueryVersion(this->_data->display, &glxMajor, &glxMinor);
				if ((glxMajor == 1 && glxMinor < 3) || glxMajor < 1) {
					const auto visualAttribs = std::array{
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
						static_cast<int>(None)
					};
					framebufferConfig = glXChooseFBConfig(this->_data->display, DefaultScreen(this->_data->display), visualAttribs.data(), &nbFramebufferConfigs);
				}
				else {
					const auto visualAttribs = std::array{
						GLX_X_RENDERABLE, GL_TRUE,
						GLX_DRAWABLE_TYPE, GLX_WINDOW_BIT,
						GLX_X_VISUAL_TYPE, GLX_TRUE_COLOR,
						GLX_RENDER_TYPE, GLX_RGBA_BIT,
						GLX_DOUBLEBUFFER, settings.doubleBuffering ? GL_TRUE : GL_FALSE,
						GLX_BUFFER_SIZE, static_cast<int>(settings.bitsPerPixel),
						GLX_ALPHA_SIZE, settings.bitsPerPixel == 32 ? 8 : 0,
						GLX_DEPTH_SIZE, static_cast<int>(settings.depthBits),
						GLX_STENCIL_SIZE, static_cast<int>(settings.stencilBits),
						GLX_SAMPLE_BUFFERS, settings.antialiasingSamples > 1 ? GL_TRUE : GL_FALSE, // Enable MSAA or not
						GLX_SAMPLES, static_cast<int>(settings.antialiasingSamples), // Number of samples,
						static_cast<int>(None)
					};
					framebufferConfig = glXChooseFBConfig(this->_data->display, DefaultScreen(this->_data->display), visualAttribs.data(), &nbFramebufferConfigs);
				}

				if (!framebufferConfig) {
					throw std::runtime_error("There is no video mode available for this device.");
				}

				auto glxExts = std::string(glXQueryExtensionsString(this->_data->display, DefaultScreen(this->_data->display)));
				if (glxExts.find("GLX_ARB_create_context") == std::string::npos) {
					this->_data->context = glXCreateNewContext(this->_data->display, framebufferConfig[0], GLX_RGBA_TYPE, nullptr, true);
				}
				else {
					auto latestVersion = ContextOpenGL::_maxVersionAvailable;
					const auto glVersion = std::array{
						GLX_CONTEXT_MAJOR_VERSION_ARB, static_cast<int>(latestVersion[0]),
						GLX_CONTEXT_MINOR_VERSION_ARB, static_cast<int>(latestVersion[1]),
						GLX_CONTEXT_PROFILE_MASK_ARB, GLX_CONTEXT_CORE_PROFILE_BIT_ARB,
						static_cast<int>(None)
					};
					this->_data->context = glXCreateContextAttribs(this->_data->display, framebufferConfig[0], nullptr, true, glVersion.data());
				}

				if (this->_data->context == nullptr) {
					throw std::runtime_error("The context cannot be created.");
				}
			}

			void ContextOpenGL::terminate()
			{
				this->_created = false;
			}

			void ContextOpenGL::swapBuffers()
			{
				glXSwapBuffers(this->_data->display, this->_data->windowHandle);
			}

			void ContextOpenGL::setCurrent()
			{
				RenderContext::setCurrent();
				if (!glXMakeCurrent(this->_data->display, this->_data->windowHandle, this->_data->context)) {
					throw std::runtime_error("The context cannot be used.");
				}
			}
		} // namespace opengl
	} // namespace renderer
} // namespace ece
