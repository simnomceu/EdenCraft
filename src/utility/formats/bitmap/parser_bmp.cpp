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
					auto buffer = std::vector<std::uint8_t>{};

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

					auto uncompressBuffer = uncompress(buffer, this->_bitmap.dib);
					
					int psw = ((this->_bitmap.dib.width * this->_bitmap.dib.bitCount / 8) + 3) & ~3; // To be sure it is aligned on 4 bytes.

					this->_bitmap.pixels.resize(static_cast<ece::size_t>(this->_bitmap.dib.width), static_cast<ece::size_t>(this->_bitmap.dib.height));

					if (this->_bitmap.dib.nbColorsUsed == 0) {
						long bufPos = 0;
						for (auto y = ece::size_t{ 0 }; y < this->_bitmap.pixels.getHeight(); ++y) {
							for (auto x = ece::size_t{ 0 }; x < 3 * this->_bitmap.pixels.getWidth(); x+=3) {
								bufPos = (static_cast<long>(this->_bitmap.dib.height) - static_cast<long>(y) - 1) * psw + static_cast<long>(x);
								if (static_cast<std::size_t>(bufPos) > uncompressBuffer.size()) {
									throw std::runtime_error("The file has been truncated in the middle of the bitmap.");
								}

								this->_bitmap.pixels[this->_bitmap.pixels.getHeight() - 1 - y][x / 3][0] = static_cast<std::uint8_t>(static_cast<unsigned char>(uncompressBuffer[bufPos + 2])); // red
								this->_bitmap.pixels[this->_bitmap.pixels.getHeight() - 1 - y][x / 3][1] = static_cast<std::uint8_t>(static_cast<unsigned char>(uncompressBuffer[bufPos + 1])); // green
								this->_bitmap.pixels[this->_bitmap.pixels.getHeight() - 1 - y][x / 3][2] = static_cast<std::uint8_t>(static_cast<unsigned char>(uncompressBuffer[bufPos])); // blue
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
								auto colorPos = static_cast<std::size_t>(static_cast<unsigned char>(uncompressBuffer[bufPos]));
								if (static_cast<std::int32_t>(colorPos) >= this->_bitmap.dib.nbColorsUsed) {
									throw std::runtime_error("Trying to access the " + std::to_string(colorPos) + "th color while the size of the color table is " + std::to_string(this->_bitmap.dib.nbColorsUsed) + ".");
								}
								auto color = (*this->_bitmap.colors)[colorPos];
								this->_bitmap.pixels[this->_bitmap.dib.height - 1 - y][x][0] = color.r; // red
								this->_bitmap.pixels[this->_bitmap.dib.height - 1 - y][x][1] = color.g; // green
								this->_bitmap.pixels[this->_bitmap.dib.height - 1 - y][x][2] = color.b; // blue
							}
						}
					}
				}

				void ParserBMP::save(std::ostream & stream)
				{
					this->_bitmap.header.signature = BitmapSignature::BM;
					this->_bitmap.header.pixelsOffset = BMPHeader::INTERNAL_SIZE + getSize(DIBHeaderType::BITMAPV3INFOHEADER);
					this->_bitmap.header.size = this->_bitmap.header.pixelsOffset + (3 * this->_bitmap.pixels.getHeight() * this->_bitmap.pixels.getWidth());
					
					this->_bitmap.dib.size = getSize(DIBHeaderType::BITMAPV3INFOHEADER);
					this->_bitmap.dib.width = this->_bitmap.pixels.getWidth();
					this->_bitmap.dib.height = this->_bitmap.pixels.getHeight();
					this->_bitmap.dib.planes = 1;
					this->_bitmap.dib.bitCount = 24;
					this->_bitmap.dib.compression = CompressionMethod::RGB;
					this->_bitmap.dib.imageSize = 0;
					this->_bitmap.dib.xResolution = static_cast<int>(DPIToPPM(DPI_MAX));
					this->_bitmap.dib.yResolution = static_cast<int>(DPIToPPM(DPI_MAX));
					this->_bitmap.dib.nbColorsUsed = 0;
					this->_bitmap.dib.nbImportantColors = 0;
					this->_bitmap.dib.mask = RGB24{ 8, 8, 8 };

					if (!this->_bitmap.isValid()) {
						SYSTEM << "Unknown error in DIB" << flush;
					}

					stream << this->_bitmap.header;
					stream << this->_bitmap.dib;

					auto buffer = std::vector<std::uint8_t>{};
					buffer.resize(this->_bitmap.pixels.getHeight() * this->_bitmap.pixels.getWidth() * 3);
					
					int psw = ((this->_bitmap.dib.width * (this->_bitmap.dib.bitCount / 8)) + 3) & ~3; // To be sure it is aligned on 4 bytes.
					long bufPos = 0;
					for (auto y = ece::size_t{ 0 }; y < this->_bitmap.pixels.getHeight(); ++y) {
						for (auto x = ece::size_t{ 0 }; x < 3 * this->_bitmap.pixels.getWidth(); x += 3) {
							bufPos = (static_cast<long>(this->_bitmap.dib.height) - static_cast<long>(y) - 1) * psw + static_cast<long>(x);
							buffer[bufPos + 2] = static_cast<std::uint8_t>(static_cast<unsigned char>(this->_bitmap.pixels[this->_bitmap.pixels.getHeight() - 1 - y][x / 3][0])); // red
							buffer[bufPos + 1] = static_cast<std::uint8_t>(static_cast<unsigned char>(this->_bitmap.pixels[this->_bitmap.pixels.getHeight() - 1 - y][x / 3][1])); // green
							buffer[bufPos] = static_cast<std::uint8_t>(static_cast<unsigned char>(this->_bitmap.pixels[this->_bitmap.pixels.getHeight() - 1 - y][x / 3][2])); // blue
						}
					}
					auto compressed = compress(std::move(buffer), this->_bitmap.dib);

					stream.seekp(this->_bitmap.header.pixelsOffset);
					stream.write(reinterpret_cast<char *>(compressed.data()), compressed.size());
				}
			} // namespace bitmap
		} // namespace formats
	} // namespace renderer
} // namespace ece
