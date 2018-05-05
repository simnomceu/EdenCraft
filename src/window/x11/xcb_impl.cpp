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

#include "window/x11/xcb_impl.hpp"

#include "utility/log/service_logger.hpp"

#include <stdexcept>

namespace ece
{
	namespace window
	{
		namespace x11
		{
			using utility::log::ServiceLoggerLocator;

			XCBImpl::XCBImpl() noexcept: _windowId(0), _connection(nullptr)
			{
			}

			Window XCBImpl::getWindowHandle() const
			{
				return 0;
			}

			Display * XCBImpl::getDevice() const
			{
				return nullptr;
			}

			void XCBImpl::createWindow()
			{
				if (!this->_connection) {
					int nbScreens = 0;
					this->_connection = xcb_connect(nullptr, &nbScreens);
					if (!this->_connection) {
						throw std::runtime_error("No X server available for XCB implementation.");
					}
				}
				if (!this->_connection) {
					xcb_screen_t * screen = xcb_setup_roots_iterator(xcb_get_setup(this->_connection)).data;

					this->_windowId = xcb_generate_id(this->_connection);
					xcb_create_window(this->_connection, XCB_COPY_FROM_PARENT, this->_windowId, screen->root, 0, 0, 320, 320, 10, XCB_WINDOW_CLASS_INPUT_OUTPUT, screen->root_visual, 0, nullptr);
					xcb_map_window(this->_connection, this->_windowId);

					xcb_flush(this->_connection);
				}
				else {
					throw std::runtime_error("No X server available for XCB implementation.");
				}
			}

			void XCBImpl::deleteWindow()
			{
				xcb_destroy_window(this->_connection, this->_windowId);
				xcb_disconnect(this->_connection);

				this->_windowId = 0;
				this->_connection = nullptr;
			}

			bool XCBImpl::isWindowCreated() const
			{
				return this->_windowId != 0;
			}

			void XCBImpl::setTitle(const std::string & title)
			{
				xcb_change_property(this->_connection, XCB_PROP_MODE_REPLACE, this->_windowId, XCB_ATOM_WM_NAME, XCB_ATOM_STRING, 8, title.size(), title.data());
				xcb_flush(this->_connection);
			}

			std::string XCBImpl::getTitle() const
			{
				auto cookie = xcb_get_property(this->_connection, 0, this->_windowId, XCB_ATOM_WM_NAME, XCB_ATOM_STRING, 0, 0);
				auto reply = xcb_get_property_reply(this->_connection, cookie, nullptr);
				char * title = static_cast<char *>(xcb_get_property_value(reply));
				return std::string(title);
			}

			void XCBImpl::setPosition(const IntVector2u & position)
			{
				const uint32_t pos[] = { static_cast<uint32_t>(position[0]), static_cast<uint32_t>(position[1]) };
				xcb_configure_window(this->_connection, this->_windowId, XCB_CONFIG_WINDOW_X | XCB_CONFIG_WINDOW_Y, pos);
				xcb_flush(this->_connection);
			}

			IntVector2u XCBImpl::getPosition() const
			{
				auto cookie = xcb_get_geometry(this->_connection, this->_windowId);
				auto pos = xcb_get_geometry_reply(this->_connection, cookie, nullptr);

				return IntVector2u{ pos->x, pos->y };
			}

			IntVector2u XCBImpl::getSize() const
			{
				auto cookie = xcb_get_geometry(this->_connection, this->_windowId);
				auto pos = xcb_get_geometry_reply(this->_connection, cookie, nullptr);

				return IntVector2u{ pos->width, pos->height };
			}

			void XCBImpl::minimize()
			{
				ServiceLoggerLocator::getService().logWarning("The window implementation does not provide any method to minimize the window.");
			}

			void XCBImpl::maximize()
			{
				ServiceLoggerLocator::getService().logWarning("The window implementation does not provide any method to maximize the window.");
			}

			std::vector<InputEvent> XCBImpl::processEvent(const bool blocking)
			{
				xcb_generic_event_t * e = (blocking ? xcb_wait_for_event(this->_connection) : xcb_poll_for_event(this->_connection));

				while (e) {
					if ((e->response_type & ~0x80) == XCB_EXPOSE) {

					}
					if ((e->response_type & ~0x80) == XCB_BUTTON_PRESS) {
						break;
					}

					free(e);
					e = (blocking ? xcb_wait_for_event(this->_connection) : xcb_poll_for_event(this->_connection));
				}
				return std::vector<InputEvent>();
			}
		} // namespace x11
	} // namespace window
} // namespace ece
