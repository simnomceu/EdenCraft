#ifndef LISTENER_HPP
#define LISTENER_HPP

#include "Core\System\Event\Slot.hpp"

#include <map>
#include <memory>

namespace ece
{
	class Emitter;

	class Listener
	{
	public:
		using SlotID = unsigned int;

		Listener();
		virtual ~Listener() = 0;

		void addSlot(const ece::SlotID id, const std::shared_ptr<ece::Slot> & slot);
		void removeSlot(const ece::SlotID slot);

		const Slot::GlobalSlotID getSlotID(const ece::SlotID slot) const;

		void connect(const ece::SlotID slot, const ece::Emitter & emitter, const ece::SignalID signal);

	private:
		//std::map<ece::SlotID, std::shared_ptr<ece::Slot>> slots;
		std::map<SlotID, Slot::GlobalSlotID> slots;
	};
}

#endif // LISTENER_HPP
