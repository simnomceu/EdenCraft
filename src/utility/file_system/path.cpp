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
 * @file utility/file_system/path.cpp
 * @author IsilinBN (casa2pir@hotmail.fr)
 * @date December, 12th 2017
 * @copyright ----------
 * @brief Describe path to any location in the file system.
 */

#include "utility/file_system/path.hpp"

#ifdef __linux__
	#include <unistd.h>
#else
	#include <Windows.h>
#endif

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>

namespace ece
{

	Path Path::currentPath()
	{
		std::string path;
		// BERK
#ifdef __linux__
		char result[FILENAME_MAX];
		ssize_t count = readlink("/proc/self/exe", result, FILENAME_MAX);
		path = std::string(result, (count > 0) ? count : 0);
#else
		wchar_t wresult[FILENAME_MAX];
		char result[FILENAME_MAX];
		int size = GetModuleFileName(NULL, wresult, FILENAME_MAX);
		size_t copiedSize;
		auto error = wcstombs_s(&copiedSize, result, FILENAME_MAX, wresult, size);
		path = std::string(result, size);
#endif
		return Path(path);
	}

	Path::Path(const std::string & pathname): path()
	{
		// BERK
		auto result = std::back_inserter(this->path);
		std::stringstream ss;
		ss.str(pathname);
		std::string item;
		while (std::getline(ss, item, '\\')) {
			*(result++) = item;
		}
	}

	std::string Path::getPathname() const
	{
		std::stringstream res;
		std::copy(this->path.begin(), this->path.end(), std::ostream_iterator<std::string>(res, "\\"));
		std::string  result = res.str();
		return result.substr(0, result.size() - 1);
	}

	std::string Path::getPath() const {
		std::stringstream res;
		std::copy(this->path.begin(), this->path.end() - 1, std::ostream_iterator<std::string>(res, "\\"));
		std::string  result = res.str() + '\\';
		return result.substr(0, result.size() - 1);
	}
}
