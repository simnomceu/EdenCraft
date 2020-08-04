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

#include "systems/food_chain.hpp"
#include "components/diet.hpp"
#include "components/alga.hpp"
#include "components/fish.hpp"

FoodChain::FoodChain(ece::World& world) noexcept : System(world)
{
}

void FoodChain::update([[maybe_unused]] float elapsedTime)
{
	ece::INFO << "##### Lunch Time #####\n";

	auto nbAlgas = this->_world.getTank<Alga>()->size();
	const auto nbFishes = this->_world.getTank<Fish>()->size();

	for (auto & fish : *this->_world.getTank<Diet>()) {
		if (this->_world.getComponent<Fish>(fish.getOwner()).alive) {
			if (fish.type == DietType::HERBIVOROUS) {
				if (nbAlgas > 0) {
					auto id = std::rand() % nbAlgas;
					this->_world.getTank<Alga>()->erase(this->_world.getTank<Alga>()->begin() + id);
					--nbAlgas;
					ece::INFO << this->_world.getComponent<Fish>(fish.getOwner()).name << " eats an alga.\n";
				}
				else {
					this->_world.getComponent<Fish>(fish.getOwner()).alive = false;
					ece::INFO << this->_world.getComponent<Fish>(fish.getOwner()).name << " doesn't find any alga and starves to death.\n";
				}
			}
			else if (fish.type == DietType::CARNIVOROUS) {
				if (nbFishes > 1) {
					bool feed = false;
					do {
						auto id = std::rand() % nbFishes;
						feed = this->_world.getTank<Fish>()->at(id).alive && this->_world.getTank<Fish>()->at(id).getOwner() != fish.getOwner();
						if (feed) {
							this->_world.getTank<Fish>()->at(id).alive = false;
							ece::INFO << this->_world.getComponent<Fish>(fish.getOwner()).name << " eats " << this->_world.getTank<Fish>()->at(id).name << ".\n";
						}
					} while (!feed);
				}
				else if (nbFishes == 1) {
					this->_world.getComponent<Fish>(fish.getOwner()).alive = false;
					ece::INFO << this->_world.getComponent<Fish>(fish.getOwner()).name << " doesn't find any prey and starves to death.\n";
				}
			}
		}
	}

	for (auto & fish : *this->_world.getTank<Fish>()) {
		if (!fish.alive) {
			this->_world.destroy(fish.getOwner());
		}
	}

	ece::INFO << ece::flush;
	std::cin.get();
}