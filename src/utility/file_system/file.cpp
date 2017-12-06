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
 * @file utility/file_system/file.cpp
 * @author IsilinBN (casa2pir@hotmail.fr)
 * @date December, 1st 2017
 * @copyright ----------
 * @brief Encapsulates the file resource in a class.
 *
 */

#include "utility/file_system/file.hpp"

#include "utility/debug/exception.hpp"

#include <iostream>
#ifdef __linux__
	#include <sys/stat.h>
#endif

namespace ece
{
	File::File(const File & copy) : filename(copy.filename), stream()
	{
		this->stream.copyfmt(copy.stream);
		this->stream.clear(copy.stream.rdstate());
		this->stream.basic_fstream<char>::basic_ios<char>::rdbuf(stream.rdbuf());
	}

	File & File::operator=(const File & copy)
	{
		this->filename = copy.filename;
		this->stream.copyfmt(copy.stream);
		this->stream.clear(copy.stream.rdstate());
		this->stream.basic_fstream<char>::basic_ios<char>::rdbuf(stream.rdbuf());
		return *this;
	}

	File & File::operator=(File && move)
	{
		this->filename = std::move(move.filename);
		this->stream = std::move(move.stream);
		move.close();
		return *this;
	}

	const bool File::open(const std::string & filename, const OpenMode & mode)
	{
		this->stream.close();
		if (!File::exists(filename)) {
			throw FileException(BAD_PATH, filename);
		}
		this->filename = filename;
		this->stream.open(this->filename, static_cast<std::ios_base::openmode>(mode));
		return this->isOpen();
	}

	void File::close()
	{
		if (this->isOpen()) {
			this->stream.close();
		}
	}

	std::string File::parseToString()
	{
		std::string content = "";
		if (this->isOpen()) {
			while (this->stream.good()) {
				std::string line;
				std::getline(this->stream, line);
				content.append(line + "\n");
			}
		}
		return content;
	}

	template<>
	std::vector<FloatVertex3u> File::parseToVector<FloatVertex3u>()
	{
		std::vector<FloatVertex3u> content;
		if (this->isOpen()) {
			FloatVertex3u value;
			try {
				while (this->stream.good()) {
					*this >> value[X] >> value[Y] >> value[Z];
					content.push_back(value);
				}
			}
			catch (std::exception & e) {
				throw FileException(PARSE_ERROR, this->filename + " (" + e.what() + ")");
			}
		}
		return content;
	}

	const bool File::exists(const std::string & filename)
	{
		struct stat info;
		int ret = -1;

		ret = stat(filename.c_str(), &info);
		return 0 == ret;
	}
}
