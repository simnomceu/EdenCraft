#include "Core\System\EventManager.hpp"

#include <iostream>

namespace ece
{
	EventManager::EventManager(): BaseEventManager(), signals(), slots(), signalsAvailable(), slotsAvailable()
	{
	}

	const Slot::GlobalSlotID EventManager::getSlotID()
	{
		auto id = this->slotsAvailable.next();
		return id;
	}

	const GlobalSignalID EventManager::getSignalID()
	{
		auto id = this->signalsAvailable.next();
		return id;
	}

	void EventManager::addSlot(const std::shared_ptr<ece::Slot>& slot)
	{
		this->slots[slot->getId()] = { slot, std::set<GlobalSignalID>() };
	}

	void EventManager::addSignal(const ece::GlobalSignalID signal)
	{
		this->signals[signal] = std::set<Slot::GlobalSlotID>();
	}

	void EventManager::eraseSlot(const  ece::Slot::GlobalSlotID slot)
	{
		auto & pos = this->slots.find(slot);
		if (pos != this->slots.end()) {
			auto & listened = pos->second.signals;
			for (auto it = listened.begin(); it != listened.end(); ++it) {
				auto & slots = this->signals[*it];
				slots.erase(slot);
			}

			this->slots.erase(slot);
			this->slotsAvailable.restack(slot);
		}
	}

	void EventManager::eraseSignal(const ece::GlobalSignalID signal)
	{
		auto & pos = this->signals.find(signal);
		if (pos != this->signals.end()) {
			auto & listener = pos->second;
			for (auto it = listener.begin(); it != listener.end(); ++it) {
				this->slots[*it].signals.erase(signal);
			}

			this->signals.erase(signal);
			this->signalsAvailable.restack(signal);
		}
	}

	void EventManager::connect(const ece::Listener & listener, const ece::SlotID slot, const ece::Emitter & emitter, const ece::SignalID signal)
	{
		const auto & tmpSlot = listener.getSlotID(slot);
		auto globalSignalID = emitter.getSignal(signal);
		if (this->slots.find(tmpSlot) != this->slots.end() && this->signals.find(globalSignalID) != this->signals.end()) {
			this->signals[globalSignalID].insert(tmpSlot);
			this->slots[tmpSlot].signals.insert(globalSignalID);
		}
	}

	void EventManager::disconnect(const ece::Listener & listener, const ece::SlotID slot, const ece::Emitter & emitter, const ece::SignalID signal)
	{
		const auto & tmpSlot = listener.getSlotID(slot);
		auto globalSignalID = emitter.getSignal(signal);
		if (this->slots.find(tmpSlot) != this->slots.end() && this->signals.find(globalSignalID) != this->signals.end()) {
			this->signals[globalSignalID].erase(tmpSlot);
			this->slots[tmpSlot].signals.erase(globalSignalID);
		}
	}

	void EventManager::broadcast(ece::Emitter & emitter, const ece::SignalID signal)
	{
		auto globalSignalID = emitter.getSignal(signal);
		if (this->signals.find(globalSignalID) != this->signals.end()) {
			auto & listeners = this->signals[globalSignalID];
			for (auto it = listeners.begin(); it != listeners.end(); ++it) {
				this->slots[*it].slot->trigger(emitter, signal);
			}
		}
	}
}