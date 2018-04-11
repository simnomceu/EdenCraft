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

#ifndef LINEAR_OPERATION_HPP
#define LINEAR_OPERATION_HPP

#include <functional>

#include "utility/template_expression/linear_expression.hpp"
#include "utility/template_expression/literal.hpp"

namespace ece
{
	/**
	 * @class LinearOperation
	 * @extends LinearExpression<LinearOperation<E1, E2, Op>>
	 * @tparam E1 The type of the first factor of the operation.
	 * @tparam E2 The type of the second factor of the operation.
	 * @tparam Op The operation to apply to.
	 * @brief Vector operation.
	 */
	template <class E1, class E2, class Op>
	class LinearOperation: public LinearExpression<LinearOperation<E1, E2, Op>>
	{
	public:
		constexpr LinearOperation() noexcept = delete;

		/**
		 * @fn LinearOperation(const E1 & lhs, const E2 & rhs) noexcept
		 * @param[in] lhs The left-hand side of the operation.
		 * @param[in] rhs The right-hand side of the operation.
		 * @brief Build an operation from two vector factors.
		 * @throw noexcept
		 */
		LinearOperation(const E1 & lhs, const E2 & rhs) noexcept;

		/**
		 * @fn LinearOperation(const LinearOperation & copy) noexcept
		 * @param[in] copy The LinearOperation to copy from.
		 * @brief Default copy constructor.
		 * @throw noexcept
		 */
		LinearOperation(const LinearOperation & copy) noexcept = default;

		/**
		 * @fn LinearOperation(LinearOperation && move) noexcept
		 * @param[in] move The LinearOperation to move.
		 * @brief Default move constructor.
		 * @throw noexcept
		 */
		LinearOperation(LinearOperation && move) noexcept = default;

		/**
		 * @fn ~LinearOperation() noexcept
		 * @brief Default destructor.
		 * @throw noexcept
		 */
		~LinearOperation() noexcept = default;

		/**
		 * @fn LinearOperation & operator=(const LinearOperation & copy) noexcept
		 * @param[in] copy The LinearOperation to copy from.
		 * @return The LinearOperation copied.
		 * @brief Default copy assignment operator.
		 * @throw noexcept
		 */
		LinearOperation & operator=(const LinearOperation & copy) noexcept = default;

		/**
		 * @fn LinearOperation & operator=(LinearOperation && move) noexcept
		 * @param[in] move The LinearOperation to move.
		 * @return The LinearOperation moved.
		 * @brief Default move assignment operator.
		 * @throw noexcept
		 */
		LinearOperation & operator=(LinearOperation && move) noexcept = default;

		/**
		 * @fn auto operator[](const unsigned int index) const
		 * @param[in] index The index of the element to access.
		 * @return The computed element of the resulting vector.
		 * @brief Compute and return the element at the index in the resulting vector of the operation.
		 * @throw
		 * @see auto LinearOperation<E1, E2, Op>::cell(const unsigned int index) const
		 */
		inline auto operator[](const unsigned int index) const;
		
		/**
		 * @fn auto cell(const unsigned int index) const
		 * @param[in] index The index of the element to access.
		 * @return The computed element of the resulting vector.
		 * @brief Compute and return the element at the index in the resulting vector of the operation.
		 * @throw
		 * @see auto LinearOperation<E1, E2, Op>::operator[](const unsigned int index) const
		 */
		inline auto cell(const unsigned int index) const;

		/**
		 * @fn unsigned int size() const
		 * @return The size of the resulting vector.
		 * @brief Get the size of the resulting vector.
		 * @throw
		 */
		inline unsigned int size() const;

	private:
		/**
		 * @property _lhs
		 * @brief The left-hand side of the operation.
		 */
		std::conditional_t<std::is_arithmetic_v<E1>, Literal<E1>, const E1 &> _lhs;
		
		/**
		 * @property _rhs
		 * @brief The right-hand side of the operation.
		 */
		std::conditional_t<std::is_arithmetic_v<E2>, Literal<E2>, const E2 &> _rhs;
	};
}

#include "utility/template_expression/linear_operation.inl"

#endif // LINEAR_OPERATION_HPP