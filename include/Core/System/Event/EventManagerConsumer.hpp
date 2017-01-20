#ifndef EVENTMANAGERCONSUMER_HPP
#define EVENTMANAGERCONSUMER_HPP

#include "Core\System\Event\EventManager.hpp"

namespace ece
{
	class EventManagerConsumer final
	{
	public:
		EventManagerConsumer();
		EventManagerConsumer(const EventManagerConsumer & copy) = default;
		EventManagerConsumer(EventManagerConsumer && move) = default;
		~EventManagerConsumer() = default;

		EventManagerConsumer & operator=(const EventManagerConsumer & copy) = default;
		EventManagerConsumer & operator=(EventManagerConsumer && move) = default;

		const std::shared_ptr<BaseEventManager> consume();
	
	private:
		std::weak_ptr<BaseEventManager> eventManager;
	};
}

#endif // EVENTMANAGERCONSUMER
