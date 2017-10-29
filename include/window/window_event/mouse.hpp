#ifndef MOUSE_HPP
#define MOUSE_HPP

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
	};
}

#endif // MOUSE_HPP
