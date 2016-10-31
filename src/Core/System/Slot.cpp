#include "Core\System\Slot.hpp"

#include "Core\System\EventManagerLocator.hpp"

namespace ece
{
	Slot::Slot(const std::function<void()> & handle): id(ece::EventManagerLocator::getService().getSlotID()), handle(handle)
	{
	}

	void Slot::trigger()
	{
		this->handle();
	}

	const ece::SlotID & Slot::getId() const
	{
		return this->id;
	}
}
