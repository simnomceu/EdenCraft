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
				DIBHeader::DIBHeader() noexcept : type(DIBHeaderType::BITMAPINFOHEADER), width(0), height(0), planes(0), bitCount(0), compression(CompressionMethod::RGB), imageSize(0),
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
						header.bitCount = proxyBitmapCoreHeader->bitCount;
						break;
					}
					case DIBHeaderType::OS21XBITMAPHEADER:
					{
						auto proxyOS21XBitmapHeader = reinterpret_cast<OS21XBitmapHeader *>(proxy.data());
						assert(headerSize == proxyOS21XBitmapHeader->size);
						header.width = proxyOS21XBitmapHeader->width;
						header.height = proxyOS21XBitmapHeader->height;
						header.planes = proxyOS21XBitmapHeader->planes;
						header.bitCount = proxyOS21XBitmapHeader->bitCount;
						break;
					}
					case DIBHeaderType::OS22XBITMAPHEADER:
					{
						auto proxyOS22XBitmapHeader = reinterpret_cast<OS22XBitmapHeader *>(proxy.data());
						assert(headerSize == proxyOS22XBitmapHeader->size || proxyOS22XBitmapHeader->size == 16);
						header.width = proxyOS22XBitmapHeader->width;
						header.height = proxyOS22XBitmapHeader->height;
						header.planes = proxyOS22XBitmapHeader->planes;
						header.bitCount = proxyOS22XBitmapHeader->bitCount;

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
						header.bitCount = proxyBitmapInfoHeader->bitCount;
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
						header.bitCount = proxyBitmapV2InfoHeader->bitCount;
						header.compression = static_cast<CompressionMethod>(proxyBitmapV2InfoHeader->compression);
						header.imageSize = proxyBitmapV2InfoHeader->imageSize;
						header.xResolution = proxyBitmapV2InfoHeader->xResolution;
						header.yResolution = proxyBitmapV2InfoHeader->yResolution;
						header.nbColorsUsed = proxyBitmapV2InfoHeader->numberOfColorsUsed;
						header.nbImportantColors = proxyBitmapV2InfoHeader->numberOfImportantColors;
						if (header.compression == CompressionMethod::BITFIELDS) {
							header.mask = RGB<std::size_t>{ proxyBitmapV2InfoHeader->redMask, proxyBitmapV2InfoHeader->greenMask, proxyBitmapV2InfoHeader->blueMask };
						}
						break;
					}
					case DIBHeaderType::BITMAPV3INFOHEADER:
					{
						auto proxyBitmapV3InfoHeader = reinterpret_cast<BitmapV3InfoHeader *>(proxy.data());
						assert(headerSize == proxyBitmapV3InfoHeader->size);
						header.width = proxyBitmapV3InfoHeader->width;
						header.height = proxyBitmapV3InfoHeader->height;
						header.planes = proxyBitmapV3InfoHeader->planes;
						header.bitCount = proxyBitmapV3InfoHeader->bitCount;
						header.compression = static_cast<CompressionMethod>(proxyBitmapV3InfoHeader->compression);
						header.imageSize = proxyBitmapV3InfoHeader->imageSize;
						header.xResolution = proxyBitmapV3InfoHeader->xResolution;
						header.yResolution = proxyBitmapV3InfoHeader->yResolution;
						header.nbColorsUsed = proxyBitmapV3InfoHeader->numberOfColorsUsed;
						header.nbImportantColors = proxyBitmapV3InfoHeader->numberOfImportantColors;
						if (header.compression == CompressionMethod::BITFIELDS) {
							header.mask = RGBA<std::size_t>{ proxyBitmapV3InfoHeader->redMask, proxyBitmapV3InfoHeader->greenMask, proxyBitmapV3InfoHeader->blueMask, proxyBitmapV3InfoHeader->alphaMask };
						}
						break;
					}
					case DIBHeaderType::BITMAPV4HEADER:
					{
						auto proxyBitmapV4Header = reinterpret_cast<BitmapV4Header *>(proxy.data());
						assert(headerSize == proxyBitmapV4Header->size);
						header.width = proxyBitmapV4Header->width;
						header.height = proxyBitmapV4Header->height;
						header.planes = proxyBitmapV4Header->planes;
						header.bitCount = proxyBitmapV4Header->bitCount;
						header.compression = static_cast<CompressionMethod>(proxyBitmapV4Header->compression);
						header.imageSize = proxyBitmapV4Header->imageSize;
						header.xResolution = proxyBitmapV4Header->xResolution;
						header.yResolution = proxyBitmapV4Header->yResolution;
						header.nbColorsUsed = proxyBitmapV4Header->numberOfColorsUsed;
						header.nbImportantColors = proxyBitmapV4Header->numberOfImportantColors;
						if (header.compression == CompressionMethod::BITFIELDS) {
							header.mask = RGBA<std::size_t>{ proxyBitmapV4Header->redMask, proxyBitmapV4Header->greenMask, proxyBitmapV4Header->blueMask, proxyBitmapV4Header->alphaMask };
						}
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
						header.bitCount = proxyBitmapV5Header->bitCount;
						header.compression = static_cast<CompressionMethod>(proxyBitmapV5Header->compression);
						header.imageSize = proxyBitmapV5Header->imageSize;
						header.xResolution = proxyBitmapV5Header->xResolution;
						header.yResolution = proxyBitmapV5Header->yResolution;
						header.nbColorsUsed = proxyBitmapV5Header->numberOfColorsUsed;
						header.nbImportantColors = proxyBitmapV5Header->numberOfImportantColors;
						if (header.compression == CompressionMethod::BITFIELDS || header.compression == CompressionMethod::ALPHABITFIELDS) {
							header.mask = RGBA<std::size_t>{ proxyBitmapV5Header->redMask, proxyBitmapV5Header->greenMask, proxyBitmapV5Header->blueMask, proxyBitmapV5Header->alphaMask };
						}
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
					default: throw std::runtime_error("This Bitmap DIB header is not recognized."); break;
					}

					return stream;
				}

				std::ostream & operator<<(std::ostream & stream, DIBHeader & header)
				{
					switch (header.type) {
					case DIBHeaderType::BITMAPCOREHEADER:
					{
						auto proxyBitmapCoreHeader = BitmapCoreHeader{
							sizeof(BitmapCoreHeader),
							static_cast<std::int16_t>(header.width),
							static_cast<std::int16_t>(header.height),
							static_cast<std::uint16_t>(header.planes),
							static_cast<std::uint16_t>(header.bitCount)
						};
						stream.write(reinterpret_cast<char *>(&proxyBitmapCoreHeader), proxyBitmapCoreHeader.size);
						break;
					}
					case DIBHeaderType::OS21XBITMAPHEADER:
					{
						auto proxyOS21XBitmapHeader = OS21XBitmapHeader{
							sizeof(OS21XBitmapHeader),
							static_cast<std::uint16_t>(header.width),
							static_cast<std::uint16_t>(header.height),
							static_cast<std::uint16_t>(header.planes),
							static_cast<std::uint16_t>(header.bitCount)
						};
						stream.write(reinterpret_cast<char *>(&proxyOS21XBitmapHeader), proxyOS21XBitmapHeader.size);
						break;
					}
					case DIBHeaderType::OS22XBITMAPHEADER:
					{
						bool shortHeader = (header.compression == CompressionMethod::RGB) && (header.xResolution == 0) && (header.yResolution == 0) && (header.nbColorsUsed == 0) && (header.nbImportantColors == 0) && (header.halftoning.algorithm == DIBHeader::Halftoning::Algorithm::NONE);
						auto proxyOS22XBitmapHeader = OS22XBitmapHeader{};
						proxyOS22XBitmapHeader.size = shortHeader ? 16 : sizeof(OS22XBitmapHeader);
						proxyOS22XBitmapHeader.width = static_cast<std::uint32_t>(header.width);
						proxyOS22XBitmapHeader.height = static_cast<std::uint32_t>(header.height);
						proxyOS22XBitmapHeader.planes = static_cast<std::uint16_t>(header.planes);
						proxyOS22XBitmapHeader.bitCount = static_cast<std::uint16_t>(header.bitCount);

						if (!shortHeader) {
							proxyOS22XBitmapHeader.compression = static_cast<std::uint32_t>(header.compression);
							proxyOS22XBitmapHeader.imageSize = static_cast<std::uint32_t>(header.imageSize);
							proxyOS22XBitmapHeader.xResolution = static_cast<std::uint32_t>(header.xResolution);
							proxyOS22XBitmapHeader.yResolution = static_cast<std::uint32_t>(header.yResolution);
							proxyOS22XBitmapHeader.numberOfColorsUsed = static_cast<std::uint32_t>(header.nbColorsUsed);
							proxyOS22XBitmapHeader.numberOfImportantColors = static_cast<std::uint32_t>(header.nbImportantColors);
							proxyOS22XBitmapHeader.resolutionUnit = 1;
							proxyOS22XBitmapHeader.recordingAlgorithm = 0;
							proxyOS22XBitmapHeader.halftoningAlgorithm = static_cast<std::uint16_t>(header.halftoning.algorithm);
							proxyOS22XBitmapHeader.halftoningSize1 = static_cast<std::uint32_t>(header.halftoning.size1);
							proxyOS22XBitmapHeader.halftoningSize2 = static_cast<std::uint32_t>(header.halftoning.size2);
							proxyOS22XBitmapHeader.colorEncoding = 0;
							proxyOS22XBitmapHeader.identifier = 42; // Edencraft Engine identifier ?
						}
						stream.write(reinterpret_cast<char *>(&proxyOS22XBitmapHeader), proxyOS22XBitmapHeader.size);
						break;
					}
					case DIBHeaderType::BITMAPINFOHEADER:
					{
						auto proxyBitmapInfoHeader = BitmapInfoHeader{
							sizeof(BitmapInfoHeader),
							static_cast<std::uint32_t>(header.width),
							static_cast<std::uint32_t>(header.height),
							static_cast<std::uint16_t>(header.planes),
							static_cast<std::uint16_t>(header.bitCount),
							static_cast<std::uint32_t>(header.compression),
							static_cast<std::uint32_t>(header.imageSize),
							static_cast<std::uint32_t>(header.xResolution),
							static_cast<std::uint32_t>(header.yResolution),
							static_cast<std::uint32_t>(header.nbColorsUsed),
							static_cast<std::uint32_t>(header.nbImportantColors)
						};
						stream.write(reinterpret_cast<char *>(&proxyBitmapInfoHeader), proxyBitmapInfoHeader.size);
						break;
					}
					case DIBHeaderType::BITMAPV2INFOHEADER:
					{
						auto proxyBitmapV2InfoHeader = BitmapV2InfoHeader{
							sizeof(BitmapV2InfoHeader),
							static_cast<std::uint32_t>(header.width),
							static_cast<std::uint32_t>(header.height),
							static_cast<std::uint16_t>(header.planes),
							static_cast<std::uint16_t>(header.bitCount),
							static_cast<std::uint32_t>(header.compression),
							static_cast<std::uint32_t>(header.imageSize),
							static_cast<std::uint32_t>(header.xResolution),
							static_cast<std::uint32_t>(header.yResolution),
							static_cast<std::uint32_t>(header.nbColorsUsed),
							static_cast<std::uint32_t>(header.nbImportantColors),
							header.compression == CompressionMethod::BITFIELDS ? static_cast<std::uint32_t>(std::get<RGB<std::size_t>>(header.mask).r) : 0,
							header.compression == CompressionMethod::BITFIELDS ? static_cast<std::uint32_t>(std::get<RGB<std::size_t>>(header.mask).g) : 0,
							header.compression == CompressionMethod::BITFIELDS ? static_cast<std::uint32_t>(std::get<RGB<std::size_t>>(header.mask).b) : 0
						};
						stream.write(reinterpret_cast<char *>(&proxyBitmapV2InfoHeader), proxyBitmapV2InfoHeader.size);
						break;
					}
					case DIBHeaderType::BITMAPV3INFOHEADER:
					{
						auto proxyBitmapV3InfoHeader = BitmapV3InfoHeader{
							sizeof(BitmapV3InfoHeader),
							static_cast<std::uint32_t>(header.width),
							static_cast<std::uint32_t>(header.height),
							static_cast<std::uint16_t>(header.planes),
							static_cast<std::uint16_t>(header.bitCount),
							static_cast<std::uint32_t>(header.compression),
							static_cast<std::uint32_t>(header.imageSize),
							static_cast<std::uint32_t>(header.xResolution),
							static_cast<std::uint32_t>(header.yResolution),
							static_cast<std::uint32_t>(header.nbColorsUsed),
							static_cast<std::uint32_t>(header.nbImportantColors),
							header.compression == CompressionMethod::BITFIELDS ? static_cast<std::uint32_t>(std::get<RGBA<std::size_t>>(header.mask).r) : 0,
							header.compression == CompressionMethod::BITFIELDS ? static_cast<std::uint32_t>(std::get<RGBA<std::size_t>>(header.mask).g) : 0,
							header.compression == CompressionMethod::BITFIELDS ? static_cast<std::uint32_t>(std::get<RGBA<std::size_t>>(header.mask).b) : 0,
							header.compression == CompressionMethod::BITFIELDS ? static_cast<std::uint32_t>(std::get<RGBA<std::size_t>>(header.mask).a) : 0
						};
						stream.write(reinterpret_cast<char *>(&proxyBitmapV3InfoHeader), proxyBitmapV3InfoHeader.size);
						break;
					}
					case DIBHeaderType::BITMAPV4HEADER:
					{
						auto proxyBitmapV4Header = BitmapV4Header{
							sizeof(BitmapV4Header),
							static_cast<std::uint32_t>(header.width),
							static_cast<std::uint32_t>(header.height),
							static_cast<std::uint16_t>(header.planes),
							static_cast<std::uint16_t>(header.bitCount),
							static_cast<std::uint32_t>(header.compression),
							static_cast<std::uint32_t>(header.imageSize),
							static_cast<std::uint32_t>(header.xResolution),
							static_cast<std::uint32_t>(header.yResolution),
static_cast<std::uint32_t>(header.nbColorsUsed),
static_cast<std::uint32_t>(header.nbImportantColors),
header.compression == CompressionMethod::BITFIELDS ? static_cast<std::uint32_t>(std::get<RGBA<std::size_t>>(header.mask).r) : 0,
header.compression == CompressionMethod::BITFIELDS ? static_cast<std::uint32_t>(std::get<RGBA<std::size_t>>(header.mask).g) : 0,
header.compression == CompressionMethod::BITFIELDS ? static_cast<std::uint32_t>(std::get<RGBA<std::size_t>>(header.mask).b) : 0,
header.compression == CompressionMethod::BITFIELDS ? static_cast<std::uint32_t>(std::get<RGBA<std::size_t>>(header.mask).a) : 0,
static_cast<std::uint32_t>(header.colorSpace.type),
static_cast<std::uint32_t>(header.colorSpace.redEndpoint[0]),
static_cast<std::uint32_t>(header.colorSpace.redEndpoint[1]),
static_cast<std::uint32_t>(header.colorSpace.redEndpoint[2]),
static_cast<std::uint32_t>(header.colorSpace.greenEndpoint[0]),
static_cast<std::uint32_t>(header.colorSpace.greenEndpoint[1]),
static_cast<std::uint32_t>(header.colorSpace.greenEndpoint[2]),
static_cast<std::uint32_t>(header.colorSpace.blueEndpoint[0]),
static_cast<std::uint32_t>(header.colorSpace.blueEndpoint[1]),
static_cast<std::uint32_t>(header.colorSpace.blueEndpoint[2]),
static_cast<std::uint32_t>(header.gamma.r),
static_cast<std::uint32_t>(header.gamma.g),
static_cast<std::uint32_t>(header.gamma.b)
						};
						stream.write(reinterpret_cast<char *>(&proxyBitmapV4Header), proxyBitmapV4Header.size);
						break;
					}
					case DIBHeaderType::BITMAPV5HEADER:
					{
						auto proxyBitmapV5Header = BitmapV5Header{
							sizeof(BitmapV5Header),
							static_cast<std::uint32_t>(header.width),
							static_cast<std::uint32_t>(header.height),
							static_cast<std::uint16_t>(header.planes),
							static_cast<std::uint16_t>(header.bitCount),
							static_cast<std::uint32_t>(header.compression),
							static_cast<std::uint32_t>(header.imageSize),
							static_cast<std::uint32_t>(header.xResolution),
							static_cast<std::uint32_t>(header.yResolution),
							static_cast<std::uint32_t>(header.nbColorsUsed),
							static_cast<std::uint32_t>(header.nbImportantColors),
							header.compression == CompressionMethod::BITFIELDS || header.compression == CompressionMethod::ALPHABITFIELDS ? static_cast<std::uint32_t>(std::get<RGBA<std::size_t>>(header.mask).r) : 0,
							header.compression == CompressionMethod::BITFIELDS || header.compression == CompressionMethod::ALPHABITFIELDS ? static_cast<std::uint32_t>(std::get<RGBA<std::size_t>>(header.mask).g) : 0,
							header.compression == CompressionMethod::BITFIELDS || header.compression == CompressionMethod::ALPHABITFIELDS ? static_cast<std::uint32_t>(std::get<RGBA<std::size_t>>(header.mask).b) : 0,
							header.compression == CompressionMethod::BITFIELDS || header.compression == CompressionMethod::ALPHABITFIELDS ? static_cast<std::uint32_t>(std::get<RGBA<std::size_t>>(header.mask).a) : 0,
							static_cast<std::uint32_t>(header.colorSpace.type),
							static_cast<std::uint32_t>(header.colorSpace.redEndpoint[0]),
							static_cast<std::uint32_t>(header.colorSpace.redEndpoint[1]),
							static_cast<std::uint32_t>(header.colorSpace.redEndpoint[2]),
							static_cast<std::uint32_t>(header.colorSpace.greenEndpoint[0]),
							static_cast<std::uint32_t>(header.colorSpace.greenEndpoint[1]),
							static_cast<std::uint32_t>(header.colorSpace.greenEndpoint[2]),
							static_cast<std::uint32_t>(header.colorSpace.blueEndpoint[0]),
							static_cast<std::uint32_t>(header.colorSpace.blueEndpoint[1]),
							static_cast<std::uint32_t>(header.colorSpace.blueEndpoint[2]),
							static_cast<std::uint32_t>(header.gamma.r),
							static_cast<std::uint32_t>(header.gamma.g),
							static_cast<std::uint32_t>(header.gamma.b),
							static_cast<std::uint32_t>(header.intent),
							static_cast<std::uint32_t>(header.profile.data),
							static_cast<std::uint32_t>(header.profile.size),
							0
						};
						stream.write(reinterpret_cast<char *>(&proxyBitmapV5Header), proxyBitmapV5Header.size);
						break;
					}
					default: throw std::runtime_error("This Bitmap DIB header is not recognized."); break;
					}

					return stream;
				}

				std::size_t DIBHeader::getBPP() const
				{
					return this->bitCount < 8 ? 1 : this->bitCount >> 3;
				}


				bool DIBHeader::isValid() const
				{
					if (this->height == 0 && this->width < 1) {
						return false;
					}
					if (this->planes != 1) {
						return false;
					}
					if (this->bitCount != 1 && this->bitCount != 4 && this->bitCount != 8 && this->bitCount != 16 && this->bitCount != 24 && this->bitCount != 32) {
						return false;
					}
					if (this->compression == CompressionMethod::BITFIELDS && this->bitCount != 16 && this->bitCount != 32) {
						return false;
					}
					if (this->imageSize == 0 && this->compression != CompressionMethod::RGB) {
						return false;
					}
					if (this->compression == CompressionMethod::RLE4 && this->bitCount != 4) {
						return false;
					}
					if (this->compression == CompressionMethod::RLE8 && this->bitCount != 8) {
						return false;
					}
					if (this->compression == CompressionMethod::JPEG && this->bitCount != 24) {
						return false;
					}
					if ((this->bitCount == 16 || this->bitCount == 32) && this->compression != CompressionMethod::RGB) {
						return false;
					}
					if (this->bitCount < 16 && this->nbColorsUsed != std::pow(2, this->bitCount) && this->nbColorsUsed != 0) {
						return false;
					}
					if (this->bitCount >= 16 && this->nbColorsUsed != 0) {
						return false;
					}

					return true;
				}
			} // namespace bitmap
		} // namespace formats
	} // namespace utility
} // namespace ece