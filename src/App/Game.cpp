#include "App/Game.hpp"

#include <iostream>

#include "Core\Window\WindowSetting.hpp"

std::shared_ptr<Game> Game::instance = nullptr;

/**
 * @fn	Game::Game()
 *
 * @brief	Default constructor.
 *
 * @author	PIERRE
 * @date	14/08/2016
 */

Game::Game() : 
	window(ece::WindowSetting()),
	windowBis(ece::WindowSetting()),
	isRunning(false)
{
}

/**
 * @fn	void Game::initialize()
 *
 * @brief	Initializes this object.
 *
 * @author	PIERRE
 * @date	14/08/2016
 */

void Game::initialize()
{
	this->start();
	this->window.open();
	this->windowBis.open();

//	this->elements.push_back(new RectangleObject());
}

/**
 * @fn	void Game::update()
 *
 * @brief	Updates this object.
 *
 * @author	PIERRE
 * @date	14/08/2016
 */

void Game::update()
{
	if (!this->window.isOpened()) {
		this->stop();
	}

	glfwPollEvents();
	// TODO add event management
	/*sf::Event event;
	while (this->window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed
			|| (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) ) {
			this->window.close();
			this->stop();
		}
	}*/
}

/**
 * @fn	void Game::render()
 *
 * @brief	Renders this object.
 *
 * @author	PIERRE
 * @date	14/08/2016
 */

void Game::render()
{
	window.display();
}

/**
 * @fn	void Game::close()
 *
 * @brief	Closes this object.
 *
 * @author	PIERRE
 * @date	14/08/2016
 */

void Game::close()
{
	if (this->isRunning) {
		this->stop();
	}
	this->window.close();
}

/**
 * @fn	std::weak_ptr<Game> Game::getInstance()
 *
 * @brief	Gets the instance.
 *
 * @author	PIERRE
 * @date	14/08/2016
 *
 * @return	The instance.
 */

std::weak_ptr<Game> Game::getInstance()
{
	if (Game::instance == nullptr) {
		Game::instance.reset(new Game());
	}
	return Game::instance;
}

/**
 * @fn	Game::~Game()
 *
 * @brief	Destructor.
 *
 * @author	PIERRE
 * @date	14/08/2016
 */

Game::~Game()
{
}

/**
 * @fn	void Game::run()
 *
 * @brief	Runs this object.
 *
 * @author	PIERRE
 * @date	14/08/2016
 */

void Game::run()
{
	this->initialize();

	/*sf::Clock clock;
	sf::Time elapsedTime = sf::Time::Zero;

	int FPS = 0;


	if (sf::Shader::isAvailable()) {
		std::cerr << Strings::SHADERS_AVAILABLE << std::endl;
	}
	else {
		std::cerr << Strings::SHADERS_NOT_AVAILABLE << std::endl;
	}*/

	while (this->isRunningGame()) {
		this->update();
		this->render();

		/*elapsedTime += clock.restart();
		FPS++;
		if (elapsedTime.asMicroseconds() > 1000000) {
			this->window.setTitle(Strings::APP_TITLE + " " + std::to_string(FPS) + "FPS");

			FPS = 0;
			elapsedTime = sf::Time::Zero;
		}*/
	}

	this->close();
}

/**
 * @fn	void Game::start()
 *
 * @brief	Starts this object.
 *
 * @author	PIERRE
 * @date	14/08/2016
 */

void Game::start()
{
	this->isRunning = true;
}

/**
 * @fn	void Game::stop()
 *
 * @brief	Stops this object.
 *
 * @author	PIERRE
 * @date	14/08/2016
 */

void Game::stop()
{
	this->isRunning = false;
}

/**
 * @fn	bool Game::isRunningGame()
 *
 * @brief	Query if this object is running game.
 *
 * @author	PIERRE
 * @date	14/08/2016
 *
 * @return	true if running game, false if not.
 */

bool Game::isRunningGame()
{
	return this->isRunning;
}

