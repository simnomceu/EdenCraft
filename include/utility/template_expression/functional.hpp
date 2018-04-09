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

#include <utility>
#include <cmath>

namespace ece
{
	template <class T = void>
	struct unary_plus
	{
		constexpr T operator()(const T & value) const { return (+value); }
	};

	template <>
	struct unary_plus<void>
	{
		template <class T>
		constexpr auto operator()(T && value) const -> decltype(+std::forward<T>(value)) { return +std::forward<T>(value); }
	};

	template <class T1 = void, class T2 = void>
	struct bitwise_left_shift
	{
		constexpr T1 operator()(const T1 & lhs, const T2 & rhs) const { return (lhs << rhs); }
	};

	template <>
	struct bitwise_left_shift<void, void>
	{
		template <class T1, class T2>
		constexpr auto operator()(T1 && lhs, T2 && rhs) const -> decltype(std::forward<T1>(lhs) << std::forward<T2>(rhs)) { return std::forward<T1>(lhs) << std::forward<T2>(rhs); }
	};

	template <class T1 = void, class T2 = void>
	struct bitwise_right_shift
	{
		constexpr T1 operator()(const T1 & lhs, const T2 & rhs) const { return (lhs >> rhs); }
	};

	template <>
	struct bitwise_right_shift<void, void>
	{
		template <class T1, class T2>
		constexpr auto operator()(T1 && lhs, T2 && rhs) const -> decltype(std::forward<T1>(lhs) >> std::forward<T2>(rhs)) { return std::forward<T1>(lhs) >> std::forward<T2>(rhs); }
	};

	template <class T = void>
	struct absolute
	{
		constexpr T operator()(const T & value) const { return value >= 0 ? value : -value; }
	};

	template <>
	struct absolute<void>
	{
		template <class T>
		constexpr auto operator()(T && value) const -> decltype(std::forward<T>(value) >= 0 ? std::forward<T>(value) : -std::forward<T>(value)) { return std::forward<T>(value) >= 0 ? std::forward<T>(value) : -std::forward<T>(value); }
	};

	template <class T = void>
	struct exponential
	{
		constexpr T operator()(const T & value) const { return std::exp(value); }
	};

	template <>
	struct exponential<void>
	{
		template <class T>
		constexpr auto operator()(T && value) const -> decltype(std::exp(std::forward<T>(value))) { return std::exp(std::forward<T>(value)); }
	};

	template <class T = void>
	struct logarithm
	{
		constexpr T operator()(const T & value) const { return std::log(value); }
	};

	template <>
	struct logarithm<void>
	{
		template <class T>
		constexpr auto operator()(T && value) const -> decltype(std::log(std::forward<T>(value))) { return std::log(std::forward<T>(value)); }
	};

	template <class T = void>
	struct logarithm10
	{
		constexpr T operator()(const T & value) const { return std::log10(value); }
	};

	template <>
	struct logarithm10<void>
	{
		template <class T>
		constexpr auto operator()(T && value) const -> decltype(std::log10(std::forward<T>(value))) { return std::log10(std::forward<T>(value)); }
	};

	template <class T1 = void, class T2 = void>
	struct power
	{
		constexpr T1 operator()(const T1 & value, const T2 & exponent) const { return std::pow(value, exponent); }
	};

	template <>
	struct power<void, void>
	{
		template <class T1, class T2>
		constexpr auto operator()(T1 && value, const T2 & exponent) const -> decltype(std::pow(std::forward<T1>(value), std::forward<T2>(exponent))) { return std::pow(std::forward<T1>(value), std::forward<T2>(exponent)); }
	};

	template <class T = void>
	struct square_root
	{
		constexpr T operator()(const T & value) const { return std::sqrt(value); }
	};

	template <>
	struct square_root<void>
	{
		template <class T>
		constexpr auto operator()(T && value) const -> decltype(std::sqrt(std::forward<T>(value))) { return std::sqrt(std::forward<T>(value)); }
	};

	template <class T = void>
	struct sinus
	{
		constexpr T operator()(const T & value) const { return std::sin(value); }
	};

	template <>
	struct sinus<void>
	{
		template <class T>
		constexpr auto operator()(T && value) const -> decltype(std::sin(std::forward<T>(value))) { return std::sin(std::forward<T>(value)); }
	};

	template <class T = void>
	struct cosinus
	{
		constexpr T operator()(const T & value) const { return std::cos(value); }
	};

	template <>
	struct cosinus<void>
	{
		template <class T>
		constexpr auto operator()(T && value) const -> decltype(std::cos(std::forward<T>(value))) { return std::cos(std::forward<T>(value)); }
	};

	template <class T = void>
	struct tangent
	{
		constexpr T operator()(const T & value) const { return std::tan(value); }
	};

	template <>
	struct tangent<void>
	{
		template <class T>
		constexpr auto operator()(T && value) const -> decltype(std::tan(std::forward<T>(value))) { return std::tan(std::forward<T>(value)); }
	};

	template <class T = void>
	struct arcsinus
	{
		constexpr T operator()(const T & value) const { return std::asin(value); }
	};

	template <>
	struct arcsinus<void>
	{
		template <class T>
		constexpr auto operator()(T && value) const -> decltype(std::asin(std::forward<T>(value))) { return std::asin(std::forward<T>(value)); }
	};

	template <class T = void>
	struct arccosinus
	{
		constexpr T operator()(const T & value) const { return std::acos(value); }
	};

	template <>
	struct arccosinus<void>
	{
		template <class T>
		constexpr auto operator()(T && value) const -> decltype(std::acos(std::forward<T>(value))) { return std::acos(std::forward<T>(value)); }
	};

	template <class T = void>
	struct arctangent
	{
		constexpr T operator()(const T & value) const { return std::atan(value); }
	};

	template <>
	struct arctangent<void>
	{
		template <class T>
		constexpr auto operator()(T && value) const -> decltype(std::atan(std::forward<T>(value))) { return std::atan(std::forward<T>(value)); }
	};

	template <class T1 = void, class T2 = void>
	struct arctangent2
	{
		constexpr T1 operator()(const T1 & value, const T2 & x) const { return std::atan2(value, x); }
	};

	template <>
	struct arctangent2<void, void>
	{
		template <class T1, class T2>
		constexpr auto operator()(T1 && value, T2 && x) const -> decltype(std::atan2(std::forward<T1>(value), std::forward<T2>(x))) { return std::atan2(std::forward<T1>(value), std::forward<T2>(x)); }
	};

	template <class T = void>
	struct sinus_hyperbolic
	{
		constexpr T operator()(const T & value) const { return std::sinh(value); }
	};

	template <>
	struct sinus_hyperbolic<void>
	{
		template <class T>
		constexpr auto operator()(T && value) const -> decltype(std::sinh(std::forward<T>(value))) { return std::sinh(std::forward<T>(value)); }
	};

	template <class T = void>
	struct cosinus_hyperbolic
	{
		constexpr T operator()(const T & value) const { return std::cosh(value); }
	};

	template <>
	struct cosinus_hyperbolic<void>
	{
		template <class T>
		constexpr auto operator()(T && value) const -> decltype(std::cosh(std::forward<T>(value))) { return std::cosh(std::forward<T>(value)); }
	};

	template <class T = void>
	struct tangent_hyperbolic
	{
		constexpr T operator()(const T & value) const { return std::tanh(value); }
	};

	template <>
	struct tangent_hyperbolic<void>
	{
		template <class T>
		constexpr auto operator()(T && value) const -> decltype(std::tanh(std::forward<T>(value))) { return std::tanh(std::forward<T>(value)); }
	};

	template <class T = void>
	struct arcsinus_hyperbolic
	{
		constexpr T operator()(const T & value) const { return std::asinh(value); }
	};

	template <>
	struct arcsinus_hyperbolic<void>
	{
		template <class T>
		constexpr auto operator()(T && value) const -> decltype(std::asinh(std::forward<T>(value))) { return std::asinh(std::forward<T>(value)); }
	};

	template <class T = void>
	struct arccosinus_hyperbolic
	{
		constexpr T operator()(const T & value) const { return std::acosh(value); }
	};

	template <>
	struct arccosinus_hyperbolic<void>
	{
		template <class T>
		constexpr auto operator()(T && value) const -> decltype(std::acosh(std::forward<T>(value))) { return std::acosh(std::forward<T>(value)); }
	};

	template <class T = void>
	struct arctangent_hyperbolic
	{
		constexpr T operator()(const T & value) const { return std::atanh(value); }
	};

	template <>
	struct arctangent_hyperbolic<void>
	{
		template <class T>
		constexpr auto operator()(T && value) const -> decltype(std::atanh(std::forward<T>(value))) { return std::atanh(std::forward<T>(value)); }
	};
}

#endif // FUNCTIONAL_HPP
