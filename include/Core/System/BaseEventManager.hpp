#ifndef BASEEVENTMANAGER_HPP
#define BASEEVENTMANAGER_HPP

#include "Core\System\Event.inl"
#include "Core\System\Emitter.hpp"
#include "Core\System\Listener.hpp"

namespace ece
{
	class BaseEventManager
	{
	public:
		virtual const Slot::GlobalSlotID getSlotID() = 0;
		virtual const GlobalSignalID getSignalID() = 0;

		virtual void addSlot(const std::shared_ptr<ece::Slot> & slot) = 0;
		virtual void addSignal(const ece::GlobalSignalID signal) = 0;

		virtual void eraseSlot(const ece::Slot::GlobalSlotID slot) = 0;
		virtual void eraseSignal(const ece::GlobalSignalID signal) = 0;

		virtual void connect(const ece::Listener & listener, const ece::SlotID slot, const ece::Emitter & emitter, const ece::SignalID signal) = 0;
		virtual void disconnect(const ece::Listener & listener, const ece::SlotID slot, const ece::Emitter & emitter, const ece::SignalID signal) = 0;

		virtual void broadcast(ece::Emitter & emitter, const ece::SignalID signal) = 0;
	};
}

#endif
