#include "Vertex3D.hpp"
namespace ece
{
	template <class T>
	inline Vertex3D<T>::Vertex3D() : position{ 0, 0, 0 } {}

	template <class T>
	inline Vertex3D<T>::Vertex3D(const T x, const T y, const T z) : position{ x, y, z } {}

	template <class T>
	template <typename V>
	inline Vertex3D<T>::Vertex3D(const Vertex3D<V> & copy) :
		position{ static_cast<T>(copy.position[X]), static_cast<T>(copy.position[Y]), static_cast<T>(copy.position[Z]) }  {}

	template <class T>
	template <typename V>
	Vertex3D<T> & Vertex3D<T>::operator=(const Vertex3D<V> & copy)
	{
		this->position[X] = static_cast<T>(copy.position[X]);
		this->position[Y] = static_cast<T>(copy.position[Y]);
		this->position[Z] = static_cast<T>(copy.position[Z]);
		return *this;
	}

	template<class T>
	template<typename V>
	inline Vertex3D<T>& Vertex3D<T>::operator/=(const V value)
	{
		this->position[X] /= value;
		this->position[Y] /= value;
		this->position[Z] /= value;
		return *this;
	}

	template<class T>
	template<typename V>
	inline Vertex3D<T>& Vertex3D<T>::operator*=(const V value)
	{
		this->position[X] *= value;
		this->position[Y] *= value;
		this->position[Z] *= value;
		return *this;
	}

	template<class T>
	inline Vertex3D<T>& Vertex3D<T>::operator+=(const Vertex3D<T> value)
	{
		this->position[X] += value.x;
		this->position[Y] += value.y;
		this->position[Z] += value.z;
		return *this;
	}

	template<class T>
	inline Vertex3D<T>& Vertex3D<T>::operator-=(const Vertex3D<T> value)
	{
		this->position[X] -= value.x;
		this->position[Y] -= value.y;
		this->position[Z] -= value.z;
		return *this;
	}

	template<class T>
	template<typename V>
	inline Vertex3D<T> Vertex3D<T>::operator/(const V value) const
	{
		return Vertex3D<T>(this->position[X] / value, this->position[Y] / value, this->position[Z] / value);
	}

	template<class T>
	template<typename V>
	inline Vertex3D<T> Vertex3D<T>::operator*(const V value) const
	{
		return Vertex3D<T>(this->position[X] * value, this->position[Y] * value, this->position[Z] * value);
	}

	template<class T>
	inline Vertex3D<T> Vertex3D<T>::operator+(const Vertex3D<T> value) const
	{
		return Vertex3D<T>(this->position[X] + value.position[X], this->position[Y] + value.position[Y], this->position[Z] + value.position[Z]);
	}

	template<class T>
	inline Vertex3D<T> Vertex3D<T>::operator-(const Vertex3D<T> value) const
	{
		return Vertex3D<T>(this->position[X] - value.position[X], this->position[Y] - value.position[Y], this->position[Z] - value.position[Z]);
	}

	template<class T>
	inline Vertex3D<T> Vertex3D<T>::operator-() const
	{
		return Vertex3D<T>(-value.position[X], -value.position[Y], -value.position[Z]);
	}

	template<class T>
	inline bool Vertex3D<T>::operator==(const Vertex3D<T> & rightOperand) const
	{
		return this->position[X] == rightOperand.position[X] && this->position[Y] == rightOperand.position[Y] && this->position[Z] == rightOperand.position[Z];
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
	inline Vertex3D<T> Vertex3D<T>::cross(const Vertex3D<T> & rightOperand) const
	{
		return Vertex3D<T>(this->position[Y] * rightOperand.position[Z] - this->position[Z] * rightOperand.position[Y],
							this->position[Z] * rightOperand.position[X] - this->position[X] * rightOperand.position[Z],
							this->position[X] * rightOperand.position[Y] - this->position[Y] * rightOperand.position[X]);
	}

	template<class T>
	inline T Vertex3D<T>::dot(const Vertex3D<T> & rightOperand) const
	{
		return this->position[X] * rightOperand.position[X] 
			+ this->position[Y] * rightOperand.position[Y] 
			+ this->position[Z] * rightOperand.position[Z];
	}

	template<class T>
	inline T Vertex3D<T>::distanceFrom(const Vertex3D<T> & rightOperand) const
	{
		return this->operator-(rightOperand).magnitude();
	}
}