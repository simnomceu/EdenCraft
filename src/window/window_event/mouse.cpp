#include "window/window_event/mouse.hpp"

namespace ece
{
	std::array<bool, 10> Mouse::states;
	IntVertex2u Mouse::position;

	bool Mouse::isKeyPressed(const Button code)
	{
		if (code == Mouse::ECE_MOUSE_NONE) {
			throw std::runtime_error("That code is not a valid key.");
		}
		return Mouse::states[code];
	}

	void Mouse::pressKey(const Button code, const bool state)
	{
		if (code == Mouse::ECE_MOUSE_NONE) {
			throw std::runtime_error("That code is not a valid key.");
		}
		Mouse::states[code] = state;
	}

	IntVertex2u & Mouse::getPosition()
	{
		return Mouse::position;
	}
	void Mouse::setPosition(const IntVertex2u & position)
	{
		Mouse::position = position;
	}
}