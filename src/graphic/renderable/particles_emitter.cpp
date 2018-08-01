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

#include "graphic/renderable/particles_emitter.hpp"

#include "graphic/model/primitives.hpp"

namespace ece
{
	namespace graphic
	{
		namespace renderable
		{
			using renderer::PrimitiveMode;
			using renderer::BufferType;
			using renderer::BufferUsage;
			using graphic::model::makeQuad;
			using renderer::resource::ShaderStage;
			using renderer::ShaderType;

			ParticlesEmitter::ParticlesEmitter(const int size) noexcept : Renderable(), _particles(), _size(size), _instanceLayout()
			{
				for (int i = 0; i < this->_size; ++i) {
					this->_particles.push_back({ 10.0f,
						{ ((rand() % 100) - 50) / 10.0f, ((rand() % 100) - 50) / 10.0f, ((rand() % 100) - 50) / 10.0f },
						{ 0.1f, 0.1f, 0.1f },
						{ 0.5f + ((rand() % 100) / 100.0f), 0.5f + ((rand() % 100) / 100.0f), 0.5f + ((rand() % 100) / 100.0f), 1.0f } });
				}

				this->_mode = PrimitiveMode::TRIANGLES;

				BufferLayout layout;
				layout.add<float>(3, false);

				auto mesh = makeQuad(0.1f);
				this->_vao.sendData(layout, BufferType::ARRAY_BUFFER, mesh.getVertices(), BufferUsage::STATIC_DRAW);
				this->_vao.addIndices(mesh.getFaces(), BufferUsage::STATIC_DRAW);
				
				this->_instanceLayout.add<float>(1, false, false);
				this->_instanceLayout.add<float>(3, false);
				this->_instanceLayout.add<float>(3, false, false);
				this->_instanceLayout.add<float>(4, false);
				this->_vao.sendData(this->_instanceLayout, BufferType::ARRAY_BUFFER, this->_particles, BufferUsage::STATIC_DRAW, true);

				ShaderStage fsSource, vsSource;
				fsSource.loadFromFile(ShaderType::FRAGMENT_SHADER, "../../examples/particles_forever/particles.frag");
				vsSource.loadFromFile(ShaderType::VERTEX_SHADER, "../../examples/particles_forever/particles.vert");

				this->_program.setStage(fsSource);
				this->_program.setStage(vsSource);
				this->_program.link();
				this->_program.use();
			}

			void ParticlesEmitter::update(const float /*elapsedTime*/)
			{
				/*this->_particles.erase(std::remove_if(this->_particles.begin(), this->_particles.end(), [](const ParticlesEmitter::Particle & element) { return element._life <= 0.0f; }), this->_particles.end());

				auto particlesToCreate = this->_size - this->_particles.size();
				for (size_t i = 0; i < particlesToCreate; ++i) {
					this->_particles.push_back({ 10.0f, 
												 { ((rand() % 100) - 50) / 10.0f, ((rand() % 100) - 50) / 10.0f, ((rand() % 100) - 50) / 10.0f }, 
												 { 0.1f, 0.1f, 0.1f }, 
												 { 0.5f + ((rand() % 100) / 100.0f), 0.5f + ((rand() % 100) / 100.0f), 0.5f + ((rand() % 100) / 100.0f), 1.0f } });
				}

				for (auto & particle : this->_particles) {
					particle._life -= elapsedTime;
					if (particle._life > 0.0f) {
						particle._position -= particle._velocity * elapsedTime;
						particle._color[3] -= elapsedTime * 2.5f;
					}
				}*/

				//this->_vao.updateData(this->_instanceLayout, BufferType::ARRAY_BUFFER, this->_particles, BufferUsage::STATIC_DRAW, true);
			}
		} // namespace renderable
	} // namespace graphic
} // namespace ece