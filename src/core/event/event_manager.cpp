#include "core/event/event_manager.hpp"

#include <iostream>
#include <algorithm>

#include "core/event/listener.hpp"
#include "core/event/emitter.hpp"

namespace ece
{
	const Slot::GlobalSlotID  EventManager::addSlot(const Slot::Handle & handle)
	{
		this->_slotsNotReady.push_back(Slot(this->getSlotID(), handle));
		return this->_slotsNotReady.back().getId();
	}

	const Signal::GlobalSignalID EventManager::addSignal()
	{
		this->_signalsNotReady.push_back(Signal(this->getSignalID()));
		return this->_signalsNotReady.back().getId();
	}

	void EventManager::eraseSlot(const Listener & listener, const Slot::SlotID slot)
	{
		if (!this->_slots.empty()) {
			auto slotID = listener.getSlotID(slot);

			std::vector<Slot>::iterator it = std::find_if(this->_slots.begin(), this->_slots.end(), [slotID](Slot & sl) { return sl.getId() == slotID; });
			if (it != this->_slots.end()) {
				it->setDirty(true);
				for (auto connection = this->_connections.begin(); connection != this->_connections.end(); ++connection) {
					if (connection->getSlot() == slotID) {
						connection->setDirty(true);
					}
				}
			}
		}
	}

	void EventManager::eraseSignal(const Emitter & emitter, const Signal::SignalID signal)
	{
		if (!this->_signals.empty()) {
			auto signalID = emitter.getSignal(signal);

			std::vector<Signal>::iterator it = std::find_if(this->_signals.begin(), this->_signals.end(), [signalID](Signal & sig) { return sig.getId() == signalID; });
			if (it != this->_signals.end()) {
				it->setDirty(true);
				for (auto connection = this->_connections.begin(); connection != this->_connections.end(); ++connection) {
					if (connection->getSignal() == signalID) {
						connection->setDirty(true);
					}
				}
			}
		}
	}

	void EventManager::connect(const Listener & listener, const Slot::SlotID slot, const Emitter & emitter, const Signal::SignalID signal)
	{

		auto slotID = listener.getSlotID(slot);
		auto signalID = emitter.getSignal(signal);

		this->_connectionsNotReady.push_back(Connection(slotID, signalID));
	}

	void EventManager::disconnect(const Listener & listener, const Slot::SlotID slot, const Emitter & emitter, const Signal::SignalID signal)
	{
		if (!this->_connections.empty()) {
			auto slotID = listener.getSlotID(slot);
			auto signalID = emitter.getSignal(signal);

			auto pos = std::find_if(this->_connections.begin(), this->_connections.end(), [slotID, signalID](Connection & connection) { return connection.getSignal() == signalID && connection.getSlot() == slotID; });
			if (pos != this->_connections.end()) {
				pos->setDirty(true);
			}
		}
	}

	void EventManager::disconnectAll(const Listener & listener, const Slot::SlotID slot)
	{
		if (!this->_connections.empty()) {
			auto slotID = listener.getSlotID(slot);

			auto pos = std::find_if(this->_connections.begin(), this->_connections.end(), [slotID](Connection & connection) { return connection.getSlot() == slotID; });
			if (pos != this->_connections.end()) {
				pos->setDirty(true);
			}
		}
	}

	void EventManager::disconnectAll(const Emitter & emitter, const Signal::SignalID signal)
	{
		if (!this->_connections.empty()) {
			auto signalID = emitter.getSignal(signal);

			auto pos = std::find_if(this->_connections.begin(), this->_connections.end(), [signalID](Connection & connection) { return connection.getSignal() == signalID; });
			if (pos != this->_connections.end()) {
				pos->setDirty(true);
			}
		}
	}

	void EventManager::broadcast(const Emitter & emitter, const Signal::SignalID signal)
	{
		this->clear();
		if (!this->_signals.empty()) {
			auto const signalID = emitter.getSignal(signal);

			auto posSignal = std::find_if(this->_signals.begin(), this->_signals.end(), [signalID](Signal & signal) { return signal.getId() == signalID; });

			if (posSignal != this->_signals.end() && !posSignal->isDirty()) {
				for (auto it = this->_connections.begin(); it != this->_connections.end(); ++it) {
					if (it->getSignal() == signalID) {
						auto posSlot = std::find_if(this->_slots.begin(), this->_slots.end(), [it](Slot & slot) { return slot.getId() == it->getSlot(); });
						posSlot->trigger(emitter, signal);
					}
				}
			}
		}
	}

	void EventManager::clear()
	{
		if (!this->_slots.empty()) {
			auto & slotsAvailableRef = this->_slotsAvailable;
			this->_slots.erase(std::remove_if(this->_slots.begin(), this->_slots.end(), [&slotsAvailableRef](Slot & slot) {
				if (slot.isDirty()) {
					slotsAvailableRef.restack(slot.getId());
				}
				return slot.isDirty();
			}), this->_slots.end());
		}

		if (!this->_signals.empty()) {
			auto & signalsAvailableRef = this->_signalsAvailable;
			this->_signals.erase(std::remove_if(this->_signals.begin(), this->_signals.end(), [&signalsAvailableRef](Signal & signal) {
				if (signal.isDirty()) {
					signalsAvailableRef.restack(signal.getId());
				}
				return signal.isDirty();
			}), this->_signals.end());
		}

		if (!this->_connections.empty()) {
			this->_connections.erase(std::remove_if(this->_connections.begin(), this->_connections.end(), [](Connection & connection) {
				return connection.isDirty();
			}), this->_connections.end());
		}

		if (!this->_signalsNotReady.empty()) {
			this->_signals.insert(this->_signals.end(), this->_signalsNotReady.begin(), this->_signalsNotReady.end());
			this->_signalsNotReady.clear();
		}

		if (!this->_slotsNotReady.empty()) {
			this->_slots.insert(this->_slots.begin(), this->_slotsNotReady.begin(), this->_slotsNotReady.end());
			this->_slotsNotReady.clear();
		}

		if (!this->_connectionsNotReady.empty()) {
			for (auto it = this->_connectionsNotReady.begin(); it != this->_connectionsNotReady.end(); ++it) {
				bool existingSlot = !this->_slots.empty() && std::find_if(this->_slots.begin(), this->_slots.end(),
					[it](Slot & slot) { return slot.getId() == it->getSlot(); }) != this->_slots.end();

				bool existingSignal = !this->_signals.empty() && std::find_if(this->_signals.begin(), this->_signals.end(),
					[it](Signal & signal) { return signal.getId() == it->getSignal(); }) != this->_signals.end();

				bool existingConnection = !this->_connections.empty() && std::find_if(this->_connections.begin(), this->_connections.end(),
					[it](Connection & connection) { return connection == *it; }) != this->_connections.end();

				if (existingSlot && existingSignal && !existingConnection) {
					this->_connections.push_back(*it);
				}
			}
			this->_connectionsNotReady.clear();
		}
	}
}
