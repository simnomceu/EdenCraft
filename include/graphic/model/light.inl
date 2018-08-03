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
		namespace model
		{
			inline void Light::setAmbient(const float ambient) noexcept { this->_ambient = ambient; }

			inline void Light::setDiffuse(const float diffuse) noexcept { this->_diffuse = diffuse; }

			inline void Light::setSpecular(const float specular) noexcept { this->_specular = specular; }

			inline void Light::setColor(const FloatVector3u & color) noexcept { this->_color = color; }

			inline void Light::setPosition(const FloatVector3u & position) noexcept { this->_position = position; }
			
			inline void Light::setDirection(const FloatVector3u & direction) noexcept { this->_direction = direction; }
			
			inline void Light::setConstant(const float constant) noexcept { this->_constant = constant; }
			
			inline void Light::setLinear(const float linear) noexcept { this->_linear = linear; }
			
			inline void Light::setQuadratic(const float quadratic) noexcept { this->_quadratic = quadratic; }
			
			inline void Light::setInnerCutOff(const float innerCutOff) noexcept { this->_innerCutOff = innerCutOff; }
			
			inline void Light::setOuterCutOff(const float outerCutOff) noexcept { this->_outerCutOff = outerCutOff; }

			inline float Light::getAmbient() const noexcept { return this->_ambient; }

			inline float Light::getDiffuse() const noexcept { return this->_diffuse; }

			inline float Light::getSpecular() const noexcept { return this->_specular; }

			inline const FloatVector3u & Light::getColor() const noexcept { return this->_color; }

			inline const FloatVector3u & Light::getPosition() const noexcept { return this->_position; }

			inline const FloatVector3u & Light::getDirection() const noexcept { return this->_direction; }

			inline float Light::getConstant() const noexcept { return this->_constant; }

			inline float Light::getLinear() const noexcept { return this->_linear; }

			inline float Light::getQuadratic() const noexcept { return this->_quadratic; }

			inline float Light::getInnerCutoff() const noexcept { return this->_innerCutOff; }

			inline float Light::getOuterCutoff() const noexcept { return this->_outerCutOff; }

			inline void Light::usePosition(const bool used) noexcept { this->_usePosition = used; }

			inline void Light::useDirection(const bool used) noexcept { this->_useDirection = used; }

			inline void Light::useAttenuation(const bool used) noexcept { this->_useAttenuation = used; }

			inline void Light::useCutOff(const bool used) noexcept { this->_useCutOff = used; }

			inline void Light::useBlinn(const bool used) noexcept { this->_useBlinn = used; }

			inline bool Light::isPositionUsed() const noexcept { return this->_usePosition; }

			inline bool Light::isDirectionUsed() const noexcept { return this->_useDirection; }

			inline bool Light::isAttenuationUsed() const noexcept { return this->_useAttenuation; }

			inline bool Light::isCutOffUsed() const noexcept { return this->_useCutOff; }

			inline bool Light::isBlinnUsed() const noexcept { return this->_useBlinn; }
		} // namespace model
	} // namespace graphic
} // namespace ece