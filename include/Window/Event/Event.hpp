#ifndef EVENT_HPP
#define EVENT_HPP

namespace ece
{
	class Event
	{
	public:
		enum EventType
		{
			NONE = -1,
			MOUSE_PRESSED = 0,
			MOUSE_RELEASED = 1,
			MOUSE_MOVED = 2,
			MOUSE_SCROLLED = 3
		};

		inline Event();

		inline const EventType getType() const;
		inline void setType(const EventType type);

	private:
		EventType type;
	};
}

#include "Event\Event.inl"

#endif // EVENT_HPP
