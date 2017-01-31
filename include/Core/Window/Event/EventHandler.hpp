#ifndef EVENTHANDLER_HPP
#define EVENTHANDLER_HPP

#include "Core\System\Event\Emitter.hpp"

#include "Core\Window\Window\Window.inl"

namespace ece
{
	class BaseWindow;

	class EventHandler: public Emitter
	{
	public:
		const Signal::SignalID KEY_PRESSED = 0;
		const Signal::SignalID KEY_RELEASED = 1;
		const Signal::SignalID MOUSE_BUTTON_PRESSED = 2;
		const Signal::SignalID MOUSE_BUTTON_RELEASED = 3;
		const Signal::SignalID MOUSE_WHEEL_SCROLLED = 4;

		static EventHandler & getInstance();

		EventHandler();
		~EventHandler();

		void produceKeyEvent(const int key, const int scancode, const int action, const int mods);
		void produceMouseButtonEvent(const int button, const int action, const int mods);

	private:

	};
}

#endif // EVENT_HANDLER
