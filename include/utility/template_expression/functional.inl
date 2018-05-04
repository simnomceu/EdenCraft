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

namespace ece
{
    namespace utility
    {
        namespace template_expression
        {
        	template<class T>
        	inline constexpr T unary_plus<T>::operator()(const T & value) const { return (+value); }

        	template<class T>
        	inline constexpr auto unary_plus<void>::operator()(T && value) const -> decltype(+std::forward<T>(value)) { return +std::forward<T>(value); }

        	template<class T1, class T2>
        	inline constexpr T1 bitwise_left_shift<T1, T2>::operator()(const T1 & lhs, const T2 & rhs) const { return (lhs << rhs); }

        	template<class T1, class T2>
        	inline constexpr auto bitwise_left_shift<void, void>::operator()(T1 && lhs, T2 && rhs) const -> decltype(std::forward<T1>(lhs) << std::forward<T2>(rhs)) { return std::forward<T1>(lhs) << std::forward<T2>(rhs); }

        	template<class T1, class T2>
        	inline constexpr T1 bitwise_right_shift<T1, T2>::operator()(const T1 & lhs, const T2 & rhs) const { return (lhs >> rhs); }

        	template<class T1, class T2>
        	inline constexpr auto bitwise_right_shift<void, void>::operator()(T1 && lhs, T2 && rhs) const -> decltype(std::forward<T1>(lhs) >> std::forward<T2>(rhs)) { return std::forward<T1>(lhs) >> std::forward<T2>(rhs); }

        	template<class T>
        	inline constexpr T absolute<T>::operator()(const T & value) const { return value >= 0 ? value : -value; }

        	template<class T>
        	inline constexpr auto absolute<void>::operator()(T && value) const -> decltype(std::forward<T>(value) >= 0 ? std::forward<T>(value) : -std::forward<T>(value)) { return std::forward<T>(value) >= 0 ? std::forward<T>(value) : -std::forward<T>(value); }

        	template<class T>
        	inline constexpr T exponential<T>::operator()(const T & value) const { return std::exp(value); }

        	template<class T>
        	inline constexpr auto exponential<void>::operator()(T && value) const -> decltype(std::exp(std::forward<T>(value))) { return std::exp(std::forward<T>(value)); }

        	template<class T>
        	inline constexpr T logarithm<T>::operator()(const T & value) const { return std::log(value); }

        	template<class T>
        	inline constexpr auto logarithm<void>::operator()(T && value) const -> decltype(std::log(std::forward<T>(value))) { return std::log(std::forward<T>(value)); }

        	template<class T>
        	inline constexpr T logarithm10<T>::operator()(const T & value) const { return std::log10(value); }

        	template<class T>
        	inline constexpr auto logarithm10<void>::operator()(T && value) const -> decltype(std::log10(std::forward<T>(value))) { return std::log10(std::forward<T>(value)); }

        	template<class T1, class T2>
        	inline constexpr T1 power<T1, T2>::operator()(const T1 & value, const T2 & exponent) const { return std::pow(value, exponent); }

        	template<class T1, class T2>
        	inline constexpr auto power<void, void>::operator()(T1 && value, const T2 & exponent) const -> decltype(std::pow(std::forward<T1>(value), std::forward<T2>(exponent))) { return std::pow(std::forward<T1>(value), std::forward<T2>(exponent)); }

        	template<class T>
        	inline constexpr T square_root<T>::operator()(const T & value) const { return std::sqrt(value); }

        	template<class T>
        	inline constexpr auto square_root<void>::operator()(T && value) const -> decltype(std::sqrt(std::forward<T>(value))) { return std::sqrt(std::forward<T>(value)); }

        	template<class T>
        	inline constexpr T sinus<T>::operator()(const T & value) const { return std::sin(value); }

        	template<class T>
        	inline constexpr auto sinus<void>::operator()(T && value) const -> decltype(std::sin(std::forward<T>(value))) { return std::sin(std::forward<T>(value)); }

        	template<class T>
        	inline constexpr T cosinus<T>::operator()(const T & value) const { return std::cos(value); }

        	template<class T>
        	inline constexpr auto cosinus<void>::operator()(T && value) const -> decltype(std::cos(std::forward<T>(value))) { return std::cos(std::forward<T>(value)); }

        	template<class T>
        	inline constexpr T tangent<T>::operator()(const T & value) const { return std::tan(value); }

        	template<class T>
        	inline constexpr auto tangent<void>::operator()(T && value) const -> decltype(std::tan(std::forward<T>(value))) { return std::tan(std::forward<T>(value)); }

        	template<class T>
        	inline constexpr T arcsinus<T>::operator()(const T & value) const { return std::asin(value); }

        	template<class T>
        	inline constexpr auto arcsinus<void>::operator()(T && value) const -> decltype(std::asin(std::forward<T>(value))) { return std::asin(std::forward<T>(value)); }

        	template<class T>
        	inline constexpr T arccosinus<T>::operator()(const T & value) const { return std::acos(value); }

        	template<class T>
        	inline constexpr auto arccosinus<void>::operator()(T && value) const -> decltype(std::acos(std::forward<T>(value))) { return std::acos(std::forward<T>(value)); }

        	template<class T>
        	inline constexpr T arctangent<T>::operator()(const T & value) const { return std::atan(value); }

        	template<class T>
        	inline constexpr auto arctangent<void>::operator()(T && value) const -> decltype(std::atan(std::forward<T>(value))) { return std::atan(std::forward<T>(value)); }

        	template<class T1, class T2>
        	inline constexpr T1 arctangent2<T1, T2>::operator()(const T1 & value, const T2 & x) const { return std::atan2(value, x); }

        	template<class T1, class T2>
        	inline constexpr auto arctangent2<void, void>::operator()(T1 && value, T2 && x) const -> decltype(std::atan2(std::forward<T1>(value), std::forward<T2>(x))) { return std::atan2(std::forward<T1>(value), std::forward<T2>(x)); }

        	template<class T>
        	inline constexpr T sinus_hyperbolic<T>::operator()(const T & value) const { return std::sinh(value); }

        	template<class T>
        	inline constexpr auto sinus_hyperbolic<void>::operator()(T && value) const -> decltype(std::sinh(std::forward<T>(value))) { return std::sinh(std::forward<T>(value)); }

        	template<class T>
        	inline constexpr T cosinus_hyperbolic<T>::operator()(const T & value) const { return std::cosh(value); }

        	template<class T>
        	inline constexpr auto cosinus_hyperbolic<void>::operator()(T && value) const -> decltype(std::cosh(std::forward<T>(value))) { return std::cosh(std::forward<T>(value)); }

        	template<class T>
        	inline constexpr T tangent_hyperbolic<T>::operator()(const T & value) const { return std::tanh(value); }

        	template<class T>
        	inline constexpr auto tangent_hyperbolic<void>::operator()(T && value) const -> decltype(std::tanh(std::forward<T>(value))) { return std::tanh(std::forward<T>(value)); }

        	template<class T>
        	inline constexpr T arcsinus_hyperbolic<T>::operator()(const T & value) const { return std::asinh(value); }

        	template<class T>
        	inline constexpr auto arcsinus_hyperbolic<void>::operator()(T && value) const -> decltype(std::asinh(std::forward<T>(value))) { return std::asinh(std::forward<T>(value)); }

        	template<class T>
        	inline constexpr T arccosinus_hyperbolic<T>::operator()(const T & value) const { return std::acosh(value); }

        	template<class T>
        	inline constexpr auto arccosinus_hyperbolic<void>::operator()(T && value) const -> decltype(std::acosh(std::forward<T>(value))) { return std::acosh(std::forward<T>(value)); }

        	template<class T>
        	inline constexpr T arctangent_hyperbolic<T>::operator()(const T & value) const { return std::atanh(value); }

        	template<class T>
        	inline constexpr auto arctangent_hyperbolic<void>::operator()(T && value) const -> decltype(std::atanh(std::forward<T>(value))) { return std::atanh(std::forward<T>(value)); }
        } // namespace template_expression
    } // namespace utility
} // namespace ece
