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

#include "window/pch.hpp"
#include "window/common/window_adapter.hpp"
#include "window/x11/data_window_adapter.hpp"
#include "window/x11/xcb_impl.hpp"
#include "window/x11/xlib_impl.hpp"
#include "utility/log.hpp"

namespace ece
{
	namespace window
	{
		namespace common
		{
			using x11::XCBImpl;
			using x11::XlibImpl;

			WindowAdapter::WindowAdapter() noexcept: BaseWindowAdapter(), _data(makePimpl<DataWindowAdapter>(std::make_shared<XCBImpl>())) {}

			void WindowAdapter::createWindow()
			{
				try {
					this->_data->_api->createWindow();
				}
				catch (std::runtime_error & e) {
					ServiceLoggerLocator::getService().logInfo(std::string(e.what()) + " Xlib client will be used instead.");
					this->_data = makePimpl<DataWindowAdapter>(std::make_shared<XlibImpl>());
					this->_data->_api->createWindow();
				}
			}

			void WindowAdapter::deleteWindow()
			{
				this->_data->_api->deleteWindow();
			}

			bool WindowAdapter::isWindowCreated() const
			{
				return this->_data->_api->isWindowCreated();
			}

			void WindowAdapter::setTitle(const std::string & title)
			{
				this->_data->_api->setTitle(title);
			}

			std::string WindowAdapter::getTitle() const
			{
				return this->_data->_api->getTitle();
			}

			void WindowAdapter::setPosition(const IntVector2u & position)
			{
				this->_data->_api->setPosition(position);
			}

			IntVector2u WindowAdapter::getSize() const
			{
				return this->_data->_api->getSize();
			}

			IntVector2u WindowAdapter::getPosition() const
			{
				return this->_data->_api->getPosition();
			}

			void WindowAdapter::minimize()
			{
				this->_data->_api->minimize();
			}

			void WindowAdapter::maximize()
			{
				this->_data->_api->maximize();
			}

			void WindowAdapter::processEvent(const bool blocking)
			{
				auto events = std::move(this->_data->_api->processEvent(blocking, this->_keyRepeat));
				for (auto event : events) {
					if (event._type != InputEvent::Type::ECE_TYPE_NONE) {
						this->pushEvent(std::move(event));
					}
				}
			}
		} // namespace common
	} // namespace window
} // namespace ece
