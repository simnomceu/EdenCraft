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
#include "utility/formats/bitmap/bitmap_image.hpp"

namespace ece
{
	namespace utility
	{
		namespace formats
		{
			namespace bitmap
			{
				bool BitmapImage::isValid() const
				{
					if (this->header.size > this->header.pixelsOffset + this->dib.imageSize) {
						throw std::runtime_error("The given size of the bitmap is absurdly large(" + std::to_string(this->header.size) + ") and exceeds the size of the file (" + std::to_string(this->header.pixelsOffset + this->dib.imageSize) + ").");
					}
					if (this->dib.width < 0 || this->dib.height < 0) {
						throw std::runtime_error("The bitmap image has an invalid size: " + std::to_string(this->dib.width) + "x" + std::to_string(this->dib.height) + ".");
					}
					if (static_cast<long long int>(this->dib.width) * static_cast<long long int>(this->dib.height) > this->dib.imageSize * 32) {
						throw std::runtime_error("The bitmap image has an absurdly large size: " + std::to_string(this->dib.width) + "x" + std::to_string(this->dib.height) + ".");
					}
					if (this->dib.height == 0 && this->dib.width < 1) {
						return false;
					}
					if (this->dib.planes != 1) {
						throw std::runtime_error("Invalid number of planes(" + std::to_string(this->dib.planes) + "), Bitmap files contain only one color plane.");
					}
					if (this->dib.bitCount != 1 && this->dib.bitCount != 2 && this->dib.bitCount != 4 && this->dib.bitCount != 8 && this->dib.bitCount != 16 && this->dib.bitCount != 24 && this->dib.bitCount != 32 && this->dib.bitCount != 64) {
						WARNING << "Unusual number of Bits Per Pixel: " << this->dib.bitCount << " while trying to parse a " << to_string(this->dib.type) << " Bitmap DIB Header" << flush;
						if (this->dib.bitCount == 0) {
							throw std::runtime_error("It is not possible to evaluate a 0bpp bitmap image.");
						}

						if (this->dib.bitCount > this->header.size - this->header.pixelsOffset) {
							throw std::runtime_error("The number of Bits Per Pixel in this bitmap is absurdly large (" + std::to_string(this->dib.bitCount) + ") and exceeds the size of the pixels array (" + std::to_string(this->header.size - header.pixelsOffset) + ").");
						}
						return false;
					}
					if (this->dib.bitCount == 2 && this->dib.type != DIBHeaderType::BITMAPINFOHEADER) {
						throw std::runtime_error("A 2bpp bitmap image  can only be used in a Pocket PC Bitmap image, using a " + to_string(DIBHeaderType::BITMAPINFOHEADER) + " dIB header. Here, " + to_string(this->dib.type) + " is used.");
					}
					if (this->dib.imageSize > this->header.size) {
						throw std::runtime_error("The size of the pixel data is absurdly large (" + std::to_string(this->dib.imageSize) + ") and exceeds the size of the bitmap (" + std::to_string(this->header.size) + ").");
					}
					if (this->dib.xResolution > this->dib.yResolution * 2.0f || this->dib.yResolution > this->dib.xResolution * 2.0f) {
						WARNING << "The density of the image is not uniform (" << this->dib.xResolution << "x" << this->dib.yResolution << ")." << flush;
						if (this->dib.xResolution > this->dib.width) {
							throw std::runtime_error("The X density of the image is absurdly large (" + std::to_string(this->dib.xResolution) + ") and exceeds the width of the image (" + std::to_string(this->dib.width) + ").");
						}
						if (this->dib.yResolution > this->dib.height) {
							throw std::runtime_error("The Y density of the image is absurdly large (" + std::to_string(this->dib.yResolution) + ") and exceeds the height of the image (" + std::to_string(this->dib.height) + ").");
						}
					}
					if (this->dib.compression == CompressionMethod::BITFIELDS && this->dib.bitCount != 16 && this->dib.bitCount != 32) {
						return false;
					}
					if (this->dib.imageSize == 0 && this->dib.compression != CompressionMethod::RGB) {
						return false;
					}
					if (this->dib.compression == CompressionMethod::RLE4 && this->dib.bitCount != 4) {
						return false;
					}
					if (this->dib.compression == CompressionMethod::RLE8 && this->dib.bitCount != 8) {
						return false;
					}
					if (this->dib.compression == CompressionMethod::JPEG && this->dib.bitCount != 24) {
						return false;
					}
					if ((this->dib.bitCount == 16 || this->dib.bitCount == 32) && (this->dib.compression != CompressionMethod::RGB && this->dib.compression != CompressionMethod::CMYK)) {
						throw std::runtime_error("A " + std::to_string(this->dib.bitCount) + "bpp image should not use a compression method (" + to_string(this->dib.compression) + ").");
					}

					auto maxColors = static_cast<std::int32_t>(std::pow(2, this->dib.bitCount));
					if (this->dib.bitCount < 16 && this->dib.nbColorsUsed > maxColors) {
						throw std::runtime_error("The number of color used is incorrect (" + std::to_string(this->dib.nbColorsUsed) + "), as the maximum number of colors is " + std::to_string(maxColors) + ".");
					}
					if (this->dib.bitCount >= 16 && this->dib.nbColorsUsed != 0) {
						throw std::runtime_error("The color palet cannot be used, as the number of bit per pixel is " + std::to_string(this->dib.bitCount) + ".");
					}
					if (this->dib.nbColorsUsed > this->dib.width * this->dib.height) {
						WARNING << "Unusual number of colors used: " << this->dib.nbColorsUsed << " while trying to parse a " << to_string(this->dib.type) << " Bitmap DIB Header" << flush;

						auto reservedColorTableSize = static_cast<int32_t>(this->header.pixelsOffset - BMPHeader::INTERNAL_SIZE - this->dib.size);
						if (reservedColorTableSize < this->dib.nbColorsUsed) {
							throw std::runtime_error("The number of color used in this bitmap is absurdly large (" + std::to_string(this->dib.nbColorsUsed) + ") and exceeds the reserved size in the file (" + std::to_string(reservedColorTableSize) + ").");
						}
						return false;
					}

					return true;
				}
			} // namespace bitmap
		} // namespace formats
	} // namespace utility
} // namespace ece