#ifndef EVENTMANAGERNONE_HPP
#define EVENTMANAGERNONE_HPP

#include "Event\BaseEventManager.hpp"

namespace ece
{
	class EventManagerNone : public BaseEventManager
	{
	public:
		inline virtual const Slot::GlobalSlotID addSlot(const Slot::Handle & handle) override;
		inline virtual const Signal::GlobalSignalID addSignal() override;

		inline virtual void eraseSlot(const Listener & listener, const Slot::SlotID slot) override;
		inline virtual void eraseSignal(const Emitter & emitter, const Signal::SignalID signal) override;

		inline virtual void connect(const Listener & listener, const Slot::SlotID slot, const Emitter & emitter, const Signal::SignalID signal) override;
		inline virtual void disconnect(const Listener & listener, const Slot::SlotID slot, const Emitter & emitter, const Signal::SignalID signal) override;
		inline virtual void disconnectAll(const Listener & listener, const Slot::SlotID slot) override;
		inline virtual void disconnectAll(const Emitter & emitter, const Signal::SignalID signal) override;

		inline virtual void broadcast(const Emitter & emitter, const Signal::SignalID signal) override;
		inline virtual void clear() override;
	};
}

#include "Event\EventManagerNone.inl"

#endif // EVENTMANAGERNONE_HPP
