#include "common_renderer/render_window.hpp"

#ifdef __unix__
#include "x11/context_opengl.hpp"
#elif __WINDOW__
#include "win32/context_opengl.hpp"
#elif __OSX__
#include "cocoa/context_opengl.hpp"
#else
#include "win32/context_opengl.hpp"
#endif

#include "log/service_logger.hpp"

namespace ece
{
	RenderWindow::RenderWindow(): context(std::make_shared<ContextOpenGL>())
	{
	}

	RenderWindow::~RenderWindow()
	{
		this->renderers.clear();
	}

	void RenderWindow::open()
	{
		Window::open();
		try {
			this->context->create(*this);
		}
		catch (std::runtime_error & e) {
			ServiceLoggerLocator::getService().logError(e.what());
		}
	}

	void RenderWindow::clear()
	{
		if (this->isOpened()) {
			glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}
	}

	void RenderWindow::display()
	{
		this->context->swapBuffers();
	}
}