#ifndef VERTEX2U_HPP
#define VERTEX2U_HPP

#include <array>

namespace ece
{
	template <class T>
	class Vertex2u: protected std::array<T, 2>
	{
	public:
		inline Vertex2u();
		inline Vertex2u(const T x, const T y);
		Vertex2u(const Vertex2u<T> & copy) = default;
		Vertex2u(Vertex2u<T> && move) = default;
		template <typename V> inline Vertex2u(const Vertex2u<V> & copy);

		~Vertex2u() = default;

		Vertex2u<T> & operator=(const Vertex2u<T> & copy) = default;
		Vertex2u<T> & operator=(Vertex2u<T> && move) = default;
		template <typename V> Vertex2u<T> & operator=(const Vertex2u<V> & copy);

		template <typename V> inline Vertex2u<T> & operator/=(const V value);
		template <typename V> inline Vertex2u<T> & operator*=(const V value);
		inline Vertex2u<T> & operator+=(const Vertex2u<T> value);
		inline Vertex2u<T> & operator-=(const Vertex2u<T> value);

		template <typename V> inline Vertex2u<T> operator/(const V value) const;
		template <typename V> inline Vertex2u<T> operator*(const V value) const;
		inline Vertex2u<T> operator+(const Vertex2u<T> value) const;
		inline Vertex2u<T> operator-(const Vertex2u<T> value) const;

		inline Vertex2u<T> operator-() const;

		inline bool operator==(const Vertex2u<T> & rightOperand) const;

		inline void normalize();
		inline T magnitude() const;
		inline T dot(const Vertex2u<T> & rightOperand) const;
		inline T distanceFrom(const Vertex2u<T> & rightOperand) const;

		using std::array<T, 2>::operator[];
	};

	typedef Vertex2u<float> FloatVertex2u;
	typedef Vertex2u<int> IntVertex2u;
	typedef Vertex2u<double> DoubleVertex2u;

	typedef Vertex2u<float> FloatPoint2u;
	typedef Vertex2u<int> IntPoint2u;
	typedef Vertex2u<double> DoublePoint2u;
}

#include "mathematics\vertex2u.inl"

#endif // VERTEX2U_HPP
