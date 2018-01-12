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
				Copyright(C) 2017 Pierre Casati (@IsilinBN)

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

/**
 * @file utility/mathematics/quaternion.inl
 * @author IsilinBN (casa2pir@hotmail.fr)
 * @date January, 6th 2018
 * @copyright ----------
 * @brief Define quaternion rotation.
 */

#include <cmath>

namespace ece
{
	template <class T>
	inline constexpr Quaternion<T>::Quaternion() noexcept: w(1), x(0), y(0), z(0) {}

	template <class T>
	inline Quaternion<T>::Quaternion(const T w, const T x, const T y, const T z) noexcept : w(w), x(x), y(y), z(z) {}

	template <class T>
	inline Quaternion<T>::Quaternion(const T angle, const Vertex3u<T> & axis) noexcept : 
		w(std::cos(angle/2)), 
		x(axis[0]*std::sin(angle/2)), 
		y(axis[1] * std::sin(angle / 2)), 
		z(axis[2] * std::sin(angle / 2)) {}

	template <class T>
	Quaternion<T>::Quaternion(const EulerAngle<T> & eulerAngle): w(0.0), x(0.0), y(0.0), z(0.0)
	{
		double cy = cos(eulerAngle.getYaw() * 0.5);
		double sy = sin(eulerAngle.getYaw() * 0.5);
		double cr = cos(eulerAngle.getRoll() * 0.5);
		double sr = sin(eulerAngle.getRoll() * 0.5);
		double cp = cos(eulerAngle.getPitch() * 0.5);
		double sp = sin(eulerAngle.getPitch() * 0.5);

		this->w = cy * cr * cp + sy * sr * sp;
		this->x = cy * sr * cp - sy * cr * sp;
		this->y = cy * cr * sp + sy * sr * cp;
		this->z = sy * cr * cp - cy * sr * sp;
	}

	template <class T>
	inline Quaternion<T> Quaternion<T>::operator+(const Quaternion<T> & rightOperator) const noexcept
	{
		return Quaternion<T>(this->w + rightOperator.w,
							 this->x + rightOperator.x,
							 this->y + rightOperator.y,
							 this->z + rightOperator.z);
	}

	template <class T>
	inline Quaternion<T> Quaternion<T>::operator-(const Quaternion<T> & rightOperator) const noexcept
	{
		return Quaternion<T>(this->w - rightOperator.w,
			this->x - rightOperator.x,
			this->y - rightOperator.y,
			this->z - rightOperator.z);
	}

	template <class T, class U>
	inline Quaternion<T> Quaternion<T>::operator*(const U rightOperator) const noexcept
	{
		return Quaternion<T>(this->w * rightOperator, this->x * rightOperator, this->y * rightOperator, this->z * rightOperator);
	}

	template <class T>
	Quaternion<T> Quaternion<T>::operator*(const Quaternion<T> & rightOperator) const
	{
		Vertex3u<T> lh(this->x, this->y, this->z);
		Vertex3u<T> rh(rightOperator.x, rightOperator.y, rightOperator.z);
		auto product = (rh * this->w) + (lh * rightOperand.w) + (lh * rh);
		return Quaternion<T>((this->w * rightOperator.w) + lh.dot(rh), product.x, product.y, product.z);
	}

	template <class T, class U>
	inline Quaternion<T> Quaternion<T>::operator/(const U rightOperator) const noexcept
	{
		return Quaternion<T>(this->w / rightOperator, this->x / rightOperator, this->y / rightOperator, this->z / rightOperator);
	}

	template <class T>
	Quaternion<T> & Quaternion<T>::operator+=(const Quaternion<T> & rightOperator) noexcept
	{
		this->w += rightOperator.w;
		this->x += rightOperator.x;
		this->y += rightOperator.y;
		this->z += rightOperator.z;
		return *this;
	}

	template <class T>
	Quaternion<T> & Quaternion<T>::operator-=(const Quaternion<T> & rightOperator) noexcept
	{
		this->w -= rightOperator.w;
		this->x -= rightOperator.x;
		this->y -= rightOperator.y;
		this->z -= rightOperator.z;
		return *this;
	}

	template <class T>
	inline Quaternion<T> Quaternion<T>::conjugate() const noexcept
	{
		return Quaternion<T>(this->w, -this->x, -this->y, -this->z);
	}

	template <class T>
	inline T Quaternion<T>::norm() const noexcept
	{
		return (this->w * this->w) + (this->x * this->x) + (this->y * this->y) + (this->z * this->z);
	}

	template<class T>
	inline Quaternion<T> Quaternion<T>::normalize() const noexcept
	{
		return this->operator/(this->norm());
	}

	template <class T>
	inline Quaternion<T> Quaternion<T>::inverse() const noexcept
	{
		return this->conjugate().normalize();
	}

	template <class T>
	inline T Quaternion<T>::dot(const Quaternion<T> & rightOperand) const noexcept
	{
		return (this->w * rightOperand.w) + (this->x * rightOperand.x) + (this->y * rightOperand.y) + (this->z * rightOperand.z);
	}

	template <class T>
	inline T Quaternion<T>::real() const noexcept { return this->w; }

	template <class T>
	inline T Quaternion<T>::angle() const noexcept { return 2 * std::arccos(this->w); }

	template <class T>
	inline Vertex3u<T> Quaternion<T>::axis() const noexcept
	{
		Vertex3u<T>(this->x / arcsin(this->angle() / 2,
					this->y / arcsin(this->angle() / 2,
					this->z / arcsin(this->angle() / 2);
	}

	template <class T>
	inline EulerAngle<T> Quaternion<T>::toEulerAngle() const noexcept
	{
		double sinr = 2.0 * (this->w * this->x + this->y * this->z);
		double cosr = 1.0 - 2.0 * (this->x * this->x + this->y * this->y);
		double sinp = 2.0 * (this->w * this->y - this->x * this->z);
		double pitch = std::fabs(sinp) >= 1.0 ? std::copysign(M_PI / 2, sinp) : std::asin(sinp);
		double siny = 2.0 * (this->w * this->z + this->x * this->y);
		double cosy = 1.0 - 2.0 * (this->y * this->y + this->z * this->z);

		return EulerAngle<T>(std::atan2(sinr, cosr), pitch, std::atan2(siny, cosy));
	}

	template <class T>
	inline Matrix4u<T> Quaternion<T>::toMatrix() const noexcept
	{
	}

	template <class T>
	inline T & Quaternion<T>::getW() noexcept { return this->w; }

	template <class T>
	inline T & Quaternion<T>::getX() noexcept { return this->x; }

	template <class T>
	inline T & Quaternion<T>::getY() noexcept { return this->y; }

	template <class T>
	inline T & Quaternion<T>::getZ() noexcept { return this->z; }

	template <class T>
	inline T Quaternion<T>::getW() const noexcept { return this->w; }

	template <class T>
	inline T Quaternion<T>::getX() const noexcept { return this->x; }

	template <class T>
	inline T Quaternion<T>::getY() const noexcept { return this->y; }

	template <class T>
	inline T Quaternion<T>::getZ() const noexcept { return this->z; }
}