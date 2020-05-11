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

#include "game_data.hpp"
#include "core/resource.hpp"
#include "components/graphic.hpp"
#include "components/motion.hpp"
#include "components/control.hpp"
#include "components/collision.hpp"

GameData::GameData(ece::World & world) noexcept :
	onSplashScreenEntered(), onPlayEntered(), _current(NONE), _background(world.createEntity()), _scoreA{ world.createEntity(), 0 }, _scoreB{ world.createEntity(), 0 },
	_playerA(world.createEntity()), _playerB(world.createEntity())
{
	{
		auto sprite = ece::makeResource<ece::Sprite>("background", ece::getResource<ece::Texture2D>("titel"), ece::Rectangle<float>{ 240.0f, 0.0f, 1440.0f, 1080.0f });
		sprite->setLevel(0);
		this->_background.addComponent<Graphic>(sprite);

		auto leftWall = world.createEntity();
		auto & leftCollision = leftWall.addComponent<Collision>();
		leftCollision.bounds = {239.0f, 0.0f, 1.0f, 1080.0f };

		auto rightWall = world.createEntity();
		auto & rightCollision = rightWall.addComponent<Collision>();
		rightCollision.bounds = { 1440.0f + 240.0f, 0.0f, 1.0f, 1080.0f };

		auto upWall = world.createEntity();
		auto & upCollision = upWall.addComponent<Collision>();
		upCollision.bounds = { 240.0f, 1080.0f, 1440.0f, 1.0f };

		auto bottomWall = world.createEntity();
		auto & bottomCollision = bottomWall.addComponent<Collision>();
		bottomCollision.bounds = { 240.0f, -1.0f, 1440.0f, 1.0f };
	}
	this->setState(PLAY);
}

void GameData::setState(const GameData::State state)
{
	this->_current = state;
	switch (state)
	{
	case SPLASHSCREEN:
	{
		{
			auto sprite = ece::getResource<ece::Sprite>("background");
			sprite->setTexture(ece::getResource<ece::Texture2D>("titel"));
		}
		this->onSplashScreenEntered();
		break;
	}
	case PLAY:
	{
		// Background entity
		{
			auto sprite = ece::getResource<ece::Sprite>("background");
			sprite->setTexture(ece::getResource<ece::Texture2D>("strand1"));
		}

		// Score A entity
		{
			auto sprite = ece::makeResource<ece::Sprite>("scoreA", ece::getResource<ece::Texture2D>("f0"));
			sprite->setLevel(1);
			auto bounds = sprite->getBounds();
			sprite->setBounds({ 220.0f, 940.0f, bounds.width * 2.0f, bounds.height * 2.0f });
			this->_scoreA.handle.addComponent<Graphic>(sprite);
		}

		// Score B entity
		{
			auto sprite = ece::makeResource<ece::Sprite>("scoreB", ece::getResource<ece::Texture2D>("f0"));
			sprite->setLevel(1);
			auto bounds = sprite->getBounds();
			sprite->setBounds({ 1840.0f, 940.0f, bounds.width * 2.0f, bounds.height * 2.0f });
			this->_scoreB.handle.addComponent<Graphic>(sprite);
		}

		// Player A entity
		{
			auto & space = this->_playerA.addComponent<Motion>();
			space.position = { 10.0f, 800.0f };
			space.velocity = { 0.0f, 0.0f };
			space.weight = 70.0f;
			auto sprite = ece::makeResource<ece::Sprite>("playerA", ece::getResource<ece::Texture2D>("blue0"));
			sprite->setLevel(1);
			sprite->moveTo(space.position);
			this->_playerA.addComponent<Graphic>(sprite);

			auto & control = this->_playerA.addComponent<Control>();
			control.binding[ece::Keyboard::Key::Z] = Action::JUMP;
			control.binding[ece::Keyboard::Key::Q] = Action::TO_LEFT;
			control.binding[ece::Keyboard::Key::S] = Action::SNEAK;
			control.binding[ece::Keyboard::Key::D] = Action::TO_RIGHT;

			auto & collision = this->_playerA.addComponent<Collision>();
			collision.bounds = sprite->getBounds();
		}

		// Player B entity
		{
			auto & space = this->_playerB.addComponent<Motion>();
			space.position = { 0.0f, 400.0f };
			space.velocity = { 0.0f, 0.0f };
			space.weight = 70.0f;
			auto sprite = ece::makeResource<ece::Sprite>("playerB", ece::getResource<ece::Texture2D>("red0"));
			sprite->setLevel(1);
			sprite->moveTo(space.position);
			this->_playerB.addComponent<Graphic>(sprite);

			auto & control = this->_playerB.addComponent<Control>();
			control.binding[ece::Keyboard::Key::UP] = Action::JUMP;
			control.binding[ece::Keyboard::Key::LEFT] = Action::TO_LEFT;
			control.binding[ece::Keyboard::Key::DOWN] = Action::SNEAK;
			control.binding[ece::Keyboard::Key::RIGHT] = Action::TO_RIGHT;

			auto & collision = this->_playerB.addComponent<Collision>();
			collision.bounds = sprite->getBounds();
		}

		this->onPlayEntered();
		break;
	}
	case NONE:
		break;
	default:
		break;
	}
}