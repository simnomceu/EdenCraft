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

#include "systems/back_up.hpp"
#include "components/alga.hpp"
#include "components/diet.hpp"
#include "components/fish.hpp"
#include "components/living.hpp"
#include "components/sexuality.hpp"
#include "utility/formats.hpp"
#include "core/resource.hpp"

BackUp::BackUp(ece::World& world) noexcept : ece::System(world)
{
}

BackUp::~BackUp()
{
}

void BackUp::update([[maybe_unused]] float elapsedTime)
{
	auto object = ece::makeResource<ece::ObjectJSON>("backup");
	object->clear();
	object->addInteger("numberOfEntities", static_cast<int>(this->_world.getNumberofEntities()));
	auto entities = object->addArray("entities");
	auto entitiesNode = ece::NodeJSON::convertTo<ece::ArrayJSON>(entities);

	this->_world.forEachEntity([&entitiesNode](ece::EntityHandler entity) {
		auto entityNodePtr = entitiesNode->addObject();
		auto entityNode = ece::NodeJSON::convertTo<ece::ObjectJSON>(entityNodePtr);

		if (entity.hasComponent<Alga>()) {
			entityNode->addObject("alga");
		}
		if (entity.hasComponent<Diet>()) {
			auto & diet = entity.getComponent<Diet>();
			auto dietNodePtr = entityNode->addObject("diet");
			auto dietNode = ece::NodeJSON::convertTo<ece::ObjectJSON>(dietNodePtr);
			dietNode->addString("type", (diet.type == DietType::CARNIVOROUS ? "carnivorous" : "herbivorous"));
		}
		if (entity.hasComponent<Fish>()) {
			auto& fish = entity.getComponent<Fish>();
			auto fishNodePtr = entityNode->addObject("fish");
			auto fishNode = ece::NodeJSON::convertTo<ece::ObjectJSON>(fishNodePtr);
			fishNode->addString("name", fish.name);
			fishNode->addString("gender", (fish.gender == Gender::MALE ? "male" : "female"));
			fishNode->addString("specie", fish.specie);
		}
		if (entity.hasComponent<Living>()) {
			auto& living = entity.getComponent<Living>();
			auto livingNodePtr = entityNode->addObject("living");
			auto livingNode = ece::NodeJSON::convertTo<ece::ObjectJSON>(livingNodePtr);
			livingNode->addInteger("life", living.life);
			livingNode->addInteger("age", living.age);
		}
		if (entity.hasComponent<Sexuality>()) {
			auto& sexuality = entity.getComponent<Sexuality>();
			auto sexualityNodePtr = entityNode->addObject("sexuality");
			auto sexualityNode = ece::NodeJSON::convertTo<ece::ObjectJSON>(sexualityNodePtr);
			sexualityNode->addInteger("type", static_cast<int>(sexuality.type));
		}
	});
	ece::ResourceLoader().saveToFile("../../examples/javaquarium/resources/backup.json", { object });
}