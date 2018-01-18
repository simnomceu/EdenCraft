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

#include "utility/mathematics/matrix2u.hpp"

namespace ece
{
	template <>
	inline int Matrix2u<int>::determinant() const
	{
		return (*this)[0][0] * (*this)[1][1] - (*this)[0][1] * (*this)[1][0];
	}

	template <>
	inline unsigned int Matrix2u<unsigned int>::determinant() const
	{
		return (*this)[0][0] * (*this)[1][1] - (*this)[0][1] * (*this)[1][0];
	}

	template <>
	inline float Matrix2u<float>::determinant() const
	{
		return (*this)[0][0] * (*this)[1][1] - (*this)[0][1] * (*this)[1][0];
	}

	template <>
	inline double Matrix2u<double>::determinant() const
	{
		return (*this)[0][0] * (*this)[1][1] - (*this)[0][1] * (*this)[1][0];
	}

	template<>
	inline Matrix2u<int> Matrix2u<int>::transpose() const
	{
		return Matrix2u<int>{ (*this)[0][0], (*this)[1][0], (*this)[0][1], (*this)[1][1] };
	}

	template<>
	inline Matrix2u<unsigned int> Matrix2u<unsigned int>::transpose() const
	{
		return Matrix2u<unsigned int>{ (*this)[0][0], (*this)[1][0], (*this)[0][1], (*this)[1][1] };
	}

	template<>
	inline Matrix2u<float> Matrix2u<float>::transpose() const
	{
		return Matrix2u<float>{ (*this)[0][0], (*this)[1][0], (*this)[0][1], (*this)[1][1] };
	}

	template<>
	inline Matrix2u<double> Matrix2u<double>::transpose() const
	{
		return Matrix2u<double>{ (*this)[0][0], (*this)[1][0], (*this)[0][1], (*this)[1][1] };
	}

	template<>
	inline Matrix2u<double> Matrix2u<int>::inverse(bool & invertible) const
	{
		auto det = this->determinant();
		invertible = (det != 0);
		if (invertible) {
			return Matrix2u<double>{ static_cast<double>((*this)[1][1]), -static_cast<double>((*this)[0][1]),
				-static_cast<double>((*this)[1][0]), static_cast<double>((*this)[0][0]) } *(1.0f / det);
		}
		else {
			return Matrix2u<double>();
		}
	}

	template<>
	inline Matrix2u<double> Matrix2u<unsigned int>::inverse(bool & invertible) const
	{
		auto det = this->determinant();
		invertible = (det != 0);
		if (invertible) {
			return Matrix2u<double>{ static_cast<double>((*this)[1][1]), -static_cast<double>((*this)[0][1]),
				-static_cast<double>((*this)[1][0]), static_cast<double>((*this)[0][0]) } *(1.0f / det);
		}
		else {
			return Matrix2u<double>();
		}
	}

	template<>
	inline Matrix2u<double> Matrix2u<float>::inverse(bool & invertible) const
	{
		auto det = this->determinant();
		invertible = (det != 0);
		if (invertible) {
			return Matrix2u<double>{ (*this)[1][1], -(*this)[0][1], -(*this)[1][0], (*this)[0][0] } *(1.0f / det);
		}
		else {
			return Matrix2u<double>();
		}
	}

	template<>
	inline Matrix2u<double> Matrix2u<double>::inverse(bool & invertible) const
	{
		auto det = this->determinant();
		invertible = (det != 0);
		if (invertible) {
			return Matrix2u<double>{ (*this)[1][1], -(*this)[0][1], -(*this)[1][0], (*this)[0][0] } *(1.0f / det);
		}
		else {
			return Matrix2u<double>();
		}
	}
}