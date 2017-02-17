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
		static EventHandler & getInstance();

		EventHandler() = default;
		~EventHandler();

		void produceKeyEvent(const int key, const int scancode, const int action, const int mods);
		void produceMouseButtonEvent(const int button, const int action, const int mods);

	private:

	};
}

#endif // EVENT_HANDLER
