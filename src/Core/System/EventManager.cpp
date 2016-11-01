#include "Core\System\EventManager.hpp"

namespace ece
{
	EventManager::EventManager(): BaseEventManager(), signals(), slots(), signalsAvailable(), slotsAvailable()
	{
	}

	const GlobalSlotID EventManager::getSlotID()
	{
		GlobalSlotID id = this->slotsAvailable.next();
		this->slots[id] = std::set<ece::GlobalSignalID>();
		return id;
	}

	const GlobalSignalID EventManager::getSignalID()
	{
		auto id = this->signalsAvailable.next();
		this->signals[id] = std::set<std::shared_ptr<ece::Slot>>();
		return id;
	}

	void EventManager::eraseSlot(const std::shared_ptr<ece::Slot> & slot)
	{
		auto & pos = this->slots.find(slot->getId());
		if (pos != this->slots.end()) {
			auto & listened = pos->second;
			for (auto it = listened.begin(); it != listened.end(); ++it) {
				auto & slots = this->signals[*it];
				slots.erase(slot);
			}

			this->slots.erase(slot->getId());
			this->slotsAvailable.restack(slot->getId());
		}
	}

	void EventManager::eraseSignal(const ece::GlobalSignalID signal)
	{
		auto & pos = this->signals.find(signal);
		if (pos != this->signals.end()) {
			auto & listener = pos->second;
			for (auto it = listener.begin(); it != listener.end(); ++it) {
				this->slots[(*it)->getId()].erase(signal);
			}

			this->signals.erase(signal);
			this->signalsAvailable.restack(signal);
		}
	}

	void EventManager::connect(const ece::Listener & listener, const ece::SlotID slot, const ece::Emitter & emitter, const ece::SignalID signal)
	{
		auto & tmpSlot = listener.getSlot(slot);
		auto globalSignalID = emitter.getSignal(signal);
		if (this->slots.find(tmpSlot->getId()) != this->slots.end() && this->signals.find(globalSignalID) != this->signals.end()) {
			this->signals[globalSignalID].insert(tmpSlot);
			this->slots[tmpSlot->getId()].insert(globalSignalID);
		}
	}

	void EventManager::disconnect(const ece::Listener & listener, const ece::SlotID slot, const ece::Emitter & emitter, const ece::SignalID signal)
	{
		auto & tmpSlot = listener.getSlot(slot);
		auto globalSignalID = emitter.getSignal(signal);
		if (this->slots.find(tmpSlot->getId()) != this->slots.end() && this->signals.find(globalSignalID) != this->signals.end()) {
			this->signals[globalSignalID].erase(tmpSlot);
			this->slots[tmpSlot->getId()].erase(globalSignalID);
		}
	}

	void EventManager::broadcast(ece::Emitter & emitter, const ece::SignalID signal)
	{
		auto globalSignalID = emitter.getSignal(signal);
		if (this->signals.find(globalSignalID) != this->signals.end()) {
			auto & listeners = this->signals[globalSignalID];
			for (auto it = listeners.begin(); it != listeners.end(); ++it) {
				(*it)->trigger();
			}
		}
	}
}