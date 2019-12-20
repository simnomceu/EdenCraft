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
#include "graphic/scene/scene.hpp"

#include "utility/mathematics.hpp"

namespace ece
{
	namespace graphic
	{
		namespace scene
		{
			Scene::Scene() noexcept: _camera(), _objects()
			{
				// TODO : change the resolution ratio to be adapted to window size
				this->_camera.value.moveTo(FloatVector3u{ 1.0f, 2.0f, 2.0f });
			}

			auto Scene::addObject() -> Object::Reference
			{
				auto object = makeResource<Object>(std::to_string(std::chrono::system_clock::now().time_since_epoch().count()));
				this->_objects.push_back(object, true, 0);
				return object;
			}

			auto Scene::getObjects() -> std::vector<Renderable::Reference>
			{
				return this->_objects.getRenderables();
			}

			auto Scene::getLights() -> std::vector<Light::Reference> &
			{
				return this->_lights;
			}

			void Scene::prepare()
			{
				for (auto i = std::size_t{ 0 }; i < this->_objects.size(); ++i) {
					ObjectWrapper object = this->_objects[i];
					if (object.hasChanged) {
						object.value->prepare();
						object.hasChanged = false;
					}
				}
			}

			void Scene::sortObjects()
			{
			/*	std::sort(this->_objects.begin(), this->_objects.end(), [](auto & a, auto & b) -> bool {
					return ObjectWrapper(a).level <= ObjectWrapper(b).level;
				});*/
			}
		} // namespace scene
	} // namespace graphic
} // namespace ece
