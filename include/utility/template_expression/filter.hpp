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
				along with this program.If noE, see <http://www.gnu.org/licenses/>.

*/

#ifndef FILTER_HPP
#define FILTER_HPP

#include <type_traits>

#include "utility/template_expression/linear_expression.hpp"

namespace ece
{
	template <typename E, unsigned int Size, typename enabled> class Vector;

	/**
	 * @class Filter
	 * @tparam Container The type of container (linked to the linear expressions) to filter.
	 * @tparam Size The complete size of the container.
	 * @tparam enabled The filter is available only for linear expressions.
	 * @brief A filter for container, to handle only some of its elements.
	 */
	template <class Container, unsigned int Size, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<Container>, Container>>>
	class Filter
	{
	public:
		constexpr Filter() noexcept = delete;

		/**
		 * @fn Filter(Container & container, Vector<bool, Size, enabled> && filter)
		 * @param[in] container The container to filter.
		 * @param[in] filter The filter to use.
		 * @brief Build a filtered container.
		 */
		Filter(Container & container, Vector<bool, Size, enabled> && filter);
		
		/**
		 * @fn Filter(Container & container, std::initializer_list<unsigned int> && il)
		 * @param[in] container The container to filter.
		 * @param[in] il The filter to use.
		 * @brief Build a filtered container.
		 */
		Filter(Container & container, std::initializer_list<unsigned int> && il);

		/**
		 * @fn Filter(const Filter<Container, Size, enabled> & copy) noexcept
		 * @param[in] copy The filter to copy from.
		 * @brief Default copy constructor.
		 * @throw noexcept
		 */
		Filter(const Filter<Container, Size, enabled> & copy) noexcept = default;

		/**
		 * @fn Filter(Filter<Container, Size, enabled> && move) noexcept
		 * @param[in] move The Filter to move.
		 * @brief Default move constructor.
		 * @throw noexcept
		 */
		Filter(Filter<Container, Size, enabled> && move) noexcept = default;

		/**
		 * @fn ~Filter() noexcept
		 * @brief Default destructor.
		 * @throw noexcept
		 */
		~Filter() noexcept = default;

		/**
		 * @fn Filter<Container, Size, enabled> & operator=(const Filter<Container, Size, enabled> & copy) noexcept
		 * @param[in] copy The Filter to copy from.
		 * @return The Filter copied.
		 * @brief Default copy assignment operator.
		 * @throw noexcept
		 */
		Filter<Container, Size, enabled> & operator=(const Filter<Container, Size, enabled> & copy) noexcept = default;

		/**
		 * @fn Filter<Container, Size, enabled> & operator=(Filter<Container, Size, enabled> && move) noexcept
		 * @param[in] move The Filter to move.
		 * @return The Filter moved.
		 * @brief Default move assignment operator.
		 * @throw noexcept
		 */
		Filter<Container, Size, enabled> & operator=(Filter<Container, Size, enabled> && move) noexcept = default;

		/**
		 * @tparam T The type of the right-hand side of the operation.
		 * @fn Container & operator=(const T & rhs)
		 * @param[in] rhs The right-hand side of the operation.
		 * @return The filtered container modified.
		 * @brief Apply the assigment operation to the filtered container.
		 */
		template <class T> Container & operator=(const T & rhs);

		/**
		 * @tparam T The type of the right-hand side of the operation.
		 * @fn Container & operator+=(const T & rhs)
		 * @param[in] rhs The right-hand side of the operation.
		 * @return The filtered container modified.
		 * @brief Apply the addition assigment operation to the filtered container.
		 */
		template <class T> Container & operator+=(const T & rhs);

		/**
		 * @tparam T The type of the right-hand side of the operation.
		 * @fn Container & operator-=(const T & rhs)
		 * @param[in] rhs The right-hand side of the operation.
		 * @return The filtered container modified.
		 * @brief Apply the subtraction assigment operation to the filtered container.
		 */
		template <class T> Container & operator-=(const T & rhs);

		/**
		 * @tparam T The type of the right-hand side of the operation.
		 * @fn Container & operator*=(const T & rhs)
		 * @param[in] rhs The right-hand side of the operation.
		 * @return The filtered container modified.
		 * @brief Apply the multiplication assigment operation to the filtered container.
		 */
		template <class T> Container & operator*=(const T & rhs);

		/**
		 * @tparam T The type of the right-hand side of the operation.
		 * @fn Container & operator/=(const T & rhs)
		 * @param[in] rhs The right-hand side of the operation.
		 * @return The filtered container modified.
		 * @brief Apply the division assigment operation to the filtered container.
		 */
		template <class T> Container & operator/=(const T & rhs);

		/**
		 * @tparam T The type of the right-hand side of the operation.
		 * @fn Container & operator%=(const T & rhs)
		 * @param[in] rhs The right-hand side of the operation.
		 * @return The filtered container modified.
		 * @brief Apply the modulo assigment operation to the filtered container.
		 */
		template <class T> Container & operator%=(const T & rhs);

		/**
		 * @tparam T The type of the right-hand side of the operation.
		 * @fn Container & operator&=(const T & rhs)
		 * @param[in] rhs The right-hand side of the operation.
		 * @return The filtered container modified.
		 * @brief Apply the bitwise and assigment operation to the filtered container.
		 */
		template <class T> Container & operator&=(const T & rhs);

		/**
		 * @tparam T The type of the right-hand side of the operation.
		 * @fn Container & operator|=(const T & rhs)
		 * @param[in] rhs The right-hand side of the operation.
		 * @return The filtered container modified.
		 * @brief Apply the bitwise or assigment operation to the filtered container.
		 */
		template <class T> Container & operator|=(const T & rhs);

		/**
		 * @tparam T The type of the right-hand side of the operation.
		 * @fn Container & operator^=(const T & rhs)
		 * @param[in] rhs The right-hand side of the operation.
		 * @return The filtered container modified.
		 * @brief Apply the bitwise xor assigment operation to the filtered container.
		 */
		template <class T> Container & operator^=(const T & rhs);

		/**
		 * @tparam T The type of the right-hand side of the operation.
		 * @fn Container & operator<<=(const T & rhs)
		 * @param[in] rhs The right-hand side of the operation.
		 * @return The filtered container modified.
		 * @brief Apply the bitwise left shift assigment operation to the filtered container.
		 */
		template <class T> Container & operator<<=(const T & rhs);

		/**
		 * @tparam T The type of the right-hand side of the operation.
		 * @fn Container & operator>>=(const T & rhs)
		 * @param[in] rhs The right-hand side of the operation.
		 * @return The filtered container modified.
		 * @brief Apply the bitwise right shift assigment operation to the filtered container.
		 */
		template <class T> Container & operator>>=(const T & rhs);

	private:
		/**
		 * @property _container
		 * @brief The container to filter.
		 */
		Container & _container;

		/**
		 * @property _filter
		 * @brief The filter to use.
		 */
		Vector<bool, Size, enabled> _filter;
	};
}

#include "utility/template_expression/filter.inl"

#endif // VECTOR_FILTER_HPP