/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

															   oooo                                                                            o8o
															   `888                                                                            `"'
																888  .oooo.   oooo    ooo  .oooo.    .ooooo oo oooo  oooo   .oooo.   oooo d8b oooo  oooo  oooo  ooo. .oo.  .oo.
																888 `P  )88b   `88.  .8'  `P  )88b  d88' `888  `888  `888  `P  )88b  `888""8P `888  `888  `888  `888P"Y88bP"Y88b
																888  .oP"888    `88..8'    .oP"888  888   888   888   888   .oP"888   888      888   888   888   888   888   888
																888 d8(  888     `888'    d8(  888  888   888   888   888  d8(  888   888      888   888   888   888   888   888
															.o. 88P `Y888""8o     `8'     `Y888""8o `V8bod888   `V88V"V8P' `Y888""8o d888b    o888o  `V88V"V8P' o888o o888o o888o
															`Y888P                                        888.
																										  8P'
																										  "


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

#include "systems/health.hpp"
#include "components/living.hpp"
#include "components/alga.hpp"
#include "components/fish.hpp"


Health::Health(ece::World& world) noexcept : ece::System(world)
{
}

void Health::update([[maybe_unused]] float elapsedTime)
{
	this->_world.getComponents<Living>().forEach([this](auto& living) {
		if (living) {
			++living.age;
			if (living.age >= 20) {
				ece::WARNING << "ID #" << living.getOwner() << " has died of old age." << ece::flush;
				this->_world.destroy(living.getOwner());
			}
			else if (living.life <= 0) {
				ece::WARNING << "ID #" << living.getOwner() << " has died of an unknown reason." << ece::flush;
				this->_world.destroy(living.getOwner());
			}
			else {
				auto handler = ece::EntityHandler(living.getOwner(), this->_world);

				if (handler.hasComponent<Alga>()) {
					++living.life;
				}
				else if (handler.hasComponent<Fish>()) {
					--living.life;
				}

				if (living.life <= 0) {
					ece::WARNING << "ID #" << living.getOwner() << " doesn't find any food and starves to death." << ece::flush;
					this->_world.destroy(living.getOwner());
				}
			}
		}
	});
}