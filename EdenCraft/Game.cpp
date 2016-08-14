#include "Game.hpp"

#include <iostream>

#include "SFML\Window\Event.hpp"
#include "TriangleObject.hpp"
#include "Strings.inl"
#include "SFML\Graphics\Shader.hpp"


#pragma warning(push)
#pragma warning(disable : 4505)
#include "GL\glew.h"
#include "GL\freeglut.h"
#pragma warning(pop)

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
	std::cerr << "Renderer used: " << glGetString(GL_RENDERER) << std::endl;
	std::cerr << glGetString(GL_VERSION) << " used in an SFML context." << std::endl;

	if (sf::Shader::isAvailable()) {
		std::cerr << "The shaders are available ..." << std::endl;
	}
	else {
		std::cerr << "The shaders are not available ... You need a more recent graphic card to use this program." << std::endl;
	}

	// Init Glew.
	// Required to use VAO & VBO.
	glewExperimental = GL_TRUE;
	glewInit();

	/* tell GL to only draw onto a pixel if the shape is closer to the viewer
	*/
	glEnable(GL_DEPTH_TEST); /* enable depth-testing */
							 /* with LESS depth-testing interprets a smaller value as "closer" */
	glDepthFunc(GL_LESS);

	this->elements.push_back(new TriangleObject());
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
		if (event.type == sf::Event::Closed
			|| (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) ) {
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
	//window.clear();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

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

	sf::Clock clock;
	sf::Time elapsedTime = sf::Time::Zero;

	int FPS = 0;

	while (this->isRunningGame()) {
		this->update();
		this->render();

		elapsedTime += clock.restart();
		FPS++;
		if (elapsedTime.asMicroseconds() > 1000000) {
			this->window.setTitle(Strings::APP_TITLE + " " + std::to_string(FPS) + "FPS");

			FPS = 0;
			elapsedTime = sf::Time::Zero;
		}
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
