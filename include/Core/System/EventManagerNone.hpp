#ifndef EVENTMANAGERNONE_HPP
#define EVENTMANAGERNONE_HPP

#include "Core\System\BaseEventManager.hpp"

namespace ece
{
	class EventManagerNone : public BaseEventManager
	{
	public:
		virtual const Slot::GlobalSlotID getSlotID();
		virtual const GlobalSignalID getSignalID();

		virtual void addSlot(const std::shared_ptr<ece::Slot> & slot);
		virtual void addSignal(const ece::GlobalSignalID signal);

		virtual void eraseSlot(const ece::Slot::GlobalSlotID slot);
		virtual void eraseSignal(const ece::GlobalSignalID signal);

		virtual void connect(const ece::Listener & listener, const ece::SlotID slot, const ece::Emitter & emitter, const ece::SignalID signal);
		virtual void disconnect(const ece::Listener & listener, const ece::SlotID slot, const ece::Emitter & emitter, const ece::SignalID signal);

		virtual void broadcast(ece::Emitter & emitter, const ece::SignalID signal);
	};
}

#endif // EVENTMANAGERNONE_HPP
