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
