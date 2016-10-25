#ifndef LISTENER_HPP
#define LISTENER_HPP

#include "Core\System\Slot.hpp"
#include "Core\System\Event.inl"

namespace ece
{
	class Listener
	{
	public:
		virtual ~Listener() = 0;

		void addSlot(const ece::Slot & slot);
		void connect(const ece::SlotID & slot, const ece::SignalID & signal);
	};
}

#endif // LISTENER_HPP
