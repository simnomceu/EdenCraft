#ifndef SLOTBUILDER_HPP
#define SLOTBUILDER_HPP

#include <memory>

#include "Core\System\Slot.hpp"

namespace ece
{
	class SlotBuilder
	{
	public:
		static std::shared_ptr<Slot> makeSlot(const Slot::Handle & action);
	};
}

#endif // SLOTBUILDER_HPP
