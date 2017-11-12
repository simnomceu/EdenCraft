#ifndef VERTEX3U_HPP
#define VERTEX3U_HPP

#include <array>

namespace ece
{
	enum Axis: unsigned short int
	{
		X = 0,
		Y = 1,
		Z = 2
	};

	template <class T>
	class Vertex3u: protected std::array<T, 3>
	{
	public:
		inline Vertex3u();
		inline Vertex3u(const T x, const T y, const T z);
		Vertex3u(const Vertex3u<T> & copy) = default;
		Vertex3u(Vertex3u<T> && move) = default;
		template <typename V> inline Vertex3u(const Vertex3u<V> & copy);

		~Vertex3u() = default;

		Vertex3u<T> & operator=(const Vertex3u<T> & copy) = default;
		Vertex3u<T> & operator=(Vertex3u<T> && move) = default;
		template <typename V> Vertex3u<T> & operator=(const Vertex3u<V> & copy);

		template <typename V> inline Vertex3u<T> & operator/=(const V value);
		template <typename V> inline Vertex3u<T> & operator*=(const V value);
		inline Vertex3u<T> & operator+=(const Vertex3u<T> value);
		inline Vertex3u<T> & operator-=(const Vertex3u<T> value);

		template <typename V> inline Vertex3u<T> operator/(const V value) const;
		template <typename V> inline Vertex3u<T> operator*(const V value) const;
		inline Vertex3u<T> operator+(const Vertex3u<T> value) const;
		inline Vertex3u<T> operator-(const Vertex3u<T> value) const;

		inline Vertex3u<T> operator-() const;

		inline bool operator==(const Vertex3u<T> & rightOperand) const;

		inline void normalize();
		inline T magnitude() const;
		inline Vertex3u<T> cross(const Vertex3u<T> & rightOperand) const;
		inline T dot(const Vertex3u<T> & rightOperand) const;
		inline T distanceFrom(const Vertex3u<T> & rightOperand) const;

		using std::array<T, 3>::operator[];
	};

	static const Vertex3u<int> UP(0, 1, 0);
	static const Vertex3u<int> DOWN(0, -1, 0);
	static const Vertex3u<int> LEFT(-1, 0, 0);
	static const Vertex3u<int> RIGHT(1, 0, 0);
	static const Vertex3u<int> FRONT(0, 0, 1);
	static const Vertex3u<int> BACK(0, 0, -1);

	typedef Vertex3u<float> FloatVertex3u;
	typedef Vertex3u<int> IntVertex3u;
	typedef Vertex3u<double> DoubleVertex3u;

	typedef Vertex3u<float> FloatPoint3u;
	typedef Vertex3u<int> IntPoint3u;
	typedef Vertex3u<double> DoublePoint3u;
}

#include "utility/mathematics/vertex3u.inl"

#endif // VERTEX3U_HPP