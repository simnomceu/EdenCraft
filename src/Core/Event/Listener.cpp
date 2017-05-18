#include "Event\Listener.hpp"

#include "Debug\Exception.hpp"

#include <iostream>

namespace ece
{
	void Listener::addSlot(const Slot::SlotID slot, const Slot::Handle & handle)
	{
		try {
			if (this->slots.find(slot) == this->slots.end()) {
				this->slots[slot] = this->consumer.consume()->addSlot(handle);
			}
		}
		catch (MemoryAccessException & e) {
			// TODO: use the logger
			std::cerr << "Slot cannot be added: " << e.what() << std::endl;
		}
	}

	void Listener::removeSlot(const Slot::SlotID slot)
	{
		try {
			this->consumer.consume()->eraseSlot(*this, slot);

			this->slots.erase(slot);
		}
		catch (MemoryAccessException & e) {
			// TODO: use the logger
			std::cerr << "Slot cannot be removed: " << e.what() << std::endl;
		}
	}

	const Slot::GlobalSlotID Listener::getSlotID(const Slot::SlotID slot) const
	{
		if (this->slots.find(slot) == this->slots.end()) {
			throw OutOfRangeException::makeException("slot", slot);
		}
		return this->slots.at(slot);
	}

	void Listener::connect(const Slot::SlotID slot, const Emitter & emitter, const Signal::SignalID signal)
	{
		try {
			if (this->slots.find(slot) != this->slots.end()) {
				this->consumer.consume()->connect(*this, slot, emitter, signal);
			}
		}
		catch (MemoryAccessException & e) {
			// TODO: use the logger
			std::cerr << "Slot cannot be connected to a signal: " << e.what() << std::endl;
		}
	}

	void Listener::disconnect(const Slot::SlotID slot, const Emitter & emitter, const Signal::SignalID signal)
	{
		try {
			if (this->slots.find(slot) != this->slots.end()) {
				this->consumer.consume()->disconnect(*this, slot, emitter, signal);
			}
		}
		catch (MemoryAccessException & e) {
			// TODO: use the logger
			std::cerr << "Slot cannot be disconnected from a signal: " << e.what() << std::endl;
		}
	}

	void Listener::disconnectAll()
	{
		try {
			for (auto it = this->slots.begin(); it != this->slots.end(); ++it) {
				this->consumer.consume()->disconnectAll(*this, it->second);
			}
		}
		catch (MemoryAccessException & e) {
			// TODO: use the logger
			std::cerr << "Slot cannot be disconnected from signals: " << e.what() << std::endl;
		}
	}

	void Listener::clear()
	{
		try {
			for (auto it = this->slots.begin(); it != this->slots.end(); ++it) {
				this->consumer.consume()->eraseSlot(*this, it->first);
			}
			this->slots.clear();
		}
		catch (MemoryAccessException & e) {
			// TODO: use the logger
			std::cerr << "Listener cannot be cleared: " << e.what() << std::endl;
		}
	}
}
