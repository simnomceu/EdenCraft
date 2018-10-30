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

#ifndef SERVICE_LOGGER_HPP
#define SERVICE_LOGGER_HPP

#include "utility/config.hpp"
#include "utility/service.hpp"
#include "utility/log/logger.hpp"

namespace ece
{
    namespace utility
    {
		namespace service
		{
			template <>
			class ECE_UTILITY_API ServiceFactory<log::Logger>
			{
			public:
				/**
				* @fn std::shared_ptr<Base> build()
				* @tparam Derived The derived class of the service to build
				* @return The base service built
				* @brief Build the service according to the derived implementation.
				* @throw
				* @remark It should be refactor to something like that: build(Args...&& args)
				*/
				template <class Derived>
				static auto build() -> std::shared_ptr<log::Logger>
				{
					if (!std::is_base_of<log::Logger, Derived>()) {
						throw InitializationException("This class cannot be instantiate as the service wished. Check again.");
					}
					return std::make_shared<Derived>();
				}
			};

			template <>
			class ECE_UTILITY_API ServiceLocator<log::Logger, log::Logger>
			{
			public:
				/**
				* @fn void provide(const std::shared_ptr<Base> & service)
				* @param[in] service The service which has to be provided by the locator.
				* @brief Set the service provided by the locator.
				* @throw
				*/
				static void provide(const std::shared_ptr<log::Logger> & service);

				/**
				* @fn Base & getService()
				* @return The service currently started.
				* @brief Consume the service provided.
				* @throw
				* @remark Should be rename as consume() ?
				*/
				static auto getService() -> log::Logger &;

				//static std::weak_ptr<Base> getServicePtr();

				/**
				* @fn void stop()
				* @brief Stop the current service. The locator still exists but provide an empty service (which do nothing).
				* @throw
				*/
				static void stop();

			protected:
				/**
				* @property _service
				* @brief The service to expose.
				*/
				static std::shared_ptr<log::Logger> _service;
			};
		}

        namespace log
        {
        	/**
        	 * @typedef ServiceLoggerFactory;
        	 * @brief Factory to build a logger implementation.
        	 */
        	using ServiceLoggerFactory = ServiceFactory<Logger>;

        	/**
        	 * @typedef ServiceLoggerLocator;
        	 * @brief Locator to access the current logger implementation.
        	 */
        	using ServiceLoggerLocator = ServiceLocator<Logger, Logger>;

        	/**
        	 * @remark LoggerHelper ERROR, WARNING, and INFO which implements operator<< and operator>> should be added to help.
        	 */
        } // namespace log
    } // namespace utility
} // namespace ece

#endif
