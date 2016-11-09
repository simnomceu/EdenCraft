#include "Core\System\Event\EventManagerNone.hpp"

namespace ece
{
	const Slot::GlobalSlotID EventManagerNone::getSlotID()
	{
		return 0;
	}

	const GlobalSignalID EventManagerNone::getSignalID()
	{
		return 0;
	}

	void EventManagerNone::addSlot(const std::shared_ptr<ece::Slot>& slot)
	{
	}

	void EventManagerNone::addSignal(const ece::GlobalSignalID signal)
	{
	}

	void EventManagerNone::eraseSlot(const  ece::Slot::GlobalSlotID slot)
	{
	}

	void EventManagerNone::eraseSignal(const ece::GlobalSignalID signal)
	{
	}

	void EventManagerNone::connect(const ece::Listener & listener, const ece::SlotID slot, const ece::Emitter & emitter, const ece::SignalID signal)
	{
	}

	void EventManagerNone::disconnect(const ece::Listener & listener, const ece::SlotID slot, const ece::Emitter & emitter, const ece::SignalID signal)
	{
	}

	void EventManagerNone::broadcast(ece::Emitter & emitter, const ece::SignalID signal)
	{
	}
}
