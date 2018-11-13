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

#include "graphic/scene/make_light.hpp"

#include "core/resource.hpp"

namespace ece
{
	namespace graphic
	{
		namespace scene
		{
			Light::Reference makeBasicLight(const float ambient, const float diffuse, const float specular, const FloatVector3u & color, const FloatVector3u & position)
			{
				auto light = makeResource<Light>("BasicLight");
				light->setAmbient(ambient);
				light->setDiffuse(diffuse);
				light->setSpecular(specular);
				light->setColor(color);
				light->setPosition(position);
				return std::move(light);
			}

			Light::Reference makeDirectionalLight(const float ambient, const float diffuse, const float specular, const FloatVector3u & color, const FloatVector3u & direction)
			{
				auto light = makeResource<Light>("DirectionalLight");
				light->setAmbient(ambient);
				light->setDiffuse(diffuse);
				light->setSpecular(specular);
				light->setColor(color);
				light->setDirection(direction);
				return std::move(light);
			}

			Light::Reference makePointLight(const float ambient, const float diffuse, const float specular, const FloatVector3u & color, const FloatVector3u & position, const float constant, const float linear, const float quadratic)
			{
				auto light = makeResource<Light>("PointLight");
				light->setAmbient(ambient);
				light->setDiffuse(diffuse);
				light->setSpecular(specular);
				light->setColor(color);
				light->setPosition(position);
				light->setAttenuation({ constant, linear, quadratic });
				return std::move(light);
			}
			
			Light::Reference makeSpotLight(const float ambient, const float diffuse, const float specular, const FloatVector3u & color, const FloatVector3u & position, const FloatVector3u & direction, const float constant, const float linear, const float quadratic, const float innerCutOff, const float outerCutOff)
			{
				auto light = makeResource<Light>("SpotLight");
				light->setAmbient(ambient);
				light->setDiffuse(diffuse);
				light->setSpecular(specular);
				light->setColor(color);
				light->setPosition(position);
				light->setDirection(direction);
				light->setAttenuation({ constant, linear, quadratic });
				light->setCutOff({ innerCutOff, outerCutOff });
				light->useBlinn(true);
				return std::move(light);
			}
		} // namespace scene
	} // namespace graphic
} // namespace ece