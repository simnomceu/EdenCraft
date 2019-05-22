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

#include "window/pch.hpp"
#include "window/config.hpp"
#include "utility/enumeration.hpp"

namespace ece
{
	namespace window
	{
		namespace event
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
					NONE = -1,
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
					DEL = 20,
					HELP = 21,
					NUM_0 = 22,
					NUM_1 = 23,
					NUM_2 = 24,
					NUM_3 = 25,
					NUM_4 = 26,
					NUM_5 = 27,
					NUM_6 = 28,
					NUM_7 = 29,
					NUM_8 = 30,
					NUM_9 = 31,
					A = 32,
					B = 33,
					C = 34,
					D = 35,
					E = 36,
					F = 37,
					G = 38,
					H = 39,
					I = 40,
					J = 41,
					K = 42,
					L = 43,
					M = 44,
					N = 45,
					O = 46,
					P = 47,
					Q = 48,
					R = 49,
					S = 50,
					T = 51,
					U = 52,
					V = 53,
					W = 54,
					X = 55,
					Y = 56,
					Z = 57,
					LEFT_COMMAND = 58,
					RIGHT_COMMAND = 59,
					APPLICATIONS = 60,
					SLEEP = 61,
					NUMPAD_0 = 62,
					NUMPAD_1 = 63,
					NUMPAD_2 = 64,
					NUMPAD_3 = 65,
					NUMPAD_4 = 66,
					NUMPAD_5 = 67,
					NUMPAD_6 = 68,
					NUMPAD_7 = 69,
					NUMPAD_8 = 70,
					NUMPAD_9 = 71,
					MULTIPLY = 72,
					ADD = 73,
					SUBSTRACT = 74,
					NUMPAD_DEL = 75,
					DIVIDE = 76,
					F1 = 77,
					F2 = 78,
					F3 = 79,
					F4 = 80,
					F5 = 81,
					F6 = 82,
					F7 = 83,
					F8 = 84,
					F9 = 85,
					F10 = 86,
					F11 = 87,
					F12 = 88,
					F13 = 89,
					F14 = 90,
					F15 = 91,
					F16 = 92,
					F17 = 93,
					F18 = 94,
					F19 = 95,
					F20 = 96,
					F21 = 97,
					F22 = 98,
					F23 = 99,
					F24 = 100,
					NUMLOCK = 101,
					BROWSER_BACK = 102,
					BROWSER_FORWARD = 103,
					BROWSER_REFRESH = 104,
					BROWSER_STOP = 105,
					BROWSER_SEARCH = 106,
					BROWSER_FAVORITES = 107,
					BROWSER_HOME = 108,
					VOLUME_MUTE = 109,
					VOLUME_DOWN = 110,
					VOLUME_UP = 111,
					MEDIA_NEXT = 112,
					MEDIA_PREVIOUS = 113,
					MEDIA_STOP = 114,
					MEDIA_PLAY = 115,
					LAUNCH_MAIL = 116,
					SELECT_MEDIA = 117,
					APP_1 = 118,
					APP_2 = 119,
					OEM_1 = 120,
					OEM_2 = 121,
					OEM_3 = 122,
					OEM_4 = 123,
					OEM_5 = 124,
					OEM_6 = 125,
					OEM_7 = 126,
					OEM_8 = 127,
					OEM_102 = 128,
					OEM_PLUS = 129,
					OEM_COMMA = 130,
					OEM_MINUS = 131,
					OEM_PERIOD = 132,
				};

				/**
				 * @fn bool isKeyPressed(const Key code)
				 * @param[in] code The key to check.
				 * @return True if the key is currently pressed, false else.
				 * @brief Check if a key is currently pressed or not.
				 * @throw
				 */
				static auto isKeyPressed(const Key code) -> bool;

				/**
				 * @fn void pressKey(const Button code, const bool state)
				 * @param[in] code The button to modify.
				 * @param[in] state The new staet of the button.
				 * @brief Change the state of a mouse button.
				 * @throw
				 */
				static void pressKey(const Key code, const bool state);

				static auto getKey(const unsigned int keycode) -> Keyboard::Key;

			private:
				/**
				 * @property _states
				 * @brief The current state for each keyboard key.
				 */
				static std::array<bool, 132> _states;
			};
		} // namespace event
	} // namespace window

    namespace utility
    {
        namespace enumeration
        {
			using window::event::Keyboard;

        	template <>
        	struct EnumCount<Keyboard::Key>
        	{
        		/**
        		 * @property EnumCount<Keyboard::Key>::value
        		 * @brief The number of supported keyboard keys.
        		 */
        		static constexpr auto value = static_cast<std::size_t>(Keyboard::Key::OEM_PERIOD) + 1;
        	};    
        } // namespace enumeration
    } // namespace utility
} // namespace ece

#endif // KEYBOARD_HPP
