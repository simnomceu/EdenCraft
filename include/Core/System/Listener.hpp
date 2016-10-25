#ifndef LISTENER_HPP
#define LISTENER_HPP

#include "Core\System\Slot.hpp"
#include "Core\System\Event.inl"

#include <vector>

namespace ece
{
	class Listener
	{
	public:
		Listener();
		virtual ~Listener() = 0;

		void addSlot(const ece::Slot & slot);
		void connect(const ece::SlotID & slot, const ece::SignalID & signal);

	private:
		std::vector<ece::Slot> slots;
	};
}

#endif // LISTENER_HPP
