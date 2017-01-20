#include "Core\System\Event\Connection.hpp"

namespace ece
{
	Connection::Connection(const Slot::GlobalSlotID slot, const Signal::GlobalSignalID signal): slot(slot), signal(signal), dirty(false)
	{
	}

	bool Connection::operator==(const Connection & rightOperand)
	{
		return this->signal == rightOperand.getSignal() && this->slot == rightOperand.getSlot();
	}

	const Slot::GlobalSlotID Connection::getSlot() const
	{
		return this->slot;
	}

	const Slot::GlobalSlotID Connection::getSignal() const
	{
		return this->signal;
	}

	void Connection::setDirty(const bool dirty)
	{
		this->dirty = dirty;
	}

	const bool Connection::isDirty() const
	{
		return this->dirty;
	}
}
