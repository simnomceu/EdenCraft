#include "Core\System\Event\EventManager.hpp"

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
		try {
			const auto & tmpSlot = listener.getSlotID(slot);
			auto globalSignalID = emitter.getSignal(signal);
			if (this->slots.find(tmpSlot) != this->slots.end() && this->signals.find(globalSignalID) != this->signals.end()) {
				if (!this->inBroadcast) {
					this->signals[globalSignalID].insert(tmpSlot);
					this->slots[tmpSlot].signals.insert(globalSignalID);
				}
				else {
					this->signalsNotReady[globalSignalID].insert(tmpSlot);
					this->slotsNotReady[tmpSlot].signals.insert(globalSignalID);
				}
			}
		}
		catch (std::exception & e) {
			std::cerr << "Error, the slot " << slot << " and the signal " << signal << " cannot be connected: " << e.what() << std::endl;
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
		bool recurseBroadcast = this->inBroadcast;
		this->inBroadcast = true;

		auto globalSignalID = emitter.getSignal(signal);
		if (this->signals.find(globalSignalID) != this->signals.end()) {
			auto & listeners = this->signals[globalSignalID];
			for (auto it = listeners.begin(); it != listeners.end(); ++it) {
				this->slots[*it].slot->trigger(emitter, signal);
			}
		}

		if (!recurseBroadcast) {
			// Add the connections created during the broadcast.
			for (auto it = this->signalsNotReady.begin(); it != this->signalsNotReady.end(); ++it) {
				this->signals[it->first].insert(it->second.begin(), it->second.end());
			}
			for (auto it = this->slotsNotReady.begin(); it != this->slotsNotReady.end(); ++it) {
				this->slots[it->first].signals.insert(it->second.signals.begin(), it->second.signals.end());
			}
			this->signalsNotReady.clear();
			this->slotsNotReady.clear();
			this->inBroadcast = false;
		}
	}
}