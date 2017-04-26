#ifndef VERTEX3D_HPP
#define VERTEX3D_HPP

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
	class Vertex3D
	{
	public:
		inline Vertex3D();
		inline Vertex3D(const T x, const T y, const T z);
		Vertex3D(const Vertex3D<T> & copy) = default;
		Vertex3D(Vertex3D<T> && move) = default;
		template <typename V> inline Vertex3D(const Vertex3D<V> & copy);

		~Vertex3D() = default;

		Vertex3D<T> & operator=(const Vertex3D<T> & copy) = default;
		Vertex3D<T> & operator=(Vertex3D<T> && move) = default;
		template <typename V> Vertex3D<T> & operator=(const Vertex3D<V> & copy);

		template <typename V> inline Vertex3D<T> & operator/=(const V value);
		template <typename V> inline Vertex3D<T> & operator*=(const V value);
		inline Vertex3D<T> & operator+=(const Vertex3D<T> value);
		inline Vertex3D<T> & operator-=(const Vertex3D<T> value);

		template <typename V> inline Vertex3D<T> operator/(const V value) const;
		template <typename V> inline Vertex3D<T> operator*(const V value) const;
		inline Vertex3D<T> operator+(const Vertex3D<T> value) const;
		inline Vertex3D<T> operator-(const Vertex3D<T> value) const;

		inline Vertex3D<T> operator-() const;

		inline bool operator==(const Vertex3D<T> & rightOperand) const;

		inline void normalize();
		inline T magnitude() const;
		inline Vertex3D<T> cross(const Vertex3D<T> & rightOperand) const;
		inline T dot(const Vertex3D<T> & rightOperand) const;
		inline T distanceFrom(const Vertex3D<T> & rightOperand) const;

		std::array<T, 3> position;
	};

	static const Vertex3D<int> UP(0, 1, 0);
	static const Vertex3D<int> DOWN(0, -1, 0);
	static const Vertex3D<int> LEFT(-1, 0, 0);
	static const Vertex3D<int> RIGHT(1, 0, 0);
	static const Vertex3D<int> FRONT(0, 0, 1);
	static const Vertex3D<int> BACK(0, 0, -1);

	typedef Vertex3D<float> FloatVertex3D;
	typedef Vertex3D<int> IntVertex3D;
	typedef Vertex3D<double> DoubleVertex3D;

	typedef Vertex3D<float> FloatPoint3D;
	typedef Vertex3D<int> IntPoint3D;
	typedef Vertex3D<double> DoublePoint3D;
}

#include "Mathematics\Vertex3D.inl"

#endif // VERTEX3D_HPP