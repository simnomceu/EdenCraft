#ifndef VECTOR_HPP
#define VECTOR_HPP

/**
* @file Rectangle.hpp
* @author IsiliBN (casa2pir@hotmail.fr)
* @date October, 17th 2016
* @copyright ----------
* @brief Describe a rectangle object.
*
* Describe a rectangle object.  This rectangle is purely a boundering, an aggregate of positions and sizes.
*
**/

#include <array>
#include <initializer_list>

/**
* @namespace ece
*
* A namespace to gather classes and functionalities of the core engine of EdenCraft.
*
**/
namespace ece
{
	template<class T, unsigned short int S> class Vector;
	template<class T, unsigned short int S> std::ostream & operator<< (std::ostream & os, const Vector<T, S> & v);


	/**
	 * @class Vector
	 * @extends std::array<T, S>
	 * @tparam T A numerical and scalar type used for the representation of the attributes of the vector.
	 * @tparam S The size of the vector.
	 * @brief Describe a eceetric vector.
	 *
	 * This is a vector, as defined eceetrically. It is used to perform numerical and eceetrical computations.
	 * The object is completely compatible with movable or copyable operations.
	 * Size is fixed at construction. The vector couldn't be resized after having been defined.
	 *
	**/
	template<class T, unsigned short int S>
	class Vector : private std::array<T, S>
	{
	public:
		/**
		 * @typedef using std::array<T, S>::operator[]
		 * @brief Use the subscript operator, as defined in the parent class std::array.
		 *
		 **/
		using std::array<T, S>::operator[];

		/**
		 * @fn Vector()
		 * @brief Build a vector, with default values. All the attributes are set to 0.
		 *
		 **/
		Vector();

		/**
		 * @fn Vector(std::initializer_list<T> values)
		 * @params values List of attributes to initialize the vector.
		 * @brief Build a vector, and set the attributes using the initializer list.
		 *
		 **/
		Vector(std::initializer_list<T> values);

		/**
		 * @fn Vector(const Vector & copy)
		 * @params copy Existing vector used as pattern to build the vector.
		 * @brief Copy constructor for the class vector.
		 *
		 * This copy constructor is the default one. All properties are of scalar type.
		 *
		 **/
		Vector(const Vector & copy) = default;

		/**
		 * @fn Vector(Vector && value)
		 * @params value Existing vector which will be used to moved attributes in the new vector.
		 * @brief Move constructor for the class vector.
		 *
		 **/
		Vector(Vector && value);
		~Vector();

		/**
		 * @fn Vector & operator=(const Vector & copy)
		 * @params copy Existing vector used as pattern to set new values to the current vector.
		 * @return The vector set with values of the copy vector.
		 * @brief Copy assigment operator for the class vector.
		 *
		 * This copy assigment operator is the default one. All properties are of scalar type.
		 *
		 **/
		Vector & operator=(const Vector & copy) = default;
		Vector & operator=(Vector && value);
		Vector & operator=(std::initializer_list<T> values);

		Vector operator+(const Vector & rightOperand);
		Vector operator-(const Vector & rightOperand);
		Vector operator-() const;
		Vector operator*(const Vector & rightOperand);
		Vector operator*(const T & rightOperand);
		Vector & operator++();
		Vector operator++(int);
		Vector & operator--();
		Vector operator--(int);

		/*Vector & operator+=(const Vector & rightOperand);
		Vector & operator-=(const Vector & rightOperand);
		Vector & operator*=(const Vector & rightOperand);*/

		bool operator==(const Vector<T, S> & rightOperand) const;

		friend std::ostream & operator<< <>(std::ostream & os, const Vector<T, S> & v);

		double norm(const unsigned short int base) const;
		double uniform_norm() const;

		double dot(const Vector<T, S> rightOperand) const;

	private:
		int base; // Use another type
	};
}

#include "Core\Geom\Vector.inl"

namespace ece
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

#endif // VECTOR_HPP