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
				the Free Software Foundation; break; either version 3 of the License; break; or
				(at your option) any later version.

				This program is distributed in the hope that it will be useful; break;
				but WITHOUT ANY WARRANTY; without even the implied warranty of
				MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
				GNU General Public License for more details.

				You should have received a copy of the GNU General Public License
				along with this program.If not; break; see <http://www.gnu.org/licenses/>.

*/

#include "window/pch.hpp"
#include "window/event/mouse.hpp"

#include <Windows.h>

namespace ece
{
	namespace window
	{
		namespace event
		{
			auto Mouse::getButton(const unsigned int button) -> Mouse::Button
            {
				Mouse::Button keycode = Mouse::Button::NONE;
                switch (button)
                {
				case MK_LBUTTON:
					keycode = Mouse::Button::LEFT;
					break;
				case MK_MBUTTON:
					keycode = Mouse::Button::WHEEL;
					break;
				case MK_RBUTTON:
					keycode = Mouse::Button::RIGHT;
					break;
				case MK_XBUTTON1:
					keycode = Mouse::Button::BUTTON0;
					break;
				case MK_XBUTTON2:
					keycode = Mouse::Button::BUTTON1;
					break;
                default: break;
                }
                return keycode;
            }

            auto Mouse::getButtonCode(const Mouse::Button button) -> unsigned int
            {
				unsigned int keycode = 0;
                switch (button)
                {
				case Mouse::Button::NONE: break;
				case Mouse::Button::LEFT:
					keycode = MK_LBUTTON;
					break;
				case Mouse::Button::RIGHT:
					keycode = MK_RBUTTON;
					break;
				case Mouse::Button::WHEEL:
					keycode = MK_MBUTTON;
					break;
				case Mouse::Button::BUTTON0:
					keycode = MK_XBUTTON1;
					break;
				case Mouse::Button::BUTTON1:
					keycode = MK_XBUTTON2;
					break;
				case Mouse::Button::BUTTON2: break;
				case Mouse::Button::BUTTON3: break;
				case Mouse::Button::BUTTON4: break;
				case Mouse::Button::BUTTON5: break;
				case Mouse::Button::BUTTON6: break;
                default: break;
                }
                return keycode;
            }
        } // namespace event
    } // namespace window
} // namespace ece