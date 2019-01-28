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

#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include "utility/config.hpp"

namespace ece
{
	namespace utility
	{
		namespace pattern
		{
			/**
			 * @class Observer
			 * @brief
			 */
			template <class ... Args>
			class ECE_UTILITY_API Observer
			{
			public:
				/**
				 * @fn constexpr Observer() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				constexpr Observer() noexcept = default;

				/**
				 * @fn Observer(const Observer & copy) noexcept
				 * @param[in] copy The Observer to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				Observer(const Observer<Args...> & copy) noexcept = default;

				/**
				 * @fn Observer(Observer && move) noexcept
				 * @param[in] move The Observer to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				Observer(Observer<Args...> && move) noexcept = default;

				/**
				 * @fn ~Observer() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~Observer() noexcept = default;

				/**
				 * @fn Observer & operator=(const Observer & copy) noexcept
				 * @param[in] copy The Observer to copy from.
				 * @return The Observer copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				Observer<Args...> & operator=(const Observer<Args...> & copy) noexcept = default;

				/**
				 * @fn Observer & operator=(Observer && move) noexcept
				 * @param[in] move The Observer to move.
				 * @return The Observer moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				Observer<Args...> & operator=(Observer<Args...> && move) noexcept = default;

				virtual void notify(Args&&... args) = 0;
			};
		} // namespace pattern
	} // namespace utility
} // namespace ece

#endif // OBSERVER_HPP
