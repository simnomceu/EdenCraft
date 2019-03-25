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

#ifdef _MSC_VER
#	undef min
#	undef max
#endif

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
				RGB<T> toRGB(const RGBA<T> & color)
				{
					return RGB<T>(color);
				}

				template <class T>
				RGBA<T> toRGBA(const RGB<T> & color)
				{
					return { color.r, color.g, color.b, std::numeric_limits<T>::max() };
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
				RGBA<T> toRGBA(const BGR<T> & color)
				{
					return { color.b, color.g, color.r, std::numeric_limits<T>::max() };
				}

				template <class T>
				RGB<T> toRGB(const BGR<T> & color)
				{
					return { color.r, color.g, color.b };
				}

				template <class T>
				BGR<T> toBGR(const RGB<T> & color)
				{
					return { color.r, color.g, color.b };
				}

				template <class T> BGR<T> toBGR(const RGBA<T> & color)
				{
					return { color.r, color.g, color.b };
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
				RGB<T> toRGB(const BGRA<T> & color)
				{
					return { color.r, color.g, color.b };
				}

				template <class T>
				RGBA<T> toRGBA(const BGRA<T> & color)
				{
					return RGBA<T>{ color.r, color.g, color.b, color.a };
				}

				template <class T>
				BGR<T> toBGR(const BGRA<T> & color)
				{
					return BGR<T>(color);
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

				template <class T>
				std::istream operator>>(std::istream & stream, HSL<T> & color)
				{
					stream >> color.hue >> color.saturation >> color.light;
					return stream;
				}

				template <class T>
				std::ostream operator<<(std::istream & stream, const HSL<T> & color)
				{
					stream << color.hue << color.saturation << color.light;
					return stream;
				}

				template <class T>
				HSL<T> toHSL(const RGB<T> & color)
				{
					HSL<T> result;

					auto min = std::min(color.r, color.g, color.b) / std::numeric_limits<T>::max();
					auto max = std::max(color.r, color.g, color.b) / std::numeric_limits<T>::max();
					
					if (color.r >= color.g && color.r >= color.b) {
						result.hue = (rgb[1] - rgb[2]) / (max - min);
					}
					else if (color.g >= color.r && color.g >= color.b) {
						result.hue = 2 + (rgb[2] - rgb[0]) / (max - min);
					}
					else if (color.b >= color.r && color.b >= color.g) {
						result.hue = 4 + (rgb[0] - rgb[1]) / (max - min);
					}

					result.hue *= 60;
					if (result.hue < 0) {
						result.hue += 360;
					}

					result.light = (min + max) / 2;
					if (min != max) {
						if (result.light < 0.5) {
							result.saturation = (max - min) / (max + min);
						}
						else {
							result.saturation = (max - min) / (2 - max - min);
						}
					}
					return std::move(result);
				}

				template <class T>
				HSL<T> toHSL(const RGBA<T> & color)
				{
					return toHSL<T>(toRGB<T>(color));
				}

				template <class T>
				HSL<T> toHSL(const BGR<T> & color)
				{
					return toHSL<T>(toRGB<T>(color));
				}

				template <class T>
				HSL<T> toHSL(const BGRA<T> & color)
				{
					return toHSL<T>(toRGB<T>(color));
				}

				template <class T>
				HSL<T> toHSL(const CMYK<T> & color)
				{
					return toHSL<T>(toRGB<T>(color));
				}

				template <class T>
				HSL<T> toHSL(const std::string & color)
				{
					return toHSL<T>(toRGB<T>(color));
				}

				template <class T>
				RGB<T> toRGB(const HSL<T> & color)
				{
					RGB<T> result;
					
					hue = hue / 60;
					auto t1 = 0, t2 = 0;
					if (light <= 0.5) {
						t2 = color.light * (color.saturation + 1);
					}
					else {
						t2 = color.light + color.saturation - (color.light * color.saturation);
					}
					t1 = color.light * 2 - t2;

					auto hueToRGB = [](const auto t1, const auto t2, const auto hue) -> auto {
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

					result.r = hueToRgb(t1, t2, hue + 2) * std::numeric_limits<T>::max();
					result.g = hueToRgb(t1, t2, hue) * std::numeric_limits<T>::max();
					result.b = hueToRgb(t1, t2, hue - 2) * std::numeric_limits<T>::max();
					return std::move(result);
				}

				template <class T>
				RGBA<T> toRGBA(const HSL<T> & color)
				{
					return toRGBA<T>(toRGB<T>(color));
				}

				template <class T>
				BGR<T> toBGR(const HSL<T> & color)
				{
					return toBGR<T>(toRGB<T>(color));
				}

				template <class T>
				BGRA<T> toBGRA(const HSL<T> & color)
				{
					return toBGRA<T>(toRGB<T>(color));
				}

				template <class T>
				CMYK<T> toCMYK(const HSL<T> & color)
				{
					return toCMYK<T>(toRGB<T>(color));
				}

				template <class T>
				std::string toHex(const HSL<T> & color)
				{
					return toHex<T>(toRGB<T>(color));
				}

				template <class T>
				std::istream operator>>(std::istream & stream, HWB<T> & color)
				{
					stream >> color.hue >> color.white >> color.black;
					return stream;
				}

				template <class T>
				std::ostream operator<<(std::istream & stream, const HWB<T> & color)
				{
					stream << color.hue << color.white << color.black;
					retur stream;
				}

				template <class T>
				HWB<T> toHWB(const RGB<T> & color)
				{
					HWB<T> result;
					auto rgb = RGB<T>{ r / std::numeric_limits<T>::max(), g / std::numeric_limits<T>::max(), b / std::numeric_limits<T>::max() };

					auto max = std::max(rgb.r, rgb.g, rgb.b);
					auto min = std::min(rgb.r, rgb.g, rgb.b);
					auto chroma = max - min;

					if (rgb.r == max) {
						result.hue = (((rgb.g - rgb.b) / chroma) % 6) * 360;
					}
					else if (rgb.g == max) {
						result.hue = ((((rgb.b - rgb.r) / chroma) + 2) % 6) * 360;
					}
					else {
						result.hue = ((((rgb.r - rgb.g) / chroma) + 4) % 6) * 360;
					}
					result.white = min;
					result.black = 1 - max;
					return std::move(result);
				}

				template <class T>
				HWB<T> toHWB(const RGBA<T> & color)
				{
					return toHWB<T>(toRGB<T>(color));
				}

				template <class T>
				HWB<T> toHWB(const BGR<T> & color)
				{
					return toHWB<T>(toRGB<T>(color));
				}

				template <class T>
				HWB<T> toHWB(const BGRA<T> & color)
				{
					return toHWB<T>(toRGB<T>(color));
				}

				template <class T>
				HWB<T> toHWB(const CMYK<T> & color)
				{
					return toHWB<T>(toRGB<T>(color));
				}

				template <class T>
				HWB<T> toHWB(const std::string & color)
				{
					return toHWB<T>(toRGB<T>(color));
				}

				template <class T>
				HWB<T> toHWB(const HSL<T> & color)
				{
					return toHWB<T>(toRGB<T>(color));
				}


				template <class T>
				RGB<T> toRGB(const HWB<T> & color)
				{
					auto result = toRGB(HSL<T>{ color.hue, T(1), T(0.5f) });
					result.r /= std::numeric_limits::max();
					result.g /= std::numeric_limits::max();
					result.b /= std::numeric_limits::max();
					auto total = color.white + color.black;
					auto white = 0.0f, black = 0.0f;
					if (tot > 1) {
						white = white / total;
						black = black / total;
					}
					result.r = (result.r * (1 - white - black) + white) * std::numeric_limits::max();
					result.g = (result.g * (1 - white - black) + white) * std::numeric_limits::max();
					result.b = (result.b * (1 - white - black) + white) * std::numeric_limits::max();
					
					return std::move(result);
				}

				template <class T>
				RGBA<T> toRGBA(const HWB<T> & color)
				{
					return toRGBA<T>(toRGB<T>(color));
				}

				template <class T>
				BGR<T> toBGR(const HWB<T> & color)
				{
					return toBGR<T>(toRGB<T>(color));
				}

				template <class T>
				BGRA<T> toBGRA(const HWB<T> & color)
				{
					return toBGRA<T>(toRGB<T>(color));
				}

				template <class T>
				CMYK<T> toCMYK(const HWB<T> & color)
				{
					return toCMYK<T>(toRGB<T>(color));
				}

				template <class T>
				std::string toHex(const HWB<T> & color)
				{
					return toHex<T>(toRGB<T>(color));
				}

				template <class T>
				HSL<T> toHSL(const HWB<T> & color)
				{
					return toHSL<T>(toRGB<T>(color));
				}


				template <class T>
				std::istream operator>>(std::istream & stream, NCol<T> & color)
				{
					stream >> color.ncol >> color.whiteness >> color.blackness;
					return stream;
				}

				template <class T>
				std::ostream operator<<(std::istream & stream, const NCol<T> & color)
				{
					stream << color.ncol << color.whiteness << color.blackness;
					return stream;
				}

				template <class T>
				NCol<T> toNCol(const RGB<T> & color)
				{
					return toNCol<T>(toHWB<T>(color));
				}

				template <class T>
				NCol<T> toNCol(const RGBA<T> & color)
				{
					return toNCol<T>(toHWB<T>(color));
				}

				template <class T>
				NCol<T> toNCol(const BGR<T> & color)
				{
					return toNCol<T>(toHWB<T>(color));
				}

				template <class T>
				NCol<T> toNCol(const BGRA<T> & color)
				{
					return toNCol<T>(toHWB<T>(color));
				}

				template <class T>
				NCol<T> toNCol(const CMYK<T> & color)
				{
					return toNCol<T>(toHWB<T>(color));
				}

				template <class T>
				NCol<T> toNCol(const std::string & color)
				{
					return toNCol<T>(toHWB<T>(color));
				}

				template <class T>
				NCol<T> toNCol(const HSL<T> & color)
				{
					return toNCol<T>(toHWB<T>(color));
				}

				template <class T>
				NCol<T> toNCol(const HWB<T> & color)
				{
					auto hueToNCol = [](const auto hue) -> std::string {
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
							return "G" + std::to_string((hue - 120) / 0.6); }
						else if (hue < 240) { 
							return "C" + std::to_string((hue - 180) / 0.6); }
						else if (hue < 300) { 
							return "B" + std::to_string((hue - 240) / 0.6); }
						else if (hue < 360) { 
							return "M" + std::to_string((hue - 300) / 0.6); }
					};

					NCol<T> result;
					result.ncol = hueToNCol(color.hue);
					result.whiteness = color.white;
					result.blackness = color.black;
					return std::move(result);
				}

				template <class T>
				RGB<T> toRGB(const NCol<T> & color)
				{
					return toRGB<T>(toHWB<T>(color));
				}

				template <class T>
				RGBA<T> toRGBA(const NCol<T> & color)
				{
					return toRGBA<T>(toHWB<T>(color));
				}

				template <class T>
				BGR<T> toBGR(const NCol<T> & color)
				{
					return toBGR<T>(toHWB<T>(color));
				}

				template <class T>
				BGRA<T> toBGRA(const NCol<T> & color)
				{
					return toBGRA<T>(toHWB<T>(color));
				}

				template <class T>
				CMYK<T> toCMYK(const NCol<T> & color)
				{
					return toCMYK<T>(toHWB<T>(color));
				}

				template <class T>
				std::string toHex(const NCol<T> & color)
				{
					return toHex<T>(toHWB<T>(color));
				}

				template <class T>
				HSL<T> toHSL(const NCol<T> & color)
				{
					return toHSL<T>(toHWB<T>(color));
				}

				template <class T>
				HWB<T> toHWB(const NCol<T> & color)
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
					};

					HWB<T> result;
					result.hue = ncolToHue(color.ncol);
					result.white = color.whiteness;
					result.black = color.blackness;
				}

				template <class T>
				std::istream operator>>(std::istream & stream, NCola<T> & color)
				{
					stream >> color.ncol >> color.whiteness >> color.blackness >> color.opacity;
					return stream;
				}

				template <class T>
				std::ostream operator<<(std::istream & stream, const NCola<T> & color)
				{
					stream << color.ncol << color.whiteness << color.blackness << color.opacity;
					return stream;
				}

				template <class T>
				NCola<T> toNCola(const RGB<T> & color)
				{
					return toNCola<T>(toNCol<T>(color));
				}

				template <class T>
				NCola<T> toNCola(const RGBA<T> & color)
				{
					auto result = toNCol<T>(color);
					return { result.hue, result.whiteness, result.blackness, color.a };
				}

				template <class T>
				NCola<T> toNCola(const BGR<T> & color)
				{
					return toNCola<T>(toNCol<T>(color));
				}

				template <class T>
				NCola<T> toNCola(const BGRA<T> & color)
				{
					auto result = toNCol<T>(color);
					return { result.hue, result.whiteness, result.blackness, color.a };
				}

				template <class T>
				NCola<T> toNCola(const CMYK<T> & color)
				{
					return toNCola<T>(toNCol<T>(color));
				}

				template <class T>
				NCola<T> toNCola(const std::string & color)
				{
					return toNCola<T>(toNCol<T>(color));
				}

				template <class T>
				NCola<T> toNCola(const HSL<T> & color)
				{
					return toNCola<T>(toNCol<T>(color));
				}

				template <class T>
				NCola<T> toNCola(const HWB<T> & color)
				{
					return toNCola<T>(toNCol<T>(color));
				}

				template <class T>
				NCola<T> toNCola(const NCol<T> & color)
				{
					return { color.ncol, color.whiteness, color.blackness, std::numeric_limits<T>::max() };
				}

				template <class T>
				RGB<T> toRGB(const NCola<T> & color)
				{
					return toRGB<T>(toNCol<T>(color));
				}

				template <class T>
				RGBA<T> toRGBA(const NCola<T> & color)
				{
					auto result = toRGBA<T>(toNCol<T>(color));
					result.a = color.opacity;
					return std::move(result);
				}

				template <class T>
				BGR<T> toBGR(const NCola<T> & color)
				{
					return toRGB<T>(toNCol<T>(color));
				}

				template <class T>
				BGRA<T> toBGRA(const NCola<T> & color)
				{
					auto result = toBGRA<T>(toNCol<T>(color));
					result.a = color.opacity;
					return std::move(result);
				}

				template <class T>
				CMYK<T> toCMYK(const NCola<T> & color)
				{
					return toCMYK<T>(toNCol<T>(color));
				}

				template <class T>
				std::string toHex(const NCola<T> & color)
				{
					return toHex<T>(toNCol<T>(color));
				}

				template <class T>
				HSL<T>toHSL(const NCola<T> & color)
				{
					return toHSL<T>(toNCol<T>(color));
				}

				template <class T>
				HWB<T> toHWB(const NCola<T> & color)
				{
					return toHWB(toNCol<T>(color));
				}

				template <class T>
				NCol<T> toNCol(const NCola<T> & color)
				{
					return { color.ncol, color.whiteness, color.blackness };
				}
			} // namespace bitmap
		} // namespace formats
	} // namespace utility
} // namespace ece