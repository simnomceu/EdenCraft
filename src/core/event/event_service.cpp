#include "event/event_service.hpp"

#include "event/event_manager_consumer.hpp"
#include "debug/exception.hpp"

namespace ece
{
	std::weak_ptr<BaseEventManager> EventServiceLocator::getServicePtr(EventManagerConsumer & consumer)
	{
		//return ServiceLocator<BaseEventManager, EventManagerNone>::getServicePtr();

		if (ServiceLocator<BaseEventManager, EventManagerNone>::service.get() == nullptr) {
			throw MemoryAccessException("a service.");
		}
		return ServiceLocator<BaseEventManager, EventManagerNone>::service;
	}
}
