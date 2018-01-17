#include "core/event/event_manager_consumer.hpp"

#include "utility/debug/exception.hpp"
#include "core/event/event_service.hpp"

namespace ece
{
	const std::shared_ptr<BaseEventManager> EventManagerConsumer::consume()
	{
		// TODO: Guard if the EventManager doesn't exist anymore.
		if (this->_eventManager.expired()) {
			throw MemoryAccessException("EventManager", "EventManagerConsumer");
		}
		return this->_eventManager.lock();
	}
}
