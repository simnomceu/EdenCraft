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
				Copyright(C) 2018 Pierre Casati (@IsilinBN)

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

#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "utility/config.hpp"

namespace ece
{
    namespace utility
    {
        namespace mathematics
        {
        	/**
        	 * @class Rectangle
        	 * @tparam T A numerical and scalar type used for the representation of dimensions and sizes.
        	 * @brief Describe a rectangle by its size and its dimension.
        	 * This rectangle is describe using size and dimension. So, it could be used only for a goal of describing bounds for an object.
        	 * The object is completely compatible with movable or copyable operations.
        	 * All the properties are defined, relating to the top left corner of the rectangle.
        	 **/
        	template<typename T>
        	class ECE_UTILITY_API Rectangle
        	{
        	public:

        		/**
        		 * @fn Rectangle() noexcept
        		 * @brief Build a rectangle, setting all the properties to 0.
        		 * @throw noexcept
        		 **/
        		inline constexpr Rectangle() noexcept;

        		/**
        		 * @fn Rectangle(const T x, const T y, const T w, const T h) noexcept
        		 * @param[in] x The position of the rectangle on the x-axis.
        		 * @param[in] y The position of the rectangle on the y-axis.
        		 * @param[in] w The width of the rectangle.
        		 * @param[in] h The height of the rectangle.
        		 * @brief Build a rectangle, setting all the properties.
        		 * throw noexcept
        		 **/
        		inline Rectangle(const T x, const T y, const T w, const T h) noexcept;

        		/**
        		 * @fn Rectangle(const Rectangle & copy) noexcept
        		 * @brief Copy constructor of a rectangle.
        		 * The copy constructor is the default one, all properties are of scalar type.
        		 * @throw noexcept
        		 **/
        		Rectangle(const Rectangle & copy) noexcept = default;

        		/**
        		 * @fn Rectangle(Rectangle && copy) noexcept
        		 * @brief Move constructor of a rectangle.
        		 * The move constructor is the default one, all properties are of scalar type.
        		 * @throw noexcept
        		 **/
        		Rectangle(Rectangle && copy) noexcept = default;

        		/**
        		 * @fn ~Rectangle() noexcept
        		 * @brief Destructor of a rectangle.
        		 * The destructor is the default one, all properties are of scalar type.
        		 * @throw noexcept
        		 **/
        		~Rectangle() noexcept = default;

        		/**
        		 * @fn Rectangle & operator=(const Rectangle & rightOperand) noexcept
        		 * @param[in] rightOperand The rectangle to copy from.
        		 * @return The rectangle copied.
        		 * @brief Copy assignment operator for a rectangle.
        		 * The copy assignment operator is the default one, all properties are of scalar type.
        		 * @throw noexcept
        		 **/
        		Rectangle & operator=(const Rectangle & rightOperand) noexcept = default;

        		/**
        		 * @fn Rectangle & operator=(Rectangle && rightOperand) noexcept
        		 * @param[in] rightOperand The rectangle to move.
        		 * @return The rectangle moved.
        		 * @brief Move assigment operator of a rectangle.
        		 * The move assigment operator is the default one, all properties are of scalar type.
        		 * @throw noexcept
        		 **/
        		Rectangle & operator=(Rectangle && rightOperand) noexcept = default;

				inline bool operator==(const Rectangle<T> & rhs) const noexcept;

				inline bool operator!=(const Rectangle<T> & rhs) const noexcept;

				inline Rectangle<T> operator*(const Rectangle<T> & rhs) const noexcept;

				inline Rectangle<T> operator/(const Rectangle<T> & rhs) const noexcept;

				/**
				  * @fn T getX() const noexcept
				  * @return The position on the x-axis. The value returned is of the same type used to define the rectangle.
				  * @brief Access to the position of the rectangle on the x-axis.
				  * @throw noexcept
				  **/
				inline T getX() const noexcept;

        		/**
        		 * @fn T getY() const noexcept
        		 * @return The position on the y-axis. The value returned is of the same type used to define the rectangle.
        		 * @brief Access to the position of the rectangle on the y-axis.
        		 * @throw noexcept
        		 **/
        		inline T getY() const noexcept;

        		/**
        		 * @fn T getWidth() const noexcept
        		 * @return The width of the rectangle. The value returned is of the same type used to define the rectangle.
        		 * @brief Access to the width of the rectangle.
        		 * @throw noexcept
        		 **/
        		inline T getWidth() const noexcept;

        		/**
        		 * @fn T getHeight() const noexcept
        		 * @return The height of the rectangle. The value returned is of the same type used to define the rectangle.
        		 * @brief Access to the height of the rectangle.
        		 * @throw noexcept
        		 **/
        		inline T getHeight() const noexcept;

        	private:
        		/**
        		 * @property _x
        		 * @brief Position on the x-axis.
        		 **/
        		T _x;

        		/**
        		 * @property _y
        		 * @brief Position on the y-axis.
        		 **/
        		T _y;

        		/**
        		 * @property _w
        		 * @brief Width of the rectangle.
        		 **/
        		T _w;

        		/**
        		 * @property _h
        		 * @brief Height of the rectangle.
        		 **/
        		T _h;
        	};
        } // namespace mathematics
    } // namespace utility
} // namespace ece

#include "utility/mathematics/rectangle.inl"

#endif // RECTANGLE_HPP
