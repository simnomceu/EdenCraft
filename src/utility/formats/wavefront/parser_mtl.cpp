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

#include "utility/formats/wavefront/parser_mtl.hpp"

#include <iostream>
#include <sstream>
#include <string>

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
					std::string line;
					while (stream.good()) {
						std::getline(stream, line);
						this->processLine(line);
					}
				}

				void ParserMTL::save(std::ostream & stream)
				{
					for (auto & material : this->_materials) {
						stream << "newmtl " << material.getName() << std::endl;
						stream << "Ka " << material.getAmbientFactor()[0] << " " << material.getAmbientFactor()[1] << " " << material.getAmbientFactor()[2] << std::endl;
						stream << "Kd " << material.getDiffuseFactor()[0] << " " << material.getDiffuseFactor()[1] << " " << material.getDiffuseFactor()[2] << std::endl;
						stream << "Ks " << material.getSpecularFactor()[0] << " " << material.getSpecularFactor()[1] << " " << material.getSpecularFactor()[2] << std::endl;
						stream << "Tf " << material.getTransmissionFilter()[0] << " " << material.getTransmissionFilter()[1] << " " << material.getTransmissionFilter()[2] << std::endl;
						stream << "illum " << material.getIllumination() << std::endl;
						stream << "d " << material.getDissolveFactor() << std::endl;
						stream << "Ns " << material.getSpecularExponent() << std::endl;
						stream << "sharpness" << material.getSharpness() << std::endl;
						stream << "Ni" << material.getOpticalDensity() << std::endl;
						stream << "map_Ka " << material.getAmbientMap() << std::endl;
						stream << "map_Kd " << material.getDiffuseMap() << std::endl;
						stream << "map_Ks " << material.getSpecularMap() << std::endl;
					}
				}

				void ParserMTL::processLine(const std::string & line)
				{
					if (line.size() >= 2) {
						std::string command = line.substr(0, line.find_first_of(' ')); //line.substr(0, 2);
						std::istringstream stream(line.substr(line.find_first_of(' ') + 1));

						// TODO add checks for the format of the file

						if (command == "newmtl") {
							std::string name;
							stream >> name;
							this->_currentMaterial = this->addMaterial(name);
						}
						else {
							if (this->_currentMaterial == this->_materials.end()) {
								this->_currentMaterial = this->addMaterial("unnamed");
							}

							if (command == "Ka") {
								FloatVector3u ambient;
								stream >> ambient[0] >> ambient[1] >> ambient[2];
								this->_currentMaterial->setAmbientFactor(ambient);
							}
							else if (command == "Kd") {
								FloatVector3u diffuse;
								stream >> diffuse[0] >> diffuse[1] >> diffuse[2];
								this->_currentMaterial->setDiffuseFactor(diffuse);
							}
							else if (command == "Ks") {
								FloatVector3u specular;
								stream >> specular[0] >> specular[1] >> specular[2];
								this->_currentMaterial->setSpecularFactor(specular);
							}
							else if (command == "Tf") {
								FloatVector3u tf;
								stream >> tf[0] >> tf[1] >> tf[2];
								this->_currentMaterial->setTransmissionFilter(tf);
							}
							else if (command == "illum") {
								std::string illumination;
								stream >> illumination;
								this->_currentMaterial->setIllumination(std::stoi(illumination.substr(illumination.size() - 1, 1)));
							}
							else if (command == "d") {
								float dissolve;
								stream >> dissolve;
								this->_currentMaterial->setDissolveFactor(dissolve);
							}
							else if (command == "Ns") {
								float exponent;
								stream >> exponent;
								this->_currentMaterial->setSpecularExponent(exponent);
							}
							else if (command == "sharpness") {
								unsigned int sharpness;
								stream >> sharpness;
								this->_currentMaterial->setSharpness(sharpness);
							}
							else if (command == "Ni") {
								float density;
								stream >> density;
								this->_currentMaterial->setOpticalDensity(density);
							}
							else if (command == "map_Ka") {
								std::string path;
								stream >> path;
								this->_currentMaterial->setAmbientMap(path);
							}
							else if (command == "map_Kd") {
								std::string path;
								stream >> path;
								this->_currentMaterial->setDiffuseMap(path);
							}
							else if (command == "map_Ks") {
								std::string path;
								stream >> path;
								this->_currentMaterial->setSpecularMap(path);
							}
						}
					}
				}

				std::vector<MaterialMTL>::iterator ParserMTL::addMaterial(const std::string & name)
				{
					this->_materials.emplace_back(name);
					return this->_materials.end() - 1;
				}
			} // namespace wavefront
		} // namespace formats
	} // namespace utility
} // namespace ece