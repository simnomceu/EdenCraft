#include "Core\System\Slot.hpp"

namespace ece
{
	Slot::Slot(const ece::SlotID&  id, std::function<void()> & handle): handle(handle)
	{
	}

	Slot::~Slot()
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
