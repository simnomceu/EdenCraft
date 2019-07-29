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

#ifndef DIB_HEADER_HPP
#define DIB_HEADER_HPP

#ifdef _MSC_VER
#	undef PROFILE_EMBEDDED
#endif

#include "utility/config.hpp"
#include "utility/pch.hpp"
#include "utility/formats/bitmap/dib_header_type.hpp"
#include "utility/formats/bitmap/compression_method.hpp"
#include "utility/types.hpp"
#include "utility/mathematics.hpp"

namespace ece
{
	namespace utility
	{
		namespace formats
		{
			namespace bitmap
			{
				/**
				 * @struct BMPDIB
				 * @brief The internal data about the image, according to the file format specification.
				 */
				class ECE_UTILITY_API DIBHeader
				{
				public:
					DIBHeader() noexcept;

					ECE_UTILITY_API friend std::istream & operator>>(std::istream & stream, DIBHeader & header);

					ECE_UTILITY_API friend std::ostream & operator<<(std::ostream & stream, DIBHeader & header);

					struct Halftoning
					{
						enum class Algorithm
						{
							NONE = 0,
							ERROR_DIFFUSION = 1,
							PANDA = 2,
							SUPER_CIRCLE = 3
						};

						Algorithm algorithm;
						std::size_t size1;
						std::size_t size2;

						// https://imageprocessing-sankarsrin.blogspot.com/2017/04/digital-half-toning-error-diffusion.html
					};

					struct ColorSpace
					{
						enum class Type
						{
							CALIBRATED_RGB = 0x00000000,
							SRGB = 0x73524742,
							WINDOWS_COLOR_SPACE = 0x57696E20,
							POFILE_LINKED,
							PROFILE_EMBEDDED
						};

						Type type;
						ece::Vector3u<std::size_t> redEndpoint;
						ece::Vector3u<std::size_t> greenEndpoint;
						ece::Vector3u<std::size_t> blueEndpoint;
					};

					enum class IntentMapping : unsigned short int
					{
						NONE = 0,
						BUSINESS = 1,
						GRAPHICS = 2,
						IMAGES = 4,
						ABS_COLORIMETRIC = 8
					};

					struct Profile
					{
						std::size_t data;
						std::size_t size;
					};

					std::size_t size;
					DIBHeaderType type;
					std::int32_t width;
					std::int32_t height;
					std::size_t planes;
					std::size_t bitCount;
					CompressionMethod compression;
					std::size_t imageSize;
					std::int32_t xResolution;
					std::int32_t yResolution;
					std::int32_t nbColorsUsed;
					std::size_t nbImportantColors;
					Halftoning halftoning;
					std::variant<RGB24, RGBA32> mask;
					ColorSpace colorSpace;
					RGB24 gamma;
					IntentMapping intent;
					Profile profile;
				};
			} // namespace bitmap
		} // namespace formats
	} // namespace utility
} // namespace ece

#endif // DIB_HEADER_HPP