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

#ifndef DATA_WINDOW_ADAPTER_HPP
#define DATA_WINDOW_ADAPTER_HPP

/*#include <xcb/xcb.h>*/
#include <X11/Xlib.h>

namespace ece
{
    /**
     * @typedef XCBConnection
     * @brief The connection to the X server.
     */
//    using XCBConnection = xcb_connection_t *;

    /**
     * @typedef XCVScreen
     * @brief A screen device.
     */
//    using XCBScreen = xcb_screen_t *;

    /**
     * @typedef XCBWindow
     * @brief A X window.
     */
//    using XCBWindow = xcb_window_t;

	/**
	 * @struct DataWindowAdapter
	 * @brief X11 implementaion of the window adapter.
	 */
	struct DataWindowAdapter
	{
		/**
		 * @fn DataWindowAdapter()
		 * @brief Default constructor.
		 * @throw
		 */
		inline DataWindowAdapter(): _windowId(), _connection(nullptr) {}

		/**
		 * @property _windowId
		 * @brief The handle of the window.
		 */
//        XCBWindow _windowId;
        Window _windowId;

        /**
         * @property _connection
         * @brief The connection to the X server.
         */
//        XCBConnection _connection;
        Display * _connection;
	};

	/**
	 * @struct WindowMessage
	 * @brief Win32 implementation for a window message/notification, including input messages.
	 */
	struct WindowMessage
	{
	};
}

#endif // DATA_WINDOW_ADAPTER_HPP
