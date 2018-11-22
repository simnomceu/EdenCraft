/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

															  .oooooo.
															 d8P'  `Y8b
															888           .ooooo.  oooo d8b  .ooooo.
															888          d88' `88b `888""8P d88' `88b
															888          888   888  888     888ooo888
															`88b    ooo  888   888  888     888    .o
															 `Y8bood8P'  `Y8bod8P' d888b    `Y8bod8P'



				This file is part of EdenCraft Engine - Core module.
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

#ifndef SERVICE_FORMAT_HPP
#define SERVICE_FORMAT_HPP

#include "core/config.hpp"
#include "utility/service.hpp"
#include "core/format/format_manager.hpp"

namespace ece
{
	namespace utility
	{
		namespace service
		{
			template <>
			class ECE_CORE_API ServiceFactory<core::format::FormatManager>
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
				static std::shared_ptr<core::format::FormatManager> build()
				{
					if (!std::is_base_of<core::format::FormatManager, Derived>()) {
						throw InitializationException("This class cannot be instantiate as the service wished. Check again.");
					}
					return std::shared_ptr<core::format::FormatManager>(new Derived());
				}
			};

			template <>
			class ECE_CORE_API ServiceLocator<core::format::FormatManager, core::format::FormatManager>
			{
			public:
				/**
				* @fn void provide(const std::shared_ptr<Base> & service)
				* @param[in] service The service which has to be provided by the locator.
				* @brief Set the service provided by the locator.
				* @throw
				*/
				static void provide(const std::shared_ptr<core::format::FormatManager> & service);

				/**
				* @fn Base & getService()
				* @return The service currently started.
				* @brief Consume the service provided.
				* @throw
				* @remark Should be rename as consume() ?
				*/
				static core::format::FormatManager & getService();

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
				static std::shared_ptr<core::format::FormatManager> _service;
			};
		} // namespace service
	} // namespace utility

	namespace core
	{
		namespace format
		{
			using ServiceFormatFactory = utility::service::ServiceFactory<FormatManager>;

			using ServiceFormatLocator = utility::service::ServiceLocator<FormatManager, FormatManager>;
		} // namespace format
	} // namespace core
} // namespace ece

#endif // SERVICE_FORMAT_HPP