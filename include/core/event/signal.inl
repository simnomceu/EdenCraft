namespace ece
{
	inline Signal::Signal(const GlobalSignalID id) : _id(id), _dirty(false) {}

	inline const Signal::GlobalSignalID Signal::getId() const { return this->_id; }

	inline const bool Signal::isDirty() const { return this->_dirty; }

	inline void Signal::setDirty(const bool dirty) { this->_dirty = dirty; }
}