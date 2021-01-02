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
#include "utility/algorithm.hpp"

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

				std::vector<std::uint8_t> compress(std::vector<std::uint8_t> uncompressed, DIBHeader & header)
				{
					switch (header.compression)
					{
					case CompressionMethod::RGB: return uncompressed; break;
					case CompressionMethod::RLE8: return compressRLE8(uncompressed, header.width); break;
					case CompressionMethod::RLE4: return compressRLE4(uncompressed, header.width); break; //should_be std::uint4_t
					case CompressionMethod::BITFIELDS: return compressBitfields(uncompressed, header); break;
					case CompressionMethod::JPEG: return compressJPEG(uncompressed, header.width); break;
					case CompressionMethod::PNG: return compressPNG(uncompressed, header.width); break;
					case CompressionMethod::ALPHABITFIELDS: return compressAlphaBitfields(uncompressed, header); break;
					case CompressionMethod::CMYK: return uncompressed; break;
					case CompressionMethod::CMYKRLE8: return compressRLE8(uncompressed, header.width); break;
					case CompressionMethod::CMYKRLE4: return compressRLE4(uncompressed, header.width); break;
					default: throw std::runtime_error("Undefined bitmap compression method."); break;
					}
				}

				std::vector<std::uint8_t> uncompress(std::vector<std::uint8_t> compressed, DIBHeader & header)
				{
					auto tmp = std::vector<std::uint8_t>();
					if (header.compression == CompressionMethod::RGB || header.compression == CompressionMethod::CMYK) {
						if (header.bitCount == 1) {
							for (auto & e : compressed) {
								tmp.push_back(get1<std::uint8_t, 7>(e));
								tmp.push_back(get1<std::uint8_t, 6>(e));
								tmp.push_back(get1<std::uint8_t, 5>(e));
								tmp.push_back(get1<std::uint8_t, 4>(e));
								tmp.push_back(get1<std::uint8_t, 3>(e));
								tmp.push_back(get1<std::uint8_t, 2>(e));
								tmp.push_back(get1<std::uint8_t, 1>(e));
								tmp.push_back(get1<std::uint8_t, 0>(e));
							}
						}
						else if (header.bitCount == 2) {
							for (auto & e : compressed) {
								tmp.push_back(get2<std::uint8_t, 3>(e));
								tmp.push_back(get2<std::uint8_t, 2>(e));
								tmp.push_back(get2<std::uint8_t, 1>(e));
								tmp.push_back(get2<std::uint8_t, 0>(e));
							}
						}
						else if (header.bitCount == 4) {
							if (header.compression == CompressionMethod::RGB || header.compression == CompressionMethod::CMYK) {
								for (auto & e : compressed) {
									tmp.push_back(get4<std::uint8_t, 1>(e));
									tmp.push_back(get4<std::uint8_t, 0>(e));
								}
							}
							else {
								tmp = compressed;
							}
						}
						else {
							tmp = compressed;
						}
					}
					else {
						tmp = compressed;
					}

				/*	if (header.compression == CompressionMethod::RGB || header.compression == CompressionMethod::CMYK) {
						if (tmp.size() > header.imageSize) {
							tmp.resize(header.width * header.height);
						}
					}*/

					switch (header.compression)
					{
					case CompressionMethod::RGB: return tmp; break;
					case CompressionMethod::RLE8: return uncompressRLE8(tmp, header.width, header.height); break;
					case CompressionMethod::RLE4: return uncompressRLE4(tmp, header.width, header.height); break;
					case CompressionMethod::BITFIELDS: return decompressBitfields(tmp, header); break;
					case CompressionMethod::JPEG: return decompressJPEG(tmp, header.width); break;
					case CompressionMethod::PNG: return decompressPNG(tmp, header.width); break;
					case CompressionMethod::ALPHABITFIELDS: return decompressAlphaBitfields(tmp, header); break;
					case CompressionMethod::CMYK: return tmp; break;
					case CompressionMethod::CMYKRLE8: return uncompressRLE8(tmp, header.width, header.height); break;
					case CompressionMethod::CMYKRLE4: return uncompressRLE4(tmp, header.width, header.height); break;
					default: throw std::runtime_error("Undefined bitmap uncompression method."); break;
					}
				}

				std::vector<std::uint8_t> compressRLE8(std::vector<std::uint8_t> uncompressed, std::size_t width)
				{
					auto result = std::vector<std::uint8_t>();

					auto it = uncompressed.begin();
					auto xPos = 0;
					auto count = 0;
					while (it != uncompressed.end()) {
						count = 0;
						while (*(it + count) == *(it + count + 1) && count < std::numeric_limits<char>::max()) {
							++count;
						}
						count = std::min(count, static_cast<int>(width) - xPos);
						if (count > 1) {
							result.emplace_back(static_cast<std::uint8_t>(count));
							result.emplace_back(*it);
						}
						else {
							result.emplace_back(static_cast<std::uint8_t>(0));
							result.emplace_back(*it);
						}
						it += count;
						xPos += count;
						if (xPos >= static_cast<int>(width)) {
							result.emplace_back(static_cast<std::uint8_t>(0));
							result.emplace_back(static_cast<std::uint8_t>(0));
							xPos = 0;
						}
					}
					result.emplace_back(static_cast<std::uint8_t>(0));
					result.emplace_back(static_cast<std::uint8_t>(1));
					return result;
				}


				std::vector<std::uint8_t> compressRLE4(std::vector<std::uint8_t> uncompressed, std::size_t width)
				{
					auto result = std::vector<std::uint8_t>();

					auto it = uncompressed.begin();
					auto xPos = 0;
					auto count = 0;
					while (it != uncompressed.end()) {
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
							result.emplace_back(static_cast<std::uint8_t>(count));
							result.emplace_back(color);
						}
						else {
							result.emplace_back(static_cast<std::uint8_t>(0));
							result.emplace_back(color);
						}
						it += count;
						xPos += count;
						if (xPos >= static_cast<int>(width)) {
							result.emplace_back(static_cast<std::uint8_t>(0));
							result.emplace_back(static_cast<std::uint8_t>(0));
							xPos = 0;
						}
					}
					result.emplace_back(static_cast<std::uint8_t>(0));
					result.emplace_back(static_cast<std::uint8_t>(1));
					return result;
				}

				std::vector<std::uint8_t> compressBitfields(std::vector<std::uint8_t> uncompressed, DIBHeader & header)
				{
					auto mask = std::get<RGB24>(header.mask);
					auto redBitcount = bitcount(mask.r);
					auto greenBitcount = bitcount(mask.g);
					auto blueBitcount = bitcount(mask.b);

					auto result = std::vector<std::uint8_t>();
					auto it = uncompressed.begin();
					for (auto i = std::int32_t{ 0 }; i < header.height; ++i) {
						for (auto j = std::int32_t{ 0 }; j < header.width; ++j) {
							result.push_back(static_cast<std::uint8_t>(convertBitCount(bitMask(*it, mask.r), 8, redBitcount)));
							result.push_back(static_cast<std::uint8_t>(convertBitCount(bitMask(*it, mask.g), 8, greenBitcount)));
							result.push_back(static_cast<std::uint8_t>(convertBitCount(bitMask(*it, mask.b), 8, blueBitcount)));
							++it;
						}
					}

					return result;
				}

				std::vector<std::uint8_t> compressJPEG(std::vector<std::uint8_t> /*uncompressed*/, std::size_t /*width*/)
				{
					throw std::runtime_error("Huffman 1D encoding has not been implemented yet.");
				}

				std::vector<std::uint8_t> compressPNG(std::vector<std::uint8_t> /*uncompressed*/, std::size_t /*width*/)
				{
					throw std::runtime_error("PNG encoding has not been implemented yet.");
				}

				std::vector<std::uint8_t> compressAlphaBitfields(std::vector<std::uint8_t> uncompressed, DIBHeader & header)
				{
					auto mask = std::get<RGBA32>(header.mask);
					auto redBitcount = bitcount(mask.r);
					auto greenBitcount = bitcount(mask.g);
					auto blueBitcount = bitcount(mask.b);
					auto alphaBitcount = bitcount(mask.a);

					auto result = std::vector<std::uint8_t>();
					auto it = uncompressed.begin();
					for (auto i = std::int32_t{ 0 }; i < header.height; ++i) {
						for (auto j = std::int32_t{ 0 }; j < header.width; ++j) {
							result.push_back(static_cast<std::uint8_t>(convertBitCount(bitMask(*it, mask.r), 8, redBitcount)));
							result.push_back(static_cast<std::uint8_t>(convertBitCount(bitMask(*it, mask.g), 8, greenBitcount)));
							result.push_back(static_cast<std::uint8_t>(convertBitCount(bitMask(*it, mask.b), 8, blueBitcount)));
							result.push_back(static_cast<std::uint8_t>(convertBitCount(bitMask(*it, mask.a), 8, alphaBitcount)));
							++it;
						}
					}

					return result;
				}

				std::vector<std::uint8_t> decompressBitfields(std::vector<std::uint8_t> compressed, DIBHeader & header)
				{
					auto mask = RGB24{};
					if (std::holds_alternative<RGB24>(header.mask)) {
						mask = std::get<RGB24>(header.mask);
					}
					else {
						auto tmp = std::get<RGBA32>(header.mask);
						mask = { tmp.r, tmp.g, tmp.b };
					}

					auto result = std::vector<std::uint8_t>();
					auto it = compressed.begin();
					for (auto i = std::int32_t{ 0 }; i < header.height; ++i) {
						for (auto j = std::int32_t{ 0 }; j < header.width; ++j) {
							result.push_back(static_cast<std::uint8_t>(convertBitCount(bitMask(*it, mask.r), bitcount(mask.r), 8)));
							result.push_back(static_cast<std::uint8_t>(convertBitCount(bitMask(*it, mask.g), bitcount(mask.g), 8)));
							result.push_back(static_cast<std::uint8_t>(convertBitCount(bitMask(*it, mask.b), bitcount(mask.b), 8)));
							++it;
						}
					}

					return result;
				}

				std::vector<std::uint8_t> decompressJPEG([[maybe_unused]] std::vector<std::uint8_t> compressed, std::size_t /*width*/)
				{
					throw std::runtime_error("Huffman 1D decoding has not been implemented yet.");
				}

				std::vector<std::uint8_t> decompressPNG([[maybe_unused]] std::vector<std::uint8_t> compressed, std::size_t /*width*/)
				{
					throw std::runtime_error("PNG decoding has not been implemented yet.");
				}

				std::vector<std::uint8_t> decompressAlphaBitfields(std::vector<std::uint8_t> compressed, DIBHeader & header)
				{
					auto mask = std::get<RGBA32>(header.mask);
					auto redBitcount = bitcount(mask.r);
					auto greenBitcount = bitcount(mask.g);
					auto blueBitcount = bitcount(mask.b);
					auto alphaBitcount = bitcount(mask.a);

					auto result = std::vector<std::uint8_t>();
					auto it = compressed.begin();
					for (auto i = std::int32_t{ 0 }; i < header.height; ++i) {
						for (auto j = std::int32_t{ 0 }; j < header.width; ++j) {
							result.push_back(static_cast<std::uint8_t>(convertBitCount(bitMask(*it, mask.r), redBitcount, 8)));
							result.push_back(static_cast<std::uint8_t>(convertBitCount(bitMask(*it, mask.g), greenBitcount, 8)));
							result.push_back(static_cast<std::uint8_t>(convertBitCount(bitMask(*it, mask.b), blueBitcount, 8)));
							result.push_back(static_cast<std::uint8_t>(convertBitCount(bitMask(*it, mask.a), alphaBitcount, 8)));
							++it;
						}
					}

					return result;
				}
			} // namespace bitmap
		} // namespace formats
	} // namespace utility
} // namespace ece
