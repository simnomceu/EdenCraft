#ifndef BASEEVENTMANAGER_HPP
#define BASEEVENTMANAGER_HPP

#include "Core\System\Event.inl"
#include "Core\System\Slot.hpp"

namespace ece
{
	class BaseEventManager
	{
	public:
		virtual void registerSignal(const ece::SignalID & signal) = 0;
		virtual void broadcast(const ece::SignalID & signal) = 0;
		virtual void connect(const ece::Slot & slot, const ece::SignalID & signal) = 0;
	};
}

#endif
