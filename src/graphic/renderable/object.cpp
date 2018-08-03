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

#include "graphic/renderable/object.hpp"
#include "renderer/resource/buffer_layout.hpp"

namespace ece
{
	namespace graphic
	{
		namespace renderable
		{
			using renderer::BufferType;
			using renderer::BufferUsage;
			using model::Mesh;
            using renderer::resource::BufferLayout;
            using renderer::PrimitiveMode;
            using renderer::ShaderType;
            using renderer::resource::ShaderStage;

            Object::Object() noexcept: Renderable(), _mesh(), _material()
            {
                this->_mode = PrimitiveMode::TRIANGLES;
            }

			void Object::setMesh(const Mesh::Reference & mesh)
			{
				this->_mesh = mesh;
			}

			void Object::setMaterial(const std::shared_ptr<Material> & material)
			{
				this->_material = material;
				if (this->_program.isLinked()) {
					this->_material->apply(this->_program);
				}
			}

            void Object::prepare()
            {
                BufferLayout layout;
                layout.add<float>(3, false);
                layout.add<float>(3, false);
                layout.add<float>(2, false);

                this->_vao.sendData(layout, BufferType::ARRAY_BUFFER, this->_mesh->getVertices(), BufferUsage::STATIC_DRAW);
                this->_vao.addIndices(this->_mesh->getFaces(), BufferUsage::STATIC_DRAW);

                if (this->isInstancingEnabled()) {
                    BufferLayout layoutInstancing;
                    layoutInstancing.add<float>(4, false);
					layoutInstancing.add<float>(4, false);
					layoutInstancing.add<float>(4, false);
					layoutInstancing.add<float>(4, false);

                    this->_vao.sendData(layoutInstancing, BufferType::ARRAY_BUFFER, this->_instances, BufferUsage::STATIC_DRAW, true);
                }

                ShaderStage fsSource, vsSource;
                fsSource.loadFromFile(ShaderType::FRAGMENT_SHADER, "../../resource/shader/phong.frag");
                if (this->isInstancingEnabled()) {
                    vsSource.loadFromFile(ShaderType::VERTEX_SHADER, "../../resource/shader/phong_instance.vert");
                }
                else {
                    vsSource.loadFromFile(ShaderType::VERTEX_SHADER, "../../resource/shader/phong.vert");
                }

                this->_program.setStage(fsSource);
                this->_program.setStage(vsSource);
                this->_program.link();
                this->_program.use();
				if (this->_material) {
					this->_material->apply(this->_program);
				}
            }
		}// namespace renderable
	} // namespace graphic
} // namespace ece
