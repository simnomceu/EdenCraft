/**
 * @file	Game.hpp
 *
 * @brief	Declares the game class.
 */

#pragma once

#include <memory>
#include <vector>

#include "SFML\System\NonCopyable.hpp"
#include "SFML\Graphics\Shape.hpp"

#include "CustomWindow.hpp"

/**
 * @class	Game
 *
 * @brief	A game.
 *
 * @author	PIERRE
 * @date	14/08/2016
 */

class Game : public sf::NonCopyable
{
public:
	static std::weak_ptr<Game> getInstance();

	~Game();

	void run();

	void start();
	void stop();
	bool isRunningGame();

private:
	static std::shared_ptr<Game> instance;

	CustomWindow window;
	bool isRunning;
	std::vector<sf::Shape*> elements;

	Game();

	void initialize();
	void update();
	void render();
	void close();
};

