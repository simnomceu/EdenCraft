#ifndef EVENTMANAGERCONSUMER_HPP
#define EVENTMANAGERCONSUMER_HPP

#include "System\Event\EventManager.hpp"
#include "EventService.hpp"

namespace ece
{
	class EventManagerConsumer final
	{
	public:
		inline EventManagerConsumer();
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

#include "System\Event\EventManagerConsumer.inl"

#endif // EVENTMANAGERCONSUMER
