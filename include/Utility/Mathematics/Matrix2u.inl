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
	inline Matrix2u<T> Matrix2u<T>::Identity() { return Matrix2u<T>(1, 0, 0, 1); }

	template <class T>
	inline Matrix2u<T>::Matrix2u() : std::array<Vertex2u<T>, 2>{ Vertex2u<T>{0, 0}, Vertex2u<T>{0, 0} } {}

	template <class T>
	inline Matrix2u<T>::Matrix2u(const T a11, const T a12, const T a21, const T a22):
		std::array<Vertex2u<T>, 2>{ Vertex2u<T>{a11, a12}, Vertex2u<T>{ a21, a22 } } {}

	template <class T>
	inline Matrix2u<T>::Matrix2u(const Vertex2u<T> & a1, const Vertex2u<T> & a2) : std::array<Vertex2u<T>, 2>{ a1, a2 } {}

	template <class T>
	template <typename V>
	inline Matrix2u<T>::Matrix2u(const Matrix2u<V> & copy): std::array<Vertex2u<T>, 2>{ copy[0], copy[1] } {}

	template <class T>
	template <typename V>
	inline Matrix2u<T> & Matrix2u<T>::operator=(const Matrix2u<V> & copy) 
	{
		(*this)[0] = copy[0];
		(*this)[1] = copy[1];
		return *this;
	}

	template <class T>
	inline Matrix2u<T>& Matrix2u<T>::setIdentity()
	{
		(*this)[0] = { 1, 0 };
		(*this)[1] = { 0, 1 };
		return *this;
	}

	template <class T>
	template<typename V>
	inline Matrix2u<T>& Matrix2u<T>::operator/=(const V value)
	{
		if (value == 0) {
			throw ece::DivideByZeroException::makeException("Matrix2u");
		}
		(*this)[0] /= value;
		(*this)[1] /= value;
		return *this;
	}

	template <class T>
	template<typename V>
	inline Matrix2u<T> & Matrix2u<T>::operator*=(const V value)
	{
		(*this)[0] *= value;
		(*this)[1] *= value;
		return *this;
	}

	template <class T>
	template <typename V>
	inline Matrix2u<T> & Matrix2u<T>::operator*=(const Matrix2u<V> value)
	{
		T a11 = (*this)[0][0] * value[0][0] + (*this)[0][1] * value[1][0];
		T a12 = (*this)[0][0] * value[0][1] + (*this)[0][1] * value[1][1];
		T a21 = (*this)[1][0] * value[0][0] + (*this)[1][1] * value[1][0];
		T a22 = (*this)[0][0] * value[0][1] + (*this)[0][1] * value[1][1];
		(*this)[0][0] = a11;
		(*this)[0][1] = a12;
		(*this)[1][0] = a21;
		(*this)[1][1] = a22;
		return *this;
	}

	template <class T>
	inline Matrix2u<T> & Matrix2u<T>::operator+=(const Matrix2u<T> value)
	{
		(*this)[0] += value[0];
		(*this)[1] += value[1];
		return *this;
	}

	template <class T>
	inline Matrix2u<T>& Matrix2u<T>::operator-=(const Matrix2u<T> value)
	{
		(*this)[0] -= value[0];
		(*this)[1] -= value[1];
		return *this;
	}

	template <class T>
	template <typename V>
	inline Matrix2u<T> Matrix2u<T>::operator/(const V value) const
	{
		if (value == 0) {
			throw ece::DivideByZeroException::makeException("Matrix2u");
		}
		return Matrix2u<T>{(*this)[0] / value, (*this)[1] / value};
	}

	template <class T>
	template <typename V>
	inline Matrix2u<T> Matrix2u<T>::operator*(const V value) const
	{
		return Matrix2u<T>{(*this)[0] * value, (*this)[1] * value};
	}

	template <class T>
	template <typename V>
	inline Vertex2u<T> Matrix2u<T>::operator*(const Vertex2u<V> value) const
	{
		T a11 = (*this)[0][0] * value[0] + (*this)[0][1] * value[1];
		T a21 = (*this)[1][0] * value[0] + (*this)[1][1] * value[1];
		return Vertex2u<T>(a11, a21);
	}

	template <class T>
	template <typename V>
	inline Matrix2u<T> Matrix2u<T>::operator*(const Matrix2u<V> value) const
	{
		T a11 = (*this)[0][0] * value[0][0] + (*this)[0][1] * value[1][0];
		T a12 = (*this)[0][0] * value[0][1] + (*this)[0][1] * value[1][1];
		T a21 = (*this)[1][0] * value[0][0] + (*this)[1][1] * value[1][0];
		T a22 = (*this)[0][0] * value[0][1] + (*this)[0][1] * value[1][1];
		return Matrix2u<T>(a11, a12, a21, a22);
	}

	template <class T>
	inline Matrix2u<T> Matrix2u<T>::operator+(const Matrix2u<T> value) const
	{
		return Matrix2u<T>{(*this)[0] + value[0], (*this)[1] + value[1]};
	}

	template <class T>
	inline Matrix2u<T> Matrix2u<T>::operator-(const Matrix2u<T> value) const
	{
		return Matrix2u<T>{(*this)[0] - value[0], (*this)[1] - value[1]};
	}

	template <class T>
	inline Matrix2u<T> Matrix2u<T>::operator-() const
	{
		return Matrix2u<T>{-(*this)[0], -(*this)[1]};
	}

	template <class T>
	inline bool Matrix2u<T>::operator==(const Matrix2u<T> & rightOperand) const
	{
		return (*this)[0] == rightOperand[0] && (*this)[1] == rightOperand[1];
	}

	template <class T>
	inline Vertex2u<T> Matrix2u<T>::getColumn(const int index) const
	{
		if (index > 1 || index < 0) {
			throw ece::OutOfRangeException::makeException("Column of Matrix2u", index);
		}
		return Vertex2u<T>((*this)[0][index], (*this)[1][index]);
	}

	template <class T>
	inline Vertex2u<T> Matrix2u<T>::getRow(const int index) const
	{
		if (index > 1 || index < 0) {
			throw ece::OutOfRangeException::makeException("Row of Matrix2u", index);
		}
		return Vertex2u<T>((*this)[index]);
	}

	template <class T>
	inline Vertex2u<T> & Matrix2u<T>::getRow(const int index)
	{
		if (index > 1 || index < 0) {
			throw ece::OutOfRangeException::makeException("Row of Matrix2u", index);
		}
		return (*this)[index];
	}

	template<class T>
	inline T Matrix2u<T>::determinant() const
	{
		return (*this)[0][0] * (*this)[1][1] - (*this)[0][1] * (*this)[1][0];
	}

	template<class T>
	inline Matrix2u<T> Matrix2u<T>::transpose() const
	{
		return Matrix2u<T>((*this)[0][0], (*this)[1][0], (*this)[0][1], (*this)[1][1]);
	}

	template<class T>
	inline Matrix2u<double> Matrix2u<T>::inverse(bool & invertible) const
	{
		auto det = this->determinant();
		invertible = (det != 0);
		if (invertible) {
			return Matrix2u<double>((*this)[1][1], -(*this)[0][1], -(*this)[1][0], (*this)[0][0]) * (1.0f / det);
		}
		else {
			return Matrix2u<double>();
		}
	}
}