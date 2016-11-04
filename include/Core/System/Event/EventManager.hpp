#ifndef EVENTMANAGER_HPP
#define EVENTMANAGER_HPP

#include "Core\System\Event\BaseEventManager.hpp"
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

		virtual const Slot::GlobalSlotID getSlotID();
		virtual const GlobalSignalID getSignalID();

		virtual void addSlot(const std::shared_ptr<ece::Slot> & slot) ;
		virtual void addSignal(const ece::GlobalSignalID signal);

		virtual void eraseSlot(const ece::Slot::GlobalSlotID slot);
		virtual void eraseSignal(const ece::GlobalSignalID signal);

		virtual void connect(const ece::Listener & listener, const ece::SlotID slot, const ece::Emitter & emitter, const ece::SignalID signal);
		virtual void disconnect(const ece::Listener & listener, const ece::SlotID slot, const ece::Emitter & emitter, const ece::SignalID signal);

		virtual void broadcast(ece::Emitter & emitter, const ece::SignalID signal);

	private:
		struct MappedSlot
		{
			std::shared_ptr<Slot> slot;
			std::set<GlobalSignalID> signals;
		};

		std::map<GlobalSignalID, std::set<Slot::GlobalSlotID>> signals;
		std::map<Slot::GlobalSlotID, MappedSlot> slots;

		ece::UniqueID signalsAvailable;
		ece::UniqueID slotsAvailable;
	};
}

#endif // EVENTMANAGER_HPP
