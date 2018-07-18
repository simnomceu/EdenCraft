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

#ifndef LOADER_HPP
#define LOADER_HPP

#include "utility/config.hpp"

#include <string>

namespace ece
{
	namespace utility
	{
		namespace file_system
		{
			/**
			 * @class Loader
			 * @brief
			 */
			class ECE_UTILITY_API Loader
			{
			public:
				/**
				 * @fn constexpr Loader() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				constexpr Loader() noexcept = default;

				/**
				 * @fn Loader(const Loader & copy) noexcept
				 * @param[in] copy The Loader to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				Loader(const Loader & copy) noexcept = default;

				/**
				 * @fn Loader(Loader && move) noexcept
				 * @param[in] move The Loader to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				Loader(Loader && move) noexcept = default;

				/**
				 * @fn ~Loader() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~Loader() noexcept = default;

				/**
				 * @fn Loader & operator=(const Loader & copy) noexcept
				 * @param[in] copy The Loader to copy from.
				 * @return The Loader copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				Loader & operator=(const Loader & copy) noexcept = default;

				/**
				 * @fn Loader & operator=(Loader && move) noexcept
				 * @param[in] move The Loader to move.
				 * @return The Loader moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				Loader & operator=(Loader && move) noexcept = default;

        		/**
        		 * @fn void loadFromFile(const std::string & filename)
        		 * @param[in] filename The name of the file to load data from.
        		 * @brief Load and parse data from a file.
        		 * @throw
        		 */
        		virtual void loadFromFile(const std::string & filename) = 0;

        		/**
        		 * @fn void loadFromString(const std::string & content)
        		 * @param[in] content The string content to load data from.
        		 * @brief Load and parse data from a string.
        		 * @throw
        		 */
        		virtual void loadFromString(const std::string & content) = 0;

        		/**
        		 * @fn void loadFromMemory(const void * content)
        		 * @param[in] content The memory buffer to load data from.
        		 * @brief Load and parse data from memory.
        		 * @throw
        		 */
        		virtual void loadFromMemory(const void * content) = 0;
			};
		} // namespace file_system
	} // namespace utility
} // namespace ece

#endif // LOADER_HPP