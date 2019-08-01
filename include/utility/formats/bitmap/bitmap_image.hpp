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

#ifndef BITMAP_IMAGE_HPP
#define BITMAP_IMAGE_HPP

#include "utility/config.hpp"
#include "utility/pch.hpp"
#include "utility/formats/bitmap/bmp_header.hpp"
#include "utility/formats/bitmap/dib_header.hpp"
#include "utility/formats/bitmap/color_table.hpp"
#include "utility/indexing.hpp"

namespace ece
{
	namespace utility
	{
		namespace formats
		{
			namespace bitmap
			{
				struct ECE_UTILITY_API BitmapImage
				{
					BMPHeader header;
					DIBHeader dib;
					std::shared_ptr<ColorTable> colors;
					Dynamic2DArray<std::array<std::uint8_t, 3>> pixels;

					bool isValid() const;
				};
				static constexpr float INCH_IN_CM = 2.54f;
				static constexpr float DPI_MAX = 1200.0f;

				template <class T>
				ECE_UTILITY_API inline float PPMToDPI(T ppm) { return ppm * INCH_IN_CM / 100.0f; }
			} // namespace bitmap
		} // namespace formats
	} // namespace utility
} // namespace ece

#endif // BITMAP_IMAGE_HPP