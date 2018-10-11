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

#include "graphic/model.hpp"

#include <vector>
#include <algorithm>

#ifdef _MSC_VER
#	undef min
#	undef max
#endif

namespace ece
{
	namespace graphic
	{
		namespace renderable
		{
			ParticlesEmitter::ParticlesEmitter(const std::size_t size) noexcept : Renderable(), _particles(), _size(size), _vertices()
			{
				this->_state._pointSize = 4.0f;
				this->_state._blending = true;
				this->_state._sourceBlend = BlendingFactor::SRC_ALPHA;
				this->_state._destinationBlend = BlendingFactor::ONE;

				this->_mode = PrimitiveMode::POINTS;

				renderer::buffer::BufferLayout layout;
				layout.add<float>(3, false, false, false);
				layout.add<float>(3, false, true, false);
				layout.add<float>(2, false, true, false);

				this->_vertices.write({ 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f });
				this->_vertexArray.attach(this->_vertices, layout);

				renderer::buffer::BufferLayout instanceLayout;
				instanceLayout.setInstanceBlockSize(1);
				instanceLayout.add<float>(1, false, true, false);
				instanceLayout.add<float>(3, false, false, true);
				instanceLayout.add<float>(3, false, true, false);
				instanceLayout.add<float>(4, false, false, true);

				this->_vertexArray.attach(this->_particles, layout);

				for (int i = 0; i < 10; ++i) {
					this->_particles.data().push_back({ 1.0f,
						{ ((rand() % 100) - 50) / 500.0f, ((rand() % 100) - 50) / 500.0f, ((rand() % 100) - 50) / 500.0f },
						{ ((rand() % 100) - 50) / 50.0f, ((rand() % 100) - 50) / 50.0f, ((rand() % 100) - 50) / 50.0f },
						{ ((rand() % 100) / 100.0f), ((rand() % 100) / 100.0f), ((rand() % 100) / 100.0f), 1.0f } });
				}
				this->_numberOfInstances = this->_particles.size();

				ShaderStage fsSource, vsSource;
				fsSource.loadFromFile(ShaderType::FRAGMENT_SHADER, "../../examples/particles_forever/particles.frag");
				vsSource.loadFromFile(ShaderType::VERTEX_SHADER, "../../examples/particles_forever/particles.vert");

				this->_program.setStage(fsSource);
				this->_program.setStage(vsSource);
				this->_program.link();
				this->_program.use();
			}

			void ParticlesEmitter::update(const float elapsedTime)
			{
				this->_particles.data().erase(std::remove_if(this->_particles.data().begin(), this->_particles.data().end(), [](const ParticlesEmitter::Particle & element) { return element._life <= 0.0f; }), this->_particles.data().end());

				auto particlesToCreate = std::min(this->_size - this->_particles.size(), std::size_t(10));
				for (size_t i = 0; i < particlesToCreate; ++i) {
					this->_particles.data().push_back({ 1.0f,
						{ ((rand() % 100) - 50) / 500.0f, ((rand() % 100) - 50) / 500.0f, ((rand() % 100) - 50) / 500.0f },
						{ ((rand() % 100) - 50) / 50.0f, ((rand() % 100) - 50) / 50.0f, ((rand() % 100) - 50) / 50.0f },
						{ ((rand() % 100) / 100.0f), ((rand() % 100) / 100.0f), ((rand() % 100) / 100.0f), 1.0f } });
				}

				for (auto & particle : this->_particles.data()) {
					particle._life -= elapsedTime;
					if (particle._life > 0.0f) {
						particle._position -= particle._velocity * elapsedTime;
						particle._color[3] -= elapsedTime * 2.5f;
					}
				}

				this->_numberOfInstances = this->_particles.size();

				this->_particles.update();
			}

			void ParticlesEmitter::draw()
			{
				this->_program.use();
				this->_vertexArray.bind();
				this->_state.apply();

				OpenGL::drawArraysInstanced(this->_mode, 0, this->_vertices.size(), this->_size);
			}
		} // namespace renderable
	} // namespace graphic
} // namespace ece
