#include "Core\System\EventManager.hpp"

namespace ece
{
	EventManager::EventManager() : matcher(), slots()
	{
	}

	EventManager::~EventManager()
	{
	}

	void EventManager::registerSignal(const ece::SignalID & signal)
	{
		if (this->matcher.count(signal) <= 0) {
			this->matcher[signal] = std::vector<ece::SlotID>();
		}
	}

	void EventManager::broadcast(const ece::SignalID & signal)
	{
		if (this->matcher.count(signal) <= 0) {
			this->matcher[signal] = std::vector<ece::SlotID>();
		}
		for (auto it = this->matcher[signal].begin(); it != this->matcher[signal].end(); ++it) {
			if (std::find(this->slots.begin(), this->slots.end(), *it) == this->slots.end()) {
				this->slots[*it].trigger();
			}
		}
	}

	void EventManager::connect(const ece::Slot & slot, const ece::SignalID & signal)
	{
		this->slots[slot.getId()] = slot;
		if (this->matcher.count(signal) <= 0) {
			this->matcher[signal] = std::vector<ece::SlotID>();
		}
		this->matcher[signal].push_back(slot.getId());
	}
}