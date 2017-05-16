#include "System\Application\Application.hpp"
#include "Log\ServiceLogger.hpp"
#include "Log\Logger.hpp"
#include "System\Event\EventService.hpp"
#include "System\Event\EventManager.hpp"
#include "System\Module\ModuleMethod.hpp"

namespace ece
{
	Application::Application() : running(false), moduleManager(), lifecycle(nullptr)
	{
		ece::ServiceLoggerLocator::provide(ece::ServiceLoggerFactory::build<ece::Logger>());
		ece::EventServiceLocator::provide(ece::EventServiceFactory::build<ece::EventManager>());

		this->lifecycle = std::make_shared<Lifecycle>();
	}

	Application::Application(int argc, char * argv[]) : running(false), moduleManager(), lifecycle(nullptr)
	{
		ece::ServiceLoggerLocator::provide(ece::ServiceLoggerFactory::build<ece::Logger>());
		ece::EventServiceLocator::provide(ece::EventServiceFactory::build<ece::EventManager>());

		this->lifecycle = std::make_shared<Lifecycle>();

		auto & argumentAnalyzer = this->addModule<ArgumentAnalyzer>(&ArgumentAnalyzer::analyse);
		argumentAnalyzer.setParameters(argc, argv);
	}

	void Application::run()
	{
		// TODO : add balancer to reduce usage of processor.
		this->lifecycle->preInit();
		this->init();
		this->lifecycle->postInit();

		while (this->isRunning()) {
			this->lifecycle->preProcess();
			this->processEvents();
			this->lifecycle->preUpdate();
			this->update();
			this->lifecycle->postUpdate();
			this->render();
			this->lifecycle->postRender();
		}

		this->lifecycle->preTerminate();
		this->terminate();
		this->lifecycle->preTerminate();
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
		//EventServiceLocator::getService().clear();
	}

	void Application::render()
	{
	}

	void Application::terminate()
	{
		this->moduleManager.terminateAll();
	}
}