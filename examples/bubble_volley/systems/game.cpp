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

#include "systems/game.hpp"

#include "components/control.hpp"
#include "components/collision.hpp"

Game::Game(ece::World & world) noexcept : System(world), _game(nullptr), _lastUpdate(0.0f), _groundId(ece::NULL_HANDLE)
{
	this->_world.onComponentCreated.connect([this](ece::BaseComponent & component) {
		if (component.is<Collision>()) {
			auto & collision = component.to<Collision>();
			if (!this->_world.hasComponent<Collision>(this->_groundId)) {
				this->_groundId = component.getOwner();
			}
			else {
				auto & ground = this->_world.getComponent<Collision>(this->_groundId);
				this->_groundId = (collision.bounds.y > ground.bounds.y) ? collision.getOwner() : this->_groundId;
			}
		}
	});
}

void Game::update(float elapsedTime)
{
	const auto limit = 1.0f / 200.0f;
	this->_lastUpdate += elapsedTime;
	if (this->_lastUpdate >= limit) {
		this->_world.getComponents<Control>().forEach([](auto& control) {
			control.current = Action::NONE;
			for (auto [key, value] : control.binding) {
				if (ece::Keyboard::isKeyPressed(key)) {
					control.current = control.current | value;
				}
			}
		});

		this->_lastUpdate = 0.0f;
	}
}

void Game::initGame()
{
	this->_game = std::make_shared<GameData>(this->_world);
}