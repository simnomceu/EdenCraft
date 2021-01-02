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

#ifndef INTERPOLATION_HPP
#define INTERPOLATION_HPP

#include "utility/config.hpp"

namespace ece
{
    namespace utility
    {
        namespace mathematics
        {
        	/**
        	 * T lerp(const T a, const T b)
        	 * @tparam T Can be compute with any numerical type.
        	 * @param[in] a The beginning of the interpolation.
        	 * @param[in] b The end of the interpolation.
             * @param[in] percent The percentage of progress between a and b.
        	 * @return The interpolation.
        	 * @brief Linear interpolation between a and b.
        	 * @throw
        	 */
        	template <class T>
			ECE_UTILITY_API auto lerp(const T a, const T b, float percent);

        	/**
        	 * Quaternion<T> slerp(const T t, const Quaternion<T> & a, const Quaternion<T> & b)
        	 * @tparam T Can be compute with any numerical type.
        	 * @param[in] t The percentage of interpolation to apply.
        	 * @param[in] a The beginning of the interpolation.
        	 * @param[in] b The end of the interpolation.
        	 * @return The interpolation.
        	 * @brief Spheric linear interpolation between a and b.
        	 * @throw.
        	 */
        	template <class T>
			ECE_UTILITY_API auto slerp(const T a, const T b, float percent);

            template <class T>
            ECE_UTILITY_API auto nlerp(const T a, const T b, float percent);
        } // namespace mathematics
    } // namespace utility
} // namespace ece

#include "utility/mathematics/interpolation.inl"

#endif // INTERPOLATION_HPP
