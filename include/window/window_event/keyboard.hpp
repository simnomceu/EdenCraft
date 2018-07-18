/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

															oooooo   oooooo     oooo  o8o                    .o8
															 `888.    `888.     .8'   `"'                   "888
															  `888.   .8888.   .8'   oooo  ooo. .oo.    .oooo888   .ooooo.  oooo oooo    ooo
															   `888  .8'`888. .8'    `888  `888P"Y88b  d88' `888  d88' `88b  `88. `88.  .8'
																`888.8'  `888.8'      888   888   888  888   888  888   888   `88..]88..8'
																 `888'    `888'       888   888   888  888   888  888   888    `888'`888'
																  `8'      `8'       o888o o888o o888o `Y8bod88P" `Y8bod8P'     `8'  `8'


				This file is part of EdenCraft Engine - Window module.
				Copyright(C) 2018 Pierre Casati (@IsilinBN)

				This program is free software : you can redistribute it and/or modify
				it under the terms of the GNU General Public License as published by
				the Free Software Foundation, either version 3 of the License, or
				(at your option) any later version.

				This program is distributed in the hope that it will be useful,
				but WITHOUT ANY WARRANTY; without even the implied warranty of
				MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
				GNU General Public License for more details.

				You should have received a copy of the GNU General Public License
				along with this program.If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef KEYBOARD_HPP
#define KEYBOARD_HPP

#include "window/config.hpp"
#include "utility/enumeration/enum_count.hpp"

#include <array>

namespace ece
{
	namespace window
	{
		namespace window_event
		{
			/**
			 * @class Keyboard
			 * @brief A keyboard input device.
			 */
			class ECE_WINDOW_API Keyboard
			{
			public:
				/**
				 * @enum Key
				 * @brief The available keyboard keys.
				 */
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
					MEDIA_PLAY = 114,
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

				/**
				 * @fn bool isKeyPressed(const Key code)
				 * @param[in] code The key to check.
				 * @return True if the key is currently pressed, false else.
				 * @brief Check if a key is currently pressed or not.
				 * @throw
				 */
				inline static bool isKeyPressed(const Key code);

				/**
				 * @fn void pressKey(const Button code, const bool state)
				 * @param[in] code The button to modify.
				 * @param[in] state The new staet of the button.
				 * @brief Change the state of a mouse button.
				 * @throw
				 */
				inline static void pressKey(const Key code, const bool state);

			private:
				/**
				 * @property _states
				 * @brief The current state for each keyboard key.
				 */
				static std::array<bool, 132> _states;
			};
		} // namespace window_event
	} // namespace window

    namespace utility
    {
        namespace enumeration
        {
			using window::window_event::Keyboard;

        	template <>
        	struct EnumCount<Keyboard::Key>
        	{
        		/**
        		 * @property EnumCount<Keyboard::Key>::value
        		 * @brief The number of supported keyboard keys.
        		 */
        		static constexpr unsigned short int value = static_cast<unsigned short int>(Keyboard::Key::OEM_PERIOD) + 1;
        	};    
        } // namespace enumeration
    } // namespace utility
} // namespace ece

#include "window/window_event/keyboard.inl"

#endif // KEYBOARD_HPP
