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
#include "utility/algorithm/rle.hpp"
#include "utility/types.hpp"

namespace ece
{
	namespace utility
	{
		namespace algorithm
		{
			std::vector<std::uint8_t> compressRLE4(const std::vector<std::uint8_t> & /*uncompressed*/, std::size_t /*width*/, std::size_t /*height*/)
			{
				return std::vector<std::uint8_t>();
			}

			std::vector<std::uint8_t> uncompressRLE4(const std::vector<std::uint8_t> & compressed, std::size_t width, std::size_t height)
			{
				auto consume = [](std::vector<std::uint8_t>::const_iterator & it) -> std::uint8_t {
					auto result = *it;
					++it;
					return std::move(result);
				};

				auto result = std::vector<std::uint8_t>(width * height, 0);

				auto shift = std::size_t{ 0 };
				auto eol = width;
				auto it = compressed.begin();
				while (it != compressed.end() && shift < result.size()) {
					auto code1 = consume(it);

					if (code1 == 0) {
						auto code2 = consume(it);

						if (code2 == 0) { // EoL
							shift = eol;
							eol += width;
						}
						else if (code2 == 1) { // EoF
							it = compressed.end();
						}
						else if (code2 == 2) { // Delta Jump
							auto x = consume(it);
							auto y = consume(it);

							shift += (y * width) + x;
							eol += y * width;
						}
						else { // absolute mode
							if (shift >= result.size() || code2 >= result.size() - shift) {
								throw std::runtime_error("Error in RLE4 decompression, buffer overrun attempt has been detected.");
							}
							if ((shift % width) + code2 >= width) {
								eol += (((shift % width) + code2) / width) * width;
							}
							auto val = std::uint8_t{ 0 };
							for (auto i = 0; i < code2; ++i) {
								if (i % 2 == 0) {
									val = consume(it);
								}
								result[shift] = i % 2 == 0 ? get4<std::uint8_t, 1>(val) : get4<std::uint8_t, 0>(val);
								++shift;
							}
						}
					}
					else {
						if (shift >= result.size() || code1 >= result.size() - shift) {
							throw std::runtime_error("Error in RLE4 decompression, buffer overrun attempt has been detected.");
						}
						if ((shift % width) + code1 >= width) {
							eol += (((shift % width) + code1) / width) * width;
						}
						auto val = consume(it);
						for (auto i = 0; i < code1; ++i) {
							result[shift] = i % 2 == 0 ? get4<std::uint8_t, 1>(val) : get4<std::uint8_t, 0>(val);
							++shift;
						}
					}
				}

				return std::move(result);
			}

			std::vector<std::uint8_t> compressRLE8(const std::vector<std::uint8_t> & uncompressed, std::size_t /*width*/, std::size_t /*height*/)
			{
				auto consume = [](std::vector<std::uint8_t>::const_iterator & it) -> std::uint8_t {
					auto result = *it;
					++it;
					return std::move(result);
				};

				auto result = std::vector<std::uint8_t>();

			//	auto count = std::size_t{ 0 };
			//	auto last = std::uint8_t{ 0 };

				auto it = uncompressed.begin();
				while (it != uncompressed.end()) {
					
				}

				return std::move(result);
			}

			std::vector<std::uint8_t> uncompressRLE8(const std::vector<std::uint8_t> & compressed, std::size_t width, std::size_t height)
			{
				auto consume = [](std::vector<std::uint8_t>::const_iterator & it) -> std::uint8_t {
					auto result = *it;
					++it;
					return std::move(result);
				};

				auto result = std::vector<std::uint8_t>(width * height, 0);
				
				auto shift = std::size_t{ 0 };
				auto eol = width;
				auto it = compressed.begin();
				while (it != compressed.end() && shift < result.size()) {
					auto code1 = consume(it);

					if (code1 == 0) {
						auto code2 = consume(it);

						if (code2 == 0) { // EoL
							shift = eol;
							eol += width;
						}
						else if (code2 == 1) { // EoF
							it = compressed.end();
						}
						else if (code2 == 2) { // Delta Jump
							auto x = consume(it);
							auto y = consume(it);

							shift += (y * width) + x;
							eol += y * width;
						}
						else { // absolute mode
							if (shift >= result.size() || code2 >= result.size() - shift) {
								throw std::runtime_error("Error in RLE8 decompression, buffer overrun attempt has been detected.");
							}
							if ((shift % width) + code2 >= width) {
								eol += (((shift % width) + code2) / width) * width;
							}
							for (int i = 0; i < code2; ++i) {
								result[shift] = consume(it);
								++shift;
							}
						}
					}
					else {
						if (shift >= result.size() || code1 >= result.size() - shift) {
							throw std::runtime_error("Error in RLE8 decompression, buffer overrun attempt has been detected.");
						}
						if ((shift % width) + code1 >= width) {
							eol += (((shift % width) + code1) / width) * width;
						}
						auto val = consume(it);
						for (int i = 0; i < code1; ++i) {
							result[shift] = val;
							++shift;
						}
					}
				}

				return std::move(result);
			}
		} // algorithm
	} // namespace 
} // namespace ece