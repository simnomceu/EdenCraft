namespace ece
{
	inline Slot::Slot(const GlobalSlotID id, const Handle & handle) : id(id), handle(handle), dirty(false) {}

	inline void Slot::trigger(const Emitter & emitter, const Signal::SignalID signal) { this->handle(emitter, signal); }

	inline const Slot::GlobalSlotID & Slot::getId() const { return this->id; }

	inline const bool Slot::isDirty() const { return this->dirty; }

	inline void Slot::setDirty(const bool dirty) { this->dirty = dirty; }
}