#include "Core\System\EventManagerLocator.hpp"

#include "Core\System\EventManagerNone.hpp"

namespace ece
{
	BaseEventManager & EventManagerLocator::service = EventManagerNone();

	void EventManagerLocator::provide(BaseEventManager & service)
	{
		EventManagerLocator::service = service;
	}
	BaseEventManager & EventManagerLocator::getService()
	{
		return EventManagerLocator::service;
	}
	void EventManagerLocator::stop()
	{
		EventManagerLocator::service = EventManagerNone();
	}
}
