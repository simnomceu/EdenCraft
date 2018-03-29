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

#ifndef VECTOR_OPERATOR_HPP
#define VECTOR_OPERATOR_HPP

#include <functional>

#include "utility/template_expression/vector_expression.hpp"

namespace ece
{
	/**
	 * @class VectorOperation
	 * @extends VectorExpression<VectorOperation<E1, E2, Op>>
	 * @tparam E1 The type of the first factor of the operation.
	 * @tparam E2 The type of the second factor of the operation.
	 * @tparam Op The operation to apply to.
	 * @brief Vector operation.
	 */
	template <class E1, class E2, class Op>
	class VectorOperation: public VectorExpression<VectorOperation<E1, E2, Op>>
	{
	public:
		constexpr VectorOperation() noexcept = delete;

		/**
		 * @fn VectorOperation(const E1 & lhs, const E2 & rhs) noexcept
		 * @param[in] lhs The left-hand side of the operation.
		 * @param[in] rhs The right-hand side of the operation.
		 * @brief Build an operation from two vector factors.
		 * @throw noexcept
		 */
		VectorOperation(const E1 & lhs, const E2 & rhs) noexcept;

		/**
		 * @fn VectorOperation(const VectorOperation & copy) noexcept
		 * @param[in] copy The VectorOperation to copy from.
		 * @brief Default copy constructor.
		 * @throw noexcept
		 */
		VectorOperation(const VectorOperation & copy) noexcept = default;

		/**
		 * @fn VectorOperation(VectorOperation && move) noexcept
		 * @param[in] move The VectorOperation to move.
		 * @brief Default move constructor.
		 * @throw noexcept
		 */
		VectorOperation(VectorOperation && move) noexcept = default;

		/**
		 * @fn ~VectorOperation() noexcept
		 * @brief Default destructor.
		 * @throw noexcept
		 */
		~VectorOperation() noexcept = default;

		/**
		 * @fn VectorOperation & operator=(const VectorOperation & copy) noexcept
		 * @param[in] copy The VectorOperation to copy from.
		 * @return The VectorOperation copied.
		 * @brief Default copy assignment operator.
		 * @throw noexcept
		 */
		VectorOperation & operator=(const VectorOperation & copy) noexcept = default;

		/**
		 * @fn VectorOperation & operator=(VectorOperation && move) noexcept
		 * @param[in] move The VectorOperation to move.
		 * @return The VectorOperation moved.
		 * @brief Default move assignment operator.
		 * @throw noexcept
		 */
		VectorOperation & operator=(VectorOperation && move) noexcept = default;

		/**
		 * @fn auto operator[](const unsigned int index) const
		 * @param[in] index The index of the element to access.
		 * @return The computed element of the resulting vector.
		 * @brief Compute and return the element at the index in the resulting vector of the operation.
		 * @throw
		 */
		inline auto operator[](const unsigned int index) const;

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
		const E1 _lhs;
		
		/**
		 * @property _rhs
		 * @brief The right-hand side of the operation.
		 */
		const E2 _rhs;
	};
	
	/**
	 * @class VectorUnaryOperation
	 * @extends VectorExpression<VectorUnaryOperation<E, Op>>
	 * @tparam E The type of the first factor of the operation.
	 * @tparam Op The operation to apply to.
	 * @brief Vector operation.
	 */
	template <class E, class Op>
	class VectorUnaryOperation: public VectorExpression<VectorUnaryOperation<E, Op>>
	{
	public:
		constexpr VectorUnaryOperation() noexcept = delete;

		/**
		 * @fn VectorUnaryOperation(const E & lhs) noexcept
		 * @param[in] lhs The left-hand side of the operation.
		 * @brief Build an operation from a vector factor.
		 * @throw noexcept
		 */
		VectorUnaryOperation(const E & lhs) noexcept;

		/**
		 * @fn VectorUnaryOperation(const VectorUnaryOperation & copy) noexcept
		 * @param[in] copy The VectorUnaryOperation to copy from.
		 * @brief Default copy constructor.
		 * @throw noexcept
		 */
		VectorUnaryOperation(const VectorUnaryOperation & copy) noexcept = default;

		/**
		 * @fn VectorUnaryOperation(VectorUnaryOperation && move) noexcept
		 * @param[in] move The VectorUnaryOperation to move.
		 * @brief Default move constructor.
		 * @throw noexcept
		 */
		VectorUnaryOperation(VectorUnaryOperation && move) noexcept = default;

		/**
		 * @fn ~VectorUnaryOperation() noexcept
		 * @brief Default destructor.
		 * @throw noexcept
		 */
		~VectorUnaryOperation() noexcept = default;

		/**
		 * @fn VectorUnaryOperation & operator=(const VectorUnaryOperation & copy) noexcept
		 * @param[in] copy The VectorUnaryOperation to copy from.
		 * @return The VectorUnaryOperation copied.
		 * @brief Default copy assignment operator.
		 * @throw noexcept
		 */
		VectorUnaryOperation & operator=(const VectorUnaryOperation & copy) noexcept = default;

		/**
		 * @fn VectorUnaryOperation & operator=(VectorUnaryOperation && move) noexcept
		 * @param[in] move The VectorUnaryOperation to move.
		 * @return The VectorUnaryOperation moved.
		 * @brief Default move assignment operator.
		 * @throw noexcept
		 */
		VectorUnaryOperation & operator=(VectorUnaryOperation && move) noexcept = default;

		/**
		 * @fn auto operator[](const unsigned int index) const
		 * @param[in] index The index of the element to access.
		 * @return The computed element of the resulting vector.
		 * @brief Compute and return the element at the index in the resulting vector of the operation.
		 * @throw
		 */
		inline auto operator[](const unsigned int index) const;

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
		const E _lhs;
	};

	template <class E, typename enabled = typename std::enable_if_t<std::is_base_of_v<VectorExpression<E>, E>>>
	VectorUnaryOperation<E, std::negate<>> operator-(const E & lhs);
}

#include "utility/template_expression/vector_operator.inl"

#endif // VECTOR_OPERATOR_HPP