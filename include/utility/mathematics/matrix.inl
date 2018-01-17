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
	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::Identity()
	{
		Matrix<T, M, N> tmp;
		tmp[std::slice(0, M, M + 1)] = 1;
		return  tmp;
	}

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N>::Matrix(const std::initializer_list<T> & il): std::valarray<T>(il) {}

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N>::Matrix(std::valarray<T> && move): std::valarray<T>(move) {}

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> & Matrix<T, M, N>::operator=(const std::initializer_list<T> & il) { std::valarray<T>::operator=(il); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> & Matrix<T, M, N>::setIdentity()
	{
		std::valarray<T>::operator=(0);
		(*this)[std::slice(0, M, M + 1)] = 1;
		return *this;
	}

	template <class T, unsigned int M, unsigned int N>
	inline Vector<T, M> Matrix<T, M, N>::operator[](const unsigned int index) const
		{ return Vector<T, M>(std::move(std::valarray<T>::operator[](std::slice(index, M, 1)))); }

	template <class T, unsigned int M, unsigned int N>
	inline Vector<T, M> Matrix<T, M, N>::operator[](const unsigned int index)
		{ return Vector<T, M>(std::move(std::valarray<T>::operator[](std::slice(index, M, 1)))); }

	template <class T, unsigned int M, unsigned int N>
	std::slice_array<T> Matrix<T, M, N>::operator[](std::slice slicearr)
		{ return std::valarray<T>::operator[](slicearr); }

	template <class T, unsigned int M, unsigned int N>
	inline Vector<T, M> Matrix<T, M, N>::row(const unsigned int index) const
		{ return Vector<T, M>(std::move(std::valarray<T>::operator[](std::slice(index, M, 1)))); }

	template <class T, unsigned int M, unsigned int N>
	inline Vector<T, M> Matrix<T, M, N>::row(const unsigned int index)
		{ return Vector<T, M>(std::move(std::valarray<T>::operator[](std::slice(index, M, 1)))); }

	template <class T, unsigned int M, unsigned int N>
	inline Vector<T, N> Matrix<T, M, N>::column(const unsigned int index) const
		{ return Vector<T, N>(std::move(std::valarray<T>::operator[](std::slice(index, N, M)))); }

	template <class T, unsigned int M, unsigned int N>
	inline Vector<T, N> Matrix<T, M, N>::column(const unsigned int index)
		{ return Vector<T, N>(std::move(std::valarray<T>::operator[](std::slice(index, N, M)))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::operator+() const noexcept { return Matrix<T, M, N>(std::move(std::valarray<T>::operator+())); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::operator-() const noexcept { return Matrix<T, M, N>(std::move(std::valarray<T>::operator-())); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::operator~() const noexcept { return Matrix<T, M, N>(std::move(std::valarray<T>::operator~())); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<bool, M, N> Matrix<T, M, N>::operator!() const noexcept { return Matrix<T, M, N>(std::move(std::valarray<T>::operator!())); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> & Matrix<T, M, N>::operator+=(const Matrix<T, M, N> & v)
	{
		std::valarray<T>::operator+=(v);
		return *this;
	}

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> & Matrix<T, M, N>::operator-=(const Matrix<T, M, N> & v)
	{
		std::valarray<T>::operator-=(v);
		return *this;
	}

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> & Matrix<T, M, N>::operator*=(const Matrix<T, M, N> & v)
	{
		Matrix<T, M, N> result;
		for (unsigned int j = 0; j < N; ++j) {
			for (unsigned int i = 0; i < M; ++i) {
				result[i][j] = (this->row(i) * v.column(j)).sum();
			}
		}
		this->operator=(std::move(result));
		return *this;
	}

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> & Matrix<T, M, N>::operator/=(const Matrix<T, M, N> & v)
	{
		std::valarray<T>::operator/=(v);
		return *this;
	}

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> & Matrix<T, M, N>::operator%=(const Matrix<T, M, N> & v)
	{
		std::valarray<T>::operator%=(v);
		return *this;
	}

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> & Matrix<T, M, N>::operator&=(const Matrix<T, M, N> & v)
	{
		std::valarray<T>::operator&=(v);
		return *this;
	}

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> & Matrix<T, M, N>::operator|=(const Matrix<T, M, N> & v)
	{
		std::valarray<T>::operator|=(v);
		return *this;
	}

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> & Matrix<T, M, N>::operator^=(const Matrix<T, M, N> & v)
	{
		std::valarray<T>::operator^=(v);
		return *this;
	}

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> & Matrix<T, M, N>::operator<<=(const Matrix<T, M, N> & v)
	{
		std::valarray<T>::operator<<=(v);
		return *this;
	}

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> & Matrix<T, M, N>::operator>>=(const Matrix<T, M, N> & v)
	{
		std::valarray<T>::operator>>=(v);
		return *this;
	}

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> & Matrix<T, M, N>::operator+=(const T & val)
	{
		std::valarray<T>::operator+=(val);
		return *this;
	}

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> & Matrix<T, M, N>::operator-=(const T & val)
	{
		std::valarray<T>::operator-=(val);
		return *this;
	}

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> & Matrix<T, M, N>::operator*=(const T & val)
	{
		std::valarray<T>::operator*=(val);
		return *this;
	}

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> & Matrix<T, M, N>::operator/=(const T & val)
	{
		std::valarray<T>::operator/=(val);
		return *this;
	}

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> & Matrix<T, M, N>::operator%=(const T & val)
	{
		std::valarray<T>::operator%=(val);
		return *this;
	}

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> & Matrix<T, M, N>::operator&=(const T & val)
	{
		std::valarray<T>::operator&=(val);
		return *this;
	}

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> & Matrix<T, M, N>::operator|=(const T & val)
	{
		std::valarray<T>::operator|=(val);
		return *this;
	}

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> & Matrix<T, M, N>::operator^=(const T & val)
	{
		std::valarray<T>::operator^=(val);
		return *this;
	}

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> & Matrix<T, M, N>::operator<<=(const T & val)
	{
		std::valarray<T>::operator<<=(val);
		return *this;
	}

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> & Matrix<T, M, N>::operator>>=(const T & val)
	{
		std::valarray<T>::operator>>=(val);
		return *this;
	}

	template <class T, unsigned int M, unsigned int N>
	inline Vector<T, M> Matrix<T, M, N>::operator*=(const Vector<T, M> & v) const
	{
		Vector<T, M> result;
		for (unsigned int i = 0; i < M; ++i) {
			result[i] = (this->row(i) * v).sum();
		}
		return result;
	}

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::apply(T func(T)) const { return Matrix<T, M, N>(std::move(std::valarray<T>::apply(func))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::apply(T func(const T&)) const { return Matrix<T, M, N>(std::move(std::valarray<T>::apply(func))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::operator+(const Matrix<T, M, N> & rhs) const
		{ return Matrix<T, M, N>(std::move(std::operator+(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::operator-(const Matrix<T, M, N> & rhs) const
		{ return Matrix<T, M, N>(std::move(std::operator-(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::operator*(const Matrix<T, M, N> & rhs) const
	{ 
		Matrix<T, M, N> result;
		for (unsigned int j = 0; j < N; ++j) {
			for (unsigned int i = 0; i < M; ++i) {
				result[i][j] = (this->row(i) * rhs.column(j)).sum();
			}
		}
		return result;
	}

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::operator/(const Matrix<T, M, N> & rhs) const
		{ return Matrix<T, M, N>(std::move(std::operator/(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::operator%(const Matrix<T, M, N> & rhs) const
		{ return Matrix<T, M, N>(std::move(std::operator%(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::operator&(const Matrix<T, M, N> & rhs) const
		{ return Matrix<T, M, N>(std::move(std::operator&(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::operator|(const Matrix<T, M, N> & rhs) const
		{ return Matrix<T, M, N>(std::move(std::operator|(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::operator^(const Matrix<T, M, N> & rhs) const
		{ return Matrix<T, M, N>(std::move(std::operator^(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::operator<<(const Matrix<T, M, N> & rhs) const
		{ return Matrix<T, M, N>(std::move(std::operator<<(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::operator>>(const Matrix<T, M, N> & rhs) const
		{ return Matrix<T, M, N>(std::move(std::operator>>(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::operator&&(const Matrix<T, M, N> & rhs) const
		{ return Matrix<T, M, N>(std::move(std::operator&&(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::operator||(const Matrix<T, M, N> & rhs) const
		{ return Matrix<T, M, N>(std::move(std::operator||(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::operator+(const T & rhs) const
		{ return Matrix<T, M, N>(std::move(std::operator+(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::operator-(const T & rhs) const
		{ return Matrix<T, M, N>(std::move(std::operator-(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N>
	inline Vector<T, N> Matrix<T, M, N>::operator*(const Vector<T, N> & rhs) const
	{
		Vector<T, N> result;
		for (auto i = 0; i < N; ++i) {
			result[i] = (this->row(i) * rhs).sum();
		}
		return result;
	}

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::operator*(const T & rhs) const
		{ return Matrix<T, M, N>(std::move(std::operator*(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::operator/(const T & rhs) const
		{ return Matrix<T, M, N>(std::move(std::operator/(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::operator%(const T & rhs) const
		{ return Matrix<T, M, N>(std::move(std::operator%(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::operator&(const T & rhs) const
		{ return Matrix<T, M, N>(std::move(std::operator&(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::operator|(const T & rhs) const
		{ return Matrix<T, M, N>(std::move(std::operator|(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::operator^(const T & rhs) const
		{ return Matrix<T, M, N>(std::move(std::operator^(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::operator<<(const T & rhs) const
		{ return Matrix<T, M, N>(std::move(std::operator<<(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::operator>>(const T & rhs) const
		{ return Matrix<T, M, N>(std::move(std::operator>>(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::operator&&(const T & rhs) const
		{ return Matrix<T, M, N>(std::move(std::operator&&(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::operator||(const T & rhs) const
	{
		return Matrix<T, M, N>(std::move(std::operator||(*this, rhs)));
	}

	template <class T, unsigned int M, unsigned int N>
	bool Matrix<T, M, N>::operator==(const Matrix<T, M, N> & rhs) const { return std::operator==(*this, rhs).min(); }

	template <class T, unsigned int M, unsigned int N>
	Matrix<bool, M, N> Matrix<T, M, N>::operator!=(const Matrix<T, M, N> & rhs)
		{ return Matrix<T, M, N>(std::move(std::operator!=(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N>
	Matrix<bool, M, N> Matrix<T, M, N>::operator<(const Matrix<T, M, N> & rhs)
		{ return Matrix<T, M, N>(std::move(std::operator<(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N>
	Matrix<bool, M, N> Matrix<T, M, N>::operator<=(const Matrix<T, M, N> & rhs)
		{ return Matrix<T, M, N>(std::move(std::operator<=(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N>
	Matrix<bool, M, N> Matrix<T, M, N>::operator>(const Matrix<T, M, N> & rhs)
		{ return Matrix<T, M, N>(std::move(std::operator>(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N>
	Matrix<bool, M, N> Matrix<T, M, N>::operator>=(const Matrix<T, M, N> & rhs)
		{ return Matrix<T, M, N>(std::move(std::operator>=(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N>
	Matrix<bool, M, N> Matrix<T, M, N>::operator==(const T & rhs)
		{ return Matrix<T, M, N>(std::move(std::operator==(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N>
	Matrix<bool, M, N> Matrix<T, M, N>::operator!=(const T & rhs)
		{ return Matrix<T, M, N>(std::move(std::operator!=(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N>
	Matrix<bool, M, N> Matrix<T, M, N>::operator<(const T & rhs)
		{ return Matrix<T, M, N>(std::move(std::operator<(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N>
	Matrix<bool, M, N> Matrix<T, M, N>::operator<=(const T & rhs)
		{ return Matrix<T, M, N>(std::move(std::operator<=(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N>
	Matrix<bool, M, N> Matrix<T, M, N>::operator>(const T & rhs)
		{ return Matrix<T, M, N>(std::move(std::operator>(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N>
	Matrix<bool, M, N> Matrix<T, M, N>::operator>=(const T & rhs)
		{ return Matrix<T, M, N>(std::move(std::operator>=(*this, rhs))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::abs() const
		{ return Matrix<T, M, N>(std::move(std::abs(*this))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::exp() const
		{ return Matrix<T, M, N>(std::move(std::exp(*this))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::log() const
		{ return Matrix<T, M, N>(std::move(std::log(*this))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::log10() const
		{ return Matrix<T, M, N>(std::move(std::log10(*this))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::pow(const Matrix<T, M, N> & exp) const
		{ return Matrix<T, M, N>(std::move(std::pow(*this, exp))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::pow(const T & exp) const
		{ return Matrix<T, M, N>(std::move(std::pow(*this, exp))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::sqrt() const
		{ return Matrix<T, M, N>(std::move(std::sqrt(*this))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::sin() const
		{ return Matrix<T, M, N>(std::move(std::sin(*this))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::cos() const
		{ return Matrix<T, M, N>(std::move(std::cos(*this))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::tan() const
		{ return Matrix<T, M, N>(std::move(std::tan(*this))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::asin() const
		{ return Matrix<T, M, N>(std::move(std::asin(*this))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::acos() const
		{ return Matrix<T, M, N>(std::move(std::acos(*this))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::atan() const
		{ return Matrix<T, M, N>(std::move(std::atan(*this))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::atan2(const Matrix<T, M, N> & x) const
		{ return Matrix<T, M, N>(std::move(std::atan2(*this, x))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::atan2(const T & x) const
		{ return Matrix<T, M, N>(std::move(std::atan2(*this, x))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::sinh() const
		{ return Matrix<T, M, N>(std::move(std::sinh(*this))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::cosh() const
		{ return Matrix<T, M, N>(std::move(std::cosh(*this))); }

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::tanh() const
		{ return Matrix<T, M, N>(std::move(std::tanh(*this))); }

	template <class T, unsigned int M, unsigned int N>
	inline T Matrix<T, M, N>::trace() const
	{
		static_assert(M == N, "It is not possible to compute the trace of a non-square matrix.");
		return std::valarray<T>::operator[std::slice(0, M, M + 1)].sum();
	}

	template <class T, unsigned int M, unsigned int N>
	inline T Matrix<T, M, N>::determinant() const
	{
		static_assert(M == N, "It is not possible to compute the determinant of a non-square matrix.");
		return 0;
	}

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<T, M, N> Matrix<T, M, N>::transpose() const
	{
		static_assert(M == N, "It is not possible to compute the transpose matrix of a non-square matrix.");
		return Matrix<T, M, N>();
	}

	template <class T, unsigned int M, unsigned int N>
	inline Matrix<double, M, N> Matrix<T, M, N>::inverse(bool & invertible) const
	{
		static_assert(M == N, "It is not possible to compute the inverse matrix of a non-square matrix.");
		invertible = false;
		return Matrix<double, M, N>();
	}
}