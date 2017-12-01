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

#include "utility/file_system/parser_obj.hpp"

#include "utility/debug/exception.hpp"
#include "utility/enum.hpp"

#include <fstream>
#include <sstream>

#ifdef __linux__
	#define sscanf_s sscanf
#endif

namespace ece
{
	void ParserOBJ::open(const std::string & pathname)
	{

		std::ifstream file(pathname, std::ios::out);
		if (!file.is_open()) {
			throw FileException(FileCodeError::BAD_PATH, pathname);
		}
		std::string line, command;
		while (file.good()) {
			getline(file, line);
			if (line.size() >= 2) {
				command = line.substr(0, 2);
				std::istringstream stream(line.substr(2));

				// TODO add checks for the format of the file

				if (command == "v ") {
					float vertice[3];
					stream >> vertice[0] >> vertice[1] >> vertice[2];
					vertices.push_back(vertice[0]);
					vertices.push_back(vertice[1]);
					vertices.push_back(vertice[2]);
				}
				else if (command == "vt") {
					float texture[2];
					stream >> texture[0] >> texture[1];
					textures.push_back(texture[0]);
					textures.push_back(texture[1]);
				}
				else if (command == "vn") {
					float normale[3];
					stream >> normale[0] >> normale[1] >> normale[2];
					normales.push_back(normale[0]);
					normales.push_back(normale[1]);
					normales.push_back(normale[2]);
				}
				else if (command == "f ") {
					int face[9];
					sscanf_s(line.substr(2).c_str(), "%i/%i/%i %i/%i/%i %i/%i/%i", &face[0], &face[1], &face[2], &face[3], &face[4],
						&face[5], &face[6], &face[7], &face[8]);
					faces.push_back(face[0] * 3);
					//faces.push_back(face[1]);
					//faces.push_back(face[2]);
					faces.push_back(face[3] * 3);
					//faces.push_back(face[4]);
					//faces.push_back(face[5]);
					faces.push_back(face[6] * 3);
					//faces.push_back(face[7]);
					//faces.push_back(face[8]);

					// TODO check that it uses existing vertices, normales, and textures.
				}
				else if (command == "g ") {

				}
				else if (command == "o ") {

				}
				else if (line.size() > 6 && line.substr(0, 6) == "usemtl") {

				}
			}
		}
		// TODO care about objects groups and faces groups
	}
}
