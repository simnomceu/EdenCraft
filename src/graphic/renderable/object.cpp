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
#include "renderer/shader.hpp"

namespace ece
{
	namespace graphic
	{
		namespace renderable
		{
            Object::Object() noexcept: Renderable(), _mesh(), _instances()
            {
                this->_mode = PrimitiveMode::TRIANGLES;

				this->_instances.data().push_back(FloatMatrix4u::Identity());
            }

			void Object::setMesh(const Mesh::Reference & mesh)
			{
				this->_mesh = mesh;
			}

            void Object::prepare()
            {
				this->_mesh->update();
				this->_vertexArray.attach(this->_mesh->getVertexBuffer(), this->_mesh->getLayout());

                if (this->isInstancingEnabled()) {
					renderer::buffer::BufferLayout layoutInstancing;
					layoutInstancing.setInstanceBlockSize(1);
					layoutInstancing.add<float>(4, false, false, true);
					layoutInstancing.add<float>(4, false, false, true);
					layoutInstancing.add<float>(4, false, false, true);
					layoutInstancing.add<float>(4, false, false, true);

					this->_instances.update();
					this->_vertexArray.attach(this->_instances, layoutInstancing);
                }
            }

			void Object::addInstance(const FloatMatrix4u & offset)
			{
				this->_instances.data().push_back(offset.transpose());
				++this->_numberOfInstances;
			}

			void Object::draw(std::shared_ptr<Shader> program)
			{
				this->_vertexArray.bind();
				for (auto & submesh : this->_mesh->getSubmeshes()) {
					if (*submesh.material) {
						auto uniforms = submesh.material->getProperties();
						for (auto uniform : uniforms) {
							program->bind(uniform, "material." + uniform->getName());
						}
					//	submesh.material->apply(*program);
					}
					submesh.mesh.getIndexBuffer().bind();
					if (submesh.mesh.getIndexBuffer().size() > 0) {
						if (this->isInstancingEnabled()) {
							OpenGL::drawElementsInstanced(this->_mode, submesh.mesh.size(), renderer::opengl::DataType::UNSIGNED_INT, 0, this->_instances.size());

						}
						else {
							OpenGL::drawElements(this->_mode, this->_mesh->size(), renderer::opengl::DataType::UNSIGNED_INT, 0);
						}
					}
					else {
						if (this->isInstancingEnabled()) {
							OpenGL::drawArraysInstanced(this->_mode, 0, this->_mesh->size(), this->_instances.size());
						}
						else {
							OpenGL::drawArrays(this->_mode, 0, this->_mesh->size());
						}
					}
				}
			}
		}// namespace renderable
	} // namespace graphic
} // namespace ece
