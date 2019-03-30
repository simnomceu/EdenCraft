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

#ifndef OBSERVABLE_HPP
#define OBSERVABLE_HPP

#include "utility/config.hpp"
#include "utility/pch.hpp"

namespace ece
{
	namespace utility
	{
		namespace pattern
		{
			template <class ... Args> class Observer;

			/**
			 * @class Observable
			 * @brief
			 */
			template <class... Args>
			class ECE_UTILITY_API Observable
			{
			public:
				/**
				 * @fn constexpr Observable() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				inline constexpr Observable() noexcept;

				/**
				 * @fn Observable(const Observable & copy)
				 * @param[in] copy The Observable to copy from.
				 * @brief Default copy constructor.
				 * @throw
				 */
				Observable(const Observable<Args...> & copy) = default;

				/**
				 * @fn Observable(Observable && move) noexcept
				 * @param[in] move The Observable to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				Observable(Observable<Args...> && move) noexcept = default;

				/**
				 * @fn ~Observable() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~Observable() noexcept = default;

				/**
				 * @fn Observable & operator=(const Observable & copy)
				 * @param[in] copy The Observable to copy from.
				 * @return The Observable copied.
				 * @brief Default copy assignment operator.
				 * @throw
				 */
				Observable<Args...> & operator=(const Observable<Args...> & copy) = default;

				/**
				 * @fn Observable & operator=(Observable && move) noexcept
				 * @param[in] move The Observable to move.
				 * @return The Observable moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				Observable<Args...> & operator=(Observable && move) noexcept = default;

				inline void attach(const std::shared_ptr<Observer<Args...>> & observer);
				inline void detach(const std::shared_ptr<Observer<Args...>> & observer);

				inline void detachAll();

				void notify(Args &&... args);

			protected:
				std::vector<std::shared_ptr<Observer<Args...>>> _observers;
			};
		} // namespace pattern
	} // namespace utility
} // namespace ece

#include "utility/pattern/observable.inl"

#endif // OBSERVABLE_HPP