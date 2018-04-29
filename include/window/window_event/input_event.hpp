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

#ifndef INPUT_EVENT_HPP
#define INPUT_EVENT_HPP

#include "window/window_event/mouse.hpp"
#include "window/window_event/keyboard.hpp"
#include "utility/mathematics/vector2u.hpp"

namespace ece
{
    using namespace utility::mathematics;
    
	/**
	 * @class InputEvent
	 * @brief Event from a user input.
	 */
	class InputEvent
	{
	public:
		/**
		 * @enum Type
		 * @brief Type of event produced.
		 */
		enum class Type: short int
		{
			ECE_TYPE_NONE = -1,
			ECE_MOUSE_PRESSED = 0,
			ECE_MOUSE_RELEASED = 1,
			ECE_MOUSE_MOVED = 2,
			ECE_MOUSE_SCROLLED = 3,
			ECE_KEY_PRESSED = 4,
			ECE_KEY_RELEASED = 5,
		};

		/**
		 * @enum DoubleTap
		 * @brief Which part of the double tap is an event.
		 */
		enum class DoubleTap: short int
		{
			ECE_TAP_NONE = -1,
			ECE_FIRST_OF = 0,
			ECE_LAST_OF = 1
		};

		/**
		 * @fn InputEvent()
		 * @brief Default constructor.
		 * @throw noexcept
		 */
		inline InputEvent() noexcept;

		/**
		 * @fn InputEvent(const InputEvent & copy)
		 * @param[in] copy The event to copy from.
		 * @brief Default copy constructor.
		 * @throw
		 */
		InputEvent(const InputEvent & copy) = default;

		/**
		 * @fn InputEvent(InputEvent && move) noexcept
		 * @param[in] move The event to move.
		 * @brief Default move constructor.
		 * @throw noexcept
		 */
		InputEvent(InputEvent && move) noexcept = default;

		/**
		 * @fn ~InputEvent() noexcept
		 * @brief Default destructor.
		 * @throw noexcept
		 */
		~InputEvent() noexcept = default;

		/**
		 * @fn InputEvent & operator=(const InputEvent & copy)
		 * @param[in] copy The event to copy from.
		 * @return The event copied.
		 * @brief Default copy assignment operator.
		 * @throw
		 */
		InputEvent & operator=(const InputEvent & copy) = default;

		/**
		 * @fn InputEvent & operator=(InputEvent && move) noexcept
		 * @param[in] move The event to move.
		 * @return The event moved.
		 * @brief Default move assignment operator.
		 * @throw noexcept
		 */
		InputEvent & operator=(InputEvent && move) noexcept = default;

		/**
		 * @property _type
		 * @brief The type of event produced.
		 */
		InputEvent::Type _type;

		/**
		 * @property _doubleTap
		 * @brief If it is produced from a double tap event.
		 */
		DoubleTap _doubleTap;

		/**
		 * @property _mouseButton
		 * @brief The mouse button pressed.
		 */
		Mouse::Button _mouseButton;

		/**
		 * @property _mousePosition
		 * @brief The position of the mouse cursor.
		 */
		IntVector2u _mousePosition;

		/**
		 * @property _key
		 * @brief The keyboard key pressed.
		 */
		Keyboard::Key _key;
	};
}

#include "window/window_event/input_event.inl"

#endif // INPUT_EVENT_HPP
