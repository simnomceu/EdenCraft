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

#ifndef CONTAINER_TYPE_HPP
#define CONTAINER_TYPE_HPP

#include "utility/config.hpp"

#include <type_traits>

namespace ece
{
	namespace utility
	{
		namespace container
		{
			/* Container::value_type */
			template <class T, typename = void>
			struct ECE_UTILITY_API has_value_type: std::false_type {};

			template <class T>
			struct ECE_UTILITY_API has_value_type<T, std::void_t<typename T::value_type>>: std::true_type {}; // Todo: T::value_type should be 'Erasable'.

			template <class T>
			inline constexpr bool has_value_type_v = has_value_type<T>::value;

			/* Container::reference */
			template <class T, typename = void>
			struct ECE_UTILITY_API has_reference : std::false_type {};

			template <class T>
			struct ECE_UTILITY_API has_reference<T, std::void_t<typename T::reference>> : std::true_type {};

			template <class T>
			inline constexpr bool has_reference_v = has_reference<T>::value;

			/* Container::const_reference */
			template <class T, typename = void>
			struct ECE_UTILITY_API has_const_reference : std::false_type {};

			template <class T>
			struct ECE_UTILITY_API has_const_reference<T, std::void_t<typename T::const_reference>> : std::true_type {};

			template <class T>
			inline constexpr bool has_const_reference_v = has_const_reference<T>::value;

			/* Container::iterator */
			template <class T, typename = void>
			struct ECE_UTILITY_API has_iterator : std::false_type {};

			template <class T>
			struct ECE_UTILITY_API has_iterator<T, std::void_t<typename T::iterator>> : std::true_type {}; // Todo: T::iterator should be 'ForwardIterator'.

			template <class T>
			inline constexpr bool has_iterator_v = has_iterator<T>::value;

			/* Container::const_iterator */
			template <class T, typename = void>
			struct ECE_UTILITY_API has_const_iterator : std::false_type {};

			template <class T>
			struct ECE_UTILITY_API has_const_iterator<T, std::void_t<typename T::const_iterator>> : std::true_type {}; // Todo: T::iterator should be 'ForwardIterator'.

			template <class T>
			inline constexpr bool has_const_iterator_v = has_const_iterator<T>::value;

			/* Container::difference_type */
			template <class T, typename = void>
			struct ECE_UTILITY_API has_difference_type : std::false_type {};

			template <class T>
			struct ECE_UTILITY_API has_difference_type<T, std::void_t<typename T::difference_type>> : std::true_type {};

			template <class T>
			inline constexpr bool has_difference_type_v = has_difference_type<T>::value;

			/* Container::size_type */
			template <class T, typename = void>
			struct ECE_UTILITY_API has_size_type : std::false_type {};

			template <class T>
			struct ECE_UTILITY_API has_size_type<T, std::void_t<typename T::size_type>> : std::true_type {};

			template <class T>
			inline constexpr bool has_size_type_v = has_size_type<T>::value;
		} // namespace container
	} // namespace utility
} // namespace ece

#endif // CONTAINER_TYPE_HPP