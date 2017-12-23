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
 * @file utility/indexing/index2u.hpp
 * @author IsilinBN (casa2pir@hotmail.fr)
 * @date December, 19th 2017
 * @copyright ----------
 * @brief A 2D index key.
 *
 */

#ifndef INDEX2U_HPP
#define INDEX2U_HPP

namespace ece
{
	/**
	 * @class Index2u
	 * @brief
	 * @remark This class need to be refactored to be usable in others classes like Matrix.
	 */
	class Index2u
	{
	public:
		/**
		 * @fn Index2u()
		 * @brief
		 * @throw noexcept
		 */
		inline constexpr Index2u() noexcept;
		
		/**
		 * @fn Index2u(const int i, const int j)
		 * @param[in] i
		 * @param[in] j
		 * @brief
		 * @throw noexcept
		 */
		inline Index2u(const int i, const int j) noexcept;

		/**
		 * @fn Index2u(const Index2u & copy)
		 * @param[in] copy
		 * @brief
		 * @throw noexcept
		 */
		Index2u(const Index2u & copy) noexcept = default;

		/**
		 * @fn Index2u(Index2u && move)
		 * @param[in] move
		 * @brief
		 * @throw noexcept
		 */
		Index2u(Index2u && move) noexcept = default;

		/**
		 * @fn ~Index2u()
		 * @brief
		 * @throw noexcept
		 */
		~Index2u() noexcept = default;

		/**
		 * @fn Index2u & operator=(const Index2u & copy)
		 * @param[in] copy
		 * @return
		 * @brief
		 * @throw noexcept
		 */
		Index2u & operator=(const Index2u & copy) noexcept = default;

		/**
		 * @fn Index2u & operator=(Index2u && move)
		 * @param[in] move
		 * @return
		 * @brief
		 * @throw noexcept
		 */
		Index2u & operator=(Index2u && move) noexcept = default;

		/**
		 * @fn int get(const int maxI)
		 * @param[in] maxI
		 * @return
		 * @brief
		 * @throw noexcept
		 */
		inline int get(const int maxI) noexcept;

		/**
		 * @fn void set(const int maxI, const int index)
		 * @param[in] maxI
		 * @param[in] index
		 * @brief
		 * @throw 
		 */
		inline void set(const int maxI, const int index);

		/**
		 * @property i
		 * @brief
		 */
		unsigned int i;

		/**
		 * @property j
		 * @brief
		 */
		unsigned int j;
	};
}

#include "utility/indexing/index2u.inl"

#endif // INDEX2U_HPP
