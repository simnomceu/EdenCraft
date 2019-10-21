/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

															  .oooooo.                                  oooo         o8o
															 d8P'  `Y8b                                 `888         `"'
															888           oooo d8b  .oooo.   oo.ooooo.   888 .oo.   oooo   .ooooo.
															888           `888""8P `P  )88b   888' `88b  888P"Y88b  `888  d88' `"Y8
															888     ooooo  888      .oP"888   888   888  888   888   888  888
															`88.    .88'   888     d8(  888   888   888  888   888   888  888   .o8
															 `Y8bood8P'   d888b    `Y888""8o  888bod8P' o888o o888o o888o `Y8bod8P'
																							  888
																							 o888o



				This file is part of EdenCraft Engine - Graphic module.
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

#include "graphic/pch.hpp"
#include "graphic/model/obj_saver.hpp"

#include "utility/file_system.hpp"
#include "utility/formats/wavefront.hpp"
#include "graphic/material/phong_material.hpp"

namespace ece
{
	namespace graphic
	{
		namespace model
		{
			using material::PhongMaterial;

			void OBJSaver::save(StreamInfoOut info)
			{
				auto parser = ParserOBJ();
				auto parserMaterial = ParserMTL();

				auto meshResource = info.resource.to<Mesh>();
				auto relativePath = info.filename.substr(0, info.filename.find_last_of('/') + 1);

				auto & objects = parser.getObjects();
				auto & materials = parser.getMaterials();

				objects.clear();
				materials.clear();

				auto & object = objects.emplace_back(info.identifier);
				object.setFaceFormat(ObjectOBJ::FaceFormat{ 3, ObjectOBJ::Clockwise::CCW });

				for (auto & vertex : meshResource->getVertices()) {
					object.addVertex({ vertex._position[0], vertex._position[1], vertex._position[2], 1.0f });
					object.addVertexNormal({ vertex._normal[0], vertex._normal[1], vertex._normal[2] });
					object.addVertexTexture({ vertex._textureCoordinate[0], vertex._textureCoordinate[1] });

					// TODO :: not optimal as there is dopples. Be careful with face adding at the end.
				}

				auto & submeshes = meshResource->getSubmeshes();
				int i = 0;
				for (auto & submesh : submeshes) {
					object.resetCurrentGroups();
					auto groupName = info.identifier + std::to_string(i);
					object.addGroup(groupName);

					object.setMaterial(submesh.material.getIdentifier());
					{
						parserMaterial.getMaterials().clear();
						auto materialFilename = relativePath + submesh.material.getIdentifier() + ".mtl";

						materials.push_back(submesh.material.getIdentifier());
						auto & material = parserMaterial.getMaterials()[0];

						auto materialVisitor = PhongMaterial();
						materialVisitor.setMaterial(*submesh.material);
						
						material.name = submesh.material.getIdentifier();

						material.ambient.value = materialVisitor.getAmbient();
						material.diffuse.value = materialVisitor.getDiffuse();
						material.specular.value = materialVisitor.getSpecular();
						material.specularExponent = materialVisitor.getShininess();

						if (!materialVisitor.getDiffuseMap().isDirty()) {
							materialVisitor.getDiffuseMap()->saveToFile(relativePath + submesh.material.getIdentifier() + "_diffuse.bmp");
						}

						if (!materialVisitor.getSpecularMap().isDirty()) {
							materialVisitor.getSpecularMap()->saveToFile(relativePath + submesh.material.getIdentifier() + "_specular.bmp");
						}

						auto materialFile = std::ofstream(materialFilename, std::ios::in);
						if (!materialFile.is_open()) {
							throw FileException(FileCodeError::BAD_PATH, materialFilename);
						}
						parserMaterial.save(materialFile);
					}

					for (auto & face : submesh.mesh.getFaces()) {
						object.addFace({ { static_cast<int>(face[0]), static_cast<int>(face[0]), static_cast<int>(face[0]) }, 
										 { static_cast<int>(face[1]), static_cast<int>(face[1]), static_cast<int>(face[1]) },
										 { static_cast<int>(face[2]), static_cast<int>(face[2]), static_cast<int>(face[2]) } });
					}

					++i;
				}

				parser.save(info.stream);
			}
		} // namespace model
	} // namespace graphic
} // namespace ece