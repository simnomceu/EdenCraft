namespace ece
{
	inline Connection::Connection(const Slot::GlobalSlotID slot, const Signal::GlobalSignalID signal) : slot(slot), signal(signal), dirty(false)
	{
	}

	inline bool Connection::operator==(const Connection & rightOperand) { return this->signal == rightOperand.getSignal() && this->slot == rightOperand.getSlot(); }

	inline const Slot::GlobalSlotID Connection::getSlot() const { return this->slot; }

	inline const Slot::GlobalSlotID Connection::getSignal() const { return this->signal; }

	inline void Connection::setDirty(const bool dirty) { this->dirty = dirty; }

	inline const bool Connection::isDirty() const { return this->dirty; }
}