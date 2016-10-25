#include "Core\System\Slot.hpp"

namespace ece
{
	Slot::Slot(const ece::SlotID&  id, const std::function<void()> & handle): handle(handle)
	{
	}

	Slot::~Slot()
	{
	}

	bool Slot::operator==(const Slot & rightOperand)
	{
		return this->id == rightOperand.getId();
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
