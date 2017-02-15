/**
 * @file	Game.hpp
 *
 * @brief	Declares the game class.
 */

#pragma once

#include <memory>
#include <vector>
#include "Core\System\Application\Application.hpp"
#include "Core\System\Event\Listener.hpp"

/**
 * @class	Game
 *
 * @brief	A game.
 *
 * @author	PIERRE
 * @date	14/08/2016
 */

class Game: public ece::Application
{
public:
	Game();
	~Game();

private:
	virtual void render();
	virtual void update();
	virtual void processEvents();
};

