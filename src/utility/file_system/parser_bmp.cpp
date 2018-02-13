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

#include "utility/file_system/parser_bmp.hpp"

#include "utility/file_system/file.hpp"

namespace ece
{
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
			this->_buffer.resize(DIB.height * psw);

			this->_width = psw / 3;
			this->_height = DIB.height;
			std::cout << "size :" << this->_width << "*" << this->_height << " pixels" << std::endl;
			long bufPos = 0, newPos = 0;
			for (uint32_t y = 0; y < DIB.height; ++y) {
				for (uint32_t x = 0; x < 3 * DIB.width; x+=3) {
					newPos = y * 3 * DIB.width + x;
					bufPos = (DIB.height - y - 1) * psw + x;
					
					this->_buffer[newPos].red = buffer[newPos + 2]; std::cout << static_cast<int>(this->_buffer[newPos].red) << "|";
					this->_buffer[newPos].green = buffer[newPos + 1]; std::cout << static_cast<int>(this->_buffer[newPos].green) << "|";
					this->_buffer[newPos].blue = buffer[newPos]; std::cout << static_cast<int>(this->_buffer[newPos].blue);
					std::cout << " ";
				}
				std::cout << std::endl;
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

	std::vector<ParserBMP::RGB24> & ParserBMP::getBuffer() { return this->_buffer; }
	unsigned int ParserBMP::getWidth() const { return this->_width; }
	unsigned int ParserBMP::getHeight() const { return this->_height; }
}