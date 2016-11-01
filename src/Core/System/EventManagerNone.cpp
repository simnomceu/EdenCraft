#include "Core\System\EventManagerNone.hpp"

namespace ece
{
	const SlotID EventManagerNone::getSlotID()
	{
		return 0;
	}

	const SignalID EventManagerNone::getSignalID()
	{
		return 0;
	}

	void EventManagerNone::eraseSlot(const std::shared_ptr<ece::Slot> & slot)
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
