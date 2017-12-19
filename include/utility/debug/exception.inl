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
 * @file utility/debug/exception.inl
 * @author IsilinBN (casa2pir@hotmail.fr)
 * @date November, 28th 2017
 * @copyright ----------
 * @brief Generic exception constructor and set of exceptions used in Edencraft libraries.
 *
 * @remark Another pattern should be used to implements the set of exceptions. Indeed, the scalability is not take into account.
 *
 */

#include <sstream>
#include <iostream>

namespace ece
{
	inline Exception::Exception() : std::runtime_error(""), message() {}

	template<class ...Args>
	inline void Exception::setMessage(const std::string & message, Args ...args) noexcept
	{
		this->message = this->mapString(message, args...);
	}

	inline const char * Exception::what() const noexcept { return this->message.data(); }

	inline std::string Exception::mapString(const std::string & content) noexcept { return content; }

	template <class V, class... Args>
	std::string Exception::mapString(const std::string & content, V value, Args... args) noexcept
	{
		/* Look for the next '%' tag to bind. */
		auto pos = content.find_first_of("%");
		if (pos != std::string::npos) {
			std::string end;
			try {
				/* If there is one, replace it. */
				std::stringstream stream;
				stream << value;
				/* The new content with the recursive result of the others arguments to bind. */
				end = stream.str() + this->mapString(content.substr(pos + 1), args...);
			}
			catch (std::exception & e) {
				// TODO what ?
				std::cerr << "Error with parsing exception argument: " << e.what() << std::endl;
			}
			/* And then return  */
			return content.substr(0, pos) + end;
		}
		/* Else, just return the current content. */
		return content;
	}
}
