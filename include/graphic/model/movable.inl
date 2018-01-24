namespace ece
{
	inline Movable::Movable() : _position{ 0.0f, 0.0f, 0.0f } {}

	inline Movable::~Movable() {}

	inline const FloatVector3u & Movable::getPosition() const { return this->_position; }
}