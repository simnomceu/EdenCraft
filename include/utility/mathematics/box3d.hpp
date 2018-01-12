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
 * @file utility/mathematics/box3d.hpp
 * @author IsilinBN (casa2pir@hotmail.fr)
 * @date January, 3rd 2018
 * @copyright ----------
 * @brief Define a box in a 3D space.
 */

#ifndef BOX3D_HPP
#define BOX3D_HPP

#include "utility/mathematics/vector3u.hpp"

namespace ece
{
	/**
	 * @class Box3D
	 * @brief Box in a 3D space, defined by two vertices.
	 * @remark Need to be refactored as a templated class.
	 *      *-------b
	 *     /|      /|
	 *	  / |     / |
	 *   *--|----*  |
	 *   |  *----|--*
	 *   | /     | /
	 *   a-------*
	 */
	class Box3D
	{
	public:
		Box3D() = delete;

		/**
		 * @fn Box3D(const FloatVertex3u & a, const FloatVertex3u & b)
		 * @param[in] a The left-bottom vertex of the box
		 * @param[in] b The right-top vertex of the box
		 * @brief  Build a box in 3D space.
		 * @throw
		 */
		inline Box3D(const FloatVertex3u & a, const FloatVertex3u & b);

		/**
		 * @fn Box3D(const Box3D & copy)
		 * @param[in] copy The box to copy from.
		 * @brief Default copy constructor.
		 * @throw
		 */
		Box3D(const Box3D & copy) = default;

		/**
		 * @fn Box3D(Box3D && move) noexcept
		 * @param[in] move The box to move.
		 * @brief Default move constructor.
		 * @throw noexcept
		 */
		Box3D(Box3D && move) noexcept = default;

		/**
		 * @fn ~Box3D() noexcept
		 * @brief Default destructor.
		 * @throw noexcept
		 */
		~Box3D() noexcept = default;

		/**
		 * @fn Box3D & operator=(const Box3D & copy)
		 * @param[in] copy The box to copy from.
		 * @return The box copied.
		 * @brief Default copy assignment operator.
		 * @throw
		 */
		Box3D & operator=(const Box3D & copy) = default;

		/**
		 * @fn Box3D & operator=(Box3D && move) noexcept
		 * @param[in] move The box to move.
		 * @return The box moved.
		 * @brief Default move assignment operator.
		 * @throw noexcept
		 */
		Box3D & operator=(Box3D && move) noexcept = default;

		/**
		 * @fn FloatVertex3u getCenter() const
		 * @return The center of the box.
		 * @brief Get the center of the box as a 3D vertex.
		 * @throw noexcept.
		 */
		inline FloatVertex3u getCenter() const noexcept;

	private:
		/**
		 * @property a
		 * @brief The left-bottom vertex of the box.
		 */
		FloatVertex3u a;

		/**
		 * @property b
		 * @brief The right-top vertex of the box.
		 */
		FloatVertex3u b;
	};
}

#include "utility/mathematics/box3d.inl"

#endif // BOX3D_HPP
