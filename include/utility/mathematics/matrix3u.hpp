#ifndef MATRIX3U_HPP
#define MATRIX3U_HPP

#include <array>

#include "utility/mathematics/vertex3u.hpp"

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

#include "utility/mathematics/matrix3u.inl"

#endif // MATRIX3U_HPP
