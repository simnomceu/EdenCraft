#ifndef EVENTMANAGER_HPP
#define EVENTMANAGER_HPP

#include "System\Event\BaseEventManager.hpp"
#include "System\Event\Connection.hpp"

#include <vector>

#include <memory>

namespace ece
{
	class EventManager: public BaseEventManager
	{
	public:
		inline EventManager();
		virtual const Slot::GlobalSlotID addSlot(const Slot::Handle & handle) override;
		virtual const Signal::GlobalSignalID addSignal() override;

		virtual void eraseSlot(const Listener & listener, const Slot::SlotID slot) override;
		virtual void eraseSignal(const Emitter & emitter, const Signal::SignalID signal) override;

		virtual void connect(const Listener & listener, const Slot::SlotID slot, const Emitter & emitter, const Signal::SignalID signal) override;
		virtual void disconnect(const Listener & listener, const Slot::SlotID slot, const Emitter & emitter, const Signal::SignalID signal) override;
		virtual void disconnectAll(const Listener & listener, const Slot::SlotID slot) override;
		virtual void disconnectAll(const Emitter & emitter, const Signal::SignalID signal) override;

		virtual void broadcast(const Emitter & emitter, const Signal::SignalID signal) override;
		virtual void clear() override;

	private:
		inline const Slot::GlobalSlotID getSlotID();
		inline const Signal::GlobalSignalID getSignalID();

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

#include "System\Event\EventManager.inl"

#endif // EVENTMANAGER_HPP
