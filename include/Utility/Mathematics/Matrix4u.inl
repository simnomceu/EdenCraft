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

#include "Debug\Exception.hpp"

namespace ece
{
	template <class T>
	inline Matrix4u<T> Matrix4u<T>::Identity() {
		return Matrix4u<T>(1, 0, 0, 0,
						   0, 1, 0, 0,
						   0, 0, 1, 0,
						   0, 0, 0, 1);
	}

	template <class T>
	inline Matrix4u<T>::Matrix4u() : std::array<Vertex4u<T>, 4>{ Vertex4u<T>(),
																 Vertex4u<T>(),
																 Vertex4u<T>(),
																 Vertex4u<T>() } {}

	template <class T>
	inline Matrix4u<T>::Matrix4u(const T a11, const T a12, const T a13, const T a14,
								 const T a21, const T a22, const T a23, const T a24,
								 const T a31, const T a32, const T a33, const T a34,
								 const T a41, const T a42, const T a43, const T a44) :
		std::array<Vertex4u<T>, 4>{ Vertex4u<T>(a11, a12, a13, a14),
									Vertex4u<T>(a21, a22, a23, a24),
									Vertex4u<T>(a31, a32, a33, a34),
									Vertex4u<T>(a41, a42, a43, a44) } {}

	template <class T>
	inline Matrix4u<T>::Matrix4u(const Vertex4u<T> & a1, const Vertex4u<T> & a2, const Vertex4u<T> & a3, const Vertex4u<T> & a4) :
		std::array<Vertex4u<T>, 4>{ a1, a2, a3, a4 } {}

	template <class T>
	template <typename V>
	inline Matrix4u<T>::Matrix4u(const Matrix4u<V> & copy) : 
		std::array<Vertex4u<T>, 4>{ copy[0], copy[1], copy[2], copy[3] } {}

	template <class T>
	template <typename V>
	inline Matrix4u<T> & Matrix4u<T>::operator=(const Matrix4u<V> & copy)
	{
		(*this)[0] = copy[0];
		(*this)[1] = copy[1];
		(*this)[2] = copy[2];
		(*this)[3] = copy[3];
		return *this;
	}

	template <class T>
	inline Matrix4u<T>& Matrix4u<T>::setIdentity()
	{
		(*this)[0] = { 1, 0, 0, 0 };
		(*this)[1] = { 0, 1, 0, 0 };
		(*this)[2] = { 0, 0, 1, 0 };
		(*this)[3] = { 0, 0, 0, 1 };
		return *this;
	}

	template <class T>
	template<typename V>
	inline Matrix4u<T>& Matrix4u<T>::operator/=(const V value)
	{
		if (value == 0) {
			throw DivideByZeroException::makeException("Matrix4u");
		}

		(*this)[0] /= value;
		(*this)[1] /= value;
		(*this)[2] /= value;
		(*this)[3] /= value;
		return *this;
	}

	template <class T>
	template<typename V>
	inline Matrix4u<T>& Matrix4u<T>::operator*=(const V value)
	{
		(*this)[0] *= value;
		(*this)[1] *= value;
		(*this)[2] *= value;
		(*this)[3] *= value;
		return *this;
	}

	template <class T>
	template <typename V>
	inline Matrix4u<T> & Matrix4u<T>::operator*=(const Matrix4u<V> value)
	{
		T a11 = (*this)[0][0] * value[0][0] + (*this)[0][1] * value[1][0] + (*this)[0][2] * value[2][0] + (*this)[0][3] * value[3][0];
		T a12 = (*this)[0][0] * value[0][1] + (*this)[0][1] * value[1][1] + (*this)[0][2] * value[2][1] + (*this)[0][3] * value[3][1];
		T a13 = (*this)[0][0] * value[0][2] + (*this)[0][1] * value[1][2] + (*this)[0][2] * value[2][2] + (*this)[0][3] * value[3][2];
		T a14 = (*this)[0][0] * value[0][3] + (*this)[0][1] * value[1][3] + (*this)[0][2] * value[2][3] + (*this)[0][3] * value[3][3];
		T a21 = (*this)[1][0] * value[0][0] + (*this)[1][1] * value[1][0] + (*this)[1][2] * value[2][0] + (*this)[1][3] * value[3][0];
		T a22 = (*this)[1][0] * value[0][1] + (*this)[1][1] * value[1][1] + (*this)[1][2] * value[2][1] + (*this)[1][3] * value[3][1];
		T a23 = (*this)[1][0] * value[0][2] + (*this)[1][1] * value[1][2] + (*this)[1][2] * value[2][2] + (*this)[1][3] * value[3][2];
		T a24 = (*this)[1][0] * value[0][3] + (*this)[1][1] * value[1][3] + (*this)[1][2] * value[2][3] + (*this)[1][3] * value[3][3];
		T a31 = (*this)[2][0] * value[0][0] + (*this)[2][1] * value[1][0] + (*this)[2][2] * value[2][0] + (*this)[2][3] * value[3][0];
		T a32 = (*this)[2][0] * value[0][1] + (*this)[2][1] * value[1][1] + (*this)[2][2] * value[2][1] + (*this)[2][3] * value[3][1];
		T a33 = (*this)[2][0] * value[0][2] + (*this)[2][1] * value[1][2] + (*this)[2][2] * value[2][2] + (*this)[2][3] * value[3][2];
		T a34 = (*this)[2][0] * value[0][3] + (*this)[2][1] * value[1][3] + (*this)[2][2] * value[2][3] + (*this)[2][3] * value[3][3];
		T a41 = (*this)[3][0] * value[0][0] + (*this)[3][1] * value[1][0] + (*this)[3][2] * value[2][0] + (*this)[3][3] * value[3][0];
		T a42 = (*this)[3][0] * value[0][1] + (*this)[3][1] * value[1][1] + (*this)[3][2] * value[2][1] + (*this)[3][3] * value[3][1];
		T a43 = (*this)[3][0] * value[0][2] + (*this)[3][1] * value[1][2] + (*this)[3][2] * value[2][2] + (*this)[3][3] * value[3][2];
		T a44 = (*this)[3][0] * value[0][3] + (*this)[3][1] * value[1][3] + (*this)[3][2] * value[2][3] + (*this)[3][3] * value[3][3];
		(*this)[0][0] = a11;
		(*this)[0][1] = a12;
		(*this)[0][2] = a13;
		(*this)[0][3] = a14;
		(*this)[1][0] = a21;
		(*this)[1][1] = a22;
		(*this)[1][2] = a23;
		(*this)[1][3] = a24;
		(*this)[2][0] = a31;
		(*this)[2][1] = a32;
		(*this)[2][2] = a33;
		(*this)[2][3] = a44;
		(*this)[3][0] = a41;
		(*this)[3][1] = a42;
		(*this)[3][2] = a43;
		(*this)[3][3] = a44;
		return *this;
	}

	template <class T>
	inline Matrix4u<T>& Matrix4u<T>::operator+=(const Matrix4u<T> value)
	{
		(*this)[0] += value[0];
		(*this)[1] += value[1];
		(*this)[2] += value[2];
		(*this)[3] += value[3];
		return *this;
	}

	template <class T>
	inline Matrix4u<T>& Matrix4u<T>::operator-=(const Matrix4u<T> value)
	{
		(*this)[0] -= value[0];
		(*this)[1] -= value[1];
		(*this)[2] -= value[2];
		(*this)[3] -= value[3];
		return *this;
	}

	template <class T>
	template <typename V>
	inline Matrix4u<T> Matrix4u<T>::operator/(const V value) const
	{
		if (value == 0) {
			throw DivideByZeroException::makeException("Matrix4u");
		}
		return Matrix4u<T>{(*this)[0] / value, (*this)[1] / value, (*this)[2] / value, (*this)[3] / value};
	}

	template <class T>
	template <typename V>
	inline Matrix4u<T> Matrix4u<T>::operator*(const V value) const
	{
		return Matrix4u<T>{(*this)[0] * value, (*this)[1] * value, (*this)[2] * value, (*this)[3] * value};
	}

	template <class T>
	template <typename V>
	inline Vertex4u<T> Matrix4u<T>::operator*(const Vertex4u<V> value) const
	{
		T a11 = (*this)[0][0] * value[0] + (*this)[0][1] * value[1] + (*this)[0][2] * value[2] + (*this)[0][3] * value[3];
		T a21 = (*this)[1][0] * value[0] + (*this)[1][1] * value[1] + (*this)[1][2] * value[2] + (*this)[1][3] * value[3];
		T a31 = (*this)[2][0] * value[0] + (*this)[2][1] * value[1] + (*this)[2][2] * value[2] + (*this)[2][3] * value[3];
		T a41 = (*this)[3][0] * value[0] + (*this)[3][1] * value[1] + (*this)[3][2] * value[2] + (*this)[3][3] * value[3];
		return Vertex4u<T>(a11, a21, a31, a41);
	}

	template <class T>
	template <typename V>
	inline Matrix4u<T> Matrix4u<T>::operator*(const Matrix4u<V> value) const
	{
		T a11 = (*this)[0][0] * value[0][0] + (*this)[0][1] * value[1][0] + (*this)[0][2] * value[2][0] + (*this)[0][3] * value[3][0];
		T a12 = (*this)[0][0] * value[0][1] + (*this)[0][1] * value[1][1] + (*this)[0][2] * value[2][1] + (*this)[0][3] * value[3][1];
		T a13 = (*this)[0][0] * value[0][2] + (*this)[0][1] * value[1][2] + (*this)[0][2] * value[2][2] + (*this)[0][3] * value[3][2];
		T a14 = (*this)[0][0] * value[0][3] + (*this)[0][1] * value[1][3] + (*this)[0][2] * value[2][3] + (*this)[0][3] * value[3][3];
		T a21 = (*this)[1][0] * value[0][0] + (*this)[1][1] * value[1][0] + (*this)[1][2] * value[2][0] + (*this)[1][3] * value[3][0];
		T a22 = (*this)[1][0] * value[0][1] + (*this)[1][1] * value[1][1] + (*this)[1][2] * value[2][1] + (*this)[1][3] * value[3][1];
		T a23 = (*this)[1][0] * value[0][2] + (*this)[1][1] * value[1][2] + (*this)[1][2] * value[2][2] + (*this)[1][3] * value[3][2];
		T a24 = (*this)[1][0] * value[0][3] + (*this)[1][1] * value[1][3] + (*this)[1][2] * value[2][3] + (*this)[1][3] * value[3][3];
		T a31 = (*this)[2][0] * value[0][0] + (*this)[2][1] * value[1][0] + (*this)[2][2] * value[2][0] + (*this)[2][3] * value[3][0];
		T a32 = (*this)[2][0] * value[0][1] + (*this)[2][1] * value[1][1] + (*this)[2][2] * value[2][1] + (*this)[2][3] * value[3][1];
		T a33 = (*this)[2][0] * value[0][2] + (*this)[2][1] * value[1][2] + (*this)[2][2] * value[2][2] + (*this)[2][3] * value[3][2];
		T a34 = (*this)[2][0] * value[0][3] + (*this)[2][1] * value[1][3] + (*this)[2][2] * value[2][3] + (*this)[2][3] * value[3][3];
		T a41 = (*this)[3][0] * value[0][0] + (*this)[3][1] * value[1][0] + (*this)[3][2] * value[2][0] + (*this)[3][3] * value[3][0];
		T a42 = (*this)[3][0] * value[0][1] + (*this)[3][1] * value[1][1] + (*this)[3][2] * value[2][1] + (*this)[3][3] * value[3][1];
		T a43 = (*this)[3][0] * value[0][2] + (*this)[3][1] * value[1][2] + (*this)[3][2] * value[2][2] + (*this)[3][3] * value[3][2];
		T a44 = (*this)[3][0] * value[0][3] + (*this)[3][1] * value[1][3] + (*this)[3][2] * value[2][3] + (*this)[3][3] * value[3][3];
		return Matrix4u<T>(a11, a12, a13, a14,
						   a21, a22, a23, a24,
						   a31, a32, a33, a34,
						   a41, a42, a43, a44);
	}

	template <class T>
	inline Matrix4u<T> Matrix4u<T>::operator+(const Matrix4u<T> value) const
	{
		return Matrix4u<T>{(*this)[0] + value[0], (*this)[1] + value[1], (*this)[2] + value[2], (*this)[3] + value[3]};
	}

	template <class T>
	inline Matrix4u<T> Matrix4u<T>::operator-(const Matrix4u<T> value) const
	{
		return Matrix4u<T>{(*this)[0] - value[0], (*this)[1] - value[1], (*this)[2] - value[2], (*this)[3] - value[3]};
	}

	template <class T>
	inline Matrix4u<T> Matrix4u<T>::operator-() const
	{
		return Matrix4u<T>{-(*this)[0], -(*this)[1], -(*this)[2], -(*this)[3]};
	}

	template <class T>
	inline bool Matrix4u<T>::operator==(const Matrix4u<T> & rightOperand) const
	{
		return (*this)[0] == rightOperand[0] && (*this)[1] == rightOperand[1] 
			&& (*this)[2] == rightOperand[2] && (*this)[3] == rightOperand[3];
	}

	template <class T>
	inline Vertex4u<T> Matrix4u<T>::getColumn(const int index) const
	{
		return Vertex4u<T>((*this)[0][index], (*this)[1][index], (*this)[2][index], (*this)[3][index]);
	}

	template <class T>
	inline Vertex4u<T> Matrix4u<T>::getRow(const int index) const
	{
		return Vertex4u<T>((*this)[index]);
	}

	template <class T>
	inline Vertex4u<T> & Matrix4u<T>::getRow(const int index)
	{
		return (*this)[index];
	}

	template<class T>
	inline T Matrix4u<T>::determinant() const
	{
		T a11 = (*this)[0][3] * (*this)[1][2] * (*this)[2][1] * (*this)[3][0];
		T a12 = (*this)[0][2] * (*this)[1][3] * (*this)[2][1] * (*this)[3][0];
		T a13 = (*this)[0][3] * (*this)[1][1] * (*this)[2][2] * (*this)[3][0];
		T a14 = (*this)[0][1] * (*this)[1][3] * (*this)[2][2] * (*this)[3][0];
		T a21 = (*this)[0][2] * (*this)[1][1] * (*this)[2][3] * (*this)[3][0];
		T a22 = (*this)[0][1] * (*this)[1][2] * (*this)[2][3] * (*this)[3][0];
		T a23 = (*this)[0][3] * (*this)[1][2] * (*this)[2][0] * (*this)[3][1];
		T a24 = (*this)[0][2] * (*this)[1][3] * (*this)[2][0] * (*this)[3][1];
		T a31 = (*this)[0][3] * (*this)[1][0] * (*this)[2][2] * (*this)[3][1];
		T a32 = (*this)[0][0] * (*this)[1][3] * (*this)[2][2] * (*this)[3][1];
		T a33 = (*this)[0][2] * (*this)[1][0] * (*this)[2][3] * (*this)[3][1];
		T a34 = (*this)[0][0] * (*this)[1][2] * (*this)[2][3] * (*this)[3][1];
		T a41 = (*this)[0][3] * (*this)[1][1] * (*this)[2][0] * (*this)[3][2];
		T a42 = (*this)[0][1] * (*this)[1][3] * (*this)[2][0] * (*this)[3][2];
		T a43 = (*this)[0][3] * (*this)[1][0] * (*this)[2][1] * (*this)[3][2];
		T a44 = (*this)[0][0] * (*this)[1][3] * (*this)[2][1] * (*this)[3][2];
		T a51 = (*this)[0][1] * (*this)[1][0] * (*this)[2][3] * (*this)[3][2];
		T a52 = (*this)[0][0] * (*this)[1][1] * (*this)[2][3] * (*this)[3][2];
		T a53 = (*this)[0][2] * (*this)[1][1] * (*this)[2][0] * (*this)[3][3];
		T a54 = (*this)[0][1] * (*this)[1][2] * (*this)[2][0] * (*this)[3][3];
		T a61 = (*this)[0][2] * (*this)[1][0] * (*this)[2][1] * (*this)[3][3];
		T a62 = (*this)[0][0] * (*this)[1][2] * (*this)[2][1] * (*this)[3][3];
		T a63 = (*this)[0][1] * (*this)[1][0] * (*this)[2][2] * (*this)[3][3];
		T a64 = (*this)[0][0] * (*this)[1][1] * (*this)[2][2] * (*this)[3][3];
		return  a11 - a12 - a13 + a14 +
				a21 - a22 - a23 + a24 +
				a31 - a32 - a33 + a34 +
				a41 - a42 - a43 + a44 +
				a51 - a52 - a53 + a54 +
				a61 - a62 - a63 + a64;
	}

	template<class T>
	inline Matrix4u<T> Matrix4u<T>::transpose() const
	{
		return Matrix4u<T>((*this)[0][0], (*this)[1][0], (*this)[2][0], (*this)[3][0],
						   (*this)[0][1], (*this)[1][1], (*this)[2][1], (*this)[3][1],
						   (*this)[0][2], (*this)[1][2], (*this)[2][2], (*this)[3][2],
						   (*this)[0][3], (*this)[1][3], (*this)[2][3], (*this)[3][3]);
	}

	template<class T>
	inline Matrix4u<T> Matrix4u<T>::inverse(bool & invertible) const
	{
		auto det = this->determinant();
		invertible = (det != 0);
		if (invertible) {
			T a11 = (*this)[1][2] * (*this)[2][3] * (*this)[3][1] - (*this)[1][3] * (*this)[2][2] * (*this)[3][1] + (*this)[1][3] * (*this)[2][1] * (*this)[3][2] - (*this)[1][1] * (*this)[2][3] * (*this)[3][2] - (*this)[1][2] * (*this)[2][1] * (*this)[3][3] + (*this)[1][1] * (*this)[2][2] * (*this)[3][3];
			T a12 = (*this)[0][3] * (*this)[2][2] * (*this)[3][1] - (*this)[0][2] * (*this)[2][3] * (*this)[3][1] - (*this)[0][3] * (*this)[2][1] * (*this)[3][2] + (*this)[0][1] * (*this)[2][3] * (*this)[3][2] + (*this)[0][2] * (*this)[2][1] * (*this)[3][3] - (*this)[0][1] * (*this)[2][2] * (*this)[3][3];
			T a13 = (*this)[0][2] * (*this)[1][3] * (*this)[3][1] - (*this)[0][3] * (*this)[1][2] * (*this)[3][1] + (*this)[0][3] * (*this)[1][1] * (*this)[3][2] - (*this)[0][1] * (*this)[1][3] * (*this)[3][2] - (*this)[0][2] * (*this)[1][1] * (*this)[3][3] + (*this)[0][1] * (*this)[1][2] * (*this)[3][3];
			T a14 = (*this)[0][3] * (*this)[1][2] * (*this)[2][1] - (*this)[0][2] * (*this)[1][3] * (*this)[2][1] - (*this)[0][3] * (*this)[1][1] * (*this)[2][2] + (*this)[0][1] * (*this)[1][3] * (*this)[2][2] + (*this)[0][2] * (*this)[1][1] * (*this)[2][3] - (*this)[0][1] * (*this)[1][2] * (*this)[2][3];
			T a21 = (*this)[1][3] * (*this)[2][2] * (*this)[3][0] - (*this)[1][2] * (*this)[2][3] * (*this)[3][0] - (*this)[1][3] * (*this)[2][0] * (*this)[3][2] + (*this)[1][0] * (*this)[2][3] * (*this)[3][2] + (*this)[1][2] * (*this)[2][0] * (*this)[3][3] - (*this)[1][0] * (*this)[2][2] * (*this)[3][3];
			T a22 = (*this)[0][2] * (*this)[2][3] * (*this)[3][0] - (*this)[0][3] * (*this)[2][2] * (*this)[3][0] + (*this)[0][3] * (*this)[2][0] * (*this)[3][2] - (*this)[0][0] * (*this)[2][3] * (*this)[3][2] - (*this)[0][2] * (*this)[2][0] * (*this)[3][3] + (*this)[0][0] * (*this)[2][2] * (*this)[3][3];
			T a23 = (*this)[0][3] * (*this)[1][2] * (*this)[3][0] - (*this)[0][2] * (*this)[1][3] * (*this)[3][0] - (*this)[0][3] * (*this)[1][0] * (*this)[3][2] + (*this)[0][0] * (*this)[1][3] * (*this)[3][2] + (*this)[0][2] * (*this)[1][0] * (*this)[3][3] - (*this)[0][0] * (*this)[1][2] * (*this)[3][3];
			T a24 = (*this)[0][2] * (*this)[1][3] * (*this)[2][0] - (*this)[0][3] * (*this)[1][2] * (*this)[2][0] + (*this)[0][3] * (*this)[1][0] * (*this)[2][2] - (*this)[0][0] * (*this)[1][3] * (*this)[2][2] - (*this)[0][2] * (*this)[1][0] * (*this)[2][3] + (*this)[0][0] * (*this)[1][2] * (*this)[2][3];
			T a31 = (*this)[1][1] * (*this)[2][3] * (*this)[3][0] - (*this)[1][3] * (*this)[2][1] * (*this)[3][0] + (*this)[1][3] * (*this)[2][0] * (*this)[3][1] - (*this)[1][0] * (*this)[2][3] * (*this)[3][1] - (*this)[1][1] * (*this)[2][0] * (*this)[3][3] + (*this)[1][0] * (*this)[2][1] * (*this)[3][3];
			T a32 = (*this)[0][3] * (*this)[2][1] * (*this)[3][0] - (*this)[0][1] * (*this)[2][3] * (*this)[3][0] - (*this)[0][3] * (*this)[2][0] * (*this)[3][1] + (*this)[0][0] * (*this)[2][3] * (*this)[3][1] + (*this)[0][1] * (*this)[2][0] * (*this)[3][3] - (*this)[0][0] * (*this)[2][1] * (*this)[3][3];
			T a33 = (*this)[0][1] * (*this)[1][3] * (*this)[3][0] - (*this)[0][3] * (*this)[1][1] * (*this)[3][0] + (*this)[0][3] * (*this)[1][0] * (*this)[3][1] - (*this)[0][0] * (*this)[1][3] * (*this)[3][1] - (*this)[0][1] * (*this)[1][0] * (*this)[3][3] + (*this)[0][0] * (*this)[1][1] * (*this)[3][3];
			T a34 = (*this)[0][3] * (*this)[1][1] * (*this)[2][0] - (*this)[0][1] * (*this)[1][3] * (*this)[2][0] - (*this)[0][3] * (*this)[1][0] * (*this)[2][1] + (*this)[0][0] * (*this)[1][3] * (*this)[2][1] + (*this)[0][1] * (*this)[1][0] * (*this)[2][3] - (*this)[0][0] * (*this)[1][1] * (*this)[2][3];
			T a41 = (*this)[1][2] * (*this)[2][1] * (*this)[3][0] - (*this)[1][1] * (*this)[2][2] * (*this)[3][0] - (*this)[1][2] * (*this)[2][0] * (*this)[3][1] + (*this)[1][0] * (*this)[2][2] * (*this)[3][1] + (*this)[1][1] * (*this)[2][0] * (*this)[3][2] - (*this)[1][0] * (*this)[2][1] * (*this)[3][2];
			T a42 = (*this)[0][1] * (*this)[2][2] * (*this)[3][0] - (*this)[0][2] * (*this)[2][1] * (*this)[3][0] + (*this)[0][2] * (*this)[2][0] * (*this)[3][1] - (*this)[0][0] * (*this)[2][2] * (*this)[3][1] - (*this)[0][1] * (*this)[2][0] * (*this)[3][2] + (*this)[0][0] * (*this)[2][1] * (*this)[3][2];
			T a43 = (*this)[0][2] * (*this)[1][1] * (*this)[3][0] - (*this)[0][1] * (*this)[1][2] * (*this)[3][0] - (*this)[0][2] * (*this)[1][0] * (*this)[3][1] + (*this)[0][0] * (*this)[1][2] * (*this)[3][1] + (*this)[0][1] * (*this)[1][0] * (*this)[3][2] - (*this)[0][0] * (*this)[1][1] * (*this)[3][2];
			T a44 = (*this)[0][1] * (*this)[1][2] * (*this)[2][0] - (*this)[0][2] * (*this)[1][1] * (*this)[2][0] + (*this)[0][2] * (*this)[1][0] * (*this)[2][1] - (*this)[0][0] * (*this)[1][2] * (*this)[2][1] - (*this)[0][1] * (*this)[1][0] * (*this)[2][2] + (*this)[0][0] * (*this)[1][1] * (*this)[2][2];

			return Matrix4u<T>(a11, a12, a13, a14,
							   a21, a22, a23, a24,
							   a31, a32, a33, a34,
							   a41, a42, a43, a44) * (1.0f / det);
		}
		else {
			return Matrix4u<T>();
		}
	}
}