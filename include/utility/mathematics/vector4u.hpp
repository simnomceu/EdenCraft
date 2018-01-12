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
 * @file utility/mathematics/vector4u.hpp
 * @author IsiliBN (casa2pir@hotmail.fr)
 * @date January, 8th 2017
 * @copyright ----------
 * @brief A 4D specialization of Vector.
 **/

#ifndef VERTEX4U_HPP
#define VERTEX4U_HPP

#include "utility/mathematics/vector.hpp"

namespace ece
{
	/**
	 * @typedef Vector4u
	 * @brief A 4D Vector.
	 */
	template <class T>
	using Vector4u = Vector<T, 4>;

	/**
	 * @typedef IntVector4u
	 */
	using IntVector4u = Vector4u<int>;

	/**
	 * @typedef UintVector4u
	 */
	using UintVector4u = Vector4u<unsigned int>;

	/**
	 * @typedef FloatVector4u
	 */
	using FloatVector4u = Vector4u<float>;

	/**
	 * @typedef DoubleVector4u
	 */
	using DoubleVector4u = Vector4u<double>;

	template <class T>
	[[deprecated]] using Vertex4u = Vector4u<T>;

	using IntVertex4u = IntVector4u;
	using UintVertex4u = UintVector4u;
	using FloatVertex4u = FloatVector4u;
	using DoubleVertex4u = DoubleVector4u;
}

#endif // VERTEX4U_HPP
