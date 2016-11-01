#include "Core\System\Listener.hpp"

#include "Core\System\EventManagerLocator.hpp"

namespace ece
{
	Listener::Listener(): slots()
	{
	}

	Listener::~Listener()
	{
		this->slots.clear();
	}

	void Listener::addSlot(const ece::SlotID id, const std::shared_ptr<ece::Slot> & slot)
	{
		if (this->slots.find(id) == this->slots.end()) {
			this->slots[id] = slot;
		}
	}

	void Listener::removeSlot(const ece::SlotID slot)
	{
		ece::EventManagerLocator::getService().eraseSlot(this->slots[slot]);

		this->slots.erase(slot);
	}

	const std::shared_ptr<Slot> & Listener::getSlot(const ece::SlotID slot) const
	{
		return this->slots.at(slot);
	}
}
