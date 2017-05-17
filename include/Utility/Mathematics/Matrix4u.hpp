#ifndef MATRIX4U_HPP
#define MATRIX4U_HPP

#include <array>

#include "Mathematics\Vertex4u.hpp"

namespace ece
{
	template <class T>
	class Matrix4u : public std::array<Vertex4u<T>, 4>
	{
	public:
		static Matrix4u<T> Identity();
		inline Matrix4u();
		inline Matrix4u(const T a11, const T a12, const T a13, const T a14,
						const T a21, const T a22, const T a23, const T a24,
						const T a31, const T a32, const T a33, const T a34,
						const T a41, const T a42, const T a43, const T a44);
		inline Matrix4u(const Vertex4u<T> & a1, const Vertex4u<T> & a2, const Vertex4u<T> & a3, const Vertex4u<T> & a4);
		Matrix4u(const Matrix4u<T> & copy) = default;
		Matrix4u(Matrix4u<T> && move) = default;
		template <typename V> inline Matrix4u(const Matrix4u<V> & copy);

		~Matrix4u() = default;

		Matrix4u<T> & operator=(const Matrix4u<T> & copy) = default;
		Matrix4u<T> & operator=(Matrix4u<T> && move) = default;
		template <typename V> inline Matrix4u<T> & operator=(const Matrix4u<V> & copy);
		inline Matrix4u<T> & setIdentity();

		template <typename V> inline Matrix4u<T> & operator/=(const V value);
		template <typename V> inline Matrix4u<T> & operator*=(const V value);
		template <typename V> inline Matrix4u<T> & operator*=(const Matrix4u<V> value);
		inline Matrix4u<T> & operator+=(const Matrix4u<T> value);
		inline Matrix4u<T> & operator-=(const Matrix4u<T> value);

		template <typename V> inline Matrix4u<T> operator/(const V value) const;
		template <typename V> inline Matrix4u<T> operator*(const V value) const;
		template <typename V> inline Vertex4u<T> operator*(const Vertex4u<V> value) const;
		template <typename V> inline Matrix4u<T> operator*(const Matrix4u<V> value) const;
		inline Matrix4u<T> operator+(const Matrix4u<T> value) const;
		inline Matrix4u<T> operator-(const Matrix4u<T> value) const;

		inline Matrix4u<T> operator-() const;

		inline bool operator==(const Matrix4u<T> & rightOperand) const;

		inline Vertex2u<T> getColumn(const int index) const;
		inline Vertex2u<T> getRow(const int index) const;
		inline Vertex2u<T> & getRow(const int index);
		using std::array<Vertex4u<T>, 4>::operator[];

		inline T determinant() const;
		inline Matrix4u<T> transpose() const;
		inline Matrix4u<T> inverse(bool & invertible) const;
	};

	typedef Matrix4u<float> FloatMatrix4u;
	typedef Matrix4u<int> IntMatrix4u;
	typedef Matrix4u<double> DoubleMatrix4u;
}

#include "Mathematics\Matrix4u.inl"

#endif // MATRIX4U_HPP
