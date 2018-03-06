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

#include "utility/log/service_logger.hpp"

namespace ece
{
    inline void BaseWindowAdapter::createWindow() { ServiceLoggerLocator::getService().logWarning("The window implementation does not provide any method to create a window."); }

    inline void BaseWindowAdapter::deleteWindow() { ServiceLoggerLocator::getService().logWarning("The window implementation does not provide any method to delete a window."); }

    inline bool BaseWindowAdapter::isWindowCreated() const
    {
        ServiceLoggerLocator::getService().logWarning("The window implementation does not provide any method to check if a window is created.");
        return false;
    }

    inline void BaseWindowAdapter::setTitle(const std::string & /*title*/)  { ServiceLoggerLocator::getService().logWarning("The window implementation does not provide any method to set the window title."); }

    inline std::string BaseWindowAdapter::getTitle() const
    {
        ServiceLoggerLocator::getService().logWarning("The window implementation does not provide any method to get the window title.");
        return "";
    }

    inline void BaseWindowAdapter::setPosition(const IntVector2u & /*position*/) { ServiceLoggerLocator::getService().logWarning("The window implementation does not provide any method to set he window position."); }

    inline IntVector2u BaseWindowAdapter::getPosition() const
    {
        ServiceLoggerLocator::getService().logWarning("The window implementation does not provide any method to get the window position.");
        return IntVector2u();
    }

    inline void BaseWindowAdapter::minimize() { ServiceLoggerLocator::getService().logWarning("The window implementation does not provide any method to minimize a window."); }

    inline void BaseWindowAdapter::maximize() { ServiceLoggerLocator::getService().logWarning("The window implementation does not provide any method to maximize a window."); }

    inline void BaseWindowAdapter::processEvent(const bool /*blocking*/) { ServiceLoggerLocator::getService().logWarning("The window implementation does not provide any method to process a window event."); }
}
