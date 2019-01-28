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

#include "graphic/config.hpp"
#include "graphic/pch.hpp"
#include "graphic/renderable/renderable.hpp"
#include "utility/mathematics.hpp"

namespace ece
{
	namespace graphic
	{
		namespace renderable
		{
			/**
			 * @class ParticlesEmitter
			 * @brief
			 */
			class ECE_GRAPHIC_API ParticlesEmitter: public Renderable
			{
			public:
				struct Particle
				{
					float _life;
					FloatVector3u _position;
					FloatVector3u _velocity;
					FloatVector4u _color;
				};

				/**
				 * @fn ParticlesEmitter() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				ParticlesEmitter(const std::size_t size) noexcept;

				/**
				 * @fn ParticlesEmitter(const ParticlesEmitter & copy)
				 * @param[in] copy The ParticlesEmitter to copy from.
				 * @brief Default copy constructor.
				 * @throw
				 */
				ParticlesEmitter(const ParticlesEmitter & copy) = default;

				/**
				 * @fn ParticlesEmitter(ParticlesEmitter && move) noexcept
				 * @param[in] move The ParticlesEmitter to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				ParticlesEmitter(ParticlesEmitter && move) noexcept = default;

				/**
				 * @fn ~ParticlesEmitter() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~ParticlesEmitter() noexcept = default;

				/**
				 * @fn ParticlesEmitter & operator=(const ParticlesEmitter & copy)
				 * @param[in] copy The ParticlesEmitter to copy from.
				 * @return The ParticlesEmitter copied.
				 * @brief Default copy assignment operator.
				 * @throw
				 */
				ParticlesEmitter & operator=(const ParticlesEmitter & copy) = default;

				/**
				 * @fn ParticlesEmitter & operator=(ParticlesEmitter && move) noexcept
				 * @param[in] move The ParticlesEmitter to move.
				 * @return The ParticlesEmitter moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				ParticlesEmitter & operator=(ParticlesEmitter && move) noexcept = default;

				void update(const float elapsedTime);

				virtual void draw([[maybe_unused]] std::shared_ptr<Shader> program) override;
			private:
				VertexBuffer<SymetricStorage, std::vector<Particle>> _particles;
				std::size_t _size;

				VertexBuffer<SymetricStorage, std::vector<float>> _vertices;
			};
		} // namespace renderable
	} // namespace graphic
} // namespace ece