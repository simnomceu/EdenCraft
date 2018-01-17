namespace ece
{
	inline Slot::Slot(const GlobalSlotID id, const Handle & handle) : _id(id), _handle(handle), _dirty(false) {}

	inline void Slot::trigger(const Emitter & emitter, const Signal::SignalID signal) { this->_handle(emitter, signal); }

	inline const Slot::GlobalSlotID & Slot::getId() const { return this->_id; }

	inline const bool Slot::isDirty() const { return this->_dirty; }

	inline void Slot::setDirty(const bool dirty) { this->_dirty = dirty; }
}