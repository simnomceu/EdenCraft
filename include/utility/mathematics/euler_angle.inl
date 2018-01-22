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
	template <class T>
	inline constexpr EulerAngle<T>::EulerAngle() noexcept: _roll(0.0), _pitch(0.0), _yaw(0.0) {}

	template <class T>
	inline EulerAngle<T>::EulerAngle(const double roll, const double pitch, const double yaw) noexcept: _roll(roll), _pitch(pitch), _yaw(yaw) {}

	template <class T>
	EulerAngle<T>::EulerAngle(const Quaternion<T> & quaternion): _roll(0.0), _pitch(0.0), _yaw(0.0)
	{
		double sinr = 2.0 * (quaternion.getW() * quaternion.getX() + quaternion.getY() * quaternion.getZ());
		double cosr = 1.0 - 2.0 * (quaternion.getX() * quaternion.getX() + quaternion.getY() * quaternion.getY());
		double sinp = 2.0 * (quaternion.getW() * quaternion.getY() - quaternion.getX() * quaternion.getZ());
		double siny = 2.0 * (quaternion.getW() * quaternion.getZ() + quaternion.getX() * quaternion.getY());
		double cosy = 1.0 - 2.0 * (quaternion.getY() * quaternion.getY() + quaternion.getZ() * quaternion.getZ());

		this->_roll = std::atan2(sinr, cosr);
		this->_pitch = std::fabs(sinp) >= 1.0 ? std::copysign(M_PI / 2, sinp) : std::asin(sinp);
		this->_yaw = std::atan2(siny, cosy);
	}

	template <class T>
	Quaternion<T> EulerAngle<T>::toQuaternion() const
	{
		double cy = cos(this->_yaw * 0.5);
		double sy = sin(this->_yaw * 0.5);
		double cr = cos(this->_roll * 0.5);
		double sr = sin(this->_roll * 0.5);
		double cp = cos(this->_pitch * 0.5);
		double sp = sin(this->_pitch * 0.5);

		return Quaternion<T>(cy * cr * cp + sy * sr * sp,
			cy * sr * cp - sy * cr * sp,
			cy * cr * sp + sy * sr * cp,
			sy * cr * cp - cy * sr * sp);
	}

	template <class T>
	Matrix4u<T> EulerAngle<T>::toMatrix() const
	{
	}

	template <class T>
	inline T & EulerAngle<T>::getRoll() noexcept { return this->_roll; }

	template <class T>
	inline T & EulerAngle<T>::getPitch() noexcept { return this->_pitch; }

	template <class T>
	inline T & EulerAngle<T>::getYaw() noexcept { return this->_yaw; }

	template <class T>
	inline T EulerAngle<T>::getRoll() const noexcept { return this->_roll; }

	template <class T>
	inline T EulerAngle<T>::getPitch() const noexcept { return this->_pitch; }

	template <class T>
	inline T EulerAngle<T>::getYaw() const noexcept { return this->_yaw; }
}