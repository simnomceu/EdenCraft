#ifndef VERTEX_HPP
#define VERTEX_HPP

namespace ece
{
	template <class T>
	class Vertex3D
	{
	public:
		inline Vertex3D();
		inline Vertex3D(const T x, const T y, const T z);
		Vertex3D(const Vertex3D & copy) = default;
		Vertex3D(Vertex3D && move) = default;

		~Vertex3D() = default;

		Vertex3D & operator=(const Vertex3D & copy) = default;
		Vertex3D & operator=(Vertex3D && move) = default;

		template <typename V> inline Vertex3D<T> & operator/=(const V value);
		template <typename V> inline Vertex3D<T> & operator*=(const V value);
		inline Vertex3D<T> & operator+=(const Vertex3D<T> value);
		inline Vertex3D<T> & operator-=(const Vertex3D<T> value);

		template <typename V> inline Vertex3D<T> operator/(const V value) const;
		template <typename V> inline Vertex3D<T> operator*(const V value) const;
		inline Vertex3D<T> operator+(const Vertex3D<T> value) const;
		inline Vertex3D<T> operator-(const Vertex3D<T> value) const;

		inline Vertex3D<T> operator-() const;

		inline bool operator==(const Vertex3D<T> rightOperand) const;

		inline void normalize();
		inline T magnitude() const;
		inline Vertex3D cross(const Vertex3D<T> & rightOperand) const;
		inline T dot(const Vertex3D<T> & rightOperand) const;
		inline T distanceFrom(const Vertex3D<T> & rightOperand) const;

		T x;
		T y;
		T z;
	};

	using FloatVertex3D = Vertex3D<float>;
	using IntVertex3D = Vertex3D<int>;
	using DoubleVertex3D = Vertex3D<double>;
}

#include "Mathematics\Vertex3D.hpp"

#endif // VERTEX_HPP