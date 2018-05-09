/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

															ooooo     ooo     .    o8o  oooo   o8o      .
															`888'     `8'   .o8    `"'  `888   `"'    .o8
															 888       8  .o888oo oooo   888  oooo  .o888oo oooo    ooo
															 888       8    888   `888   888  `888    888    `88.  .8'
															 888       8    888    888   888   888    888     `88..8'
															 `88.    .8'    888 .  888   888   888    888 .    `888'
															   `YbodP'      "888" o888o o888o o888o   "888"     .8'
																											.o..P'
																											`Y8P'

				This file is part of EdenCraft Engine - Utility module.
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

#ifndef BASE_LOGGER_HPP
#define BASE_LOGGER_HPP

#include <string>
#include <iostream>

namespace ece
{
    namespace utility
    {
        namespace log
        {
        	/**
        	 * @class BaseLogger
        	 * @brief Empty base of the logger service.
        	 */
        	class BaseLogger
        	{
        	public:
        		/**
        		 * @fn BaseLogger()
        		 * @brief Default constructor.
        		 * @throw
        		 */
        		inline BaseLogger();

        		/**
        		 * @fn BaseLogger(const BaseLogger & copy)
        		 * @param[in] copy The logger to copy from.
        		 * @brief Default copy constructor.
        		 * @throw
        		 */
        		BaseLogger(const BaseLogger & copy) = default;

        		/**
        		 * @fn BaseLogger(BaseLogger && move)
        		 * @param[in] move The logger to move.
        		 * @brief Default move constructor.
        		 * @throw noexcept
        		 */
        		BaseLogger(BaseLogger && move) noexcept = default;

        		/**
        		 * @fn ~BaseLogger()
        		 * @brief Default destructor.
        		 * @throw noexcept
        		 */
        		~BaseLogger() noexcept = default;

        		/**
        		 * @fn BaseLogger & operator=(const BaseLogger & copy)
        		 * @param[in] copy The logger to copy from.
        		 * @return The logger copied.
        		 * @brief Default copy assignment operator.
        		 * @throw
        		 */
        		BaseLogger & operator=(const BaseLogger & copy) = default;

        		/**
        		 * @fn BaseLogger & operator=(BaseLogger && move)
        		 * @param[in] move The logger to move.
        		 * @return The logger moved.
        		 * @brief Default move assignment operator.
        		 * @throw noexcept
        		 */
        		BaseLogger & operator=(BaseLogger && move) noexcept = default;

        		/**
        		 * @fn void logError(const std::string & data)
        		 * @param[in] data The data to log.
        		 * @brief Log data with the tag ERROR.
        		 * @throw
        		 */
        		inline virtual void logError(const std::string & data);

        		/**
        		 * @fn void logWarning(const std::string & data)
        		 * @param[in] data The data to log.
        		 * @brief Log data with the tag WARNING.
        		 * @throw
        		 */
        		inline virtual void logWarning(const std::string & data);

        		/**
        		 * @fn void logInfo(const std::string & data)
        		 * @param[in] data The data to log.
        		 * @brief Log data with the tag INFO.
        		 * @throw
        		 */
        		inline virtual void logInfo(const std::string & data);

        	protected:
        		/**
        		 * @property _target
        		 * @brief The target stream to send the log.
        		 */
        		std::ostream & _target;
        	};
        } // namespace log
    } // namespace utility
} // namespace ece

#include "utility/log/base_logger.inl"

#endif // BASE_LOGGER_HPP
