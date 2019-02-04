/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

															oooooooooo.               .o8        .o8       oooo            oooooo     oooo           oooo  oooo
															`888'   `Y8b             "888       "888       `888             `888.     .8'            `888  `888
															 888     888 oooo  oooo   888oooo.   888oooo.   888   .ooooo.    `888.   .8'    .ooooo.   888   888   .ooooo.  oooo    ooo
															 888oooo888' `888  `888   d88' `88b  d88' `88b  888  d88' `88b    `888. .8'    d88' `88b  888   888  d88' `88b  `88.  .8'
															 888    `88b  888   888   888   888  888   888  888  888ooo888     `888.8'     888   888  888   888  888ooo888   `88..8'
															 888    .88P  888   888   888   888  888   888  888  888    .o      `888'      888   888  888   888  888    .o    `888'
															o888bood8P'   `V88V"V8P'  `Y8bod8P'  `Y8bod8P' o888o `Y8bod8P'       `8'       `Y8bod8P' o888o o888o `Y8bod8P'     .8'
																																										   .o..P'
																																										   `Y8P'



				This file is part of EdenCraft Engine - MoreCube sample.
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

#include "systems/physic.hpp"
#include "components/motion.hpp"
#include "components/collision.hpp"
#include "components/control.hpp"

const float Physic::gravity = 9.81f;

Physic::Physic(ece::World & world) noexcept: System(world), _lastUpdate(0.0f)
{

}

void Physic::update(float elapsedTime)
{
	const auto limit = 1.0f / 200.0f;
	this->_lastUpdate += elapsedTime;
	if (this->_lastUpdate >= limit) {
		const auto floor = 200.0f;
		const auto ratioMeter = 400.0f / 2.43f;
		for (auto & motion : *this->_world.getTank<Motion>()) {
			// Update position
			const auto force = ece::FloatVector2u{ 0.0f, motion.weight * -Physic::gravity };
			ece::FloatVector2u acceleration = force / motion.weight;
			motion.velocity += acceleration * elapsedTime;
			motion.velocity[0] = std::clamp(motion.velocity[0], -4.0f, 4.0f);
			motion.velocity[1] = std::clamp(motion.velocity[1], -7.0f, 7.0f);

			motion.position += motion.velocity * elapsedTime * ratioMeter;

			motion.position[1] = std::max(motion.position[1], floor);

			auto owner = motion.getOwner();

			// Check position with collisions
			if (this->_world.hasComponent<Collision>(owner)) {
				auto & collision = this->_world.getComponent<Collision>(owner);
				for (auto & collisionBis : *this->_world.getTank<Collision>()) {
					if (collisionBis.getID() != collision.getID()) {
						auto intersect = collisionBis.bounds.intersects(collision.bounds);
					}
				}
			}

			// Update acceleration
			if (this->_world.hasComponent<Control>(owner)) {
				auto & control = this->_world.getComponent<Control>(owner);

				auto vertical = ((control.current & Action::JUMP) == Action::JUMP) || ((control.current & Action::SNEAK) == Action::SNEAK);
				auto horizontal = ((control.current & Action::TO_LEFT) == Action::TO_LEFT) || ((control.current & Action::TO_RIGHT) == Action::TO_RIGHT);
				auto factor = (vertical && horizontal) ? 1.0f / std::sqrt(2.0f) : 1.0f;

				if ((control.current & Action::JUMP) == Action::JUMP) {
					motion.velocity += ece::FloatVector2u{ 0.0f, 10.0f * factor };
				}
				if ((control.current & Action::TO_LEFT) == Action::TO_LEFT) {
					motion.velocity += ece::FloatVector2u{ -1.0f * factor, 0.0f };
				}
				if ((control.current & Action::SNEAK) == Action::SNEAK) {
					motion.velocity += ece::FloatVector2u{ 0.0f, -10.0f * factor };
				}
				if ((control.current & Action::TO_RIGHT) == Action::TO_RIGHT) {
					motion.velocity += ece::FloatVector2u{ 1.0f * factor, 0.0f };
				}

			/*	if (!vertical && motion.velocity[1] != 0.0f) {
					motion.velocity += ece::FloatVector2u{ 0.0f, motion.velocity[1] > 0.0f ? -1.0f : 1.0f };
				}
				if (!horizontal && motion.velocity[0] != 0.0f) {
					motion.velocity += ece::FloatVector2u{ motion.velocity[0] > 0.0f ? -1.0f : 1.0f, 0.0f };
				} */
			}
		}

		this->_lastUpdate = 0.0f;
	}
}