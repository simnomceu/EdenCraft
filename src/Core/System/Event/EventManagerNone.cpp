#include "Core\System\Event\EventManagerNone.hpp"

namespace ece
{

	const Slot::GlobalSlotID  EventManagerNone::addSlot(const Slot::Handle & handle)
	{
		return -1;
	}

	const Signal::GlobalSignalID EventManagerNone::addSignal()
	{
		return -1;
	}

	void EventManagerNone::eraseSlot(const Listener & listener, const Slot::SlotID slot)
	{
	}

	void EventManagerNone::eraseSignal(const Emitter & emitter, const Signal::SignalID signal)
	{
	}

	void EventManagerNone::connect(const Listener & listener, const Slot::SlotID slot, const Emitter & emitter, const Signal::SignalID signal)
	{
	}

	void EventManagerNone::disconnect(const Listener & listener, const Slot::SlotID slot, const Emitter & emitter, const Signal::SignalID signal)
	{
	}

	void EventManagerNone::disconnectAll(const Listener & listener, const Slot::SlotID slot)
	{
	}

	void EventManagerNone::disconnectAll(const Emitter & emitter, const Signal::SignalID signal)
	{
	}

	void EventManagerNone::broadcast(const Emitter & emitter, const Signal::SignalID signal)
	{
	}

	void EventManagerNone::clear()
	{
	}
}
