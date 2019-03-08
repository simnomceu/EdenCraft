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

			} // namespace bitmap
		} // namespace formats
	} // namespace utility
} // namespace ece