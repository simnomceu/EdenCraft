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

#ifndef CONTIGUOUS_CONTAINER_HPP
#define CONTIGUOUS_CONTAINER_HPP

#include "utility/config.hpp"

#include <vector>
#include <array>
#include <valarray>
#include <string>
#include <string_view>

namespace ece
{
	namespace utility
	{
		namespace container
		{
			template <class T>
			struct ECE_UTILITY_API contiguous_container: std::false_type {};

			template <class T>
			inline ECE_UTILITY_API constexpr bool contiguous_container_v = contiguous_container<T>::value;

			template <class Type, class Allocator>
			struct ECE_UTILITY_API contiguous_container<std::vector<Type, Allocator>>: std::true_type {};

			template <class Type, std::size_t Size>
			struct ECE_UTILITY_API contiguous_container<std::array<Type, Size>> : std::true_type {};

			template <class Type>
			struct ECE_UTILITY_API contiguous_container<std::valarray<Type>> : std::true_type {};

			template <class CharT, class Traits, class Allocator>
			struct ECE_UTILITY_API contiguous_container<std::basic_string<CharT, Traits, Allocator>> : std::true_type {};

			template <class CharT, class Traits>
			struct ECE_UTILITY_API contiguous_container<std::basic_string_view<CharT, Traits>> : std::true_type {};
		}
	}
}

#endif // CONTIGUOUS_CONTAINER_HPP