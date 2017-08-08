#ifndef EVENT_MANAGER_CONSUMER_HPP
#define EVENT_MANAGER_CONSUMER_HPP

#include "event\event_manager.hpp"
#include "event_service.hpp"

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

#include "event\event_manager_consumer.inl"

#endif // EVENT_MANAGER_CONSUMER_HPP
