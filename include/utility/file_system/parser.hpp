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
 * @file utility/file_system/parser.hpp
 * @author IsilinBN (casa2pir@hotmail.fr)
 * @date December, 1st 2017
 * @copyright ----------
 * @brief Interface for any parser.
 *
 */

#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>

namespace ece
{
	/**
	 * @interface Parser
	 * @brief An interface for a parser to read and write a specific format.
	 * @remark See if it is necessary to add loadFrom and saveTo with stream (and eventually, include file reading/writing as stream).
	 * @remark All member methods should be constant as they doesn't modify internally the parser.
	 */
	class Parser
	{
	public:
		/**
		 * @fn Parser()
		 * @brief Default constructor.
		 */
		Parser() = default;

		/**
		 * @fn Parser(const Parser & copy)
		 * @param[in] copy
		 * @brief Default copy constructor.
		 */
		Parser(const Parser & copy) = default;

		/**
		 * @fn Parser(Parser && move)
		 * @param[in] move
		 * @brief Default move constructor.
		 */
		Parser(Parser && move) = default;

		/**
		 * @fn ~Parser()
		 * @brief Default destructor.
		 */
		inline virtual ~Parser() noexcept = 0;

		/**
		 * @fn Parser & operator=(const Parser & copy)
		 * @param[in] copy The parser to copy from.
		 * @return The parser copied.
		 * @brief Default copy assigment operator.
		 */
		Parser & operator=(const Parser & copy) = default;

		/**
		 * @fn Parser & operator=(Parser && move)
		 * @param[in] move The parser to move.
		 * @return The parser moved.
		 * @brief Default move assigment operator.
		 */
		Parser & operator=(Parser && move) = default;

		/**
		 * @fn void loadFromFile(const std::string & filename)
		 * @param[in] filename The name of the file to load data from.
		 * @brief Load and parse data from a file.
		 */
		virtual void loadFromFile(const std::string & filename) = 0;

		/**
		 * @fn void loadFromString(const std::string & content)
		 * @param[in] content The string content to load data from.
		 * @brief Load and parse data from a string.
		 */
		virtual void loadFromString(const std::string & content) = 0;

		/**
		 * @fn void loadFromMemory(const void * content)
		 * @param[in] content The memory buffer to load data from.
		 * @brief Load and parse data from memory.
		 */
		virtual void loadFromMemory(const void * content) = 0;

		/**
		 * @fn void saveToFile(const std::string & filename)
		 * @param[out] filename The name of the file to save into.
		 * @brief Formate and save data into a file.
		 */
		virtual void saveToFile(const std::string & filename) = 0;

		/**
		 * @fn void saveToString(std::string & content)
		 * @param[out] content The string buffer to save into.
		 * @brief Formate and save data into a string buffer.
		 */
		virtual void saveToString(std::string & content) = 0;

		/**
		 * @fn void saveToMemory(void * content)
		 * @param[out] content The memory to save into.
		 * @brief Formate and save data into memory.
		 */
		virtual void saveToMemory(void * content) = 0;
	};
}

#include "utility/file_system/parser.inl"

#endif // PARSER_HPP
