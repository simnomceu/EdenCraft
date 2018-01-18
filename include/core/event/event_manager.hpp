#ifndef EVENT_MANAGER_HPP
#define EVENT_MANAGER_HPP

#include "core/event/base_event_manager.hpp"
#include "core/event/connection.hpp"

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

		std::vector<Signal> _signals;
		std::vector<Slot> _slots;
		std::vector<Connection> _connections;

		std::vector<Signal> _signalsNotReady;
		std::vector<Slot> _slotsNotReady;
		std::vector<Connection> _connectionsNotReady;

		UniqueID _signalsAvailable;
		UniqueID _slotsAvailable;
	};
}

#include "core/event/event_manager.inl"

#endif // EVENT_MANAGER_HPP
