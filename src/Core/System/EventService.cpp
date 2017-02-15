#include "Core\System\EventService.hpp"

#include "Core\System\Event\EventManager.hpp"

#include "Core\Util\LogService.hpp"
#include "Core\Core.hpp"

namespace ece
{
	std::weak_ptr<BaseEventManager> EventServiceLocator::getServicePtr(EventManagerConsumer & consumer)
	{
		return ServiceLocator<BaseEventManager, EventManagerNone>::service;
	}

	EventService::EventService(): Service()
	{
	}

	void EventService::init(Mode mode)
	{
		if (!this->isInitialized()) {
			switch (mode)
			{
			case ece::Mode::NOT_INIT:
				break;
			case ece::Mode::NONE:
				EventServiceLocator::provide(EventServiceFactory::build<EventManagerNone>());
				break;
			case ece::Mode::DEFAULT:
				EventServiceLocator::provide(EventServiceFactory::build<EventManager>());
				break;
			case ece::Mode::CONSOLE:
				break;
			default:
				break;
			}
			this->initialized = true;
			this->modeInitialized = mode;
			LogServiceLocator::getService().logInfo("Event service started.");
		}
	}

	void EventService::setMode(Mode mode)
	{
	}
}
