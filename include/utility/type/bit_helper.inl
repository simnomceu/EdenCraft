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

#include "utility/debug.hpp"

namespace ece
{
	namespace utility
	{
		namespace type
		{
			template <class T, std::size_t I, typename enabled> bool get1(T & data)
			{
				return (bool)((data >> I) & 1u);
			}

			template <class T, std::size_t I, typename enabled> void set1(T & data, bool value)
			{
				data = (data & ~(1u << I)) | (value << I);
			}

			template <class T, std::size_t I, typename enabled> std::uint8_t get2(T & data)
			{
				return ((data >> I * 2) & 0b11);
			}

			template <class T, std::size_t I, typename enabled> void set2(T & data, std::uint8_t value)
			{
				ece_assert(value <= 0b11, "The bit value is too big for its memory storage.");
				data = static_cast<T>((data & ~(0b11 << I * 2)) | (value << I * 2));
			}

			template <class T, std::size_t I, typename enabled> std::uint8_t get4(T & data)
			{
				return ((data >> I * 4) & 0b1111);
			}

			template <class T, std::size_t I, typename enabled> void set4(T & data, std::uint8_t value)
			{
				ece_assert(value <= 0b1111, "The bit value is too big for its memory storage.");
				data = static_cast<T>((data & ~(0b1111 << I * 4)) | (value << I * 4));
			}

			inline std::size_t bitcount(std::uint8_t value) { return std::bitset<32>(value).count(); }

			inline std::size_t bitPosition(std::uint8_t value) { return bitcount((value & (~value + 1)) - 1); }

			inline unsigned int bitMask(unsigned int color, std::uint8_t mask) { return (color & mask) >> bitPosition(mask); }

			inline unsigned int mask(std::size_t bitcount) { return (bitcount == 32) ? 0xFFFFFFFF : (1 << bitcount) - 1; }

			inline unsigned int convertBitCount(unsigned int value, std::size_t origin, std::size_t target)
			{
				if (target < origin) {
					return (value >> (origin - target));
				}
				else {
					auto result = static_cast<std::uint8_t>(value << (target - origin));
					if (result > 0) {
						result |= mask(target - origin);
					}
					return result;
				}
			}
		} // namespace type
	} // namespace utility
} // namespace ece