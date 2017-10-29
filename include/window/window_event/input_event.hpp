#ifndef INPUT_EVENT_HPP
#define INPUT_EVENT_HPP

#include "window_event/mouse.hpp"
#include "window_event/keyboard.hpp"
#include "mathematics/vertex2u.hpp"

namespace ece
{
	class InputEvent
	{
	public:
		enum InputEventType
		{
			ECE_TYPE_NONE = -1,
			ECE_MOUSE_PRESSED = 0,
			ECE_MOUSE_RELEASED = 1,
			ECE_MOUSE_MOVED = 2,
			ECE_MOUSE_SCROLLED = 3,
			ECE_KEY_PRESSED = 4,
			ECE_KEY_RELEASED = 5,
		};

		enum DoubleTap
		{
			ECE_TAP_NONE = -1,
			ECE_FIRST_OF = 0,
			ECE_LAST_OF = 1
		};

		inline InputEvent();

		InputEventType type;
		DoubleTap doubleTap;
		Mouse::Button mouseButton;
		IntVertex2u mousePosition;
		Keyboard::Key key;
	};
}

#include "window_event/input_event.inl"

#endif // INPUT_EVENT_HPP
