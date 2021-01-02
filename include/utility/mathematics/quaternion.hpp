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

#ifndef QUATERNION_HPP
#define QUATERNION_HPP

#include "utility/config.hpp"
#include "utility/pch.hpp"

namespace ece
{
    namespace utility
    {
        namespace mathematics
        {
	        template <class T> class EulerAngle;
        } // namespace mathematics
    } // namespace utility
} // namespace ece

#include "utility/mathematics/matrix4u.hpp"
#include "utility/mathematics/vector3u.hpp"

namespace ece
{
    namespace utility
    {
        namespace mathematics
        {
        	/**
        	 * @class Quaternion
        	 * @tparam T Quaternion accept any numeric type.
        	 * @brief Quaternion is a complex number in three-dimensional space.
        	 * @remark Add a check for templated parameter (numeric type)
        	 */
        	template <class T>
        	class ECE_UTILITY_API Quaternion
        	{
        	public:
        		/**
        		 * @fn constexpr Quaternion() noexcept
        		 * @brief Default constructor. Quaternion is initialized as 0i + 0j + 0k + 1.
        		 * @throw noexcept
        		 */
        		inline constexpr Quaternion() noexcept;

        		/**
        		 * Quaternion(const T w, const T x, const T y, const T z) noexcept
        		 * @param[in] w The real part of the quaternion.
        		 * @param[in] x The x-axis complex part of the quaternion.
        		 * @param[in] y The y-axis complex part of the quaternion
        		 * @param[in] z The z-axis complex part of the quaternion
        		 * @brief Build a quaternion as xi + yj + zk + w.
        		 * @throw noexcept
        		 */
        		inline Quaternion(const T w, const T x, const T y, const T z) noexcept;

        		/**
        		 * @fn Quaternion(const T angle, const Vector3u<T> & axis) noexcept
        		 * @param[in] angle The angle of the rotation to set.
        		 * @param[in] axis The axis of the rotation to set.
        		 * @brief Build a quaternion from a classic rotation defined by the angle an the axis of rotation.
        		 * @throw noexcept
        		 */
        		inline Quaternion(const T angle, const Vector3u<T> & axis) noexcept;

        		/**
        		 * @fn Quaternion(const EulerAngle<T> & eulerAngle)
        		 * @param[in] eulerAngle the Euler angle rotation to convert.
        		 * @brief Build a quaternion from an Euler angle rotation.
        		 * @throw
        		 */
        		Quaternion(const EulerAngle<T> & eulerAngle);

        		/**
        		 * @fn Quaternion(const Quaternion<T> & copy)
        		 * @param[in] copy The quaternion to copy from.
        		 * @brief Default copy constructor.
        		 * @throw noexcept
        		 */
        		Quaternion(const Quaternion<T> & copy) noexcept = default;

        		/**
        		 * @fn Quaternion(Quaternion<T> && move) noexcept
        		 * @param[in] move The quaternion to move.
        		 * @brief Default move constructor.
        		 * @throw noexcept
        		 */
        		Quaternion(Quaternion<T> && move) noexcept = default;

        		/**
        		 * @fn ~Quaternion() noexcept
        		 * @brief Default destructor.
        		 * @throw noexcept
        		 */
        		~Quaternion() noexcept = default;

        		/**
        		 * @fn Quaternion<T> & operator=(const Quaternion<T> & copy) noexcept
        		 * @param[in] copy The quaternion to copy from.
        		 * @return The quaternion copied.
        		 * @brief Default copy assignment operator.
        		 * @throw noexcept
        		 */
        		Quaternion<T> & operator=(const Quaternion<T> & copy) noexcept = default;

        		/**
        		 * @fn Quaternion<T> & operator=(Quaternion<T> && move) noexcept
        		 * @param[in] move The quaternion to move.
        		 * @return The quaternion moved.
        		 * @brief Default move assignment operator.
        		 * @throw noexcept
        		 */
        		Quaternion<T> & operator=(Quaternion<T> && move) noexcept = default;

        		/**
        		 * @fn Quaternion<T> operator+(const Quaternion<T> & rightOperator) const noexcept
        		 * @param[in] rightOperator The right hand side of the addition operation.
        		 * @return The two quaternion added.
        		 * @brief Add two quaternions.
        		 * @throw noexcept
        		 * @remark Parameter could be renamed like "rhs" (right hand side).
        		 */
        		inline Quaternion<T> operator+(const Quaternion<T> & rightOperator) const noexcept;

        		/**
        		 * @fn Quaternion<T> operator-(const Quaternion<T> & rightOperator) const noexcept
        		 * @param[in] rightOperator The right hand side of the subtraction operation.
        		 * @return The two quaternion subtracted.
        		 * @brief Subtract two quaternions.
        		 * @throw noexcept
        		 * @remark Parameter could be renamed like "rhs" (right hand side).
        		 */
        		inline Quaternion<T> operator-(const Quaternion<T> & rightOperator) const noexcept;

        		/**
        		 * @fn Quaternion<T> operator*(const U rightOperator) const noexcept
        		 * @tparam U Type of the right hand side.
        		 * @param[in] rightOperator The right hand side of the multiplication operation.
        		 * @return The result of the multiplication.
        		 * @brief Multiply the quaternion by a scalar.
        		 * @throw noexcept
        		 * @remark Parameter could be renamed like "rhs" (right hand side).
        		 * @remark Add a static assertion to check the U templated parameter.
        		 */
        		template<class U> inline Quaternion<T> operator*(const U rightOperator) const noexcept;

        		/**
        		 * @fn Quaternion<T> operator*(const Quaternion<T> & rightOperator) const
        		 * @param[in] rightOperator The right hand side of the multiplication operation.
        		 * @return The result of the multiplication.
        		 * @brief Multiply a quaternion by another quaternion.
        		 * @throw
        		 * @remark Parameter could be renamed like "rhs" (right hand side).
        		 */
        		Quaternion<T> operator*(const Quaternion<T> & rightOperator) const;

        		/**
        		 * @fn Quaternion<T> operator/(const U rightOperator) const noexcept
        		 * @tparam U Type of the right hand side.
        		 * @param[in] rightOperator The right hand side of the division operation.
        		 * @return The result of the division.
        		 * @brief Divide a quaternion by a scalar.
        		 * @throw noexcept
        		 * @remark Parameter could be renamed like "rhs" (right hand side).
        		 * @remark Add a static assertion to check the U templated parameter.
        		 */
        		template<class U> inline Quaternion<T> operator/(const U rightOperator) const noexcept;

        		/**
        		 * @remark Is there missing operation ? Like *= /= and division by a quaternion.
        		 */

        		/**
        		 * @fn Quaternion<T> & operator+=(const Quaternion<T> & rightOperator) noexcept
        		 * @param[in] rightOperator The right hand side of the addition operation.
        		 * @return This object modified.
        		 * @brief Add the right hand side to the current quaternion.
        		 * @throw noexcept
        		 */
        		Quaternion<T> & operator+=(const Quaternion<T> & rightOperator) noexcept;

        		/**
        		 * @fn Quaternion<T> & operator-=(const Quaternion<T> & rightOperator) noexcept
        		 * @param[in] rightOperator The right hand side of the subtraction operation.
        		 * @return This object modified.
        		 * @brief Subtract the right hand side to the current quaternion.
        		 * @throw noexcept
        		 */
        		Quaternion<T> & operator-=(const Quaternion<T> & rightOperator) noexcept;

        		/**
        		 * @fn Quaternion<T> conjugate() const noexcept
        		 * @return The conjugate of the quaternion.
        		 * @brief Get the conjugation of the quaternion.
        		 * For a quaternion w + xi + yj + zk, its conjugation is w - xi - yj - zk.
        		 * @throw noexcept
        		 */
        		inline Quaternion<T> conjugate() const noexcept;

        		/**
        		 * @fn T norm() const noexcept
        		 * @return The norm of the quaternion.
        		 * @brief Get the norm of the quaternion.
        		 * @throw noexcept
        		 */
        		inline T norm() const noexcept;

        		/**
        		 * @fn Quaternion<T> normalize() const noexcept
        		 * @return The current quaternion normalized.
        		 * @brief Get a normalized version of this quaternion.
        		 * @throw noexcept
        		 */
        		inline Quaternion<T> normalize() const noexcept;

        		/**
        		 * @fn Quaternion<T> inverse() const noexcept
        		 * @return The inverse quaternion.
        		 * @brief Get the inverse of this quaternion.
        		 * @throw noexcept
        		 */
        		inline Quaternion<T> inverse() const noexcept;

        		/**
        		 * @fn T dot(const Quaternion<T> & rightOperand) const noexcept
        		 * @param[in] rightOperand The right hand side of the dot product.
        		 * @return The dot product of this quaternion with another one.
        		 * @brief Get a dot product of this quaternion with anoterh one.
        		 * @throw noexcept
        		 */
        		inline T dot(const Quaternion<T> & rightOperand) const noexcept;

        		/**
        		 * @fn T real() const noexcept
        		 * @return The real part.
        		 * @brief Get the real part of this quaternion.
        		 * @throw noexcept
        		 */
        		inline T real() const noexcept;

        		/**
        		 * @fn T angle() const noexcept
        		 * @return The angle of rotation.
        		 * @brief Get the angle of rotation of this quaternion.
        		 * @throw noexcept
        		 */
        		inline T angle() const noexcept;

        		/**
        		 * @fn Vector3u<T> axis() const noexcept
        		 * @return The axis of rotation.
        		 * @brief Get the axis of rotation of this quaternion.
        		 * @throw noexcept
        		 */
        		inline Vector3u<T> axis() const noexcept;

        		/**
        		 * @fn EulerAngle<T> toEulerAngle() const noexcept
        		 * @return An Euler angle, equivalent to this quaternion.
        		 * @brief Convert this quaternion to an Euler angle representation.
        		 * @throw noexcept
        		 */
        		inline EulerAngle<T> toEulerAngle() const noexcept;

        		/**
        		 * @fn Matrix4u<T> toMatrix() const noexcept
        		 * @return A rotation matrix, equivalent to this quaternion.
        		 * @brief Convert this quaternion to a rotation matrix representation.
        		 * @throw noexcept
        		 */
        		inline Matrix4u<T> toMatrix() const noexcept;

        		/**
        		 * @property _w
        		 * @brief The real part of the quaternion.
        		 */
        		T _w;

        		/**
        		 * @property _x
        		 * @brief The x-axis complex part of the quaternion.
        		 */
        		T _x;

        		/**
        		 * @property _y
        		 * @brief The y-axis complex part of the quaternion.
        		 */
        		T _y;

        		/**
        		 * @property _z
        		 * @brief The z-axis complex part of the quaternion.
        		 */
        		T _z;
        	};
        } // namespace mathematics
    } // namespace utility
} // namespace ece

#include "utility/mathematics/euler_angle.hpp"
#include "utility/mathematics/quaternion.inl"

#endif // QUATERNION_HPP
