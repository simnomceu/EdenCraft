#include "Core\System\EventManager.hpp"

namespace ece
{
	void EventManager::registerSlot(const std::shared_ptr<ece::Slot>& slot)
	{
		if (this->slots.find(slot->getId()) == this->slots.end()) {
			this->slots[slot->getId()] = slot;
		}
	}

	void EventManager::eraseSlot(const ece::SlotID & slot)
	{
		if (this->slots.find(slot) != this->slots.end()) {
			this->slots.erase(slot);
			for (auto it = this->matcher.begin(); it != this->matcher.end(); ++it) {
				auto & connections = it->second;
				connections.erase(std::find(connections.begin(), connections.end(), slot));
			}
		}
	}

	void EventManager::registerSignal(const ece::SignalID & signal)
	{
		if (this->matcher.find(signal) == this->matcher.end()) {
			this->matcher[signal] = std::vector<ece::SlotID>();
		}
	}

	void EventManager::eraseSignal(const ece::SignalID & signal)
	{
		if (this->matcher.find(signal) != this->matcher.end()) {
			this->matcher.erase(signal);
		}
	}

	void EventManager::connect(const ece::SlotID & slot, const ece::SignalID & signal)
	{
		if (this->matcher.find(signal) != this->matcher.end() && this->slots.find(slot) != this->slots.end()) {
			auto & connections = this->matcher[signal];
			if (std::find(connections.begin(), connections.end(), slot) == connections.end()) {
				connections.push_back(slot);
			}
		}
	}

	void EventManager::disconnect(const ece::SlotID & slot, const ece::SignalID & signal)
	{
		if (this->matcher.find(signal) != this->matcher.end() && this->slots.find(slot) != this->slots.end()) {
			auto & connections = this->matcher[signal];
			auto pos = std::find(connections.begin(), connections.end(), slot);
			if (pos != connections.end()) {
				connections.erase(pos);
			}
		}
	}

	void EventManager::broadcast(const ece::SignalID & signal)
	{
		auto connections = this->matcher[signal];
		for (auto it = connections.begin(); it != connections.end(); ++it) {
			this->slots[*it]->trigger();
		}
	}
}