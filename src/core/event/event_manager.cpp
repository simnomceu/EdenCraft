#include "event\event_manager.hpp"

#include <iostream>
#include <algorithm>

#include "event\listener.hpp"
#include "event\emitter.hpp"

namespace ece
{
	const Slot::GlobalSlotID  EventManager::addSlot(const Slot::Handle & handle)
	{
		this->slotsNotReady.push_back(Slot(this->getSlotID(), handle));
		return this->slotsNotReady.back().getId();
	}

	const Signal::GlobalSignalID EventManager::addSignal()
	{
		this->signalsNotReady.push_back(Signal(this->getSignalID()));
		return this->signalsNotReady.back().getId();
	}

	void EventManager::eraseSlot(const Listener & listener, const Slot::SlotID slot)
	{
		if (!this->slots.empty()) {
			auto slotID = listener.getSlotID(slot);

			std::vector<Slot>::iterator it = std::find_if(this->slots.begin(), this->slots.end(), [slotID](Slot & sl) { return sl.getId() == slotID; });
			if (it != this->slots.end()) {
				it->setDirty(true);
				for (auto it = this->connections.begin(); it != this->connections.end(); ++it) {
					if (it->getSlot() == slotID) {
						it->setDirty(true);
					}
				}
			}
		}
	}

	void EventManager::eraseSignal(const Emitter & emitter, const Signal::SignalID signal)
	{
		if (!this->signals.empty()) {
			auto signalID = emitter.getSignal(signal);

			std::vector<Signal>::iterator it = std::find_if(this->signals.begin(), this->signals.end(), [signalID](Signal & sig) { return sig.getId() == signalID; });
			if (it != this->signals.end()) {
				it->setDirty(true);
				for (auto it = this->connections.begin(); it != this->connections.end(); ++it) {
					if (it->getSignal() == signalID) {
						it->setDirty(true);
					}
				}
			}
		}
	}

	void EventManager::connect(const Listener & listener, const Slot::SlotID slot, const Emitter & emitter, const Signal::SignalID signal)
	{

		auto slotID = listener.getSlotID(slot);
		auto signalID = emitter.getSignal(signal);

		this->connectionsNotReady.push_back(Connection(slotID, signalID));
	}

	void EventManager::disconnect(const Listener & listener, const Slot::SlotID slot, const Emitter & emitter, const Signal::SignalID signal)
	{
		if (!this->connections.empty()) {
			auto slotID = listener.getSlotID(slot);
			auto signalID = emitter.getSignal(signal);

			auto pos = std::find_if(this->connections.begin(), this->connections.end(), [slotID, signalID](Connection & connection) { return connection.getSignal() == signalID && connection.getSlot() == slotID; });
			if (pos != this->connections.end()) {
				pos->setDirty(true);
			}
		}
	}

	void EventManager::disconnectAll(const Listener & listener, const Slot::SlotID slot)
	{
		if (!this->connections.empty()) {
			auto slotID = listener.getSlotID(slot);

			auto pos = std::find_if(this->connections.begin(), this->connections.end(), [slotID](Connection & connection) { return connection.getSlot() == slotID; });
			if (pos != this->connections.end()) {
				pos->setDirty(true);
			}
		}
	}

	void EventManager::disconnectAll(const Emitter & emitter, const Signal::SignalID signal)
	{
		if (!this->connections.empty()) {
			auto signalID = emitter.getSignal(signal);

			auto pos = std::find_if(this->connections.begin(), this->connections.end(), [signalID](Connection & connection) { return connection.getSignal() == signalID; });
			if (pos != this->connections.end()) {
				pos->setDirty(true);
			}
		}
	}

	void EventManager::broadcast(const Emitter & emitter, const Signal::SignalID signal)
	{
		this->clear();
		if (!this->signals.empty()) {
			auto const signalID = emitter.getSignal(signal);

			auto posSignal = std::find_if(this->signals.begin(), this->signals.end(), [signalID](Signal & signal) { return signal.getId() == signalID; });

			if (posSignal != this->signals.end() && !posSignal->isDirty()) {
				for (auto & it = this->connections.begin(); it != this->connections.end(); ++it) {
					if (it->getSignal() == signalID) {
						auto posSlot = std::find_if(this->slots.begin(), this->slots.end(), [it](Slot & slot) { return slot.getId() == it->getSlot(); });
						posSlot->trigger(emitter, signal);
					}
				}
			}
		}
	}

	void EventManager::clear()
	{
		if (!this->slots.empty()) {
			auto & slotsAvailableRef = this->slotsAvailable;
			this->slots.erase(std::remove_if(this->slots.begin(), this->slots.end(), [&slotsAvailableRef](Slot & slot) {
				if (slot.isDirty()) {
					slotsAvailableRef.restack(slot.getId());
				}
				return slot.isDirty();
			}), this->slots.end());
		}

		if (!this->signals.empty()) {
			auto & signalsAvailableRef = this->signalsAvailable;
			this->signals.erase(std::remove_if(this->signals.begin(), this->signals.end(), [&signalsAvailableRef](Signal & signal) {
				if (signal.isDirty()) {
					signalsAvailableRef.restack(signal.getId());
				}
				return signal.isDirty();
			}), this->signals.end());
		}

		if (!this->connections.empty()) {
			this->connections.erase(std::remove_if(this->connections.begin(), this->connections.end(), [](Connection & connection) {
				return connection.isDirty();
			}), this->connections.end());
		}

		if (!this->signalsNotReady.empty()) {
			this->signals.insert(this->signals.end(), this->signalsNotReady.begin(), this->signalsNotReady.end());
			this->signalsNotReady.clear();
		}

		if (!this->slotsNotReady.empty()) {
			this->slots.insert(this->slots.begin(), this->slotsNotReady.begin(), this->slotsNotReady.end());
			this->slotsNotReady.clear();
		}

		if (!this->connectionsNotReady.empty()) {
			for (auto it = this->connectionsNotReady.begin(); it != this->connectionsNotReady.end(); ++it) {
				bool existingSlot = !this->slots.empty() && std::find_if(this->slots.begin(), this->slots.end(),
					[it](Slot & slot) { return slot.getId() == it->getSlot(); }) != this->slots.end();

				bool existingSignal = !this->signals.empty() && std::find_if(this->signals.begin(), this->signals.end(),
					[it](Signal & signal) { return signal.getId() == it->getSignal(); }) != this->signals.end();

				bool existingConnection = !this->connections.empty() && std::find_if(this->connections.begin(), this->connections.end(),
					[it](Connection & connection) { return connection == *it; }) != this->connections.end();

				if (existingSlot && existingSignal && !existingConnection) {
					this->connections.push_back(*it);
				}
			}
			this->connectionsNotReady.clear();
		}
	}
}