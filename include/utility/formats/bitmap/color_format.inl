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

namespace ece
{
	namespace utility
	{
		namespace formats
		{
			namespace bitmap
			{
				template <class T>
				std::istream operator>>(std::istream & stream, RGB<T> & color)
				{
					stream.read(reinterpret_cast<char *>(&color), sizeof(T) * 3);
					return stream;
				}

				template <class T>
				std::ostream operator<<(std::istream & stream, const RGB<T> & color)
				{
					stream.write(reinterpret_cast<char *>(&color), sizeof(T) * 3);
					return stream;
				}

				template <class T>
				RGBA<T>::operator RGB<T> &()
				{
					return *this;
				}

				template <class T>
				RGBA<T>::operator const RGB<T> &() const
				{
					return *this;
				}

				template <class T>
				std::istream operator>>(std::istream & stream, RGBA<T> & color)
				{
					stream.read(reinterpret_cast<char *>(&color), sizeof(T) * 4);
					return stream;
				}

				template <class T>
				std::ostream operator<<(std::istream & stream, const RGBA<T> & color)
				{
					stream.write(reinterpret_cast<char *>(&color), sizeof(T) * 4);
					return stream;
				}

				template <class T>
				std::istream operator>>(std::istream & stream, BGR<T> & color)
				{
					stream.read(reinterpret_cast<char *>(&color), sizeof(T) * 3);
					return stream;
				}

				template <class T>
				std::ostream operator<<(std::istream & stream, const BGR<T> & color)
				{
					stream.write(reinterpret_cast<char *>(&color), sizeof(T) * 3);
					return stream;
				}

				template <class T>
				BGRA<T>::operator BGR<T> &()
				{
					return *this;
				}

				template <class T>
				BGRA<T>::operator const BGR<T> &() const
				{
					return *this;
				}

				template <class T>
				std::istream operator>>(std::istream & stream, BGRA<T> & color)
				{
					stream.read(reinterpret_cast<char *>(&color), sizeof(T) * 4);
					return stream;
				}

				template <class T>
				std::ostream operator<<(std::istream & stream, const BGRA<T> & color)
				{
					stream.write(reinterpret_cast<char *>(&color), sizeof(T) * 4);
					return stream;
				}

				template <class T>
				RGBA<T> toRGBA(const BGRA<T> & color)
				{
					return RGBA<T>{ color.r, color.g, color.b, color.a };
				}

				template <class T>
				RGBA<T> toRGBA(const BGR<T> & color)
				{
					return { color.b, color.g, color.r, std::numeric_limits<T>::max() };
				}

				template <class T>
				RGBA<T> toRGBA(const RGB<T> & color)
				{
					return { color.r, color.g, color.b, std::numeric_limits<T>::max() };
				}

				template <class T>
				BGRA<T> toBGRA(const RGBA<T> & color)
				{
					return { color.b, color.g, color.r, color.a };
				}

				template <class T>
				BGRA<T> toBGRA(const RGB<T> & color)
				{
					return { color.b, color.g, color.r, std::numeric_limits<T>::max() };
				}

				template <class T>
				BGRA<T> toBGRA(const BGR<T> & color)
				{
					return { color.b, color.g, color.r, std::numeric_limits<T>::max() };
				}

				template <class T>
				std::istream operator>>(std::istream & stream, CMYK<T> & color)
				{
					stream.read(reinterpret_cast<char *>(&color), sizeof(T) * 4);
					return stream;
				}

				template <class T>
				std::ostream operator<<(std::istream & stream, const CMYK<T> & color)
				{
					stream.write(reinterpret_cast<char *>(&color), sizeof(T) * 4);
					return stream;
				}

				template <class T>
				RGB<T> toRGB(const CMYK<T> & color)
				{
					const auto max = std::numeric_limits<T>::max();
					RGB<T> result;
					result.r = max - ((std::min(T(1), color.c * (T(1) - color.k) + color.k)) * max);
					result.g = max - ((std::min(T(1), color.m * (T(1) - color.k) + color.k)) * max);
					result.b = max - ((std::min(T(1), color.y * (T(1) - color.k) + color.k)) * max);
					return std::move(result);
				}

				template <class T> RGBA<T> toRGBA(const CMYK<T> & color)
				{
					const auto max = std::numeric_limits<T>::max();
					RGBA<T> result;
					result.r = max - ((std::min(T(1), color.c * (T(1) - color.k) + color.k)) * max);
					result.g = max - ((std::min(T(1), color.m * (T(1) - color.k) + color.k)) * max);
					result.b = max - ((std::min(T(1), color.y * (T(1) - color.k) + color.k)) * max);
					result.a = max ;
					return std::move(result);
				}
				template <class T> BGR<T> toBGR(const CMYK<T> & color)
				{
					const auto max = std::numeric_limits<T>::max();
					BGR<T> result;
					result.r = max - ((std::min(T(1), color.c * (T(1) - color.k) + color.k)) * max);
					result.g = max - ((std::min(T(1), color.m * (T(1) - color.k) + color.k)) * max);
					result.b = max - ((std::min(T(1), color.y * (T(1) - color.k) + color.k)) * max);
					return std::move(result);
				}

				template <class T> BGRA<T> toBGRA(const CMYK<T> & color)
				{
					const auto max = std::numeric_limits<T>::max();
					BGRA<T> result;
					result.r = max - ((std::min(T(1), color.c * (T(1) - color.k) + color.k)) * max);
					result.g = max - ((std::min(T(1), color.m * (T(1) - color.k) + color.k)) * max);
					result.b = max - ((std::min(T(1), color.y * (T(1) - color.k) + color.k)) * max);
					result.a = max;
					return std::move(result);
				}

				template <class T> CMYK<T> toCMYK(const RGB<T> & color)
				{
					const auto max = std::numeric_limits<T>::max();
					auto r = color.r / max;
					auto g = color.g / max;
					auto b = color.b / max;
					CMYK<T> result;
					result.k = 1 - std::max(r, g, b);

					if (result.k == 1) {
						result.c = T(0);
						result.m = T(0);
						result.y = T(0);
					}
					else {
						result.c = (T(1) - r - k) / (T(1) - k);
						result.m = (T(1) - g - k) / (T(1) - k);
						result.y = (T(1) - b - k) / (T(1) - k);
					}
					return std::move(result);
				}

				template <class T> CMYK<T> toCMYK(const RGBA<T> & color)
				{
					const auto max = std::numeric_limits<T>::max();
					auto r = color.r / max;
					auto g = color.g / max;
					auto b = color.b / max;
					CMYK<T> result;
					result.k = 1 - std::max(r, g, b);

					if (result.k == 1) {
						result.c = T(0);
						result.m = T(0);
						result.y = T(0);
					}
					else {
						result.c = (T(1) - r - k) / (T(1) - k);
						result.m = (T(1) - g - k) / (T(1) - k);
						result.y = (T(1) - b - k) / (T(1) - k);
					}
					return std::move(result);
				}

				template <class T> CMYK<T> toCMYK(const BGR<T> & color)
				{
					const auto max = std::numeric_limits<T>::max();
					auto r = color.r / max;
					auto g = color.g / max;
					auto b = color.b / max;
					CMYK<T> result;
					result.k = 1 - std::max(r, g, b);

					if (result.k == 1) {
						result.c = T(0);
						result.m = T(0);
						result.y = T(0);
					}
					else {
						result.c = (T(1) - r - k) / (T(1) - k);
						result.m = (T(1) - g - k) / (T(1) - k);
						result.y = (T(1) - b - k) / (T(1) - k);
					}
					return std::move(result);
				}

				template <class T> CMYK<T> toCMYK(const BGRA<T> & color)
				{
					const auto max = std::numeric_limits<T>::max();
					auto r = color.r / max;
					auto g = color.g / max;
					auto b = color.b / max;
					CMYK<T> result;
					result.k = 1 - std::max(r, g, b);

					if (result.k == 1) {
						result.c = T(0);
						result.m = T(0);
						result.y = T(0);
					}
					else {
						result.c = (T(1) - r - k) / (T(1) - k);
						result.m = (T(1) - g - k) / (T(1) - k);
						result.y = (T(1) - b - k) / (T(1) - k);
					}
					return std::move(result);
				}

				template <class T> std::string toHex(const RGB<T> & color)
				{
					auto stream = std::ostringstream();
					stream << '#';
					if (rgb.r <= 9) {
						stream << '0';
					}
					stream << std::hex << rgb.r;
					if (rgb.g <= 9) {
						stream << '0';
					}
					stream << std::hex << rgb.g;
					if (rgb.b <= 9) {
						stream << '0';
					}
					stream << std::hex << rgb.b;
					return stream.str();
				}

				template <class T> std::string toHex(const RGBA<T> & color)
				{
					auto stream = std::ostringstream();
					stream << '#';
					if (rgb.r <= 9) {
						stream << '0';
					}
					stream << std::hex << rgb.r;
					if (rgb.g <= 9) {
						stream << '0';
					}
					stream << std::hex << rgb.g;
					if (rgb.b <= 9) {
						stream << '0';
					}
					stream << std::hex << rgb.b;
					return stream.str();
				}

				template <class T> std::string toHex(const BGR<T> & color)
				{
					auto stream = std::ostringstream();
					stream << '#';
					if (rgb.r <= 9) {
						stream << '0';
					}
					stream << std::hex << rgb.r;
					if (rgb.g <= 9) {
						stream << '0';
					}
					stream << std::hex << rgb.g;
					if (rgb.b <= 9) {
						stream << '0';
					}
					stream << std::hex << rgb.b;
					return stream.str();
				}

				template <class T> std::string toHex(const BGRA<T> & color)
				{
					auto stream = std::ostringstream();
					stream << '#';
					if (rgb.r <= 9) {
						stream << '0';
					}
					stream << std::hex << rgb.r;
					if (rgb.g <= 9) {
						stream << '0';
					}
					stream << std::hex << rgb.g;
					if (rgb.b <= 9) {
						stream << '0';
					}
					stream << std::hex << rgb.b;
					return stream.str();
				}
				template <class T> std::string toHex(const CMYK<T> & color)
				{
					return toHex<T>(toRGB<T>(color));
				}

				template <class T> RGB<T> toRGB(const std::string & color)
				{
					const auto ratio = std::numeric_limits<T>::max() / 255;
					RGB<T> result;
					std::sscanf(color.data(), "#%02x%02x%02x", &result.r, &result.g, &result.b);
					result.r *= ratio;
					result.g *= ratio;
					result.b *= ratio;
					return std::move(result);
				}

				template <class T> RGBA<T> toRGBA(const std::string & color)
				{
					const auto ratio = std::numeric_limits<T>::max() / 255;
					RGB<T> result;
					std::sscanf(color.data(), "#%02x%02x%02x", &result.r, &result.g, &result.b);
					result.r *= ratio;
					result.g *= ratio;
					result.b *= ratio;
					result.a = std::numeric_limits<T>::max();
					return std::move(result);
				}

				template <class T> BGR<T> toBGR(const std::string & color)
				{
					const auto ratio = std::numeric_limits<T>::max() / 255;
					RGB<T> result;
					std::sscanf(color.data(), "#%02x%02x%02x", &result.r, &result.g, &result.b);
					result.r *= ratio;
					result.g *= ratio;
					result.b *= ratio;
					return std::move(result);
				}

				template <class T> BGRA<T> toBGRA(const std::string & color)
				{
					const auto ratio = std::numeric_limits<T>::max() / 255;
					RGB<T> result;
					std::sscanf(color.data(), "#%02x%02x%02x", &result.r, &result.g, &result.b);
					result.r *= ratio;
					result.g *= ratio;
					result.b *= ratio;
					result.a = std::numeric_limits<T>::max();
					return std::move(result);
				}

				template <class T> CMYK<T> toCMYK(const std::string & color)
				{
					return toCMYK<T>(toRGB<T>(color));
				}
			} // namespace bitmap
		} // namespace formats
	} // namespace utility
} // namespace ece