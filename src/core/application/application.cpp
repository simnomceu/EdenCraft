#include "core/application/application.hpp"

#include "utility/log/service_logger.hpp"
#include "utility/log/logger.hpp"
#include "core/event/event_service.hpp"
#include "core/event/event_manager.hpp"
#include "core/module/module_method.hpp"
#include "utility/debug/exception.hpp"

namespace ece
{
	Application::Application() : _running(false), _moduleManager(), _lifecycle(nullptr)
	{
		ece::ServiceLoggerLocator::provide(ece::ServiceLoggerFactory::build<ece::Logger>());
		ece::EventServiceLocator::provide(ece::EventServiceFactory::build<ece::EventManager>());

		this->_lifecycle = std::make_shared<Lifecycle>();
	}

	Application::Application(int argc, char * argv[]) : _running(false), _moduleManager(), _lifecycle(nullptr)
	{
		ece::ServiceLoggerLocator::provide(ece::ServiceLoggerFactory::build<ece::Logger>());
		ece::EventServiceLocator::provide(ece::EventServiceFactory::build<ece::EventManager>());

		this->_lifecycle = std::make_shared<Lifecycle>();

		auto & argumentAnalyzer = this->addModule<ArgumentAnalyzer>(&ArgumentAnalyzer::analyse);
		argumentAnalyzer.setParameters(argc, argv);
	}

	void Application::run()
	{
		// TODO : add balancer to reduce usage of processor.
		this->_lifecycle->preInit();
		this->init();
		this->_lifecycle->postInit();

		while (this->isRunning()) {
			this->_lifecycle->preProcess();
			this->processEvents();
			this->_lifecycle->preUpdate();
			this->update();
			this->_lifecycle->postUpdate();
			this->render();
			this->_lifecycle->postRender();
		}

		this->_lifecycle->preTerminate();
		this->terminate();
		this->_lifecycle->preTerminate();
	}

	void Application::init()
	{
		try {
			this->_moduleManager.initAll();
		}
		catch (std::runtime_error & e) {
			ServiceLoggerLocator::getService().logError("Invalid command argument: " + std::string(e.what()));
		}
		this->_running = true;
	}

	void Application::update()
	{
		this->_moduleManager.updateAll();
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
		this->_moduleManager.terminateAll();
	}
}
