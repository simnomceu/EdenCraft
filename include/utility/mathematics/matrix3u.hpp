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

#ifndef MATRIX3U_HPP
#define MATRIX3U_HPP

#include "utility/mathematics/matrix.hpp"

namespace ece
{
	template <class T>
	struct determinant<T, 3>
	{
		inline double operator()(const Matrix<T, 3, 3> & matrix) const;
	};

	template <class T>
	struct transpose<T, 3>
	{
		inline Matrix<T, 3, 3> operator()(const Matrix<T, 3, 3> & matrix) const;
	};

	template <class T>
	struct inverse<T, 3>
	{
		inline Matrix<double, 3, 3> operator()(const Matrix<T, 3, 3> & matrix, bool & invertible) const;
	};

	/**
	 * @typedef Matrix3u
	 * @brief 3x3 Square matrix
	 */
	template <class T>
	using Matrix3u = Matrix<T, 3, 3>;

	/**
	 * @typedef IntMatrix3u
	 */
	using IntMatrix3u = Matrix3u<int>;

	/**
	* @typedef UintMatrix3u
	*/
	using UintMatrix3u = Matrix3u<unsigned int>;

	/**
	* @typedef FloatMatrix3u
	*/
	using FloatMatrix3u = Matrix3u<float>;

	/**
	* @typedef DoubleMatrix3u
	*/
	using DoubleMatrix3u = Matrix3u<double>;
}

#include "utility/mathematics/matrix3u.inl"

#endif // MATRIX3U_HPP
