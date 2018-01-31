#include "renderer/opengl/context_opengl.hpp"
#include "renderer/win32/data_context_opengl.hpp"

#include "renderer/opengl/opengl.hpp"
#include "renderer/win32/wgl_extension.hpp"
#include "renderer/common/render_window.hpp"
#include "window/common/window_adapter.hpp"
#include "window/win32/data_window_adapter.hpp"
#include "utility/log/service_logger.hpp"

#include <iostream>

namespace ece
{
	ContextOpenGL::ContextOpenGL(): BaseContextOpenGL(), _data(makePimpl<DataContextOpenGL>(nullptr, nullptr, nullptr))
	{
	}

	ContextOpenGL::~ContextOpenGL()
	{
		if (this->_data->_context != nullptr) {
			wglMakeCurrent(nullptr, nullptr);
			wglDeleteContext(this->_data->_context);
			this->_data->_context = nullptr;
		}
		if (this->_data->_device != nullptr) {
			ReleaseDC(this->_data->_windowHandle, this->_data->_device);
			this->_data->_device = nullptr;
		}
		this->_data->_windowHandle = nullptr;
	}

	void ContextOpenGL::create(const RenderWindow & window)
	{
		OpenGL::init(COMMAND_EXECUTION | TIMER_QUERIES | SYNCHRONIZATION | ASYNCHRONOUS_QUERIES
			| BUFFER_OBJECTS | SHADERS_AND_PROGRAMS | TEXTURES_AND_SAMPLERS | FRAMEBUFFER_OBJECTS
			| VERTICES | VERTEX_ARRAYS | VERTEX_ATTRIBUTES | VERTEX_POST_PROCESSING | RASTERIZATION
			| FRAGMENT_SHADERS | COMPUTE_SHADERS | PER_FRAGMENT_OPERATIONS | HINTS
			| WHOLE_FRAMEBUFFER | READING_AND_COPYING_PIXELS | DEBUG_OUTPUT | STATE_AND_STATE_REQUESTS
			| PLATFORM,
			std::make_unique<WGLExtension>());

		// Create real context
		this->_data->_windowHandle = window.getAdapter().lock()->getImpl()->_windowId;
		this->_data->_device = GetDC(this->_data->_windowHandle);
		if (!this->_data->_device) {
			throw std::runtime_error("The device associated to that window cannot be used or there is not device.");
		}

		const int pixelAttribs[] = {
			WGL_DRAW_TO_WINDOW_ARB, GL_TRUE,
			WGL_SUPPORT_OPENGL_ARB, GL_TRUE,
			WGL_DOUBLE_BUFFER_ARB, GL_TRUE,
			WGL_PIXEL_TYPE_ARB, WGL_TYPE_RGBA_ARB,
			WGL_COLOR_BITS_ARB, 32,
			WGL_DEPTH_BITS_ARB, 24,
			WGL_STENCIL_BITS_ARB, 8,
			WGL_SAMPLE_BUFFERS_ARB, window.getVideoMode().getSamples() > 1 ? GL_TRUE : GL_FALSE, // Enable MSAA or not
			WGL_SAMPLES_ARB, window.getVideoMode().getSamples(), // Number of samples
			0
		};

		int iPF;
		UINT num_formats_choosen;
		if (!wglChoosePixelFormat(this->_data->_device, pixelAttribs, NULL, 1, &iPF, &num_formats_choosen) || !num_formats_choosen) {
			throw std::runtime_error("There is no video mode available for this device.");
		}

		PIXELFORMATDESCRIPTOR pfd;
		memset(&pfd, 0, sizeof(pfd));
		DescribePixelFormat(this->_data->_device, iPF, sizeof(pfd), &pfd);

		if (!SetPixelFormat(this->_data->_device, iPF, &pfd)) {
			std::cout << "PixelFormat: " << iPF << std::endl;
			throw std::runtime_error("The video mode cannot be used.");
		}

		const int glVersion[] = {
			WGL_CONTEXT_MAJOR_VERSION_ARB, OpenGL::getLatestMajorVersion(),
			WGL_CONTEXT_MINOR_VERSION_ARB, OpenGL::getLatestMinorVersion(),
			WGL_CONTEXT_FLAGS_ARB, WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB,
			WGL_CONTEXT_PROFILE_MASK_ARB, WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
			0
		};
		// TODO: deal with shared context, like for restarting window (MSAA requirements)
		this->_data->_context = wglCreateContextAttribs(this->_data->_device, nullptr, glVersion);
		if (this->_data->_context == nullptr) {
			throw std::runtime_error("The context cannot be created.");
		}
		if (wglMakeCurrent(this->_data->_device, this->_data->_context) == FALSE) {
			throw std::runtime_error("The created context cannot be used.");
		}
		OpenGL::checkErrors("ContextOpenGL::create");
		
		this->logInfos();

		OpenGL::enable(Capability::DEPTH_TEST);
		OpenGL::depthFunc(DepthFunctionCondition::LESS);

		OpenGL::clearColor(0.0f, 0.0f, 0.0f, 0.0f);
	}

	void ContextOpenGL::swapBuffers()
	{
		if (!SwapBuffers(this->_data->_device)) {
			ServiceLoggerLocator::getService().logError("Buffers not swapped !");
		}
	}
}