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

#include "renderer/resource/shader.hpp"

namespace ece
{
	namespace graphic
	{
		namespace model
		{
			Light::Light() noexcept : _ambient(1.0f), _diffuse(1.0f), _specular(1.0f), _color{ 1.0f, 1.0f, 1.0f }, _position{ 0.0f, 0.0f, 0.0f }, _direction{ 0.0f, 0.0f, 0.0f }, _constant(1.0f), 
				_linear(0.0f), _quadratic(0.0f), _innerCutOff(0.0f), _outerCutOff(0.0f), _usePosition(false), _useDirection(false), _useAttenuation(false), _useCutOff(false), _useBlinn(false)
			{
			}

			void Light::apply(Shader & shader)
			{
				shader.use();
				auto tmpId = std::to_string(0);
				shader.uniform<float, 3>("lights[" + tmpId + "].ambient", this->_color * this->_ambient);
				shader.uniform<float, 3>("lights[" + tmpId + "].diffuse", this->_color * this->_diffuse);
				shader.uniform("lights[" + tmpId + "].specular", FloatVector3u{ this->_specular, this->_specular, this->_specular });
				shader.uniform("lights[" + tmpId + "].position", this->_position);
				shader.uniform("lights[" + tmpId + "].direction", this->_direction);
				shader.uniform("lights[" + tmpId + "].constant", this->_constant);
				shader.uniform("lights[" + tmpId + "].linear", this->_linear);
				shader.uniform("lights[" + tmpId + "].quadratic", this->_quadratic);
				shader.uniform("lights[" + tmpId + "].innerCutOff", this->_innerCutOff);
				shader.uniform("lights[" + tmpId + "].outerCutOff", this->_outerCutOff);
				shader.uniform("lights[" + tmpId + "].usePosition", this->_usePosition);
				shader.uniform("lights[" + tmpId + "].useDirection", this->_useDirection);
				shader.uniform("lights[" + tmpId + "].useAttenuation", this->_useAttenuation);
				shader.uniform("lights[" + tmpId + "].useCutOff", this->_useCutOff);
				shader.uniform("numberOfLights", 1);
			}
		} // namespace model
	} // namespace graphic
} // namespace ece