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

#include "utility/wavefront/parser_mtl.hpp"

#include <iostream>
#include <sstream>
#include <string>

namespace ece
{
	namespace utility
	{
		namespace wavefront
		{
			void ParserMTL::load(std::istream & stream)
			{
				std::string line;
				while (stream.good()) {
					std::getline(stream, line);
					this->processLine(line);
				}
			}

			void ParserMTL::save(std::ostream & /*stream*/)
			{
				/* NOT IMPLEMENTED YET*/
			}

			void ParserMTL::processLine(const std::string & line)
			{
				if (line.size() >= 2) {
					std::string command = line.substr(0, 2);
					std::istringstream stream(line.substr(2));

					// TODO add checks for the format of the file

					if (command == "ne") {
						const std::string end = "wmtl";
						std::string confirm;
						stream.read(confirm.data(), end.size());
						if (confirm == end) {
							std::string name;
							stream >> name;
							this->_currentMaterial = this->addMaterial(name);
						}
					}
					else if (command == "ka") {
					}
					else if (command == "kd") {
					}
					else if (command == "ks") {
					}
				}
			}

			std::vector<MaterialMTL>::iterator ParserMTL::addMaterial(const std::string & name)
			{
				this->_materials.emplace_back(name);
				return this->_materials.end() - 1;
			}
		} // namespace wavefront
	} // namespace utility
} // namespace ece