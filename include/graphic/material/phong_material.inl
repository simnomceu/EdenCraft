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

namespace ece
{
	namespace graphic
	{
		namespace material
		{
			inline void PhongMaterial::setMaterial(const std::shared_ptr<Material> & material) { this->_material = material; }

			inline std::shared_ptr<Material> PhongMaterial::getMaterial() { return this->_material; }

			inline void PhongMaterial::setAmbient(const FloatVector3u & ambient) { *std::dynamic_pointer_cast<Ambient>(this->_material->getProperty("ambient")) = ambient; }
			
			inline void PhongMaterial::setDiffuse(const FloatVector3u & diffuse) { *std::dynamic_pointer_cast<Diffuse>(this->_material->getProperty("diffuse")) = diffuse; }
			
			inline void PhongMaterial::setSpecular(const FloatVector3u & specular) { *std::dynamic_pointer_cast<Specular>(this->_material->getProperty("specular")) = specular; }
			
			inline void PhongMaterial::setShininess(const float shininess) { *std::dynamic_pointer_cast<Shininess>(this->_material->getProperty("shininess")) = shininess; }

			inline void PhongMaterial::setDiffuseMap(const Texture2D::Reference & texture) { *std::dynamic_pointer_cast<DiffuseMap>(this->_material->getProperty("diffuseMap")) = texture; }

			inline void PhongMaterial::setSpecularMap(const Texture2D::Reference & texture) { *std::dynamic_pointer_cast<SpecularMap>(this->_material->getProperty("specularMap")) = texture; }

			inline const FloatVector3u & PhongMaterial::getAmbient() const { return std::dynamic_pointer_cast<Ambient>(this->_material->getProperty("ambient"))->get(); }
			
			inline const FloatVector3u & PhongMaterial::getDiffuse() const { return std::dynamic_pointer_cast<Diffuse>(this->_material->getProperty("diffuse"))->get(); }
			
			inline const FloatVector3u & PhongMaterial::getSpecular() const { return std::dynamic_pointer_cast<Specular>(this->_material->getProperty("specular"))->get(); }
			
			inline float PhongMaterial::getShininess() const { return std::dynamic_pointer_cast<Shininess>(this->_material->getProperty("shininess"))->get(); }

			inline Texture2D::Reference PhongMaterial::getDiffuseMap() const { return std::dynamic_pointer_cast<DiffuseMap>(this->_material->getProperty("diffuseMap"))->get(); }
			
			inline Texture2D::Reference PhongMaterial::getSpecularMap() const { return std::dynamic_pointer_cast<SpecularMap>(this->_material->getProperty("specularMap"))->get(); }
		} // namespace material
	} // namespace graphic
} // namespace ece