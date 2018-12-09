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

#ifndef RADIAN_HPP
#define RADIAN_HPP

#include "utility/mathematics/angle.hpp"

namespace ece
{
    namespace utility
    {
        namespace mathematics
        {
            template <class T> class Radian;

        	/**
        	 * @class Radian
        	 * @tparam T Euler Radian accept any numeric type.
        	 * @brief Euler Radian defines rotation of an object as X, Y, and Z axis independent rotations.
        	 * @remark A constructor from Matrix should be added.
        	 * @remark Add a check for templated parameter (numerical type)
        	 */
        	template <class T>
        	class ECE_UTILITY_API Radian: public Angle<Radian, T>
        	{
        	public:
        		/**
        		 * @fn constexpr Radian() noexcept
        		 * @brief
        		 * @throw noexcept
        		 */
        		inline constexpr Radian() noexcept = default;

                inline Radian(T angle) noexcept;

        		/**
        		 * @fn Radian(const Radian<T> & copy) noexcept
        		 * @param[in] copy The Euler Radian to copy from.
        		 * @brief Default copy constructor.
        		 * @throw noexcept
        		 */
        		Radian(const Radian<T> & copy) noexcept = default;

        		/**
        		 * @fn Radian(Radian<T> && move) noexcept
        		 * @param[in] move The Euler Radian to move.
        		 * @brief Default move constructor.
        		 * @throw noexcept
        		 */
        		Radian(Radian<T> && move) noexcept = default;

        		/**
        		 * @fn ~Radian()
        		 * @brief Default destructor.
        		 * @throw noexcept
        		 */
        		~Radian() noexcept = default;

        		/**
        		 * @fn Radian<T> & operator=(const Radian<T> & copy) noexcept
        		 * @param[in] copy The Euler Radian to copy from.
        		 * @return The Euler Radian copied.
        		 * @brief Default copy assignment operator.
        		 * @throw noexcept
        		 */
        		Radian<T> & operator=(const Radian<T> & copy) noexcept = default;

        		/**
        		 * @fn Radian<T> & operator=(Radian<T> && move) noexcept
        		 * @param[in] move The Euler Radian to move.
        		 * @return The Euler Radian moved.
        		 * @brief Default move assignment operator.
        		 * @throw noexcept
        		 */
        		Radian<T> & operator=(Radian<T> && move) noexcept = default;

                inline constexpr auto toDegree() const;

                inline auto normalizePi() const;
                inline auto normalizeTwoPi() const;
        	};
        } // namespace mathematics
    } // namespace utility
} // namespace ece

#include "utility/mathematics/radian.inl"

#endif // RADIAN_HPP
