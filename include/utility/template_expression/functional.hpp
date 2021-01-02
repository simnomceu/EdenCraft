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

#ifndef FUNCTIONAL_HPP
#define FUNCTIONAL_HPP

#include "utility/config.hpp"
#include "utility/pch.hpp"

namespace ece
{
    namespace utility
    {
        namespace template_expression
        {
        	/**
        	 * @struct unary_plus
        	 * @tparam T The type of element to apply the operation to.
        	 * @brief Structure operation for the unary plus operation.
        	 */
        	template <class T = void>
        	struct unary_plus
        	{
        		inline constexpr T operator()(const T & value) const;
        	};

        	template <>
        	struct unary_plus<void>
        	{
        		template <class T>
        		inline constexpr auto operator()(T && value) const -> decltype(+std::forward<T>(value));
        	};

        	/**
        	 * @struct bitwise_left_shift
        	 * @tparam T1 The type of element to apply the operation to.
        	 * @tparam T2 The type of the shif to apply.
        	 * @brief Structure operation for the bitwise left shift operation.
        	 */
        	template <class T1 = void, class T2 = void>
        	struct bitwise_left_shift
        	{
        		inline constexpr T1 operator()(const T1 & lhs, const T2 & rhs) const;
        	};

        	template <>
        	struct bitwise_left_shift<void, void>
        	{
        		template <class T1, class T2>
        		inline constexpr auto operator()(T1 && lhs, T2 && rhs) const -> decltype(std::forward<T1>(lhs) << std::forward<T2>(rhs));
        	};

        	/**
        	 * @struct bitwise_right_shift
        	 * @tparam T1 The type of element to apply the operation to.
        	 * @tparam T2 The type of the shif to apply.
        	 * @brief Structure operation for the bitwise right shift operation.
        	 */
        	template <class T1 = void, class T2 = void>
        	struct bitwise_right_shift
        	{
        		inline constexpr T1 operator()(const T1 & lhs, const T2 & rhs) const;
        	};

        	template <>
        	struct bitwise_right_shift<void, void>
        	{
        		template <class T1, class T2>
        		inline constexpr auto operator()(T1 && lhs, T2 && rhs) const -> decltype(std::forward<T1>(lhs) >> std::forward<T2>(rhs));
        	};

        	/**
        	 * @struct absolute
        	 * @tparam T The type of element to apply the operation to.
        	 * @brief Structure operation for the absolute operation.
        	 */
        	template <class T = void>
        	struct absolute
        	{
        		inline constexpr T operator()(const T & value) const;
        	};

        	template <>
        	struct absolute<void>
        	{
        		template <class T>
        		inline constexpr auto operator()(T && value) const -> decltype(std::forward<T>(value) >= 0 ? std::forward<T>(value) : -std::forward<T>(value));
        	};

        	/**
        	 * @struct exponential
        	 * @tparam T The type of element to apply the operation to.
        	 * @brief Structure operation for the exponential operation.
        	 */
        	template <class T = void>
        	struct exponential
        	{
        		inline constexpr T operator()(const T & value) const;
        	};

        	template <>
        	struct exponential<void>
        	{
        		template <class T>
        		inline constexpr auto operator()(T && value) const -> decltype(std::exp(std::forward<T>(value)));
        	};

        	/**
        	 * @struct logarithm
        	 * @tparam T The type of element to apply the operation to.
        	 * @brief Structure operation for the logarithm operation.
        	 */
        	template <class T = void>
        	struct logarithm
        	{
        		inline constexpr T operator()(const T & value) const;
        	};

        	template <>
        	struct logarithm<void>
        	{
        		template <class T>
        		inline constexpr auto operator()(T && value) const -> decltype(std::log(std::forward<T>(value)));
        	};

        	/**
        	 * @struct logarithm10
        	 * @tparam T The type of element to apply the operation to.
        	 * @brief Structure operation for the base 10 logarithm operation.
        	 */
        	template <class T = void>
        	struct logarithm10
        	{
        		inline constexpr T operator()(const T & value) const;
        	};

        	template <>
        	struct logarithm10<void>
        	{
        		template <class T>
        		inline constexpr auto operator()(T && value) const -> decltype(std::log10(std::forward<T>(value)));
        	};

        	/**
        	 * @struct power
        	 * @tparam T1 The type of element to apply the operation to.
        	 * @tparam T2 The type of the exponent to apply.
        	 * @brief Structure operation for the power operation.
        	 */
        	template <class T1 = void, class T2 = void>
        	struct power
        	{
        		inline constexpr T1 operator()(const T1 & value, const T2 & exponent) const;
        	};

        	template <>
        	struct power<void, void>
        	{
        		template <class T1, class T2>
        		inline constexpr auto operator()(T1 && value, const T2 & exponent) const -> decltype(std::pow(std::forward<T1>(value), std::forward<T2>(exponent)));
        	};

        	/**
        	 * @struct square_root
        	 * @tparam T The type of element to apply the operation to.
        	 * @brief Structure operation for the square root operation.
        	 */
        	template <class T = void>
        	struct square_root
        	{
        		inline constexpr T operator()(const T & value) const;
        	};

        	template <>
        	struct square_root<void>
        	{
        		template <class T>
        		inline constexpr auto operator()(T && value) const -> decltype(std::sqrt(std::forward<T>(value)));
        	};

        	/**
        	 * @struct sinus
        	 * @tparam T The type of element to apply the operation to.
        	 * @brief Structure operation for the sinus operation.
        	 */
        	template <class T = void>
        	struct sinus
        	{
        		inline constexpr T operator()(const T & value) const;
        	};

        	template <>
        	struct sinus<void>
        	{
        		template <class T>
        		inline constexpr auto operator()(T && value) const -> decltype(std::sin(std::forward<T>(value)));
        	};

        	/**
        	 * @struct cosinus
        	 * @tparam T The type of element to apply the operation to.
        	 * @brief Structure operation for the cosinus operation.
        	 */
        	template <class T = void>
        	struct cosinus
        	{
        		inline constexpr T operator()(const T & value) const;
        	};

        	template <>
        	struct cosinus<void>
        	{
        		template <class T>
        		inline constexpr auto operator()(T && value) const -> decltype(std::cos(std::forward<T>(value)));
        	};

        	/**
        	 * @struct tangent
        	 * @tparam T The type of element to apply the operation to.
        	 * @brief Structure operation for the tangent operation.
        	 */
        	template <class T = void>
        	struct tangent
        	{
        		inline constexpr T operator()(const T & value) const;
        	};

        	template <>
        	struct tangent<void>
        	{
        		template <class T>
        		inline constexpr auto operator()(T && value) const -> decltype(std::tan(std::forward<T>(value)));
        	};

        	/**
        	 * @struct arcsinus
        	 * @tparam T The type of element to apply the operation to.
        	 * @brief Structure operation for the arcsinus operation.
        	 */
        	template <class T = void>
        	struct arcsinus
        	{
        		inline constexpr T operator()(const T & value) const;
        	};

        	template <>
        	struct arcsinus<void>
        	{
        		template <class T>
        		inline constexpr auto operator()(T && value) const -> decltype(std::asin(std::forward<T>(value)));
        	};

        	/**
        	 * @struct arccosinus
        	 * @tparam T The type of element to apply the operation to.
        	 * @brief Structure operation for the arccosinus operation.
        	 */
        	template <class T = void>
        	struct arccosinus
        	{
        		inline constexpr T operator()(const T & value) const;
        	};

        	template <>
        	struct arccosinus<void>
        	{
        		template <class T>
        		inline constexpr auto operator()(T && value) const -> decltype(std::acos(std::forward<T>(value)));
        	};

        	/**
        	 * @struct arctangent
        	 * @tparam T The type of element to apply the operation to.
        	 * @brief Structure operation for the arctangent operation.
        	 */
        	template <class T = void>
        	struct arctangent
        	{
        		inline constexpr T operator()(const T & value) const;
        	};

        	template <>
        	struct arctangent<void>
        	{
        		template <class T>
        		inline constexpr auto operator()(T && value) const -> decltype(std::atan(std::forward<T>(value)));
        	};

        	/**
        	 * @struct arctangent2
        	 * @tparam T1 The type of element to apply the operation to.
        	 * @tparam T2 The type of the x element to apply to.
        	 * @brief Structure operation for the arctangent operation.
        	 */
        	template <class T1 = void, class T2 = void>
        	struct arctangent2
        	{
        		inline constexpr T1 operator()(const T1 & value, const T2 & x) const;
        	};

        	template <>
        	struct arctangent2<void, void>
        	{
        		template <class T1, class T2>
        		inline constexpr auto operator()(T1 && value, T2 && x) const -> decltype(std::atan2(std::forward<T1>(value), std::forward<T2>(x)));
        	};

        	/**
        	 * @struct sinus_hyperbolic
        	 * @tparam T The type of element to apply the operation to.
        	 * @brief Structure operation for the sinus hyperbolic operation.
        	 */
        	template <class T = void>
        	struct sinus_hyperbolic
        	{
        		inline constexpr T operator()(const T & value) const;
        	};

        	template <>
        	struct sinus_hyperbolic<void>
        	{
        		template <class T>
        		inline constexpr auto operator()(T && value) const -> decltype(std::sinh(std::forward<T>(value)));
        	};

        	/**
        	 * @struct cosinus_hyperbolic
        	 * @tparam T The type of element to apply the operation to.
        	 * @brief Structure operation for the cosinus hyperbolic operation.
        	 */
        	template <class T = void>
        	struct cosinus_hyperbolic
        	{
        		inline constexpr T operator()(const T & value) const;
        	};

        	template <>
        	struct cosinus_hyperbolic<void>
        	{
        		template <class T>
        		inline constexpr auto operator()(T && value) const -> decltype(std::cosh(std::forward<T>(value)));
        	};

        	/**
        	 * @struct tangent_hyperbolic
        	 * @tparam T The type of element to apply the operation to.
        	 * @brief Structure operation for the tangent hyperbolic operation.
        	 */
        	template <class T = void>
        	struct tangent_hyperbolic
        	{
        		inline constexpr T operator()(const T & value) const;
        	};

        	template <>
        	struct tangent_hyperbolic<void>
        	{
        		template <class T>
        		inline constexpr auto operator()(T && value) const -> decltype(std::tanh(std::forward<T>(value)));
        	};

        	/**
        	 * @struct arcsinus_hyperbolic
        	 * @tparam T The type of element to apply the operation to.
        	 * @brief Structure operation for the arcsinus hyperbolic operation.
        	 */
        	template <class T = void>
        	struct arcsinus_hyperbolic
        	{
        		inline constexpr T operator()(const T & value) const;
        	};

        	template <>
        	struct arcsinus_hyperbolic<void>
        	{
        		template <class T>
        		inline constexpr auto operator()(T && value) const -> decltype(std::asinh(std::forward<T>(value)));
        	};

        	/**
        	 * @struct arccosinus_hyperbolic
        	 * @tparam T The type of element to apply the operation to.
        	 * @brief Structure operation for the arccosinus hyperbolic operation.
        	 */
        	template <class T = void>
        	struct arccosinus_hyperbolic
        	{
        		inline constexpr T operator()(const T & value) const;
        	};

        	template <>
        	struct arccosinus_hyperbolic<void>
        	{
        		template <class T>
        		inline constexpr auto operator()(T && value) const -> decltype(std::acosh(std::forward<T>(value)));
        	};

        	/**
        	 * @struct arctangent_hyperbolic
        	 * @tparam T The type of element to apply the operation to.
        	 * @brief Structure operation for the arctangent hyperbolic operation.
        	 */
        	template <class T = void>
        	struct arctangent_hyperbolic
        	{
        		inline constexpr T operator()(const T & value) const;
        	};

        	template <>
        	struct arctangent_hyperbolic<void>
        	{
        		template <class T>
        		inline constexpr auto operator()(T && value) const -> decltype(std::atanh(std::forward<T>(value)));
        	};
        } // namespace template_expression
    } // namespace utility
} // namespace ece

#include "utility/template_expression/functional.inl"

#endif // FUNCTIONAL_HPP
