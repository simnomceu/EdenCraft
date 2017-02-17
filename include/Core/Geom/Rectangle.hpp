#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

/**
 * @file Rectangle.hpp
 * @author IsiliBN (casa2pir@hotmail.fr)
 * @date October, 13th 2016
 * @copyright ----------
 * @brief Describe a rectangle object.
 *
 * Describe a rectangle object.  This rectangle is purely a boundering, an aggregate of positions and sizes.
 *
 **/

/**
 * @namespace ece
 * 
 * A namespace to gather classes and functionalities of the core engine of EdenCraft.
 *
 **/
namespace ece
{
	/**
	 * @class Rectangle
	 * @tparam T A numerical and scalar type used for the representation of dimensions and sizes.
	 * @brief Describe a rectangle by its size and its dimension.
	 *
	 * This rectangle is describe using size and dimension. So, it could be used only for a goal of describing bounds for an object.
	 * The object is completely compatible with movable or copyable operations. 
	 * All the properties are defined, relating to the top left corner of the rectangle.
	 *
	 **/
	template<typename T>
	class Rectangle
	{
	public:

		/**
		* @fn Rectangle()
		* @brief Build a rectangle, setting all the properties to 0.
		*
		**/
		inline Rectangle();

		/**
		 * @fn Rectangle(const T x, const T y, const T w, const T h)
		 * @param[in] x The position of the rectangle on the x-axis.
		 * @param[in] y The position of the rectangle on the y-axis.
		 * @param[in] w The width of the rectangle.
		 * @param[in] h The height of the rectangle.
		 * @brief Build a rectangle, setting all the properties.
		 *
		 **/
		inline Rectangle(const T x, const T y, const T w, const T h);

		/**
		 * @fn Rectangle(const Rectangle & copy)
		 * @brief Copy constructor of a rectangle.
		 *
		 * The copy constructor is the default one, all properties are of scalar type.
		 *
		 **/
		Rectangle(const Rectangle & copy) = default;

		/**
		* @fn Rectangle(Rectangle && copy)
		* @brief Move constructor of a rectangle.
		*
		* The move constructor is the default one, all properties are of scalar type.
		*
		**/
		Rectangle(Rectangle && copy) = default;

		/**
		* @fn ~Rectangle()
		* @brief Destructor of a rectangle.
		*
		* The destructor is the default one, all properties are of scalar type.
		*
		**/
		~Rectangle() = default;

		/**
		* @fn Rectangle & operator=(const Rectangle & rightOperand)
		* @brief Copy assigment operator for a rectangle.
		*
		* The copy assigment operator is the default one, all properties are of scalar type.
		*
		**/
		Rectangle & operator=(const Rectangle & rightOperand) = default;

		/**
		* @fn Rectangle & operator=(const Rectangle && rightOperand)
		* @brief Move assigment operator of a rectangle.
		*
		* The move assigment operator is the default one, all properties are of scalar type.
		*
		**/
		Rectangle & operator=(Rectangle && rightOperand) = default;

		/**
		 * @fn T getX() const
		 * @return The position on the x-axis. The value returned is of the same type used to define the rectangle.
		 * @brief Access to the position of the rectangle on the x-axis.
		 *
		 **/
		inline T getX() const;
		

		/**
		* @fn T getY() const
		* @return The position on the y-axis. The value returned is of the same type used to define the rectangle.
		* @brief Access to the position of the rectangle on the y-axis.
		*
		**/
		inline T getY() const;

		/**
		* @fn T getWidth() const
		* @return The width of the rectangle. The value returned is of the same type used to define the rectangle.
		* @brief Access to the width of the rectangle.
		*
		**/
		inline T getWidth() const;

		/**
		* @fn T getHeight() const
		* @return The height of the rectangle. The value returned is of the same type used to define the rectangle.
		* @brief Access to the height of the rectangle.
		*
		**/
		inline T getHeight() const;

	private:
		/**
		 * @property x
		 * @brief Position on the x-axis.
		 *
		 **/
		T x;

		/**
		* @property y
		* @brief Position on the y-axis.
		*
		**/
		T y;

		/**
		* @property w
		* @brief Width of the rectangle.
		*
		**/
		T w;

		/**
		* @property h
		* @brief Height of the rectangle.
		*
		**/
		T h;
	};
}


/**
 * @include Rectangle.inl
 * @brief Definition of inline and template methods of the Rectangle class.
 **/
#include "Rectangle.inl"


#endif // RECTANGLE_HPP