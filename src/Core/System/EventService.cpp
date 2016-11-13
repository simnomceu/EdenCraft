#include "Core\System\EventService.hpp"

#include "Core\System\Event\EventManager.hpp"

#include "Core\Util\LogService.hpp"
#include "Core\Core.hpp"

namespace ece
{
	EventService::EventService(): Service()
	{
	}

	void EventService::init(Mode mode)
	{
		if (!Core::isServiceInit(ece::EVENT)) {
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
			LogServiceLocator::getService().logInfo("Event service started.");
			Core::initService(ece::EVENT);
		}
	}

	void EventService::setMode(Mode mode)
	{
	}
}
