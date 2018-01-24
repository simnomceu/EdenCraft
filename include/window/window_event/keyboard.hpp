#ifndef KEYBOARD_HPP
#define KEYBOARD_HPP

#include <array>

#include "utility/enum/enum_count.hpp"

namespace ece
{
	class Keyboard
	{
	public:
		enum class Key : short int
		{
			KEY_NONE = -1,
			BACKSPACE = 0,
			TAB = 1,
			RETURN = 2,
			SHIFT = 3,
			CTRL = 4,
			ALTGR = 5,
			PAUSE = 6,
			CAPS_LOCK = 7,
			ESCAPE = 8,
			SPACEBAR = 9,
			PAGE_UP = 10,
			PAGE_DOWN = 11,
			END = 12,
			HOME = 13,
			LEFT = 14,
			UP = 15,
			RIGHT = 16,
			DOWN = 17,
			PRINT_SCREEN = 18,
			INS = 19,
			DEL = 19,
			HELP = 20,
			NUM_0 = 21,
			NUM_1 = 22,
			NUM_2 = 23,
			NUM_3 = 24,
			NUM_4 = 25,
			NUM_5 = 26,
			NUM_6 = 27,
			NUM_7 = 28,
			NUM_8 = 29,
			NUM_9 = 30,
			A = 31,
			B = 32,
			C = 33,
			D = 34,
			E = 35,
			F = 36,
			G = 37,
			H = 38,
			I = 39,
			J = 40,
			K = 41,
			L = 42,
			M = 43,
			N = 44,
			O = 45,
			P = 46,
			Q = 47,
			R = 48,
			S = 49,
			T = 50,
			U = 51,
			V = 52,
			W = 53,
			X = 54,
			Y = 55,
			Z = 56,
			LEFT_COMMAND = 57,
			RIGHT_COMMAND = 58,
			APPLICATIONS = 59,
			SLEEP = 60,
			NUMPAD_0 = 61,
			NUMPAD_1 = 62,
			NUMPAD_2 = 63,
			NUMPAD_3 = 64,
			NUMPAD_4 = 65,
			NUMPAD_5 = 66,
			NUMPAD_6 = 67,
			NUMPAD_7 = 68,
			NUMPAD_8 = 69,
			NUMPAD_9 = 70,
			MULTIPLY = 71,
			ADD = 72,
			SUBSTRACT = 73,
			NUMPAD_DEL = 74,
			DIVIDE = 75,
			F1 = 76,
			F2 = 77,
			F3 = 78,
			F4 = 79,
			F5 = 80,
			F6 = 81,
			F7 = 82,
			F8 = 83,
			F9 = 84,
			F10 = 85,
			F11 = 86,
			F12 = 87,
			F13 = 88,
			F14 = 89,
			F15 = 90,
			F16 = 91,
			F17 = 92,
			F18 = 93,
			F19 = 94,
			F20 = 95,
			F21 = 96,
			F22 = 97,
			F23 = 98,
			F24 = 99,
			NUMLOCK = 100,
			BROWSER_BACK = 101,
			BROWSER_FORWARD = 102,
			BROWSER_REFRESH = 103,
			BROWSER_STOP = 104,
			BROWSER_SEARCH = 105,
			BROWSER_FAVORITES = 106,
			BROWSER_HOME = 107,
			VOLUME_MUTE = 108,
			VOLUME_DOWN = 109,
			VOLUME_UP = 110,
			MEDIA_NEXT = 111,
			MEDIA_PREVIOUS = 112,
			MEDIA_STOP = 113,
			MEDIA_PLAY= 114,
			LAUNCH_MAIL = 115,
			SELECT_MEDIA = 116,
			APP_1 = 117,
			APP_2 = 118,
			OEM_1 = 119,
			OEM_2 = 120,
			OEM_3 = 121,
			OEM_4 = 122,
			OEM_5 = 123,
			OEM_6 = 124,
			OEM_7 = 125,
			OEM_8 = 126,
			OEM_102 = 127,
			OEM_PLUS = 128,
			OEM_COMMA = 129,
			OEM_MINUS = 130,
			OEM_PERIOD = 131,
		};

		inline static bool isKeyPressed(const Key code);
		inline static void pressKey(const Key code, const bool state);

	private:
		static std::array<bool, 132> _states;
	};

	template <>
	struct EnumCount<Keyboard::Key>
	{
		static constexpr unsigned short int value = static_cast<unsigned short int>(Keyboard::Key::OEM_PERIOD) + 1;
	};
}

#include "window/window_event/keyboard.inl"

#endif // KEYBOARD_HPP
