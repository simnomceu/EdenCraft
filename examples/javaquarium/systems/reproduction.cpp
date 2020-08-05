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

Reproduction::Reproduction(ece::World& world) noexcept: System(world)
{
}

void Reproduction::update([[maybe_unused]] float elapsedTime)
{
	for (auto& sexuality : *this->_world.getTank<Sexuality>()) {
		auto fishId = ece::EntityHandler(sexuality.getOwner(), this->_world);
		auto & fish = fishId.getComponent<Fish>();

		if (!sexuality.isDirty()) {
			if (sexuality.ready) {
				switch (sexuality.type) {
				case SexualityType::MONOSEXUAL: {
					auto partnerId = ece::EntityHandler(this->_world.getTank<Fish>()->at(rand() % this->_world.getTank<Fish>()->size()).getOwner(), this->_world);
					auto & partner = partnerId.getComponent<Fish>();
					auto & partnerLiving = partnerId.getComponent<Living>();
					if (partner.gender != fish.gender && partner.specie == fish.specie && partnerLiving.life >= 5 && partnerId.getId() != fishId.getId()) {
						auto baby = create(this->_world, this->_world.getComponent<Fish>(id).specie);
						baby.getComponent<Sexuality>().ready = false;
						ece::INFO << this->_world.getComponent<Fish>(id).name << " the " << this->_world.getComponent<Fish>(id).specie << " and "
							<< this->_world.getComponent<Fish>(partner).name << " the " << this->_world.getComponent<Fish>(partner).specie
							<< " bring a baby into this aquarium : " << baby.getComponent<Fish>().name << " the "
							<< baby.getComponent<Fish>().specie << "." << ece::flush;
					}
				}
											  break;
				case SexualityType::SWINGER: {
					if (this->_world.getComponent<Living>(id).life >= 5) {
						if (this->_world.getComponent<Living>(id).life >= 10 && this->_world.getComponent<Fish>(id).gender == Gender::MALE) {
							this->_world.getComponent<Fish>(id).gender = Gender::FEMALE;
						}

						auto partner = this->_world.getTank<Fish>()->at(rand() % this->_world.getTank<Fish>()->size()).getOwner();
						if (this->_world.getComponent<Fish>(partner).gender != this->_world.getComponent<Fish>(id).gender
							&& this->_world.getComponent<Fish>(partner).specie == this->_world.getComponent<Fish>(id).specie && partner != id) {
							auto baby = create(this->_world, this->_world.getComponent<Fish>(id).specie);
							baby.getComponent<Sexuality>().ready = false;
							ece::INFO << this->_world.getComponent<Fish>(id).name << " the " << this->_world.getComponent<Fish>(id).specie << " and "
								<< this->_world.getComponent<Fish>(partner).name << " the " << this->_world.getComponent<Fish>(partner).specie
								<< " bring a baby into this aquarium : " << baby.getComponent<Fish>().name << " the "
								<< baby.getComponent<Fish>().specie << "." << ece::flush;
						}
					}
				}
										   break;
				case SexualityType::OPPORTUNIST: {
					auto partner = this->_world.getTank<Fish>()->at(rand() % this->_world.getTank<Fish>()->size()).getOwner();
					if (this->_world.getComponent<Fish>(partner).specie == this->_world.getComponent<Fish>(id).specie
						&& this->_world.getComponent<Living>(id).life >= 5 && partner != id) {
						if (this->_world.getComponent<Fish>(partner).gender == this->_world.getComponent<Fish>(id).gender) {
							this->_world.getComponent<Fish>(id).gender = (this->_world.getComponent<Fish>(id).gender == Gender::MALE ? Gender::FEMALE : Gender::MALE);
						}
						auto baby = create(this->_world, this->_world.getComponent<Fish>(id).specie);
						baby.getComponent<Sexuality>().ready = false;
						ece::INFO << this->_world.getComponent<Fish>(id).name << " the " << this->_world.getComponent<Fish>(id).specie << " and "
							<< this->_world.getComponent<Fish>(partner).name << " the " << this->_world.getComponent<Fish>(partner).specie
							<< " bring a baby into this aquarium : " << baby.getComponent<Fish>().name << " the "
							<< baby.getComponent<Fish>().specie << "." << ece::flush;
					}
				}
											   break;
				case SexualityType::PARTHENOGENESIS:
					if (this->_world.getComponent<Living>(id).life >= 10) {
						auto newLife = this->_world.getComponent<Living>(id).life / 2;
						this->_world.getComponent<Living>(id).life = newLife;
						auto baby = create(this->_world, this->_world.hasComponent<Fish>(id) ? this->_world.getComponent<Fish>(id).specie : "alga");
						baby.getComponent<Sexuality>().ready = false;
						baby.getComponent<Living>().life = newLife;
						ece::INFO << "Alga ID #" << id << " bring a baby alga into this aquarium : Alga ID #" << baby.getId() << "." << ece::flush;
					}
					break;
				default: break;
				}
			}
			sexuality.ready = true;
		}
	}
	std::cin.get();
}