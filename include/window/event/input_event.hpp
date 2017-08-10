#ifndef INPUT_EVENT_HPP
#define INPUT_EVENT_HPP

namespace ece
{
	class InputEvent
	{
	public:
		enum InputEventType
		{
			NONE = -1,
			MOUSE_PRESSED = 0,
			MOUSE_RELEASED = 1,
			MOUSE_MOVED = 2,
			MOUSE_SCROLLED = 3
		};

		inline InputEvent();

		inline const InputEventType getType() const;
		inline void setType(const InputEventType type);

	private:
		InputEventType type;
	};
}

#include "event/input_event.inl"

#endif // INPUT_EVENT_HPP
