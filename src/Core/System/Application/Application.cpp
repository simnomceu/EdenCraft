#include "System\Application\Application.hpp"

namespace ece
{
	void Application::run()
	{
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