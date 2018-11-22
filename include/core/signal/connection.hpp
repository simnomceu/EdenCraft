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

#ifndef CONNECTION_HPP
#define CONNECTION_HPP

#include "core/config.hpp"

#include <memory>

namespace ece
{
	namespace core
	{
		namespace signal
		{
			template <class... Args> class SignalImplementation;
			template <class... Args> class Slot;

			/**
			 * @class Connection
			 * @brief
			 */
			template <class... Args>
			class ECE_CORE_API Connection
			{
			public:
				Connection(const std::weak_ptr<SignalImplementation<Args...>> & signal, const std::weak_ptr<Slot<Args...>> & slot) noexcept;

				/**
				 * @fn Connection(const Connection & copy) noexcept
				 * @param[in] copy The Connection to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				Connection(const Connection & copy) noexcept = default;

				/**
				 * @fn Connection(Connection && move) noexcept
				 * @param[in] move The Connection to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				Connection(Connection && move) noexcept = default;

				/**
				 * @fn ~Connection() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~Connection() noexcept = default;

				/**
				 * @fn Connection & operator=(const Connection & copy) noexcept
				 * @param[in] copy The Connection to copy from.
				 * @return The Connection copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				Connection & operator=(const Connection & copy) noexcept = default;

				/**
				 * @fn Connection & operator=(Connection && move) noexcept
				 * @param[in] move The Connection to move.
				 * @return The Connection moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				Connection & operator=(Connection && move) noexcept = default;

				bool isConnected() const noexcept;

				void disconnect();

			protected:
				Connection() noexcept = default;

			private:
				std::weak_ptr<SignalImplementation<Args...>> _signal;
				std::weak_ptr<Slot<Args...>> _slot;
			};
		} // namespace signal
	} // namespace core
} // namespace ece

#include "core/signal/connection.inl"

#endif // CONNECTION_HPP