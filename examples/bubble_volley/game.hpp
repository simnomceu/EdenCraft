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

#ifndef GAME_HPP
#define GAME_HPP

#include "core/signal.hpp"
#include "graphic/renderable.hpp"
#include "graphic/scene.hpp"

/**
 * @class Game
 * @brief
 */
class Game
{
public:
	enum State
	{
		NONE,
		SPLASHSCREEN,
		PLAY
	};

	/**
	 * @fn constexpr Game() noexcept
	 * @brief Default constructor.
	 * @throw noexcept
	 */
	Game(ece::World & world) noexcept;

	/**
	 * @fn Game(const Game & copy) noexcept
	 * @param[in] copy The Game to copy from.
	 * @brief Default copy constructor.
	 * @throw noexcept
	 */
	Game(const Game & copy) noexcept = default;

	/**
	 * @fn Game(Game && move) noexcept
	 * @param[in] move The Game to move.
	 * @brief Default move constructor.
	 * @throw noexcept
	 */
	Game(Game && move) noexcept = default;

	/**
	 * @fn ~Game() noexcept
	 * @brief Default destructor.
	 * @throw noexcept
	 */
	~Game() noexcept = default;

	/**
	 * @fn Game & operator=(const Game & copy) noexcept
	 * @param[in] copy The Game to copy from.
	 * @return The Game copied.
	 * @brief Default copy assignment operator.
	 * @throw noexcept
	 */
	Game & operator=(const Game & copy) noexcept = default;

	/**
	 * @fn Game & operator=(Game && move) noexcept
	 * @param[in] move The Game to move.
	 * @return The Game moved.
	 * @brief Default move assignment operator.
	 * @throw noexcept
	 */
	Game & operator=(Game && move) noexcept = default;

	void setState(const Game::State state);

//	void draw();

	ece::Signal<> onSplashScreenEntered;
	ece::Signal<> onPlayEntered;

private:
	struct Score
	{
		ece::EntityHandler handle;
		int value;
	};

	Game::State _current;
	
//	ece::Scene _scene;

//	ece::ResourceHandler<ece::Sprite> _background;
	ece::EntityHandler _background;

	Score _scoreA;
	Score _scoreB;

	ece::EntityHandler _playerA;
	ece::EntityHandler _playerB;
};

#endif // GAME_HPP