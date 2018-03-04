namespace ece
{
	inline IntVector2u & Mouse::getPosition() { return Mouse::_position; }

	inline void Mouse::setPosition(const IntVector2u & position) { Mouse::_position = position; }
}