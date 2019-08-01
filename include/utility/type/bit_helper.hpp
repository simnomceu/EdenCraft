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

#ifndef BIT_HELPER_HPP
#define BIT_HELPER_HPP

#include "utility/config.hpp"
#include "utility/pch.hpp"

namespace ece
{
	namespace utility
	{
		namespace type
		{
			template <class T, std::size_t I, typename enabled = std::enable_if_t<(I < sizeof(T) * 8)>> bool get1(T & data);
			template <class T, std::size_t I, typename enabled = std::enable_if_t<(I < sizeof(T) * 8)>> void set1(T & data, bool value);

			template <class T, std::size_t I, typename enabled = std::enable_if_t<(I * 2 < sizeof(T) * 8)>> std::uint8_t get2(T & data);
			template <class T, std::size_t I, typename enabled = std::enable_if_t<(I * 2 < sizeof(T) * 8)>> void set2(T & data, std::uint8_t value);

			template <class T, std::size_t I, typename enabled = std::enable_if_t<(I * 4 < sizeof(T) * 8)>> std::uint8_t get4(T & data);
			template <class T, std::size_t I, typename enabled = std::enable_if_t<(I * 4 < sizeof(T) * 8)>> void set4(T & data, std::uint8_t value);

			inline std::size_t bitcount(unsigned int value);
			inline std::size_t bitPosition(unsigned int value);
			inline unsigned int bitMask(unsigned int color, unsigned int mask);
			unsigned int mask(unsigned int bitcount);
			inline unsigned int convertBitCount(unsigned int value, unsigned int origin, unsigned int target);
		} // namespace type
	} // namespace utility
} // namespace ece

#include "utility/type/bit_helper.inl"

#endif // BIT_HELPER_HPP