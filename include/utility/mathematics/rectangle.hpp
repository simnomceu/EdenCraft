/*
	
	oooooooooooo       .o8                          .oooooo.                       .o88o.     .   
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8   
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo 
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888   
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888   
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 . 
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888" 

															ooooo     ooo     .    o8o  oooo   o8o      .
															`888'     `8'   .o8    `"'  `888   `"'    .o8
															 888       8  .o888oo oooo   888  oooo  .o888oo oooo    ooo
															 888       8    888   `888   888  `888    888    `88.  .8'
															 888       8    888    888   888   888    888     `88..8'
															 `88.    .8'    888 .  888   888   888    888 .    `888'
															   `YbodP'      "888" o888o o888o o888o   "888"     .8'
																											.o..P'
																											`Y8P'

				This file is part of EdenCraft Engine - Utility module.
				Copyright(C) 2017 Pierre Casati (@IsilinBN)

				This program is free software : you can redistribute it and/or modify
				it under the terms of the GNU General Public License as published by
				the Free Software Foundation, either version 3 of the License, or
				(at your option) any later version.

				This program is distributed in the hope that it will be useful,
				but WITHOUT ANY WARRANTY; without even the implied warranty of
				MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
				GNU General Public License for more details.

				You should have received a copy of the GNU General Public License
				along with this program.If not, see <http://www.gnu.org/licenses/>.

*/

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

#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

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
#include "utility/mathematics/rectangle.inl"


#endif // RECTANGLE_HPP