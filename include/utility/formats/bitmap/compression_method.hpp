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

#ifndef COMPRESSION_METHOD_HPP
#define COMPRESSION_METHOD_HPP

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
				enum class CompressionMethod
				{
					RGB = 0,
					RLE8 = 1,
					RLE4 = 2,
					BITFIELDS = 3, // Huffman 1D
					JPEG = 4, // RLE24
					PNG = 5,
					ALPHABITFIELDS = 6,
					CMYK = 11,
					CMYKRLE8 = 12,
					CMYKRLE4 = 13
				};

				class DIBHeader;

				ECE_UTILITY_API std::string to_string(CompressionMethod method);

				ECE_UTILITY_API std::vector<std::uint8_t> compress(std::vector<std::uint8_t> uncompressed, DIBHeader & header);
				ECE_UTILITY_API std::vector<std::uint8_t> uncompress(std::vector<std::uint8_t> compressed, DIBHeader & header);

				ECE_UTILITY_API std::vector<std::uint8_t> compressRLE8(std::vector<std::uint8_t> uncompressed, std::size_t width);
				ECE_UTILITY_API std::vector<std::uint8_t> compressRLE4(std::vector<std::uint8_t> uncompressed, std::size_t width);
				ECE_UTILITY_API std::vector<std::uint8_t> compressBitfields(std::vector<std::uint8_t> uncompressed, DIBHeader & header);
				ECE_UTILITY_API std::vector<std::uint8_t> compressJPEG(std::vector<std::uint8_t> uncompressed, std::size_t width);
				ECE_UTILITY_API std::vector<std::uint8_t> compressPNG(std::vector<std::uint8_t> uncompressed, std::size_t width);
				ECE_UTILITY_API std::vector<std::uint8_t> compressAlphaBitfields(std::vector<std::uint8_t> uncompressed, DIBHeader & header);

				ECE_UTILITY_API std::vector<std::uint8_t> decompressBitfields(std::vector<std::uint8_t> compressed, DIBHeader & header);
				ECE_UTILITY_API std::vector<std::uint8_t> decompressJPEG(std::vector<std::uint8_t> compressed, std::size_t width);
				ECE_UTILITY_API std::vector<std::uint8_t> decompressPNG(std::vector<std::uint8_t> compressed, std::size_t width);
				ECE_UTILITY_API std::vector<std::uint8_t> decompressAlphaBitfields(std::vector<std::uint8_t> compressed, DIBHeader & header);

				// TODO: Implementing Huffman 1D/PNG encoding/decoding algorithm.
			} // namespace bitmap
		} // namespace formats
	} // namespace utility
} // namespace ece

#endif // COMPRESSION_METHOD_HPP
