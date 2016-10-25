#ifndef EVENTMANAGERNONE_HPP
#define EVENTMANAGERNONE_HPP

#include "Core\System\BaseEventManager.hpp"

namespace ece
{
	class EventManagerNone : public BaseEventManager
	{
	public:
		void registerSignal(const ece::SignalID & signal);
		void broadcast(const ece::SignalID & signal);
		void connect(const ece::Slot & slot, const ece::SignalID & signal);
	};
}

#endif // EVENTMANAGERNONE_HPP
