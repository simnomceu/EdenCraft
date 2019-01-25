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

#include "utility/pch.hpp"
#include "utility/formats/wavefront/parser_mtl.hpp"

namespace ece
{
	namespace utility
	{
		namespace formats
		{
			namespace wavefront
			{
				void ParserMTL::load(std::istream & stream)
				{
					auto line = std::vector<char>(std::numeric_limits<short>::max());
					StringStream lineStream("");
					do {
						stream.getline(line.data(), std::numeric_limits<short>::max(), '\n');
						lineStream.str(line.data());
						this->processLine(lineStream);
					} while (stream.good());
				}

				void ParserMTL::save(std::ostream & stream)
				{
					for (auto & material : this->_materials) {
						stream << "newmtl " << material.name << std::endl;
						stream << "Ka " << std::get<FloatVector3u>(material.ambient.value)[0] << " " << std::get<FloatVector3u>(material.ambient.value)[1] << " " << std::get<FloatVector3u>(material.ambient.value)[2] << std::endl;
						stream << "Kd " << std::get<FloatVector3u>(material.diffuse.value)[0] << " " << std::get<FloatVector3u>(material.diffuse.value)[1] << " " << std::get<FloatVector3u>(material.diffuse.value)[2] << std::endl;
						stream << "Ks " << std::get<FloatVector3u>(material.specular.value)[0] << " " << std::get<FloatVector3u>(material.specular.value)[1] << " " << std::get<FloatVector3u>(material.specular.value)[2] << std::endl;
						stream << "Tf " << std::get<FloatVector3u>(material.transmissionFilter.value)[0] << " " << std::get<FloatVector3u>(material.transmissionFilter.value)[1] << " " << std::get<FloatVector3u>(material.transmissionFilter.value)[2] << std::endl;
						stream << "illum " << material.illumination << std::endl;
						stream << "d " << material.dissolve.factor << std::endl;
						stream << "Ns " << material.specularExponent << std::endl;
						stream << "sharpness" << material.sharpness << std::endl;
						stream << "Ni" << material.opticalDensity << std::endl;
						stream << "map_Ka " << material.mapAmbient << std::endl;
						stream << "map_Kd " << material.mapDiffuse << std::endl;
						stream << "map_Ks " << material.mapSpecular << std::endl;
					}
				}

				void ParserMTL::processLine(StringStream & line)
				{
					line.ignore({ '\r', '\n', });
					if (line.str().size() >= 2) {
						std::string command;
						line >> command;

						// TODO add checks for the format of the file
						if (command == "#") {
						}
						else if (command == "newmtl") {
							std::string name;
							line >> name;
							this->_currentMaterial = this->addMaterial(name);
						}
						else {
							if (this->_currentMaterial == this->_materials.end()) {
								this->_currentMaterial = this->addMaterial("unnamed");
							}

							if (command == "Ka") {
								FloatVector3u & ambient = std::get<FloatVector3u>(this->_currentMaterial->ambient.value);
								line >> ambient[0] >> ambient[1] >> ambient[2];
							}
							else if (command == "Kd") {
								FloatVector3u & diffuse = std::get<FloatVector3u>(this->_currentMaterial->diffuse.value);
								line >> diffuse[0] >> diffuse[1] >> diffuse[2];
							}
							else if (command == "Ks") {
								FloatVector3u & specular = std::get<FloatVector3u>(this->_currentMaterial->specular.value);
								line >> specular[0] >> specular[1] >> specular[2];
							}
							else if (command == "Tf") {
								FloatVector3u & tf = std::get<FloatVector3u>(this->_currentMaterial->transmissionFilter.value);
								line >> tf[0] >> tf[1] >> tf[2];
							}
							else if (command == "illum") {
								std::string illumination;
								line >> illumination;
								this->_currentMaterial->illumination = std::stoi(illumination.substr(illumination.size() - 1, 1));
							}
							else if (command == "d") {
								line >> this->_currentMaterial->dissolve.factor;
							}
							else if (command == "Ns") {
								line >> this->_currentMaterial->specularExponent;
							}
							else if (command == "sharpness") {
								line >> this->_currentMaterial->sharpness;
							}
							else if (command == "Ni") {
								line >> this->_currentMaterial->opticalDensity;
							}
							else if (command == "map_Ka") {
								line >> this->_currentMaterial->mapAmbient;
							}
							else if (command == "map_Kd") {
								line >> this->_currentMaterial->mapDiffuse;
							}
							else if (command == "map_Ks") {
								line >> this->_currentMaterial->mapSpecular;
							}
						}
					}
				}

				auto ParserMTL::addMaterial(const std::string & name) -> std::vector<MaterialMTL>::iterator
				{
					this->_materials.emplace_back(name);
					return this->_materials.end() - 1;
				}
			} // namespace wavefront
		} // namespace formats
	} // namespace utility
} // namespace ece