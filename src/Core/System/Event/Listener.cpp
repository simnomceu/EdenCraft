#include "Core\System\Event\Listener.hpp"

#include "Core\System\EventService.hpp"

namespace ece
{
	Listener::Listener(): slots()
	{
	}

	Listener::~Listener()
	{
		for (auto it = this->slots.begin(); it != this->slots.end(); ++it) {
			ece::EventServiceLocator::getService().eraseSlot(it->second);
		}
		this->slots.clear();
	}

	void Listener::addSlot(const ece::SlotID id, const std::shared_ptr<ece::Slot> & slot)
	{
		if (this->slots.find(id) == this->slots.end()) {
			this->slots[id] = slot->getId();
			ece::EventServiceLocator::getService().addSlot(slot);
		}
	}

	void Listener::removeSlot(const ece::SlotID slot)
	{
		ece::EventServiceLocator::getService().eraseSlot(this->slots[slot]);

		this->slots.erase(slot);
	}

	const Slot::GlobalSlotID Listener::getSlotID(const ece::SlotID slot) const
	{
		if (this->slots.find(slot) == this->slots.end()) {
			throw std::exception();
		}
		return this->slots.at(slot);
	}
	
	void Listener::connect(const ece::SlotID slot, const ece::Emitter & emitter, const ece::SignalID signal)
	{
		if (this->slots.find(slot) != this->slots.end()) {
			ece::EventServiceLocator::getService().connect(*this, slot, emitter, signal);
		}
	}
}
