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

#ifndef PIXEL_FORMAT_HPP
#define PIXEL_FORMAT_HPP

#include "utility/config.hpp"
#include "utility/pch.hpp"
#include "utility/type/borned.hpp"

#ifdef _MSC_VER
#	undef RGB
#	undef CMYK
#	undef max
#	undef min
#endif

namespace ece
{
	namespace utility
	{
		namespace type
		{
			struct ECE_UTILITY_API RGB24
			{
				std::uint8_t r;
				std::uint8_t g;
				std::uint8_t b;
			};

			struct ECE_UTILITY_API RGBf
			{
				Percentage r;
				Percentage g;
				Percentage b;
			};

			RGB24 toRGB24(const RGBf & color);

			RGBf toRGBf(const RGB24 & color);

			struct ECE_UTILITY_API RGBA32 : public RGB24
			{
				std::uint8_t a;
			};

			RGB24 toRGB24(const RGBA32 & color);
			RGBf toRGBf(const RGBA32 & color);

			RGBA32 toRGBA32(const RGB24 & color);
			RGBA32 toRGBA32(const RGBf & color);

			struct ECE_UTILITY_API RGBAf : public RGBf
			{
				Percentage a;
			};

			RGB24 toRGB24(const RGBAf & color);
			RGBf toRGBf(const RGBAf & color);
			RGBA32 toRGBA32(const RGBAf & color);

			RGBAf toRGBAf(const RGB24 & color);
			RGBAf toRGBAf(const RGBf & color);
			RGBAf toRGBAf(const RGBA32 & color);

			struct ECE_UTILITY_API BGR24
			{
				std::uint8_t b;
				std::uint8_t g;
				std::uint8_t r;
			};

			RGB24 toRGB24(const BGR24 & color);
			RGBf toRGBf(const BGR24 & color);
			RGBA32 toRGBA32(const BGR24 & color);
			RGBAf toRGBAf(const BGR24 & color);

			BGR24 toBGR24(const RGB24 & color);
			BGR24 toBGR24(const RGBf & color);
			BGR24 toBGR24(const RGBA32 & color);
			BGR24 toBGR24(const RGBAf & color);

			struct ECE_UTILITY_API BGRf
			{
				Percentage b;
				Percentage g;
				Percentage r;
			};

			RGB24 toRGB24(const BGRf & color);
			RGBf toRGBf(const BGRf & color);
			RGBA32 toRGBA32(const BGRf & color);
			RGBAf toRGBAf(const BGRf & color);
			BGR24 toBGR24(const BGRf & color);

			BGRf toBGRf(const RGB24 & color);
			BGRf toBGRf(const RGBf & color);
			BGRf toBGRf(const RGBA32 & color);
			BGRf toBGRf(const RGBAf & color);
			BGRf toBGRf(const BGR24 & color);

			struct ECE_UTILITY_API BGRA32 : public BGR24
			{
				std::uint8_t a;
			};

			RGB24 toRGB24(const BGRA32 & color);
			RGBf toRGBf(const BGRA32 & color);
			RGBA32 toRGBA32(const BGRA32 & color);
			RGBAf toRGBAf(const BGRA32 & color);
			BGR24 toBGR24(const BGRA32 & color);
			BGRf toBGRf(const BGRA32 & color);

			BGRA32 toBGRA32(const RGB24 & color);
			BGRA32 toBGRA32(const RGBf & color);
			BGRA32 toBGRA32(const RGBA32 & color);
			BGRA32 toBGRA32(const RGBAf & color);
			BGRA32 toBGRA32(const BGR24 & color);
			BGRA32 toBGRA32(const BGRf & color);

			struct ECE_UTILITY_API BGRAf : public BGRf
			{
				Percentage a;
			};

			RGB24 toRGB24(const BGRAf & color);
			RGBf toRGBf(const BGRAf & color);
			RGBA32 toRGBA32(const BGRAf & color);
			RGBAf toRGBAf(const BGRAf & color);
			BGR24 toBGR24(const BGRAf & color);
			BGRf toBGRf(const BGRAf & color);
			BGRA32 toBGRA32(const BGRAf & color);

			BGRAf toBGRAf(const RGB24 & color);
			BGRAf toBGRAf(const RGBf & color);
			BGRAf toBGRAf(const RGBA32 & color);
			BGRAf toBGRAf(const RGBAf & color);
			BGRAf toBGRAf(const BGR24 & color);
			BGRAf toBGRAf(const BGRf & color);
			BGRAf toBGRAf(const BGRA32 & color);

			struct ECE_UTILITY_API CMYK
			{
				Percentage c;
				Percentage m;
				Percentage y;
				Percentage k;
			};

			RGB24 toRGB24(const CMYK & color);
			RGBf toRGBf(const CMYK & color);
			RGBA32 toRGBA32(const CMYK & color);
			RGBAf toRGBAf(const CMYK & color);
			BGR24 toBGR24(const CMYK & color);
			BGRf toBGRf(const CMYK & color);
			BGRA32 toBGRA32(const CMYK & color);
			BGRAf toBGRAf(const CMYK & color);

			CMYK toCMYK(const RGB24 & color);
			CMYK toCMYK(const RGBf & color);
			CMYK toCMYK(const RGBA32 & color);
			CMYK toCMYK(const RGBAf & color);
			CMYK toCMYK(const BGR24 & color);
			CMYK toCMYK(const BGRf & color);
			CMYK toCMYK(const BGRA32 & color);
			CMYK toCMYK(const BGRAf & color);

			RGB24 toRGB24(const std::string & color);
			RGBf toRGBf(const std::string & color);
			RGBA32 toRGBA32(const std::string & color);
			RGBAf toRGBAf(const std::string & color);
			BGR24 toBGR24(const std::string & color);
			BGRf toBGRf(const std::string & color);
			BGRA32 toBGRA32(const std::string & color);
			BGRAf toBGRAf(const std::string & color);
			CMYK toCMYK(const std::string & color);

			std::string toHex(const RGB24 & color);
			std::string toHex(const RGBf & color);
			std::string toHex(const RGBA32 & color);
			std::string toHex(const RGBAf & color);
			std::string toHex(const BGR24 & color);
			std::string toHex(const BGRf & color);
			std::string toHex(const BGRA32 & color);
			std::string toHex(const BGRAf & color);
			std::string toHex(const CMYK & color);

			struct HSL
			{
				Borned<unsigned short int> hue;
				Percentage saturation;
				Percentage light;

				HSL(): hue{ 0, 0, 360 }, saturation(), light() {}
			};

			RGB24 toRGB24(const HSL & color);
			RGBf toRGBf(const HSL & color);
			RGBA32 toRGBA32(const HSL & color);
			RGBAf toRGBAf(const HSL & color);
			BGR24 toBGR24(const HSL & color);
			BGRf toBGRf(const HSL & color);
			BGRA32 toBGRA32(const HSL & color);
			BGRAf toBGRAf(const HSL & color);
			CMYK toCMYK(const HSL & color);
			std::string toHex(const HSL & color);

			HSL toHSL(const RGB24 & color);
			HSL toHSL(const RGBf & color);
			HSL toHSL(const RGBA32 & color);
			HSL toHSL(const RGBAf & color);
			HSL toHSL(const BGR24 & color);
			HSL toHSL(const BGRf & color);
			HSL toHSL(const BGRA32 & color);
			HSL toHSL(const BGRAf & color);
			HSL toHSL(const CMYK & color);
			HSL toHSL(const std::string & color);

			struct HSLA: public HSL
			{
				Percentage a;
			};

			RGB24 toRGB24(const HSLA & color);
			RGBf toRGBf(const HSLA & color);
			RGBA32 toRGBA32(const HSLA & color);
			RGBAf toRGBAf(const HSLA & color);
			BGR24 toBGR24(const HSLA & color);
			BGRf toBGRf(const HSLA & color);
			BGRA32 toBGRA32(const HSLA & color);
			BGRAf toBGRAf(const HSLA & color);
			CMYK toCMYK(const HSLA & color);
			std::string toHex(const HSLA & color);
			HSL toHSL(const HSLA & color);

			HSLA toHSLA(const RGB24 & color);
			HSLA toHSLA(const RGBf & color);
			HSLA toHSLA(const RGBA32 & color);
			HSLA toHSLA(const RGBAf & color);
			HSLA toHSLA(const BGR24 & color);
			HSLA toHSLA(const BGRf & color);
			HSLA toHSLA(const BGRA32 & color);
			HSLA toHSLA(const BGRAf & color);
			HSLA toHSLA(const CMYK & color);
			HSLA toHSLA(const std::string & color);
			HSLA toHSLA(const HSL & color);

			struct HSB // aka HSV (Hue, Saturation, Value)
			{
				Borned<unsigned short int> hue;
				Percentage saturation;
				Percentage brightness;

				HSB() : hue{ 0, 0, 360 }, saturation(), brightness() {}
			};

			RGB24 toRGB24(const HSB & color);
			RGBf toRGBf(const HSB & color);
			RGBA32 toRGBA32(const HSB & color);
			RGBAf toRGBAf(const HSB & color);
			BGR24 toBGR24(const HSB & color);
			BGRf toBGRf(const HSB & color);
			BGRA32 toBGRA32(const HSB & color);
			BGRAf toBGRAf(const HSB & color);
			CMYK toCMYK(const HSB & color);
			std::string toHex(const HSB & color);
			HSL toHSL(const HSB & color);
			HSLA toHSLA(const HSB & color);

			HSB toHSB(const RGB24 & color);
			HSB toHSB(const RGBf & color);
			HSB toHSB(const RGBA32 & color);
			HSB toHSB(const RGBAf & color);
			HSB toHSB(const BGR24 & color);
			HSB toHSB(const BGRf & color);
			HSB toHSB(const BGRA32 & color);
			HSB toHSB(const BGRAf & color);
			HSB toHSB(const CMYK & color);
			HSB toHSB(const std::string & color);
			HSB toHSB(const HSL & color);
			HSB toHSB(const HSLA & color);

			struct HSBA : public HSB // aka HSVA (Hue, Saturation, Value, Alpha transparency)
			{
				Percentage a;
			};

			RGB24 toRGB24(const HSBA & color);
			RGBf toRGBf(const HSBA & color);
			RGBA32 toRGBA32(const HSBA & color);
			RGBAf toRGBAf(const HSBA & color);
			BGR24 toBGR24(const HSBA & color);
			BGRf toBGRf(const HSBA & color);
			BGRA32 toBGRA32(const HSBA & color);
			BGRAf toBGRAf(const HSBA & color);
			CMYK toCMYK(const HSBA & color);
			std::string toHex(const HSBA & color);
			HSL toHSL(const HSBA & color);
			HSLA toHSLA(const HSBA & color);
			HSB toHSB(const HSBA & color);

			HSBA toHSBA(const RGB24 & color);
			HSBA toHSBA(const RGBf & color);
			HSBA toHSBA(const RGBA32 & color);
			HSBA toHSBA(const RGBAf & color);
			HSBA toHSBA(const BGR24 & color);
			HSBA toHSBA(const BGRf & color);
			HSBA toHSBA(const BGRA32 & color);
			HSBA toHSBA(const BGRAf & color);
			HSBA toHSBA(const CMYK & color);
			HSBA toHSBA(const std::string & color);
			HSBA toHSBA(const HSL & color);
			HSBA toHSBA(const HSLA & color);
			HSBA toHSBA(const HSB & color);

			struct HWB
			{
				Borned<unsigned short int> hue;
				Percentage white;
				Percentage black;

				HWB(): hue{0, 0, 360}, white(), black() {}
			};

			RGB24 toRGB24(const HWB & color);
			RGBf toRGBf(const HWB & color);
			RGBA32 toRGBA32(const HWB & color);
			RGBAf toRGBAf(const HWB & color);
			BGR24 toBGR24(const HWB & color);
			BGRf toBGRf(const HWB & color);
			BGRA32 toBGRA32(const HWB & color);
			BGRAf toBGRAf(const HWB & color);
			CMYK toCMYK(const HWB & color);
			std::string toHex(const HWB & color);
			HSL toHSL(const HWB & color);
			HSLA toHSLA(const HWB & color);
			HSB toHSB(const HWB & color);
			HSBA toHSBA(const HWB & color);

			HWB toHWB(const RGB24 & color);
			HWB toHWB(const RGBf & color);
			HWB toHWB(const RGBA32 & color);
			HWB toHWB(const RGBAf & color);
			HWB toHWB(const BGR24 & color);
			HWB toHWB(const BGRf & color);
			HWB toHWB(const BGRA32 & color);
			HWB toHWB(const BGRAf & color);
			HWB toHWB(const CMYK & color);
			HWB toHWB(const std::string & color);
			HWB toHWB(const HSL & color);
			HWB toHWB(const HSLA & color);
			HWB toHWB(const HSB & color);
			HWB toHWB(const HSBA & color);

			struct HWBA: public HWB
			{
				Percentage a;
			};

			RGB24 toRGB24(const HWBA & color);
			RGBf toRGBf(const HWBA & color);
			RGBA32 toRGBA32(const HWBA & color);
			RGBAf toRGBAf(const HWBA & color);
			BGR24 toBGR24(const HWBA & color);
			BGRf toBGRf(const HWBA & color);
			BGRA32 toBGRA32(const HWBA & color);
			BGRAf toBGRAf(const HWBA & color);
			CMYK toCMYK(const HWBA & color);
			std::string toHex(const HWBA & color);
			HSL toHSL(const HWBA & color);
			HSLA toHSLA(const HWBA & color);
			HSB toHSB(const HWBA & color);
			HSBA toHSBA(const HWBA & color);
			HWB toHWB(const HWBA & color);

			HWBA toHWBA(const RGB24 & color);
			HWBA toHWBA(const RGBf & color);
			HWBA toHWBA(const RGBA32 & color);
			HWBA toHWBA(const RGBAf & color);
			HWBA toHWBA(const BGR24 & color);
			HWBA toHWBA(const BGRf & color);
			HWBA toHWBA(const BGRA32 & color);
			HWBA toHWBA(const BGRAf & color);
			HWBA toHWBA(const CMYK & color);
			HWBA toHWBA(const std::string & color);
			HWBA toHWBA(const HSL & color);
			HWBA toHWBA(const HSLA & color);
			HWBA toHWBA(const HSB & color);
			HWBA toHWBA(const HSBA & color);
			HWBA toHWBA(const HWB & color);

			struct NCol
			{
				std::string ncol;
				Percentage whiteness;
				Percentage blackness;
			};

			RGB24 toRGB24(const NCol & color);
			RGBf toRGBf(const NCol & color);
			RGBA32 toRGBA32(const NCol & color);
			RGBAf toRGBAf(const NCol & color);
			BGR24 toBGR24(const NCol & color);
			BGRf toBGRf(const NCol & color);
			BGRA32 toBGRA32(const NCol & color);
			BGRAf toBGRAf(const NCol & color);
			CMYK toCMYK(const NCol & color);
			std::string toHex(const NCol & color);
			HSL toHSL(const NCol & color);
			HSLA toHSLA(const NCol & color);
			HSB toHSB(const NCol & color);
			HSBA toHSBA(const NCol & color);
			HWB toHWB(const NCol & color);
			HWBA toHWBA(const NCol & color);

			NCol toNCol(const RGB24 & color);
			NCol toNCol(const RGBf & color);
			NCol toNCol(const RGBA32 & color);
			NCol toNCol(const RGBAf & color);
			NCol toNCol(const BGR24 & color);
			NCol toNCol(const BGRf & color);
			NCol toNCol(const BGRA32 & color);
			NCol toNCol(const BGRAf & color);
			NCol toNCol(const CMYK & color);
			NCol toNCol(const std::string & color);
			NCol toNCol(const HSL & color);
			NCol toNCol(const HSLA & color);
			NCol toNCol(const HSB & color);
			NCol toNCol(const HSBA & color);
			NCol toNCol(const HWB & color);
			NCol toNCol(const HWBA & color);

			struct NCola : public NCol
			{
				Percentage opacity;
			};

			RGB24 toRGB24(const NCola & color);
			RGBf toRGBf(const NCola & color);
			RGBA32 toRGBA32(const NCola & color);
			RGBAf toRGBAf(const NCola & color);
			BGR24 toBGR24(const NCola & color);
			BGRf toBGRf(const NCola & color);
			BGRA32 toBGRA32(const NCola & color);
			BGRAf toBGRAf(const NCola & color);
			CMYK toCMYK(const NCola & color);
			std::string toHex(const NCola & color);
			HSL toHSL(const NCola & color);
			HSLA toHSLA(const NCola & color);
			HSB toHSB(const NCola & color);
			HSBA toHSBA(const NCola & color);
			HWB toHWB(const NCola & color);
			HWBA toHWBA(const NCola & color);
			NCol toNCol(const NCola & color);

			NCola toNCola(const RGB24 & color);
			NCola toNCola(const RGBf & color);
			NCola toNCola(const RGBA32 & color);
			NCola toNCola(const RGBAf & color);
			NCola toNCola(const BGR24 & color);
			NCola toNCola(const BGRf & color);
			NCola toNCola(const BGRA32 & color);
			NCola toNCola(const BGRAf & color);
			NCola toNCola(const CMYK & color);
			NCola toNCola(const std::string & color);
			NCola toNCola(const HSL & color);
			NCola toNCola(const HSLA & color);
			NCola toNCola(const HSB & color);
			NCola toNCola(const HSBA & color);
			NCola toNCola(const HWB & color);
			NCola toNCola(const HWBA & color);
			NCola toNCola(const NCol & color);
		} // namespace type
	} // namespace utility
} // namespace ece

ECE_UTILITY_API std::istream & operator>>(std::istream & stream, ece::utility::type::RGB24 & color);
ECE_UTILITY_API std::ostream & operator<<(std::ostream & stream, const ece::utility::type::RGB24 & color);
ECE_UTILITY_API std::istream & operator>>(std::istream & stream, ece::utility::type::RGBf & color);
ECE_UTILITY_API std::ostream & operator<<(std::ostream & stream, const ece::utility::type::RGBf & color);
ECE_UTILITY_API std::istream & operator>>(std::istream & stream, ece::utility::type::RGBA32 & color);
ECE_UTILITY_API std::ostream & operator<<(std::ostream & stream, const ece::utility::type::RGBA32 & color);
ECE_UTILITY_API std::istream & operator>>(std::istream & stream, ece::utility::type::RGBAf & color);
ECE_UTILITY_API std::ostream & operator<<(std::ostream & stream, const ece::utility::type::RGBAf & color);
ECE_UTILITY_API std::istream & operator>>(std::istream & stream, ece::utility::type::BGR24 & color);
ECE_UTILITY_API std::ostream & operator<<(std::ostream & stream, const ece::utility::type::BGR24 & color);
ECE_UTILITY_API std::istream & operator>>(std::istream & stream, ece::utility::type::BGRf & color);
ECE_UTILITY_API std::ostream & operator<<(std::ostream & stream, const ece::utility::type::BGRf & color);
ECE_UTILITY_API std::istream & operator>>(std::istream & stream, ece::utility::type::BGRA32 & color);
ECE_UTILITY_API std::ostream & operator<<(std::ostream & stream, const ece::utility::type::BGRA32 & color);
ECE_UTILITY_API std::istream & operator>>(std::istream & stream, ece::utility::type::BGRAf & color);
ECE_UTILITY_API std::ostream & operator<<(std::ostream & stream, const ece::utility::type::BGRAf & color);
ECE_UTILITY_API std::istream & operator>>(std::istream & stream, ece::utility::type::CMYK & color);
ECE_UTILITY_API std::ostream & operator<<(std::ostream & stream, const ece::utility::type::CMYK & color);
ECE_UTILITY_API std::istream & operator>>(std::istream & stream, ece::utility::type::HSL & color);
ECE_UTILITY_API std::ostream & operator<<(std::ostream & stream, const ece::utility::type::HSL & color);
ECE_UTILITY_API std::istream & operator>>(std::istream & stream, ece::utility::type::HSLA & color);
ECE_UTILITY_API std::ostream & operator<<(std::ostream & stream, const ece::utility::type::HSLA & color);
ECE_UTILITY_API std::istream & operator>>(std::istream & stream, ece::utility::type::HSB & color);
ECE_UTILITY_API std::ostream & operator<<(std::ostream & stream, const ece::utility::type::HSB & color);
ECE_UTILITY_API std::istream & operator>>(std::istream & stream, ece::utility::type::HSBA & color);
ECE_UTILITY_API std::ostream & operator<<(std::ostream & stream, const ece::utility::type::HSBA & color);
ECE_UTILITY_API std::istream & operator>>(std::istream & stream, ece::utility::type::HWB & color);
ECE_UTILITY_API std::ostream & operator<<(std::ostream & stream, const ece::utility::type::HWB & color);
ECE_UTILITY_API std::istream & operator>>(std::istream & stream, ece::utility::type::HWBA & color);
ECE_UTILITY_API std::ostream & operator<<(std::ostream & stream, const ece::utility::type::HWBA & color);
ECE_UTILITY_API std::istream & operator>>(std::istream & stream, ece::utility::type::NCol & color);
ECE_UTILITY_API std::ostream & operator<<(std::ostream & stream, const ece::utility::type::NCol & color);
ECE_UTILITY_API std::istream & operator>>(std::istream & stream, ece::utility::type::NCola & color);
ECE_UTILITY_API std::ostream & operator<<(std::ostream & stream, const ece::utility::type::NCola & color);

#endif // PIXEL_FORMAT_HPP