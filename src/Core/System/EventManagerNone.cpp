#include "Core\System\EventManagerNone.hpp"

namespace ece
{
	void EventManagerNone::registerSlot(const std::shared_ptr<ece::Slot>& slot)
	{
	}

	void EventManagerNone::eraseSlot(const ece::SlotID & slot)
	{
	}

	void EventManagerNone::registerSignal(const ece::SignalID & signal)
	{
	}

	void EventManagerNone::eraseSignal(const ece::SignalID & signal)
	{
	}

	void EventManagerNone::connect(const ece::SlotID & slot, const ece::SignalID & signal)
	{
	}

	void EventManagerNone::disconnect(const ece::SlotID & slot, const ece::SignalID & signal)
	{
	}

	void EventManagerNone::broadcast(const ece::SignalID & signal)
	{
	}
}
