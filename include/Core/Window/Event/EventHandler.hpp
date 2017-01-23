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
		EventHandler(BaseWindow & window);
		~EventHandler();

		const WindowID getWindowAttached() const;

		void produceEvent(const int key, const int scancode, const int action, const int mods);

	private:
		BaseWindow & windowAttached;
	};
}

#endif // EVENT_HANDLER
