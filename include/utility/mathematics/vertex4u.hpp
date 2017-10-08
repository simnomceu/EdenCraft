#ifndef VERTEX4U_HPP
#define VERTEX4U_HPP

#include <array>
#include "mathematics/vertex3u.hpp"

namespace ece
{
	template <class T>
	class Vertex4u : protected std::array<T, 4>
	{
	public:
		inline Vertex4u();
		inline Vertex4u(const T x, const T y, const T z, const T w);
		inline Vertex4u(const Vertex3u<T> & xyz, const T w);
		Vertex4u(const Vertex4u<T> & copy) = default;
		Vertex4u(Vertex4u<T> && move) = default;
		template <typename V> inline Vertex4u(const Vertex4u<V> & copy);

		~Vertex4u() = default;

		Vertex4u<T> & operator=(const Vertex4u<T> & copy) = default;
		Vertex4u<T> & operator=(Vertex4u<T> && move) = default;
		template <typename V> Vertex4u<T> & operator=(const Vertex4u<V> & copy);

		template <typename V> inline Vertex4u<T> & operator/=(const V value);
		template <typename V> inline Vertex4u<T> & operator*=(const V value);
		inline Vertex4u<T> & operator+=(const Vertex4u<T> value);
		inline Vertex4u<T> & operator-=(const Vertex4u<T> value);

		template <typename V> inline Vertex4u<T> operator/(const V value) const;
		template <typename V> inline Vertex4u<T> operator*(const V value) const;
		inline Vertex4u<T> operator+(const Vertex4u<T> value) const;
		inline Vertex4u<T> operator-(const Vertex4u<T> value) const;

		inline Vertex4u<T> operator-() const;

		inline bool operator==(const Vertex4u<T> & rightOperand) const;

		inline void normalize();
		inline T magnitude() const;
		inline T dot(const Vertex4u<T> & rightOperand) const;
		inline T distanceFrom(const Vertex4u<T> & rightOperand) const;

		using std::array<T, 4>::operator[];
	};

	typedef Vertex4u<float> FloatVertex4u;
	typedef Vertex4u<int> IntVertex4u;
	typedef Vertex4u<double> DoubleVertex4u;

	typedef Vertex4u<float> FloatPoint2u;
	typedef Vertex4u<int> IntPoint2u;
	typedef Vertex4u<double> DoublePoint2u;
}

#include "mathematics/vertex4u.inl"

#endif // VERTEX4U_HPP
