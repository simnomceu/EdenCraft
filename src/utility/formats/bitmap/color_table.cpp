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
#include "utility/formats/bitmap/color_table.hpp"

namespace ece
{
	namespace utility
	{
		namespace formats
		{
			namespace bitmap
			{
				ColorTable::ColorTable(DIBHeader & dib) : _colors()
				{
					const auto colorTableSize = (dib.nbColorsUsed == 0 && dib.bitCount < 16) ? static_cast<std::size_t>(std::pow(2, dib.bitCount)) : dib.nbColorsUsed;
					if (dib.type == DIBHeaderType::BITMAPCOREHEADER || dib.type == DIBHeaderType::OS21XBITMAPHEADER || dib.type == DIBHeaderType::OS22XBITMAPHEADER) {
						this->_colors = std::vector<BGR24>(colorTableSize);
					}
					else {
						this->_colors = std::vector<BGRA32>(colorTableSize);
					}
				}

				RGBA32 ColorTable::operator[](const std::size_t index) const
				{
					if (std::holds_alternative<std::vector<BGR24>>(this->_colors)) {
						auto & proxyTable = std::get<std::vector<BGR24>>(this->_colors);
						return toRGBA32(proxyTable[index]);
					}
					else {
						auto & proxyTable = std::get<std::vector<BGRA32>>(this->_colors);
						return toRGBA32(proxyTable[index]);
					}
				}

				void ColorTable::set(const std::size_t index, RGBA32 value)
				{
					if (std::holds_alternative<std::vector<BGR24>>(this->_colors)) {
						auto & proxyTable = std::get<std::vector<BGR24>>(this->_colors);
						proxyTable[index] = toBGRA32(value);
					}
					else {
						auto & proxyTable = std::get<std::vector<BGRA32>>(this->_colors);
						proxyTable[index] = toBGRA32(value);
					}
				}

				std::istream & operator>>(std::istream & stream, ColorTable & colorTable)
				{
					if (std::holds_alternative<std::vector<BGR24>>(colorTable._colors)) {
						auto & proxyTable = std::get<std::vector<BGR24>>(colorTable._colors);
						stream.read(reinterpret_cast<char *>(proxyTable.data()), proxyTable.size() * sizeof(BGR24));
					}
					else {
						auto & proxyTable = std::get<std::vector<BGRA32>>(colorTable._colors);
						stream.read(reinterpret_cast<char *>(proxyTable.data()), proxyTable.size() * sizeof(BGRA32));
					}

					return stream;
				}

				std::ostream & operator<<(std::ostream & stream, ColorTable & colorTable)
				{
					if (std::holds_alternative<std::vector<BGR24>>(colorTable._colors)) {
						auto & proxyTable = std::get<std::vector<BGR24>>(colorTable._colors);
						stream.write(reinterpret_cast<const char *>(proxyTable.data()), proxyTable.size() * sizeof(BGR24));
					}
					else {
						auto & proxyTable = std::get<std::vector<BGRA32>>(colorTable._colors);
						stream.write(reinterpret_cast<const char *>(proxyTable.data()), proxyTable.size() * sizeof(BGRA32));
					}

					return stream;
				}
			} // namespace bitmap
		} // namespace formats
	} // namespace utility
} // namespace ece