#include "Core\System\Event\EventManagerLocator.hpp"

#include "Core\System\Event\EventManagerNone.hpp"

namespace ece
{
	std::shared_ptr<BaseEventManager> EventManagerLocator::service(new EventManagerNone());

	void EventManagerLocator::provide(const std::shared_ptr<BaseEventManager> & service)
	{
		EventManagerLocator::service = service;
	}
	BaseEventManager & EventManagerLocator::getService()
	{
		return *EventManagerLocator::service;
	}
	void EventManagerLocator::stop()
	{
		EventManagerLocator::service = std::shared_ptr<BaseEventManager>(new EventManagerNone());
	}
}
