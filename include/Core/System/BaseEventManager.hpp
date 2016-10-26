#ifndef BASEEVENTMANAGER_HPP
#define BASEEVENTMANAGER_HPP

#include "Core\System\Event.inl"
#include "Core\System\Slot.hpp"

#include <memory>

#include "Core\System\Event.inl"

namespace ece
{
	class BaseEventManager
	{
	public:
		virtual void registerSlot(const std::shared_ptr<ece::Slot> & slot) = 0;
		virtual void eraseSlot(const ece::SlotID & slot) = 0;

		virtual void registerSignal(const ece::SignalID & signal) = 0;
		virtual void eraseSignal(const ece::SignalID & signal) = 0;

		virtual void connect(const ece::SlotID & slot, const ece::SignalID & signal) = 0;
		virtual void disconnect(const ece::SlotID & slot, const ece::SignalID & signal) = 0;

		virtual void broadcast(const ece::SignalID & signal) = 0;
	};
}

#endif
