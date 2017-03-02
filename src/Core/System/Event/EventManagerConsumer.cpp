#include "System\Event\EventManagerConsumer.hpp"

#include "Util\Debug\MemoryAccessException.hpp"
#include "System\Event\EventService.hpp"

namespace ece
{
	const std::shared_ptr<BaseEventManager> EventManagerConsumer::consume()
	{
		// TODO: Guard if the EventManager doesn't exist anymore.
		if (this->eventManager.expired()) {
			throw MemoryAccessException("EventManager", "EventManagerConsumer");
		}
		return this->eventManager.lock();
	}
}
