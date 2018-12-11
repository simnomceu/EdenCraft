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

#ifndef CONTAINER_METHOD_HPP
#define CONTAINER_METHOD_HPP

#include "utility/config.hpp"
#include "utility/pch.hpp"

namespace ece
{
	namespace utility
	{
		namespace container
		{
			/* Container::Container() */
			template <class T, typename = void>
			struct ECE_UTILITY_API has_empty_constructor : std::false_type {};

			template <class T>
			struct ECE_UTILITY_API has_empty_constructor<T, std::void_t<decltype(T())>> : std::true_type {};

			template <class T>
			inline constexpr bool has_empty_constructor_v = has_empty_constructor<T>::value;

			/* Container::Container(Container) */
			template <class T, typename = void>
			struct ECE_UTILITY_API has_copy_constructor : std::false_type {};

			template <class T>
			struct ECE_UTILITY_API has_copy_constructor<T, std::void_t<decltype(T(std::declval<T>()))>> : std::true_type {};

			template <class T>
			inline constexpr bool has_copy_constructor_v = has_copy_constructor<T>::value;

			/* Container & Container::operator=(Container) */
			template <class T, typename = void>
			struct ECE_UTILITY_API has_copy_assignment_operator : std::false_type {};

			template <class T>
			struct ECE_UTILITY_API has_copy_assignment_operator<T, std::void_t<decltype(std::declval<T>().operator=(std::declval<T>()))>> : std::true_type {};

			template <class T>
			inline constexpr bool has_copy_assignment_operator_v = has_copy_assignment_operator<T>::value;

			/* Container::~Container() */
			template <class T, typename = void>
			struct ECE_UTILITY_API has_destructor : std::false_type {};

			template <class T>
			struct ECE_UTILITY_API has_destructor<T, std::void_t<decltype(std::declval<T>().~T())>> : std::true_type {};

			template <class T>
			inline constexpr bool has_destructor_v = has_destructor<T>::value;

			/* Container::iterator Container::begin() */
			template <class T, typename = void>
			struct ECE_UTILITY_API has_method_begin : std::false_type {};

			template <class T>
			struct ECE_UTILITY_API has_method_begin<T, std::void_t<decltype(std::declval<T>().begin())>> : std::true_type {};

			template <class T>
			inline constexpr bool has_method_begin_v = has_method_begin<T>::value;

			/* Container::iterator Container::end() */
			template <class T, typename = void>
			struct ECE_UTILITY_API has_method_end : std::false_type {};

			template <class T>
			struct ECE_UTILITY_API has_method_end<T, std::void_t<decltype(std::declval<T>().end())>> : std::true_type {};

			template <class T>
			inline constexpr bool has_method_end_v = has_method_end<T>::value;

			/* Container::const_iterator Container::cbegin() */
			template <class T, typename = void>
			struct ECE_UTILITY_API has_method_cbegin : std::false_type {};

			template <class T>
			struct ECE_UTILITY_API has_method_cbegin<T, std::void_t<decltype(std::declval<T>().cbegin())>> : std::true_type {};

			template <class T>
			inline constexpr bool has_method_cbegin_v = has_method_cbegin<T>::value;

			/* Container::const_iterator Container::cend() */
			template <class T, typename = void>
			struct ECE_UTILITY_API has_method_cend : std::false_type {};

			template <class T>
			struct ECE_UTILITY_API has_method_cend<T, std::void_t<decltype(std::declval<T>().cend())>> : std::true_type {};

			template <class T>
			inline constexpr bool has_method_cend_v = has_method_cend<T>::value;

			/* bool Container::operator==(Container) */
			template <class T, typename = void>
			struct ECE_UTILITY_API equal_to_operator : std::false_type {};

			template <class T>
			struct ECE_UTILITY_API equal_to_operator<T, std::void_t<decltype(operator==(std::declval<T>(), std::declval<T>()))>> : std::true_type {};

			template <class T>
			inline constexpr bool equal_to_operator_v = equal_to_operator<T>::value;

			/* bool Container::operator!=(Container) */
			template <class T, typename = void>
			struct ECE_UTILITY_API not_equal_to_operator : std::false_type {};

			template <class T>
			struct ECE_UTILITY_API not_equal_to_operator<T, std::void_t<decltype(operator!=(std::declval<T>(), std::declval<T>()))>> : std::true_type {};

			template <class T>
			inline constexpr bool not_equal_to_operator_v = not_equal_to_operator<T>::value;

			/* void Container::swap(Container) */
			template <class T, typename = void>
			struct ECE_UTILITY_API has_swap_method : std::false_type {};

			template <class T>
			struct ECE_UTILITY_API has_swap_method<T, std::void_t<decltype(std::declval<T>().swap(std::declval<T&>()))>> : std::true_type {};

			template <class T>
			inline constexpr bool has_swap_method_v = has_swap_method<T>::value;

			/* void std::swap(Container, Container) */
			template <class T, typename = void>
			struct ECE_UTILITY_API has_swap_function : std::false_type {};

			template <class T>
			struct ECE_UTILITY_API has_swap_function<T, std::void_t<decltype(std::swap(std::declval<T&>(), std::declval<T&>()))>> : std::true_type {};

			template <class T>
			inline constexpr bool has_swap_function_v = has_swap_function<T>::value;

			/* Container::size_type Container::size() */
			template <class T, typename = void>
			struct ECE_UTILITY_API has_size_method : std::false_type {};

			template <class T>
			struct ECE_UTILITY_API has_size_method<T, std::void_t<decltype(std::declval<T>().size())>> : std::true_type {};

			template <class T>
			inline constexpr bool has_size_method_v = has_size_method<T>::value;

			/* Container::size_type Container::max_size() */
			template <class T, typename = void>
			struct ECE_UTILITY_API has_max_size_method : std::false_type {};

			template <class T>
			struct ECE_UTILITY_API has_max_size_method<T, std::void_t<decltype(std::declval<T>().max_size())>> : std::true_type {};

			template <class T>
			inline constexpr bool has_max_size_method_v = has_max_size_method<T>::value;

			/* bool Container::empty() */
			template <class T, typename = void>
			struct ECE_UTILITY_API has_empty_method : std::false_type {};

			template <class T>
			struct ECE_UTILITY_API has_empty_method<T, std::void_t<decltype(std::declval<T>().empty())>> : std::true_type {};

			template <class T>
			inline constexpr bool has_empty_method_v = has_empty_method<T>::value;
		} // namespace container
	} // namespace utility
} // namespace ece

#endif // CONTAINER_METHOD_HPP