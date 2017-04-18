#include "Vertex3D.hpp"
namespace ece
{
	template <class T>
	inline Vertex3D::Vertex3D(): x(0), y(0), z(0) {}

	template <class T>
	inline Vertex3D::Vertex3D(const T x, const T y, const T z) : x(x), y(y), z(z) {}

	template<class T>
	template<typename V>
	inline Vertex3D<T>& Vertex3D<T>::operator/=(const V value)
	{
		this->x /= value;
		this->y /= value;
		this->z /= value;
	}

	template<class T>
	template<typename V>
	inline Vertex3D<T>& Vertex3D<T>::operator*=(const V value)
	{
		this->x *= value;
		this->y *= value;
		this->z *= value;
	}

	template<class T>
	inline Vertex3D<T>& Vertex3D<T>::operator+=(const Vertex3D<T> value)
	{
		this->x += value.x;
		this->y += value.y;
		this->z += value.z;
	}

	template<class T>
	inline Vertex3D<T>& Vertex3D<T>::operator-=(const Vertex3D<T> value)
	{
		this->x -= value.x;
		this->y -= value.y;
		this->z -= value.z;
	}

	template<class T>
	template<typename V>
	inline Vertex3D<T> Vertex3D<T>::operator/(const V value) const
	{
		return Vertex3D<T>(this->x / value, this->y / value, this->z / value);
	}

	template<class T>
	template<typename V>
	inline Vertex3D<T> Vertex3D<T>::operator*(const V value) const
	{
		return Vertex3D<T>(this->x * value, this->y * value, this->z * value);
	}

	template<class T>
	inline Vertex3D<T> Vertex3D<T>::operator+(const Vertex3D<T> value) const
	{
		return Vertex3D<T>(this->x + value.x, this->y + value.y, this->z + value.z);
	}

	template<class T>
	inline Vertex3D<T> Vertex3D<T>::operator-(const Vertex3D<T> value) const
	{
		return Vertex3D<T>(this->x - value.x, this->y - value.y, this->z - value.z);
	}

	template<class T>
	inline Vertex3D<T> Vertex3D<T>::operator-() const
	{
		return Vertex3D<T>(-value.x, -value.y, -value.z);
	}

	template<class T>
	inline bool Vertex3D<T>::operator==(const Vertex3D<T> rightOperand) const
	{
		return this->x == rightOperand.x && this->y == rightOperand.y && this->z == rightOperand.z;
	}

	template<class T>
	inline void Vertex3D<T>::normalize()
	{
		this->operator/=(this->magnitude());
	}

	template<class T>
	inline T Vertex3D<T>::magnitude() const
	{
		return sqrt(this->dot(*this));
	}

	template<class T>
	inline Vertex3D Vertex3D<T>::cross(const Vertex3D<T> & rightOperand) const
	{
		return Vertex3D<T>(this->y * rightOperand.z - this->z * rightOperand.y,
							this->z * rightOperand.x - this->x * rightOperand.z,
							this->x * rightOperand.y - this->y * rightOperand.x);
	}

	template<class T>
	inline T Vertex3D<T>::dot(const Vertex3D<T> & rightOperand) const
	{
		return this->x * rightOperand.x + this->y * rightOperand.y + this->z * rightOperand.z;
	}

	template<class T>
	inline T Vertex3D<T>::distanceFrom(const Vertex3D<T> & rightOperand) const
	{
		return this->operator-(rightOperand).magnitude();
	}
}