#ifndef KEYBOARD_HPP
#define KEYBOARD_HPP

#include "Core\Window\Window\BaseWindow.hpp"
#include "Core\System\Event\Emitter.hpp"

namespace ece
{
	class Keyboard: public Emitter
	{
	public:
		enum Key: SignalID
		{
			Unknown,
			A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
			F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12,
			NUM0, NUM1, NUM2, NUM2, NUM3, NUM4, NUM5, NUM6, NUM7, NUM8, NUM9,
			LCTRL, FN, CMD, ALT, ALTGR, RCTRL, LEFT, RIGHT, UP, DOWN, LSHIFT, RSHIFT, MAJLOCK, NUMLOCK, TAB, ENTER, SPACE, ESCAPE, DEL, REMOVE, BEGIN, END, SCREENSHOT, SCROLLUP, SCROLLDOWN,
			NUMSLASH, NUMPRODUCT, NUMSUB, NUMADD, NUMENTER, NUMDEL,
			KEY1, KEY2, KEY3, KEY4, KEY5, KEY6, KEY7, KEY8, KEY9, KEY0, RPARENTHESIS, EQUAL, ACCENT, DOLLAR, PERCENT, STAR, COMMA, SEMICOLON, SLASH, EXCLAM,
			BRACKET, SQUARE
		};

		SignalID KEY_PRESSED;
		SignalID KEY_RELEASED;

		Keyboard(const BaseWindow & window);

		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
		{

	};
}

#endif // KEYBOARD_HPP
