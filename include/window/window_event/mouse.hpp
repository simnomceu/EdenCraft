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

#ifndef MOUSE_HPP
#define MOUSE_HPP

#include "window/config.hpp"
#include "utility/mathematics/vector2u.hpp"
#include "utility/enumeration/enum_count.hpp"

#include <array>

namespace ece
{
	namespace window
	{
		namespace window_event
		{
			using utility::mathematics::IntVector2u;

			/**
			 * @class Mouse
			 * @brief A mouse input device.
			 */
			class ECE_WINDOW_API Mouse
			{
			public:
				/**
				 * @enum Button
				 * @brief The available mouse buttons.
				 */
				enum class Button : short int
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

				/**
				 * @fn bool isKeyPressed(const Button code)
				 * @param[in] code The button to check.
				 * @return True if the button is currently pressed, false else.
				 * @brief Check if a button is currently pressed or not.
				 * @throw
				 */
				static bool isKeyPressed(const Button code);

				/**
				 * @fn void pressKey(const Button code, const bool state)
				 * @param[in] code The button to modify.
				 * @param[in] state The new staet of the button.
				 * @brief Change the state of a mouse button.
				 * @throw
				 */
				static void pressKey(const Button code, const bool state);

				/**
				 * @fn IntVector2u & getPosition()
				 * @return Get the last registered position of the mouse cursor.
				 * @throw
				 */
				static inline IntVector2u & getPosition();

				/**
				 * @fn void setPosition(const IntVector2u & position)
				 * @param[in] position The position to set.
				 * @brief Set the position of the mouse cursor.
				 * @throw
				 */
				static inline void setPosition(const IntVector2u & position);

			private:
				/**
				 * @property _states
				 * @brief The current state for each mouse button.
				 */
				static std::array<bool, 10> _states;

				/**
				 * @property _position
				 * @brief The last registered position of the mouse cursor.
				 */
				static IntVector2u _position;
			};
		} // namespace window_event
	} // namespace window

	namespace utility
	{
		namespace enumeration
		{
			using window::window_event::Mouse;

			template <>
			struct EnumCount<Mouse::Button>
			{
				/**
				* @property EnumCount<Mouse::Button>::value
				* @brief The number of supported mouse buttons.
				*/
				static constexpr unsigned short int value = static_cast<unsigned short int>(Mouse::Button::ECE_MOUSE_BUTTON6) + 1;
			};
		} // namespace enumeration
	} // namespace utility
} // namespace ece

#include "window/window_event/mouse.inl"

#endif // MOUSE_HPP
