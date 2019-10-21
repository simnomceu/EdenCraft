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
#include "graphic/model/mtl_loader.hpp"
#include "utility/formats.hpp"
#include "core/resource.hpp"
#include "graphic/material.hpp"

namespace ece
{
	namespace graphic
	{
		namespace model
		{
			ResourceRef MTLLoader::load(StreamInfoIn info)
			{
				auto parserMaterial = ParserMTL();
				parserMaterial.load(info.stream);
				auto material = parserMaterial.getMaterials()[0];

				auto relativePath = info.filename.substr(0, info.filename.find_last_of('/') + 1);

				auto materialResource = makeResource<Material>(material.name);
				auto materialVisitor = PhongMaterial();
				materialVisitor.setMaterial(*materialResource);
				materialVisitor.initialize();

				materialVisitor.setAmbient(std::get<FloatVector3u>(material.ambient.value));
				materialVisitor.setDiffuse(std::get<FloatVector3u>(material.diffuse.value));
				materialVisitor.setSpecular(std::get<FloatVector3u>(material.specular.value));
				materialVisitor.setShininess(material.specularExponent);

				if (!material.mapDiffuse.empty()) {
					auto diffuseMap = makeResource<Texture2D>(material.mapDiffuse);
					if (diffuseMap->getData().empty()) {
						diffuseMap->loadFromFile(Texture::TypeTarget::TEXTURE_2D, relativePath + material.mapDiffuse);
					}
					diffuseMap->bind(Texture::Target::TEXTURE_2D);
					diffuseMap->generateMipmap();
					materialVisitor.setDiffuseMap(diffuseMap);
				}

				if (!material.mapSpecular.empty()) {
					auto specularMap = makeResource<Texture2D>(material.mapSpecular);
					if (specularMap->getData().empty()) {
						specularMap->loadFromFile(Texture::TypeTarget::TEXTURE_2D, relativePath + material.mapSpecular);
					}
					specularMap->bind(Texture::Target::TEXTURE_2D);
					specularMap->generateMipmap();
					materialVisitor.setSpecularMap(specularMap);
				}

				return materialResource;
			}

			void MTLLoader::save(StreamInfoOut info)
			{
				auto parserMaterial = ParserMTL();
				auto materialResource = info.resource.to<Material>();

				auto relativePath = info.filename.substr(0, info.filename.find_last_of('/') + 1);

				auto & material = parserMaterial.getMaterials()[0];

				auto materialVisitor = PhongMaterial();
				materialVisitor.setMaterial(*materialResource);

				material.name = materialResource.getIdentifier();

				material.ambient.value = materialVisitor.getAmbient();
				material.diffuse.value = materialVisitor.getDiffuse();
				material.specular.value = materialVisitor.getSpecular();
				material.specularExponent = materialVisitor.getShininess();

				if (!materialVisitor.getDiffuseMap().isDirty()) {
					materialVisitor.getDiffuseMap()->saveToFile(relativePath + materialResource.getIdentifier() + "_diffuse.bmp");
				}

				if (!materialVisitor.getSpecularMap().isDirty()) {
					materialVisitor.getSpecularMap()->saveToFile(relativePath + materialResource.getIdentifier() + "_specular.bmp");
				}

				parserMaterial.save(info.stream);
			}
		}
	}
}