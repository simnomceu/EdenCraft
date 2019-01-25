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
#include "utility/formats/wavefront/parser_obj.hpp"
#include "utility/formats/wavefront/parser_mtl.hpp"

namespace ece
{
	namespace utility
	{
		namespace formats
		{
			namespace wavefront
			{
				void ParserOBJ::load(std::istream & stream)
				{
					char line[std::numeric_limits<short>::max()];
					StringStream lineStream("");
					do {
						stream.getline(line, std::numeric_limits<short>::max());
						lineStream.str(line);
						if (lineStream.str().size() >= 2) {
							this->processLine(lineStream);
						}
					} while (stream.good());
					// TODO care about objects groups and faces groups
				}

				void ParserOBJ::save(std::ostream & stream)
				{
					for (auto & material : this->_materials) {
						stream << "mtllib " << material << std::endl;
					}

					for (auto & object : this->_objects) {
						stream << "o " << object.getName() << std::endl << std::endl;

						for (auto & vertex : object.getVertices()) {
							stream << "v " << vertex[0] << " " << vertex[1] << " " << vertex[2] << " " << vertex[3] << std::endl;
						}
						stream << std::endl;

						for (auto & vertex : object.getVerticesTexture()) {
							stream << "vt " << vertex[0] << " " << vertex[1] << " " << vertex[2] << " " << vertex[3] << std::endl;
						}
						stream << std::endl;

						for (auto & vertex : object.getVerticesNormal()) {
							stream << "vn " << vertex[0] << " " << vertex[1] << " " << vertex[2] << " " << vertex[3] << std::endl;
						}
						stream << std::endl;

						for (auto & vertex : object.getVerticesSpaceParameter()) {
							stream << "vp " << vertex[0] << " " << vertex[1] << " " << vertex[2] << " " << vertex[3] << std::endl;
						}
						stream << std::endl;

						for (auto & group : object.getGroups()) {
							stream << "g " << group.second.name << std::endl;
							if (!group.second.material.empty()) {
								stream << "usemtl " << group.second.material << std::endl;
							}
							for (auto it : group.second.faces) {
								auto & face = object.getFaces()[it];
								stream << "f";
								for (auto & vertex : face) {
									stream << " " << vertex._v << "/" << vertex._vt << "/" << vertex._vn;
								}
								stream << std::endl;
							}
						}
					}
				}

				void ParserOBJ::processLine(StringStream & line)
				{
					// TODO add checks for the format of the file
					auto first = line.get();
					line.ignore({ '\r', '\n', });
					switch (first) {
					case 'v':
						if (line.peek() == 't') { //vt
							line.get();
							if (this->_currentObject == this->_objects.end()) {
								this->_currentObject = this->addObject("unnamed");
							}

							auto texture = FloatVector3u{ 0.0f, 0.0f, 0.0f };
							line.scan("%f %f %f", &texture[0], &texture[1], &texture[2]);
							// TODO: Deal with 1D, 2D, and 3D texture
							this->_currentObject->addVertexTexture({ texture[0], texture[1] });
						}
						else if (line.peek() == 'n') { // vn
							line.get();
							if (this->_currentObject == this->_objects.end()) {
								this->_currentObject = this->addObject("unnamed");
							}

							auto normal = FloatVector3u{ 0.0f, 0.0f, 0.0f };
							line.scan("%f %f %f", &normal[0], &normal[1], &normal[2]);
							this->_currentObject->addVertexNormal(normal);
						}
						else if (line.peek() == 'p') { // vp
							line.get();
							if (this->_currentObject == this->_objects.end()) {
								this->_currentObject = this->addObject("unnamed");
							}

							auto parameterSpace = FloatVector3u{ 0.0f, 0.0f, 1.0f };
							line.scan("%f %f %f", &parameterSpace[0], &parameterSpace[1], &parameterSpace[2]);
							// TODO: Deal with 1D and 2D parameter space.
							this->_currentObject->addVertexSpaceParameter(parameterSpace);
						}
						else { // v
							line.get();
							if (this->_currentObject == this->_objects.end()) {
								this->_currentObject = this->addObject("unnamed");
							}

							auto vertice = FloatVector4u{ 0.0f, 0.0f, 0.0f, 1.0f };
							line.scan("%f %f %f %f", &vertice[0], &vertice[1], &vertice[2], &vertice[3]);
							this->_currentObject->addVertex(vertice);
						}
						break;
					case 'f':
					{
						ObjectOBJ::Face face;
						ObjectOBJ::Vertex vertex;

						auto faceSize = line.count(' ');
						face.resize(faceSize);

						for (unsigned int i = 0; i < faceSize; ++i) {
							vertex = { 0, 0, 0 };
							line.scan("%d/%d/%d", &vertex._v, &vertex._vt, &vertex._vn);
							face[i] = std::move(vertex);
						}

						if (this->_currentObject->getFaceFormat().clockwise == ObjectOBJ::Clockwise::NON_SIGNIFICANT) {
							auto a = this->_currentObject->getVertices()[face[0]._v - 1];
							auto b = this->_currentObject->getVertices()[face[1]._v - 1];
							auto c = this->_currentObject->getVertices()[face[face.size() - 1]._v - 1];
							FloatVector3u ab = { b[0] - a[0], b[1] - a[1], b[2] - a[2] };
							FloatVector3u cb = { b[0] - c[0], b[1] - c[1], b[2] - c[2] };
							FloatVector3u n = this->_currentObject->getVerticesNormal()[face[0]._vn - 1];
							float det = (ab[0] * cb[1] * n[2]) + (cb[0] * n[1] * ab[2]) + (n[0] * ab[1] * cb[2]) - (n[0] * cb[1] * ab[2]) - (ab[0] * n[1] * cb[2]) - (cb[0] * ab[1] * n[2]);
							auto angle = std::atan2(det, ab.dot(cb));
							if (angle > 0) {
								this->_currentObject->setFaceFormat({ face.size(), ObjectOBJ::Clockwise::CW });
							}
							else if (angle < 0) {
								this->_currentObject->setFaceFormat({ face.size(), ObjectOBJ::Clockwise::CCW });
							}
							else {
								this->_currentObject->setFaceFormat({ face.size(), ObjectOBJ::Clockwise::NON_SIGNIFICANT });
							}
						}

						this->_currentObject->addFace(std::move(face));

						// TODO check that it uses existing vertices, normales, and textures.
					}
					break;
					case 'o':
					{
						std::string name = line.substr();
						this->_currentObject = this->addObject(name);
					}
					break;
					case 'g':
					{
						this->_currentObject->resetCurrentGroups();

						std::string group;
						while (!line.eof()) {
							line >> group;
							this->_currentObject->addGroup(group);
						}
						// TODO: need to make the difference between object and group to complete implementation of submeshes for wavefront specification.
					}
					break;
					case 'm': // mtllib
					{
						line.get(5);
						std::string materialFile;
						line >> materialFile;
						this->_materials.push_back(materialFile);
					}
					break;
					case 'u': // usemtl
					{
						line.get(5);
						std::string material;
						line >> material;
						this->_currentObject->setMaterial(material);
					}
					break;
					default: break;
					}
				}

				auto ParserOBJ::addObject(const std::string & name) -> std::vector<ObjectOBJ>::iterator
				{
					this->_objects.emplace_back(name);
					return this->_objects.end() - 1;
				}
			} // namespace wavefront
		} // namespace formats
    } // namespace utility
} // namespace ece
