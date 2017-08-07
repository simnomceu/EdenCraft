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

#include <sstream>

namespace ece
{
	template <class T>
	inline Exception<T>::Exception(const std::string & whatArg) : std::runtime_error(whatArg) { }

	template <class T>
	template <class ...Args>
	static T Exception<T>::makeException(const std::string & message, Args... args)
	{
		return static_cast<T&>(Exception<T>(mapString(message, args...)));
	}

	template <class T>
	inline std::string Exception<T>::mapString(const std::string & content) { return content; }

	template <class T>
	template <class V, class... Args>
	std::string Exception<T>::mapString(const std::string & content, V value, Args... args)
	{
		/* Look for the next '%' tag to bind. */
		auto pos = content.find_first_of("%");
		if (pos != std::string::npos) {
			/* If there is one, replace it. */
			std::stringstream stream;
			stream << value;
			/* And then return the new content with the recursive result of the others arguments to bind. */
			return content.substr(0, pos) + stream.str() + Exception<T>::mapString(content.substr(pos + 1), args...);
		}
		/* Else, just return the current content. */
		return content;
	}
}