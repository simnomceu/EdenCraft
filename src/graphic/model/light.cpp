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

#include "graphic/model/light.hpp"

#include "renderer/shader.hpp"

namespace ece
{
	namespace graphic
	{
		namespace model
		{
			Light::Light() noexcept : _ambient(1.0f), _diffuse(1.0f), _specular(1.0f), _color{ 1.0f, 1.0f, 1.0f }, _position(), _direction(), _attenuation(), 
									_cutOff(), _useBlinn(false)
			{
			}

			void Light::apply(Shader & shader)
			{
				shader.use();
				auto tmpId = std::to_string(0);
				shader.bind(std::make_shared<Uniform<float, 3>>("ambient", FloatVector3u(this->_color * this->_ambient).data()), "lights[" + tmpId + "].ambient");
				shader.bind(std::make_shared<Uniform<float, 3>>("diffuse", FloatVector3u(this->_color * this->_diffuse).data()), "lights[" + tmpId + "].diffuse");
				shader.bind(std::make_shared<Uniform<float, 3>>("specular", std::array<float, 3>{ this->_specular, this->_specular, this->_specular }), "lights[" + tmpId + "].specular");
				shader.bind(std::make_shared<Uniform<float, 3>>("position", this->_position.value_or(FloatVector3u{ 0.0f, 0.0f, 0.0f }).data()), "lights[" + tmpId + "].position");
				shader.bind(std::make_shared<Uniform<float, 3>>("direction", this->_direction.value_or(FloatVector3u{ 0.0f, 0.0f, 0.0f }).data()), "lights[" + tmpId + "].direction");
				shader.bind(std::make_shared<Uniform<float>>("constant", this->_attenuation.value_or(Attenuation{ 1.0f, 0.0f, 0.0f }).constant), "lights[" + tmpId + "].constant");
				shader.bind(std::make_shared<Uniform<float>>("linear", this->_attenuation.value_or(Attenuation{ 1.0f, 0.0f, 0.0f }).linear), "lights[" + tmpId + "].linear");
				shader.bind(std::make_shared<Uniform<float>>("quadratic", this->_attenuation.value_or(Attenuation{ 1.0f, 0.0f, 0.0f }).quadratic), "lights[" + tmpId + "].quadratic");
				shader.bind(std::make_shared<Uniform<float>>("innerCutOff", this->_cutOff.value_or(CutOff{ 0.0f, 0.0f }).inner), "lights[" + tmpId + "].innerCutOff");
				shader.bind(std::make_shared<Uniform<float>>("outerCutOff", this->_cutOff.value_or(CutOff{ 0.0f, 0.0f }).outer), "lights[" + tmpId + "].outerCutOff");
				shader.bind(std::make_shared<Uniform<bool>>("usePosition", this->isPositionUsed()), "lights[" + tmpId + "].usePosition");
				shader.bind(std::make_shared<Uniform<bool>>("useDirection", this->isDirectionUsed()), "lights[" + tmpId + "].useDirection");
				shader.bind(std::make_shared<Uniform<bool>>("useAttenuation", this->isAttenuationUsed()), "lights[" + tmpId + "].useAttenuation");
				shader.bind(std::make_shared<Uniform<bool>>("useCutOff", this->isCutOffUsed()), "lights[" + tmpId + "].useCutOff");
				shader.bind(std::make_shared<Uniform<int>>("numberOfLights", 1), "numberOfLights");
			}
		} // namespace model
	} // namespace graphic
} // namespace ece