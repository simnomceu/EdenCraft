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

#ifndef IMAGE_FORMAT_HPP
#define IMAGE_FORMAT_HPP

#include "renderer/config.hpp"

#include <cstddef>

namespace ece
{
	namespace renderer
	{
		namespace image
		{
			struct ECE_RENDERER_API RGB24
			{
				std::byte red;
				std::byte green;
				std::byte blue;

				inline RGB24(): red(), green(), blue() {}

				inline RGB24(const unsigned short int r, const unsigned short int g, const unsigned short int b):
					red(static_cast<std::byte>(r)), green(static_cast<std::byte>(g)), blue(static_cast<std::byte>(b)) {}
			};

			struct ECE_RENDERER_API RGBA32 : public RGB24
			{
				std::byte alpha;

				inline RGBA32(): RGB24(), alpha() {}

				inline RGBA32(const unsigned short int r, const unsigned short int g, const unsigned short int b, const unsigned short int a):
					RGB24(r, g, b), alpha(static_cast<std::byte>(a)) {}
			};

			struct ECE_RENDERER_API HSV
			{
				unsigned short int hue;
				unsigned short int saturation;
				unsigned short int value;
			};

			struct ECE_RENDERER_API HSL
			{
				unsigned short int hue;
				unsigned short int saturation;
				unsigned short int lightness;
			};

			struct ECE_RENDERER_API CMYK
			{
				unsigned short int cyan;
				unsigned short int magenta;
				unsigned short int yellow;
				unsigned short int key;
			};
		} // namespace image
	} // namespace renderer
} // namespace ece

#endif // IMAGE_FORMAT_HPP
