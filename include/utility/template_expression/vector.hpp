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

#ifdef _MSC_VER
#	undef min
#	undef max
#endif

#include <array>
#include <type_traits>
#include <cmath>

#include "utility/template_expression/linear_expression.hpp"
#include "utility/template_expression/linear_operation.hpp"
#include "utility/template_expression/linear_unary_operation.hpp"
#include "utility/template_expression/literal.hpp"
#include "utility/template_expression/functional.hpp"

namespace ece
{
	template <class Container, unsigned int Size, typename enabled> class Filter;

	/**
	 * @class Vector
	 * @tparam E The type of elements in the vector.
	 * @tparam Size The size of the vector.
	 * @extends LinearExpression<Vector, E, enabled>
	 * @brief An arithmetic vector.
	 */
	template <typename E, unsigned int Size, typename enabled = typename std::enable_if_t<std::is_arithmetic<E>::value>>
	class Vector : public LinearExpression<Vector<E, Size, enabled>>
	{
	public:
		/**
		 * @fn constexpr Vector() noexcept
		 * @brief Default constructor.
		 * @throw noexcept
		 */
		constexpr Vector() noexcept;

		/**
		 * @fn constexpr Vector(const E value) noexcept
		 * @param[in] value The value to assign to all the members of the vector.
		 * @brief Build a vector with the same value for all members.
		 * @throw noexcept
		 */
		inline constexpr Vector(const E value) noexcept;

		/**
		 * @fn Vector(const E2 & rhs) noexcept
         * @tparam E2 The type of the linear expression to cast.
		 * @param[in] rhs The vector expression to cast.
		 * @brief Build a vector from a linear expression, forcing its evaluation.
		 * @throw noexcept
		 */
		template <class E2, typename enabledBis = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E2>, E2> && !std::is_same_v<E2, Vector<E, Size, enabled>>>>
		Vector(const E2 & rhs) noexcept;

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
		 * @fn Vector<E, Size, enabled> & operator=(const Vector<E, Size, enabled> & copy) noexcept
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
		 * @fn Vector<E, Size, enabled> & operator=(const LinearExpression<Vector<E, Size, enabled>, E> & rhs) noexcept
		 * @param[in] rhs The vector expression to cast.
		 * @return The vector built.
		 * @brief Build a vector from a vector expression, forcing its evaluation.
		 * @throw noexcept
		 */
		Vector<E, Size, enabled> & operator=(const LinearExpression<Vector<E, Size, enabled>> & rhs) noexcept;

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
         * @fn E cell(const unsigned int index) const
         * @param[in] index The index of the element to access.
         * @return The element wished.
         * @brief Get the element at the index.
         * @throw
         */
		inline E cell(const unsigned int index) const;

        /**
         * @fn E & cell(const unsigned int index)
         * @param[in] index The index of the element to access.
         * @return The element wished.
         * @brief Get the element at the index.
         * @throw
         */
        inline E & cell(const unsigned int index);

        /**
         * @fn Filter<Vector<E, Size, enabled>, Size, enabled> operator[](Vector<bool, Size, enabled> && filter)
         * @param[in] filter The filter to apply.
         * @return The vector filtered.
         * @brief Get a vector filtered according to the filter.
         * @throw
         */
		Filter<Vector<E, Size, enabled>, Size, enabled> operator[](Vector<bool, Size, enabled> && filter);

        /**
         * @fn Filter<Vector<E, Size, enabled>, Size, enabled> operator[](std::initializer_list<unsigned int> && il)
         * @param[in] il The filter to apply.
         * @return The vector filtered.
         * @brief Get a vector filtered according to the filter.
         * @throw
         */
		Filter<Vector<E, Size, enabled>, Size, enabled> operator[](std::initializer_list<unsigned int> && il);

		/**
		 * @fn constexpr unsigned int size() const noexcept
		 * @return The number of element in the expression result.
		 * @brief Get he number of elements.
		 * @throw noexcept
		 */
		inline constexpr unsigned int size() const noexcept;

        /**
         * @fn auto begin() noexcept
         * @return An iterator to the first element of the vector.
         * @brief Get the first element of the vector.
         * @throw noexcept
         */
		inline auto begin() noexcept;

        /**
         * @fn auto end() noexcept
         * @return An iterator to the last element of the vector.
         * @brief Get the last element of the vector.
         * @throw noexcept
         */
		inline auto end() noexcept;

        /**
         * @fn E min() const noexcept
         * @return The smallest element of the vector.
         * @brief Get the smallest element of the vector.
         * @throw noexcept
         */
		inline E min() const noexcept;

        /**
         * @fn E max() const noexcept
         * @return The greatest element of the vector.
         * @brief Get the greatest element of the vector.
         * @throw noexcept
         */
		inline E max() const noexcept;

        /**
         * @fn E sum() const noexcept
         * @return The sum of the elements of the vector.
         * @brief Get a sum of the elements of the vector.
         * @throw noexcept
         */
		inline E sum() const noexcept;

        /**
         * @fn Vector<E, Size, enabled> shift(const int count) const noexcept
         * @param[in] count The size of the shift to apply.
         * @return The vector shifted.
         * @brief Get a shifted vector, filled with 0.
         * @throw noexcept
         */
		inline Vector<E, Size, enabled> shift(const int count) const noexcept;

        /**
         * @fn Vector<E, Size, enabled> cshift(const int count) const noexcept
         * @param[in] count The size of the shift to apply.
         * @return The vector shifted.
         * @brief Get a shifted vector, with circular fill.
         * @throw noexcept
         */
		inline Vector<E, Size, enabled> cshift(const int count) const noexcept;

        /**
         * @fn Vector<E, Size, enabled> apply(E func(E)) const noexcept
         * @param[in] func The function to apply to each element of the vector.
         * @return The vector modified.
         * @brief Apply a function to all elements of the vector.
         * @throw noexcept
         */
		inline Vector<E, Size, enabled> apply(E func(E)) const noexcept;

        /**
         * @fn Vector<E, Size, enabled> apply(E func(const E &)) const noexcept
         * @param[in] func The function to apply to each element of the vector.
         * @return The vector modified.
         * @brief Apply a function to all elements of the vector.
         * @throw noexcept
         */
		inline Vector<E, Size, enabled> apply(E func(const E &)) const noexcept;

        /**
         * @fn auto magnitude() const
         * @return The magnitude of the vector.
         * @brief Get the magnitude of the vector, also called norm 2.
         * @throw
         */
		inline auto magnitude() const;

        /**
         * @fn auto distanceFrom(const E2 & rhs) const
         * @tparam E2 The type of the right-hand side.
         * @param[in] rhs The right-hand side to compute the distance from.
         * @return The distance between the two vectors, considered as points in the dimensional space.
         * @brief Get the distance between two points.
         * @throw
         */
		template <class E2, typename enabledBis = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E2>, E2>>>
		inline auto distanceFrom(const E2 & rhs) const;

        /**
         * @fn LinearOperation<Vector<E, Size, enabled>, Vector<E, Size, enabled>, std::divides<>> normalize() const
         * @return The linear operation of normalization.
         * @brief Get the linear operation of normalization of the vector.
         * @throw
         */
		LinearOperation<Vector<E, Size, enabled>, Vector<E, Size, enabled>, std::divides<>> normalize() const;

        /**
         * @fn Vector<E, Size, enabled> cross(const E2 & rhs) const
         * @tparam E2 The type of the right-hand side.
         * @param[in] rhs The right hand side of the cross product.
         * @return The result of the cross product of the two vectors.
         * @brief Compute the cross product of two vectors.
         * @throw
         */
		template <class E2, typename enabledBis = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E2>, E2> && Size == 3>>
		Vector<E, Size, enabled> cross(const E2 & rhs) const;

        /**
         * @fn auto dot(const E2 & rhs) const
         * @tparam E2 The type of the right-hand side.
         * @param[in] rhs The right-hand side of the dot product.
         * @return The result of the dot product of the two vectors.
         * @brief Compute the dot product of the two vectors.
         * @throw
         */
		template <class E2, typename enabledBis = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E2>, E2>>>
		auto dot(const E2 & rhs) const;

	protected:
        /**
         * @property _elements
         * @brief The list of elements of the vector.
         */
		std::array<E, Size> _elements;
	};

    /**
     * @fn LinearUnaryOperation<E, unary_plus<>> operator+(const E & lhs)
     * @tparam E The type of linear expression concerned by the operation.
     * @param[in] lhs The linear expression to apply the unary operation to.
     * @return The linear unary plus operation.
     * @brief Apply the unary plus operation on a linear expression.
     */
	template <class E, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E>, E>>>
	LinearUnaryOperation<E, unary_plus<>> operator+(const E & lhs);

    /**
     * @fn LinearUnaryOperation<E, std::negate<>> operator-(const E & lhs)
     * @tparam E The type of linear expression concerned by the operation.
     * @param[in] lhs The linear expression to apply the unary operation to.
     * @return The linear unary negate operation.
     * @brief Apply the unary negate operation on a linear expression.
     */
	template <class E, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E>, E>>>
	LinearUnaryOperation<E, std::negate<>> operator-(const E & lhs);

    /**
     * @fn LinearUnaryOperation<E, std::bit_not<>> operator~(const E & lhs)
     * @tparam E The type of linear expression concerned by the operation.
     * @param[in] lhs The linear expression to apply the unary operation to.
     * @return The linear unary bit not operation.
     * @brief Apply the unary bit not operation on a linear expression.
     */
	template <class E, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E>, E>>>
	LinearUnaryOperation<E, std::bit_not<>> operator~(const E & lhs);

    /**
     * @fn LinearUnaryOperation<E, std::logical_not<>> operator!(const E & lhs)
     * @tparam E The type of linear expression concerned by the operation.
     * @param[in] lhs The linear expression to apply the unary operation to.
     * @return The linear logical not operation.
     * @brief Apply the logical not operation on a linear expression.
     */
	template <class E, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E>, E>>>
	LinearUnaryOperation<E, std::logical_not<>> operator!(const E & lhs);

    /**
     * @fn E1 & operator+=(E1 & lhs, const E2 & rhs)
     * @tparam E1 The type of the left-hand side linear expression concerned by the operation.
     * @tparam E2 The type of the right-hand side linear expression concerned by the operation.
     * @param[in] lhs The left-hand side linear expression to apply the unary operation to.
     * @param[in] rhs The right-hand side linear expression to apply the unary operation to.
     * @return The left-hand side modified.
     * @brief Apply the addition of the two elements into the left-hand side.
     */
	template <class E1, class E2, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E1>, E1>>>
	E1 & operator+=(E1 & lhs, const E2 & rhs);

    /**
     * @fn E1 & operator-=(E1 & lhs, const E2 & rhs);
     * @tparam E1 The type of the left-hand side linear expression concerned by the operation.
     * @tparam E2 The type of the right-hand side linear expression concerned by the operation.
     * @param[in] lhs The left-hand side linear expression to apply the unary operation to.
     * @param[in] rhs The right-hand side linear expression to apply the unary operation to.
     * @return The left-hand side modified.
     * @brief Apply the subtraction of the two elements into the left-hand side.
     */
	template <class E1, class E2, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E1>, E1>>>
	E1 & operator-=(E1 & lhs, const E2 & rhs);

    /**
     * @fn E1 & operator*=(E1 & lhs, const E2 & rhs)
     * @tparam E1 The type of the left-hand side linear expression concerned by the operation.
     * @tparam E2 The type of the right-hand side linear expression concerned by the operation.
     * @param[in] lhs The left-hand side linear expression to apply the unary operation to.
     * @param[in] rhs The right-hand side linear expression to apply the unary operation to.
     * @return The left-hand side modified.
     * @brief Apply the multiplication of the two elements, member-to-member into the left-hand side.
     */
	template <class E1, class E2, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E1>, E1> && std::is_arithmetic_v<E2>>>
	E1 & operator*=(E1 & lhs, const E2 & rhs);

    /**
     * @fn E1 & operator/=(E1 & lhs, const E2 & rhs)
     * @tparam E1 The type of the left-hand side linear expression concerned by the operation.
     * @tparam E2 The type of the right-hand side linear expression concerned by the operation.
     * @param[in] lhs The left-hand side linear expression to apply the unary operation to.
     * @param[in] rhs The right-hand side linear expression to apply the unary operation to.
     * @return The left-hand side modified.
     * @brief Apply the division of the two elements, member-to-member into the left-hand side.
     */
	template <class E1, class E2, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E1>, E1> && std::is_arithmetic_v<E2>>>
	E1 & operator/=(E1 & lhs, const E2 & rhs);

    /**
     * @fn E1 & operator%=(E1 & lhs, const E2 & rhs)
     * @tparam E1 The type of the left-hand side linear expression concerned by the operation.
     * @tparam E2 The type of the right-hand side linear expression concerned by the operation.
     * @param[in] lhs The left-hand side linear expression to apply the unary operation to.
     * @param[in] rhs The right-hand side linear expression to apply the unary operation to.
     * @return The left-hand side modified.
     * @brief Apply the modulo of the two elements, member-to-member into the left-hand side.
     */
	template <class E1, class E2, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E1>, E1> && std::is_integral_v<E2>>>
	E1 & operator%=(E1 & lhs, const E2 & rhs);

    /**
     * @fn E1 & operator&=(E1 & lhs, const E2 & rhs)
     * @tparam E1 The type of the left-hand side linear expression concerned by the operation.
     * @tparam E2 The type of the right-hand side linear expression concerned by the operation.
     * @param[in] lhs The left-hand side linear expression to apply the unary operation to.
     * @param[in] rhs The right-hand side linear expression to apply the unary operation to.
     * @return The left-hand side modified.
     * @brief Apply the bit-and of the two elements, member-to-member into the left-hand side.
     */
	template <class E1, class E2, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E1>, E1> && std::is_integral_v<E2>>>
	E1 & operator&=(E1 & lhs, const E2 & rhs);

    /**
     * @fn E1 & operator|=(E1 & lhs, const E2 & rhs)
     * @tparam E1 The type of the left-hand side linear expression concerned by the operation.
     * @tparam E2 The type of the right-hand side linear expression concerned by the operation.
     * @param[in] lhs The left-hand side linear expression to apply the unary operation to.
     * @param[in] rhs The right-hand side linear expression to apply the unary operation to.
     * @return The left-hand side modified.
     * @brief Apply the bit-or of the two elements, member-to-member into the left-hand side.
     */
	template <class E1, class E2, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E1>, E1> && std::is_integral_v<E2>>>
	E1 & operator|=(E1 & lhs, const E2 & rhs);

    /**
     * @fn E1 & operator^=(E1 & lhs, const E2 & rhs)
     * @tparam E1 The type of the left-hand side linear expression concerned by the operation.
     * @tparam E2 The type of the right-hand side linear expression concerned by the operation.
     * @param[in] lhs The left-hand side linear expression to apply the unary operation to.
     * @param[in] rhs The right-hand side linear expression to apply the unary operation to.
     * @return The left-hand side modified.
     * @brief Apply the bit-xor of the two elements, member-to-member into the left-hand side.
     */
	template <class E1, class E2, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E1>, E1> && std::is_integral_v<E2>>>
	E1 & operator^=(E1 & lhs, const E2 & rhs);

    /**
     * @fn E1 & operator<<=(E1 & lhs, const E2 & rhs)
     * @tparam E1 The type of the left-hand side linear expression concerned by the operation.
     * @tparam E2 The type of the right-hand side linear expression concerned by the operation.
     * @param[in] lhs The left-hand side linear expression to apply the unary operation to.
     * @param[in] rhs The right-hand side linear expression to apply the unary operation to.
     * @return The left-hand side modified.
     * @brief Apply the biwise left shift of the two elements, member-to-member into the left-hand side.
     */
	template <class E1, class E2, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E1>, E1> && std::is_integral_v<E2>>>
	E1 & operator<<=(E1 & lhs, const E2 & rhs);

    /**
     * @fn E1 & operator>>=(E1 & lhs, const E2 & rhs)
     * @tparam E1 The type of the left-hand side linear expression concerned by the operation.
     * @tparam E2 The type of the right-hand side linear expression concerned by the operation.
     * @param[in] lhs The left-hand side linear expression to apply the unary operation to.
     * @param[in] rhs The right-hand side linear expression to apply the unary operation to.
     * @return The left-hand side modified.
     * @brief Apply the biwise right shift of the two elements, member-to-member into the left-hand side.
     */
	template <class E1, class E2, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E1>, E1> && std::is_integral_v<E2>>>
	E1 & operator>>=(E1 & lhs, const E2 & rhs);

    /**
     * @fn LinearOperation<E1, E2, std::plus<>> operator+(const E1 & lhs, const E2 & rhs)
     * @tparam E1 The type of the left-hand side linear expression concerned by the operation.
     * @tparam E2 The type of the right-hand side linear expression concerned by the operation.
     * @param[in] lhs The left-hand side linear expression to apply the unary operation to.
     * @param[in] rhs The right-hand side linear expression to apply the unary operation to.
     * @return The linear operation on the two linear expressions.
     * @brief Create the linear expression of the sum of the two factors.
     */
	template <class E1, class E2, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E1>, E1> || std::is_base_of_v<LinearExpression<E2>, E2>>>
	LinearOperation<E1, E2, std::plus<>> operator+(const E1 & lhs, const E2 & rhs);

    /**
     * @fn LinearOperation<E1, E2, std::minus<>> operator-(const E1 & lhs, const E2 & rhs)
     * @tparam E1 The type of the left-hand side linear expression concerned by the operation.
     * @tparam E2 The type of the right-hand side linear expression concerned by the operation.
     * @param[in] lhs The left-hand side linear expression to apply the unary operation to.
     * @param[in] rhs The right-hand side linear expression to apply the unary operation to.
     * @return The linear operation on the two linear expressions.
     * @brief Create the linear expression of the subtraction of the two factors.
     */
	template <class E1, class E2, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E1>, E1> || std::is_base_of_v<LinearExpression<E2>, E2>>>
	LinearOperation<E1, E2, std::minus<>> operator-(const E1 & lhs, const E2 & rhs);

    /**
     * @fn LinearOperation<E1, E2, std::multiplies<>> operator*(const E1 & lhs, const E2 & rhs)
     * @tparam E1 The type of the left-hand side linear expression concerned by the operation.
     * @tparam E2 The type of the right-hand side linear expression concerned by the operation.
     * @param[in] lhs The left-hand side linear expression to apply the unary operation to.
     * @param[in] rhs The right-hand side linear expression to apply the unary operation to.
     * @return The linear operation on the two linear expressions.
     * @brief Create the linear expression of the multiplication of the two factors.
     */
	template <class E1, class E2, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E1>, E1> || std::is_base_of_v<LinearExpression<E2>, E2>>>
	LinearOperation<E1, E2, std::multiplies<>> operator*(const E1 & lhs, const E2 & rhs);

    /**
     * @fn LinearOperation<E1, E2, std::divides<>> operator/(const E1 & lhs, const E2 & rhs)
     * @tparam E1 The type of the left-hand side linear expression concerned by the operation.
     * @tparam E2 The type of the right-hand side linear expression concerned by the operation.
     * @param[in] lhs The left-hand side linear expression to apply the unary operation to.
     * @param[in] rhs The right-hand side linear expression to apply the unary operation to.
     * @return The linear operation on the two linear expressions.
     * @brief Create the linear expression of the division of the two factors.
     */
	template <class E1, class E2, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E1>, E1> || std::is_base_of_v<LinearExpression<E2>, E2>>>
	LinearOperation<E1, E2, std::divides<>> operator/(const E1 & lhs, const E2 & rhs);

    /**
     * @fn LinearOperation<E1, E2, std::modulus<>> operator%(const E1 & lhs, const E2 & rhs)
     * @tparam E1 The type of the left-hand side linear expression concerned by the operation.
     * @tparam E2 The type of the right-hand side linear expression concerned by the operation.
     * @param[in] lhs The left-hand side linear expression to apply the unary operation to.
     * @param[in] rhs The right-hand side linear expression to apply the unary operation to.
     * @return The linear operation on the two linear expressions.
     * @brief Create the linear expression of the modulo of the two factors.
     */
	template <class E1, class E2, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E1>, E1> || std::is_base_of_v<LinearExpression<E2>, E2>>>
	LinearOperation<E1, E2, std::modulus<>> operator%(const E1 & lhs, const E2 & rhs);

    /**
     * @fn LinearOperation<E1, E2, std::bit_and<>> operator&(const E1 & lhs, const E2 & rhs)
     * @tparam E1 The type of the left-hand side linear expression concerned by the operation.
     * @tparam E2 The type of the right-hand side linear expression concerned by the operation.
     * @param[in] lhs The left-hand side linear expression to apply the unary operation to.
     * @param[in] rhs The right-hand side linear expression to apply the unary operation to.
     * @return The linear operation on the two linear expressions.
     * @brief Create the linear expression of the bit-and of the two factors.
     */
	template <class E1, class E2, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E1>, E1> || std::is_base_of_v<LinearExpression<E2>, E2>>>
	LinearOperation<E1, E2, std::bit_and<>> operator&(const E1 & lhs, const E2 & rhs);

    /**
     * @fn LinearOperation<E1, E2, std::bit_or<>> operator|(const E1 & lhs, const E2 & rhs)
     * @tparam E1 The type of the left-hand side linear expression concerned by the operation.
     * @tparam E2 The type of the right-hand side linear expression concerned by the operation.
     * @param[in] lhs The left-hand side linear expression to apply the unary operation to.
     * @param[in] rhs The right-hand side linear expression to apply the unary operation to.
     * @return The linear operation on the two linear expressions.
     * @brief Create the linear expression of the bit-or of the two factors.
     */
	template <class E1, class E2, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E1>, E1> || std::is_base_of_v<LinearExpression<E2>, E2>>>
	LinearOperation<E1, E2, std::bit_or<>> operator|(const E1 & lhs, const E2 & rhs);

    /**
     * @fn LinearOperation<E1, E2, std::bit_nor<>> operator^(const E1 & lhs, const E2 & rhs)
     * @tparam E1 The type of the left-hand side linear expression concerned by the operation.
     * @tparam E2 The type of the right-hand side linear expression concerned by the operation.
     * @param[in] lhs The left-hand side linear expression to apply the unary operation to.
     * @param[in] rhs The right-hand side linear expression to apply the unary operation to.
     * @return The linear operation on the two linear expressions.
     * @brief Create the linear expression of the bit-nor of the two factors.
     */
	template <class E1, class E2, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E1>, E1> || std::is_base_of_v<LinearExpression<E2>, E2>>>
	LinearOperation<E1, E2, std::bit_xor<>> operator^(const E1 & lhs, const E2 & rhs);

    /**
     * @fn LinearOperation<E1, E2, bitwise_left_shift<>> operator<<(const E1 & lhs, const E2 & rhs)
     * @tparam E1 The type of the left-hand side linear expression concerned by the operation.
     * @tparam E2 The type of the right-hand side linear expression concerned by the operation.
     * @param[in] lhs The left-hand side linear expression to apply the unary operation to.
     * @param[in] rhs The right-hand side linear expression to apply the unary operation to.
     * @return The linear operation on the two linear expressions.
     * @brief Create the linear expression of the bitwise left shift of the two factors.
     */
	template <class E1, class E2, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E1>, E1> || std::is_base_of_v<LinearExpression<E2>, E2>>>
	LinearOperation<E1, E2, bitwise_left_shift<>> operator<<(const E1 & lhs, const E2 & rhs);

    /**
     * @fn LinearOperation<E1, E2, bitwise_right_shift<>> operator>>(const E1 & lhs, const E2 & rhs)
     * @tparam E1 The type of the left-hand side linear expression concerned by the operation.
     * @tparam E2 The type of the right-hand side linear expression concerned by the operation.
     * @param[in] lhs The left-hand side linear expression to apply the unary operation to.
     * @param[in] rhs The right-hand side linear expression to apply the unary operation to.
     * @return The linear operation on the two linear expressions.
     * @brief Create the linear expression of the bitwise right shift of the two factors.
     */
	template <class E1, class E2, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E1>, E1> || std::is_base_of_v<LinearExpression<E2>, E2>>>
	LinearOperation<E1, E2, bitwise_right_shift<>> operator<<(const E1 & lhs, const E2 & rhs);

    /**
     * @fn LinearOperation<E1, E2, std::logical_and<>> operator&&(const E1 & lhs, const E2 & rhs)
     * @tparam E1 The type of the left-hand side linear expression concerned by the operation.
     * @tparam E2 The type of the right-hand side linear expression concerned by the operation.
     * @param[in] lhs The left-hand side linear expression to apply the unary operation to.
     * @param[in] rhs The right-hand side linear expression to apply the unary operation to.
     * @return The linear operation on the two linear expressions.
     * @brief Create the linear expression of the logical-and of the two factors.
     */
	template <class E1, class E2, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E1>, E1> || std::is_base_of_v<LinearExpression<E2>, E2>>>
	LinearOperation<E1, E2, std::logical_and<>> operator&&(const E1 & lhs, const E2 & rhs);

    /**
     * @fn LinearOperation<E1, E2, std::logical_or<>> operator||(const E1 & lhs, const E2 & rhs)
     * @tparam E1 The type of the left-hand side linear expression concerned by the operation.
     * @tparam E2 The type of the right-hand side linear expression concerned by the operation.
     * @param[in] lhs The left-hand side linear expression to apply the unary operation to.
     * @param[in] rhs The right-hand side linear expression to apply the unary operation to.
     * @return The linear operation on the two linear expressions.
     * @brief Create the linear expression of the logical-or of the two factors.
     */
	template <class E1, class E2, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E1>, E1> || std::is_base_of_v<LinearExpression<E2>, E2>>>
	LinearOperation<E1, E2, std::logical_or<>> operator||(const E1 & lhs, const E2 & rhs);

    /**
     * @fn bool operator==(const E1 & lhs, const E2 & rhs)
     * @tparam E1 The type of the left-hand side linear expression concerned by the operation.
     * @tparam E2 The type of the right-hand side linear expression concerned by the operation.
     * @param[in] lhs The left-hand side linear expression to apply the unary operation to.
     * @param[in] rhs The right-hand side linear expression to apply the unary operation to.
     * @return True, if both are equal member-to-member, else false.
     * @brief Check if two linear expression are equal or not.
     */
	template <class E1, class E2, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E1>, E1> || std::is_base_of_v<LinearExpression<E2>, E2>>>
	bool operator==(const E1 & lhs, const E2 & rhs);

    /**
     * @fn bool operator!=(const E1 & lhs, const E2 & rhs)
     * @tparam E1 The type of the left-hand side linear expression concerned by the operation.
     * @tparam E2 The type of the right-hand side linear expression concerned by the operation.
     * @param[in] lhs The left-hand side linear expression to apply the unary operation to.
     * @param[in] rhs The right-hand side linear expression to apply the unary operation to.
     * @return True, if both are different member-to-member, else false.
     * @brief Check if two linear expression are different or not.
     */
	template <class E1, class E2, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E1>, E1> || std::is_base_of_v<LinearExpression<E2>, E2>>>
	bool operator!=(const E1 & lhs, const E2 & rhs);

    /**
     * @fn LinearOperation<E1, E2, std::greater<>> operator>(const E1 & lhs, const E2 & rhs)
     * @tparam E1 The type of the left-hand side linear expression concerned by the operation.
     * @tparam E2 The type of the right-hand side linear expression concerned by the operation.
     * @param[in] lhs The left-hand side linear expression to apply the unary operation to.
     * @param[in] rhs The right-hand side linear expression to apply the unary operation to.
     * @return The linear operation on the two linear expressions.
     * @brief Create the linear expression of the logical-greater of the two factors.
     */
	template <class E1, class E2, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E1>, E1> || std::is_base_of_v<LinearExpression<E2>, E2>>>
	LinearOperation<E1, E2, std::greater<>> operator>(const E1 & lhs, const E2 & rhs);

    /**
     * @fn LinearOperation<E1, E2, std::less<>> operator<(const E1 & lhs, const E2 & rhs)
     * @tparam E1 The type of the left-hand side linear expression concerned by the operation.
     * @tparam E2 The type of the right-hand side linear expression concerned by the operation.
     * @param[in] lhs The left-hand side linear expression to apply the unary operation to.
     * @param[in] rhs The right-hand side linear expression to apply the unary operation to.
     * @return The linear operation on the two linear expressions.
     * @brief Create the linear expression of the logical-less of the two factors.
     */
	template <class E1, class E2, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E1>, E1> || std::is_base_of_v<LinearExpression<E2>, E2>>>
	LinearOperation<E1, E2, std::less<>> operator<(const E1 & lhs, const E2 & rhs);

    /**
     * @fn LinearOperation<E1, E2, std::greater_equal<>> operator>=(const E1 & lhs, const E2 & rhs)
     * @tparam E1 The type of the left-hand side linear expression concerned by the operation.
     * @tparam E2 The type of the right-hand side linear expression concerned by the operation.
     * @param[in] lhs The left-hand side linear expression to apply the unary operation to.
     * @param[in] rhs The right-hand side linear expression to apply the unary operation to.
     * @return The linear operation on the two linear expressions.
     * @brief Create the linear expression of the logical-greater-or-equal of the two factors.
     */
	template <class E1, class E2, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E1>, E1> || std::is_base_of_v<LinearExpression<E2>, E2>>>
	LinearOperation<E1, E2, std::greater_equal<>> operator>=(const E1 & lhs, const E2 & rhs);

    /**
     * @fn LinearOperation<E1, E2, std::less_equal<>> operator<=(const E1 & lhs, const E2 & rhs)
     * @tparam E1 The type of the left-hand side linear expression concerned by the operation.
     * @tparam E2 The type of the right-hand side linear expression concerned by the operation.
     * @param[in] lhs The left-hand side linear expression to apply the unary operation to.
     * @param[in] rhs The right-hand side linear expression to apply the unary operation to.
     * @return The linear operation on the two linear expressions.
     * @brief Create the linear expression of the logical-less-or-equal of the two factors.
     */
	template <class E1, class E2, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E1>, E1> || std::is_base_of_v<LinearExpression<E2>, E2>>>
	LinearOperation<E1, E2, std::less_equal<>> operator<=(const E1 & lhs, const E2 & rhs);

    /**
     * @fn LinearUnaryOperation<E, absolute<>> abs(const E & lhs)
     * @tparam E The type of the left-hand side linear expression concerned by the operation.
     * @param[in] lhs The left-hand side linear expression to apply the unary operation to.
     * @return The linear absolute operation.
     * @brief Apply the absolute operation on the linear expression.
     */
	template <class E, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E>, E>>>
	LinearUnaryOperation<E, absolute<>> abs(const E & lhs);

    /**
     * @fn LinearUnaryOperation<E, exponential<>> exp(const E & lhs)
     * @tparam E The type of the left-hand side linear expression concerned by the operation.
     * @param[in] lhs The left-hand side linear expression to apply the unary operation to.
     * @return The linear exponential operation.
     * @brief Apply the exponential operation on the linear expression.
     */
	template <class E, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E>, E>>>
	LinearUnaryOperation<E, exponential<>> exp(const E & lhs);

    /**
     * @fn LinearUnaryOperation<E, logarithm<>> log(const E & lhs)
     * @tparam E The type of the left-hand side linear expression concerned by the operation.
     * @param[in] lhs The left-hand side linear expression to apply the unary operation to.
     * @return The linear logarithm operation.
     * @brief Apply the logarithm operation on the linear expression.
     */
	template <class E, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E>, E>>>
	LinearUnaryOperation<E, logarithm<>> log(const E & lhs);

    /**
     * @fn LinearUnaryOperation<E, logarithm10<>> log10(const E & lhs)
     * @tparam E The type of the left-hand side linear expression concerned by the operation.
     * @param[in] lhs The left-hand side linear expression to apply the unary operation to.
     * @return The linear logarithm 10 operation.
     * @brief Apply the logarithm 10 operation on the linear expression.
     */
	template <class E, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E>, E>>>
	LinearUnaryOperation<E, logarithm10<>> log10(const E & lhs);

    /**
     * @fn LinearOperation<E1, E2, power<>> pow(const E1 & lhs, const E2 & rhs)
     * @tparam E1 The type of the left-hand side linear expression concerned by the operation.
     * @tparam E2 The type of the right-hand side linear expression concerned by the operation.
     * @param[in] lhs The left-hand side linear expression to apply the unary operation to.
     * @param[in] rhs The right-hand side linear expression to apply the unary operation to.
     * @return The linear power operation.
     * @brief Apply the power operation on the linear expression.
     */
	template <class E1, class E2, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E1>, E1>>>
	LinearOperation<E1, E2, power<>> pow(const E1 & lhs, const E2 & rhs);

    /**
     * @fn LinearUnaryOperation<E, square_root<>> sqrt(const E & lhs)
     * @tparam E The type of the left-hand side linear expression concerned by the operation.
     * @param[in] lhs The left-hand side linear expression to apply the unary operation to.
     * @return The linear square root operation.
     * @brief Apply the square root operation on the linear expression.
     */
	template <class E, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E>, E>>>
	LinearUnaryOperation<E, square_root<>> sqrt(const E & lhs);

    /**
     * @fn LinearUnaryOperation<E, sinus<>> sin(const E & lhs)
     * @tparam E The type of the left-hand side linear expression concerned by the operation.
     * @param[in] lhs The left-hand side linear expression to apply the unary operation to.
     * @return The linear sinus operation.
     * @brief Apply the sinus operation on the linear expression.
     */
	template <class E, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E>, E>>>
	LinearUnaryOperation<E, sinus<>> sin(const E & lhs);

    /**
     * @fn LinearUnaryOperation<E, cosinus<>> cos(const E & lhs)
     * @tparam E The type of the left-hand side linear expression concerned by the operation.
     * @param[in] lhs The left-hand side linear expression to apply the unary operation to.
     * @return The linear cosinus operation.
     * @brief Apply the cosinus operation on the linear expression.
     */
	template <class E, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E>, E>>>
	LinearUnaryOperation<E, cosinus<>> cos(const E & lhs);

    /**
     * @fn LinearUnaryOperation<E, tangent<>> tan(const E & lhs)
     * @tparam E The type of the left-hand side linear expression concerned by the operation.
     * @param[in] lhs The left-hand side linear expression to apply the unary operation to.
     * @return The linear tangent operation.
     * @brief Apply the tangent operation on the linear expression.
     */
	template <class E, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E>, E>>>
	LinearUnaryOperation<E, tangent<>> tan(const E & lhs);

    /**
     * @fn LinearUnaryOperation<E, arcsinus<>> asin(const E & lhs)
     * @tparam E The type of the left-hand side linear expression concerned by the operation.
     * @param[in] lhs The left-hand side linear expression to apply the unary operation to.
     * @return The linear arcsinus operation.
     * @brief Apply the arcsinus operation on the linear expression.
     */
	template <class E, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E>, E>>>
	LinearUnaryOperation<E, arcsinus<>> asin(const E & lhs);

    /**
     * @fn LinearUnaryOperation<E, arccosinus<>> acos(const E & lhs)
     * @tparam E The type of the left-hand side linear expression concerned by the operation.
     * @param[in] lhs The left-hand side linear expression to apply the unary operation to.
     * @return The linear arccosinus operation.
     * @brief Apply the arccosinus operation on the linear expression.
     */
	template <class E, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E>, E>>>
	LinearUnaryOperation<E, arccosinus<>> acos(const E & lhs);

    /**
     * @fn LinearUnaryOperation<E, arctangent<>> atan(const E & lhs)
     * @tparam E The type of the left-hand side linear expression concerned by the operation.
     * @param[in] lhs The left-hand side linear expression to apply the unary operation to.
     * @return The linear arctangent operation.
     * @brief Apply the arctangent operation on the linear expression.
     */
	template <class E, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E>, E>>>
	LinearUnaryOperation<E, arctangent<>> atan(const E & lhs);

    /**
     * @fn LinearUnaryOperation<E, arctangent<>> atan(const E & lhs)
     * @tparam E1 The type of the left-hand side linear expression concerned by the operation.
     * @tparam E2 The type of the right-hand side linear expression concerned by the operation.
     * @param[in] lhs The left-hand side linear expression to apply the unary operation to.
     * @param[in] rhs The right-hand side linear expression to apply the unary operation to.
     * @return The linear arctangent 2 operation.
     * @brief Apply the arctangent 2 operation on the linear expression.
     */
	template <class E1, class E2, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E1>, E1>>>
	LinearOperation<E1, E2, arctangent2<>> atan2(const E1 & lhs, const E2 & rhs);

    /**
     * @fn LinearUnaryOperation<E, sinus_hyperbolic<>> sinh(const E & lhs)
     * @tparam E The type of the left-hand side linear expression concerned by the operation.
     * @param[in] lhs The left-hand side linear expression to apply the unary operation to.
     * @return The linear sinus hyperbolic operation.
     * @brief Apply the sinus hyperbolic operation on the linear expression.
     */
	template <class E, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E>, E>>>
	LinearUnaryOperation<E, sinus_hyperbolic<>> sinh(const E & lhs);

    /**
     * @fn LinearUnaryOperation<E, cosinus_hyperbolic<>> cosh(const E & lhs)
     * @tparam E The type of the left-hand side linear expression concerned by the operation.
     * @param[in] lhs The left-hand side linear expression to apply the unary operation to.
     * @return The linear cosinus hyperbolic operation.
     * @brief Apply the cosinus hyperbolic operation on the linear expression.
     */
	template <class E, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E>, E>>>
	LinearUnaryOperation<E, cosinus_hyperbolic<>> cosh(const E & lhs);

    /**
     * @fn LinearUnaryOperation<E, tangent_hyperbolic<>> tanh(const E & lhs)
     * @tparam E The type of the left-hand side linear expression concerned by the operation.
     * @param[in] lhs The left-hand side linear expression to apply the unary operation to.
     * @return The linear tangent hyperbolic operation.
     * @brief Apply the tangent hyperbolic operation on the linear expression.
     */
	template <class E, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E>, E>>>
	LinearUnaryOperation<E, tangent_hyperbolic<>> tanh(const E & lhs);

    /**
     * @fn LinearUnaryOperation<E, arcsinus_hyperbolic<>> asinh(const E & lhs)
     * @tparam E The type of the left-hand side linear expression concerned by the operation.
     * @param[in] lhs The left-hand side linear expression to apply the unary operation to.
     * @return The linear arcsinus hyperbolic operation.
     * @brief Apply the arcsinus hyperbolic operation on the linear expression.
     */
	template <class E, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E>, E>>>
	LinearUnaryOperation<E, arcsinus_hyperbolic<>> asinh(const E & lhs);

    /**
     * @fn LinearUnaryOperation<E, arccosinus_hyperbolic<>> acosh(const E & lhs)
     * @tparam E The type of the left-hand side linear expression concerned by the operation.
     * @param[in] lhs The left-hand side linear expression to apply the unary operation to.
     * @return The linear arccosinus hyperbolic operation.
     * @brief Apply the arccosinus hyperbolic operation on the linear expression.
     */
	template <class E, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E>, E>>>
	LinearUnaryOperation<E, arccosinus_hyperbolic<>> acosh(const E & lhs);

    /**
     * @fn LinearUnaryOperation<E, arctangent_hyperbolic<>> atanh(const E & lhs)
     * @tparam E The type of the left-hand side linear expression concerned by the operation.
     * @param[in] lhs The left-hand side linear expression to apply the unary operation to.
     * @return The linear arctangent hyperbolic operation.
     * @brief Apply the arctangent hyperbolic operation on the linear expression.
     */
	template <class E, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E>, E>>>
	LinearUnaryOperation<E, arctangent_hyperbolic<>> atanh(const E & lhs);
}

#include "utility/template_expression/vector.inl"

#endif // NEW_VECTOR_HPP
