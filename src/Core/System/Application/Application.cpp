#include "System\Application\Application.hpp"
#include "Log\ServiceLogger.hpp"

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

	void Application::onInit()
	{
		try {
			this->argumentAnalyzer.analyse();
		}
		catch (std::runtime_error & e) {
			ServiceLoggerLocator::getService().logError("Invalid command argument: " + std::string(e.what()));
		}
	}

	void Application::start()
	{
		this->onInit();
		this->running = true;
	}
}