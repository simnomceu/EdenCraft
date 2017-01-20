#ifndef LISTENER_HPP
#define LISTENER_HPP

#include "Core\System\Event\Slot.hpp"
#include "Core\System\Event\EventManagerConsumer.hpp"

#include <map>

namespace ece
{
	class Emitter;

	class Listener
	{
	public:
		Listener() = default;
		Listener(const Listener & copy) = default;
		Listener(Listener && move) = default;
		virtual ~Listener() = 0;

		Listener & operator=(const Listener & copy) = default;
		Listener & operator=(Listener && move) = default;

		void addSlot(const Slot::SlotID slot, const Slot::Handle & handle);
		void removeSlot(const Slot::SlotID slot);

		const Slot::GlobalSlotID getSlotID(const Slot::SlotID slot) const;

		void connect(const Slot::SlotID slot, const Emitter & emitter, const Signal::SignalID signal);
		void disconnect(const Slot::SlotID slot, const Emitter & emitter, const Signal::SignalID signal);
		void disconnectAll();

		void clear();

	private:
		EventManagerConsumer consumer;
		std::map<Slot::SlotID, Slot::GlobalSlotID> slots;
	};
}

#endif // LISTENER_HPP
