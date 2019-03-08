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

#ifndef BMP_HEADER_HPP
#define BMP_HEADER_HPP

#include "utility/config.hpp"
#include "utility/pch.hpp"
#include "utility/formats/bitmap/bitmap_signature.hpp"
#include "utility/types.hpp"

namespace ece
{
	namespace utility
	{
		namespace formats
		{
			namespace bitmap
			{
				/**
				 * @struct BMPHeader
				 * @brief The header of a BMP file according to the file format specification.
				 */
				struct ECE_UTILITY_API BMPHeader
				{
					BitmapSignature signature;
					ece::size_t size;
					std::array<std::uint32_t, 2> reserved;
					ece::offset_t pixelsOffset;

					ECE_UTILITY_API friend std::istream & operator>>(std::istream & stream, BMPHeader & header);

					ECE_UTILITY_API friend std::ostream & operator<<(std::ostream & stream, BMPHeader & header);

					static const std::size_t INTERNAL_SIZE;
				};
			} // namespace bitmap
		} // namespace formats
	} // namespace utility
} // namespace ece

#endif // BMP_HEADER_HPP