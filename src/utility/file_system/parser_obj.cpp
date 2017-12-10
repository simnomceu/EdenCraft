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

#include "utility/file_system/file.hpp"
#include "utility/enum.hpp"

#include <fstream>
#include <sstream>

#ifdef __linux__
	#define sscanf_s sscanf
#endif


namespace ece
{
	void ParserOBJ::loadFromFile(const std::string & filename)
	{
		File file(filename);

		Mesh * current = nullptr;

		std::string line = file.getLine(), command;
		while (!line.empty()) {
			if (line.size() >= 2) {
				command = line.substr(0, 2);
				std::istringstream stream(line.substr(2));

				// TODO add checks for the format of the file

				if (command == "v ") {
					if (!current) {
						this->meshes.push_back(Mesh());
						current = &this->meshes.back();
					}
					FloatVertex3u tmp;
					stream >> tmp[0] >> tmp[1] >> tmp[2];
					current->positions.push_back(tmp);
				}
				else if (command == "vt") {
					if (!current) {
						this->meshes.push_back(Mesh());
						current = &this->meshes.back();
					}
					FloatVertex2u tmp;
					stream >> tmp[0] >> tmp[1];
					current->textures.push_back(tmp);
				}
				else if (command == "vn") {
					if (!current) {
						this->meshes.push_back(Mesh());
						current = &this->meshes.back();
					}
					FloatVertex3u tmp;
					stream >> tmp[0] >> tmp[1] >> tmp[2];
					current->normals.push_back(tmp);
				}
				else if (command == "f ") {
					if (!current) {
						this->meshes.push_back(Mesh());
						current = &this->meshes.back();
					}
					Face tmp;
					
					sscanf_s(line.substr(2).c_str(), "%i/%i/%i %i/%i/%i %i/%i/%i", &tmp.position[0], &tmp.normal[0], &tmp.texture[0],
																				   &tmp.position[1], &tmp.normal[1], &tmp.texture[1],
																				   &tmp.position[2], &tmp.normal[2], &tmp.texture[2]);
					current->faces.push_back(tmp);

					// TODO check that it uses existing vertices, normales, and textures.
				}
				else if (command == "g ") {
					current->submesh.push_back(Mesh());
					// TODO add name of the group and parent mesh
					current = &current->submesh.back();
				}
				else if (command == "o ") {
					this->meshes.push_back(Mesh());
					// TODO add name of the group and parent mesh
					current = &this->meshes.back();
				}
				else if (line.size() > 6 && line.substr(0, 6) == "usemtl") {

				}
			}
			line = file.getLine();
		}
		// TODO care about objects groups and faces groups
	}
}
