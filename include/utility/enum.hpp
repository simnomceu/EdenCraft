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

#ifndef UTILITY_ENUM_HPP
#define UTILITY_ENUM_HPP

#include "utility/enumeration/enum_count.hpp"
#include "utility/enumeration/enum_flags.hpp"

#include <fstream>

namespace ece
{
	using namespace utility::enumeration;

    namespace utility
    {
    	/**
    	* @enum OpenMode
    	* @brief Alias to Standard Library openmode.
    	* @see http://en.cppreference.com/w/cpp/io/ios_base/openmode
    	*/
    	EnumFlagsT(/*std::ios_base::openmode*/unsigned short int, OpenMode)
    	{
    		app = std::fstream::app, /*< @brief "Seek to the end of stream before each write". */
    		binary = std::fstream::binary, /*< @brief "Open in binary mode". */
    		in = std::fstream::in, /*< @brief "Open for reading". */
    		out = std::fstream::out, /*< @brief "Open for writing". */
    		trunc = std::fstream::trunc, /*< @brief "Discard the contents of the stream when opening". */
    		ate = std::fstream::ate /*< @brief "Seek to the end of stream immediately after open". */
    	};

    	enum FileCodeError : unsigned short int
    	{
    		BAD_PATH = 0,
    		PARSE_ERROR = 1
    	};

    	enum TypeNodeJSON : unsigned short int
    	{
    		NULL_JSON = 0,
    		BOOLEAN_JSON = 1,
    		INTEGER_JSON = 2,
    		DOUBLE_JSON = 3,
    		STRING_JSON = 4,
    		OBJECT_JSON = 5,
    		ARRAY_JSON = 6
    	};
    } // namespace utility
} // namespace ece

#endif // UTILITY_ENUM_HPP
