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

#ifndef BITMAP_COLOR_HPP
#define BITMAP_COLOR_HPP

#ifdef _MSC_VER
#	undef RGB
#	undef max
#endif

#include "utility/config.hpp"
#include "utility/pch.hpp"

namespace ece
{
	namespace utility
	{
		namespace formats
		{
			namespace bitmap
			{
				template <class T>
				struct ECE_UTILITY_API RGB
				{
					T r;
					T g;
					T b;

					ECE_UTILITY_API friend std::istream operator>>(std::istream & stream, RGB<T> & color);

					ECE_UTILITY_API friend std::ostream operator<<(std::istream & stream, const RGB<T> & color);
				};

				template <class T>
				struct ECE_UTILITY_API RGBA : public RGB<T>
				{
					T a;

					operator RGB<T> &();
					operator const RGB<T> &() const;

					ECE_UTILITY_API friend std::istream operator>>(std::istream & stream, RGBA<T> & color);

					ECE_UTILITY_API friend std::ostream operator<<(std::istream & stream, const RGBA<T> & color);
				};

				template <class T>
				struct ECE_UTILITY_API BGR
				{
					T b;
					T g;
					T r;

					ECE_UTILITY_API friend std::istream operator>>(std::istream & stream, BGR<T> & color);

					ECE_UTILITY_API friend std::ostream operator<<(std::istream & stream, const BGR<T> & color);
				};

				template <class T>
				struct ECE_UTILITY_API BGRA : public BGR<T>
				{
					T a;

					operator BGR<T> &();
					operator const BGR<T> &() const;

					ECE_UTILITY_API friend std::istream operator>>(std::istream & stream, BGRA<T> & color);

					ECE_UTILITY_API friend std::ostream operator<<(std::istream & stream, const BGRA<T> & color);
				};

				template <class T> RGBA<T> toRGBA(const BGRA<T> & color);
				template <class T> RGBA<T> toRGBA(const BGR<T> & color);
				template <class T> RGBA<T> toRGBA(const RGB<T> & color);

				template <class T> BGRA<T> toBGRA(const RGBA<T> & color);
				template <class T> BGRA<T> toBGRA(const RGB<T> & color);
				template <class T> BGRA<T> toBGRA(const BGR<T> & color);

				template <class T>
				struct ECE_UTILITY_API CMYK
				{
					T c;
					T m;
					T y;
					T k;

					ECE_UTILITY_API friend std::istream operator>>(std::istream & stream, CMYK<T> & color);

					ECE_UTILITY_API friend std::ostream operator<<(std::istream & stream, const CMYK<T> & color);
				};

				template <class T> RGB<T> toRGB(const CMYK<T> & color);
				template <class T> RGBA<T> toRGBA(const CMYK<T> & color);
				template <class T> BGR<T> toBGR(const CMYK<T> & color);
				template <class T> BGRA<T> toBGRA(const CMYK<T> & color);

				template <class T> CMYK<T> toCMYK(const RGB<T> & color);
				template <class T> CMYK<T> toCMYK(const RGBA<T> & color);
				template <class T> CMYK<T> toCMYK(const BGR<T> & color);
				template <class T> CMYK<T> toCMYK(const BGRA<T> & color);

				template <class T> std::string toHex(const RGB<T> & color);
				template <class T> std::string toHex(const RGBA<T> & color);
				template <class T> std::string toHex(const BGR<T> & color);
				template <class T> std::string toHex(const BGRA<T> & color);
				template <class T> std::string toHex(const CMYK<T> & color);

				template <class T> RGB<T> toRGB(const std::string & color);
				template <class T> RGBA<T> toRGBA(const std::string & color);
				template <class T> BGR<T> toBGR(const std::string & color);
				template <class T> BGRA<T> toBGRA(const std::string & color);
				template <class T> CMYK<T> toCMYK(const std::string & color);
			} // namespace bitmap
		} // namespace formats
	} // namespace utility
} // namespace ece

#include "utility/formats/bitmap/color_format.inl"

#endif // BITMAP_COLOR_HPP