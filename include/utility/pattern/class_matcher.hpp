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

#ifndef CLASS_MATCHER_HPP
#define CLASS_MATCHER_HPP

#include "utility/config.hpp"
#include "utility/pch.hpp"
#include "utility/hash.hpp"

namespace ece
{
	namespace utility
	{
		namespace pattern
		{
			template <class A>
			struct ECE_UTILITY_API match_class_to_class
			{
			public:
				using type = void;
			};

			template <class A>
			using match_class_to_class_t = typename match_class_to_class<A>::type;

#			define RegisterMatchClassToClass(A, B) \
				template <> \
				struct ECE_UTILITY_API ece::utility::pattern::match_class_to_class<A> \
				{ \
				public: \
				    using type = B; \
				};

			template <std::uint64_t UUID>
			struct ECE_UTILITY_API match_string_to_class
			{
			public:
				using type = void;
			};

			template <std::uint64_t UUID>
			using match_string_to_class_t = typename match_string_to_class<UUID>::type;

#			define RegisterMatchStringToClass(A, B) \
				__pragma(warning(push)) \
				__pragma(warning(disable: 4307)) \
				template <> \
				struct ECE_UTILITY_API ece::utility::pattern::match_string_to_class<ece::hash64_fnv1a(A)> \
				{ \
				public: \
				    using type = B; \
				}; \
				__pragma(warning(pop))
		} // namespace pattern
	} // namespace utility
} // namespace ece

#endif // CLASS_MATCHER_HPP
