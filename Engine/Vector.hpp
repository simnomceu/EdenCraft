#pragma once

#include <algorithm>
#include <array>
#include <initializer_list>

namespace Utils
{
	template<class T, unsigned short int S> class Vector;
	//template<class T, unsigned short int S> Vector<T,S> operator* (const T & t, const Vector<T, S> & v);
	template<class T, unsigned short int S> std::ostream & operator<< (std::ostream & os, const Vector<T, S> & v);


	template<class T, unsigned short int S>
	class Vector : private std::array<T, S>
	{
	public:
		using std::array<T, S>::operator[];

		Vector();
		Vector(std::initializer_list<T> values);
		Vector(const Vector & copy) = default;
		Vector(Vector && value);
		~Vector();

		Vector & operator=(const Vector & copy) = default;
		Vector & operator=(Vector && value);
		Vector & operator=(std::initializer_list<T> values);

		Vector operator+(const Vector & rightOperand);
		Vector operator-(const Vector & rightOperand);
		Vector operator-() const;
		Vector operator*(const Vector & rightOperand);
		Vector operator*(const T & rightOperand);
		/*Vector operator/(const Vector & rightOperand);
		Vector operator/(const T & rightOperand);
		Vector operator%(const Vector & rightOperand);*/
		Vector & operator++();
		Vector operator++(int);
		Vector & operator--();
		Vector operator--(int);

		/*Vector & operator+=(const Vector & rightOperand);
		Vector & operator-=(const Vector & rightOperand);
		Vector & operator*=(const Vector & rightOperand);
		Vector & operator/=(const Vector & rightOperand);
		Vector & operator%=(const Vector & rightOperand);*/

		//friend Vector<T,S> operator* <>(const T & t, const Vector<T, S> & v);

		friend std::ostream & operator<< <>(std::ostream & os, const Vector<T, S> & v);

		double norm(const unsigned short int base) const;
		double uniform_norm() const;

		double dot(const Vector<T, S> rightOperand) const;

	private:
		int base; // Use another type
	};
}

#include "Vector.inl"

namespace Utils
{
	template<class T>
	using Vector2 = Vector<T, 2>;

	using Vector2f = Vector2<float>;
	using Vector2i = Vector2<int>;
	using Vector2ui = Vector2<unsigned int>;

	template<class T>
	using Vector3 = Vector<T, 3>;

	using Vector3f = Vector3<float>;
	using Vector3i = Vector3<int>;
	using Vector3ui = Vector3<unsigned int>;
}