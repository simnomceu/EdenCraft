#ifndef EVENTMANAGER_HPP
#define EVENTMANAGER_HPP

#include "Core\System\BaseEventManager.hpp"

#include <map>
#include <set>
#include <stack>

#include <memory>

namespace ece
{
	class EventManager: public BaseEventManager
	{
	public:
		EventManager();

		virtual const SlotID getSlotID();
		virtual const SignalID getSignalID();

		virtual void eraseSlot(const std::shared_ptr<ece::Slot> & slot);
		virtual void eraseSignal(const ece::GlobalSignalID signal);

		virtual void connect(const ece::Listener & listener, const ece::SlotID slot, const ece::Emitter & emitter, const ece::SignalID signal);
		virtual void disconnect(const ece::Listener & listener, const ece::SlotID slot, const ece::Emitter & emitter, const ece::SignalID signal);

		virtual void broadcast(ece::Emitter & emitter, const ece::SignalID signal);

	private:
		std::map<ece::GlobalSignalID, std::set<std::shared_ptr<ece::Slot>>> signals;
		std::map<ece::GlobalSlotID, std::set<ece::GlobalSignalID>> slots;

		std::stack<ece::GlobalSignalID> signalsAvailable;
		std::stack<ece::GlobalSlotID> slotsAvailable;
	};
}

#endif // EVENTMANAGER_HPP
