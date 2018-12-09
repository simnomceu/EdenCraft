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

#ifndef EULER_ANGLE_HPP
#define EULER_ANGLE_HPP

namespace ece
{
    namespace utility
    {
        namespace mathematics
        {
	        template <class T> class Quaternion;
        } // namespace mathematics
    } // namespace utility
} // namespace ece

#include "utility/mathematics/matrix4u.hpp"

namespace ece
{
    namespace utility
    {
        namespace mathematics
        {
        	/**
        	 * @class EulerAngle
        	 * @tparam T Euler angle accept any numeric type.
        	 * @brief Euler angle defines rotation of an object as X, Y, and Z axis independent rotations.
        	 * @remark A constructor from Matrix should be added.
        	 * @remark Add a check for templated parameter (numerical type)
        	 */
        	template <class T>
        	class EulerAngle
        	{
        	public:
        		/**
        		 * @fn constexpr EulerAngle() noexcept
        		 * @brief
        		 * @throw noexcept
        		 */
        		inline constexpr EulerAngle() noexcept;

        		/**
        		 * @fn EulerAngle(const double roll, const double pitch, const double yaw) noexcept
        		 * @param[in] roll
        		 * @param[in] pitch
        		 * @param[in] yaw
        		 * @brief
        		 * @throw noexcept
        		 * @remark The parameters should be templated, according to the class definition.
        		 */
        		inline EulerAngle(const T roll, const T pitch, const T yaw) noexcept;

        		/**
        		 * @fn EulerAngle(const Quaternion<T> & quaternion)
        		 * @param[in] quaternion
        		 * @brief
        		 * @throw
        		 */
        		EulerAngle(const Quaternion<T> & quaternion);

        		/**
        		 * @fn EulerAngle(const EulerAngle<T> & copy) noexcept
        		 * @param[in] copy The Euler angle to copy from.
        		 * @brief Default copy constructor.
        		 * @throw noexcept
        		 */
        		EulerAngle(const EulerAngle<T> & copy) noexcept = default;

        		/**
        		 * @fn EulerAngle(EulerAngle<T> && move) noexcept
        		 * @param[in] move The Euler angle to move.
        		 * @brief Default move constructor.
        		 * @throw noexcept
        		 */
        		EulerAngle(EulerAngle<T> && move) noexcept = default;

        		/**
        		 * @fn ~EulerAngle()
        		 * @brief Default destructor.
        		 * @throw noexcept
        		 */
        		~EulerAngle() noexcept = default;

        		/**
        		 * @fn EulerAngle<T> & operator=(const EulerAngle<T> & copy) noexcept
        		 * @param[in] copy The Euler angle to copy from.
        		 * @return The Euler angle copied.
        		 * @brief Default copy assignment operator.
        		 * @throw noexcept
        		 */
        		EulerAngle<T> & operator=(const EulerAngle<T> & copy) noexcept = default;

        		/**
        		 * @fn EulerAngle<T> & operator=(EulerAngle<T> && move) noexcept
        		 * @param[in] move The Euler angle to move.
        		 * @return The Euler angle moved.
        		 * @brief Default move assignment operator.
        		 * @throw noexcept
        		 */
        		EulerAngle<T> & operator=(EulerAngle<T> && move) noexcept = default;

        		/**
        		 * @fn Quaternion<T> toQuaternion() const
        		 * @return A quaternion representing the rotation.
        		 * @brief Convert the Euler angle rotation to a quaternion representation.
        		 * @throw
        		 */
        		auto toQuaternion() const -> Quaternion<T>;

        		/**
        		 * @fn Matrix4u<T> toMatrix() const
        		 * @return A matrix representing the rotation.
        		 * @brief Convert the Euler angle rotation to a matrix representation.
        		 * @throw
        		 */
        		auto toMatrix() const -> Matrix4u<T>;

        		/**
        		 * @property roll
        		 * @brief The x-axis rotation, according to Euler/aeronautic notation.
        		 */
        		T roll;

        		/**
        		 * @property pitch
        		 * @brief The y-axis rotation, according to aeronautic notation.
        		 */
        		T pitch;
        		/**
        		 * @property yaw
        		 * @brief The z-axis rotation, according to aeronautic notation.
        		 */
        		T yaw;
        	};
        } // namespace mathematics
    } // namespace utility
} // namespace ece

#include "utility/mathematics/quaternion.hpp"
#include "utility/mathematics/euler_angle.inl"

#endif // EULER_ANGLE_HPP
