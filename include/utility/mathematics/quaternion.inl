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

#include <cmath>

namespace ece
{
	template <class T>
	inline constexpr Quaternion<T>::Quaternion() noexcept: _w(1), _x(0), _y(0), _z(0) {}

	template <class T>
	inline Quaternion<T>::Quaternion(const T w, const T x, const T y, const T z) noexcept : _w(w), _x(x), _y(y), _z(z) {}

	template <class T>
	inline Quaternion<T>::Quaternion(const T angle, const Vector3u<T> & axis) noexcept :
		_w(std::cos(angle/2)),
		_x(axis[0]*std::sin(angle/2)),
		_y(axis[1] * std::sin(angle / 2)),
		_z(axis[2] * std::sin(angle / 2)) {}

	template <class T>
	Quaternion<T>::Quaternion(const EulerAngle<T> & eulerAngle): _w(0.0), _x(0.0), _y(0.0), _z(0.0)
	{
		double cy = cos(eulerAngle.getYaw() * 0.5);
		double sy = sin(eulerAngle.getYaw() * 0.5);
		double cr = cos(eulerAngle.getRoll() * 0.5);
		double sr = sin(eulerAngle.getRoll() * 0.5);
		double cp = cos(eulerAngle.getPitch() * 0.5);
		double sp = sin(eulerAngle.getPitch() * 0.5);

		this->_w = cy * cr * cp + sy * sr * sp;
		this->_x = cy * sr * cp - sy * cr * sp;
		this->_y = cy * cr * sp + sy * sr * cp;
		this->_z = sy * cr * cp - cy * sr * sp;
	}

	template <class T>
	inline Quaternion<T> Quaternion<T>::operator+(const Quaternion<T> & rightOperator) const noexcept
	{
		return Quaternion<T>(this->_w + rightOperator._w,
							 this->_x + rightOperator._x,
							 this->_y + rightOperator._y,
							 this->_z + rightOperator._z);
	}

	template <class T>
	inline Quaternion<T> Quaternion<T>::operator-(const Quaternion<T> & rightOperator) const noexcept
	{
		return Quaternion<T>(this->_w - rightOperator._w,
			this->_x - rightOperator._x,
			this->_y - rightOperator._y,
			this->_z - rightOperator._z);
	}

	template <class T>
	template <class U>
	inline Quaternion<T> Quaternion<T>::operator*(const U rightOperator) const noexcept
	{
		return Quaternion<T>(this->_w * rightOperator, this->_x * rightOperator, this->_y * rightOperator, this->_z * rightOperator);
	}

	template <class T>
	Quaternion<T> Quaternion<T>::operator*(const Quaternion<T> & rightOperator) const
	{
		Vector3u<T> lh(this->_x, this->_y, this->_z);
		Vector3u<T> rh(rightOperator._x, rightOperator._y, rightOperator._z);
		auto product = (rh * this->_w) + (lh * rightOperator._w) + (lh * rh);
		return Quaternion<T>((this->_w * rightOperator._w) + lh.dot(rh), product._x, product._y, product._z);
	}

	template <class T>
	template <class U>
	inline Quaternion<T> Quaternion<T>::operator/(const U rightOperator) const noexcept
	{
		return Quaternion<T>(this->_w / rightOperator, this->_x / rightOperator, this->_y / rightOperator, this->_z / rightOperator);
	}

	template <class T>
	Quaternion<T> & Quaternion<T>::operator+=(const Quaternion<T> & rightOperator) noexcept
	{
		this->_w += rightOperator._w;
		this->_x += rightOperator._x;
		this->_y += rightOperator._y;
		this->_z += rightOperator._z;
		return *this;
	}

	template <class T>
	Quaternion<T> & Quaternion<T>::operator-=(const Quaternion<T> & rightOperator) noexcept
	{
		this->_w -= rightOperator._w;
		this->_x -= rightOperator._x;
		this->_y -= rightOperator._y;
		this->_z -= rightOperator._z;
		return *this;
	}

	template <class T>
	inline Quaternion<T> Quaternion<T>::conjugate() const noexcept
	{
		return Quaternion<T>(this->_w, -this->_x, -this->_y, -this->_z);
	}

	template <class T>
	inline T Quaternion<T>::norm() const noexcept
	{
		return (this->_w * this->_w) + (this->_x * this->_x) + (this->_y * this->_y) + (this->_z * this->_z);
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
		return (this->_w * rightOperand.w) + (this->_x * rightOperand.x) + (this->_y * rightOperand.y) + (this->_z * rightOperand.z);
	}

	template <class T>
	inline T Quaternion<T>::real() const noexcept { return this->_w; }

	template <class T>
	inline T Quaternion<T>::angle() const noexcept { return 2 * std::acos(this->_w); }

	template <class T>
	inline Vector3u<T> Quaternion<T>::axis() const noexcept
	{
		Vector3u<T>{ this->_x / std::asin(this->angle() / 2),
					this->_y / std::asin(this->angle() / 2),
					this->_z / std::asin(this->angle() / 2) };
	}

	template <class T>
	inline EulerAngle<T> Quaternion<T>::toEulerAngle() const noexcept
	{
		double sinr = 2.0 * (this->_w * this->_x + this->_y * this->_z);
		double cosr = 1.0 - 2.0 * (this->_x * this->_x + this->_y * this->_y);
		double sinp = 2.0 * (this->_w * this->_y - this->_x * this->_z);
		double pitch = std::fabs(sinp) >= 1.0 ? std::copysign(M_PI / 2, sinp) : std::asin(sinp);
		double siny = 2.0 * (this->_w * this->_z + this->_x * this->_y);
		double cosy = 1.0 - 2.0 * (this->_y * this->_y + this->_z * this->_z);

		return EulerAngle<T>(std::atan2(sinr, cosr), pitch, std::atan2(siny, cosy));
	}

	template <class T>
	inline Matrix4u<T> Quaternion<T>::toMatrix() const noexcept
	{
	}
}
