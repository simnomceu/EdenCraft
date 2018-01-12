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
 * @file utility/mathematics/matrix3u.inl
 * @author IsiliBN (casa2pir@hotmail.fr)
 * @date January, 8th 2017
 * @copyright ----------
 * @brief A 3x3 specialization of Matrix.
 **/


#include "utility/debug/exception.hpp"

namespace ece
{
	template<>
	inline int Matrix3u<int>::determinant() const
	{
		return (*this)[0][0] * (*this)[1][1] * (*this)[2][2]
			 + (*this)[0][1] * (*this)[1][2] * (*this)[2][0]
			 + (*this)[0][2] * (*this)[1][0] * (*this)[2][1]
			 - (*this)[0][2] * (*this)[1][1] * (*this)[2][0]
			 - (*this)[0][1] * (*this)[1][0] * (*this)[2][2]
			 - (*this)[0][0] * (*this)[1][2] * (*this)[2][1];
	}

	template<>
	inline unsigned int Matrix3u<unsigned int>::determinant() const
	{
		return (*this)[0][0] * (*this)[1][1] * (*this)[2][2]
			+ (*this)[0][1] * (*this)[1][2] * (*this)[2][0]
			+ (*this)[0][2] * (*this)[1][0] * (*this)[2][1]
			- (*this)[0][2] * (*this)[1][1] * (*this)[2][0]
			- (*this)[0][1] * (*this)[1][0] * (*this)[2][2]
			- (*this)[0][0] * (*this)[1][2] * (*this)[2][1];
	}

	template<>
	inline float Matrix3u<float>::determinant() const
	{
		return (*this)[0][0] * (*this)[1][1] * (*this)[2][2]
			+ (*this)[0][1] * (*this)[1][2] * (*this)[2][0]
			+ (*this)[0][2] * (*this)[1][0] * (*this)[2][1]
			- (*this)[0][2] * (*this)[1][1] * (*this)[2][0]
			- (*this)[0][1] * (*this)[1][0] * (*this)[2][2]
			- (*this)[0][0] * (*this)[1][2] * (*this)[2][1];
	}

	template<>
	inline double Matrix3u<double>::determinant() const
	{
		return (*this)[0][0] * (*this)[1][1] * (*this)[2][2]
			+ (*this)[0][1] * (*this)[1][2] * (*this)[2][0]
			+ (*this)[0][2] * (*this)[1][0] * (*this)[2][1]
			- (*this)[0][2] * (*this)[1][1] * (*this)[2][0]
			- (*this)[0][1] * (*this)[1][0] * (*this)[2][2]
			- (*this)[0][0] * (*this)[1][2] * (*this)[2][1];
	}

	template<>
	inline Matrix3u<int> Matrix3u<int>::transpose() const
	{
		return Matrix3u<int>{ (*this)[0][0], (*this)[1][0], (*this)[2][0],
							  (*this)[0][1], (*this)[1][1], (*this)[2][1],
							  (*this)[0][2], (*this)[1][2], (*this)[2][2] };
	}

	template<>
	inline Matrix3u<unsigned int> Matrix3u<unsigned int>::transpose() const
	{
		return Matrix3u<unsigned int>{ (*this)[0][0], (*this)[1][0], (*this)[2][0],
									   (*this)[0][1], (*this)[1][1], (*this)[2][1],
									   (*this)[0][2], (*this)[1][2], (*this)[2][2] };
	}

	template<>
	inline Matrix3u<float> Matrix3u<float>::transpose() const
	{
		return Matrix3u<float>{ (*this)[0][0], (*this)[1][0], (*this)[2][0],
								(*this)[0][1], (*this)[1][1], (*this)[2][1],
								(*this)[0][2], (*this)[1][2], (*this)[2][2] };
	}

	template<>
	inline Matrix3u<double> Matrix3u<double>::transpose() const
	{
		return Matrix3u<double>{ (*this)[0][0], (*this)[1][0], (*this)[2][0],
								 (*this)[0][1], (*this)[1][1], (*this)[2][1],
								 (*this)[0][2], (*this)[1][2], (*this)[2][2] };
	}

	template<>
	inline Matrix3u<double> Matrix3u<int>::inverse(bool & invertible) const
	{
		auto det = this->determinant();
		invertible = (det != 0);
		if (invertible) {
			double a11 = (*this)[1][1] * (*this)[2][2] - (*this)[1][2] * (*this)[2][1];
			double a12 = (*this)[0][2] * (*this)[2][1] - (*this)[0][1] * (*this)[2][2];
			double a13 = (*this)[0][1] * (*this)[1][2] - (*this)[0][2] * (*this)[1][1];
			double a21 = (*this)[1][2] * (*this)[2][0] - (*this)[1][0] * (*this)[2][2];
			double a22 = (*this)[0][0] * (*this)[2][2] - (*this)[0][2] * (*this)[2][0];
			double a23 = (*this)[0][2] * (*this)[1][0] - (*this)[0][0] * (*this)[1][2];
			double a31 = (*this)[1][0] * (*this)[2][1] - (*this)[1][1] * (*this)[2][0];
			double a32 = (*this)[0][1] * (*this)[2][0] - (*this)[0][0] * (*this)[2][1];
			double a33 = (*this)[0][0] * (*this)[1][1] - (*this)[0][1] * (*this)[1][0];

			return Matrix3u<double>{ a11, a12, a13,
									a21, a22, a23,
									a31, a32, a33 } *(1.0f / det);
		}
		else {
			return Matrix3u<double>();
		}
	}

	template<>
	inline Matrix3u<double> Matrix3u<unsigned int>::inverse(bool & invertible) const
	{
		auto det = this->determinant();
		invertible = (det != 0);
		if (invertible) {
			double a11 = (*this)[1][1] * (*this)[2][2] - (*this)[1][2] * (*this)[2][1];
			double a12 = (*this)[0][2] * (*this)[2][1] - (*this)[0][1] * (*this)[2][2];
			double a13 = (*this)[0][1] * (*this)[1][2] - (*this)[0][2] * (*this)[1][1];
			double a21 = (*this)[1][2] * (*this)[2][0] - (*this)[1][0] * (*this)[2][2];
			double a22 = (*this)[0][0] * (*this)[2][2] - (*this)[0][2] * (*this)[2][0];
			double a23 = (*this)[0][2] * (*this)[1][0] - (*this)[0][0] * (*this)[1][2];
			double a31 = (*this)[1][0] * (*this)[2][1] - (*this)[1][1] * (*this)[2][0];
			double a32 = (*this)[0][1] * (*this)[2][0] - (*this)[0][0] * (*this)[2][1];
			double a33 = (*this)[0][0] * (*this)[1][1] - (*this)[0][1] * (*this)[1][0];

			return Matrix3u<double>{ a11, a12, a13,
									a21, a22, a23,
									a31, a32, a33 } *(1.0f / det);
		}
		else {
			return Matrix3u<double>();
		}
	}

	template<>
	inline Matrix3u<double> Matrix3u<float>::inverse(bool & invertible) const
	{
		auto det = this->determinant();
		invertible = (det != 0);
		if (invertible) {
			double a11 = (*this)[1][1] * (*this)[2][2] - (*this)[1][2] * (*this)[2][1];
			double a12 = (*this)[0][2] * (*this)[2][1] - (*this)[0][1] * (*this)[2][2];
			double a13 = (*this)[0][1] * (*this)[1][2] - (*this)[0][2] * (*this)[1][1];
			double a21 = (*this)[1][2] * (*this)[2][0] - (*this)[1][0] * (*this)[2][2];
			double a22 = (*this)[0][0] * (*this)[2][2] - (*this)[0][2] * (*this)[2][0];
			double a23 = (*this)[0][2] * (*this)[1][0] - (*this)[0][0] * (*this)[1][2];
			double a31 = (*this)[1][0] * (*this)[2][1] - (*this)[1][1] * (*this)[2][0];
			double a32 = (*this)[0][1] * (*this)[2][0] - (*this)[0][0] * (*this)[2][1];
			double a33 = (*this)[0][0] * (*this)[1][1] - (*this)[0][1] * (*this)[1][0];

			return Matrix3u<double>{ a11, a12, a13,
									a21, a22, a23,
									a31, a32, a33 } *(1.0f / det);
		}
		else {
			return Matrix3u<double>();
		}
	}

	template<>
	inline Matrix3u<double> Matrix3u<double>::inverse(bool & invertible) const
	{
		auto det = this->determinant();
		invertible = (det != 0);
		if (invertible) {
			double a11 = (*this)[1][1] * (*this)[2][2] - (*this)[1][2] * (*this)[2][1];
			double a12 = (*this)[0][2] * (*this)[2][1] - (*this)[0][1] * (*this)[2][2];
			double a13 = (*this)[0][1] * (*this)[1][2] - (*this)[0][2] * (*this)[1][1];
			double a21 = (*this)[1][2] * (*this)[2][0] - (*this)[1][0] * (*this)[2][2];
			double a22 = (*this)[0][0] * (*this)[2][2] - (*this)[0][2] * (*this)[2][0];
			double a23 = (*this)[0][2] * (*this)[1][0] - (*this)[0][0] * (*this)[1][2];
			double a31 = (*this)[1][0] * (*this)[2][1] - (*this)[1][1] * (*this)[2][0];
			double a32 = (*this)[0][1] * (*this)[2][0] - (*this)[0][0] * (*this)[2][1];
			double a33 = (*this)[0][0] * (*this)[1][1] - (*this)[0][1] * (*this)[1][0];

			return Matrix3u<double>{ a11, a12, a13,
									a21, a22, a23,
									a31, a32, a33 } *(1.0f / det);
		}
		else {
			return Matrix3u<double>();
		}
	}
}