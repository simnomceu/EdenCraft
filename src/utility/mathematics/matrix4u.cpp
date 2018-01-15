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
 * @file utility/mathematics/matrix4u.cpp
 * @author IsiliBN (casa2pir@hotmail.fr)
 * @date January, 8th 2017
 * @copyright ----------
 * @brief A 4x4 specialization of Matrix.
 **/

#include "utility/mathematics/matrix4u.hpp"

#include "utility/debug/exception.hpp"

namespace ece
{
	template<>
	inline int Matrix4u<int>::determinant() const
	{
		int a11 = (*this)[0][3] * (*this)[1][2] * (*this)[2][1] * (*this)[3][0];
		int a12 = (*this)[0][2] * (*this)[1][3] * (*this)[2][1] * (*this)[3][0];
		int a13 = (*this)[0][3] * (*this)[1][1] * (*this)[2][2] * (*this)[3][0];
		int a14 = (*this)[0][1] * (*this)[1][3] * (*this)[2][2] * (*this)[3][0];
		int a21 = (*this)[0][2] * (*this)[1][1] * (*this)[2][3] * (*this)[3][0];
		int a22 = (*this)[0][1] * (*this)[1][2] * (*this)[2][3] * (*this)[3][0];
		int a23 = (*this)[0][3] * (*this)[1][2] * (*this)[2][0] * (*this)[3][1];
		int a24 = (*this)[0][2] * (*this)[1][3] * (*this)[2][0] * (*this)[3][1];
		int a31 = (*this)[0][3] * (*this)[1][0] * (*this)[2][2] * (*this)[3][1];
		int a32 = (*this)[0][0] * (*this)[1][3] * (*this)[2][2] * (*this)[3][1];
		int a33 = (*this)[0][2] * (*this)[1][0] * (*this)[2][3] * (*this)[3][1];
		int a34 = (*this)[0][0] * (*this)[1][2] * (*this)[2][3] * (*this)[3][1];
		int a41 = (*this)[0][3] * (*this)[1][1] * (*this)[2][0] * (*this)[3][2];
		int a42 = (*this)[0][1] * (*this)[1][3] * (*this)[2][0] * (*this)[3][2];
		int a43 = (*this)[0][3] * (*this)[1][0] * (*this)[2][1] * (*this)[3][2];
		int a44 = (*this)[0][0] * (*this)[1][3] * (*this)[2][1] * (*this)[3][2];
		int a51 = (*this)[0][1] * (*this)[1][0] * (*this)[2][3] * (*this)[3][2];
		int a52 = (*this)[0][0] * (*this)[1][1] * (*this)[2][3] * (*this)[3][2];
		int a53 = (*this)[0][2] * (*this)[1][1] * (*this)[2][0] * (*this)[3][3];
		int a54 = (*this)[0][1] * (*this)[1][2] * (*this)[2][0] * (*this)[3][3];
		int a61 = (*this)[0][2] * (*this)[1][0] * (*this)[2][1] * (*this)[3][3];
		int a62 = (*this)[0][0] * (*this)[1][2] * (*this)[2][1] * (*this)[3][3];
		int a63 = (*this)[0][1] * (*this)[1][0] * (*this)[2][2] * (*this)[3][3];
		int a64 = (*this)[0][0] * (*this)[1][1] * (*this)[2][2] * (*this)[3][3];
		return  a11 - a12 - a13 + a14 +
				a21 - a22 - a23 + a24 +
				a31 - a32 - a33 + a34 +
				a41 - a42 - a43 + a44 +
				a51 - a52 - a53 + a54 +
				a61 - a62 - a63 + a64;
	}

	template<>
	inline unsigned int Matrix4u<unsigned int>::determinant() const
	{
		unsigned int a11 = (*this)[0][3] * (*this)[1][2] * (*this)[2][1] * (*this)[3][0];
		unsigned int a12 = (*this)[0][2] * (*this)[1][3] * (*this)[2][1] * (*this)[3][0];
		unsigned int a13 = (*this)[0][3] * (*this)[1][1] * (*this)[2][2] * (*this)[3][0];
		unsigned int a14 = (*this)[0][1] * (*this)[1][3] * (*this)[2][2] * (*this)[3][0];
		unsigned int a21 = (*this)[0][2] * (*this)[1][1] * (*this)[2][3] * (*this)[3][0];
		unsigned int a22 = (*this)[0][1] * (*this)[1][2] * (*this)[2][3] * (*this)[3][0];
		unsigned int a23 = (*this)[0][3] * (*this)[1][2] * (*this)[2][0] * (*this)[3][1];
		unsigned int a24 = (*this)[0][2] * (*this)[1][3] * (*this)[2][0] * (*this)[3][1];
		unsigned int a31 = (*this)[0][3] * (*this)[1][0] * (*this)[2][2] * (*this)[3][1];
		unsigned int a32 = (*this)[0][0] * (*this)[1][3] * (*this)[2][2] * (*this)[3][1];
		unsigned int a33 = (*this)[0][2] * (*this)[1][0] * (*this)[2][3] * (*this)[3][1];
		unsigned int a34 = (*this)[0][0] * (*this)[1][2] * (*this)[2][3] * (*this)[3][1];
		unsigned int a41 = (*this)[0][3] * (*this)[1][1] * (*this)[2][0] * (*this)[3][2];
		unsigned int a42 = (*this)[0][1] * (*this)[1][3] * (*this)[2][0] * (*this)[3][2];
		unsigned int a43 = (*this)[0][3] * (*this)[1][0] * (*this)[2][1] * (*this)[3][2];
		unsigned int a44 = (*this)[0][0] * (*this)[1][3] * (*this)[2][1] * (*this)[3][2];
		unsigned int a51 = (*this)[0][1] * (*this)[1][0] * (*this)[2][3] * (*this)[3][2];
		unsigned int a52 = (*this)[0][0] * (*this)[1][1] * (*this)[2][3] * (*this)[3][2];
		unsigned int a53 = (*this)[0][2] * (*this)[1][1] * (*this)[2][0] * (*this)[3][3];
		unsigned int a54 = (*this)[0][1] * (*this)[1][2] * (*this)[2][0] * (*this)[3][3];
		unsigned int a61 = (*this)[0][2] * (*this)[1][0] * (*this)[2][1] * (*this)[3][3];
		unsigned int a62 = (*this)[0][0] * (*this)[1][2] * (*this)[2][1] * (*this)[3][3];
		unsigned int a63 = (*this)[0][1] * (*this)[1][0] * (*this)[2][2] * (*this)[3][3];
		unsigned int a64 = (*this)[0][0] * (*this)[1][1] * (*this)[2][2] * (*this)[3][3];
		return  a11 - a12 - a13 + a14 +
			a21 - a22 - a23 + a24 +
			a31 - a32 - a33 + a34 +
			a41 - a42 - a43 + a44 +
			a51 - a52 - a53 + a54 +
			a61 - a62 - a63 + a64;
	}

	template<>
	inline float Matrix4u<float>::determinant() const
	{
		float a11 = (*this)[0][3] * (*this)[1][2] * (*this)[2][1] * (*this)[3][0];
		float a12 = (*this)[0][2] * (*this)[1][3] * (*this)[2][1] * (*this)[3][0];
		float a13 = (*this)[0][3] * (*this)[1][1] * (*this)[2][2] * (*this)[3][0];
		float a14 = (*this)[0][1] * (*this)[1][3] * (*this)[2][2] * (*this)[3][0];
		float a21 = (*this)[0][2] * (*this)[1][1] * (*this)[2][3] * (*this)[3][0];
		float a22 = (*this)[0][1] * (*this)[1][2] * (*this)[2][3] * (*this)[3][0];
		float a23 = (*this)[0][3] * (*this)[1][2] * (*this)[2][0] * (*this)[3][1];
		float a24 = (*this)[0][2] * (*this)[1][3] * (*this)[2][0] * (*this)[3][1];
		float a31 = (*this)[0][3] * (*this)[1][0] * (*this)[2][2] * (*this)[3][1];
		float a32 = (*this)[0][0] * (*this)[1][3] * (*this)[2][2] * (*this)[3][1];
		float a33 = (*this)[0][2] * (*this)[1][0] * (*this)[2][3] * (*this)[3][1];
		float a34 = (*this)[0][0] * (*this)[1][2] * (*this)[2][3] * (*this)[3][1];
		float a41 = (*this)[0][3] * (*this)[1][1] * (*this)[2][0] * (*this)[3][2];
		float a42 = (*this)[0][1] * (*this)[1][3] * (*this)[2][0] * (*this)[3][2];
		float a43 = (*this)[0][3] * (*this)[1][0] * (*this)[2][1] * (*this)[3][2];
		float a44 = (*this)[0][0] * (*this)[1][3] * (*this)[2][1] * (*this)[3][2];
		float a51 = (*this)[0][1] * (*this)[1][0] * (*this)[2][3] * (*this)[3][2];
		float a52 = (*this)[0][0] * (*this)[1][1] * (*this)[2][3] * (*this)[3][2];
		float a53 = (*this)[0][2] * (*this)[1][1] * (*this)[2][0] * (*this)[3][3];
		float a54 = (*this)[0][1] * (*this)[1][2] * (*this)[2][0] * (*this)[3][3];
		float a61 = (*this)[0][2] * (*this)[1][0] * (*this)[2][1] * (*this)[3][3];
		float a62 = (*this)[0][0] * (*this)[1][2] * (*this)[2][1] * (*this)[3][3];
		float a63 = (*this)[0][1] * (*this)[1][0] * (*this)[2][2] * (*this)[3][3];
		float a64 = (*this)[0][0] * (*this)[1][1] * (*this)[2][2] * (*this)[3][3];
		return  a11 - a12 - a13 + a14 +
			a21 - a22 - a23 + a24 +
			a31 - a32 - a33 + a34 +
			a41 - a42 - a43 + a44 +
			a51 - a52 - a53 + a54 +
			a61 - a62 - a63 + a64;
	}

	template<>
	inline double Matrix4u<double>::determinant() const
	{
		double a11 = (*this)[0][3] * (*this)[1][2] * (*this)[2][1] * (*this)[3][0];
		double a12 = (*this)[0][2] * (*this)[1][3] * (*this)[2][1] * (*this)[3][0];
		double a13 = (*this)[0][3] * (*this)[1][1] * (*this)[2][2] * (*this)[3][0];
		double a14 = (*this)[0][1] * (*this)[1][3] * (*this)[2][2] * (*this)[3][0];
		double a21 = (*this)[0][2] * (*this)[1][1] * (*this)[2][3] * (*this)[3][0];
		double a22 = (*this)[0][1] * (*this)[1][2] * (*this)[2][3] * (*this)[3][0];
		double a23 = (*this)[0][3] * (*this)[1][2] * (*this)[2][0] * (*this)[3][1];
		double a24 = (*this)[0][2] * (*this)[1][3] * (*this)[2][0] * (*this)[3][1];
		double a31 = (*this)[0][3] * (*this)[1][0] * (*this)[2][2] * (*this)[3][1];
		double a32 = (*this)[0][0] * (*this)[1][3] * (*this)[2][2] * (*this)[3][1];
		double a33 = (*this)[0][2] * (*this)[1][0] * (*this)[2][3] * (*this)[3][1];
		double a34 = (*this)[0][0] * (*this)[1][2] * (*this)[2][3] * (*this)[3][1];
		double a41 = (*this)[0][3] * (*this)[1][1] * (*this)[2][0] * (*this)[3][2];
		double a42 = (*this)[0][1] * (*this)[1][3] * (*this)[2][0] * (*this)[3][2];
		double a43 = (*this)[0][3] * (*this)[1][0] * (*this)[2][1] * (*this)[3][2];
		double a44 = (*this)[0][0] * (*this)[1][3] * (*this)[2][1] * (*this)[3][2];
		double a51 = (*this)[0][1] * (*this)[1][0] * (*this)[2][3] * (*this)[3][2];
		double a52 = (*this)[0][0] * (*this)[1][1] * (*this)[2][3] * (*this)[3][2];
		double a53 = (*this)[0][2] * (*this)[1][1] * (*this)[2][0] * (*this)[3][3];
		double a54 = (*this)[0][1] * (*this)[1][2] * (*this)[2][0] * (*this)[3][3];
		double a61 = (*this)[0][2] * (*this)[1][0] * (*this)[2][1] * (*this)[3][3];
		double a62 = (*this)[0][0] * (*this)[1][2] * (*this)[2][1] * (*this)[3][3];
		double a63 = (*this)[0][1] * (*this)[1][0] * (*this)[2][2] * (*this)[3][3];
		double a64 = (*this)[0][0] * (*this)[1][1] * (*this)[2][2] * (*this)[3][3];
		return  a11 - a12 - a13 + a14 +
			a21 - a22 - a23 + a24 +
			a31 - a32 - a33 + a34 +
			a41 - a42 - a43 + a44 +
			a51 - a52 - a53 + a54 +
			a61 - a62 - a63 + a64;
	}

	template<>
	inline Matrix4u<int> Matrix4u<int>::transpose() const
	{
		return Matrix4u<int>{ (*this)[0][0], (*this)[1][0], (*this)[2][0], (*this)[3][0],
							(*this)[0][1], (*this)[1][1], (*this)[2][1], (*this)[3][1],
							(*this)[0][2], (*this)[1][2], (*this)[2][2], (*this)[3][2],
							(*this)[0][3], (*this)[1][3], (*this)[2][3], (*this)[3][3] };
	}

	template<>
	inline Matrix4u<unsigned int> Matrix4u<unsigned int>::transpose() const
	{
		return Matrix4u<unsigned int>{ (*this)[0][0], (*this)[1][0], (*this)[2][0], (*this)[3][0],
			(*this)[0][1], (*this)[1][1], (*this)[2][1], (*this)[3][1],
			(*this)[0][2], (*this)[1][2], (*this)[2][2], (*this)[3][2],
			(*this)[0][3], (*this)[1][3], (*this)[2][3], (*this)[3][3] };
	}

	template<>
	inline Matrix4u<float> Matrix4u<float>::transpose() const
	{
		return Matrix4u<float>{ (*this)[0][0], (*this)[1][0], (*this)[2][0], (*this)[3][0],
								(*this)[0][1], (*this)[1][1], (*this)[2][1], (*this)[3][1],
								(*this)[0][2], (*this)[1][2], (*this)[2][2], (*this)[3][2],
								(*this)[0][3], (*this)[1][3], (*this)[2][3], (*this)[3][3] };
	}

	template<>
	inline Matrix4u<double> Matrix4u<double>::transpose() const
	{
		return Matrix4u<double>{ (*this)[0][0], (*this)[1][0], (*this)[2][0], (*this)[3][0],
								(*this)[0][1], (*this)[1][1], (*this)[2][1], (*this)[3][1],
								(*this)[0][2], (*this)[1][2], (*this)[2][2], (*this)[3][2],
								(*this)[0][3], (*this)[1][3], (*this)[2][3], (*this)[3][3] };
	}

	template<>
	inline Matrix4u<double> Matrix4u<int>::inverse(bool & invertible) const
	{
		auto det = this->determinant();
		invertible = (det != 0);
		if (invertible) {
			double a11 = (*this)[1][2] * (*this)[2][3] * (*this)[3][1] - (*this)[1][3] * (*this)[2][2] * (*this)[3][1] + (*this)[1][3] * (*this)[2][1] * (*this)[3][2] - (*this)[1][1] * (*this)[2][3] * (*this)[3][2] - (*this)[1][2] * (*this)[2][1] * (*this)[3][3] + (*this)[1][1] * (*this)[2][2] * (*this)[3][3];
			double a12 = (*this)[0][3] * (*this)[2][2] * (*this)[3][1] - (*this)[0][2] * (*this)[2][3] * (*this)[3][1] - (*this)[0][3] * (*this)[2][1] * (*this)[3][2] + (*this)[0][1] * (*this)[2][3] * (*this)[3][2] + (*this)[0][2] * (*this)[2][1] * (*this)[3][3] - (*this)[0][1] * (*this)[2][2] * (*this)[3][3];
			double a13 = (*this)[0][2] * (*this)[1][3] * (*this)[3][1] - (*this)[0][3] * (*this)[1][2] * (*this)[3][1] + (*this)[0][3] * (*this)[1][1] * (*this)[3][2] - (*this)[0][1] * (*this)[1][3] * (*this)[3][2] - (*this)[0][2] * (*this)[1][1] * (*this)[3][3] + (*this)[0][1] * (*this)[1][2] * (*this)[3][3];
			double a14 = (*this)[0][3] * (*this)[1][2] * (*this)[2][1] - (*this)[0][2] * (*this)[1][3] * (*this)[2][1] - (*this)[0][3] * (*this)[1][1] * (*this)[2][2] + (*this)[0][1] * (*this)[1][3] * (*this)[2][2] + (*this)[0][2] * (*this)[1][1] * (*this)[2][3] - (*this)[0][1] * (*this)[1][2] * (*this)[2][3];
			double a21 = (*this)[1][3] * (*this)[2][2] * (*this)[3][0] - (*this)[1][2] * (*this)[2][3] * (*this)[3][0] - (*this)[1][3] * (*this)[2][0] * (*this)[3][2] + (*this)[1][0] * (*this)[2][3] * (*this)[3][2] + (*this)[1][2] * (*this)[2][0] * (*this)[3][3] - (*this)[1][0] * (*this)[2][2] * (*this)[3][3];
			double a22 = (*this)[0][2] * (*this)[2][3] * (*this)[3][0] - (*this)[0][3] * (*this)[2][2] * (*this)[3][0] + (*this)[0][3] * (*this)[2][0] * (*this)[3][2] - (*this)[0][0] * (*this)[2][3] * (*this)[3][2] - (*this)[0][2] * (*this)[2][0] * (*this)[3][3] + (*this)[0][0] * (*this)[2][2] * (*this)[3][3];
			double a23 = (*this)[0][3] * (*this)[1][2] * (*this)[3][0] - (*this)[0][2] * (*this)[1][3] * (*this)[3][0] - (*this)[0][3] * (*this)[1][0] * (*this)[3][2] + (*this)[0][0] * (*this)[1][3] * (*this)[3][2] + (*this)[0][2] * (*this)[1][0] * (*this)[3][3] - (*this)[0][0] * (*this)[1][2] * (*this)[3][3];
			double a24 = (*this)[0][2] * (*this)[1][3] * (*this)[2][0] - (*this)[0][3] * (*this)[1][2] * (*this)[2][0] + (*this)[0][3] * (*this)[1][0] * (*this)[2][2] - (*this)[0][0] * (*this)[1][3] * (*this)[2][2] - (*this)[0][2] * (*this)[1][0] * (*this)[2][3] + (*this)[0][0] * (*this)[1][2] * (*this)[2][3];
			double a31 = (*this)[1][1] * (*this)[2][3] * (*this)[3][0] - (*this)[1][3] * (*this)[2][1] * (*this)[3][0] + (*this)[1][3] * (*this)[2][0] * (*this)[3][1] - (*this)[1][0] * (*this)[2][3] * (*this)[3][1] - (*this)[1][1] * (*this)[2][0] * (*this)[3][3] + (*this)[1][0] * (*this)[2][1] * (*this)[3][3];
			double a32 = (*this)[0][3] * (*this)[2][1] * (*this)[3][0] - (*this)[0][1] * (*this)[2][3] * (*this)[3][0] - (*this)[0][3] * (*this)[2][0] * (*this)[3][1] + (*this)[0][0] * (*this)[2][3] * (*this)[3][1] + (*this)[0][1] * (*this)[2][0] * (*this)[3][3] - (*this)[0][0] * (*this)[2][1] * (*this)[3][3];
			double a33 = (*this)[0][1] * (*this)[1][3] * (*this)[3][0] - (*this)[0][3] * (*this)[1][1] * (*this)[3][0] + (*this)[0][3] * (*this)[1][0] * (*this)[3][1] - (*this)[0][0] * (*this)[1][3] * (*this)[3][1] - (*this)[0][1] * (*this)[1][0] * (*this)[3][3] + (*this)[0][0] * (*this)[1][1] * (*this)[3][3];
			double a34 = (*this)[0][3] * (*this)[1][1] * (*this)[2][0] - (*this)[0][1] * (*this)[1][3] * (*this)[2][0] - (*this)[0][3] * (*this)[1][0] * (*this)[2][1] + (*this)[0][0] * (*this)[1][3] * (*this)[2][1] + (*this)[0][1] * (*this)[1][0] * (*this)[2][3] - (*this)[0][0] * (*this)[1][1] * (*this)[2][3];
			double a41 = (*this)[1][2] * (*this)[2][1] * (*this)[3][0] - (*this)[1][1] * (*this)[2][2] * (*this)[3][0] - (*this)[1][2] * (*this)[2][0] * (*this)[3][1] + (*this)[1][0] * (*this)[2][2] * (*this)[3][1] + (*this)[1][1] * (*this)[2][0] * (*this)[3][2] - (*this)[1][0] * (*this)[2][1] * (*this)[3][2];
			double a42 = (*this)[0][1] * (*this)[2][2] * (*this)[3][0] - (*this)[0][2] * (*this)[2][1] * (*this)[3][0] + (*this)[0][2] * (*this)[2][0] * (*this)[3][1] - (*this)[0][0] * (*this)[2][2] * (*this)[3][1] - (*this)[0][1] * (*this)[2][0] * (*this)[3][2] + (*this)[0][0] * (*this)[2][1] * (*this)[3][2];
			double a43 = (*this)[0][2] * (*this)[1][1] * (*this)[3][0] - (*this)[0][1] * (*this)[1][2] * (*this)[3][0] - (*this)[0][2] * (*this)[1][0] * (*this)[3][1] + (*this)[0][0] * (*this)[1][2] * (*this)[3][1] + (*this)[0][1] * (*this)[1][0] * (*this)[3][2] - (*this)[0][0] * (*this)[1][1] * (*this)[3][2];
			double a44 = (*this)[0][1] * (*this)[1][2] * (*this)[2][0] - (*this)[0][2] * (*this)[1][1] * (*this)[2][0] + (*this)[0][2] * (*this)[1][0] * (*this)[2][1] - (*this)[0][0] * (*this)[1][2] * (*this)[2][1] - (*this)[0][1] * (*this)[1][0] * (*this)[2][2] + (*this)[0][0] * (*this)[1][1] * (*this)[2][2];

			return Matrix4u<double>{ a11, a12, a13, a14,
									a21, a22, a23, a24,
									a31, a32, a33, a34,
									a41, a42, a43, a44 } *(1.0f / det);
		}
		else {
			return Matrix4u<double>();
		}
	}

	template<>
	inline Matrix4u<double> Matrix4u<unsigned int>::inverse(bool & invertible) const
	{
		auto det = this->determinant();
		invertible = (det != 0);
		if (invertible) {
			double a11 = (*this)[1][2] * (*this)[2][3] * (*this)[3][1] - (*this)[1][3] * (*this)[2][2] * (*this)[3][1] + (*this)[1][3] * (*this)[2][1] * (*this)[3][2] - (*this)[1][1] * (*this)[2][3] * (*this)[3][2] - (*this)[1][2] * (*this)[2][1] * (*this)[3][3] + (*this)[1][1] * (*this)[2][2] * (*this)[3][3];
			double a12 = (*this)[0][3] * (*this)[2][2] * (*this)[3][1] - (*this)[0][2] * (*this)[2][3] * (*this)[3][1] - (*this)[0][3] * (*this)[2][1] * (*this)[3][2] + (*this)[0][1] * (*this)[2][3] * (*this)[3][2] + (*this)[0][2] * (*this)[2][1] * (*this)[3][3] - (*this)[0][1] * (*this)[2][2] * (*this)[3][3];
			double a13 = (*this)[0][2] * (*this)[1][3] * (*this)[3][1] - (*this)[0][3] * (*this)[1][2] * (*this)[3][1] + (*this)[0][3] * (*this)[1][1] * (*this)[3][2] - (*this)[0][1] * (*this)[1][3] * (*this)[3][2] - (*this)[0][2] * (*this)[1][1] * (*this)[3][3] + (*this)[0][1] * (*this)[1][2] * (*this)[3][3];
			double a14 = (*this)[0][3] * (*this)[1][2] * (*this)[2][1] - (*this)[0][2] * (*this)[1][3] * (*this)[2][1] - (*this)[0][3] * (*this)[1][1] * (*this)[2][2] + (*this)[0][1] * (*this)[1][3] * (*this)[2][2] + (*this)[0][2] * (*this)[1][1] * (*this)[2][3] - (*this)[0][1] * (*this)[1][2] * (*this)[2][3];
			double a21 = (*this)[1][3] * (*this)[2][2] * (*this)[3][0] - (*this)[1][2] * (*this)[2][3] * (*this)[3][0] - (*this)[1][3] * (*this)[2][0] * (*this)[3][2] + (*this)[1][0] * (*this)[2][3] * (*this)[3][2] + (*this)[1][2] * (*this)[2][0] * (*this)[3][3] - (*this)[1][0] * (*this)[2][2] * (*this)[3][3];
			double a22 = (*this)[0][2] * (*this)[2][3] * (*this)[3][0] - (*this)[0][3] * (*this)[2][2] * (*this)[3][0] + (*this)[0][3] * (*this)[2][0] * (*this)[3][2] - (*this)[0][0] * (*this)[2][3] * (*this)[3][2] - (*this)[0][2] * (*this)[2][0] * (*this)[3][3] + (*this)[0][0] * (*this)[2][2] * (*this)[3][3];
			double a23 = (*this)[0][3] * (*this)[1][2] * (*this)[3][0] - (*this)[0][2] * (*this)[1][3] * (*this)[3][0] - (*this)[0][3] * (*this)[1][0] * (*this)[3][2] + (*this)[0][0] * (*this)[1][3] * (*this)[3][2] + (*this)[0][2] * (*this)[1][0] * (*this)[3][3] - (*this)[0][0] * (*this)[1][2] * (*this)[3][3];
			double a24 = (*this)[0][2] * (*this)[1][3] * (*this)[2][0] - (*this)[0][3] * (*this)[1][2] * (*this)[2][0] + (*this)[0][3] * (*this)[1][0] * (*this)[2][2] - (*this)[0][0] * (*this)[1][3] * (*this)[2][2] - (*this)[0][2] * (*this)[1][0] * (*this)[2][3] + (*this)[0][0] * (*this)[1][2] * (*this)[2][3];
			double a31 = (*this)[1][1] * (*this)[2][3] * (*this)[3][0] - (*this)[1][3] * (*this)[2][1] * (*this)[3][0] + (*this)[1][3] * (*this)[2][0] * (*this)[3][1] - (*this)[1][0] * (*this)[2][3] * (*this)[3][1] - (*this)[1][1] * (*this)[2][0] * (*this)[3][3] + (*this)[1][0] * (*this)[2][1] * (*this)[3][3];
			double a32 = (*this)[0][3] * (*this)[2][1] * (*this)[3][0] - (*this)[0][1] * (*this)[2][3] * (*this)[3][0] - (*this)[0][3] * (*this)[2][0] * (*this)[3][1] + (*this)[0][0] * (*this)[2][3] * (*this)[3][1] + (*this)[0][1] * (*this)[2][0] * (*this)[3][3] - (*this)[0][0] * (*this)[2][1] * (*this)[3][3];
			double a33 = (*this)[0][1] * (*this)[1][3] * (*this)[3][0] - (*this)[0][3] * (*this)[1][1] * (*this)[3][0] + (*this)[0][3] * (*this)[1][0] * (*this)[3][1] - (*this)[0][0] * (*this)[1][3] * (*this)[3][1] - (*this)[0][1] * (*this)[1][0] * (*this)[3][3] + (*this)[0][0] * (*this)[1][1] * (*this)[3][3];
			double a34 = (*this)[0][3] * (*this)[1][1] * (*this)[2][0] - (*this)[0][1] * (*this)[1][3] * (*this)[2][0] - (*this)[0][3] * (*this)[1][0] * (*this)[2][1] + (*this)[0][0] * (*this)[1][3] * (*this)[2][1] + (*this)[0][1] * (*this)[1][0] * (*this)[2][3] - (*this)[0][0] * (*this)[1][1] * (*this)[2][3];
			double a41 = (*this)[1][2] * (*this)[2][1] * (*this)[3][0] - (*this)[1][1] * (*this)[2][2] * (*this)[3][0] - (*this)[1][2] * (*this)[2][0] * (*this)[3][1] + (*this)[1][0] * (*this)[2][2] * (*this)[3][1] + (*this)[1][1] * (*this)[2][0] * (*this)[3][2] - (*this)[1][0] * (*this)[2][1] * (*this)[3][2];
			double a42 = (*this)[0][1] * (*this)[2][2] * (*this)[3][0] - (*this)[0][2] * (*this)[2][1] * (*this)[3][0] + (*this)[0][2] * (*this)[2][0] * (*this)[3][1] - (*this)[0][0] * (*this)[2][2] * (*this)[3][1] - (*this)[0][1] * (*this)[2][0] * (*this)[3][2] + (*this)[0][0] * (*this)[2][1] * (*this)[3][2];
			double a43 = (*this)[0][2] * (*this)[1][1] * (*this)[3][0] - (*this)[0][1] * (*this)[1][2] * (*this)[3][0] - (*this)[0][2] * (*this)[1][0] * (*this)[3][1] + (*this)[0][0] * (*this)[1][2] * (*this)[3][1] + (*this)[0][1] * (*this)[1][0] * (*this)[3][2] - (*this)[0][0] * (*this)[1][1] * (*this)[3][2];
			double a44 = (*this)[0][1] * (*this)[1][2] * (*this)[2][0] - (*this)[0][2] * (*this)[1][1] * (*this)[2][0] + (*this)[0][2] * (*this)[1][0] * (*this)[2][1] - (*this)[0][0] * (*this)[1][2] * (*this)[2][1] - (*this)[0][1] * (*this)[1][0] * (*this)[2][2] + (*this)[0][0] * (*this)[1][1] * (*this)[2][2];

			return Matrix4u<double>{ a11, a12, a13, a14,
				a21, a22, a23, a24,
				a31, a32, a33, a34,
				a41, a42, a43, a44 } *(1.0f / det);
		}
		else {
			return Matrix4u<double>();
		}
	}

	template<>
	inline Matrix4u<double> Matrix4u<float>::inverse(bool & invertible) const
	{
		auto det = this->determinant();
		invertible = (det != 0);
		if (invertible) {
			double a11 = (*this)[1][2] * (*this)[2][3] * (*this)[3][1] - (*this)[1][3] * (*this)[2][2] * (*this)[3][1] + (*this)[1][3] * (*this)[2][1] * (*this)[3][2] - (*this)[1][1] * (*this)[2][3] * (*this)[3][2] - (*this)[1][2] * (*this)[2][1] * (*this)[3][3] + (*this)[1][1] * (*this)[2][2] * (*this)[3][3];
			double a12 = (*this)[0][3] * (*this)[2][2] * (*this)[3][1] - (*this)[0][2] * (*this)[2][3] * (*this)[3][1] - (*this)[0][3] * (*this)[2][1] * (*this)[3][2] + (*this)[0][1] * (*this)[2][3] * (*this)[3][2] + (*this)[0][2] * (*this)[2][1] * (*this)[3][3] - (*this)[0][1] * (*this)[2][2] * (*this)[3][3];
			double a13 = (*this)[0][2] * (*this)[1][3] * (*this)[3][1] - (*this)[0][3] * (*this)[1][2] * (*this)[3][1] + (*this)[0][3] * (*this)[1][1] * (*this)[3][2] - (*this)[0][1] * (*this)[1][3] * (*this)[3][2] - (*this)[0][2] * (*this)[1][1] * (*this)[3][3] + (*this)[0][1] * (*this)[1][2] * (*this)[3][3];
			double a14 = (*this)[0][3] * (*this)[1][2] * (*this)[2][1] - (*this)[0][2] * (*this)[1][3] * (*this)[2][1] - (*this)[0][3] * (*this)[1][1] * (*this)[2][2] + (*this)[0][1] * (*this)[1][3] * (*this)[2][2] + (*this)[0][2] * (*this)[1][1] * (*this)[2][3] - (*this)[0][1] * (*this)[1][2] * (*this)[2][3];
			double a21 = (*this)[1][3] * (*this)[2][2] * (*this)[3][0] - (*this)[1][2] * (*this)[2][3] * (*this)[3][0] - (*this)[1][3] * (*this)[2][0] * (*this)[3][2] + (*this)[1][0] * (*this)[2][3] * (*this)[3][2] + (*this)[1][2] * (*this)[2][0] * (*this)[3][3] - (*this)[1][0] * (*this)[2][2] * (*this)[3][3];
			double a22 = (*this)[0][2] * (*this)[2][3] * (*this)[3][0] - (*this)[0][3] * (*this)[2][2] * (*this)[3][0] + (*this)[0][3] * (*this)[2][0] * (*this)[3][2] - (*this)[0][0] * (*this)[2][3] * (*this)[3][2] - (*this)[0][2] * (*this)[2][0] * (*this)[3][3] + (*this)[0][0] * (*this)[2][2] * (*this)[3][3];
			double a23 = (*this)[0][3] * (*this)[1][2] * (*this)[3][0] - (*this)[0][2] * (*this)[1][3] * (*this)[3][0] - (*this)[0][3] * (*this)[1][0] * (*this)[3][2] + (*this)[0][0] * (*this)[1][3] * (*this)[3][2] + (*this)[0][2] * (*this)[1][0] * (*this)[3][3] - (*this)[0][0] * (*this)[1][2] * (*this)[3][3];
			double a24 = (*this)[0][2] * (*this)[1][3] * (*this)[2][0] - (*this)[0][3] * (*this)[1][2] * (*this)[2][0] + (*this)[0][3] * (*this)[1][0] * (*this)[2][2] - (*this)[0][0] * (*this)[1][3] * (*this)[2][2] - (*this)[0][2] * (*this)[1][0] * (*this)[2][3] + (*this)[0][0] * (*this)[1][2] * (*this)[2][3];
			double a31 = (*this)[1][1] * (*this)[2][3] * (*this)[3][0] - (*this)[1][3] * (*this)[2][1] * (*this)[3][0] + (*this)[1][3] * (*this)[2][0] * (*this)[3][1] - (*this)[1][0] * (*this)[2][3] * (*this)[3][1] - (*this)[1][1] * (*this)[2][0] * (*this)[3][3] + (*this)[1][0] * (*this)[2][1] * (*this)[3][3];
			double a32 = (*this)[0][3] * (*this)[2][1] * (*this)[3][0] - (*this)[0][1] * (*this)[2][3] * (*this)[3][0] - (*this)[0][3] * (*this)[2][0] * (*this)[3][1] + (*this)[0][0] * (*this)[2][3] * (*this)[3][1] + (*this)[0][1] * (*this)[2][0] * (*this)[3][3] - (*this)[0][0] * (*this)[2][1] * (*this)[3][3];
			double a33 = (*this)[0][1] * (*this)[1][3] * (*this)[3][0] - (*this)[0][3] * (*this)[1][1] * (*this)[3][0] + (*this)[0][3] * (*this)[1][0] * (*this)[3][1] - (*this)[0][0] * (*this)[1][3] * (*this)[3][1] - (*this)[0][1] * (*this)[1][0] * (*this)[3][3] + (*this)[0][0] * (*this)[1][1] * (*this)[3][3];
			double a34 = (*this)[0][3] * (*this)[1][1] * (*this)[2][0] - (*this)[0][1] * (*this)[1][3] * (*this)[2][0] - (*this)[0][3] * (*this)[1][0] * (*this)[2][1] + (*this)[0][0] * (*this)[1][3] * (*this)[2][1] + (*this)[0][1] * (*this)[1][0] * (*this)[2][3] - (*this)[0][0] * (*this)[1][1] * (*this)[2][3];
			double a41 = (*this)[1][2] * (*this)[2][1] * (*this)[3][0] - (*this)[1][1] * (*this)[2][2] * (*this)[3][0] - (*this)[1][2] * (*this)[2][0] * (*this)[3][1] + (*this)[1][0] * (*this)[2][2] * (*this)[3][1] + (*this)[1][1] * (*this)[2][0] * (*this)[3][2] - (*this)[1][0] * (*this)[2][1] * (*this)[3][2];
			double a42 = (*this)[0][1] * (*this)[2][2] * (*this)[3][0] - (*this)[0][2] * (*this)[2][1] * (*this)[3][0] + (*this)[0][2] * (*this)[2][0] * (*this)[3][1] - (*this)[0][0] * (*this)[2][2] * (*this)[3][1] - (*this)[0][1] * (*this)[2][0] * (*this)[3][2] + (*this)[0][0] * (*this)[2][1] * (*this)[3][2];
			double a43 = (*this)[0][2] * (*this)[1][1] * (*this)[3][0] - (*this)[0][1] * (*this)[1][2] * (*this)[3][0] - (*this)[0][2] * (*this)[1][0] * (*this)[3][1] + (*this)[0][0] * (*this)[1][2] * (*this)[3][1] + (*this)[0][1] * (*this)[1][0] * (*this)[3][2] - (*this)[0][0] * (*this)[1][1] * (*this)[3][2];
			double a44 = (*this)[0][1] * (*this)[1][2] * (*this)[2][0] - (*this)[0][2] * (*this)[1][1] * (*this)[2][0] + (*this)[0][2] * (*this)[1][0] * (*this)[2][1] - (*this)[0][0] * (*this)[1][2] * (*this)[2][1] - (*this)[0][1] * (*this)[1][0] * (*this)[2][2] + (*this)[0][0] * (*this)[1][1] * (*this)[2][2];

			return Matrix4u<double>{ a11, a12, a13, a14,
				a21, a22, a23, a24,
				a31, a32, a33, a34,
				a41, a42, a43, a44 } *(1.0f / det);
		}
		else {
			return Matrix4u<double>();
		}
	}

	template<>
	inline Matrix4u<double> Matrix4u<double>::inverse(bool & invertible) const
	{
		auto det = this->determinant();
		invertible = (det != 0);
		if (invertible) {
			double a11 = (*this)[1][2] * (*this)[2][3] * (*this)[3][1] - (*this)[1][3] * (*this)[2][2] * (*this)[3][1] + (*this)[1][3] * (*this)[2][1] * (*this)[3][2] - (*this)[1][1] * (*this)[2][3] * (*this)[3][2] - (*this)[1][2] * (*this)[2][1] * (*this)[3][3] + (*this)[1][1] * (*this)[2][2] * (*this)[3][3];
			double a12 = (*this)[0][3] * (*this)[2][2] * (*this)[3][1] - (*this)[0][2] * (*this)[2][3] * (*this)[3][1] - (*this)[0][3] * (*this)[2][1] * (*this)[3][2] + (*this)[0][1] * (*this)[2][3] * (*this)[3][2] + (*this)[0][2] * (*this)[2][1] * (*this)[3][3] - (*this)[0][1] * (*this)[2][2] * (*this)[3][3];
			double a13 = (*this)[0][2] * (*this)[1][3] * (*this)[3][1] - (*this)[0][3] * (*this)[1][2] * (*this)[3][1] + (*this)[0][3] * (*this)[1][1] * (*this)[3][2] - (*this)[0][1] * (*this)[1][3] * (*this)[3][2] - (*this)[0][2] * (*this)[1][1] * (*this)[3][3] + (*this)[0][1] * (*this)[1][2] * (*this)[3][3];
			double a14 = (*this)[0][3] * (*this)[1][2] * (*this)[2][1] - (*this)[0][2] * (*this)[1][3] * (*this)[2][1] - (*this)[0][3] * (*this)[1][1] * (*this)[2][2] + (*this)[0][1] * (*this)[1][3] * (*this)[2][2] + (*this)[0][2] * (*this)[1][1] * (*this)[2][3] - (*this)[0][1] * (*this)[1][2] * (*this)[2][3];
			double a21 = (*this)[1][3] * (*this)[2][2] * (*this)[3][0] - (*this)[1][2] * (*this)[2][3] * (*this)[3][0] - (*this)[1][3] * (*this)[2][0] * (*this)[3][2] + (*this)[1][0] * (*this)[2][3] * (*this)[3][2] + (*this)[1][2] * (*this)[2][0] * (*this)[3][3] - (*this)[1][0] * (*this)[2][2] * (*this)[3][3];
			double a22 = (*this)[0][2] * (*this)[2][3] * (*this)[3][0] - (*this)[0][3] * (*this)[2][2] * (*this)[3][0] + (*this)[0][3] * (*this)[2][0] * (*this)[3][2] - (*this)[0][0] * (*this)[2][3] * (*this)[3][2] - (*this)[0][2] * (*this)[2][0] * (*this)[3][3] + (*this)[0][0] * (*this)[2][2] * (*this)[3][3];
			double a23 = (*this)[0][3] * (*this)[1][2] * (*this)[3][0] - (*this)[0][2] * (*this)[1][3] * (*this)[3][0] - (*this)[0][3] * (*this)[1][0] * (*this)[3][2] + (*this)[0][0] * (*this)[1][3] * (*this)[3][2] + (*this)[0][2] * (*this)[1][0] * (*this)[3][3] - (*this)[0][0] * (*this)[1][2] * (*this)[3][3];
			double a24 = (*this)[0][2] * (*this)[1][3] * (*this)[2][0] - (*this)[0][3] * (*this)[1][2] * (*this)[2][0] + (*this)[0][3] * (*this)[1][0] * (*this)[2][2] - (*this)[0][0] * (*this)[1][3] * (*this)[2][2] - (*this)[0][2] * (*this)[1][0] * (*this)[2][3] + (*this)[0][0] * (*this)[1][2] * (*this)[2][3];
			double a31 = (*this)[1][1] * (*this)[2][3] * (*this)[3][0] - (*this)[1][3] * (*this)[2][1] * (*this)[3][0] + (*this)[1][3] * (*this)[2][0] * (*this)[3][1] - (*this)[1][0] * (*this)[2][3] * (*this)[3][1] - (*this)[1][1] * (*this)[2][0] * (*this)[3][3] + (*this)[1][0] * (*this)[2][1] * (*this)[3][3];
			double a32 = (*this)[0][3] * (*this)[2][1] * (*this)[3][0] - (*this)[0][1] * (*this)[2][3] * (*this)[3][0] - (*this)[0][3] * (*this)[2][0] * (*this)[3][1] + (*this)[0][0] * (*this)[2][3] * (*this)[3][1] + (*this)[0][1] * (*this)[2][0] * (*this)[3][3] - (*this)[0][0] * (*this)[2][1] * (*this)[3][3];
			double a33 = (*this)[0][1] * (*this)[1][3] * (*this)[3][0] - (*this)[0][3] * (*this)[1][1] * (*this)[3][0] + (*this)[0][3] * (*this)[1][0] * (*this)[3][1] - (*this)[0][0] * (*this)[1][3] * (*this)[3][1] - (*this)[0][1] * (*this)[1][0] * (*this)[3][3] + (*this)[0][0] * (*this)[1][1] * (*this)[3][3];
			double a34 = (*this)[0][3] * (*this)[1][1] * (*this)[2][0] - (*this)[0][1] * (*this)[1][3] * (*this)[2][0] - (*this)[0][3] * (*this)[1][0] * (*this)[2][1] + (*this)[0][0] * (*this)[1][3] * (*this)[2][1] + (*this)[0][1] * (*this)[1][0] * (*this)[2][3] - (*this)[0][0] * (*this)[1][1] * (*this)[2][3];
			double a41 = (*this)[1][2] * (*this)[2][1] * (*this)[3][0] - (*this)[1][1] * (*this)[2][2] * (*this)[3][0] - (*this)[1][2] * (*this)[2][0] * (*this)[3][1] + (*this)[1][0] * (*this)[2][2] * (*this)[3][1] + (*this)[1][1] * (*this)[2][0] * (*this)[3][2] - (*this)[1][0] * (*this)[2][1] * (*this)[3][2];
			double a42 = (*this)[0][1] * (*this)[2][2] * (*this)[3][0] - (*this)[0][2] * (*this)[2][1] * (*this)[3][0] + (*this)[0][2] * (*this)[2][0] * (*this)[3][1] - (*this)[0][0] * (*this)[2][2] * (*this)[3][1] - (*this)[0][1] * (*this)[2][0] * (*this)[3][2] + (*this)[0][0] * (*this)[2][1] * (*this)[3][2];
			double a43 = (*this)[0][2] * (*this)[1][1] * (*this)[3][0] - (*this)[0][1] * (*this)[1][2] * (*this)[3][0] - (*this)[0][2] * (*this)[1][0] * (*this)[3][1] + (*this)[0][0] * (*this)[1][2] * (*this)[3][1] + (*this)[0][1] * (*this)[1][0] * (*this)[3][2] - (*this)[0][0] * (*this)[1][1] * (*this)[3][2];
			double a44 = (*this)[0][1] * (*this)[1][2] * (*this)[2][0] - (*this)[0][2] * (*this)[1][1] * (*this)[2][0] + (*this)[0][2] * (*this)[1][0] * (*this)[2][1] - (*this)[0][0] * (*this)[1][2] * (*this)[2][1] - (*this)[0][1] * (*this)[1][0] * (*this)[2][2] + (*this)[0][0] * (*this)[1][1] * (*this)[2][2];

			return Matrix4u<double>{ a11, a12, a13, a14,
				a21, a22, a23, a24,
				a31, a32, a33, a34,
				a41, a42, a43, a44 } *(1.0f / det);
		}
		else {
			return Matrix4u<double>();
		}
	}
}