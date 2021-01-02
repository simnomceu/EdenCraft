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
#include "utility/type/pixel_format.hpp"

#ifdef _MSC_VER
#	define sscanf sscanf_s
#endif

namespace ece
{
	namespace utility
	{
		namespace type
		{
			RGB24 toRGB24(const RGBf & color)
			{
				return { static_cast<std::uint8_t>(color.r * 255), static_cast<std::uint8_t>(color.g * 255), static_cast<std::uint8_t>(color.b * 255) };
			}

			RGBf toRGBf(const RGB24 & color)
			{
				auto result = RGBf();
				result.r = color.r / 255.0f;
				result.g = color.g / 255.0f;
				result.b = color.b / 255.0f;
				return result;
			}

			RGB24 toRGB24(const RGBA32 & color)
			{
				return RGB24(color);
			}

			RGBf toRGBf(const RGBA32 & color)
			{
				auto result = RGBf();
				result.r = color.r / 255.0f;
				result.g = color.g / 255.0f;
				result.b = color.b / 255.0f;
				return result;
			}

			RGBA32 toRGBA32(const RGB24 & color)
			{
				return { color.r, color.g, color.b, 255 };
			}

			RGBA32 toRGBA32(const RGBf & color)
			{
				return { static_cast<std::uint8_t>(color.r * 255), static_cast<std::uint8_t>(color.g * 255), static_cast<std::uint8_t>(color.b * 255), 255 };
			}

			RGB24 toRGB24(const RGBAf & color)
			{
				return { static_cast<std::uint8_t>(color.r * 255), static_cast<std::uint8_t>(color.g * 255), static_cast<std::uint8_t>(color.b * 255) };
			}

			RGBf toRGBf(const RGBAf & color)
			{
				return color;
			}

			RGBA32 toRGBA32(const RGBAf & color)
			{
				return { static_cast<std::uint8_t>(color.r * 255), static_cast<std::uint8_t>(color.g * 255), static_cast<std::uint8_t>(color.b * 255), static_cast<std::uint8_t>(color.a * 255) };
			}

			RGBAf toRGBAf(const RGB24 & color)
			{
				auto result = RGBAf();
				result.r = color.r / 255.0f;
				result.g = color.g / 255.0f;
				result.b = color.b / 255.0f;
				result.a = 1.0f;
				return result;
			}

			RGBAf toRGBAf(const RGBf & color)
			{
				auto result = RGBAf();
				result.r = color.r;
				result.g = color.g;
				result.b = color.b;
				result.a = 1.0f;
				return result;
			}

			RGBAf toRGBAf(const RGBA32 & color)
			{
				auto result = RGBAf();
				result.r = color.r / 255.0f;
				result.g = color.g / 255.0f;
				result.b = color.b / 255.0f;
				result.a = color.a / 255.0f;
				return result;
			}

			RGB24 toRGB24(const BGR24 & color)
			{
				return { color.r, color.g, color.b };
			}

			RGBf toRGBf(const BGR24 & color)
			{
				auto result = RGBf();
				result.r = color.r / 255.0f;
				result.g = color.g / 255.0f;
				result.b = color.b / 255.0f;
				return result;
			}

			RGBA32 toRGBA32(const BGR24 & color)
			{
				return { color.r, color.g, color.b, 250 };
			}

			RGBAf toRGBAf(const BGR24 & color)
			{
				auto result = RGBAf();
				result.r = color.r / 255.0f;
				result.g = color.g / 255.0f;
				result.b = color.b / 255.0f;
				result.a = 1.0f;
				return result;
			}

			BGR24 toBGR24(const RGB24 & color)
			{
				return { color.b, color.g, color.r };
			}

			BGR24 toBGR24(const RGBf & color)
			{
				return { static_cast<std::uint8_t>(color.b * 255), static_cast<std::uint8_t>(color.g * 255), static_cast<std::uint8_t>(color.r * 255) };
			}

			BGR24 toBGR24(const RGBA32 & color)
			{
				return { color.b, color.g, color.r };
			}

			BGR24 toBGR24(const RGBAf & color)
			{
				return { static_cast<std::uint8_t>(color.b * 255), static_cast<std::uint8_t>(color.g * 255), static_cast<std::uint8_t>(color.r * 255) };
			}

			RGB24 toRGB24(const BGRf & color)
			{
				return { static_cast<std::uint8_t>(color.r * 255), static_cast<std::uint8_t>(color.g * 255), static_cast<std::uint8_t>(color.b * 255) };
			}

			RGBf toRGBf(const BGRf & color)
			{
				return { color.r, color.g, color.b };
			}

			RGBA32 toRGBA32(const BGRf & color)
			{
				return { static_cast<std::uint8_t>(color.r * 255), static_cast<std::uint8_t>(color.g * 255), static_cast<std::uint8_t>(color.b * 255), 255 };
			}

			RGBAf toRGBAf(const BGRf & color)
			{
				auto result = RGBAf();
				result.r = color.r;
				result.g = color.g;
				result.b = color.b;
				result.a = 1.0f;
				return result;
			}

			BGR24 toBGR24(const BGRf & color)
			{
				return { static_cast<std::uint8_t>(color.b * 255), static_cast<std::uint8_t>(color.g * 255), static_cast<std::uint8_t>(color.r * 255) };
			}

			BGRf toBGRf(const RGB24 & color)
			{
				auto result = BGRf();
				result.b = color.b / 255.0f;
				result.g = color.g / 255.0f;
				result.r = color.r / 255.0f;
				return result;
			}

			BGRf toBGRf(const RGBf & color)
			{
				return { color.b, color.g, color.r };
			}

			BGRf toBGRf(const RGBA32 & color)
			{
				auto result = BGRf();
				result.b = color.b / 255.0f;
				result.g = color.g / 255.0f;
				result.r = color.r / 255.0f;
				return result;
			}

			BGRf toBGRf(const RGBAf & color)
			{
				return { color.b, color.g, color.r };
			}

			BGRf toBGRf(const BGR24 & color)
			{
				auto result = BGRf();
				result.b = color.b / 255.0f;
				result.g = color.g / 255.0f;
				result.r = color.r / 255.0f;
				return result;
			}

			RGB24 toRGB24(const BGRA32 & color)
			{
				return { color.r, color.g, color.b };
			}

			RGBf toRGBf(const BGRA32 & color)
			{
				auto result = RGBf();
				result.r = color.r / 255.0f;
				result.g = color.g / 255.0f;
				result.b = color.b / 255.0f;
				return result;
			}

			RGBA32 toRGBA32(const BGRA32 & color)
			{
				return RGBA32{ color.r, color.g, color.b, color.a };
			}

			RGBAf toRGBAf(const BGRA32 & color)
			{
				auto result = RGBAf();
				result.r = color.r / 255.0f;
				result.g = color.g / 255.0f;
				result.b = color.b / 255.0f;
				result.a = 1.0f;
				return result;
			}

			BGR24 toBGR24(const BGRA32 & color)
			{
				return BGR24(color);
			}

			BGRf toBGRf(const BGRA32 & color)
			{
				auto result = BGRf();
				result.b = color.b / 255.0f;
				result.g = color.g / 255.0f;
				result.r = color.r / 255.0f;
				return result;
			}

			BGRA32 toBGRA32(const RGB24 & color)
			{
				return { color.b, color.g, color.r, 255 };
			}

			BGRA32 toBGRA32(const RGBf & color)
			{
				return { static_cast<std::uint8_t>(color.b * 255), static_cast<std::uint8_t>(color.g * 255), static_cast<std::uint8_t>(color.r * 255), 255 };
			}

			BGRA32 toBGRA32(const RGBA32 & color)
			{
				return { color.b, color.g, color.r, color.a };
			}

			BGRA32 toBGRA32(const RGBAf & color)
			{
				return { static_cast<std::uint8_t>(color.b * 255), static_cast<std::uint8_t>(color.g * 255), static_cast<std::uint8_t>(color.r * 255), static_cast<std::uint8_t>(color.a * 255) };
			}

			BGRA32 toBGRA32(const BGR24 & color)
			{
				return { color.b, color.g, color.r, 255 };
			}

			BGRA32 toBGRA32(const BGRf & color)
			{
				return { static_cast<std::uint8_t>(color.b * 255), static_cast<std::uint8_t>(color.g * 255), static_cast<std::uint8_t>(color.r * 255), 255 };
			}

			RGB24 toRGB24(const BGRAf & color)
			{
				return { static_cast<std::uint8_t>(color.r * 255), static_cast<std::uint8_t>(color.g * 255), static_cast<std::uint8_t>(color.b * 255) };
			}

			RGBf toRGBf(const BGRAf & color)
			{
				return { color.r, color.g, color.b };
			}

			RGBA32 toRGBA32(const BGRAf & color)
			{
				return { static_cast<std::uint8_t>(color.r * 255), static_cast<std::uint8_t>(color.g * 255), static_cast<std::uint8_t>(color.b * 255), static_cast<std::uint8_t>(color.a * 255) };
			}

			RGBAf toRGBAf(const BGRAf & color)
			{
				return { color.r, color.g, color.b, color.a };
			}

			BGR24 toBGR24(const BGRAf & color)
			{
				return { static_cast<std::uint8_t>(color.b * 255), static_cast<std::uint8_t>(color.g * 255), static_cast<std::uint8_t>(color.r * 255) };
			}

			BGRf toBGRf(const BGRAf & color)
			{
				return { color.b, color.g, color.r };
			}

			BGRA32 toBGRA32(const BGRAf & color)
			{
				return { static_cast<std::uint8_t>(color.b), static_cast<std::uint8_t>(color.g), static_cast<std::uint8_t>(color.r), static_cast<std::uint8_t>(color.a) };
			}

			BGRAf toBGRAf(const RGB24 & color)
			{
				auto result = BGRAf();
				result.b = color.b / 255.0f;
				result.g = color.g / 255.0f;
				result.r = color.r / 255.0f;
				result.a = 1.0f;
				return result;
			}

			BGRAf toBGRAf(const RGBf & color)
			{
				auto result = BGRAf();
				result.b = color.b;
				result.g = color.g;
				result.r = color.r;
				result.a = 1.0f;
				return result;
			}

			BGRAf toBGRAf(const RGBA32 & color)
			{
				auto result = BGRAf();
				result.b = color.b / 255.0f;
				result.g = color.g / 255.0f;
				result.r = color.r / 255.0f;
				result.a = color.a / 255.0f;
				return result;
			}

			BGRAf toBGRAf(const RGBAf & color)
			{
				auto result = BGRAf();
				result.b = color.b;
				result.g = color.g;
				result.r = color.r;
				result.a = color.a;
				return result;
			}

			BGRAf toBGRAf(const BGR24 & color)
			{
				auto result = BGRAf();
				result.b = color.b / 255.0f;
				result.g = color.g / 255.0f;
				result.r = color.r / 255.0f;
				result.a = 1.0f;
				return result;
			}

			BGRAf toBGRAf(const BGRf & color)
			{
				auto result = BGRAf();
				result.b = color.b;
				result.g = color.g;
				result.r = color.r;
				result.a = 1.0f;
				return result;
			}

			BGRAf toBGRAf(const BGRA32 & color)
			{
				auto result = BGRAf();
				result.b = color.b / 255.0f;
				result.g = color.g / 255.0f;
				result.r = color.r / 255.0f;
				result.a = color.a / 255.0f;
				return result;
			}

			RGB24 toRGB24(const CMYK & color)
			{
				auto result = RGB24();
				result.r = 255 - static_cast<std::uint8_t>((std::min(1.0f, color.c * (1.0f - color.k) + color.k)) * 255);
				result.g = 255 - static_cast<std::uint8_t>((std::min(1.0f, color.m * (1.0f - color.k) + color.k)) * 255);
				result.b = 255 - static_cast<std::uint8_t>((std::min(1.0f, color.y * (1.0f - color.k) + color.k)) * 255);
				return result;
			}

			RGBf toRGBf(const CMYK & color)
			{
				auto result = RGBf();
				result.r = (255.0f - ((std::min(1.0f, color.c * (1.0f - color.k) + color.k)) * 255.0f)) / 255.0f;
				result.g = (255.0f - ((std::min(1.0f, color.m * (1.0f - color.k) + color.k)) * 255.0f)) / 255.0f;
				result.b = (255.0f - ((std::min(1.0f, color.y * (1.0f - color.k) + color.k)) * 255.0f)) / 255.0f;
				return result;
			}

			RGBA32 toRGBA32(const CMYK & color)
			{
				auto result = RGBA32();
				result.r = 255 - static_cast<std::uint8_t>((std::min(1.0f, color.c * (1.0f - color.k) + color.k)) * 255);
				result.g = 255 - static_cast<std::uint8_t>((std::min(1.0f, color.m * (1.0f - color.k) + color.k)) * 255);
				result.b = 255 - static_cast<std::uint8_t>((std::min(1.0f, color.y * (1.0f - color.k) + color.k)) * 255);
				result.a = 255;
				return result;
			}

			RGBAf toRGBAf(const CMYK & color)
			{
				auto result = RGBAf();
				result.r = (255.0f - ((std::min(1.0f, color.c * (1.0f - color.k) + color.k)) * 255.0f)) / 255.0f;
				result.g = (255.0f - ((std::min(1.0f, color.m * (1.0f - color.k) + color.k)) * 255.0f)) / 255.0f;
				result.b = (255.0f - ((std::min(1.0f, color.y * (1.0f - color.k) + color.k)) * 255.0f)) / 255.0f;
				result.a = 1.0f;
				return result;
			}

			BGR24 toBGR24(const CMYK & color)
			{
				auto result = BGR24();
				result.r = 255 - static_cast<std::uint8_t>((std::min(1.0f, color.c * (1.0f - color.k) + color.k)) * 255);
				result.g = 255 - static_cast<std::uint8_t>((std::min(1.0f, color.m * (1.0f - color.k) + color.k)) * 255);
				result.b = 255 - static_cast<std::uint8_t>((std::min(1.0f, color.y * (1.0f - color.k) + color.k)) * 255);
				return result;
			}

			BGRf toBGRf(const CMYK & color)
			{
				auto result = BGRf();
				result.r = (255.0f - ((std::min(1.0f, color.c * (1.0f - color.k) + color.k)) * 255.0f)) / 255.0f;
				result.g = (255.0f - ((std::min(1.0f, color.m * (1.0f - color.k) + color.k)) * 255.0f)) / 255.0f;
				result.b = (255.0f - ((std::min(1.0f, color.y * (1.0f - color.k) + color.k)) * 255.0f)) / 255.0f;
				return result;
			}

			BGRA32 toBGRA32(const CMYK & color)
			{
				auto result = BGRA32();
				result.r = 255 - static_cast<std::uint8_t>((std::min(1.0f, color.c * (1.0f - color.k) + color.k)) * 255);
				result.g = 255 - static_cast<std::uint8_t>((std::min(1.0f, color.m * (1.0f - color.k) + color.k)) * 255);
				result.b = 255 - static_cast<std::uint8_t>((std::min(1.0f, color.y * (1.0f - color.k) + color.k)) * 255);
				result.a = 255;
				return result;
			}

			BGRAf toBGRAf(const CMYK & color)
			{
				auto result = BGRAf();
				result.r = (255.0f - ((std::min(1.0f, color.c * (1.0f - color.k) + color.k)) * 255.0f)) / 255.0f;
				result.g = (255.0f - ((std::min(1.0f, color.m * (1.0f - color.k) + color.k)) * 255.0f)) / 255.0f;
				result.b = (255.0f - ((std::min(1.0f, color.y * (1.0f - color.k) + color.k)) * 255.0f)) / 255.0f;
				result.a = 1.0f;
				return result;
			}

			CMYK toCMYK(const RGB24 & color)
			{
				auto r = color.r / 255.0f;
				auto g = color.g / 255.0f;
				auto b = color.b / 255.0f;
				auto result = CMYK();
				result.k = 1.0f - std::max({ r, g, b });

				result.c = result.k == 1.0f ? 0.0f : (1.0f - r - result.k) / (1.0f - result.k);
				result.m = result.k == 1.0f ? 0.0f : (1.0f - g - result.k) / (1.0f - result.k);
				result.y = result.k == 1.0f ? 0.0f : (1.0f - b - result.k) / (1.0f - result.k);

				return result;
			}

			CMYK toCMYK(const RGBf & color)
			{
				auto result = CMYK();
				result.k = 1.0f - std::max({ color.r, color.g, color.b });

				result.c = result.k == 1.0f ? 0.0f : (1.0f - color.r - result.k) / (1.0f - result.k);
				result.m = result.k == 1.0f ? 0.0f : (1.0f - color.g - result.k) / (1.0f - result.k);
				result.y = result.k == 1.0f ? 0.0f : (1.0f - color.b - result.k) / (1.0f - result.k);

				return result;
			}

			CMYK toCMYK(const RGBA32 & color)
			{
				auto r = color.r / 255.0f;
				auto g = color.g / 255.0f;
				auto b = color.b / 255.0f;
				auto result = CMYK();
				result.k = 1.0f - std::max({ r, g, b });

				result.c = result.k == 1.0f ? 0.0f : (1.0f - r - result.k) / (1.0f - result.k);
				result.m = result.k == 1.0f ? 0.0f : (1.0f - g - result.k) / (1.0f - result.k);
				result.y = result.k == 1.0f ? 0.0f : (1.0f - b - result.k) / (1.0f - result.k);

				return result;
			}

			CMYK toCMYK(const RGBAf & color)
			{
				auto result = CMYK();
				result.k = 1.0f - std::max({ color.r, color.g, color.b });

				result.c = result.k == 1.0f ? 0.0f : (1.0f - color.r - result.k) / (1.0f - result.k);
				result.m = result.k == 1.0f ? 0.0f : (1.0f - color.g - result.k) / (1.0f - result.k);
				result.y = result.k == 1.0f ? 0.0f : (1.0f - color.b - result.k) / (1.0f - result.k);

				return result;
			}

			CMYK toCMYK(const BGR24 & color)
			{
				auto r = color.r / 255.0f;
				auto g = color.g / 255.0f;
				auto b = color.b / 255.0f;
				auto result = CMYK();
				result.k = 1.0f - std::max({ r, g, b });

				result.c = result.k == 1.0f ? 0.0f : (1.0f - r - result.k) / (1.0f - result.k);
				result.m = result.k == 1.0f ? 0.0f : (1.0f - g - result.k) / (1.0f - result.k);
				result.y = result.k == 1.0f ? 0.0f : (1.0f - b - result.k) / (1.0f - result.k);

				return result;
			}

			CMYK toCMYK(const BGRf & color)
			{
				auto result = CMYK();
				result.k = 1.0f - std::max({ color.r, color.g, color.b });

				result.c = result.k == 1.0f ? 0.0f : (1.0f - color.r - result.k) / (1.0f - result.k);
				result.m = result.k == 1.0f ? 0.0f : (1.0f - color.g - result.k) / (1.0f - result.k);
				result.y = result.k == 1.0f ? 0.0f : (1.0f - color.b - result.k) / (1.0f - result.k);

				return result;
			}

			CMYK toCMYK(const BGRA32 & color)
			{
				auto r = color.r / 255.0f;
				auto g = color.g / 255.0f;
				auto b = color.b / 255.0f;
				auto result = CMYK();
				result.k = 1.0f - std::max({ r, g, b });

				result.c = result.k == 1.0f ? 0.0f : (1.0f - r - result.k) / (1.0f - result.k);
				result.m = result.k == 1.0f ? 0.0f : (1.0f - g - result.k) / (1.0f - result.k);
				result.y = result.k == 1.0f ? 0.0f : (1.0f - b - result.k) / (1.0f - result.k);

				return result;
			}

			CMYK toCMYK(const BGRAf & color)
			{
				auto result = CMYK();
				result.k = 1.0f - std::max({ color.r, color.g, color.b });

				result.c = result.k == 1.0f ? 0.0f : (1.0f - color.r - result.k) / (1.0f - result.k);
				result.m = result.k == 1.0f ? 0.0f : (1.0f - color.g - result.k) / (1.0f - result.k);
				result.y = result.k == 1.0f ? 0.0f : (1.0f - color.b - result.k) / (1.0f - result.k);

				return result;
			}

			RGB24 toRGB24(const std::string & color)
			{
				auto result = RGB24();
				int r, g, b;
				sscanf(color.data(), "#%02x%02x%02x", &r, &g, &b);
				result.r = static_cast<std::uint8_t>(r);
				result.g = static_cast<std::uint8_t>(g);
				result.b = static_cast<std::uint8_t>(b);
				return result;
			}

			RGBf toRGBf(const std::string & color)
			{
				auto result = RGBf();
				int r, g, b;
				sscanf(color.data(), "#%02x%02x%02x", &r, &g, &b);
				result.r = r / 255.0f;
				result.g = g / 255.0f;
				result.b = b / 255.0f;
				return result;
			}

			RGBA32 toRGBA32(const std::string & color)
			{
				auto result = RGBA32();
				int r, g, b;
				sscanf(color.data(), "#%02x%02x%02x", &r, &g, &b);
				result.r = static_cast<std::uint8_t>(r);
				result.g = static_cast<std::uint8_t>(g);
				result.b = static_cast<std::uint8_t>(b);
				result.a = 255;
				return result;
			}

			RGBAf toRGBAf(const std::string & color)
			{
				auto result = RGBAf();
				int r, g, b;
				sscanf(color.data(), "#%02x%02x%02x", &r, &g, &b);
				result.r = r / 255.0f;
				result.g = g / 255.0f;
				result.b = b / 255.0f;
				result.a = 1.0f;
				return result;
			}

			BGR24 toBGR24(const std::string & color)
			{
				auto result = BGR24();
				int r, g, b;
				sscanf(color.data(), "#%02x%02x%02x", &r, &g, &b);
				result.r = static_cast<std::uint8_t>(r);
				result.g = static_cast<std::uint8_t>(g);
				result.b = static_cast<std::uint8_t>(b);
				return result;
			}

			BGRf toBGRf(const std::string & color)
			{
				auto result = BGRf();
				int r, g, b;
				sscanf(color.data(), "#%02x%02x%02x", &r, &g, &b);
				result.r = r / 255.0f;
				result.g = g / 255.0f;
				result.b = b / 255.0f;
				return result;
			}

			BGRA32 toBGRA32(const std::string & color)
			{
				auto result = BGRA32();
				int r, g, b;
				sscanf(color.data(), "#%02x%02x%02x", &r, &g, &b);
				result.r = static_cast<std::uint8_t>(r);
				result.g = static_cast<std::uint8_t>(g);
				result.b = static_cast<std::uint8_t>(b);
				result.a = 255;
				return result;
			}

			BGRAf toBGRAf(const std::string & color)
			{
				auto result = BGRAf();
				int r, g, b;
				sscanf(color.data(), "#%02x%02x%02x", &r, &g, &b);
				result.r = r / 255.0f;
				result.g = g / 255.0f;
				result.b = b / 255.0f;
				result.a = 1.0f;
				return result;
			}

			CMYK toCMYK(const std::string & color)
			{
				return toCMYK(toRGB24(color));
			}

			std::string toHex(const RGB24 & color)
			{
				auto stream = std::ostringstream();
				stream << '#';
				if (color.r <= 9) {
					stream << '0';
				}
				stream << std::hex << color.r;
				if (color.g <= 9) {
					stream << '0';
				}
				stream << std::hex << color.g;
				if (color.b <= 9) {
					stream << '0';
				}
				stream << std::hex << color.b;
				return stream.str();
			}

			std::string toHex(const RGBf & color)
			{
				auto stream = std::ostringstream();
				stream << '#';
				if (color.r <= 9.0f / 255.0f) {
					stream << '0';
				}
				stream << std::hex << color.r * 255;
				if (color.g <= 9.0f / 255.0f) {
					stream << '0';
				}
				stream << std::hex << color.g * 255;
				if (color.b <= 9.0f / 255.0f) {
					stream << '0';
				}
				stream << std::hex << color.b * 255;
				return stream.str();
			}

			std::string toHex(const RGBA32 & color)
			{
				auto stream = std::ostringstream();
				stream << '#';
				if (color.r <= 9) {
					stream << '0';
				}
				stream << std::hex << color.r;
				if (color.g <= 9) {
					stream << '0';
				}
				stream << std::hex << color.g;
				if (color.b <= 9) {
					stream << '0';
				}
				stream << std::hex << color.b;
				return stream.str();
			}

			std::string toHex(const RGBAf & color)
			{
				auto stream = std::ostringstream();
				stream << '#';
				if (color.r <= 9.0f / 255.0f) {
					stream << '0';
				}
				stream << std::hex << color.r * 255;
				if (color.g <= 9.0f / 255.0f) {
					stream << '0';
				}
				stream << std::hex << color.g * 255;
				if (color.b <= 9.0f / 255.0f) {
					stream << '0';
				}
				stream << std::hex << color.b * 255;
				return stream.str();
			}

			std::string toHex(const BGR24 & color)
			{
				auto stream = std::ostringstream();
				stream << '#';
				if (color.r <= 9) {
					stream << '0';
				}
				stream << std::hex << color.r;
				if (color.g <= 9) {
					stream << '0';
				}
				stream << std::hex << color.g;
				if (color.b <= 9) {
					stream << '0';
				}
				stream << std::hex << color.b;
				return stream.str();
			}

			std::string toHex(const BGRf & color)
			{
				auto stream = std::ostringstream();
				stream << '#';
				if (color.r <= 9.0f / 255.0f) {
					stream << '0';
				}
				stream << std::hex << color.r * 255;
				if (color.g <= 9.0f / 255.0f) {
					stream << '0';
				}
				stream << std::hex << color.g * 255;
				if (color.b <= 9.0f / 255.0f) {
					stream << '0';
				}
				stream << std::hex << color.b * 255;
				return stream.str();
			}

			std::string toHex(const BGRA32 & color)
			{
				auto stream = std::ostringstream();
				stream << '#';
				if (color.r <= 9) {
					stream << '0';
				}
				stream << std::hex << color.r;
				if (color.g <= 9) {
					stream << '0';
				}
				stream << std::hex << color.g;
				if (color.b <= 9) {
					stream << '0';
				}
				stream << std::hex << color.b;
				return stream.str();
			}

			std::string toHex(const BGRAf & color)
			{
				auto stream = std::ostringstream();
				stream << '#';
				if (color.r <= 9.0f / 255.0f) {
					stream << '0';
				}
				stream << std::hex << color.r * 255;
				if (color.g <= 9.0f / 255.0f) {
					stream << '0';
				}
				stream << std::hex << color.g * 255;
				if (color.b <= 9.0f / 255.0f) {
					stream << '0';
				}
				stream << std::hex << color.b * 255;
				return stream.str();
			}

			std::string toHex(const CMYK & color)
			{
				return toHex(toRGB24(color));
			}

			RGB24 toRGB24(const HSL & color)
			{
				auto result = RGB24();

				auto hue = color.hue / 60;
				auto t1 = 0.0f;
				auto t2 = 0.0f;
				if (color.light <= 0.5) {
					t2 = color.light * (color.saturation + 1);
				}
				else {
					t2 = color.light + color.saturation - (color.light * color.saturation);
				}
				t1 = color.light * 2 - t2;

				auto hueToRGB24 = [](const auto t1, const auto t2, auto hue) -> auto {
					if (hue < 0) {
						hue += 6;
					}
					else if (hue >= 6) {
						hue -= 6;
					}

					if (hue < 1) {
						return (t2 - t1) * hue + t1;
					}
					else if (hue < 3) {
						return t2;
					}
					else if (hue < 4) {
						return (t2 - t1) * (4 - hue) + t1;
					}
					else {
						return t1;
					}
				};

				result.r = static_cast<std::uint8_t>(hueToRGB24(t1, t2, hue + 2) * 255);
				result.g = static_cast<std::uint8_t>(hueToRGB24(t1, t2, hue) * 255);
				result.b = static_cast<std::uint8_t>(hueToRGB24(t1, t2, hue - 2) * 255);
				return result;
			}

			RGBf toRGBf(const HSL & color)
			{
				return toRGBf(toRGB24(color));
			}

			RGBA32 toRGBA32(const HSL & color)
			{
				return toRGBA32(toRGB24(color));
			}

			RGBAf toRGBAf(const HSL & color)
			{
				return toRGBAf(toRGB24(color));
			}

			BGR24 toBGR24(const HSL & color)
			{
				return toBGR24(toRGB24(color));
			}

			BGRf toBGRf(const HSL & color)
			{
				return toBGRf(toRGB24(color));
			}

			BGRA32 toBGRA32(const HSL & color)
			{
				return toBGRA32(toRGB24(color));
			}

			BGRAf toBGRAf(const HSL & color)
			{
				return toBGRAf(toRGB24(color));
			}

			CMYK toCMYK(const HSL & color)
			{
				return toCMYK(toRGB24(color));
			}

			std::string toHex(const HSL & color)
			{
				return toHex(toRGB24(color));
			}

			HSL toHSL(const RGB24 & color)
			{
				HSL result;

				auto min = std::min({ color.r, color.g, color.b }) / 255.0f;
				auto max = std::max({ color.r, color.g, color.b }) / 255.0f;

				if (color.r >= color.g && color.r >= color.b) {
					result.hue = static_cast<std::uint8_t>((color.g - color.b) / (max - min));
				}
				else if (color.g >= color.r && color.g >= color.b) {
					result.hue = static_cast<std::uint8_t>(2 + (color.b - color.r) / (max - min));
				}
				else if (color.b >= color.r && color.b >= color.g) {
					result.hue = static_cast<std::uint8_t>(4 + (color.r - color.g) / (max - min));
				}

				result.hue *= 60;

				result.light = (min + max) / 2;
				if (min != max) {
					if (result.light < 0.5) {
						result.saturation = (max - min) / (max + min);
					}
					else {
						result.saturation = (max - min) / (2 - max - min);
					}
				}
				return result;
			}

			HSL toHSL(const RGBf & color)
			{
				return toHSL(toRGB24(color));
			}

			HSL toHSL(const RGBA32 & color)
			{
				return toHSL(toRGB24(color));
			}

			HSL toHSL(const RGBAf & color)
			{
				return toHSL(toRGB24(color));
			}

			HSL toHSL(const BGR24 & color)
			{
				return toHSL(toRGB24(color));
			}

			HSL toHSL(const BGRf & color)
			{
				return toHSL(toRGBf(color));
			}

			HSL toHSL(const BGRA32 & color)
			{
				return toHSL(toRGB24(color));
			}

			HSL toHSL(const BGRAf & color)
			{
				return toHSL(toRGB24(color));
			}

			HSL toHSL(const CMYK & color)
			{
				return toHSL(toRGB24(color));
			}

			HSL toHSL(const std::string & color)
			{
				return toHSL(toRGB24(color));
			}

			RGB24 toRGB24(const HSLA & color)
			{
				return toRGB24(static_cast<HSL>(color));
			}

			RGBf toRGBf(const HSLA & color)
			{
				return toRGBf(toRGB24(color));
			}

			RGBA32 toRGBA32(const HSLA & color)
			{
				return toRGBA32(toRGB24(color));
			}

			RGBAf toRGBAf(const HSLA & color)
			{
				return toRGBAf(toRGB24(color));
			}

			BGR24 toBGR24(const HSLA & color)
			{
				return toBGR24(toRGB24(color));
			}

			BGRf toBGRf(const HSLA & color)
			{
				return toBGRf(toRGB24(color));
			}

			BGRA32 toBGRA32(const HSLA & color)
			{
				return toBGRA32(toRGB24(color));
			}

			BGRAf toBGRAf(const HSLA & color)
			{
				return toBGRAf(toRGB24(color));
			}

			CMYK toCMYK(const HSLA & color)
			{
				return toCMYK(toRGB24(color));
			}

			std::string toHex(const HSLA & color)
			{
				return toHex(toRGB24(color));
			}

			HSL toHSL(const HSLA & color)
			{
				return color;
			}

			HSLA toHSLA(const RGB24 & color)
			{
				return toHSLA(toHSL(color));
			}

			HSLA toHSLA(const RGBf & color)
			{
				return toHSLA(toHSL(color));
			}

			HSLA toHSLA(const RGBA32 & color)
			{
				return toHSLA(toHSL(color));
			}

			HSLA toHSLA(const RGBAf & color)
			{
				return toHSLA(toHSL(color));
			}

			HSLA toHSLA(const BGR24 & color)
			{
				return toHSLA(toHSL(color));
			}

			HSLA toHSLA(const BGRf & color)
			{
				return toHSLA(toHSL(color));
			}

			HSLA toHSLA(const BGRA32 & color)
			{
				return toHSLA(toHSL(color));
			}

			HSLA toHSLA(const BGRAf & color)
			{
				return toHSLA(toHSL(color));
			}

			HSLA toHSLA(const CMYK & color)
			{
				return toHSLA(toHSL(color));
			}

			HSLA toHSLA(const std::string & color)
			{
				return toHSLA(toHSL(color));
			}

			HSLA toHSLA(const HSL & color)
			{
				auto result = HSLA();
				result.hue = color.hue;
				result.saturation = color.saturation;
				result.light = color.light;
				result.a = 1.0f;
				return result;
			}

			RGB24 toRGB24(const HSB & color)
			{
				auto mod = (color.hue / 60) % 6;
				auto hue = (color.hue / 60) - mod;
				std::uint8_t l = static_cast<std::uint8_t>(color.brightness * (1.0f - color.saturation));
				std::uint8_t m = static_cast<std::uint8_t>(color.brightness * (1.0f - color.saturation * hue));
				std::uint8_t n = static_cast<std::uint8_t>(color.brightness * (1.0f - (1.0f - color.saturation) * hue));
				auto result = RGB24();
				switch (hue) {
				case 0:
					result = { static_cast<std::uint8_t>(color.brightness), n, l };
					break;
				case 1:
					result = { m, static_cast<std::uint8_t>(color.brightness), l };
					break;
				case 2:
					result = { l, static_cast<std::uint8_t>(color.brightness), n };
					break;
				case 3:
					result = { l, m, static_cast<std::uint8_t>(color.brightness) };
					break;
				case 4:
					result = { n, l, static_cast<std::uint8_t>(color.brightness) };
					break;
				case 5:
					result = { static_cast<std::uint8_t>(color.brightness), l, m };
					break;
				default: break;
				}

				return result;
			}

			RGBf toRGBf(const HSB & color)
			{
				return toRGBf(toRGB24(color));
			}

			RGBA32 toRGBA32(const HSB & color)
			{
				return toRGBA32(toRGB24(color));
			}

			RGBAf toRGBAf(const HSB & color)
			{
				return toRGBAf(toRGB24(color));
			}

			BGR24 toBGR24(const HSB & color)
			{
				return toBGR24(toRGB24(color));
			}

			BGRf toBGRf(const HSB & color)
			{
				return toBGRf(toRGB24(color));
			}

			BGRA32 toBGRA32(const HSB & color)
			{
				return toBGRA32(toRGB24(color));
			}

			BGRAf toBGRAf(const HSB & color)
			{
				return toBGRAf(toRGB24(color));
			}

			CMYK toCMYK(const HSB & color)
			{
				return toCMYK(toRGB24(color));
			}

			std::string toHex(const HSB & color)
			{
				return toHex(toRGB24(color));
			}

			HSL toHSL(const HSB & color)
			{
				return toHSL(toRGB24(color));
			}

			HSLA toHSLA(const HSB & color)
			{
				return toHSLA(toRGB24(color));
			}

			HSB toHSB(const RGB24 & color)
			{
				auto result = HSB();

				auto min = static_cast<float>(std::min({ color.r, color.g, color.b }));
				auto max = static_cast<float>(std::max({ color.r, color.g, color.b }));

				if (max == min) {
					result.hue = 0;
				}
				else if (max == color.r) {
					result.hue = static_cast<int>(60 * (color.g - color.b) / (max - min) + 360) % 360;
				}
				else if (max == color.g) {
					result.hue = static_cast<std::uint8_t>(60 * (color.b - color.r) / (max - min)) + 120;
				}
				else if (max == color.b) {
					result.hue = static_cast<std::uint8_t>(60 * (color.r - color.g) / (max - min)) + 240;
				}

				if (max == 0) {
					result.saturation = 0.0f;
				}
				else {
					result.saturation = 1.0f - min / max;
				}

				result.brightness = max;

				return result;
			}

			HSB toHSB(const RGBf & color)
			{
				return toHSB(toRGB24(color));
			}

			HSB toHSB(const RGBA32 & color)
			{
				return toHSB(toRGB24(color));
			}

			HSB toHSB(const RGBAf & color)
			{
				return toHSB(toRGB24(color));
			}

			HSB toHSB(const BGR24 & color)
			{
				return toHSB(toRGB24(color));
			}

			HSB toHSB(const BGRf & color)
			{
				return toHSB(toRGB24(color));
			}

			HSB toHSB(const BGRA32 & color)
			{
				return toHSB(toRGB24(color));
			}

			HSB toHSB(const BGRAf & color)
			{
				return toHSB(toRGB24(color));
			}

			HSB toHSB(const CMYK & color)
			{
				return toHSB(toRGB24(color));
			}

			HSB toHSB(const std::string & color)
			{
				return toHSB(toRGB24(color));
			}

			HSB toHSB(const HSL & color)
			{
				return toHSB(toRGB24(color));
			}

			HSB toHSB(const HSLA & color)
			{
				return toHSB(toRGB24(color));
			}

			RGB24 toRGB24(const HSBA & color)
			{
				return toRGB24(toHSB(color));
			}

			RGBf toRGBf(const HSBA & color)
			{
				return toRGBf(toHSB(color));
			}

			RGBA32 toRGBA32(const HSBA & color)
			{
				return toRGBA32(toHSB(color));
			}

			RGBAf toRGBAf(const HSBA & color)
			{
				return toRGBAf(toHSB(color));
			}

			BGR24 toBGR24(const HSBA & color)
			{
				return toBGR24(toHSB(color));
			}

			BGRf toBGRf(const HSBA & color)
			{
				return toBGRf(toHSB(color));
			}

			BGRA32 toBGRA32(const HSBA & color)
			{
				return toBGRA32(toHSB(color));
			}

			BGRAf toBGRAf(const HSBA & color)
			{
				return toBGRAf(toHSB(color));
			}

			CMYK toCMYK(const HSBA & color)
			{
				return toCMYK(toHSB(color));
			}

			std::string toHex(const HSBA & color)
			{
				return toHex(toHSB(color));
			}

			HSL toHSL(const HSBA & color)
			{
				return toHSL(toHSB(color));
			}

			HSLA toHSLA(const HSBA & color)
			{
				return toHSLA(toHSB(color));
			}

			HSB toHSB(const HSBA & color)
			{
				return color;
			}

			HSBA toHSBA(const RGB24 & color)
			{
				return toHSBA(toHSB(color));
			}

			HSBA toHSBA(const RGBf & color)
			{
				return toHSBA(toHSB(color));
			}

			HSBA toHSBA(const RGBA32 & color)
			{
				return toHSBA(toHSB(color));
			}

			HSBA toHSBA(const RGBAf & color)
			{
				return toHSBA(toHSB(color));
			}

			HSBA toHSBA(const BGR24 & color)
			{
				return toHSBA(toHSB(color));
			}

			HSBA toHSBA(const BGRf & color)
			{
				return toHSBA(toHSB(color));
			}

			HSBA toHSBA(const BGRA32 & color)
			{
				return toHSBA(toHSB(color));
			}

			HSBA toHSBA(const BGRAf & color)
			{
				return toHSBA(toHSB(color));
			}

			HSBA toHSBA(const CMYK & color)
			{
				return toHSBA(toHSB(color));
			}

			HSBA toHSBA(const std::string & color)
			{
				return toHSBA(toHSB(color));
			}

			HSBA toHSBA(const HSL & color)
			{
				return toHSBA(toHSB(color));
			}

			HSBA toHSBA(const HSLA & color)
			{
				return toHSBA(toHSB(color));
			}

			HSBA toHSBA(const HSB & color)
			{
				auto result = HSBA();
				result.hue = color.hue;
				result.saturation = color.saturation;
				result.brightness = color.brightness;
				result.a = 1.0f;
				return result;
			}

			RGB24 toRGB24(const HWB & color)
			{
				auto begin = HSL();
				begin.hue = color.hue;
				begin.saturation = 1.0f;
				begin.light = 0.5f;

				auto result = toRGBf(begin);
				auto total = color.white + color.black;
				auto white = 0.0f, black = 0.0f;
				if (total > 1.0f) {
					white = white / total;
					black = black / total;
				}
				result.r = result.r * (1.0f - white - black) + white;
				result.g = result.g * (1.0f - white - black) + white;
				result.b = result.b * (1.0f - white - black) + white;

				return std::move(toRGB24(result));
			}

			RGBf toRGBf(const HWB & color)
			{
				return toRGBf(toRGB24(color));
			}

			RGBA32 toRGBA32(const HWB & color)
			{
				return toRGBA32(toRGB24(color));
			}

			RGBAf toRGBAf(const HWB & color)
			{
				return toRGBAf(toRGB24(color));
			}

			BGR24 toBGR24(const HWB & color)
			{
				return toBGR24(toRGB24(color));
			}

			BGRf toBGRf(const HWB & color)
			{
				return toBGRf(toRGB24(color));
			}

			BGRA32 toBGRA32(const HWB & color)
			{
				return toBGRA32(toRGB24(color));
			}
			BGRAf toBGRAf(const HWB & color)
			{
				return toBGRAf(toRGB24(color));
			}

			CMYK toCMYK(const HWB & color)
			{
				return toCMYK(toRGB24(color));
			}

			std::string toHex(const HWB & color)
			{
				return toHex(toRGB24(color));
			}

			HSL toHSL(const HWB & color)
			{
				return toHSL(toRGB24(color));
			}

			HSLA toHSLA(const HWB & color)
			{
				return toHSLA(toRGB24(color));
			}

			HSB toHSB(const HWB & color)
			{
				return toHSB(toRGB24(color));
			}

			HSBA toHSBA(const HWB & color)
			{
				return toHSBA(toRGB24(color));
			}

			HWB toHWB(const RGB24 & color)
			{
				HWB result;
				auto rgb = toRGBf(color);

				auto max = std::max({ rgb.r, rgb.g, rgb.b });
				auto min = std::min({ rgb.r, rgb.g, rgb.b });
				auto chroma = max - min;

				if (rgb.r == max) {
					result.hue = (static_cast<int>((rgb.g - rgb.b) / chroma) % 6) * 360;
				}
				else if (rgb.g == max) {
					result.hue = ((static_cast<int>((rgb.b - rgb.r) / chroma) + 2) % 6) * 360;
				}
				else {
					result.hue = ((static_cast<int>((rgb.r - rgb.g) / chroma) + 4) % 6) * 360;
				}
				result.white = min;
				result.black = 1.0f - max;
				return result;
			}

			HWB toHWB(const RGBf & color)
			{
				return toHWB(toRGB24(color));
			}

			HWB toHWB(const RGBA32 & color)
			{
				return toHWB(toRGB24(color));
			}

			HWB toHWB(const RGBAf & color)
			{
				return toHWB(toRGB24(color));
			}

			HWB toHWB(const BGR24 & color)
			{
				return toHWB(toRGB24(color));
			}

			HWB toHWB(const BGRf & color)
			{
				return toHWB(toRGB24(color));
			}

			HWB toHWB(const BGRA32 & color)
			{
				return toHWB(toRGB24(color));
			}

			HWB toHWB(const BGRAf & color)
			{
				return toHWB(toRGB24(color));
			}

			HWB toHWB(const CMYK & color)
			{
				return toHWB(toRGB24(color));
			}

			HWB toHWB(const std::string & color)
			{
				return toHWB(toRGB24(color));
			}

			HWB toHWB(const HSL & color)
			{
				return toHWB(toRGB24(color));
			}

			HWB toHWB(const HSLA & color)
			{
				return toHWB(toRGB24(color));
			}

			HWB toHWB(const HSB & color)
			{
				return toHWB(toRGB24(color));
			}

			HWB toHWB(const HSBA & color)
			{
				return toHWB(toRGB24(color));
			}

			RGB24 toRGB24(const HWBA & color)
			{
				return toRGB24(toHWB(color));
			}

			RGBf toRGBf(const HWBA & color)
			{
				return toRGBf(toHWB(color));
			}

			RGBA32 toRGBA32(const HWBA & color)
			{
				return toRGBA32(toHWB(color));
			}

			RGBAf toRGBAf(const HWBA & color)
			{
				return toRGBAf(toHWB(color));
			}

			BGR24 toBGR24(const HWBA & color)
			{
				return toBGR24(toHWB(color));
			}

			BGRf toBGRf(const HWBA & color)
			{
				return toBGRf(toHWB(color));
			}

			BGRA32 toBGRA32(const HWBA & color)
			{
				return toBGRA32(toHWB(color));
			}

			BGRAf toBGRAf(const HWBA & color)
			{
				return toBGRAf(toHWB(color));
			}

			CMYK toCMYK(const HWBA & color)
			{
				return toCMYK(toHWB(color));
			}

			std::string toHex(const HWBA & color)
			{
				return toHex(toHWB(color));
			}

			HSL toHSL(const HWBA & color)
			{
				return toHSL(toHWB(color));
			}

			HSLA toHSLA(const HWBA & color)
			{
				return toHSLA(toHWB(color));
			}

			HSB toHSB(const HWBA & color)
			{
				return toHSB(toHWB(color));
			}

			HSBA toHSBA(const HWBA & color)
			{
				return toHSBA(toHWB(color));
			}

			HWB toHWB(const HWBA & color)
			{
				return color;
			}

			HWBA toHWBA(const RGB24 & color)
			{
				return toHWBA(toHWB(color));
			}

			HWBA toHWBA(const RGBf & color)
			{
				return toHWBA(toHWB(color));
			}

			HWBA toHWBA(const RGBA32 & color)
			{
				return toHWBA(toHWB(color));
			}

			HWBA toHWBA(const RGBAf & color)
			{
				return toHWBA(toHWB(color));
			}

			HWBA toHWBA(const BGR24 & color)
			{
				return toHWBA(toHWB(color));
			}

			HWBA toHWBA(const BGRf & color)
			{
				return toHWBA(toHWB(color));
			}

			HWBA toHWBA(const BGRA32 & color)
			{
				return toHWBA(toHWB(color));
			}

			HWBA toHWBA(const BGRAf & color)
			{
				return toHWBA(toHWB(color));
			}

			HWBA toHWBA(const CMYK & color)
			{
				return toHWBA(toHWB(color));
			}

			HWBA toHWBA(const std::string & color)
			{
				return toHWBA(toHWB(color));
			}

			HWBA toHWBA(const HSL & color)
			{
				return toHWBA(toHWB(color));
			}

			HWBA toHWBA(const HSLA & color)
			{
				return toHWBA(toHWB(color));
			}

			HWBA toHWBA(const HSB & color)
			{
				return toHWBA(toHWB(color));
			}

			HWBA toHWBA(const HSBA & color)
			{
				return toHWBA(toHWB(color));
			}

			HWBA toHWBA(const HWB & color)
			{
				auto result = HWBA();
				result.hue = color.hue;
				result.white = color.white;
				result.black = color.black;
				result.a = 1.0f;
				return result;
			}

			RGB24 toRGB24(const NCol & color)
			{
				return toRGB24(toHWB(color));
			}

			RGBf toRGBf(const NCol & color)
			{
				return toRGBf(toHWB(color));
			}

			RGBA32 toRGBA32(const NCol & color)
			{
				return toRGBA32(toHWB(color));
			}

			RGBAf toRGBAf(const NCol & color)
			{
				return toRGBAf(toHWB(color));
			}

			BGR24 toBGR24(const NCol & color)
			{
				return toBGR24(toHWB(color));
			}

			BGRf toBGRf(const NCol & color)
			{
				return toBGRf(toHWB(color));
			}

			BGRA32 toBGRA32(const NCol & color)
			{
				return toBGRA32(toHWB(color));
			}

			BGRAf toBGRAf(const NCol & color)
			{
				return toBGRAf(toHWB(color));
			}

			CMYK toCMYK(const NCol & color)
			{
				return toCMYK(toHWB(color));
			}

			std::string toHex(const NCol & color)
			{
				return toHex(toHWB(color));
			}

			HSL toHSL(const NCol & color)
			{
				return toHSL(toHWB(color));
			}

			HSLA toHSLA(const NCol & color)
			{
				return toHSLA(toHWB(color));
			}

			HSB toHSB(const NCol & color)
			{
				return toHSB(toHWB(color));
			}

			HSBA toHSBA(const NCol & color)
			{
				return toHSBA(toHWB(color));
			}

			HWB toHWB(const NCol & color)
			{
				auto ncolToHue = [](const std::string & ncol) -> auto {
					auto cat = ncol[0];
					auto value = std::stoi(ncol.substr(1));

					if (cat == 'R') {
						return value * 0.6;
					}
					else if (cat == 'Y') {
						return (value * 0.6) + 60;
					}
					else if (cat == 'G') {
						return (value * 0.6) + 120;
					}
					else if (cat == 'C') {
						return (value * 0.6) + 180;
					}
					else if (cat == 'B') {
						return (value * 0.6) + 240;
					}
					else if (cat == 'M') {
						return (value * 0.6) + 300;
					}
					return 0.0;
				};

				HWB result;
				result.hue = static_cast<std::uint8_t>(ncolToHue(color.ncol));
				result.white = color.whiteness;
				result.black = color.blackness;
				return result;
			}

			HWBA toHWBA(const NCol & color)
			{
				return toHWBA(toHWB(color));
			}

			NCol toNCol(const RGB24 & color)
			{
				return toNCol(toHWB(color));
			}

			NCol toNCol(const RGBf & color)
			{
				return toNCol(toHWB(color));
			}

			NCol toNCol(const RGBA32 & color)
			{
				return toNCol(toHWB(color));
			}

			NCol toNCol(const RGBAf & color)
			{
				return toNCol(toHWB(color));
			}

			NCol toNCol(const BGR24 & color)
			{
				return toNCol(toHWB(color));
			}

			NCol toNCol(const BGRf & color)
			{
				return toNCol(toHWB(color));
			}

			NCol toNCol(const BGRA32 & color)
			{
				return toNCol(toHWB(color));
			}

			NCol toNCol(const BGRAf & color)
			{
				return toNCol(toHWB(color));
			}

			NCol toNCol(const CMYK & color)
			{
				return toNCol(toHWB(color));
			}

			NCol toNCol(const std::string & color)
			{
				return toNCol(toHWB(color));
			}

			NCol toNCol(const HSL & color)
			{
				return toNCol(toHWB(color));
			}

			NCol toNCol(const HSLA & color)
			{
				return toNCol(toHWB(color));
			}

			NCol toNCol(const HSB & color)
			{
				return toNCol(toHWB(color));
			}

			NCol toNCol(const HSBA & color)
			{
				return toNCol(toHWB(color));
			}

			NCol toNCol(const HWB & color)
			{
				auto hueToNCol = [](auto hue) -> std::string {
					while (hue >= 360) {
						hue %= 360;
					}
					if (hue < 60) {
						return "R" + std::to_string(hue / 0.6);
					}
					else if (hue < 120) {
						return "Y" + std::to_string((hue - 60) / 0.6);
					}
					else if (hue < 180) {
						return "G" + std::to_string((hue - 120) / 0.6);
					}
					else if (hue < 240) {
						return "C" + std::to_string((hue - 180) / 0.6);
					}
					else if (hue < 300) {
						return "B" + std::to_string((hue - 240) / 0.6);
					}
					else if (hue < 360) {
						return "M" + std::to_string((hue - 300) / 0.6);
					}
					return "";
				};

				NCol result;
				result.ncol = hueToNCol(color.hue);
				result.whiteness = color.white;
				result.blackness = color.black;
				return result;
			}

			NCol toNCol(const HWBA & color)
			{
				return toNCol(toHWB(color));
			}

			RGB24 toRGB24(const NCola & color)
			{
				return toRGB24(toNCol(color));
			}

			RGBf toRGBf(const NCola & color)
			{
				return toRGBf(toNCol(color));
			}

			RGBA32 toRGBA32(const NCola & color)
			{
				auto result = toRGBA32(toNCol(color));
				result.a = static_cast<std::uint8_t>(color.opacity * 255);
				return result;
			}

			RGBAf toRGBAf(const NCola & color)
			{
				return toRGBAf(toNCol(color));
			}

			BGR24 toBGR24(const NCola & color)
			{
				return toBGR24(toNCol(color));
			}

			BGRf toBGRf(const NCola & color)
			{
				return toBGRf(toNCol(color));
			}

			BGRA32 toBGRA32(const NCola & color)
			{
				return toBGRA32(toNCol(color));
			}

			BGRAf toBGRAf(const NCola & color)
			{
				return toBGRAf(toNCol(color));
			}

			CMYK toCMYK(const NCola & color)
			{
				return toCMYK(toNCol(color));
			}

			std::string toHex(const NCola & color)
			{
				return toHex(toNCol(color));
			}

			HSL toHSL(const NCola & color)
			{
				return toHSL(toNCol(color));
			}

			HSLA toHSLA(const NCola & color)
			{
				return toHSLA(toNCol(color));
			}

			HSB toHSB(const NCola & color)
			{
				return toHSB(toNCol(color));
			}

			HSBA toHSBA(const NCola & color)
			{
				return toHSBA(toNCol(color));
			}

			HWB toHWB(const NCola & color)
			{
				return toHWB(toNCol(color));
			}

			HWBA toHWBA(const NCola & color)
			{
				return toHWBA(toNCol(color));
			}

			NCol toNCol(const NCola & color)
			{
				return color;
			}

			NCola toNCola(const RGB24 & color)
			{
				return toNCola(toNCol(color));
			}

			NCola toNCola(const RGBf & color)
			{
				return toNCola(toNCol(color));
			}

			NCola toNCola(const RGBA32 & color)
			{
				return toNCola(toNCol(color));
			}

			NCola toNCola(const RGBAf & color)
			{
				return toNCola(toNCol(color));
			}

			NCola toNCola(const BGR24 & color)
			{
				return toNCola(toNCol(color));
			}

			NCola toNCola(const BGRf & color)
			{
				return toNCola(toNCol(color));
			}

			NCola toNCola(const BGRA32 & color)
			{
				return toNCola(toNCol(color));
			}

			NCola toNCola(const BGRAf & color)
			{
				return toNCola(toNCol(color));
			}

			NCola toNCola(const CMYK & color)
			{
				return toNCola(toNCol(color));
			}

			NCola toNCola(const std::string & color)
			{
				return toNCola(toNCol(color));
			}

			NCola toNCola(const HSL & color)
			{
				return toNCola(toNCol(color));
			}

			NCola toNCola(const HSLA & color)
			{
				return toNCola(toNCol(color));
			}

			NCola toNCola(const HSB & color)
			{
				return toNCola(toNCol(color));
			}

			NCola toNCola(const HSBA & color)
			{
				return toNCola(toNCol(color));
			}

			NCola toNCola(const HWB & color)
			{
				return toNCola(toNCol(color));
			}

			NCola toNCola(const HWBA & color)
			{
				return toNCola(toNCol(color));
			}

			NCola toNCola(const NCol & color)
			{
				auto result = NCola();
				result.ncol = color.ncol;
				result.whiteness = color.whiteness;
				result.blackness = color.blackness;
				result.opacity = 1.0f;
				return result;
			}
		} // namespace type
	} // namespace utility
} // namespace ece

std::istream & operator>>(std::istream & stream, ece::utility::type::RGB24 & color)
{
	stream.read(reinterpret_cast<char *>(&color), sizeof(ece::utility::type::RGB24));
	return stream;
}

std::ostream & operator<<(std::ostream & stream, const ece::utility::type::RGB24 & color)
{
	stream.write(reinterpret_cast<const char *>(&color), sizeof(ece::utility::type::RGB24));
	return stream;
}

std::istream & operator>>(std::istream & stream, ece::utility::type::RGBf & color)
{
	stream >> color.r >> color.g >> color.b;
	return stream;
}

std::ostream & operator<<(std::ostream & stream, const ece::utility::type::RGBf & color)
{
	stream << color.r << color.g << color.b;
	return stream;
}

std::istream & operator>>(std::istream & stream, ece::utility::type::RGBA32 & color)
{
	stream.read(reinterpret_cast<char *>(&color), sizeof(ece::utility::type::RGBA32));
	return stream;
}

std::ostream & operator<<(std::ostream & stream, const ece::utility::type::RGBA32 & color)
{
	stream.write(reinterpret_cast<const char *>(&color), sizeof(ece::utility::type::RGBA32));
	return stream;
}

std::istream & operator>>(std::istream & stream, ece::utility::type::RGBAf & color)
{
	stream >> color.r >> color.g >> color.b >> color.a;
	return stream;
}

std::ostream & operator<<(std::ostream & stream, const ece::utility::type::RGBAf & color)
{
	stream << color.r << color.g << color.b << color.a;
	return stream;
}

std::istream & operator>>(std::istream & stream, ece::utility::type::BGR24 & color)
{
	stream.read(reinterpret_cast<char *>(&color), sizeof(ece::utility::type::BGR24));
	return stream;
}

std::ostream & operator<<(std::ostream & stream, const ece::utility::type::BGR24 & color)
{
	stream.write(reinterpret_cast<const char *>(&color), sizeof(ece::utility::type::BGR24));
	return stream;
}

std::istream & operator>>(std::istream & stream, ece::utility::type::BGRf & color)
{
	stream >> color.b >> color.g >> color.r;
	return stream;
}

std::ostream & operator<<(std::ostream & stream, const ece::utility::type::BGRf & color)
{
	stream << color.b << color.g << color.r;
	return stream;
}

std::istream & operator>>(std::istream & stream, ece::utility::type::BGRA32 & color)
{
	stream.read(reinterpret_cast<char *>(&color), sizeof(ece::utility::type::BGRA32));
	return stream;
}

std::ostream & operator<<(std::ostream & stream, const ece::utility::type::BGRA32 & color)
{
	stream.write(reinterpret_cast<const char *>(&color), sizeof(ece::utility::type::BGRA32));
	return stream;
}

std::istream & operator>>(std::istream & stream, ece::utility::type::BGRAf & color)
{
	stream >> color.b >> color.g >> color.r >> color.a;
	return stream;
}

std::ostream & operator<<(std::ostream & stream, const ece::utility::type::BGRAf & color)
{
	stream << color.b << color.g << color.r << color.a;
	return stream;
}

std::istream & operator>>(std::istream & stream, ece::utility::type::CMYK & color)
{
	stream >> color.c >> color.m >> color.y >> color.k;
	return stream;
}

std::ostream & operator<<(std::ostream & stream, const ece::utility::type::CMYK & color)
{
	stream << color.c << color.m << color.y << color.k;
	return stream;
}

std::istream & operator>>(std::istream & stream, ece::utility::type::HSL & color)
{
	stream >> color.hue >> color.saturation >> color.light;
	return stream;
}

std::ostream & operator<<(std::ostream & stream, const ece::utility::type::HSL & color)
{
	stream << color.hue << color.saturation << color.light;
	return stream;
}

std::istream & operator>>(std::istream & stream, ece::utility::type::HSLA & color)
{
	stream >> color.hue >> color.saturation >> color.light >> color.a;
	return stream;
}

std::ostream & operator<<(std::ostream & stream, const ece::utility::type::HSLA & color)
{
	stream << color.hue << color.saturation << color.light << color.a;
	return stream;
}

std::istream & operator>>(std::istream & stream, ece::utility::type::HSB & color)
{
	stream >> color.hue >> color.saturation >> color.brightness;
	return stream;
}

std::ostream & operator<<(std::ostream & stream, const ece::utility::type::HSB & color)
{
	stream << color.hue << color.saturation << color.brightness;
	return stream;
}

std::istream & operator>>(std::istream & stream, ece::utility::type::HSBA & color)
{
	stream >> color.hue >> color.saturation >> color.brightness >> color.a;
	return stream;
}

std::ostream & operator<<(std::ostream & stream, const ece::utility::type::HSBA & color)
{
	stream << color.hue << color.saturation << color.brightness << color.a;
	return stream;
}

std::istream & operator>>(std::istream & stream, ece::utility::type::HWB & color)
{
	stream >> color.hue >> color.white >> color.black;
	return stream;
}

std::ostream & operator<<(std::ostream & stream, const ece::utility::type::HWB & color)
{
	stream << color.hue << color.white << color.black;
	return stream;
}

std::istream & operator>>(std::istream & stream, ece::utility::type::HWBA & color)
{
	stream >> color.hue >> color.white >> color.black >> color.a;
	return stream;
}

std::ostream & operator<<(std::ostream & stream, const ece::utility::type::HWBA & color)
{
	stream << color.hue << color.white << color.black << color.a;
	return stream;
}

std::istream & operator>>(std::istream & stream, ece::utility::type::NCol & color)
{
	stream >> color.ncol >> color.whiteness >> color.blackness;
	return stream;
}
std::ostream & operator<<(std::ostream & stream, const ece::utility::type::NCol & color)
{
	stream << color.ncol << color.whiteness << color.blackness;
	return stream;
}
std::istream & operator>>(std::istream & stream, ece::utility::type::NCola & color)
{
	stream >> color.ncol >> color.whiteness >> color.blackness >> color.opacity;
	return stream;
}
std::ostream & operator<<(std::ostream & stream, const ece::utility::type::NCola & color)
{
	stream << color.ncol << color.whiteness << color.blackness << color.opacity;
	return stream;
}

#ifdef _MSC_VER
#	undef sscanf
#endif