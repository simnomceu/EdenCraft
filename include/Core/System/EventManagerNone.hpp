#ifndef EVENTMANAGERNONE_HPP
#define EVENTMANAGERNONE_HPP

#include "Core\System\BaseEventManager.hpp"

namespace ece
{
	class EventManagerNone : public BaseEventManager
	{
	public:
		virtual void registerSlot(const std::shared_ptr<ece::Slot> & slot);
		virtual void eraseSlot(const ece::SlotID & slot);

		virtual void registerSignal(const ece::SignalID & signal);
		virtual void eraseSignal(const ece::SignalID & signal);

		virtual void connect(const ece::SlotID & slot, const ece::SignalID & signal);
		virtual void disconnect(const ece::SlotID & slot, const ece::SignalID & signal);

		virtual void broadcast(const ece::SignalID & signal);
	};
}

#endif // EVENTMANAGERNONE_HPP
