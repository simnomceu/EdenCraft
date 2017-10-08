namespace ece
{
	inline const Slot::GlobalSlotID  EventManagerNone::addSlot(const Slot::Handle & handle) { return -1; }

	inline const Signal::GlobalSignalID EventManagerNone::addSignal() { return -1; }

	inline void EventManagerNone::eraseSlot(const Listener & listener, const Slot::SlotID slot) {}

	inline void EventManagerNone::eraseSignal(const Emitter & emitter, const Signal::SignalID signal) {}

	inline void EventManagerNone::connect(const Listener & listener, const Slot::SlotID slot, const Emitter & emitter, const Signal::SignalID signal) {}

	inline void EventManagerNone::disconnect(const Listener & listener, const Slot::SlotID slot, const Emitter & emitter, const Signal::SignalID signal) {}

	inline void EventManagerNone::disconnectAll(const Listener & listener, const Slot::SlotID slot) {}

	inline void EventManagerNone::disconnectAll(const Emitter & emitter, const Signal::SignalID signal) {}

	inline void EventManagerNone::broadcast(const Emitter & emitter, const Signal::SignalID signal) {}

	inline void EventManagerNone::clear() {}
}