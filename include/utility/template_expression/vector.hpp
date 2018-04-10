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
	 * @extends LinearExpression<Vector, E>
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
		 * @fn Vector(const LinearExpression<Vector<E, Size, enabled>, E> & rhs) noexcept
		 * @param[in] The vector expression to cast.
		 * @brief Build a vector from a vector expression, forcing its evaluation.
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

		inline E cell(const unsigned int index) const;

		Filter<Vector<E, Size, enabled>, Size, enabled> operator[](Vector<bool, Size, enabled> && filter);

		Filter<Vector<E, Size, enabled>, Size, enabled> operator[](std::initializer_list<unsigned int> && il);

		/**
		* @fn constexpr unsigned int size() const noexcept
		* @return The number of element in the expression result.
		* @brief Get he number of elements.
		* @throw noexcept
		*/
		inline constexpr unsigned int size() const noexcept;

		inline auto begin() noexcept;
		inline auto end() noexcept;

		inline E min() const noexcept;

		inline E max() const noexcept;

		inline E sum() const noexcept;

		inline Vector<E, Size, enabled> shift(const int count) const noexcept;
		
		inline Vector<E, Size, enabled> cshift(const int count) const noexcept;

		inline Vector<E, Size, enabled> apply(E func(E)) const noexcept;

		inline Vector<E, Size, enabled> apply(E func(const E &)) const noexcept;

		inline auto magnitude() const;

		template <class E2, typename enabledBis = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E2>, E2>>>
		inline auto distanceFrom(const E2 & rhs) const;

		LinearOperation<Vector<E, Size, enabled>, Vector<E, Size, enabled>, std::divides<>> normalize() const;

		template <class E2, typename enabledBis = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E2>, E2>>>
		Vector<E, Size, enabled> cross(const E2 & rhs) const;

		template <class E2, typename enabledBis = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E2>, E2>>>
		auto dot(const E2 & rhs) const;

	protected:
		std::array<E, Size> _elements;
	};

	template <class E, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E>, E>>>
	LinearUnaryOperation<E, unary_plus<>> operator+(const E & lhs);

	template <class E, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E>, E>>>
	LinearUnaryOperation<E, std::negate<>> operator-(const E & lhs);

	template <class E, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E>, E>>>
	LinearUnaryOperation<E, std::bit_not<>> operator~(const E & lhs);

	template <class E, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E>, E>>>
	LinearUnaryOperation<E, std::logical_not<>> operator!(const E & lhs);

	template <class E1, class E2, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E1>, E1>>>
	E1 & operator+=(E1 & lhs, const E2 & rhs);

	template <class E1, class E2, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E1>, E1>>>
	E1 & operator-=(E1 & lhs, const E2 & rhs);

	template <class E1, class E2, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E1>, E1> && std::is_arithmetic_v<E2>>>
	E1 & operator*=(E1 & lhs, const E2 & rhs);

	template <class E1, class E2, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E1>, E1> && std::is_arithmetic_v<E2>>>
	E1 & operator/=(E1 & lhs, const E2 & rhs);

	template <class E1, class E2, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E1>, E1> && std::is_integral_v<E2>>>
	E1 & operator%=(E1 & lhs, const E2 & rhs);

	template <class E1, class E2, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E1>, E1> && std::is_integral_v<E2>>>
	E1 & operator&=(E1 & lhs, const E2 & rhs);

	template <class E1, class E2, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E1>, E1> && std::is_integral_v<E2>>>
	E1 & operator|=(E1 & lhs, const E2 & rhs);

	template <class E1, class E2, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E1>, E1> && std::is_integral_v<E2>>>
	E1 & operator^=(E1 & lhs, const E2 & rhs);

	template <class E1, class E2, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E1>, E1> && std::is_integral_v<E2>>>
	E1 & operator<<=(E1 & lhs, const E2 & rhs);

	template <class E1, class E2, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E1>, E1> && std::is_integral_v<E2>>>
	E1 & operator>>=(E1 & lhs, const E2 & rhs);

	template <class E1, class E2, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E1>, E1> || std::is_base_of_v<LinearExpression<E2>, E2>>>
	LinearOperation<E1, E2, std::plus<>> operator+(const E1 & lhs, const E2 & rhs);

	template <class E1, class E2, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E1>, E1> || std::is_base_of_v<LinearExpression<E2>, E2>>>
	LinearOperation<E1, E2, std::minus<>> operator-(const E1 & lhs, const E2 & rhs);

	template <class E1, class E2, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E1>, E1> || std::is_base_of_v<LinearExpression<E2>, E2>>>
	LinearOperation<E1, E2, std::multiplies<>> operator*(const E1 & lhs, const E2 & rhs);

	template <class E1, class E2, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E1>, E1> || std::is_base_of_v<LinearExpression<E2>, E2>>>
	LinearOperation<E1, E2, std::divides<>> operator/(const E1 & lhs, const E2 & rhs);

	template <class E1, class E2, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E1>, E1> || std::is_base_of_v<LinearExpression<E2>, E2>>>
	LinearOperation<E1, E2, std::modulus<>> operator%(const E1 & lhs, const E2 & rhs);

	template <class E1, class E2, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E1>, E1> || std::is_base_of_v<LinearExpression<E2>, E2>>>
	LinearOperation<E1, E2, std::bit_and<>> operator&(const E1 & lhs, const E2 & rhs);

	template <class E1, class E2, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E1>, E1> || std::is_base_of_v<LinearExpression<E2>, E2>>>
	LinearOperation<E1, E2, std::bit_or<>> operator|(const E1 & lhs, const E2 & rhs);

	template <class E1, class E2, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E1>, E1> || std::is_base_of_v<LinearExpression<E2>, E2>>>
	LinearOperation<E1, E2, std::bit_xor<>> operator^(const E1 & lhs, const E2 & rhs);

	template <class E1, class E2, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E1>, E1> || std::is_base_of_v<LinearExpression<E2>, E2>>>
	LinearOperation<E1, E2, bitwise_left_shift<>> operator<<(const E1 & lhs, const E2 & rhs);

	template <class E1, class E2, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E1>, E1> || std::is_base_of_v<LinearExpression<E2>, E2>>>
	LinearOperation<E1, E2, bitwise_right_shift<>> operator<<(const E1 & lhs, const E2 & rhs);

	template <class E1, class E2, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E1>, E1> || std::is_base_of_v<LinearExpression<E2>, E2>>>
	LinearOperation<E1, E2, std::logical_and<>> operator&&(const E1 & lhs, const E2 & rhs);

	template <class E1, class E2, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E1>, E1> || std::is_base_of_v<LinearExpression<E2>, E2>>>
	LinearOperation<E1, E2, std::logical_or<>> operator||(const E1 & lhs, const E2 & rhs);

	template <class E1, class E2, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E1>, E1> || std::is_base_of_v<LinearExpression<E2>, E2>>>
	bool operator==(const E1 & lhs, const E2 & rhs);

	template <class E1, class E2, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E1>, E1> || std::is_base_of_v<LinearExpression<E2>, E2>>>
	bool operator!=(const E1 & lhs, const E2 & rhs);

	template <class E1, class E2, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E1>, E1> || std::is_base_of_v<LinearExpression<E2>, E2>>>
	LinearOperation<E1, E2, std::greater<>> operator>(const E1 & lhs, const E2 & rhs);

	template <class E1, class E2, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E1>, E1> || std::is_base_of_v<LinearExpression<E2>, E2>>>
	LinearOperation<E1, E2, std::less<>> operator<(const E1 & lhs, const E2 & rhs);

	template <class E1, class E2, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E1>, E1> || std::is_base_of_v<LinearExpression<E2>, E2>>>
	LinearOperation<E1, E2, std::greater_equal<>> operator>=(const E1 & lhs, const E2 & rhs);

	template <class E1, class E2, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E1>, E1> || std::is_base_of_v<LinearExpression<E2>, E2>>>
	LinearOperation<E1, E2, std::less_equal<>> operator<=(const E1 & lhs, const E2 & rhs);

	template <class E, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E>, E>>>
	LinearUnaryOperation<E, absolute<>> abs(const E & lhs);

	template <class E, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E>, E>>>
	LinearUnaryOperation<E, exponential<>> exp(const E & lhs);

	template <class E, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E>, E>>>
	LinearUnaryOperation<E, logarithm<>> log(const E & lhs);

	template <class E, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E>, E>>>
	LinearUnaryOperation<E, logarithm10<>> log10(const E & lhs);

	template <class E1, class E2, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E1>, E1>>>
	LinearOperation<E1, E2, power<>> pow(const E1 & lhs, const E2 & rhs);

	template <class E, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E>, E>>>
	LinearUnaryOperation<E, square_root<>> sqrt(const E & lhs);

	template <class E, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E>, E>>>
	LinearUnaryOperation<E, sinus<>> sin(const E & lhs);

	template <class E, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E>, E>>>
	LinearUnaryOperation<E, cosinus<>> cos(const E & lhs);

	template <class E, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E>, E>>>
	LinearUnaryOperation<E, tangent<>> tan(const E & lhs);

	template <class E, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E>, E>>>
	LinearUnaryOperation<E, arcsinus<>> asin(const E & lhs);

	template <class E, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E>, E>>>
	LinearUnaryOperation<E, arccosinus<>> acos(const E & lhs);

	template <class E, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E>, E>>>
	LinearUnaryOperation<E, arctangent<>> atan(const E & lhs);

	template <class E1, class E2, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E1>, E1>>>
	LinearOperation<E1, E2, arctangent2<>> atan2(const E1 & lhs, const E2 & rhs);

	template <class E, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E>, E>>>
	LinearUnaryOperation<E, sinus_hyperbolic<>> sinh(const E & lhs);

	template <class E, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E>, E>>>
	LinearUnaryOperation<E, cosinus_hyperbolic<>> cosh(const E & lhs);

	template <class E, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E>, E>>>
	LinearUnaryOperation<E, tangent_hyperbolic<>> tanh(const E & lhs);

	template <class E, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E>, E>>>
	LinearUnaryOperation<E, arcsinus_hyperbolic<>> asinh(const E & lhs);

	template <class E, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E>, E>>>
	LinearUnaryOperation<E, arccosinus_hyperbolic<>> acosh(const E & lhs);

	template <class E, typename enabled = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E>, E>>>
	LinearUnaryOperation<E, arctangent_hyperbolic<>> atanh(const E & lhs);
}

#include "utility/template_expression/vector.inl"

#endif // NEW_VECTOR_HPP