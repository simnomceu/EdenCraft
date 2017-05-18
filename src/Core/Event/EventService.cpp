#include "Event\EventService.hpp"

#include "Event\EventManagerConsumer.hpp"

namespace ece
{
	std::weak_ptr<BaseEventManager> EventServiceLocator::getServicePtr(EventManagerConsumer & consumer)
	{
		//return ServiceLocator<BaseEventManager, EventManagerNone>::getServicePtr();

		if (ServiceLocator<BaseEventManager, EventManagerNone>::service.get() == nullptr) {
			throw std::exception("Invalid pointer to a service.");
		}
		return ServiceLocator<BaseEventManager, EventManagerNone>::service;
	}
}