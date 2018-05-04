#include "matrix.hpp"
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
	template <class E, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<E, M, N, enabled> Matrix<E, M, N, enabled>::Identity()
	{
		Matrix<E, M, N, enabled> tmp;
		for (unsigned int i = 0; i < M; ++i) {
			tmp[i][i] = 1;
		}
		return  tmp;
	}

	template<typename E, unsigned int M, unsigned int N, typename enabled>
	inline constexpr Matrix<E, M, N, enabled>::Matrix() noexcept: LinearExpression<Matrix<E, M, N, enabled>>(), _elements() { this->_elements.fill(0); }

	template <typename E, unsigned int M, unsigned int N, typename enabled>
	inline constexpr Matrix<E, M, N, enabled>::Matrix(const E value) noexcept : LinearExpression<Matrix<E, M, N, enabled>>(), _elements() { this->_elements.fill(value); }

	template <typename E, unsigned int M, unsigned int N, typename enabled>
	template <class E2, typename enabledBis>
	Matrix<E, M, N, enabled>::Matrix(const E2 & rhs) noexcept : LinearExpression<Matrix<E, M, N, enabled>>(), _elements()
	{
		for (unsigned int i = 0; i < rhs.size(); ++i) {
			this->_elements[i] = rhs.cell(i);
		}
	}

	template <typename E, unsigned int M, unsigned int N, typename enabled>
	Matrix<E, M, N, enabled>::Matrix(std::initializer_list<E> il) noexcept: LinearExpression<Matrix<E, M, N, enabled>>(), _elements()
	{
		for (unsigned int i = 0; i < il.size(); ++i) {
			this->_elements[i] = *(il.begin() + i);
		}
	}

	template <typename E, unsigned int M, unsigned int N, typename enabled>
	Matrix<E, M, N, enabled> & Matrix<E, M, N, enabled>::operator=(const LinearExpression<Matrix<E, M, N, enabled>> & rhs) noexcept
	{
		for (unsigned int i = 0; i < rhs.size(); ++i) {
			this->_elements[i] = rhs[i];
		}
		return *this;
	}

	template <class E, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<E, M, N, enabled> & Matrix<E, M, N, enabled>::setIdentity()
	{
		for (unsigned int i = 0; i < M; ++i) {
			for (unsigned int j = 0; j < N; ++j) {
				(*this)[i][j] = i == j ? 1 : 0;
			}
		}
		return *this;
	}

	template <typename E, unsigned int M, unsigned int N, typename enabled>
	inline Slice<Matrix<E, M, N, enabled>> Matrix<E, M, N, enabled>::operator[](const unsigned int index) { return Slice<Matrix<E, M, N, enabled>>(this, N * index, M, 1); }

	template <typename E, unsigned int M, unsigned int N, typename enabled>
	inline Slice<Matrix<E, M, N, enabled>> Matrix<E, M, N, enabled>::operator[](const unsigned int index) const { return Slice<Matrix<E, M, N, enabled>>(this, N * index, M, 1); }

	template <typename E, unsigned int M, unsigned int N, typename enabled>
	inline Slice<Matrix<E, M, N, enabled>> Matrix<E, M, N, enabled>::row(const unsigned int index) { return Slice<Matrix<E, M, N, enabled>>(this, N * index, M, 1); }

	template <typename E, unsigned int M, unsigned int N, typename enabled>
	inline Slice<Matrix<E, M, N, enabled>> Matrix<E, M, N, enabled>::row(const unsigned int index) const { return Slice<Matrix<E, M, N, enabled>>(this, N * index, M, 1); }

	template <typename E, unsigned int M, unsigned int N, typename enabled>
	inline Slice<Matrix<E, M, N, enabled>> Matrix<E, M, N, enabled>::column(const unsigned int index) { return Slice<Matrix<E, M, N, enabled>>(this, index, M, N); }

	template <typename E, unsigned int M, unsigned int N, typename enabled>
	inline Slice<Matrix<E, M, N, enabled>> Matrix<E, M, N, enabled>::column(const unsigned int index) const { return Slice<Matrix<E, M, N, enabled>>(this, index, M, N); }

	template <typename E, unsigned int M, unsigned int N, typename enabled>
	Filter<Matrix<E, M, N, enabled>, M * N, enabled> Matrix<E, M, N, enabled>::operator[](Matrix<bool, M, N, enabled> && filter) { return Filter<Matrix<E, M, N, enabled>, M * N>(this, std::move(filter)); }

	template <typename E, unsigned int M, unsigned int N, typename enabled>
	Filter<Matrix<E, M, N, enabled>, M * N, enabled> Matrix<E, M, N, enabled>::operator[](Matrix<bool, M, N, enabled> && filter) const { return Filter<Matrix<E, M, N, enabled>, M * N>(this, std::move(filter)); }

	template <typename E, unsigned int M, unsigned int N, typename enabled>
	Filter<Matrix<E, M, N, enabled>, M * N, enabled> Matrix<E, M, N, enabled>::operator[](std::initializer_list<unsigned int> && il) { return Filter<Matrix<E, M, N, enabled>, M * N>(this, std::move(il)); }

	template <typename E, unsigned int M, unsigned int N, typename enabled>
	Filter<Matrix<E, M, N, enabled>, M * N, enabled> Matrix<E, M, N, enabled>::operator[](std::initializer_list<unsigned int> && il) const { return Filter<Matrix<E, M, N, enabled>, M * N>(this, std::move(il)); }

	template <typename E, unsigned int M, unsigned int N, typename enabled>
	inline E Matrix<E, M, N, enabled>::cell(const unsigned int index) const { return this->_elements[index]; }

	template <typename E, unsigned int M, unsigned int N, typename enabled>
	inline E & Matrix<E, M, N, enabled>::cell(const unsigned int index) { return this->_elements[index]; }

	template <typename E, unsigned int M, unsigned int N, typename enabled>
	inline constexpr E * Matrix<E, M, N, enabled>::data() noexcept { return this->_elements.data(); }

	template <typename E, unsigned int M, unsigned int N, typename enabled>
	inline constexpr const E * Matrix<E, M, N, enabled>::data() const noexcept { return this->_elements.data(); }

	template <typename E, unsigned int M, unsigned int N, typename enabled>
	inline constexpr unsigned int Matrix<E, M, N, enabled>::size() const noexcept { return M * N; }

	template <typename E, unsigned int M, unsigned int N, typename enabled>
	inline auto Matrix<E, M, N, enabled>::begin() noexcept { return this->_elements.begin(); }

	template <typename E, unsigned int M, unsigned int N, typename enabled>
	inline auto Matrix<E, M, N, enabled>::end() noexcept { return this->_elements.end(); }

	template <typename E, unsigned int M, unsigned int N, typename enabled>
	inline E Matrix<E, M, N, enabled>::min() const noexcept { return std::min_element(this->_elements.begin(), this->_elements.end()); }

	template <typename E, unsigned int M, unsigned int N, typename enabled>
	inline E Matrix<E, M, N, enabled>::max() const noexcept { return std::max_element(this->_elements.begin(), this->_elements.end()); }

	template <typename E, unsigned int M, unsigned int N, typename enabled>
	inline E Matrix<E, M, N, enabled>::sum() const noexcept { return std::accumulate(this->_elements.begin(), this->_elements.end(), static_cast<E>(0)); }

	template <typename E, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<E, M, N, enabled> Matrix<E, M, N, enabled>::shift(const int count) const noexcept
	{
		Matrix<E, M, N, enabled> result;
		for (unsigned int i = 0; i < M * N; ++i) {
			result[i] = count + i < 0 || count + i >= M * N ? 0 : this->_elements[count + i];
		}
		return std::move(result);
	}

	template <typename E, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<E, M, N, enabled> Matrix<E, M, N, enabled>::cshift(const int count) const noexcept
	{
		Matrix<E, M, N, enabled> result;
		for (unsigned int i = 0; i < M * N; ++i) {
			result[i] = (count + i < 0 || count + i >= M * N) ? (count + i < 0 ? this->_elements[M * N + count + i] : this->_elements[(count + i) % (M * N)]) : this->_elements[count + i];
		}
		return std::move(result);
	}

	template <typename E, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<E, M, N, enabled> Matrix<E, M, N, enabled>::apply(E func(E)) const noexcept
	{
		Matrix<E, M, N, enabled> result;
		for (unsigned int i = 0; i < M * N; ++i) {
			result[i] = func(this->_elements[i]);
		}
		return std::move(result);
	}

	template <typename E, unsigned int M, unsigned int N, typename enabled>
	inline Matrix<E, M, N, enabled> Matrix<E, M, N, enabled>::apply(E func(const E &)) const noexcept
	{
		Matrix<E, M, N, enabled> result;
		for (unsigned int i = 0; i < M * N; ++i) {
			result[i] = func(this->_elements[i]);
		}
		return std::move(result);
	}

	template <typename E, unsigned int M, unsigned int N, typename enabled>
	template <typename>
	inline E Matrix<E, M, N, enabled>::trace() const
	{
		E result = 0;
		for (unsigned int i = 0; i < M; ++i) {
			result += this->_elements[i * M + i];
		}
		return result;
	}

	template <class E, unsigned int M, unsigned int N, typename enabled>
	template <typename>
	inline double Matrix<E, M, N, enabled>::determinant() const
	{
		ece::determinant<E, M> det;
		return det(*this);
	}

	template <class E, unsigned int M, unsigned int N, typename enabled>
	template <typename>
	inline Matrix<E, M, N, enabled> Matrix<E, M, N, enabled>::transpose() const
	{
		ece::transpose<E, M> transposed;
		return transposed(*this);
	}

	template <class E, unsigned int M, unsigned int N, typename enabled>
	template <typename>
	inline Matrix<double, M, N> Matrix<E, M, N, enabled>::inverse(bool & invertible) const
	{
		ece::inverse<E, M> inversed;
		return inversed(*this, invertible);
	}

	template <class E, unsigned int M, unsigned int N, typename enabled>
	inline void Matrix<E, M, N, enabled>::fill(const E & value)
	{
		for (unsigned int i = 0; i < M * N; ++i) {
			this->_elements[i] = value;
		}
	}

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

	template<typename E1, typename E2, unsigned int Size>
	Matrix<E1, Size, Size> & operator*=(Matrix<E1, Size, Size>& lhs, const Matrix<E2, Size, Size>& rhs)
	{
		Matrix<E1, Size, Size> result;
		for (unsigned int i = 0; i < Size; ++i) {
			for (unsigned int j = 0; j < Size; ++j) {
				for (unsigned int k = 0; k < Size; ++k) {
					result[i][j] += lhs.row(i)[k] * static_cast<E1>(rhs.column(j)[k]);
				}
			}
		}
		lhs = std::move(result);
		return lhs;
	}

	template<typename E1, typename E2, unsigned int Size>
	Matrix<E1, Size, Size> operator*(const Matrix<E1, Size, Size>& lhs, const Matrix<E2, Size, Size>& rhs)
	{
		Matrix<E1, Size, Size> result;
		for (unsigned int i = 0; i < Size; ++i) {
			for (unsigned int j = 0; j < Size; ++j) {
				for (unsigned int k = 0; k < Size; ++k) {
					result[i][j] += lhs.row(i)[k] * static_cast<E1>(rhs.column(j)[k]);
				}
			}
		}
		return std::move(result);
	}

	template<typename E1, typename E2, unsigned int Size>
	Vector<E1, Size> operator*(const Matrix<E1, Size, Size>& lhs, const Vector<E2, Size>& rhs)
	{
		Vector<E1, Size> result;
		for (unsigned int i = 0; i < Size; ++i) {
			for (unsigned int j = 0; j < Size; ++j) {
				result[j] += lhs.row(j)[i] * static_cast<E1>(rhs[i]);
			}
		}
		return std::move(result);
	}
}
