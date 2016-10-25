#include "Core\System\Listener.hpp"

#include "Core\System\EventManagerLocator.hpp"

namespace ece
{
	Listener::Listener(): slots()
	{
	}

	void Listener::addSlot(const ece::Slot & slot)
	{
		this->slots[slot.getId()] = slot;
	}

	void Listener::connect(const ece::SlotID & slot, const ece::SignalID & signal)
	{
		ece::EventManagerLocator::getService().connect(this->slots[slot], signal);
	}
}
