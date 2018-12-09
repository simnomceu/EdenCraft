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

#ifndef ANGLE_HPP
#define ANGLE_HPP

#include <cmath>

namespace ece
{
    namespace utility
    {
        namespace mathematics
        {
        	/**
        	 * @class Angle
        	 * @tparam T Euler angle accept any numeric type.
        	 * @brief Euler angle defines rotation of an object as X, Y, and Z axis independent rotations.
        	 * @remark A constructor from Matrix should be added.
        	 * @remark Add a check for templated parameter (numerical type)
        	 */
        	template <template <class> class D, class T>
        	class Angle
        	{
        	public:
        		/**
        		 * @fn constexpr Angle() noexcept
        		 * @brief
        		 * @throw noexcept
        		 */
        		inline constexpr Angle() noexcept = default;

                inline Angle(T angle) noexcept;

        		/**
        		 * @fn Angle(const Angle<T> & copy) noexcept
        		 * @param[in] copy The Euler angle to copy from.
        		 * @brief Default copy constructor.
        		 * @throw noexcept
        		 */
        		Angle(const Angle<D, T> & copy) noexcept = default;

        		/**
        		 * @fn Angle(Angle<T> && move) noexcept
        		 * @param[in] move The Euler angle to move.
        		 * @brief Default move constructor.
        		 * @throw noexcept
        		 */
        		Angle(Angle<D, T> && move) noexcept = default;

        		/**
        		 * @fn ~Angle()
        		 * @brief Default destructor.
        		 * @throw noexcept
        		 */
        		~Angle() noexcept = default;

        		/**
        		 * @fn Angle<T> & operator=(const Angle<T> & copy) noexcept
        		 * @param[in] copy The Euler angle to copy from.
        		 * @return The Euler angle copied.
        		 * @brief Default copy assignment operator.
        		 * @throw noexcept
        		 */
        		Angle<D, T> & operator=(const Angle<D, T> & copy) noexcept = default;

        		/**
        		 * @fn Angle<T> & operator=(Angle<T> && move) noexcept
        		 * @param[in] move The Euler angle to move.
        		 * @return The Euler angle moved.
        		 * @brief Default move assignment operator.
        		 * @throw noexcept
        		 */
        		Angle<D, T> & operator=(Angle<D, T> && move) noexcept = default;

                inline Angle<D, T> & operator=(T angle) noexcept;

                inline operator T();
                inline operator T &();

                inline auto operator-() const;

                inline auto operator+(const D<T> & rhs) const;
                inline auto operator-(const D<T> & rhs) const;

                inline auto & operator+=(const D<T> & rhs);
                inline auto & operator-=(const D<T> & rhs);

                inline auto operator*(T scalar) const;
                inline auto operator/(T scalar) const;

                inline auto & operator*=(T scalar);
                inline auto & operator/=(T scalar);

                inline auto operator==(const D<T> & rhs) const;
                inline auto operator!=(const D<T> & rhs) const;
                inline auto operator>(const D<T> & rhs) const;
                inline auto operator>=(const D<T> & rhs) const;
                inline auto operator<(const D<T> & rhs) const;
                inline auto operator<=(const D<T> & rhs) const;

            private:
                T _value;
        	};
        } // namespace mathematics
    } // namespace utility
} // namespace ece

#include "utility/mathematics/angle.inl"

#endif // ANGLE_HPP
