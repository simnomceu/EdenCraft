/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

							ooooooooo.                          .    o8o            oooo                          oooooooooooo
						   `888   `Y88.                      .o8    `"'            `888                          `888'     `8
							888   .d88'  .oooo.   oooo d8b .o888oo oooo   .ooooo.   888   .ooooo.   .oooo.o       888          .ooooo.  oooo d8b  .ooooo.  oooo    ooo  .ooooo.  oooo d8b
							888ooo88P'  `P  )88b  `888""8P   888   `888  d88' `"Y8  888  d88' `88b d88(  "8       888oooo8    d88' `88b `888""8P d88' `88b  `88.  .8'  d88' `88b `888""8P
							888          .oP"888   888       888    888  888        888  888ooo888 `"Y88b.        888    "    888   888  888     888ooo888   `88..8'   888ooo888  888
							888         d8(  888   888       888 .  888  888   .o8  888  888    .o o.  )88b       888         888   888  888     888    .o    `888'    888    .o  888
						   o888o        `Y888""8o d888b      "888" o888o `Y8bod8P' o888o `Y8bod8P' 8""888P'      o888o        `Y8bod8P' d888b    `Y8bod8P'     `8'     `Y8bod8P' d888b



				This file is part of EdenCraft Engine - Particles Forever sample.
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

#ifndef RENDER_SYSTEM_HPP
#define RENDER_SYSTEM_HPP

#include "core/ecs.hpp"
#include "renderer/pipeline.hpp"
#include "graphic/scene.hpp"

/**
 * @class RenderSystem
 * @brief
 */
class RenderSystem: public ece::System
{
public:
	/**
	 * @fn constexpr RenderSystem(World & world) noexcept
	 * @brief Default constructor.
	 * @throw noexcept
	 */
	RenderSystem(ece::World & world) noexcept;

	/**
	 * @fn RenderSystem(const RenderSystem & copy) noexcept
	 * @param[in] copy The RenderSystem to copy from.
	 * @brief Default copy constructor.
	 * @throw noexcept
	 */
	RenderSystem(const RenderSystem & copy) noexcept = default;

	/**
	 * @fn RenderSystem(RenderSystem && move) noexcept
	 * @param[in] move The RenderSystem to move.
	 * @brief Default move constructor.
	 * @throw noexcept
	 */
	RenderSystem(RenderSystem && move) noexcept = default;

	/**
	 * @fn ~RenderSystem() noexcept
	 * @brief Default destructor.
	 * @throw noexcept
	 */
	~RenderSystem() noexcept = default;

	/**
	 * @fn RenderSystem & operator=(const RenderSystem & copy) noexcept
	 * @param[in] copy The RenderSystem to copy from.
	 * @return The RenderSystem copied.
	 * @brief Default copy assignment operator.
	 * @throw noexcept
	 */
	RenderSystem & operator=(const RenderSystem & copy) noexcept = default;

	/**
	 * @fn RenderSystem & operator=(RenderSystem && move) noexcept
	 * @param[in] move The RenderSystem to move.
	 * @return The RenderSystem moved.
	 * @brief Default move assignment operator.
	 * @throw noexcept
	 */
	RenderSystem & operator=(RenderSystem && move) noexcept = default;

	virtual void update(float elapsedTime) override;

	ece::Scene & getScene();

private:
	std::unique_ptr<ece::RenderProcess> _process;
	ece::Scene _scene;
};

#endif // RENDER_SYSTEM_HPP
