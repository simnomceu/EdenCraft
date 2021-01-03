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

#include "systems/aquarium.hpp"
#include "components/alga.hpp"
#include "components/fish.hpp"
#include "components/diet.hpp"
#include "components/living.hpp"
#include "incubator.hpp"


Aquarium::Aquarium(ece::World& world) noexcept : ece::System(world), _turn(0)
{
}

Aquarium::~Aquarium()
{
	ece::INFO << "##### END #####" << ece::flush;
	ece::INFO << "Number of algas : " << this->_world.getComponents<Alga>().size() << ece::flush;
	ece::INFO << "Number of fishes : " << this->_world.getComponents<Fish>().size() << ece::flush;
}

void Aquarium::update([[maybe_unused]] float elapsedTime)
{
	++this->_turn;

	ece::INFO << "##### Turn " << this->_turn << " #####" << ece::flush;
	ece::INFO << "Number of algas : " << this->_world.getComponents<Alga>().size() << ece::flush;
	ece::INFO << "Number of fishes : " << this->_world.getComponents<Fish>().size() << ece::flush;
	this->_world.getComponents<Fish>().forEach([this](auto& fish) {
		if (fish) {
			auto fishId = ece::EntityHandler(fish.getOwner(), this->_world);

			if (fish) {
				ece::INFO << "    ID #" << fish.getOwner() << ": " << fish.name << " the " << fish.specie << " (" << (fish.gender == Gender::MALE ? "M" : "F") << ") ["
					<< fishId.getComponent<Living>().life << " PV]" << ece::flush;
			}
		}
	});
}

void Aquarium::init(int numberOfFishes, int numberOfAlgas)
{
	for (auto i = 0; i < numberOfFishes; ++i) {
		auto specie = std::rand() % 6;
		switch (specie) {
		case 0: create(this->_world, "grouper"); break;
		case 1: create(this->_world, "tuna"); break;
		case 2: create(this->_world, "clownfish"); break;
		case 3: create(this->_world, "sole"); break;
		case 4: create(this->_world, "bass"); break;
		case 5: create(this->_world, "carp"); break;
		default: break;
		}
	}

	for (auto i = 0; i < numberOfAlgas; ++i) {
		create(this->_world, "alga");
	}
}


int Aquarium::getTurn() const
{
	return this->_turn;
}