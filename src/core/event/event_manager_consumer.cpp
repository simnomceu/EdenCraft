#include "event/event_manager_consumer.hpp"

#include "debug/exception.hpp"
#include "event/event_service.hpp"

namespace ece
{
	const std::shared_ptr<BaseEventManager> EventManagerConsumer::consume()
	{
		// TODO: Guard if the EventManager doesn't exist anymore.
		if (this->eventManager.expired()) {
			throw MemoryAccessException::makeException("EventManager", "EventManagerConsumer");
		}
		return this->eventManager.lock();
	}
}
