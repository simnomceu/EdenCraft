#ifndef EVENTHANDLER_HPP
#define EVENTHANDLER_HPP

#include "System\Event\Emitter.hpp"

#include "Window\Window.inl"

namespace ece
{
	class BaseWindow;

	class EventHandler: public Emitter
	{
	public:
		static EventHandler & getInstance();

		inline ~EventHandler();

		void produceKeyEvent(const int key, const int scancode, const int action, const int mods);
		void produceMouseButtonEvent(const int button, const int action, const int mods);

	private:
		EventHandler() = default;

	};
}

#include "Event\EventHandler.inl"

#endif // EVENT_HANDLER
