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
#include "components/living.hpp"
#include "components/sexuality.hpp"

FoodChain::FoodChain(ece::World& world) noexcept : ece::System(world)
{
}

void FoodChain::update([[maybe_unused]] float elapsedTime)
{
	ece::INFO << "##### Lunch Time #####" << ece::flush;

	const auto nbAlgas = this->_world.getTank<Alga>().size();
	const auto nbFishes = this->_world.getTank<Fish>().size();

	for (auto & fish : this->_world.getTank<Diet>()) {
		if (!fish.isDirty()) {
			auto fishId = ece::EntityHandler(fish.getOwner(), this->_world);
			auto [fishLiving, fishSexuality, fishFish] = fishId.getComponents<Living, Sexuality, Fish>();
			if (!fish.isDirty() && fishLiving.isAlive() && fishLiving.life <= 5) {
				if (fish.type == DietType::HERBIVOROUS) {
					if (nbAlgas > 0) {
						bool feed = false;
						do {
							auto targetId = ece::EntityHandler(this->_world.getTank<Alga>().at(std::rand() % nbAlgas).getOwner(), this->_world);
							auto& targetLiving = targetId.getComponent<Living>();
							feed = targetLiving.isAlive();
							if (feed) {
								fishLiving.life += 3;
								fishSexuality.ready = false;
								ece::INFO << fishFish.name << " the " << fishFish.specie << " (+3 PV) eats an alga (-2 PV)." << ece::flush;

								targetLiving.life -= 2;
								if (!targetLiving.isAlive()) {
									ece::WARNING << "Alga ID #" << targetId.getId() << " was too weak and died." << ece::flush;
									this->_world.destroy(targetId.getId());
								}
							}
						} while (!feed);
					}
				}
				else if (fish.type == DietType::CARNIVOROUS) {
					if (nbFishes > 1) {
						bool feed = false;
						do {
							auto targetId = ece::EntityHandler(this->_world.getTank<Fish>().at(std::rand() % nbFishes).getOwner(), this->_world);
							auto [targetLiving, targetFish] = targetId.getComponents<Living, Fish>();
							feed = targetLiving.isAlive() && targetId != fishId && targetFish.specie != fishFish.specie;
							if (feed) {
								fishLiving.life += 5;
								fishSexuality.ready = false;
								ece::INFO << fishFish.name << " the " << fishFish.specie << " (+5 PV) eats " << targetFish.name << " the " << targetFish.specie << " (-4 PV)." << ece::flush;

								targetLiving.life -= 4;
								if (!targetLiving.isAlive()) {
									ece::WARNING << targetFish.name << " the " << targetFish.specie << " was too weak and died." << ece::flush;
									this->_world.destroy(targetId.getId());
								}
							}
						} while (!feed);
					}
				}
			}
		}
	}

	std::cin.get();
}