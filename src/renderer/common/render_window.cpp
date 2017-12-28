#include "renderer/common/render_window.hpp"

#include "renderer/opengl/context_opengl.hpp"

#include "renderer/opengl/opengl.hpp"
#include "utility/log/service_logger.hpp"
#include "window/common/video_mode.hpp"

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
			glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}
	}

	void RenderWindow::display()
	{
		this->context->swapBuffers();
	}

	void RenderWindow::enableMSAA(const unsigned short int samples)
	{
		if (samples < 2) {
			glDisable(GL_MULTISAMPLE);
		}
		this->videoMode.setSamples(samples);
	}

	void RenderWindow::updateVideoMode()
	{
		if (this->videoMode.hasChanged()) {
			this->context.reset();
			this->close();
			this->context = std::make_shared<ContextOpenGL>();
			this->open();
			this->videoMode.applyChanges();
		}
	}
}