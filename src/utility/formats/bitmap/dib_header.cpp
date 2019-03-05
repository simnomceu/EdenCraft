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
#include "utility/formats/bitmap/dib_header.hpp"
#include "utility/formats/bitmap/bitmap_core_header.hpp"
#include "utility/formats/bitmap/os21x_bitmap_header.hpp"
#include "utility/formats/bitmap/os22x_bitmap_header.hpp"
#include "utility/formats/bitmap/bitmap_info_header.hpp"
#include "utility/formats/bitmap/bitmap_v2_info_header.hpp"
#include "utility/formats/bitmap/bitmap_v3_info_header.hpp"
#include "utility/formats/bitmap/bitmap_v4_header.hpp"
#include "utility/formats/bitmap/bitmap_v5_header.hpp"

namespace ece
{
	namespace utility
	{
		namespace formats
		{
			namespace bitmap
			{
				DIBHeader::DIBHeader() noexcept : type(DIBHeaderType::BITMAPINFOHEADER), width(0), height(0), planes(0), bpp(0), compression(CompressionMethod::RGB), imageSize(0),
					xResolution(0), yResolution(0), halftoning{ Halftoning::Algorithm::NONE, 0, 0 }, mask(), colorSpace{ColorSpace::Type::CALIBRATED_RGB, {}, {}, {}}, gamma(), 
					intent(IntentMapping::NONE), profile() {}

				std::istream & operator>>(std::istream & stream, DIBHeader & header)
				{
					const auto headerSize = getSize(header.type);
					auto proxy = std::vector<char>(headerSize);
					stream.read(proxy.data(), headerSize);

					switch (header.type)
					{
					case DIBHeaderType::BITMAPCOREHEADER:
					{
						auto proxyBitmapCoreHeader = reinterpret_cast<BitmapCoreHeader *>(proxy.data());
						assert(headerSize == proxyBitmapCoreHeader->size);
						header.width = proxyBitmapCoreHeader->width;
						header.height = proxyBitmapCoreHeader->height;
						header.planes = proxyBitmapCoreHeader->planes;
						header.bpp = proxyBitmapCoreHeader->bpp;
						break;
					}
					case DIBHeaderType::OS21XBITMAPHEADER:
					{
						auto proxyOS21XBitmapHeader = reinterpret_cast<OS21XBitmapHeader *>(proxy.data());
						assert(headerSize == proxyOS21XBitmapHeader->size);
						header.width = proxyOS21XBitmapHeader->width;
						header.height = proxyOS21XBitmapHeader->height;
						header.planes = proxyOS21XBitmapHeader->planes;
						header.bpp = proxyOS21XBitmapHeader->bpp;
						break;
					}
					case DIBHeaderType::OS22XBITMAPHEADER:
					{
						auto proxyOS22XBitmapHeader = reinterpret_cast<OS22XBitmapHeader *>(proxy.data());
						assert(headerSize == proxyOS22XBitmapHeader->size || proxyOS22XBitmapHeader->size == 16);
						header.width = proxyOS22XBitmapHeader->width;
						header.height = proxyOS22XBitmapHeader->height;
						header.planes = proxyOS22XBitmapHeader->planes;
						header.bpp = proxyOS22XBitmapHeader->bpp;

						if (proxyOS22XBitmapHeader->size == headerSize) {
							header.compression = static_cast<CompressionMethod>(proxyOS22XBitmapHeader->compression);
							header.imageSize = proxyOS22XBitmapHeader->imageSize;
							header.xResolution = proxyOS22XBitmapHeader->xResolution * proxyOS22XBitmapHeader->resolutionUnit;
							header.yResolution = proxyOS22XBitmapHeader->yResolution * proxyOS22XBitmapHeader->resolutionUnit;
							header.nbColorsUsed = proxyOS22XBitmapHeader->numberOfColorsUsed;
							header.nbImportantColors = proxyOS22XBitmapHeader->numberOfImportantColors;
							assert(proxyOS22XBitmapHeader->recordingAlgorithm == 0);
							header.halftoning.algorithm = static_cast<DIBHeader::Halftoning::Algorithm>(proxyOS22XBitmapHeader->halftoningAlgorithm);
							header.halftoning.size1 = proxyOS22XBitmapHeader->halftoningSize1;
							header.halftoning.size2 = proxyOS22XBitmapHeader->halftoningSize2;
							assert(proxyOS22XBitmapHeader->colorEncoding == 0);
							// proxyOS22XBitmapHeader->identifier
						}
						break;
					}
					case DIBHeaderType::BITMAPINFOHEADER:
					{
						auto proxyBitmapInfoHeader = reinterpret_cast<BitmapInfoHeader *>(proxy.data());
						assert(headerSize == proxyBitmapInfoHeader->size);
						header.width = proxyBitmapInfoHeader->width;
						header.height = proxyBitmapInfoHeader->height;
						header.planes = proxyBitmapInfoHeader->planes;
						header.bpp = proxyBitmapInfoHeader->bpp;
						header.compression = static_cast<CompressionMethod>(proxyBitmapInfoHeader->compression);
						header.imageSize = proxyBitmapInfoHeader->imageSize;
						header.xResolution = proxyBitmapInfoHeader->xResolution;
						header.yResolution = proxyBitmapInfoHeader->yResolution;
						header.nbColorsUsed = proxyBitmapInfoHeader->numberOfColorsUsed;
						header.nbImportantColors = proxyBitmapInfoHeader->numberOfImportantColors;
						break;
					}
					case DIBHeaderType::BITMAPV2INFOHEADER:
					{
						auto proxyBitmapV2InfoHeader = reinterpret_cast<BitmapV2InfoHeader *>(proxy.data());
						assert(headerSize == proxyBitmapV2InfoHeader->size);
						header.width = proxyBitmapV2InfoHeader->width;
						header.height = proxyBitmapV2InfoHeader->height;
						header.planes = proxyBitmapV2InfoHeader->planes;
						header.bpp = proxyBitmapV2InfoHeader->bpp;
						header.compression = static_cast<CompressionMethod>(proxyBitmapV2InfoHeader->compression);
						header.imageSize = proxyBitmapV2InfoHeader->imageSize;
						header.xResolution = proxyBitmapV2InfoHeader->xResolution;
						header.yResolution = proxyBitmapV2InfoHeader->yResolution;
						header.nbColorsUsed = proxyBitmapV2InfoHeader->numberOfColorsUsed;
						header.nbImportantColors = proxyBitmapV2InfoHeader->numberOfImportantColors;
						header.mask = RGB<std::size_t>{ proxyBitmapV2InfoHeader->redMask, proxyBitmapV2InfoHeader->greenMask, proxyBitmapV2InfoHeader->blueMask };
						break;
					}
					case DIBHeaderType::BITMAPV3INFOHEADER:
					{
						auto proxyBitmapV3InfoHeader = reinterpret_cast<BitmapV3InfoHeader *>(proxy.data());
						assert(headerSize == proxyBitmapV3InfoHeader->size);
						header.width = proxyBitmapV3InfoHeader->width;
						header.height = proxyBitmapV3InfoHeader->height;
						header.planes = proxyBitmapV3InfoHeader->planes;
						header.bpp = proxyBitmapV3InfoHeader->bpp;
						header.compression = static_cast<CompressionMethod>(proxyBitmapV3InfoHeader->compression);
						header.imageSize = proxyBitmapV3InfoHeader->imageSize;
						header.xResolution = proxyBitmapV3InfoHeader->xResolution;
						header.yResolution = proxyBitmapV3InfoHeader->yResolution;
						header.nbColorsUsed = proxyBitmapV3InfoHeader->numberOfColorsUsed;
						header.nbImportantColors = proxyBitmapV3InfoHeader->numberOfImportantColors;
						header.mask = RGBA<std::size_t>{ proxyBitmapV3InfoHeader->redMask, proxyBitmapV3InfoHeader->greenMask, proxyBitmapV3InfoHeader->blueMask, proxyBitmapV3InfoHeader->alphaMask };
						break;
					}
					case DIBHeaderType::BITMAPV4HEADER:
					{
						auto proxyBitmapV4Header = reinterpret_cast<BitmapV4Header *>(proxy.data());
						assert(headerSize == proxyBitmapV4Header->size);
						header.width = proxyBitmapV4Header->width;
						header.height = proxyBitmapV4Header->height;
						header.planes = proxyBitmapV4Header->planes;
						header.bpp = proxyBitmapV4Header->bpp;
						header.compression = static_cast<CompressionMethod>(proxyBitmapV4Header->compression);
						header.imageSize = proxyBitmapV4Header->imageSize;
						header.xResolution = proxyBitmapV4Header->xResolution;
						header.yResolution = proxyBitmapV4Header->yResolution;
						header.nbColorsUsed = proxyBitmapV4Header->numberOfColorsUsed;
						header.nbImportantColors = proxyBitmapV4Header->numberOfImportantColors;
						header.colorSpace.type = static_cast<DIBHeader::ColorSpace::Type>(proxyBitmapV4Header->colorSpaceType);
						if (header.colorSpace.type == DIBHeader::ColorSpace::Type::CALIBRATED_RGB) {
							header.colorSpace.redEndpoint = { proxyBitmapV4Header->xRedEndpoint, proxyBitmapV4Header->yRedEndpoint, proxyBitmapV4Header->zRedEndpoint };
							header.colorSpace.greenEndpoint = { proxyBitmapV4Header->xGreenEndpoint, proxyBitmapV4Header->yGreenEndpoint, proxyBitmapV4Header->zGreenEndpoint };
							header.colorSpace.blueEndpoint = { proxyBitmapV4Header->xBlueEndpoint, proxyBitmapV4Header->yBlueEndpoint, proxyBitmapV4Header->zBlueEndpoint };
							header.gamma = { proxyBitmapV4Header->gammaRed, proxyBitmapV4Header->gammaGreen, proxyBitmapV4Header->gammaBlue };
						}
						break;
					}
					case DIBHeaderType::BITMAPV5HEADER:
					{
						auto proxyBitmapV5Header = reinterpret_cast<BitmapV5Header *>(proxy.data());
						assert(headerSize == proxyBitmapV5Header->size);
						header.width = proxyBitmapV5Header->width;
						header.height = proxyBitmapV5Header->height;
						header.planes = proxyBitmapV5Header->planes;
						header.bpp = proxyBitmapV5Header->bpp;
						header.compression = static_cast<CompressionMethod>(proxyBitmapV5Header->compression);
						header.imageSize = proxyBitmapV5Header->imageSize;
						header.xResolution = proxyBitmapV5Header->xResolution;
						header.yResolution = proxyBitmapV5Header->yResolution;
						header.nbColorsUsed = proxyBitmapV5Header->numberOfColorsUsed;
						header.nbImportantColors = proxyBitmapV5Header->numberOfImportantColors;
						header.colorSpace.type = static_cast<DIBHeader::ColorSpace::Type>(proxyBitmapV5Header->colorSpaceType);
						if (header.colorSpace.type == DIBHeader::ColorSpace::Type::CALIBRATED_RGB) {
							header.colorSpace.redEndpoint = { proxyBitmapV5Header->xRedEndpoint, proxyBitmapV5Header->yRedEndpoint, proxyBitmapV5Header->zRedEndpoint };
							header.colorSpace.greenEndpoint = { proxyBitmapV5Header->xGreenEndpoint, proxyBitmapV5Header->yGreenEndpoint, proxyBitmapV5Header->zGreenEndpoint };
							header.colorSpace.blueEndpoint = { proxyBitmapV5Header->xBlueEndpoint, proxyBitmapV5Header->yBlueEndpoint, proxyBitmapV5Header->zBlueEndpoint };
							header.gamma = { proxyBitmapV5Header->gammaRed, proxyBitmapV5Header->gammaGreen, proxyBitmapV5Header->gammaBlue };
						}
						header.intent = static_cast<DIBHeader::IntentMapping>(proxyBitmapV5Header->intent);
						if (header.colorSpace.type == DIBHeader::ColorSpace::Type::POFILE_LINKED || header.colorSpace.type == DIBHeader::ColorSpace::Type::PROFILE_EMBEDDED) {
							header.profile.data = proxyBitmapV5Header->profileData;
							header.profile.size = proxyBitmapV5Header->profileSize;
						}
						assert(proxyBitmapV5Header->reserved == 0);
						break;
					}
					default: break;
					}

					return stream;
				}

				std::ostream & operator<<(std::ostream & stream, DIBHeader & /*header*/)
				{
					return stream;
				}
			} // namespace bitmap
		} // namespace formats
	} // namespace utility
} // namespace ece