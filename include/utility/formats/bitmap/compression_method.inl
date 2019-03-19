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

#include "utility/types.hpp"

namespace ece
{
	namespace utility
	{
		namespace formats
		{
			namespace bitmap
			{
				template <class T>
				std::vector<T> compress(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator end, std::size_t width, CompressionMethod method)
				{
					switch (method)
					{
					case CompressionMethod::RGB: return { begin, end }; break;
					case CompressionMethod::RLE8: return compressRLE<std::uint8_t>(begin, end, width): break;
					case CompressionMethod::RLE4: return compressRLE<std::uint8_t>(begin, end, width) break; //should_be std::uint4_t
					case CompressionMethod::BITFIELDS: return compressRLE<bool>(begin, end, width); break;
					case CompressionMethod::JPEG: return compressJPEG(begin, end, width); break;
					case CompressionMethod::PNG: return compressPNG(begin, end, width); break;
					case CompressionMethod::ALPHABITFIELDS: return compressAlhaBitfields(begin, end, width); break;
					case CompressionMethod::CMYK: return compressCMYK(begin, end, width); break;
					case CompressionMethod::CMYKRLE8: return compressCMYKRLE8(begin, end, width); break;
					case CompressionMethod::CMYKRLE4: return compressCMYKRLE4(begin, end, width); break;
					default: break;
					}
				}

				template <class T>
				std::vector<T> uncompress(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator end, std::size_t width, CompressionMethod method)
				{
					switch (method)
					{
					case CompressionMethod::RGB: return { begin, end }; break;
					case CompressionMethod::RLE8: return decompressRLE8<char>(begin, end, width) : break;
					case CompressionMethod::RLE4: return decompressRLE4<char>(begin, end, width) break;
					case CompressionMethod::BITFIELDS: return decompressRLE(begin, end); break;
					case CompressionMethod::JPEG: return decompressJPEG(begin, end); break;
					case CompressionMethod::PNG: return decompressPNG(begin, end); break;
					case CompressionMethod::ALPHABITFIELDS: return decompressAlhaBitfields(begin, end); break;
					case CompressionMethod::CMYK: return decompressCMYK(begin, end); break;
					case CompressionMethod::CMYKRLE8: return decompressCMYKRLE8(begin, end); break;
					case CompressionMethod::CMYKRLE4: return decompressCMYKRLE4(begin, end); break;
					default: break;
					}
				}

				inline std::vector<char> compressRLE8(std::vector<char>::iterator begin, std::vector<char>::iterator end, std::size_t width)
				{
					auto result = std::vector<char>();

					auto it = begin;
					while (it != end) {
						if (*it == 0) {
							++it;

						}
					}
				}

				inline std::vector<char> compressRLE4(std::vector<char>::iterator begin, std::vector<char>::iterator end, std::size_t width)
				{
				}

				template <class T>
				std::vector<T> compressBitfields(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator end, std::size_t width)
				{
				}

				template <class T>
				std::vector<T> compressJPEG(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator end, std::size_t width)
				{
				}

				template <class T>
				std::vector<T> compressPNG(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator end, std::size_t width)
				{
				}

				template <class T>
				std::vector<T> compressAlphaBitfields(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator end, std::size_t width)
				{
				}

				template <class T>
				std::vector<T> compressCMYK(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator end, std::size_t width)
				{
				}

				template <class T>
				std::vector<T> compressCMYKRLE8(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator end, std::size_t width)
				{
				}

				template <class T>
				std::vector<T> compressCMYKRLE4(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator end, std::size_t width)
				{
				}

				inline std::vector<char> decompressRLE8(std::vector<char>::iterator begin, std::vector<char>::iterator end, std::size_t width)
				{
					auto result = std::vector<char>();
					auto it = begin;
					int xPos = 0;
					while (it != end) {
						if (*it == 0) { // absolute mode
							++it;
							if (*it == 0) { // end of line
								result.insert(result.end(), width - xPos, 0);
							}
							else if (*it == 1) { // end of bitmap
								it == end;
							}
							else if (*it = 2) { // delta jump
								++it;
								const int x = *it;
								++it;
								const int y = *it;
								it += (y * width) + x;
								result.insert(result.end(), (y * width) + x, 0);
								xPos = 0;
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

				inline std::vector<char> decompressRLE4(std::vector<char>::iterator begin, std::vector<char>::iterator end, std::size_t width)
				{
					auto result = std::vector<char>();
					auto it = begin;
					while (it != end) {
						if (*it == 0) { // absolute mode
							++it;
							if (*it == 0) { // end of line
								// TODO
							}
							else if (*it == 1) { // end of bitmap
								it == end;
							}
							else if (*it = 2) { // delta jump
								++it;
								const int x = *it;
								++it;
								const int y = *it;
								it += (y * width) + x;
							}
							else {
								const int count = *it;
								++it;
								for (int i = 0; i < count; ++i) {
									result.push_back(get4<char, 0>(*it));
									result.push_back(get4<char, 1>(*it));
									++it;
								}
							}
						}
						else { // encoded mode
							const int count = *it;
							++it;
							const int firstColor = get4<char, 0>(*it);
							const int secondColor = get4<char, 1>(*it);
							for (int i = 0; i < count; ++i) {
								if (i % 2 == 0) {
									result.push_back(firstColor);
								}
								else {
									result.push_back(secondColor);
								}
							}
							++it;
						}
					}
					return result;
				}

				template <class T>
				std::vector<T> decompressBitfields(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator end, std::size_t width)
				{
				}

				template <class T>
				std::vector<T> decompressJPEG(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator end, std::size_t width)
				{
				}

				template <class T>
				std::vector<T> decompressPNG(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator end, std::size_t width)
				{
				}

				template <class T>
				std::vector<T> decompressAlphaBitfields(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator end, std::size_t width)
				{
				}

				template <class T>
				std::vector<T> decompressCMYK(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator end, std::size_t width)
				{
				}

				template <class T>
				std::vector<T> decompressCMYKRLE8(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator end, std::size_t width)
				{
				}

				template <class T>
				std::vector<T> decompressCMYKRLE4(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator end, std::size_t width)
				{
				}

			} // namespace bitmap
		} // namespace formats
	} // namespace utility
} // namespace ece