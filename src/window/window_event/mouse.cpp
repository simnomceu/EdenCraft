#include "window/window_event/mouse.hpp"

namespace ece
{
	std::array<bool, 10> Mouse::_states;
	IntVector2u Mouse::_position;

	bool Mouse::isKeyPressed(const Button code)
	{
		if (code == Mouse::ECE_MOUSE_NONE) {
			throw std::runtime_error("That code is not a valid key.");
		}
		return Mouse::_states[code];
	}

	void Mouse::pressKey(const Button code, const bool state)
	{
		if (code == Mouse::ECE_MOUSE_NONE) {
			throw std::runtime_error("That code is not a valid key.");
		}
		Mouse::_states[code] = state;
	}

	IntVector2u & Mouse::getPosition()
	{
		return Mouse::_position;
	}
	void Mouse::setPosition(const IntVector2u & position)
	{
		Mouse::_position = position;
	}
}