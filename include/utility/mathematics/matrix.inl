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
	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> Matrix<T, M, N, enabled>::Identity()
	{
		Matrix<T, M, N, enabled> tmp;
		tmp[std::slice(0, M, M + 1)] = 1;
		return  tmp;
	}

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled>::Matrix(): std::valarray<T>(static_cast<T>(0), M * N) {}

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled>::Matrix(const T & value) : std::valarray<T>(value, M * N) {}

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled>::Matrix(const std::initializer_list<T> & il): std::valarray<T>(il) {}

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled>::Matrix(std::valarray<T> && move): std::valarray<T>(move) {}

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> & Matrix<T, M, N, enabled>::operator=(const std::initializer_list<T> & il) { std::valarray<T>::operator=(il); }

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> & Matrix<T, M, N, enabled>::setIdentity()
	{
		std::valarray<T>::operator=(0);
		(*this)[std::slice(0, M, M + 1)] = 1;
		return *this;
	}

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Vector<T, M> Matrix<T, M, N, enabled>::operator[](const unsigned int index) const
	{
		if (index >= N) {
			throw OutOfRangeException("Vector<T, M> Matrix<T, M, N, enabled>::operator[](const unsigned int index) const", index);
		}
		return Vector<T, M>(std::move(std::valarray<T>::operator[](std::slice(index * M, M, 1))));
	}

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Vector<T, M> Matrix<T, M, N, enabled>::operator[](const unsigned int index)
	{
		if (index >= N) {
			throw OutOfRangeException("std::slice_array<T> Matrix<T, M, N, enabled>::operator[](const unsigned int index) const", index);
		}
		return Vector<T, M>(std::move(std::valarray<T>::operator[](std::slice(index * M, M, 1))));
	}

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline T & Matrix<T, M, N, enabled>::operator()(const unsigned int i, const unsigned int j)
	{
		if (i >= N || j >= M) {
			throw OutOfRangeException("T & Matrix<T, M, N, enabled>::operator()(const unsigned int i, const unsigned int j)", i*M + j);
		}
		return std::valarray<T>::operator[](i*M + j);
	}

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline T Matrix<T, M, N, enabled>::operator()(const unsigned int i, const unsigned int j) const
	{
		if (i >= N || j >= M) {
			throw OutOfRangeException("T & Matrix<T, M, N, enabled>::operator()(const unsigned int i, const unsigned int j)", i*M + j);
		}
		return std::valarray<T>::operator[](i*M + j);
	}

	template <class T, unsigned int M, unsigned int N, typename enabled>
	std::slice_array<T> Matrix<T, M, N, enabled>::operator[](std::slice slicearr)
	{
		return std::valarray<T>::operator[](slicearr);
	}

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Vector<T, M> Matrix<T, M, N, enabled>::row(const unsigned int index) const
	{
		if (index >= N) {
			throw OutOfRangeException("Vector<T, M> Matrix<T, M, N, enabled>::row(const unsigned int index) const", index);
		}
		return Vector<T, M>(std::move(std::valarray<T>::operator[](std::slice(index * M, M, 1))));
	}

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Vector<T, M> Matrix<T, M, N, enabled>::row(const unsigned int index)
	{
		if (index >= N) {
			throw OutOfRangeException("Vector<T, M> Matrix<T, M, N, enabled>::row(const unsigned int index)", index);
		}
		return Vector<T, M>(std::move(std::valarray<T>::operator[](std::slice(index * M, M, 1))));
	}

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Vector<T, N> Matrix<T, M, N, enabled>::column(const unsigned int index) const
	{
		if (index >= M) {
			throw OutOfRangeException("Vector<T, N> Matrix<T, M, N, enabled>::column(const unsigned int index) const", index);
		}
		return Vector<T, N>(std::move(std::valarray<T>::operator[](std::slice(index, N, M))));
	}

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Vector<T, N> Matrix<T, M, N, enabled>::column(const unsigned int index)
	{
		if (index >= M) {
			throw OutOfRangeException("Vector<T, N> Matrix<T, M, N, enabled>::column(const unsigned int index)", index);
		}
		return Vector<T, N>(std::move(std::valarray<T>::operator[](std::slice(index, N, M))));
	}

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> Matrix<T, M, N, enabled>::operator+() const noexcept { return Matrix<T, M, N, enabled>(std::move(std::valarray<T>::operator+())); }

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> Matrix<T, M, N, enabled>::operator-() const noexcept { return Matrix<T, M, N, enabled>(std::move(std::valarray<T>::operator-())); }

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> Matrix<T, M, N, enabled>::operator~() const noexcept { return Matrix<T, M, N, enabled>(std::move(std::valarray<T>::operator~())); }

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<bool, M, N> Matrix<T, M, N, enabled>::operator!() const noexcept { return Matrix<T, M, N, enabled>(std::move(std::valarray<T>::operator!())); }

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> & Matrix<T, M, N, enabled>::operator+=(const Matrix<T, M, N, enabled> & v)
	{
		std::valarray<T>::operator+=(v);
		return *this;
	}

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> & Matrix<T, M, N, enabled>::operator-=(const Matrix<T, M, N, enabled> & v)
	{
		std::valarray<T>::operator-=(v);
		return *this;
	}

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> & Matrix<T, M, N, enabled>::operator*=(const Matrix<T, M, N, enabled> & v)
	{
		Matrix<T, M, N, enabled> result;
		for (unsigned int j = 0; j < N; ++j) {
			for (unsigned int i = 0; i < M; ++i) {
				result(i, j) = (this->row(i) * v.column(j)).sum();
			}
		}
		this->operator=(std::move(result));
		return *this;
	}

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> & Matrix<T, M, N, enabled>::operator/=(const Matrix<T, M, N, enabled> & v)
	{
		std::valarray<T>::operator/=(std::numeric_limits<T>::is_integer ? Matrix<float, M, N>(v) : v);
		return *this;
	}

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> & Matrix<T, M, N, enabled>::operator%=(const Matrix<T, M, N, enabled> & v)
	{
		std::valarray<T>::operator%=(std::numeric_limits<T>::is_integer ? Matrix<float, M, N>(v) : v);
		return *this;
	}

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> & Matrix<T, M, N, enabled>::operator&=(const Matrix<T, M, N, enabled> & v)
	{
		std::valarray<T>::operator&=(v);
		return *this;
	}

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> & Matrix<T, M, N, enabled>::operator|=(const Matrix<T, M, N, enabled> & v)
	{
		std::valarray<T>::operator|=(v);
		return *this;
	}

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> & Matrix<T, M, N, enabled>::operator^=(const Matrix<T, M, N, enabled> & v)
	{
		std::valarray<T>::operator^=(v);
		return *this;
	}

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> & Matrix<T, M, N, enabled>::operator<<=(const Matrix<T, M, N, enabled> & v)
	{
		std::valarray<T>::operator<<=(v);
		return *this;
	}

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> & Matrix<T, M, N, enabled>::operator>>=(const Matrix<T, M, N, enabled> & v)
	{
		std::valarray<T>::operator>>=(v);
		return *this;
	}

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> & Matrix<T, M, N, enabled>::operator+=(const T & val)
	{
		std::valarray<T>::operator+=(val);
		return *this;
	}

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> & Matrix<T, M, N, enabled>::operator-=(const T & val)
	{
		std::valarray<T>::operator-=(val);
		return *this;
	}

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> & Matrix<T, M, N, enabled>::operator*=(const T & val)
	{
		std::valarray<T>::operator*=(val);
		return *this;
	}

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> & Matrix<T, M, N, enabled>::operator/=(const T & val)
	{
		if (val == 0) {
			throw DivideByZeroException("Matrix<T, M, N, enabled>::operator/=(const T & val)");
		}
		std::valarray<T>::operator/=(val);
		return *this;
	}

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> & Matrix<T, M, N, enabled>::operator%=(const T & val)
	{
		if (val == 0) {
			throw DivideByZeroException("Matrix<T, M, N, enabled>::operator%=(const T & val)");
		}
		std::valarray<T>::operator%=(val);
		return *this;
	}

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> & Matrix<T, M, N, enabled>::operator&=(const T & val)
	{
		std::valarray<T>::operator&=(val);
		return *this;
	}

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> & Matrix<T, M, N, enabled>::operator|=(const T & val)
	{
		std::valarray<T>::operator|=(val);
		return *this;
	}

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> & Matrix<T, M, N, enabled>::operator^=(const T & val)
	{
		std::valarray<T>::operator^=(val);
		return *this;
	}

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> & Matrix<T, M, N, enabled>::operator<<=(const T & val)
	{
		std::valarray<T>::operator<<=(val);
		return *this;
	}

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> & Matrix<T, M, N, enabled>::operator>>=(const T & val)
	{
		std::valarray<T>::operator>>=(val);
		return *this;
	}

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Vector<T, M> Matrix<T, M, N, enabled>::operator*=(const Vector<T, M> & v) const
	{
		Vector<T, M> result;
		for (unsigned int i = 0; i < M; ++i) {
			result[i] = (this->row(i) * v).sum();
		}
		return result;
	}

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> Matrix<T, M, N, enabled>::apply(T func(T)) const { return Matrix<T, M, N, enabled>(std::move(std::valarray<T>::apply(func))); }

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> Matrix<T, M, N, enabled>::apply(T func(const T&)) const { return Matrix<T, M, N, enabled>(std::move(std::valarray<T>::apply(func))); }

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> Matrix<T, M, N, enabled>::operator+(const Matrix<T, M, N, enabled> & rhs) const
		{ return Matrix<T, M, N, enabled>(std::move(std::operator+(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> Matrix<T, M, N, enabled>::operator-(const Matrix<T, M, N, enabled> & rhs) const
		{ return Matrix<T, M, N, enabled>(std::move(std::operator-(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> Matrix<T, M, N, enabled>::operator*(const Matrix<T, M, N, enabled> & rhs) const
	{ 
		Matrix<T, M, N, enabled> result;
		for (unsigned int j = 0; j < N; ++j) {
			for (unsigned int i = 0; i < M; ++i) {
				result(i, j) = (this->row(i) * rhs.column(j)).sum();
			}
		}
		return result;
	}

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> Matrix<T, M, N, enabled>::operator/(const Matrix<T, M, N, enabled> & rhs) const
	{
		if (rhs == 0) {
			throw DivideByZeroException("Matrix<T, M, N, enabled>::operator/(const Matrix<T, M, N, enabled> & rhs)");
		}
		return Matrix<T, M, N, enabled>(std::move(std::operator/(*this, rhs)));
	}

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> Matrix<T, M, N, enabled>::operator%(const Matrix<T, M, N, enabled> & rhs) const
	{
		if (rhs == 0) {
			throw DivideByZeroException("Matrix<T, M, N, enabled>::operator%(const Matrix<T, M, N, enabled> & rhs)");
		}
		return Matrix<T, M, N, enabled>(std::move(std::operator%(*this, rhs)));
	}

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> Matrix<T, M, N, enabled>::operator&(const Matrix<T, M, N, enabled> & rhs) const
		{ return Matrix<T, M, N, enabled>(std::move(std::operator&(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> Matrix<T, M, N, enabled>::operator|(const Matrix<T, M, N, enabled> & rhs) const
		{ return Matrix<T, M, N, enabled>(std::move(std::operator|(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> Matrix<T, M, N, enabled>::operator^(const Matrix<T, M, N, enabled> & rhs) const
		{ return Matrix<T, M, N, enabled>(std::move(std::operator^(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> Matrix<T, M, N, enabled>::operator<<(const Matrix<T, M, N, enabled> & rhs) const
		{ return Matrix<T, M, N, enabled>(std::move(std::operator<<(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> Matrix<T, M, N, enabled>::operator>>(const Matrix<T, M, N, enabled> & rhs) const
		{ return Matrix<T, M, N, enabled>(std::move(std::operator>>(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> Matrix<T, M, N, enabled>::operator&&(const Matrix<T, M, N, enabled> & rhs) const
		{ return Matrix<T, M, N, enabled>(std::move(std::operator&&(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> Matrix<T, M, N, enabled>::operator||(const Matrix<T, M, N, enabled> & rhs) const
		{ return Matrix<T, M, N, enabled>(std::move(std::operator||(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> Matrix<T, M, N, enabled>::operator+(const T & rhs) const
		{ return Matrix<T, M, N, enabled>(std::move(std::operator+(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> Matrix<T, M, N, enabled>::operator-(const T & rhs) const
		{ return Matrix<T, M, N, enabled>(std::move(std::operator-(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Vector<T, N> Matrix<T, M, N, enabled>::operator*(const Vector<T, N> & rhs) const
	{
		Vector<T, N> result;
		for (auto i = 0; i < N; ++i) {
			result[i] = (this->row(i) * rhs).sum();
		}
		return result;
	}

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> Matrix<T, M, N, enabled>::operator*(const T & rhs) const
		{ return Matrix<T, M, N, enabled>(std::move(std::operator*(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> Matrix<T, M, N, enabled>::operator/(const T & rhs) const
	{
		if (rhs == 0) {
			throw DivideByZeroException("Matrix<T, M, N, enabled>::operator/(const T & rhs)");
		}
		return Matrix<T, M, N, enabled>(std::move(std::operator/(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> Matrix<T, M, N, enabled>::operator%(const T & rhs) const
	{
		if (rhs == 0) {
			throw DivideByZeroException("Matrix<T, M, N, enabled>::operator%(const T & rhs)");
		}
		return Matrix<T, M, N, enabled>(std::move(std::operator%(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> Matrix<T, M, N, enabled>::operator&(const T & rhs) const
		{ return Matrix<T, M, N, enabled>(std::move(std::operator&(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> Matrix<T, M, N, enabled>::operator|(const T & rhs) const
		{ return Matrix<T, M, N, enabled>(std::move(std::operator|(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> Matrix<T, M, N, enabled>::operator^(const T & rhs) const
		{ return Matrix<T, M, N, enabled>(std::move(std::operator^(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> Matrix<T, M, N, enabled>::operator<<(const T & rhs) const
		{ return Matrix<T, M, N, enabled>(std::move(std::operator<<(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> Matrix<T, M, N, enabled>::operator>>(const T & rhs) const
		{ return Matrix<T, M, N, enabled>(std::move(std::operator>>(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> Matrix<T, M, N, enabled>::operator&&(const T & rhs) const
		{ return Matrix<T, M, N, enabled>(std::move(std::operator&&(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> Matrix<T, M, N, enabled>::operator||(const T & rhs) const
	{
		return Matrix<T, M, N, enabled>(std::move(std::operator||(*this, rhs)));
	}

	template <class T, unsigned int M, unsigned int N, typename enabled>
	bool Matrix<T, M, N, enabled>::operator==(const Matrix<T, M, N, enabled> & rhs) const { return std::operator==(*this, rhs).min(); }

	template <class T, unsigned int M, unsigned int N, typename enabled>
	Matrix<bool, M, N> Matrix<T, M, N, enabled>::operator!=(const Matrix<T, M, N, enabled> & rhs)
		{ return Matrix<T, M, N, enabled>(std::move(std::operator!=(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N, typename enabled>
	Matrix<bool, M, N> Matrix<T, M, N, enabled>::operator<(const Matrix<T, M, N, enabled> & rhs)
		{ return Matrix<T, M, N, enabled>(std::move(std::operator<(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N, typename enabled>
	Matrix<bool, M, N> Matrix<T, M, N, enabled>::operator<=(const Matrix<T, M, N, enabled> & rhs)
		{ return Matrix<T, M, N, enabled>(std::move(std::operator<=(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N, typename enabled>
	Matrix<bool, M, N> Matrix<T, M, N, enabled>::operator>(const Matrix<T, M, N, enabled> & rhs)
		{ return Matrix<T, M, N, enabled>(std::move(std::operator>(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N, typename enabled>
	Matrix<bool, M, N> Matrix<T, M, N, enabled>::operator>=(const Matrix<T, M, N, enabled> & rhs)
		{ return Matrix<T, M, N, enabled>(std::move(std::operator>=(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N, typename enabled>
	Matrix<bool, M, N> Matrix<T, M, N, enabled>::operator==(const T & rhs)
		{ return Matrix<T, M, N, enabled>(std::move(std::operator==(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N, typename enabled>
	Matrix<bool, M, N> Matrix<T, M, N, enabled>::operator!=(const T & rhs)
		{ return Matrix<T, M, N, enabled>(std::move(std::operator!=(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N, typename enabled>
	Matrix<bool, M, N> Matrix<T, M, N, enabled>::operator<(const T & rhs)
		{ return Matrix<T, M, N, enabled>(std::move(std::operator<(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N, typename enabled>
	Matrix<bool, M, N> Matrix<T, M, N, enabled>::operator<=(const T & rhs)
		{ return Matrix<T, M, N, enabled>(std::move(std::operator<=(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N, typename enabled>
	Matrix<bool, M, N> Matrix<T, M, N, enabled>::operator>(const T & rhs)
		{ return Matrix<T, M, N, enabled>(std::move(std::operator>(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N, typename enabled>
	Matrix<bool, M, N> Matrix<T, M, N, enabled>::operator>=(const T & rhs)
		{ return Matrix<T, M, N, enabled>(std::move(std::operator>=(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> Matrix<T, M, N, enabled>::abs() const
		{ return Matrix<T, M, N, enabled>(std::move(std::abs(*this))); }

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> Matrix<T, M, N, enabled>::exp() const
		{ return Matrix<T, M, N, enabled>(std::move(std::exp(*this))); }

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> Matrix<T, M, N, enabled>::log() const
		{ return Matrix<T, M, N, enabled>(std::move(std::log(*this))); }

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> Matrix<T, M, N, enabled>::log10() const
		{ return Matrix<T, M, N, enabled>(std::move(std::log10(*this))); }

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> Matrix<T, M, N, enabled>::pow(const Matrix<T, M, N, enabled> & exp) const
		{ return Matrix<T, M, N, enabled>(std::move(std::pow(*this, exp))); }

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> Matrix<T, M, N, enabled>::pow(const T & exp) const
		{ return Matrix<T, M, N, enabled>(std::move(std::pow(*this, exp))); }

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> Matrix<T, M, N, enabled>::sqrt() const
		{ return Matrix<T, M, N, enabled>(std::move(std::sqrt(*this))); }

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> Matrix<T, M, N, enabled>::sin() const
		{ return Matrix<T, M, N, enabled>(std::move(std::sin(*this))); }

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> Matrix<T, M, N, enabled>::cos() const
		{ return Matrix<T, M, N, enabled>(std::move(std::cos(*this))); }

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> Matrix<T, M, N, enabled>::tan() const
		{ return Matrix<T, M, N, enabled>(std::move(std::tan(*this))); }

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> Matrix<T, M, N, enabled>::asin() const
		{ return Matrix<T, M, N, enabled>(std::move(std::asin(*this))); }

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> Matrix<T, M, N, enabled>::acos() const
		{ return Matrix<T, M, N, enabled>(std::move(std::acos(*this))); }

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> Matrix<T, M, N, enabled>::atan() const
		{ return Matrix<T, M, N, enabled>(std::move(std::atan(*this))); }

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> Matrix<T, M, N, enabled>::atan2(const Matrix<T, M, N, enabled> & x) const
		{ return Matrix<T, M, N, enabled>(std::move(std::atan2(*this, x))); }

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> Matrix<T, M, N, enabled>::atan2(const T & x) const
		{ return Matrix<T, M, N, enabled>(std::move(std::atan2(*this, x))); }

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> Matrix<T, M, N, enabled>::sinh() const
		{ return Matrix<T, M, N, enabled>(std::move(std::sinh(*this))); }

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> Matrix<T, M, N, enabled>::cosh() const
		{ return Matrix<T, M, N, enabled>(std::move(std::cosh(*this))); }

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<T, M, N, enabled> Matrix<T, M, N, enabled>::tanh() const
		{ return Matrix<T, M, N, enabled>(std::move(std::tanh(*this))); }

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline T Matrix<T, M, N, enabled>::trace() const
	{
		static_assert(M == N, "It is not possible to compute the trace of a non-square matrix.");
		return std::valarray<T>::operator[std::slice(0, M, M + 1)].sum();
	}

	template <class T, unsigned int M, unsigned int N, typename enabled>
	template <typename>
	inline double Matrix<T, M, N, enabled>::determinant() const
	{
		ece::determinant<T, M> det;
		return det(*this);
	}

	template <class T, unsigned int M, unsigned int N, typename enabled>
	template <typename>
	inline Matrix<T, M, N, enabled> Matrix<T, M, N, enabled>::transpose() const
	{
		ece::transpose<T, M> transposed;
		return transposed(*this);
	}

	template <class T, unsigned int M, unsigned int N, typename enabled>
	template <typename>
	inline Matrix<double, M, N> Matrix<T, M, N, enabled>::inverse(bool & invertible) const
	{
		ece::inverse<T, M> inversed;
		return inversed(*this, invertible);
	}

	template <class T, unsigned int M, unsigned int N, typename enabled>
	inline void Matrix<T, M, N, enabled>::fill(const T & value) { std::valarray<T>::operator=(value); }

	template<class T, unsigned int Size>
	inline double determinant<T, Size>::operator()(const Matrix<T, Size, Size> & matrix) const
	{
		return 0.0;
	}

	template<class T, unsigned int Size>
	inline Matrix<T, Size, Size> transpose<T, Size>::operator()(const Matrix<T, Size, Size> & matrix) const
	{
		return Matrix<T, Size, Size>();
	}

	template<class T, unsigned int Size>
	inline Matrix<double, Size, Size> inverse<T, Size>::operator()(const Matrix<T, Size, Size> & matrix, bool & invertible) const
	{
		invertible = false;
		return Matrix<double, Size, Size>();
	}
}