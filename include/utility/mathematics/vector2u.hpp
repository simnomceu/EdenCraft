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
 * @file utility/mathematics/vector2u.hpp
 * @author IsiliBN (casa2pir@hotmail.fr)
 * @date January, 8th 2017
 * @copyright ----------
 * @brief A 2D specialization of Vector.
 **/

#ifndef VERTEX2U_HPP
#define VERTEX2U_HPP

#include "utility/mathematics/vector.hpp"

namespace ece
{
	/**
	 * @typedef Vector2u
	 * @brief A 2D Vector.
	 */
	template <class T>
	using Vector2u = Vector<T, 2>;

	/**
	 * @typedef IntVector2u
	 */
	using IntVector2u = Vector2u<int>;
	
	/**
	 * @typedef UintVector2u
	 */
	using UintVector2u = Vector2u<unsigned int>;
	
	/**
	 * @typedef FloatVector2u
	 */
	using FloatVector2u = Vector2u<float>;

	/**
	 * @typedef DoubleVector2u
	 */
	using DoubleVector2u = Vector2u<double>;

	template <class T>
	[[deprecated]] using Vertex2u = Vector2u<T>;

	using IntVertex2u = IntVector2u;
	using UintVertex2u = UintVector2u;
	using FloatVertex2u = FloatVector2u;
	using DoubleVertex2u = DoubleVector2u;
}

#endif // VERTEX2U_HPP
