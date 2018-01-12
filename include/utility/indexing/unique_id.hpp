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
 * @file utility/indexing/unique_id.hpp
 * @author IsilinBN (casa2pir@hotmail.fr)
 * @date December, 28th 2017
 * @copyright ----------
 * @brief A class to manage unique IDs, considering limited memory.
 */

#ifndef UNIQUE_ID_HPP
#define UNIQUE_ID_HPP

#include <deque>

namespace ece
{
	/**
	 * @class UniqueID
	 * @extends std::deque<unsigned int>
	 * @brief Manage unique IDs, considering limited memory.
	 */
	class UniqueID : protected std::deque<unsigned int>
	{
	public:
		/**
		 * @fn UniqueID()
		 * @brief Default constructor.
		 * @throw bad_alloc
		 * Initialize the unique ID generator. The next ID get will be 0.
		 */
		inline UniqueID();

		/**
		 * @fn UniqueID(const unsigned int start)
		 * @param[in] start The minimum ID to get.
		 * @brief Build the unique ID generator, with a minimum ID.
		 * @throw bad_alloc
		 */
		inline UniqueID(const unsigned int start);
		
		/**
		 * @fn UniqueID(const UniqueID & copy)
		 * @param[in] copy The unique ID generator to copy from.
		 * @brief Default copy constructor.
		 * @throw bad_alloc
		 */
		UniqueID(const UniqueID & copy) = default;
		
		/**
		 * @fn UniqueID(UniqueID && move)
		 * @param[in] move The unique ID generator to move.
		 * @brief Default move constructor.
		 * @throw bad_alloc
		 */
		UniqueID(UniqueID && move) = default;
		
		/**
		 * @fn ~UniqueID()
		 * @brief Default destructor.
		 * @throw noexcept
		 */
		~UniqueID() noexcept = default;

		/**
		 * @fn UniqueID & operator=(const UniqueID & copy)
		 * @param[in] copy The unique ID generator to copy from.
		 * @return The generator copied.
		 * @brief Default copy assignment operator.
		 * @throw bad_alloc
		 */
		UniqueID & operator=(const UniqueID & copy) = default;
		
		/**
		 * @fn UniqueID & operator=(UniqueID && move)
		 * @param[in] move The unique ID generator to move.
		 * @return The generator moved.
		 * @brief Default move assignment operator.
		 * @throw noexcept
		 */
		UniqueID & operator=(UniqueID && move) noexcept = default;

		/**
		 * @fn unsigned int next()
		 * @return An unused unique ID.
		 * @brief Get the next unused Id available.
		 * @throw bad_alloc
		 */
		unsigned int next();
		
		/**
		 * @fn void restack(const unsigned int value)
		 * @param[in] value The ID to to re-use.
		 * @brief Make available a specific ID.
		 * @throw bad_alloc.
		 * This ID will be used before generating new IDs.
		 */
		void restack(const unsigned int value);

		/**
		* @see http://en.cppreference.com/w/cpp/container/deque/size
		*/
		using std::deque<unsigned int>::size;

		/**
		* @see http://en.cppreference.com/w/cpp/container/deque/clear
		*/
		using std::deque<unsigned int>::clear;
	};
}

#include "utility/indexing/unique_id.inl"

#endif // UNIQUE_ID_HPP