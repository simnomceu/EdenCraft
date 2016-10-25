#include "Core\System\EventManagerNone.hpp"

namespace ece
{
	void EventManagerNone::registerSignal(const ece::SignalID & signal)
	{
	}

	void EventManagerNone::broadcast(const ece::SignalID & signal)
	{
	}

	void EventManagerNone::connect(const ece::Slot & slot, const ece::SignalID & signal)
	{
	}
}
