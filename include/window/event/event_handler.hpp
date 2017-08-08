#ifndef EVENT_HANDLER_HPP
#define EVENT_HANDLER_HPP

#include "event\emitter.hpp"

#include "window\window.inl"

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

#include "event\event_handler.inl"

#endif // EVENT_HANDLER_HPP
