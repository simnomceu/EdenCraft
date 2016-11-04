#include "Core\System\Event\EventService.hpp"

namespace ece
{
	EventService::EventService(): Service()
	{
	}

	void EventService::init(Mode mode)
	{
		switch (mode)
		{
		case ece::Mode::NOT_INIT:
			break;
		case ece::Mode::NONE:
			EventServiceLocator::provide(EventServiceFactory::build<EventManagerNone>());
			break;
		case ece::Mode::DEFAULT:
			break;
		case ece::Mode::CONSOLE:
			break;
		default:
			break;
		}
	}
	void EventService::setMode(Mode mode)
	{
	}
}
