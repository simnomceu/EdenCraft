/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

															ooooooooo.                               .o8
															`888   `Y88.                            "888
															 888   .d88'  .ooooo.  ooo. .oo.    .oooo888   .ooooo.  oooo d8b  .ooooo.  oooo d8b
															 888ooo88P'  d88' `88b `888P"Y88b  d88' `888  d88' `88b `888""8P d88' `88b `888""8P
															 888`88b.    888ooo888  888   888  888   888  888ooo888  888     888ooo888  888
															 888  `88b.  888    .o  888   888  888   888  888    .o  888     888    .o  888
															o888o  o888o `Y8bod8P' o888o o888o `Y8bod88P" `Y8bod8P' d888b    `Y8bod8P' d888b



				This file is part of EdenCraft Engine - Renderer module.
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

#include "renderer/image/parser_bmp.hpp"

#include "utility/file_system/file.hpp"

namespace ece
{
	namespace renderer
	{
		namespace image
		{
			using utility::file_system::File;
			using utility::debug::FileException;
			using utility::OpenMode;

			void ParserBMP::loadFromFile(const std::string & filename)
			{
				File file;

				BMPHeader header;
				BMPDIB DIB;
				std::vector<std::byte> buffer;

				// see http://tipsandtricks.runicsoft.com/Cpp/BitmapTutorial.html
				// see http://www.di.unito.it/~marcog/SM/BMPformat-Wiki.pdf
				// see https://upload.wikimedia.org/wikipedia/commons/c/c4/BMPfileFormat.png
				// see https://en.wikipedia.org/wiki/BMP_file_format

				try {
					if (!file.open(filename, OpenMode::binary | OpenMode::in | OpenMode::out)) {
						throw std::runtime_error(filename + " has not been opened.");
					}
					header.magic[0] = file.read<uint8_t>();
					header.magic[1] = file.read<uint8_t>();
					header.size = file.read<uint32_t>();
					header.reserved = file.read<uint32_t>();
					header.pixelsOffset = file.read<uint32_t>();

					DIB = file.read<BMPDIB>();

					buffer.resize(header.size - header.pixelsOffset);
					file.moveCursorTo(header.pixelsOffset);
					for (size_t i = 0; i < buffer.size(); ++i) { // TODO: should be done with one call to reada contiguous value of size sizeof(std::byte)*nbBytes
						buffer[i] = file.read<std::byte>();
					}

					int padding = 0;
					int scanLineBytes = DIB.width * 3;
					while ((scanLineBytes + padding) % 4 != 0) {
						++padding;
					}
					int psw = scanLineBytes + padding; // TODO: all here is not efficient at all

			this->_image.resize(psw / 3, DIB.height);
			long bufPos = 0;
			for (uint32_t y = 0; y < this->_image.getHeight(); ++y) {
				for (uint32_t x = 0; x < 3 * this->_image.getWidth(); x+=3) {
					bufPos = (DIB.height - y - 1) * psw + x;
					
					this->_image[this->_image.getHeight() - 1 - y][x / 3].red = buffer[bufPos + 2];
					this->_image[this->_image.getHeight() - 1 - y][x / 3].green = buffer[bufPos + 1];
					this->_image[this->_image.getHeight() - 1 - y][x / 3].blue = buffer[bufPos];
						}
					}
				}
				catch (FileException & e) {
					throw e;
				}
			}

			void ParserBMP::loadFromString(const std::string & /*content*/)
			{

			}

			void ParserBMP::loadFromMemory(const void * /*content*/)
			{

			}

			void ParserBMP::saveToFile(const std::string & /*filename*/)
			{

			}

			void ParserBMP::saveToString(std::string & /*content*/)
			{

			}

			void ParserBMP::saveToMemory(void * /*content*/)
			{

			}
		} // namespace image
	} // namespace renderer
} // namespace ece
