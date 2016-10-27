#ifndef LISTENER_HPP
#define LISTENER_HPP

#include "Core\System\Slot.hpp"
#include "Core\System\Event.inl"

#include <map>
#include <memory>

namespace ece
{
	class Listener
	{
	public:
		Listener();
		virtual ~Listener() = 0;

		void addSlot(const ece::SlotID id, const ece::Slot & slot);
		void removeSlot(const ece::SlotID slot);

		std::shared_ptr<Slot> getSlot(const ece::SlotID slot) const;

	private:
		std::map<ece::SlotID, std::shared_ptr<ece::Slot>> slots;
	};
}

#endif // LISTENER_HPP
