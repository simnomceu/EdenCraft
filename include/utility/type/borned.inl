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
		namespace type
		{
			template <class T>
			inline Borned<T>::Borned(T value, T lower, T upper) : value(value), lowerBound(lower), upperBound(upper)
			{
			}

			template <class T>
			inline Borned<T>::Borned(const Borned<T> & copy) : value(copy.value), lowerBound(copy.lowerBound), upperBound(copy.upperBound)
			{
			}

			template <class T>
			inline Borned<T>::Borned(Borned<T> && move) : value(std::move(move.value)), lowerBound(std::move(move.lowerBound)), upperBound(std::move(move.upperBound))
			{
			}

			template <class T>
			inline Borned<T> & Borned<T>::operator=(const Borned<T> & copy)
			{
				this->value = copy.value;
				return *this;
			}

			template <class T>
			inline Borned<T> & Borned<T>::operator=(Borned<T> && move)
			{
				this->value = std::move(move.value);
				return *this;
			}

			template <class T>
			inline Borned<T> & Borned<T>::operator=(T v)
			{
				ece_assert(v >= lowerBound && v <= upperBound, "This value does not respect the boundaries.");
				this->value = v;
				return *this;
			}

			template <class T>
			inline Borned<T>::operator T &()
			{
				return this->value;
			}

			template <class T>
			inline Borned<T>::operator const T &() const
			{
				return this->value;
			}

			inline Percentage::Percentage(const Percentage & copy) : Borned<float>(copy)
			{
			}

			inline Percentage::Percentage(Percentage && move) : Borned<float>(move)
			{
			}

			inline Percentage::Percentage() : Borned<float>{ 0.0f, 0.0f, 1.0f }
			{
			}

			inline Percentage & Percentage::operator=(const Percentage & copy)
			{
				this->value = copy.value;
				return *this;
			}

			inline Percentage & Percentage::operator=(Percentage && move)
			{
				this->value = std::move(move.value);
				return *this;
			}

			inline Percentage & Percentage::operator=(float v)
			{
				Borned<float>::operator=(v);
				return *this;
			}
		} // namespace type
	} // namespace utility
} // namespace ece