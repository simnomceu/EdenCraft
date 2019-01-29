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
#include "utility/formats/bitmap/parser_bmp.hpp"

namespace ece
{
	namespace utility
	{
		namespace formats
		{
			namespace bitmap
			{
				void ParserBMP::load(std::istream & stream)
				{
					auto header = BMPHeader{};
					auto DIB = BMPDIB{};
					auto buffer = std::vector<std::byte>{};

					// see http://tipsandtricks.runicsoft.com/Cpp/BitmapTutorial.html
					// see http://www.di.unito.it/~marcog/SM/BMPformat-Wiki.pdf
					// see https://upload.wikimedia.org/wikipedia/commons/c/c4/BMPfileFormat.png
					// see https://en.wikipedia.org/wiki/BMP_file_format

					stream.read(reinterpret_cast<char *>(&header.magic[0]), sizeof(uint8_t));
					stream.read(reinterpret_cast<char *>(&header.magic[1]), sizeof(uint8_t));
					stream.read(reinterpret_cast<char *>(&header.size), sizeof(uint32_t));
					stream.read(reinterpret_cast<char *>(&header.reserved), sizeof(uint32_t));
					stream.read(reinterpret_cast<char *>(&header.pixelsOffset), sizeof(uint32_t));

					stream.read(reinterpret_cast<char *>(&DIB), sizeof(BMPDIB));

					buffer.resize(header.size - header.pixelsOffset);
					stream.seekg(header.pixelsOffset);
					for (auto i = std::size_t{ 0 }; i < buffer.size(); ++i) { // TODO: should be done with one call to read a contiguous value of size sizeof(std::byte)*nbBytes
						stream.read(reinterpret_cast<char *>(&buffer[i]), sizeof(std::byte));
					}

					auto padding = 0;
					auto scanLineBytes = DIB.width * 3;
					while ((scanLineBytes + padding) % 4 != 0) {
						++padding;
					}
					int psw = scanLineBytes + padding; // TODO: all here is not efficient at all

					this->_pixels.resize(DIB.width, DIB.height);
					long bufPos = 0;
					for (auto y = std::size_t{ 0 }; y < this->_pixels.getHeight(); ++y) {
						for (auto x = std::size_t{ 0 }; x < 3 * this->_pixels.getWidth(); x += 3) {
							bufPos = (DIB.height - y - 1) * psw + x;

							this->_pixels[this->_pixels.getHeight() - 1 - y][x / 3][0] = buffer[bufPos + 2]; // red
							this->_pixels[this->_pixels.getHeight() - 1 - y][x / 3][1] = buffer[bufPos + 1]; // green
							this->_pixels[this->_pixels.getHeight() - 1 - y][x / 3][2] = buffer[bufPos]; // blue
						}
					}
				}

				void ParserBMP::save([[maybe_unused]] std::ostream & stream)
				{
					/* NOT IMPLEMENTED YET*/
				}
			} // namespace bitmap
		} // namespace formats
	} // namespace renderer
} // namespace ece
