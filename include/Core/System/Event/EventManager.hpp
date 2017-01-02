#ifndef EVENTMANAGER_HPP
#define EVENTMANAGER_HPP

#include "Core\System\Event\BaseEventManager.hpp"
#include "Core\Util\UniqueID.hpp"

#include <vector>

#include <memory>

namespace ece
{
	class EventManager: public BaseEventManager
	{
	public:
		EventManager();
		virtual const Slot::GlobalSlotID addSlot(const Slot::Handle & handle);
		virtual const Signal::GlobalSignalID addSignal();

		virtual void eraseSlot(const Listener & listener, const Slot::SlotID slot);
		virtual void eraseSignal(const Emitter & emitter, const Signal::SignalID signal);

		virtual void connect(const Listener & listener, const Slot::SlotID slot, const Emitter & emitter, const Signal::SignalID signal);
		virtual void disconnect(const Listener & listener, const Slot::SlotID slot, const Emitter & emitter, const Signal::SignalID signal);
		virtual void disconnectAll(const Listener & listener, const Slot::SlotID slot);
		virtual void disconnectAll(const Emitter & emitter, const Signal::SignalID signal);

		virtual void broadcast(const Emitter & emitter, const Signal::SignalID signal);
		virtual void clear();

	private:
		const Slot::GlobalSlotID getSlotID();
		const Signal::GlobalSignalID getSignalID();

		std::vector<Signal> signals;
		std::vector<Slot> slots;
		std::vector<Connection> connections;

		std::vector<Signal> signalsNotReady;
		std::vector<Slot> slotsNotReady;
		std::vector<Connection> connectionsNotReady;

		UniqueID signalsAvailable;
		UniqueID slotsAvailable;
	};
}

#endif // EVENTMANAGER_HPP
