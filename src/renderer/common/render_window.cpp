#include "renderer/common/render_window.hpp"

#include "renderer/opengl/context_opengl.hpp"

#include "renderer/opengl/opengl.hpp"
#include "utility/log/service_logger.hpp"
#include "window/common/video_mode.hpp"

namespace ece
{
	RenderWindow::RenderWindow(): _context(std::make_shared<ContextOpenGL>())
	{
	}

	RenderWindow::~RenderWindow()
	{
		this->_renderers.clear();
	}

	void RenderWindow::open()
	{
		Window::open();
		try {
			this->_context->create(*this);
		}
		catch (Exception & /*e*/) {
			throw;
		}
		catch (std::runtime_error & e) {
			ServiceLoggerLocator::getService().logError(e.what());
		}
	}

	void RenderWindow::clear()
	{
		if (this->isOpened()) {
			OpenGL::clear(Bitfield::COLOR_BUFFER_BIT | Bitfield::STENCIL_BUFFER_BIT | Bitfield::DEPTH_BUFFER_BIT);
		}
	}

	void RenderWindow::display()
	{
		this->_context->swapBuffers();
	}

	void RenderWindow::enableMSAA(const unsigned short int samples)
	{
		if (samples < 2) {
			OpenGL::disable(Capability::MULTISAMPLE);
		}
		this->_videoMode.setSamples(samples);
	}

	void RenderWindow::updateVideoMode()
	{
		if (this->_videoMode.hasChanged()) {
			this->_context.reset();
			this->close();
			this->_context = std::make_shared<ContextOpenGL>();
			this->open();
			this->_videoMode.applyChanges();
		}
	}
}