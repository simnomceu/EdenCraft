#include "core/event/event_service.hpp"

#include "core/event/event_manager_consumer.hpp"
#include "utility/debug/exception.hpp"

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
