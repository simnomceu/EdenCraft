#include "event\event_service.hpp"

#include "event\event_manager_consumer.hpp"

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