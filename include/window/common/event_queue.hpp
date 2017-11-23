#ifndef EVENT_QUEUE_HPP
#define EVENT_QUEUE_HPP

#include <queue>

#include "window/window_event/input_event.hpp"

namespace ece
{
	class EventQueue: private std::queue<InputEvent>
	{
	public:
		EventQueue() = default;
		EventQueue(const EventQueue & copy) = default;
		EventQueue(EventQueue && move) = default;

		~EventQueue() = default;

		EventQueue & operator=(const EventQueue & copy) = default;
		EventQueue & operator=(EventQueue && move) = default;

		using std::queue<InputEvent>::push;
		using std::queue<InputEvent>::pop;
		using std::queue<InputEvent>::empty;
		using std::queue<InputEvent>::front;
		using std::queue<InputEvent>::back;

	private:
	};
}

#endif // EVENT_QUEUE_HPP
