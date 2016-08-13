#include "Game.hpp"

#include "SFML\Window\Event.hpp"
#include "SFML\Graphics\CircleShape.hpp"

std::shared_ptr<Game> Game::instance = nullptr;

/**
 * @fn	Game::Game()
 *
 * @brief	Default constructor.
 *
 * @author	PIERRE
 * @date	14/08/2016
 */

Game::Game(): NonCopyable(), window(), isRunning(false), elements()
{
	this->elements.push_back(new sf::CircleShape(100.f));
	this->elements[0]->setFillColor(sf::Color::Green);
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
	this->window.initialize();
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
	sf::Event event;
	while (this->window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed) {
			this->window.close();
			this->stop();
		}
	}
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
	window.clear();

	for (auto it = this->elements.begin(); it != this->elements.end(); ++it)
	{
		this->window.draw(**it);
	}
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
	this->elements.clear();
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

	while (this->isRunningGame()) {
		this->update();
		this->render();
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
