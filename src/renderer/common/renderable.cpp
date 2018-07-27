/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

															ooooooooo.                               .o8
															`888   `Y88.                            "888
															 888   .d88'  .ooooo.  ooo. .oo.    .oooo888   .ooooo.  oooo d8b  .ooooo.  oooo d8b
															 888ooo88P'  d88' `88b `888P"Y88b  d88' `888  d88' `88b `888""8P d88' `88b `888""8P
															 888`88b.    888ooo888  888   888  888   888  888ooo888  888     888ooo888  888
															 888  `88b.  888    .o  888   888  888   888  888    .o  888     888    .o  888
															o888o  o888o `Y8bod8P' o888o o888o `Y8bod88P" `Y8bod8P' d888b    `Y8bod8P' d888b



				This file is part of EdenCraft Engine - Renderer module.
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

#include "renderer/common/renderable.hpp"

#include "utility/mathematics/matrix4u.hpp"
#include "utility/mathematics/transform.hpp"

namespace ece
{
	namespace renderer
	{
		namespace common
		{
			using utility::mathematics::FloatMatrix4u;
			using utility::mathematics::FloatVector3u;
			using opengl::OpenGL;

			Renderable::Renderable() noexcept: _vao(), _mode(), _program(), _model(), _instances()
			{
				this->_model.setIdentity();
                this->_instances.push_back(FloatMatrix4u::Identity());
			}

			Renderable::~Renderable() {}

			void Renderable::draw()
			{
				this->_program.use();
				this->_vao.bind();
				this->_vao.bindIndexBuffer();
                if (this->isInstancingEnabled()) {
		            OpenGL::drawElementsInstanced(this->_mode, this->_vao.getNbVertices(), DataType::UNSIGNED_INT, 0, this->_instances.size());
                }
                else {
		            OpenGL::drawElements(this->_mode, this->_vao.getNbVertices(), DataType::UNSIGNED_INT, 0);
                }
			}

			void Renderable::setCamera(const FloatMatrix4u & view, const FloatMatrix4u & projection) const noexcept
			{
				OpenGL::uniform<float, 4, 4>(glGetUniformLocation(this->_program.getHandle(), "model"), true, this->_model);
				OpenGL::uniform<float, 4, 4>(glGetUniformLocation(this->_program.getHandle(), "view"), false, view);
				OpenGL::uniform<float, 4, 4>(glGetUniformLocation(this->_program.getHandle(), "projection"), false, projection);
			}

			void Renderable::applyTransformation(const FloatMatrix4u & transformation)
			{
				this->_model = transformation * this->_model;
				OpenGL::uniform<float, 4, 4>(glGetUniformLocation(this->_program.getHandle(), "model"), true, this->_model);
			}

            void Renderable::addInstance(const FloatMatrix4u & offset)
            {
                this->_instances.push_back(offset.transpose());
            }

            bool Renderable::isInstancingEnabled() const
            {
                return this->_instances.size() > 1;
            }
		} // namespace common
	} // namespace renderer
} // namespace ece
