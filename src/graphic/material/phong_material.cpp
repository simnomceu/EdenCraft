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
#include "graphic/material/phong_material.hpp"

#include "graphic/material/property.hpp"
#include "graphic/material/computed_property.hpp"

namespace ece
{
	namespace graphic
	{
		namespace material
		{
			auto PhongMaterial::isValid() -> bool
			{
				return this->_material.lock()->hasProperty("diffuseMapEnabled")
					&& this->_material.lock()->hasProperty("specularMapEnabled")
					&& this->_material.lock()->hasProperty("ambient")
					&& this->_material.lock()->hasProperty("diffuse")
					&& this->_material.lock()->hasProperty("specular")
					&& this->_material.lock()->hasProperty("diffuseMap")
					&& this->_material.lock()->hasProperty("specularMap")
					&& this->_material.lock()->hasProperty("shininess");
			}

			void PhongMaterial::initialize()
			{
				this->_material.lock()->addProperty("diffuseMap", makeProperty<Texture2D::Reference, int>(Texture2D::Reference(), [this](auto property) -> int {
					property->active(0);
					property->bind(Texture::Target::TEXTURE_2D);
					return 0;
				}));

				this->_material.lock()->addProperty("specularMap", makeProperty<Texture2D::Reference, int>(Texture2D::Reference(), [this](auto property) -> int {
					property->active(1);
					property->bind(Texture::Target::TEXTURE_2D);
					return 1;
				}));

				this->_material.lock()->addProperty("diffuseMapEnabled", makeComputedProperty<bool>([material = this->_material]() {
					auto diffuseMap = std::dynamic_pointer_cast<DiffuseMap>(material.lock()->getProperty("diffuseMap"))->get();
					return !diffuseMap.isDirty();
				}));

				this->_material.lock()->addProperty("specularMapEnabled", makeComputedProperty<bool>([material = this->_material]() {
					auto specularMap = std::dynamic_pointer_cast<SpecularMap>(material.lock()->getProperty("specularMap"))->get();
					return !specularMap.isDirty();
				}));

				this->_material.lock()->addProperty("ambient", makeProperty<FloatVector3u, std::array<float, 3>>(FloatVector3u{}, [](auto property) {
					return property.data();
				}));
				this->_material.lock()->addProperty("diffuse", makeProperty<FloatVector3u, std::array<float, 3>>(FloatVector3u{}, [](auto property) {
					return property.data();
				}));
				this->_material.lock()->addProperty("specular", makeProperty<FloatVector3u, std::array<float, 3>>(FloatVector3u{}, [](auto property) {
					return property.data();
				}));
				this->_material.lock()->addProperty("shininess", makeProperty<float>(0.0f));
			}

			void PhongMaterial::clear()
			{
				this->_material.lock()->removeProperty("diffuseMapEnabled");
				this->_material.lock()->removeProperty("specularMapEnabled");
				this->_material.lock()->removeProperty("ambient");
				this->_material.lock()->removeProperty("diffuse");
				this->_material.lock()->removeProperty("specular");
				this->_material.lock()->removeProperty("diffuseMap");
				this->_material.lock()->removeProperty("specularMap");
				this->_material.lock()->removeProperty("shininess");
			}
		} // namespace material
	} // namespace graphic
} // namespace ece