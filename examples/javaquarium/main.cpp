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

#include "core/application.hpp"
#include "systems/aquarium.hpp"
#include "systems/food_chain.hpp"
#include "systems/health.hpp"
#include "systems/reproduction.hpp"
#include "systems/back_up.hpp"
#include "components/fish.hpp"
#include "core/format.hpp"

int main()
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	try {
		auto app = ece::Application();

		ece::ServiceFormatLocator().getService().registerLoader<ece::JSONLoader>("json");
		ece::ServiceFormatLocator().getService().registerSaver<ece::JSONLoader>("json");

		auto & world = app.addWorld();
		auto & aquarium = world.addSystem<Aquarium>();
		world.addSystem<Health>();
		world.addSystem<FoodChain>();
		world.addSystem<Reproduction>();
		world.addSystem<BackUp>();

		app.onPostInit.connect([&aquarium]() {
			aquarium.init(10, 2);
		});

		app.onPostUpdate.connect([&aquarium, &app, &world]() {
			if (aquarium.getTurn() >= 20 || world.getComponents<Fish>().size() == 0) {
				app.stop();
			}
		});

		app.run();
	}
	catch (std::runtime_error& e) {
		ece::ERROR << e.what() << ece::flush;
	}
	catch (std::exception& e) {
		ece::ERROR << e.what() << ece::flush;
	}

	return EXIT_SUCCESS;
}