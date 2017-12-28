#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <valarray>

#include "utility/mathematics/vector.hpp"

namespace ece
{
	template <class T, unsigned int M, unsigned int N>
	class Matrix: public std::valarray<T>
	{
	public:
		static inline Matrix<T, M, N> Identity();

		constexpr Matrix() = default;
		inline Matrix(const std::initializer_list<T> & il);
		Matrix(const Matrix<T, M, N> & copy) = default;
		Matrix(Matrix<T, M, N> && move) noexcept = default;
		inline Matrix(std::valarray<T> && move);

		~Matrix() = default;

		Matrix<T, M, N> & operator=(const Matrix<T, M, N> & copy) = default;
		Matrix<T, M, N> & operator=(Matrix<T, M, N> && move) noexcept = default;
		inline Matrix<T, M, N> & operator=(const std::initializer_list<T> & il);

		inline Matrix<T, M, N> & setIdentity();

		inline const Vector<T, M> & operator[](const unsigned int index) const;
		inline Vector<T, M> & operator[](const unsigned int index);
		// inline Matrix<T, M, N> operator[](std::slice_array<T> slicearr) const;
		// inline std::slice_array<T> operator[](std::slice_array<T> slicearr);
		// inline Matrix<T, M, N> operator[](std::gslice_array<T> & gslicearr) const;
		// inline std::gslice_array<T> operator[](std::gslice_array<T> & gslicearr);
		// inline Matrix<T, M, N> operator[](const Matrix<bool, M, N> & maskarr) const;
		// inline std::mask_array<T> operator[](const Matrix<bool, M, N> & maskarr);
		// inline Matrix<T, M, N> operator[](const Matrix<bool, M, N> & indarr) const;
		// inline std::indirect_array<T> operator[](const Matrix<bool, M, N> & indarr);

		inline const Vector<T, M> & row(const unsigned int index) const;
		inline Vector<T, M> & row(const unsigned int index);
		inline const Vector<T, M> & column(const unsigned int index) const;
		inline Vector<T, M> & column(const unsigned int index);

		inline Matrix<T, M, N> operator+() const noexcept;
		inline Matrix<T, M, N> operator-() const noexcept;
		inline Matrix<T, M, N> operator~() const noexcept;
		inline Matrix<bool, M, N> operator!() const noexcept;

		inline Matrix<T, M, N> & operator+=(const Matrix<T, M, N> & v);
		inline Matrix<T, M, N> & operator-=(const Matrix<T, M, N> & v);
		inline Matrix<T, M, N> & operator*=(const Matrix<T, M, N> & v);
		inline Matrix<T, M, N> & operator/=(const Matrix<T, M, N> & v);
		inline Matrix<T, M, N> & operator%=(const Matrix<T, M, N> & v);
		inline Matrix<T, M, N> & operator&=(const Matrix<T, M, N> & v);
		inline Matrix<T, M, N> & operator|=(const Matrix<T, M, N> & v);
		inline Matrix<T, M, N> & operator^=(const Matrix<T, M, N> & v);
		inline Matrix<T, M, N> & operator<<=(const Matrix<T, M, N> & v);
		inline Matrix<T, M, N> & operator>>=(const Matrix<T, M, N> & v);

		inline Matrix<T, M, N> & operator+=(const T & val);
		inline Matrix<T, M, N> & operator-=(const T & val);
		inline Matrix<T, M, N> & operator*=(const T & val);
		inline Matrix<T, M, N> & operator/=(const T & val);
		inline Matrix<T, M, N> & operator%=(const T & val);
		inline Matrix<T, M, N> & operator&=(const T & val);
		inline Matrix<T, M, N> & operator|=(const T & val);
		inline Matrix<T, M, N> & operator^=(const T & val);
		inline Matrix<T, M, N> & operator<<=(const T & val);
		inline Matrix<T, M, N> & operator>>=(const T & val);

		inline Vector<T, M> operator*=(const Vector<T, M> & v) const;

		using std::valarray<T>::min;
		using std::valarray<T>::max;
		using std::valarray<T>::sum;

//		inline Matrix<T, M, N> shift(int count) const;
//		inline Matrix<T, M, N> cshift(int count) const;
		inline Matrix<T, M, N> apply(T func(T)) const;
		inline Matrix<T, M, N> apply(T func(const T&)) const;

		inline Matrix<T, M, N> operator+(const Matrix<T, M, N> & rhs) const;
		inline Matrix<T, M, N> operator-(const Matrix<T, M, N> & rhs) const;
		inline Matrix<T, M, N> operator*(const Matrix<T, M, N> & rhs) const;
		inline Matrix<T, M, N> operator/(const Matrix<T, M, N> & rhs) const;
		inline Matrix<T, M, N> operator%(const Matrix<T, M, N> & rhs) const;
		inline Matrix<T, M, N> operator&(const Matrix<T, M, N> & rhs) const;
		inline Matrix<T, M, N> operator|(const Matrix<T, M, N> & rhs) const;
		inline Matrix<T, M, N> operator^(const Matrix<T, M, N> & rhs) const;
		inline Matrix<T, M, N> operator<<(const Matrix<T, M, N> & rhs) const;
		inline Matrix<T, M, N> operator>>(const Matrix<T, M, N> & rhs) const;
		inline Matrix<T, M, N> operator&&(const Matrix<T, M, N> & rhs) const;
		inline Matrix<T, M, N> operator||(const Matrix<T, M, N> & rhs) const;

		inline Matrix<T, M, N> operator+(const T & rhs) const;
		inline Matrix<T, M, N> operator-(const T & rhs) const;
		inline Matrix<T, M, N> operator*(const T & rhs) const;
		inline Matrix<T, M, N> operator/(const T & rhs) const;
		inline Matrix<T, M, N> operator%(const T & rhs) const;
		inline Matrix<T, M, N> operator&(const T & rhs) const;
		inline Matrix<T, M, N> operator|(const T & rhs) const;
		inline Matrix<T, M, N> operator^(const T & rhs) const;
		inline Matrix<T, M, N> operator<<(const T & rhs) const;
		inline Matrix<T, M, N> operator>>(const T & rhs) const;
		inline Matrix<T, M, N> operator&&(const T & rhs) const;
		inline Matrix<T, M, N> operator||(const T & rhs) const;

		bool operator==(const Matrix<T, M, N> & rhs) const;

		//		Matrix<bool, M, N> operator==(const Matrix<T, M, N> & rhs);
		Matrix<bool, M, N> operator!=(const Matrix<T, M, N> & rhs);
		Matrix<bool, M, N> operator<(const Matrix<T, M, N> & rhs);
		Matrix<bool, M, N> operator<=(const Matrix<T, M, N> & rhs);
		Matrix<bool, M, N> operator>(const Matrix<T, M, N> & rhs);
		Matrix<bool, M, N> operator>=(const Matrix<T, M, N> & rhs);

		Matrix<bool, M, N> operator==(const T & rhs);
		Matrix<bool, M, N> operator!=(const T & rhs);
		Matrix<bool, M, N> operator<(const T & rhs);
		Matrix<bool, M, N> operator<=(const T & rhs);
		Matrix<bool, M, N> operator>(const T & rhs);
		Matrix<bool, M, N> operator>=(const T & rhs);

		inline Matrix<T, M, N> abs() const;
		inline Matrix<T, M, N> exp() const;
		inline Matrix<T, M, N> log() const;
		inline Matrix<T, M, N> log10() const;
		inline Matrix<T, M, N> pow(const Matrix<T, M, N> & exp) const;
		inline Matrix<T, M, N> pow(const T & exp) const;
		inline Matrix<T, M, N> sqrt() const;
		inline Matrix<T, M, N> sin() const;
		inline Matrix<T, M, N> cos() const;
		inline Matrix<T, M, N> tan() const;
		inline Matrix<T, M, N> asin() const;
		inline Matrix<T, M, N> acos() const;
		inline Matrix<T, M, N> atan() const;
		inline Matrix<T, M, N> atan2(const Matrix<T, M, N> & x) const;
		inline Matrix<T, M, N> atan2(const T & x) const;
		inline Matrix<T, M, N> sinh() const;
		inline Matrix<T, M, N> cosh() const;
		inline Matrix<T, M, N> tanh() const;

		inline T trace() const;
		inline T determinant() const;
		inline Matrix<T, M, N> transpose() const;
		inline Matrix<double, M, N> inverse(bool & invertible) const;
	};
}

#include "utility/mathematics/matrix.inl"

#endif // MATRIX_HPP