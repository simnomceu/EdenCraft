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

#include "game.hpp"
#include "core/resource.hpp"
#include "components/graphic.hpp"
#include "space_component.hpp"

Game::Game(ece::World & world) noexcept :
	onSplashScreenEntered(), onPlayEntered(), _current(NONE), _background(world.createEntity()), _scoreA{ world.createEntity(), 0 }, _scoreB{ world.createEntity(), 0 },
	_playerA(world.createEntity()), _playerB(world.createEntity())
{
	{
		auto sprite = ece::makeResource<ece::Sprite>("background", ece::ServiceResourceLocator::getService().getResource<ece::Texture2D>("titel"), ece::Rectangle<float>{ 240.0f, 0.0f, 1440.0f, 1080.0f });
		sprite->setLevel(0);
		this->_background.addComponent<Graphic>(sprite);
	}
	this->setState(PLAY);
}

void Game::setState(const Game::State state)
{
	this->_current = state;
	switch (state)
	{
	case SPLASHSCREEN:
	{
		{
			auto sprite = ece::getResource<ece::Sprite>("background");
			sprite->setTexture(ece::ServiceResourceLocator::getService().getResource<ece::Texture2D>("titel"));
		}
		this->onSplashScreenEntered();
		break;
	}
	case PLAY:
	{
		{
			auto sprite = ece::getResource<ece::Sprite>("background");
			sprite->setTexture(ece::ServiceResourceLocator::getService().getResource<ece::Texture2D>("strand1"));
		}
		{
			auto sprite = ece::makeResource<ece::Sprite>("scoreA", ece::ServiceResourceLocator::getService().getResource<ece::Texture2D>("f0"));
			sprite->setLevel(1);
			auto bounds = sprite->getBounds();
			sprite->setBounds({ 220.0f, 940.0f, bounds.width * 2.0f, bounds.height * 2.0f });
			this->_scoreA.handle.addComponent<Graphic>(sprite);
		}
		{
			auto sprite = ece::makeResource<ece::Sprite>("scoreB", ece::ServiceResourceLocator::getService().getResource<ece::Texture2D>("f0"));
			sprite->setLevel(1);
			auto bounds = sprite->getBounds();
			sprite->setBounds({ 1840.0f, 940.0f, bounds.width * 2.0f, bounds.height * 2.0f });
			this->_scoreB.handle.addComponent<Graphic>(sprite);
		}

		{
			auto & space = this->_playerA.addComponent<SpaceComponent>();
			space.position = { 10.0f, 800.0f };
			space.velocity = { 0.0f, 0.0f };
			space.mass = 70.0f;
			auto sprite = ece::makeResource<ece::Sprite>("playerA", ece::ServiceResourceLocator::getService().getResource<ece::Texture2D>("blue0"));
			sprite->setLevel(1);
			auto bounds = sprite->getBounds();
			sprite->moveTo(space.position);
			this->_playerA.addComponent<Graphic>(sprite);
		}

		{
			auto & space = this->_playerB.addComponent<SpaceComponent>();
			space.position = { 0.0f, 400.0f };
			space.velocity = { 0.0f, 0.0f };
			space.mass = 70.0f;
			auto sprite = ece::makeResource<ece::Sprite>("playerB", ece::ServiceResourceLocator::getService().getResource<ece::Texture2D>("red0"));
			sprite->setLevel(1);
			auto bounds = sprite->getBounds();
			sprite->moveTo(space.position);
			this->_playerB.addComponent<Graphic>(sprite);
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

void Game::apply(KeyBinding key)
{
	auto vertical = ((key & KeyBinding::BLUE_UP) == KeyBinding::BLUE_UP) || ((key & KeyBinding::BLUE_DOWN) == KeyBinding::BLUE_DOWN);
	auto horizontal = ((key & KeyBinding::BLUE_LEFT) == KeyBinding::BLUE_LEFT) || ((key & KeyBinding::BLUE_DOWN) == KeyBinding::BLUE_DOWN);
	auto factor = (vertical && horizontal) ? 1.0f / std::sqrt(2.0f) : 1.0f;

	if ((key & KeyBinding::BLUE_UP) == KeyBinding::BLUE_UP) {
		this->_playerA.getComponent<SpaceComponent>().velocity += ece::FloatVector2u{ 0.0f, 10.0f * factor };
	}
	if ((key & KeyBinding::BLUE_LEFT) == KeyBinding::BLUE_LEFT) {
		this->_playerA.getComponent<SpaceComponent>().velocity += ece::FloatVector2u{ -1.0f * factor, 0.0f };
	}
	if ((key & KeyBinding::BLUE_DOWN) == KeyBinding::BLUE_DOWN) {
		this->_playerA.getComponent<SpaceComponent>().velocity += ece::FloatVector2u{ 0.0f, -10.0f * factor };
	}
	if ((key & KeyBinding::BLUE_RIGHT) == KeyBinding::BLUE_RIGHT) {
		this->_playerA.getComponent<SpaceComponent>().velocity += ece::FloatVector2u{ 1.0f * factor, 0.0f };
	}

	vertical = ((key & KeyBinding::RED_UP) == KeyBinding::RED_UP) || ((key & KeyBinding::RED_DOWN) == KeyBinding::RED_DOWN);
	horizontal = ((key & KeyBinding::RED_LEFT) == KeyBinding::RED_LEFT) || ((key & KeyBinding::RED_DOWN) == KeyBinding::RED_DOWN);
	factor = (vertical && horizontal) ? 1.0f / std::sqrt(2.0f) : 1.0f;
	if ((key & KeyBinding::RED_UP) == KeyBinding::RED_UP) {
		this->_playerB.getComponent<SpaceComponent>().velocity += ece::FloatVector2u{ 0.0f, 10.0f * factor };
	}
	if ((key & KeyBinding::RED_LEFT) == KeyBinding::RED_LEFT) {
		this->_playerB.getComponent<SpaceComponent>().velocity += ece::FloatVector2u{ -1.0f * factor, 0.0f };
	}
	if ((key & KeyBinding::RED_DOWN) == KeyBinding::RED_DOWN) {
		this->_playerB.getComponent<SpaceComponent>().velocity += ece::FloatVector2u{ 0.0f, -10.0f * factor };
	}
	if ((key & KeyBinding::RED_RIGHT) == KeyBinding::RED_RIGHT) {
		this->_playerB.getComponent<SpaceComponent>().velocity += ece::FloatVector2u{ 1.0f * factor, 0.0f };
	}
}
