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

#include "Debug\Exception.hpp"

namespace ece
{
	/* ########## FileException methods ########## */

	FileException FileException::makeException(const FileCodeError codeError, const std::string & filename)
	{
		switch (codeError) {
		case BAD_PATH:
			return Exception<FileException>::makeException("Code %. This file doesn't exist: %.", (int)codeError, filename);
			break;
		case PARSE_ERROR:
			return Exception<FileException>::makeException("Code %. Error while trying to parse %. Check the content format.", (int)codeError, filename);
			break;
		default:
			return Exception<FileException>::makeException("Code %. Undefined error on file %.", (int)codeError, filename);
			break;
		}
	}

	/* ########## BadInputException methods ########## */

	BadInputException BadInputException::makeException(const std::string & details)
	{
		return Exception<BadInputException>::makeException("Bad input: %.", details);
	}

	/* ########## InitializationException methods ########## */

	InitializationException InitializationException::makeException(const std::string & target)
	{
		return Exception<InitializationException>::makeException("% has failed to initialize.", target);
	}

	/* ########## MemoryAccessException methods ########## */

	MemoryAccessException MemoryAccessException::makeException(const std::string & target)
	{
		return Exception<MemoryAccessException>::makeException("Bad access to %. The pointer has expired.", target);
	}

	MemoryAccessException MemoryAccessException::makeException(const std::string & target, const std::string & origin)
	{
		return Exception<MemoryAccessException>::makeException("Bad access to % from %. The pointer has expired.", target, origin);
	}

	/* ########## OutOfRangeException methods ########## */

	OutOfRangeException OutOfRangeException::makeException(const std::string & type)
	{
		return Exception<OutOfRangeException>::makeException("Out of range access for %.", type);
	}

	OutOfRangeException OutOfRangeException::makeException(const std::string & type, const int id)
	{
		return Exception<OutOfRangeException>::makeException("Out of range access for % %.", type, id);
	}

	/* ########## ResourceException methods ########## */

	ResourceException ResourceException::makeException(const std::string & target, const unsigned short int id)
	{
		return Exception<ResourceException>::makeException("The resource % with the ID % is not available.", target, id);
	}

	/* ########## DivideByZeroException methods ########## */

	DivideByZeroException DivideByZeroException::makeException(const std::string & origin)
	{
		return Exception<DivideByZeroException>::makeException("A division by zero has been handle in %", origin);
	}
}
