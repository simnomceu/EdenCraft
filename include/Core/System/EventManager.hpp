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
		virtual void registerSlot(const std::shared_ptr<ece::Slot> & slot);
		virtual void eraseSlot(const ece::SlotID & slot);

		virtual void registerSignal(const ece::SignalID & signal);
		virtual void eraseSignal(const ece::SignalID & signal);

		virtual void connect(const ece::SlotID & slot, const ece::SignalID & signal);
		virtual void disconnect(const ece::SlotID & slot, const ece::SignalID & signal);

		virtual void broadcast(const ece::SignalID & signal);

	private:
		std::map<ece::SignalID, std::vector<ece::SlotID>> matcher;
		std::map<ece::SlotID, std::shared_ptr<ece::Slot>> slots;
	};
}

#endif // EVENTMANAGER_HPP
