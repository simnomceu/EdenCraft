namespace ece
{
	inline Connection::Connection(const Slot::GlobalSlotID slot, const Signal::GlobalSignalID signal) : _slot(slot), _signal(signal), _dirty(false)
	{
	}

	inline bool Connection::operator==(const Connection & rightOperand) { return this->_signal == rightOperand.getSignal() && this->_slot == rightOperand.getSlot(); }

	inline const Slot::GlobalSlotID Connection::getSlot() const { return this->_slot; }

	inline const Slot::GlobalSlotID Connection::getSignal() const { return this->_signal; }

	inline void Connection::setDirty(const bool dirty) { this->_dirty = dirty; }

	inline const bool Connection::isDirty() const { return this->_dirty; }
}