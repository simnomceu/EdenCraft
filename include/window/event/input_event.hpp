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

#include "window/pch.hpp"
#include "window/config.hpp"
#include "window/event/mouse.hpp"
#include "window/event/keyboard.hpp"
#include "utility/mathematics.hpp"

#ifdef _MSC_VER
#undef MOUSE_MOVED
#endif

namespace ece
{
	namespace window
	{
		namespace event
		{
			/**
			 * @class InputEvent
			 * @brief Event from a user input.
			 */
			struct ECE_WINDOW_API InputEvent
			{
				/**
				 * @enum DoubleTap
				 * @brief Which part of the double tap is an event.
				 */
				enum class DoubleTap : short int
				{
					NONE = -1,
					FIRST_OF = 0,
					LAST_OF = 1
				};

				struct MouseButtonEvent
				{
					/**
					 * @property _doubleTap
					 * @brief If it is produced from a double tap event.
					 */
					DoubleTap doubleTap;

					/**
					 * @property _mouseButton
					 * @brief The mouse button pressed.
					 */
					Mouse::Button mouseButton;
				};

				struct MouseEvent
				{
					/**
					 * @property _mousePosition
					 * @brief The position of the mouse cursor.
					 */
					IntVector2u position;
				};

				struct MouseWheelEvent
				{
					int delta;
				};

				struct KeyEvent
				{
					/**
					 * @property _key
					 * @brief The keyboard key pressed.
					 */
					Keyboard::Key key;
				};

				struct WindowPositionEvent
				{
					UintVector2u position;
				};

				struct WindowSizeEvent
				{
					UintVector2u size;
				};

				enum class Type : int
				{
					NONE = -1,
					MOUSE_PRESSED = 0,
					MOUSE_RELEASED = 1,
					MOUSE_MOVED = 2,
					MOUSE_SCROLLED = 3,
					KEY_PRESSED = 4,
					KEY_RELEASED = 5,
					WINDOW_OPENED = 6,
					WINDOW_RESIZED = 7,
					WINDOW_MOVED = 8,
					WINDOW_CLOSED = 9,
					WINDOW_FOCUS_GAINED = 10,
					WINDOW_FOCUS_LOST = 11,
				};

				Type type;

				std::variant<MouseButtonEvent,
					MouseEvent,
					MouseWheelEvent,
					KeyEvent,
					WindowPositionEvent,
					WindowSizeEvent> data;
			};
		} // namespace event
	} // namespace window
} // namespace ece

#endif // INPUT_EVENT_HPP
