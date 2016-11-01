#ifndef EVENTMANAGER_HPP
#define EVENTMANAGER_HPP

#include "Core\System\BaseEventManager.hpp"
#include "Core\Util\UniqueID.hpp"

#include <map>
#include <set>

#include <memory>

namespace ece
{
	class EventManager: public BaseEventManager
	{
	public:
		EventManager();

		virtual const GlobalSlotID getSlotID();
		virtual const GlobalSignalID getSignalID();

		virtual void eraseSlot(const std::shared_ptr<ece::Slot> & slot);
		virtual void eraseSignal(const ece::GlobalSignalID signal);

		virtual void connect(const ece::Listener & listener, const ece::SlotID slot, const ece::Emitter & emitter, const ece::SignalID signal);
		virtual void disconnect(const ece::Listener & listener, const ece::SlotID slot, const ece::Emitter & emitter, const ece::SignalID signal);

		virtual void broadcast(ece::Emitter & emitter, const ece::SignalID signal);

	private:
		std::map<ece::GlobalSignalID, std::set<std::shared_ptr<ece::Slot>>> signals;
		std::map<ece::GlobalSlotID, std::set<ece::GlobalSignalID>> slots;

		ece::UniqueID signalsAvailable;
		ece::UniqueID slotsAvailable;
	};
}

#endif // EVENTMANAGER_HPP
