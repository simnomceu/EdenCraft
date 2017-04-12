#include "System\Application\Application.hpp"

namespace ece
{
	void Application::run()
	{
		// TODO : add balancer to reduce usage of processor.
		this->start();
		while (this->isRunning()) {
			this->processEvents();
			this->update();
			this->render();
		}
	}

	void Application::start()
	{
		this->onInit();
		this->running = true;
	}
}