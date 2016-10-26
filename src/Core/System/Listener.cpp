#include "Core\System\Listener.hpp"

#include "Core\System\EventManagerLocator.hpp"

namespace ece
{
	Listener::Listener(): slots()
	{
	}

	Listener::~Listener()
	{
		for (auto it = this->slots.begin(); it != this->slots.end(); ++it) {
			ece::EventManagerLocator::getService().eraseSlot(it->first);
		}
	}

	void Listener::addSlot(const std::shared_ptr<ece::Slot> & slot)
	{
		if (this->slots.find(slot->getId()) == this->slots.end()) {
			this->slots[slot->getId()] = slot;
		}
		ece::EventManagerLocator::getService().registerSlot(slot);
	}

	void Listener::removeSlot(const ece::SlotID & slot)
	{
		if (this->slots.find(slot) != this->slots.end()) {
			this->slots.erase(slot);
		}
		ece::EventManagerLocator::getService().eraseSlot(slot);
	}

	void Listener::connect(const ece::SlotID & slot, const ece::SignalID & signal)
	{
		ece::EventManagerLocator::getService().connect(slot, signal);
	}
}
