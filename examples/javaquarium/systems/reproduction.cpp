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

#include "systems/reproduction.hpp"
#include "components/sexuality.hpp"
#include "components/living.hpp"
#include "components/fish.hpp"
#include "incubator.hpp"

Reproduction::Reproduction(ece::World& world) noexcept: ece::System(world)
{
}

void Reproduction::update([[maybe_unused]] float elapsedTime)
{
	auto babyFishes = std::vector<std::tuple<Fish, Fish, std::string>>();
	auto babyAlgas = std::vector<std::tuple<ece::EntityHandler, unsigned int>>();
	this->_world.getComponents<Sexuality>().forEach([this, &babyFishes, &babyAlgas](auto& sexuality) {
		if (!sexuality.isDirty()) {
			auto fishId = ece::EntityHandler(sexuality.getOwner(), this->_world);
			auto& fishLiving = fishId.getComponent<Living>();

			if (sexuality.ready && fishLiving.life >= 5) {
				switch (sexuality.type) {
				case SexualityType::MONOSEXUAL: {
					auto& fish = fishId.getComponent<Fish>();
					auto partnerId = ece::EntityHandler(this->_world.getComponents<Fish>().at(rand() % this->_world.getComponents<Fish>().size()).getOwner(), this->_world);
					auto [partner, partnerLiving] = partnerId.getComponents<Fish, Living>();
					if (partner.gender != fish.gender && partner.specie == fish.specie && partnerLiving.life >= 5 && partnerId != fishId) {
						babyFishes.push_back({ fish, partner, fish.specie });
					}
				} break;
				case SexualityType::SWINGER: {
					auto& fish = fishId.getComponent<Fish>();
					if (fishLiving.life >= 5) {
						if (fishLiving.life >= 10 && fish.gender == Gender::MALE) {
							fish.gender = Gender::FEMALE;
						}

						auto partnerId = ece::EntityHandler(this->_world.getComponents<Fish>().at(rand() % this->_world.getComponents<Fish>().size()).getOwner(), this->_world);
						auto& partner = partnerId.getComponent<Fish>();
						if (partner.gender != fish.gender && partner.specie == fish.specie && partnerId != fishId) {
							babyFishes.push_back({ fish, partner, fish.specie });
						}
					}
				} break;
				case SexualityType::OPPORTUNIST: {
					auto& fish = fishId.getComponent<Fish>();
					auto partnerId = ece::EntityHandler(this->_world.getComponents<Fish>().at(rand() % this->_world.getComponents<Fish>().size()).getOwner(), this->_world);
					auto& partner = partnerId.getComponent<Fish>();
					if (partner.specie == fish.specie && fishLiving.life >= 5 && partnerId != fishId) {
						if (partner.gender == fish.gender) {
							fish.gender = (fish.gender == Gender::MALE ? Gender::FEMALE : Gender::MALE);
						}
						babyFishes.push_back({ fish, partner, fish.specie });
					}
				} break;
				case SexualityType::PARTHENOGENESIS: {
					if (fishLiving.life >= 10) {
						auto newLife = fishLiving.life / 2;
						fishLiving.life = newLife;
						babyAlgas.push_back({ fishId, newLife });
					}
				} break;
				default: break;
				}
			}
			sexuality.ready = true;
		}
	});

	for (auto & [parent1, parent2, specie] : babyFishes) {
		auto babyId = create(this->_world, specie);
		babyId.getComponent<Sexuality>().ready = false;
		auto& baby = babyId.getComponent<Fish>();
		ece::INFO << parent1.name << " the " << parent1.specie << " and " << parent2.name << " the " << parent2.specie << " bring a baby into this aquarium : "
			<< baby.name << " the " << baby.specie << "." << ece::flush;
	}
	for (auto& [parent, age] : babyAlgas) {
		auto baby = create(this->_world, parent.hasComponent<Fish>() ? parent.getComponent<Fish>().specie : "alga");
		baby.getComponent<Sexuality>().ready = false;
		baby.getComponent<Living>().life = age;
		ece::INFO << "Alga ID #" << parent.getId() << " bring a baby alga into this aquarium : Alga ID #" << baby.getId() << "." << ece::flush;
	}
	std::cin.get();
}