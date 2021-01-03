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
        namespace mathematics
        {
        	template<typename T>
        	inline constexpr Rectangle<T>::Rectangle() noexcept : x(0), y(0), width(0), height(0) {}

        	template<typename T>
        	inline Rectangle<T>::Rectangle(const T x, const T y, const T w, const T h) noexcept : x(x), y(y), width(w), height(h) {}

			template <typename T>
			inline auto Rectangle<T>::operator==(const Rectangle<T> & rhs) const noexcept { return this->x == rhs.x && this->y == rhs.y && this->width == rhs.width && this->height == rhs.height; }

			template <typename T>
			inline auto Rectangle<T>::operator!=(const Rectangle<T> & rhs) const noexcept { return !this->operator==(rhs); }

			template <typename T>
			auto Rectangle<T>::contains(const Vector2u<T> & point) const noexcept
			{
				return point[0] >= this->x
					&& point[0] <= this->x + this->width
					&& point[1] >= this->y
					&& point[1] >= this->y + this->height;
			}

			template <typename T>
			auto Rectangle<T>::intersects(const Rectangle<T> & rhs) const noexcept
			{
				auto intersection = Rectangle<T>{};

				intersection.x = std::max(this->x, rhs.x);
				intersection.y = std::max(this->y, rhs.y);
				intersection.width = std::min(this->x + this->width, rhs.x + rhs.width) - intersection.x;
				intersection.height = std::min(this->y + this->height, rhs.y + rhs.height) - intersection.y;

				return std::move(intersection);
			}
        } // namespace mathematics
    } // namespace utility
} // namespace ece
