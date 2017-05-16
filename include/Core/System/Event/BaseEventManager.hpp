#ifndef BASEEVENTMANAGER_HPP
#define BASEEVENTMANAGER_HPP

#include "System\Event\Slot.hpp"
#include "System\Event\Signal.hpp"
#include "UniqueID.hpp"

namespace ece
{
	class EventManagerConsumer;
	class Listener;
	class Emitter;

	class BaseEventManager
	{
	public:
		virtual const Slot::GlobalSlotID addSlot(const Slot::Handle & handle) = 0;
		virtual const Signal::GlobalSignalID addSignal() = 0;
		virtual void eraseSlot(const Listener & listener, const Slot::SlotID slot) = 0;
		virtual void eraseSignal(const Emitter & emitter, const Signal::SignalID signal) = 0;
		virtual void connect(const Listener & listener, const Slot::SlotID slot, const Emitter & emitter, const Signal::SignalID signal) = 0;
		virtual void disconnect(const Listener & listener, const Slot::SlotID slot, const Emitter & emitter, const Signal::SignalID signal) = 0;
		virtual void disconnectAll(const Listener & listener, const Slot::SlotID slot) = 0;
		virtual void disconnectAll(const Emitter & emitter, const Signal::SignalID signal) = 0;

		virtual void broadcast(const Emitter & emitter, const Signal::SignalID signal) = 0;
		virtual void clear() = 0;
	};
}

#endif // EVENTMANAGER_HPP
