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

#ifndef MATRIX2U_HPP
#define MATRIX2U_HPP

#include <array>

#include "Mathematics\Vertex2u.hpp"

namespace ece
{
	template <class T>
	class Matrix2u: public std::array<Vertex2u<T>, 2>
	{
	public:
		static Matrix2u<T> Identity();
		inline Matrix2u();
		inline Matrix2u(const T a11, const T a12, const T a21, const T a22);
		inline Matrix2u(const Vertex2u<T> & a1, const Vertex2u<T> & a2);
		Matrix2u(const Matrix2u<T> & copy) = default;
		Matrix2u(Matrix2u<T> && move) = default;
		template <typename V> inline Matrix2u(const Matrix2u<V> & copy);

		~Matrix2u() = default;

		Matrix2u<T> & operator=(const Matrix2u<T> & copy) = default;
		Matrix2u<T> & operator=(Matrix2u<T> && move) = default;
		template <typename V> inline Matrix2u<T> & operator=(const Matrix2u<V> & copy);
		inline Matrix2u<T> & setIdentity();

		template <typename V> inline Matrix2u<T> & operator/=(const V value);
		template <typename V> inline Matrix2u<T> & operator*=(const V value);
		template <typename V> inline Matrix2u<T> & operator*=(const Matrix2u<V> value);
		inline Matrix2u<T> & operator+=(const Matrix2u<T> value);
		inline Matrix2u<T> & operator-=(const Matrix2u<T> value);

		template <typename V> inline Matrix2u<T> operator/(const V value) const;
		template <typename V> inline Matrix2u<T> operator*(const V value) const;
		template <typename V> inline Vertex2u<T> operator*(const Vertex2u<V> value) const;
		template <typename V> inline Matrix2u<T> operator*(const Matrix2u<V> value) const;
		inline Matrix2u<T> operator+(const Matrix2u<T> value) const;
		inline Matrix2u<T> operator-(const Matrix2u<T> value) const;

		inline Matrix2u<T> operator-() const;

		inline bool operator==(const Matrix2u<T> & rightOperand) const;

		inline Vertex2u<T> getColumn(const int index) const;
		inline Vertex2u<T> getRow(const int index) const;
		inline Vertex2u<T> & getRow(const int index);
		using std::array<Vertex2u<T>, 2>::operator[];

		inline T determinant() const;
		inline Matrix2u<T> transpose() const;
		inline Matrix2u<double> inverse(bool & invertible) const;
	};

	typedef Matrix2u<float> FloatMatrix2u;
	typedef Matrix2u<int> IntMatrix2u;
	typedef Matrix2u<double> DoubleMatrix2u;
}

#include "Mathematics\Matrix2u.inl"

#endif // MATRIX2U_HPP
