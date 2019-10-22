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

#include "utility/pch.hpp"
#include "utility/formats/bitmap/compression_method.hpp"
#include "utility/types.hpp"
#include "utility/formats/bitmap/dib_header.hpp"

#ifdef _MSC_VER
#	undef min
#	undef max
#endif

namespace ece
{
	namespace utility
	{
		namespace formats
		{
			namespace bitmap
			{
				std::string to_string(CompressionMethod method)
				{
					switch (method) {
					case CompressionMethod::RGB: return "RGB"; break;
					case CompressionMethod::RLE8: return "RLE8";  break;
					case CompressionMethod::RLE4: return "RLE4"; break;
					case CompressionMethod::BITFIELDS: return "BITFIELDS"; break;
					case CompressionMethod::JPEG: return "JPEG"; break;
					case CompressionMethod::PNG: return "PNG"; break;
					case CompressionMethod::ALPHABITFIELDS: return "ALPHABITFIELDS"; break;
					case CompressionMethod::CMYK: return "CMYK"; break;
					case CompressionMethod::CMYKRLE8: return "CMYKRLE8"; break;
					case CompressionMethod::CMYKRLE4: return "CMYKRLE4"; break;
					default: throw std::runtime_error("Unknown value for CompressionMethod enumeration."); break;
					}
				}

				std::vector<char> compress(typename std::vector<char>::iterator begin, typename std::vector<char>::iterator end, DIBHeader & header)
				{
					switch (header.compression)
					{
					case CompressionMethod::RGB: return { begin, end }; break;
					case CompressionMethod::RLE8: return compressRLE8(begin, end, header.width); break;
					case CompressionMethod::RLE4: return compressRLE4(begin, end, header.width); break; //should_be std::uint4_t
					case CompressionMethod::BITFIELDS: return compressBitfields(begin, end, header); break;
					case CompressionMethod::JPEG: return compressJPEG(begin, end, header.width); break;
					case CompressionMethod::PNG: return compressPNG(begin, end, header.width); break;
					case CompressionMethod::ALPHABITFIELDS: return compressAlphaBitfields(begin, end, header); break;
					case CompressionMethod::CMYK: return { begin, end }; break;
					case CompressionMethod::CMYKRLE8: return compressRLE8(begin, end, header.width); break;
					case CompressionMethod::CMYKRLE4: return compressRLE4(begin, end, header.width); break;
					default: throw std::runtime_error("Undefined bitmap compression method."); break;
					}
				}

				std::vector<char> uncompress(typename std::vector<char>::iterator begin, typename std::vector<char>::iterator end, DIBHeader & header)
				{
					switch (header.compression)
					{
					case CompressionMethod::RGB: return { begin, end }; break;
					case CompressionMethod::RLE8: return decompressRLE8(begin, end, header.width); break;
					case CompressionMethod::RLE4: return decompressRLE4(begin, end, header.width); break;
					case CompressionMethod::BITFIELDS: return decompressBitfields(begin, end, header); break;
					case CompressionMethod::JPEG: return decompressJPEG(begin, end, header.width); break;
					case CompressionMethod::PNG: return decompressPNG(begin, end, header.width); break;
					case CompressionMethod::ALPHABITFIELDS: return decompressAlphaBitfields(begin, end, header); break;
					case CompressionMethod::CMYK: return { begin, end }; break;
					case CompressionMethod::CMYKRLE8: return decompressRLE8(begin, end, header.width); break;
					case CompressionMethod::CMYKRLE4: return decompressRLE4(begin, end, header.width); break;
					default: throw std::runtime_error("Undefined bitmap uncompression method."); break;
					}
				}

				std::vector<char> compressRLE8(std::vector<char>::iterator begin, std::vector<char>::iterator end, std::size_t width)
				{
					auto result = std::vector<char>();

					auto it = begin;
					auto xPos = 0;
					auto count = 0;
					while (it != end) {
						count = 0;
						while (*(it + count) == *(it + count + 1) && count < std::numeric_limits<char>::max()) {
							++count;
						}
						count = std::min(count, static_cast<int>(width) - xPos);
						if (count > 1) {
							result.emplace_back(static_cast<char>(count));
							result.emplace_back(*it);
						}
						else {
							result.emplace_back(static_cast<char>(0));
							result.emplace_back(*it);
						}
						it += count;
						xPos += count;
						if (xPos >= static_cast<int>(width)) {
							result.emplace_back(static_cast<char>(0));
							result.emplace_back(static_cast<char>(0));
							xPos = 0;
						}
					}
					result.emplace_back(static_cast<char>(0));
					result.emplace_back(static_cast<char>(1));
					return result;
				}


				std::vector<char> compressRLE4(typename std::vector<char>::iterator begin, typename std::vector<char>::iterator end, std::size_t width)
				{
					auto result = std::vector<char>();

					auto it = begin;
					auto xPos = 0;
					auto count = 0;
					while (it != end) {
						count = 2;
						while (*it == *(it + count) && *(it + 1) == *(it + count + 1) && count < std::numeric_limits<char>::max()) {
							count+=2;
						}

						const auto firstColor = *it;
						const auto secondColor = *(it + 1);
						char color = 0;
						set4<char, 0>(color, firstColor);
						set4<char, 1>(color, secondColor);

						count = std::min(count, static_cast<int>(width) - xPos);
						if (count > 1) {
							result.emplace_back(static_cast<char>(count));
							result.emplace_back(color);
						}
						else {
							result.emplace_back(static_cast<char>(0));
							result.emplace_back(color);
						}
						it += count;
						xPos += count;
						if (xPos >= static_cast<int>(width)) {
							result.emplace_back(static_cast<char>(0));
							result.emplace_back(static_cast<char>(0));
							xPos = 0;
						}
					}
					result.emplace_back(static_cast<char>(0));
					result.emplace_back(static_cast<char>(1));
					return result;
				}

				std::vector<char> compressBitfields(std::vector<char>::iterator begin, [[maybe_unused]] std::vector<char>::iterator end, DIBHeader & header)
				{
					auto mask = std::get<RGB<std::size_t>>(header.mask);
					auto redBitcount = bitcount(static_cast<unsigned int>(mask.r));
					auto greenBitcount = bitcount(static_cast<unsigned int>(mask.g));
					auto blueBitcount = bitcount(static_cast<unsigned int>(mask.b));

					auto result = std::vector<char>();
					auto it = begin;
					for (auto i = std::size_t{ 0 }; i < header.height; ++i) {
						for (auto j = std::size_t{ 0 }; j < header.width; ++j) {
							result.push_back(static_cast<char>(convertBitCount(bitMask(static_cast<unsigned int>(*it), static_cast<unsigned int>(mask.r)), 8, static_cast<unsigned int>(redBitcount))));
							result.push_back(static_cast<char>(convertBitCount(bitMask(static_cast<unsigned int>(*it), static_cast<unsigned int>(mask.g)), 8, static_cast<unsigned int>(greenBitcount))));
							result.push_back(static_cast<char>(convertBitCount(bitMask(static_cast<unsigned int>(*it), static_cast<unsigned int>(mask.b)), 8, static_cast<unsigned int>(blueBitcount))));
							++it;
						}
					}

					return result;
				}

				std::vector<char> compressJPEG(std::vector<char>::iterator /*begin*/, std::vector<char>::iterator /*end*/, std::size_t /*width*/)
				{
					return {};
				}

				std::vector<char> compressPNG(std::vector<char>::iterator /*begin*/, std::vector<char>::iterator /*end*/, std::size_t /*width*/)
				{
					return {};
				}

				std::vector<char> compressAlphaBitfields(std::vector<char>::iterator begin, [[maybe_unused]] std::vector<char>::iterator end, DIBHeader & header)
				{
					auto mask = std::get<RGBA<std::size_t>>(header.mask);
					auto redBitcount = bitcount(static_cast<unsigned int>(mask.r));
					auto greenBitcount = bitcount(static_cast<unsigned int>(mask.g));
					auto blueBitcount = bitcount(static_cast<unsigned int>(mask.b));
					auto alphaBitcount = bitcount(static_cast<unsigned int>(mask.a));

					auto result = std::vector<char>();
					auto it = begin;
					for (auto i = std::size_t{ 0 }; i < header.height; ++i) {
						for (auto j = std::size_t{ 0 }; j < header.width; ++j) {
							result.push_back(static_cast<char>(convertBitCount(bitMask(static_cast<unsigned int>(*it), static_cast<unsigned int>(mask.r)), 8, static_cast<unsigned int>(redBitcount))));
							result.push_back(static_cast<char>(convertBitCount(bitMask(static_cast<unsigned int>(*it), static_cast<unsigned int>(mask.g)), 8, static_cast<unsigned int>(greenBitcount))));
							result.push_back(static_cast<char>(convertBitCount(bitMask(static_cast<unsigned int>(*it), static_cast<unsigned int>(mask.b)), 8, static_cast<unsigned int>(blueBitcount))));
							result.push_back(static_cast<char>(convertBitCount(bitMask(static_cast<unsigned int>(*it), static_cast<unsigned int>(mask.a)), 8, static_cast<unsigned int>(alphaBitcount))));
							++it;
						}
					}

					return result;
				}

				std::vector<char> decompressRLE8(std::vector<char>::iterator begin, std::vector<char>::iterator end, std::size_t width)
				{
					auto result = std::vector<char>();
					auto it = begin;
					int xPos = 0;
					while (it != end) {
						if (*it == 0) { // absolute mode
							++it;
							if (*it == 0) { // end of line
								result.insert(result.end(), width - xPos, 0);
								xPos = 0;
							}
							else if (*it == 1) { // end of bitmap
								it = end;
							}
							else if (*it == 2) { // delta jump
								++it;
								const int x = *it;
								++it;
								const int y = *it;
								it += (y * width) + x;
								result.insert(result.end(), (y * width) + x, 0);
								xPos += x;
							}
							else {
								const int count = *it;
								++it;
								result.insert(result.end(), it, it + count);
								it += count;
								xPos += count;
							}
						}
						else { // encoded mode
							const int count = *it;
							++it;
							result.insert(result.end(), count, *it);
							++it;
							xPos += count;
						}
					}
					return result;
				}

				std::vector<char> decompressRLE4(std::vector<char>::iterator begin, std::vector<char>::iterator end, std::size_t width)
				{
					auto result = std::vector<char>();
					auto it = begin;
					int xPos = 0;
					while (it != end) {
						if (*it == 0) { // absolute mode
							++it;
							if (*it == 0) { // end of line
								result.insert(result.end(), width - xPos, 0);
								xPos = 0;
							}
							else if (*it == 1) { // end of bitmap
								it = end;
							}
							else if (*it == 2) { // delta jump
								++it;
								const int x = *it;
								++it;
								const int y = *it;
								it += (y * width) + x;
								xPos += x;
							}
							else {
								const int count = *it;
								++it;
								for (int i = 0; i < count; ++i) {
									result.push_back(static_cast<char>(get4<char, 0>(*it)));
									result.push_back(static_cast<char>(get4<char, 1>(*it)));
									++it;
								}
								xPos += count;
							}
						}
						else { // encoded mode
							const int count = *it;
							++it;
							const int firstColor = get4<char, 0>(*it);
							const int secondColor = get4<char, 1>(*it);
							for (int i = 0; i < count; ++i) {
								if (i % 2 == 0) {
									result.push_back(static_cast<char>(firstColor));
								}
								else {
									result.push_back(static_cast<char>(secondColor));
								}
							}
							++it;
						}
					}
					return result;
				}

				std::vector<char> decompressBitfields(std::vector<char>::iterator begin, [[maybe_unused]] std::vector<char>::iterator end, DIBHeader & header)
				{
					auto mask = std::get<RGB<std::size_t>>(header.mask);
					auto redBitcount = bitcount(static_cast<unsigned int>(mask.r));
					auto greenBitcount = bitcount(static_cast<unsigned int>(mask.g));
					auto blueBitcount = bitcount(static_cast<unsigned int>(mask.b));

					auto result = std::vector<char>();
					auto it = begin;
					for (auto i = std::size_t{ 0 }; i < header.height; ++i) {
						for (auto j = std::size_t{ 0 }; j < header.width; ++j) {
							result.push_back(static_cast<char>(convertBitCount(bitMask(static_cast<unsigned int>(*it), static_cast<unsigned int>(mask.r)), static_cast<unsigned int>(redBitcount), 8)));
							result.push_back(static_cast<char>(convertBitCount(bitMask(static_cast<unsigned int>(*it), static_cast<unsigned int>(mask.g)), static_cast<unsigned int>(greenBitcount), 8)));
							result.push_back(static_cast<char>(convertBitCount(bitMask(static_cast<unsigned int>(*it), static_cast<unsigned int>(mask.b)), static_cast<unsigned int>(blueBitcount), 8)));
							++it;
						}
					}

					return result;
				}

				std::vector<char> decompressJPEG(std::vector<char>::iterator /*begin*/, std::vector<char>::iterator /*end*/, std::size_t /*width*/)
				{
					return {};
				}

				std::vector<char> decompressPNG(std::vector<char>::iterator /*begin*/, std::vector<char>::iterator /*end*/, std::size_t /*width*/)
				{
					return {};
				}

				std::vector<char> decompressAlphaBitfields(std::vector<char>::iterator begin, [[maybe_unused]] std::vector<char>::iterator end, DIBHeader & header)
				{
					auto mask = std::get<RGBA<std::size_t>>(header.mask);
					auto redBitcount = bitcount(static_cast<unsigned int>(mask.r));
					auto greenBitcount = bitcount(static_cast<unsigned int>(mask.g));
					auto blueBitcount = bitcount(static_cast<unsigned int>(mask.b));
					auto alphaBitcount = bitcount(static_cast<unsigned int>(mask.a));

					auto result = std::vector<char>();
					auto it = begin;
					for (auto i = std::size_t{ 0 }; i < header.height; ++i) {
						for (auto j = std::size_t{ 0 }; j < header.width; ++j) {
							result.push_back(static_cast<char>(convertBitCount(bitMask(static_cast<unsigned int>(*it), static_cast<unsigned int>(mask.r)), static_cast<unsigned int>(redBitcount), 8)));
							result.push_back(static_cast<char>(convertBitCount(bitMask(static_cast<unsigned int>(*it), static_cast<unsigned int>(mask.g)), static_cast<unsigned int>(greenBitcount), 8)));
							result.push_back(static_cast<char>(convertBitCount(bitMask(static_cast<unsigned int>(*it), static_cast<unsigned int>(mask.b)), static_cast<unsigned int>(blueBitcount), 8)));
							result.push_back(static_cast<char>(convertBitCount(bitMask(static_cast<unsigned int>(*it), static_cast<unsigned int>(mask.a)), static_cast<unsigned int>(alphaBitcount), 8)));
							++it;
						}
					}

					return result;
				}
			} // namespace bitmap
		} // namespace formats
	} // namespace utility
} // namespace ece
