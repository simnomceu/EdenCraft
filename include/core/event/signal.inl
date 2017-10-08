namespace ece
{
	inline Signal::Signal(const GlobalSignalID id) : id(id), dirty(false) {}

	inline const Signal::GlobalSignalID Signal::getId() const { return this->id; }

	inline const bool Signal::isDirty() const { return this->dirty; }

	inline void Signal::setDirty(const bool dirty) { this->dirty = dirty; }
}