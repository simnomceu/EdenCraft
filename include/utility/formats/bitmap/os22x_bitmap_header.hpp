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

#ifndef OS22X_BITMAP_HEADER_HPP
#define OS22X_BITMAP_HEADER_HPP

#include "utility/config.hpp"
#include "utility/pch.hpp"

namespace ece
{
	namespace utility
	{
		namespace formats
		{
			namespace bitmap
			{
				struct OS22XBitmapHeader
				{
					std::uint32_t size;
					std::uint32_t width;
					std::uint32_t height;
					std::uint16_t planes;
					std::uint16_t bpp;
					std::uint32_t compression;
					std::uint32_t imageSize;
					std::uint32_t xResolution;
					std::uint32_t yResolution;
					std::uint32_t numberOfColorsUsed;
					std::uint32_t numberOfImportantColors; 
					std::uint16_t resolutionUnit;
					std::uint16_t reserved;         /* Pad structure to 4-byte boundary */
					std::uint16_t recordingAlgorithm;        /* Recording algorithm */
					std::uint16_t halftoningAlgorithm;        /* Halftoning algorithm used */
					std::uint32_t halftoningsize1;            /* Reserved for halftoning algorithm use */
					std::uint32_t halftoningSize2;            /* Reserved for halftoning algorithm use */
					std::uint32_t colorEncoding;    /* Color model used in bitmap */
					std::uint32_t identifier;       /* Reserved for application use */
				};
			} // namespace bitmap
		} // namespace formats
	} // namespace utility
} // namespace ece

#endif // OS22X_BITMAP_HEADER_HPP