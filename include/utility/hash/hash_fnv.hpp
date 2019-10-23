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

#ifndef HASH_FNV_HPP
#define HASH_FNV_HPP

#include "utility/config.hpp"
#include "utility/pch.hpp"

namespace ece
{
	namespace utility
	{
		namespace hash
		{
			ECE_UTILITY_EXTERN constexpr std::uint32_t value32 = 0x811c9dc5;
			ECE_UTILITY_EXTERN constexpr std::uint32_t prime32 = 0x1000193;
			ECE_UTILITY_EXTERN constexpr std::uint64_t value64 = 0xcbf29ce484222325;
			ECE_UTILITY_EXTERN constexpr std::uint64_t prime64 = 0x100000001b3;

			ECE_UTILITY_API inline constexpr auto _hash32_fnv1a(const char * const str, const std::uint32_t value = value32) noexcept -> std::uint32_t;
			ECE_UTILITY_API inline constexpr auto _hash64_fnv1a(const char * const str, const std::uint64_t value = value64) noexcept -> std::uint64_t;

#			define hash32_fnv1a(A) \
				__pragma(warning(push)) \
				__pragma(warning(disable: 4307)) \
				ece::_hash32_fnv1a(A) \
				__pragma(warning(pop))

#			define hash64_fnv1a(A) \
				__pragma(warning(push)) \
				__pragma(warning(disable: 4307)) \
				ece::_hash64_fnv1a(A) \
				__pragma(warning(pop))

		} // namespace hash
	} // namespace utility
} // namespace ece

#include "utility/hash/hash_fnv.inl"

#endif // HASH_FNV_HPP