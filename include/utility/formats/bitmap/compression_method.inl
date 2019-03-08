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

namespace ece
{
	namespace utility
	{
		namespace formats
		{
			namespace bitmap
			{
				template <class T>
				std::vector<T> compress(std::vector<T>::iterator begin, std::vector<T>::iterator end, CompressionMethod method)
				{
					switch (method)
					{
					case CompressionMethod::RGB: return { begin, end }; break;
					case CompressionMethod::RLE8: return compressRLE<std::uint8_t>(begin, end): break;
					case CompressionMethod::RLE4: return compressRLE<std::uint8_t>(begin, end) break; //should_be std::uint4_t
					case CompressionMethod::BITFIELDS: return compressRLE<bool>(begin, end); break;
					case CompressionMethod::JPEG: return compressJPEG(begin, end); break;
					case CompressionMethod::PNG: return compressPNG(begin, end); break;
					case CompressionMethod::ALPHABITFIELDS: return compressAlhaBitfields(begin, end); break;
					case CompressionMethod::CMYK: return compressCMYK(begin, end); break;
					case CompressionMethod::CMYKRLE8: return compressCMYKRLE8(begin, end); break;
					case CompressionMethod::CMYKRLE4: return compressCMYKRLE4(begin, end); break;
					default: break;
					}
				}

				template <class T>
				std::vector<T> uncompress(std::vector<T>::iterator begin, std::vector<T>::iterator end, CompressionMethod method)
				{
					switch (method)
					{
					case CompressionMethod::RGB: return { begin, end }; break;
					case CompressionMethod::RLE8: return decompressRLE<std::uint8_t>(begin, end) : break;
					case CompressionMethod::RLE4: return decompressRLE<std::uint8_t>(begin, end) break;
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

				template <class T>
				std::vector<T> compressRLE8(std::vector<T>::iterator begin, std::vector<T>::iterator end)
				{
					auto result = std::vector<T>();

					auto iterator = begin;
					while (iterator < end) {
						if (*iterator == T(0)) {
							++iterator;

						}
					}
				}

				template <class T>
				std::vector<T> compressRLE4(std::vector<T>::iterator begin, std::vector<T>::iterator end)
				{
				}

				template <class T>
				std::vector<T> compressBitfields(std::vector<T>::iterator begin, std::vector<T>::iterator end)
				{
				}

				template <class T>
				std::vector<T> compressJPEG(std::vector<T>::iterator begin, std::vector<T>::iterator end)
				{
				}

				template <class T>
				std::vector<T> compressPNG(std::vector<T>::iterator begin, std::vector<T>::iterator end)
				{
				}

				template <class T>
				std::vector<T> compressAlphaBitfields(std::vector<T>::iterator begin, std::vector<T>::iterator end)
				{
				}

				template <class T>
				std::vector<T> compressCMYK(std::vector<T>::iterator begin, std::vector<T>::iterator end)
				{
				}

				template <class T>
				std::vector<T> compressCMYKRLE8(std::vector<T>::iterator begin, std::vector<T>::iterator end)
				{
				}

				template <class T>
				std::vector<T> compressCMYKRLE4(std::vector<T>::iterator begin, std::vector<T>::iterator end)
				{
				}

				template <class T>
				std::vector<T> decompressRLE8(std::vector<T>::iterator begin, std::vector<T>::iterator end)
				{
				}

				template <class T>
				std::vector<T> decompressRLE4(std::vector<T>::iterator begin, std::vector<T>::iterator end)
				{
				}

				template <class T>
				std::vector<T> decompressBitfields(std::vector<T>::iterator begin, std::vector<T>::iterator end)
				{
				}

				template <class T>
				std::vector<T> decompressJPEG(std::vector<T>::iterator begin, std::vector<T>::iterator end)
				{
				}

				template <class T>
				std::vector<T> decompressPNG(std::vector<T>::iterator begin, std::vector<T>::iterator end)
				{
				}

				template <class T>
				std::vector<T> decompressAlphaBitfields(std::vector<T>::iterator begin, std::vector<T>::iterator end)
				{
				}

				template <class T>
				std::vector<T> decompressCMYK(std::vector<T>::iterator begin, std::vector<T>::iterator end)
				{
				}

				template <class T>
				std::vector<T> decompressCMYKRLE8(std::vector<T>::iterator begin, std::vector<T>::iterator end)
				{
				}

				template <class T>
				std::vector<T> decompressCMYKRLE4(std::vector<T>::iterator begin, std::vector<T>::iterator end)
				{
				}

			} // namespace bitmap
		} // namespace formats
	} // namespace utility
} // namespace ece