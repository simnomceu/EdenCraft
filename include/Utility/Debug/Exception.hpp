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

#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <stdexcept>
#include <string>
#include "Type.hpp"

namespace ece
{
	template <class T>
	class Exception : protected std::runtime_error
	{
	public:
		using std::runtime_error::what;

		inline Exception(const std::string & whatArg);

		template<class... Args>
		static T makeException(const std::string & message, Args... args);

	private:
		inline static std::string mapString(const std::string & content);

		template <class V, class... Args>
		static std::string mapString(const std::string & content, V value, Args... args);
	};

	class FileException : public Exception<FileException>
	{
	public:
		static FileException makeException(const FileCodeError codeError, const std::string & filename);
	};

	class BadInputException : public Exception<BadInputException>
	{
	public:
		static BadInputException makeException(const std::string & details);
	};

	class InitializationException : public Exception<InitializationException>
	{
	public:
		static InitializationException makeException(const std::string & target);
	};

	class MemoryAccessException : public Exception<MemoryAccessException>
	{
	public:
		static MemoryAccessException makeException(const std::string & target);
		static MemoryAccessException makeException(const std::string & target, const std::string & origin);
	};

	class OutOfRangeException : public Exception<OutOfRangeException>
	{
	public:
		static OutOfRangeException makeException(const std::string & type);
		static OutOfRangeException makeException(const std::string & type, const int id);
	};

	class ResourceException : public Exception<ResourceException>
	{
	public:
		static ResourceException makeException(const std::string & target, const unsigned short int id);
	};

	class DivideByZeroException : public Exception<DivideByZeroException>
	{
	public:
		static DivideByZeroException makeException(const std::string & origin);
	};
}

#include "Debug\Exception.inl"

#endif // EXCEPTION_HPP