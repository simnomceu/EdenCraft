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

#ifndef MATRIX3U_HPP
#define MATRIX3U_HPP

#include <array>

#include "Mathematics\Vertex3u.hpp"

namespace ece
{
	template <class T>
	class Matrix3u : public std::array<Vertex3u<T>, 3>
	{
	public:
		static Matrix3u<T> Identity();
		inline Matrix3u();
		inline Matrix3u(const T a11, const T a12, const T a13,
						const T a21, const T a22, const T a23,
						const T a31, const T a32, const T a33);
		inline Matrix3u(const Vertex3u<T> & a1, const Vertex3u<T> & a2, const Vertex3u<T> & a3);
		Matrix3u(const Matrix3u<T> & copy) = default;
		Matrix3u(Matrix3u<T> && move) = default;
		template <typename V> inline Matrix3u(const Matrix3u<V> & copy);

		~Matrix3u() = default;

		Matrix3u<T> & operator=(const Matrix3u<T> & copy) = default;
		Matrix3u<T> & operator=(Matrix3u<T> && move) = default;
		template <typename V> inline Matrix3u<T> & operator=(const Matrix3u<V> & copy);
		inline Matrix3u<T> & setIdentity();

		template <typename V> inline Matrix3u<T> & operator/=(const V value);
		template <typename V> inline Matrix3u<T> & operator*=(const V value);
		template <typename V> inline Matrix3u<T> & operator*=(const Matrix3u<V> value);
		inline Matrix3u<T> & operator+=(const Matrix3u<T> value);
		inline Matrix3u<T> & operator-=(const Matrix3u<T> value);

		template <typename V> inline Matrix3u<T> operator/(const V value) const;
		template <typename V> inline Matrix3u<T> operator*(const V value) const;
		template <typename V> inline Vertex3u<T> operator*(const Vertex3u<V> value) const;
		template <typename V> inline Matrix3u<T> operator*(const Matrix3u<V> value) const;
		inline Matrix3u<T> operator+(const Matrix3u<T> value) const;
		inline Matrix3u<T> operator-(const Matrix3u<T> value) const;

		inline Matrix3u<T> operator-() const;

		inline bool operator==(const Matrix3u<T> & rightOperand) const;

		inline Vertex3u<T> getColumn(const int index) const;
		inline Vertex3u<T> getRow(const int index) const;
		inline Vertex3u<T> & getRow(const int index);
		using std::array<Vertex3u<T>, 3>::operator[];

		inline T determinant() const;
		inline Matrix3u<T> transpose() const;
		inline Matrix3u<T> inverse(bool & invertible) const;
	};

	typedef Matrix3u<float> FloatMatrix3u;
	typedef Matrix3u<int> IntMatrix3u;
	typedef Matrix3u<double> DoubleMatrix3u;
}

#include "Mathematics\Matrix3u.inl"

#endif // MATRIX3U_HPP
