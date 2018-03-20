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
#include "renderer/common/render_window.hpp"
#include "window/common/window_adapter.hpp"
#include "window/x11/data_window_adapter.hpp"
#include "utility/log/service_logger.hpp"
#include "renderer/opengl/debugging.hpp"

namespace ece
{
	ContextOpenGL::ContextOpenGL(): BaseContextOpenGL(), _data(makePimpl<DataContextOpenGL>())
	{
	}

	ContextOpenGL::~ContextOpenGL() noexcept
	{
		if (this->_data->_context) {
			glXMakeCurrent(this->_data->_display, 0, 0);
			glXDestroyContext(this->_data->_display, this->_data->_context);
		}
		this->_data->_windowHandle = 0;
	}

	void ContextOpenGL::create(const RenderWindow & window)
	{
		OpenGL::init(this->_minVersion, this->_maxVersion);

		this->_data->_windowHandle = window.getAdapter().lock()->getImpl()->_api->getWindowHandle();
		this->_data->_display = window.getAdapter().lock()->getImpl()->_api->getDevice();

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
			GLX_SAMPLE_BUFFERS, window.getVideoMode().getSamples() > 1 ? true : false, // Enable MSAA or not
			GLX_SAMPLES, window.getVideoMode().getSamples(), // Number of samples,
			None
		};
		int nbFramebufferConfigs = 0;
		GLXFBConfig * framebufferConfig = nullptr;

		int glxMajor = 0, glxMinor = 0;
		glXQueryVersion(this->_data->_display, &glxMajor, &glxMinor);

		if((glxMajor == 1 && glxMinor < 3) || glxMajor < 1) {
			framebufferConfig = glXGetFBConfigs(this->_data->_display, DefaultScreen(this->_data->_display), &nbFramebufferConfigs);
		} else {
			framebufferConfig = glXChooseFBConfig(this->_data->_display, DefaultScreen(this->_data->_display), visualAttribs, &nbFramebufferConfigs);
		}

		if (!framebufferConfig) {
			throw std::runtime_error("There is no video mode available for this device.");
		}
		std::cout << "ok" << std::endl;

		auto latestVersion = OpenGL::getLatestVersion();
		const int glVersion[] = {
	        GLX_CONTEXT_MAJOR_VERSION_ARB, latestVersion[0],
	        GLX_CONTEXT_MINOR_VERSION_ARB, latestVersion[1],
	        None
	    };

		std::cout << glVersion[0] << "." << glVersion[1] << std::endl;

		this->_data->_context = glXCreateContextAttribs(this->_data->_display, framebufferConfig[0], nullptr, true, glVersion);
		if (this->_data->_context == nullptr) {
			throw std::runtime_error("The context cannot be created.");
		}
		glXMakeCurrent(this->_data->_display, this->_data->_windowHandle, this->_data->_context);

		this->logInfos();

		GLint flags;
		glGetIntegerv(GL_CONTEXT_FLAGS, &flags);
		if (flags && GL_CONTEXT_FLAG_DEBUG_BIT)
		{
			checkErrors(glEnable(GL_DEBUG_OUTPUT));
			checkErrors(glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS));
			checkErrors(glDebugMessageCallback(glDebugOutput, nullptr));
			checkErrors(glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, nullptr, GL_TRUE));
		}

		OpenGL::enable(Capability::DEPTH_TEST);
		OpenGL::depthFunc(DepthFunctionCondition::LESS);

		OpenGL::clearColor(0.0f, 0.0f, 0.0f, 0.0f);

		this->_created = true;
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
		if (!glXMakeCurrent(this->_data->_display, this->_data->_windowHandle, this->_data->_context)) {
			throw std::runtime_error("The context cannot be used.");
		}
		OpenGL::setCurrentContext(this->shared_from_this());
	}
}
