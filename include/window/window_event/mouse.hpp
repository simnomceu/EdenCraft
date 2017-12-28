#ifndef MOUSE_HPP
#define MOUSE_HPP

#include <array>
#include "utility/mathematics/vector2u.hpp"

namespace ece
{
	class Mouse
	{
	public:
		enum Button
		{
			ECE_MOUSE_NONE = -1,
			ECE_MOUSE_LEFT = 0,
			ECE_MOUSE_RIGHT = 1,
			ECE_MOUSE_WHEEL = 2,
			ECE_MOUSE_BUTTON0 = 3,
			ECE_MOUSE_BUTTON1 = 4,
			ECE_MOUSE_BUTTON2 = 5,
			ECE_MOUSE_BUTTON3 = 6,
			ECE_MOUSE_BUTTON4 = 7,
			ECE_MOUSE_BUTTON5 = 8,
			ECE_MOUSE_BUTTON6 = 9
		};

		static bool isKeyPressed(const Button code);
		static void pressKey(const Button code, const bool state);

		static IntVertex2u & getPosition();
		static void setPosition(const IntVertex2u & position);

	private:
		static std::array<bool, 10> states;
		static IntVertex2u position;
	};
}

#endif // MOUSE_HPP
