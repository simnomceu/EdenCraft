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

#include "window/common/window_adapter.hpp"
#include "window/x11/data_window_adapter.hpp"

#include "utility/log/service_logger.hpp"

#include <iostream>

namespace ece
{
	WindowAdapter::WindowAdapter() noexcept: BaseWindowAdapter(), _data(makePimpl<DataWindowAdapter>()) {}

	void WindowAdapter::createWindow()
	{
		this->_data->_connection = XOpenDisplay(nullptr);
		if(!this->_data->_connection) {
			ServiceLoggerLocator::getService().logError("No X server available.");
		}

		auto screen = DefaultScreen(this->_data->_connection);
		this->_data->_windowId = XCreateSimpleWindow(this->_data->_connection,
													RootWindow(this->_data->_connection, screen),
													0, 0, 320, 320,
													1,
													BlackPixel(this->_data->_connection, screen),
													WhitePixel(this->_data->_connection, screen));
		XSelectInput(this->_data->_connection, this->_data->_windowId, ExposureMask | KeyPressMask);
		XMapWindow(this->_data->_connection, this->_data->_windowId);

		XEvent e;
		while (1) {
	    	XNextEvent(this->_data->_connection, &e);
	      	if (e.type == Expose) {
	        	XFillRectangle(this->_data->_connection, this->_data->_windowId, DefaultGC(this->_data->_connection, screen), 20, 20, 10, 10);
	      	}
	      	if (e.type == KeyPress)
	        	break;
	   	}

/*
		if(!this->_data->_connection) {
			int nbScreens = 0;
			this->_data->_connection = xcb_connect(nullptr, &nbScreens);
			if(!this->_data->_connection) {
				ServiceLoggerLocator::getService().logError("No X server available.");
			}
		}
		if(!this->_data->_connection) {
			XCBScreen screen = xcb_setup_roots_iterator(xcb_get_setup(this->_data->_connection)).data;

			this->_data->_windowId = xcb_generate_id(this->_data->_connection);
			xcb_create_window(this->_data->_connection, XCB_COPY_FROM_PARENT, this->_data->_windowId, screen->root, 0, 0, 320, 320, 10, XCB_WINDOW_CLASS_INPUT_OUTPUT, screen->root_visual, 0, nullptr);
			xcb_map_window(this->_data->_connection, this->_data->_windowId);

			xcb_flush(this->_data->_connection);
		} else {
			ServiceLoggerLocator::getService().logError("No X server available.");
		}
		*/
	}

	void WindowAdapter::deleteWindow()
	{
		XDestroyWindow(this->_data->_connection, this->_data->_windowId);
		XCloseDisplay(this->_data->_connection);
	}

	bool WindowAdapter::isWindowCreated() const
	{
		return BaseWindowAdapter::isWindowCreated();
	}

	void WindowAdapter::setTitle(const std::string & title)
	{
		BaseWindowAdapter::setTitle(title);
	}

	std::string WindowAdapter::getTitle() const
	{
		return BaseWindowAdapter::getTitle();
	}

	void WindowAdapter::setPosition(const IntVector2u & position)
	{
		BaseWindowAdapter::setPosition(position);
	}

	IntVector2u WindowAdapter::getPosition() const
	{
		return BaseWindowAdapter::getPosition();
	}

	void WindowAdapter::minimize()
	{
		BaseWindowAdapter::minimize();
	}

	void WindowAdapter::maximize()
	{
		BaseWindowAdapter::maximize();
	}

	void WindowAdapter::processEvent(const bool blocking)
	{
		BaseWindowAdapter::processEvent(blocking);
	}

	void WindowAdapter::processMessage(const WindowMessage & /*message*/)
	{
	}
}
