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

namespace ece
{
	namespace utility
	{
		namespace string
		{
			template <class T>
			T from_string(std::string value)
			{
				throw std::runtime_error("No conversion defined from string to this type.");
			}
			
			template <> inline short from_string(std::string value) { return static_cast<short>(std::stoi(value)); }
			
			template <> inline unsigned short from_string(std::string value) { return static_cast<unsigned short>(std::stoi(value)); }
			
			template <> inline int from_string(std::string value) { return std::stoi(value); }
			
			template <> inline unsigned int from_string(std::string value) { return static_cast<unsigned int>(std::stoi(value)); }
			
			template <> inline long from_string(std::string value) { return std::stol(value); }
			
			template <> inline unsigned long from_string(std::string value) { return std::stoul(value); }
			
			template <> inline long long from_string(std::string value) { return std::stoll(value); }
			
			template <> inline unsigned long long from_string(std::string value) { return std::stoull(value); }
			
			template <> inline float from_string(std::string value) { return std::stof(value); }
			
			template <> inline double from_string(std::string value) { return std::stod(value); }
			
			template <> inline long double from_string(std::string value) { return std::stold(value); }
			
			template <> inline bool from_string(std::string value) { return static_cast<bool>(std::stoi(value)); }
		} // namespace string
	} // namespace utility
} // namespace ece
