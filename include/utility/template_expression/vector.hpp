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

#ifndef NEW_VECTOR_HPP
#define NEW_VECTOR_HPP

#include <array>

#include "utility/template_expression/vector_expression.hpp"
#include "utility/template_expression/vector_operator.hpp"

namespace ece
{
	/**
	 * @class Vector
	 * @tparam E The type of elements in the vector.
	 * @tparam Size The size of the vector.
	 * @extends VectorExpression<Vector, E>
	 * @brief An arithmetic vector.
	 */
	template <typename E, unsigned int Size, typename enabled = std::enable_if<std::is_arithmetic_v<E>>>
	class Vector : public VectorExpression<Vector<E, Size, enabled>>
	{
	public:
		/**
		 * @fn constexpr Vector() noexcept
		 * @brief Default constructor.
		 * @throw noexcept
		 */
		constexpr Vector() noexcept = default;

		/**
		 * @fn constexpr Vector(const E value) noexcept
		 * @param[in] value The value to assign to all the members of the vector.
		 * @brief Build a vector with the same value for all members.
		 * @throw noexcept
		 */
		inline constexpr Vector(const E value) noexcept;

		/**
		 * @fn Vector(const VectorExpression<Vector<E, Size, enabled>, E> & rhs) noexcept
		 * @param[in] The vector expression to cast.
		 * @brief Build a vector from a vector expression, forcing its evaluation.
		 * @throw noexcept
		 */
		Vector(const VectorExpression<Vector<E, Size, enabled>> & rhs) noexcept;

		/**
		 * @fn Vector(std::initializer_list<E> il) noexcep
		 * @param[in] il The list of elements to set.
		 * @brief Build a vector from a list of elements.
		 * @throw
		 */
		Vector(std::initializer_list<E> il) noexcept;

		/**
		 * @fn Vector(const Vector<E, Size, enabled> & copy) noexcept
		 * @param[in] copy The Vector to copy from.
		 * @brief Default copy constructor.
		 * @throw noexcept
		 */
		Vector(const Vector<E, Size, enabled> & copy) noexcept = default;

		/**
		 * @fn Vector(Vector<E, Size, enabled> && move) noexcept
		 * @param[in] move The Vector to move.
		 * @brief Default move constructor.
		 * @throw noexcept
		 */
		Vector(Vector<E, Size, enabled> && move) noexcept = default;

		/**
		 * @fn ~Vector() noexcept
		 * @brief Default destructor.
		 * @throw noexcept
		 */
		~Vector() noexcept = default;

		/**
		 * @fn Vector & operator=(const Vector & copy) noexcept
		 * @param[in] copy The Vector to copy from.
		 * @return The Vector copied.
		 * @brief Default copy assignment operator.
		 * @throw noexcept
		 */
		Vector<E, Size, enabled> & operator=(const Vector<E, Size, enabled> & copy) noexcept = default;

		/**
		 * @fn Vector<E, Size, enabled> & operator=(Vector<E, Size, enabled> && move) noexcept
		 * @param[in] move The Vector to move.
		 * @return The Vector moved.
		 * @brief Default move assignment operator.
		 * @throw noexcept
		 */
		Vector<E, Size, enabled> & operator=(Vector<E, Size, enabled> && move) noexcept = default;

		/**
		 * @fn Vector<E, Size, enabled> & operator=(const VectorExpression<Vector<E, Size, enabled>, E> & rhs) noexcept
		 * @param[in] rhs The vector expression to cast.
		 * @return The vector built.
		 * @brief Build a vector from a vector expression, forcing its evaluation.
		 * @throw noexcept
		 */
		Vector<E, Size, enabled> & operator=(const VectorExpression<Vector<E, Size, enabled>> & rhs) noexcept;

		/**
		* @fn E operator[](const unsigned int index) const
		* @param[in] index The index of the element to access.
		* @return The element wished.
		* @brief Get the element at the index.
		* @throw
		*/
		inline E operator[](const unsigned int index) const;

		/**
		* @fn E & operator[](const unsigned int index)
		* @param[in] index The index of the element to access.
		* @return The element wished.
		* @brief Get the element at the index.
		* @throw
		*/
		inline E & operator[](const unsigned int index);

		/**
		* @fn unsigned int size() const noexcept
		* @return The number of element in the expression result.
		* @brief Get he number of elements.
		* @throw noexcept
		*/
		inline unsigned int size() const noexcept;

	protected:
		std::array<E, Size> _elements;
	};

	LXR_OPERATOR(VectorSum, +)
	LXR_OPERATOR(VectorSubtract, -)
	LXR_OPERATOR(VectorMultiply, *)
	LXR_OPERATOR(VectorDivide, /)
	LXR_OPERATOR(VectorModulo, %)
}

#include "utility/template_expression/vector.inl"

#endif // NEW_VECTOR_HPP