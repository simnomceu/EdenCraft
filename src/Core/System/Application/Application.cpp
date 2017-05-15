#include "System\Application\Application.hpp"
#include "Log\ServiceLogger.hpp"
#include "System\Module\ModuleMethod.hpp"

namespace ece
{
	Application::Application(int argc, char * argv[]) : running(false), moduleManager()
	{
		auto & argumentAnalyzer = this->addModule<ArgumentAnalyzer>(&ArgumentAnalyzer::analyse);
		argumentAnalyzer.setParameters(argc, argv);
	}

	void Application::run()
	{
		// TODO : add balancer to reduce usage of processor.
		this->onPreInit();
		this->init();
		this->onPostInit();

		while (this->isRunning()) {
			this->onPreProcess();
			this->processEvents();
			this->onPreUpdate();
			this->update();
			this->onPostUpdate();
			this->render();
			this->onPostRender();
		}

		this->onPreTerminate();
		this->terminate();
		this->onPreTerminate();
	}

	void Application::init()
	{
		try {
			this->moduleManager.initAll();
		}
		catch (std::runtime_error & e) {
			ServiceLoggerLocator::getService().logError("Invalid command argument: " + std::string(e.what()));
		}
		this->running = true;
	}

	void Application::update()
	{
		this->moduleManager.updateAll();
	}

	void Application::processEvents()
	{
	}

	void Application::render()
	{
	}

	void Application::terminate()
	{
		this->moduleManager.terminateAll();
	}
}