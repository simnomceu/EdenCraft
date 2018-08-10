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

#ifndef SECURED_CONNECTION_HPP
#define SECURED_CONNECTION_HPP

#include "core/config.hpp"
#include "core/signal/connection.hpp"

namespace ece
{
	namespace core
	{
		namespace signal
		{
			/**
			 * @class SecuredConnection
			 * @brief
			 */
			template <class... Args>
			class ECE_CORE_API SecuredConnection: public Connection<Args...>
			{
			public:
				/**
				 * @fn constexpr SecuredConnection() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				SecuredConnection() noexcept = default;

				inline SecuredConnection(Connection<Args...> && connection) noexcept;
				inline SecuredConnection(const Connection<Args...> & connection) noexcept;

				/**
				 * @fn SecuredConnection(const SecuredConnection & copy) noexcept
				 * @param[in] copy The SecuredConnection to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				SecuredConnection(const SecuredConnection<Args...> & copy) noexcept = default;

				/**
				 * @fn SecuredConnection(SecuredConnection && move) noexcept
				 * @param[in] move The SecuredConnection to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				SecuredConnection(SecuredConnection<Args...> && move) noexcept = default;

				/**
				 * @fn ~SecuredConnection() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				inline ~SecuredConnection() noexcept;

				/**
				 * @fn SecuredConnection & operator=(const SecuredConnection & copy) noexcept
				 * @param[in] copy The SecuredConnection to copy from.
				 * @return The SecuredConnection copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				SecuredConnection<Args...> & operator=(const SecuredConnection<Args...> & copy) noexcept = default;

				/**
				 * @fn SecuredConnection & operator=(SecuredConnection && move) noexcept
				 * @param[in] move The SecuredConnection to move.
				 * @return The SecuredConnection moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				SecuredConnection<Args...> & operator=(SecuredConnection<Args...> && move) noexcept = default;

				SecuredConnection<Args...> & operator=(const Connection<Args...> & copy) noexcept;
				SecuredConnection<Args...> & operator=(Connection<Args...> && move) noexcept;
			};
		} // namespace signal
	} // namespace core
} // namespace ece

#include "core/signal/secured_connection.inl"

#endif // SECURED_CONNECTION_HPP