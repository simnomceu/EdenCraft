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

#ifndef LINEAR_UNARY_OPERATION_HPP
#define LINEAR_UNARY_OPERATION_HPP

#include <functional>

#include "utility/template_expression/linear_expression.hpp"
#include "utility/template_expression/literal.hpp"

namespace ece
{
	/**
	* @class LinearUnaryOperation
	* @extends LinearExpression<LinearUnaryOperation<E, Op>>
	* @tparam E The type of the first factor of the operation.
	* @tparam Op The operation to apply to.
	* @brief Vector operation.
	*/
	template <class E, class Op>
	class LinearUnaryOperation : public LinearExpression<LinearUnaryOperation<E, Op>>
	{
	public:
		constexpr LinearUnaryOperation() noexcept = delete;

		/**
		* @fn LinearUnaryOperation(const E & lhs) noexcept
		* @param[in] lhs The left-hand side of the operation.
		* @brief Build an operation from a vector factor.
		* @throw noexcept
		*/
		LinearUnaryOperation(const E & lhs) noexcept;

		/**
		* @fn LinearUnaryOperation(const LinearUnaryOperation & copy) noexcept
		* @param[in] copy The LinearUnaryOperation to copy from.
		* @brief Default copy constructor.
		* @throw noexcept
		*/
		LinearUnaryOperation(const LinearUnaryOperation & copy) noexcept = default;

		/**
		* @fn LinearUnaryOperation(LinearUnaryOperation && move) noexcept
		* @param[in] move The LinearUnaryOperation to move.
		* @brief Default move constructor.
		* @throw noexcept
		*/
		LinearUnaryOperation(LinearUnaryOperation && move) noexcept = default;

		/**
		* @fn ~LinearUnaryOperation() noexcept
		* @brief Default destructor.
		* @throw noexcept
		*/
		~LinearUnaryOperation() noexcept = default;

		/**
		* @fn LinearUnaryOperation & operator=(const LinearUnaryOperation & copy) noexcept
		* @param[in] copy The LinearUnaryOperation to copy from.
		* @return The LinearUnaryOperation copied.
		* @brief Default copy assignment operator.
		* @throw noexcept
		*/
		LinearUnaryOperation & operator=(const LinearUnaryOperation & copy) noexcept = default;

		/**
		* @fn LinearUnaryOperation & operator=(LinearUnaryOperation && move) noexcept
		* @param[in] move The LinearUnaryOperation to move.
		* @return The LinearUnaryOperation moved.
		* @brief Default move assignment operator.
		* @throw noexcept
		*/
		LinearUnaryOperation & operator=(LinearUnaryOperation && move) noexcept = default;

		/**
		* @fn auto operator[](const unsigned int index) const
		* @param[in] index The index of the element to access.
		* @return The computed element of the resulting vector.
		* @brief Compute and return the element at the index in the resulting vector of the operation.
		* @throw
		*/
		inline auto operator[](const unsigned int index) const;

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
		std::conditional_t<std::is_arithmetic_v<E>, Literal<E>, const E &> _lhs;
	};
}

#include "utility/template_expression/linear_unary_operation.inl"

#endif // LINEAR_UNARY_OPERATION_HPP