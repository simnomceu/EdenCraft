#include "Core\System\Event\EventManagerConsumer.hpp"

#include "Core\Util\MemoryAccessException.hpp"
#include "Core\System\EventService.hpp"

namespace ece
{
	EventManagerConsumer::EventManagerConsumer(): eventManager(EventServiceLocator::getServicePtr(*this))
	{
	}

	const std::shared_ptr<BaseEventManager> EventManagerConsumer::consume()
	{
		// Guard if the EventManager doesn't exist anymore.
		if (this->eventManager.expired()) {
			throw MemoryAccessException("EventManager", "EventManagerConsumer");
		}
		return this->eventManager.lock();
	}
}
