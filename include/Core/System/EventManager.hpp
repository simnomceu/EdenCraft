#ifndef EVENTMANAGER_HPP
#define EVENTMANAGER_HPP

#include "Core\System\BaseEventManager.hpp"

#include <map>
#include <vector>

namespace ece
{
	class EventManager: public BaseEventManager
	{
	public:
		EventManager();
		~EventManager();

		void registerSignal(const ece::SignalID & signal);
		void broadcast(const ece::SignalID & signal);
		void connect(const ece::Slot & slot, const ece::SignalID & signal);

	private:
		std::map<ece::SignalID, std::vector<ece::SlotID>> matcher;
		std::vector<ece::Slot> slots;
	};
}

#endif // EVENTMANAGER_HPP
