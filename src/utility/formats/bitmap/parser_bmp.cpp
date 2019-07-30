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
#include "utility/formats/bitmap/bmp_header.hpp"
#include "utility/formats/bitmap/dib_header.hpp"
#include "utility/formats/bitmap/color_table.hpp"

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
					auto buffer = std::vector<char>{};

					// see http://paulbourke.net/dataformats/bitmaps/
					// see http://www.kalytta.com/bitmap.h
					// see http://www.di.unito.it/~marcog/SM/BMPformat-Wiki.pdf
					// see https://upload.wikimedia.org/wikipedia/commons/c/c4/BMPfileFormat.png
					// see https://en.wikipedia.org/wiki/BMP_file_format
					// see https://forums.adobe.com/message/3272950#3272950
					// see Tests : http://entropymine.com/jason/bmpsuite/

					stream >> this->_bitmap.header;
					if (this->_bitmap.header.signature != BitmapSignature::BM) {
						throw std::runtime_error("Alternative bitmap format ('BA', 'CI', 'CP', 'IC', 'PT') are not supported for now.");
						// TODO: Parser is only dealing with BM bitmap format.
					}
					this->_bitmap.dib.size = this->_bitmap.header.pixelsOffset - BMPHeader::INTERNAL_SIZE;
					stream >> this->_bitmap.dib;
					if (!this->_bitmap.isValid()) {
						SYSTEM << "Unknown error in DIB" << flush;
					}

					// Color Table
					this->_bitmap.colors = std::make_shared<ColorTable>(this->_bitmap.dib);
					stream >> *this->_bitmap.colors;

					buffer.resize(this->_bitmap.header.size - this->_bitmap.header.pixelsOffset);
					stream.seekg(this->_bitmap.header.pixelsOffset);
					stream.read(reinterpret_cast<char *>(buffer.data()), buffer.size());

					if (stream.fail() && stream.eof() && !stream.bad()) {
						throw std::runtime_error("The file has been truncated in the middle of the bitmap.");
					}

					auto uncompressBuffer = uncompress(buffer.begin(), buffer.end(), this->_bitmap.dib);
					
					int psw = ((this->_bitmap.dib.width * 3) + 3) & ~3;

					this->_bitmap.pixels.resize(static_cast<ece::size_t>(this->_bitmap.dib.width), static_cast<ece::size_t>(this->_bitmap.dib.height));

					if (this->_bitmap.dib.nbColorsUsed == 0) {
						long bufPos = 0;
						for (auto y = ece::size_t{ 0 }; y < this->_bitmap.pixels.getHeight(); ++y) {
							for (auto x = ece::size_t{ 0 }; x < 3 * this->_bitmap.pixels.getWidth(); x += 3) {
								bufPos = (static_cast<long>(this->_bitmap.dib.height) - static_cast<long>(y) - 1) * psw + static_cast<long>(x);
								if (static_cast<std::size_t>(bufPos) > uncompressBuffer.size()) {
									throw std::runtime_error("The file has been truncated in the middle of the bitmap.");
								}

								this->_bitmap.pixels[this->_bitmap.pixels.getHeight() - 1 - y][x / 3][0] = static_cast<std::uint8_t>(uncompressBuffer[bufPos + 2]); // red
								this->_bitmap.pixels[this->_bitmap.pixels.getHeight() - 1 - y][x / 3][1] = static_cast<std::uint8_t>(uncompressBuffer[bufPos + 1]); // green
								this->_bitmap.pixels[this->_bitmap.pixels.getHeight() - 1 - y][x / 3][2] = static_cast<std::uint8_t>(uncompressBuffer[bufPos]); // blue
							}
						}
					}
					else {
						long bufPos = 0;
						for (auto y = ece::size_t{ 0 }; y < this->_bitmap.pixels.getHeight(); ++y) {
							for (auto x = ece::size_t{ 0 }; x < this->_bitmap.pixels.getWidth(); ++x) {
								bufPos = (static_cast<long>(this->_bitmap.dib.height) - static_cast<long>(y) - 1) * this->_bitmap.dib.width + static_cast<long>(x);
								if (static_cast<std::size_t>(bufPos) > uncompressBuffer.size()) {
									throw std::runtime_error("The file has been truncated in the middle of the bitmap.");
								}
								if (static_cast<std::int32_t>(uncompressBuffer[bufPos]) >= this->_bitmap.dib.nbColorsUsed || static_cast<std::int32_t>(uncompressBuffer[bufPos]) < 0) {
									throw std::runtime_error("Trying to access the " + std::to_string(static_cast<std::size_t>(uncompressBuffer[bufPos])) + "th color while the size of the color table is " + std::to_string(this->_bitmap.dib.nbColorsUsed) + ".");
								}
								auto color = (*this->_bitmap.colors)[static_cast<std::size_t>(uncompressBuffer[bufPos])];
								this->_bitmap.pixels[this->_bitmap.dib.height - 1 - y][x / 3][0] = color.r; // red
								this->_bitmap.pixels[this->_bitmap.dib.height - 1 - y][x / 3][1] = color.g; // green
								this->_bitmap.pixels[this->_bitmap.dib.height - 1 - y][x / 3][2] = color.b; // blue
							}
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
