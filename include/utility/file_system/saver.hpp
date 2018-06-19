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

#ifndef SAVER_HPP
#define SAVER_HPP

#include <string>

namespace ece
{
	namespace utility
	{
		namespace file_system
		{
			/**
			 * @class Saver
			 * @brief
			 */
			class Saver
			{
			public:
				/**
				 * @fn constexpr Saver() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				constexpr Saver() noexcept = default;

				/**
				 * @fn Saver(const Saver & copy) noexcept
				 * @param[in] copy The Saver to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				Saver(const Saver & copy) noexcept = default;

				/**
				 * @fn Saver(Saver && move) noexcept
				 * @param[in] move The Saver to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				Saver(Saver && move) noexcept = default;

				/**
				 * @fn ~Saver() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~Saver() noexcept = default;

				/**
				 * @fn Saver & operator=(const Saver & copy) noexcept
				 * @param[in] copy The Saver to copy from.
				 * @return The Saver copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				Saver & operator=(const Saver & copy) noexcept = default;

				/**
				 * @fn Saver & operator=(Saver && move) noexcept
				 * @param[in] move The Saver to move.
				 * @return The Saver moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				Saver & operator=(Saver && move) noexcept = default;

        		/**
        		 * @fn void saveToFile(const std::string & filename)
        		 * @param[out] filename The name of the file to save into.
        		 * @brief Formate and save data into a file.
        		 * @throw
        		 */
        		virtual void saveToFile(const std::string & filename) = 0;

        		/**
        		 * @fn void saveToString(std::string & content)
        		 * @param[out] content The string buffer to save into.
        		 * @brief Formate and save data into a string buffer.
        		 * @throw
        		 */
        		virtual void saveToString(std::string & content) = 0;

        		/**
        		 * @fn void saveToMemory(void * content)
        		 * @param[out] content The memory to save into.
        		 * @brief Formate and save data into memory.
        		 * @throw
        		 */
        		virtual void saveToMemory(void * content) = 0;
			};
		} // namespace file_system
	} // namespace utility
} // namespace ece

#endif // SAVER_HPP