#include "App/Game.hpp"

#include "Core\Window\Window\WindowSetting.hpp"
#include "Core\Window\Window\VideoMode.hpp"

#include <algorithm>

/**
 * @fn	Game::Game()
 *
 * @brief	Default constructor.
 *
 * @author	PIERRE
 * @date	14/08/2016
 */

Game::Game() : Application()
{
	this->addWindow(ece::WindowSetting());
	this->addWindow(ece::WindowSetting());
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
* @fn	void Game::render()
*
* @brief	Renders this object.
*
* @author	PIERRE
* @date	14/08/2016
*/

void Game::render()
{
	for (auto it = this->windows.begin(); it != this->windows.end(); ++it) {
//		it->get()->display();
	}
}

void Game::update()
{
	this->windows.erase(std::remove_if(this->windows.begin(), this->windows.end(), 
										[](std::unique_ptr<ece::BaseWindow> const & x) -> bool { return x.get()->shouldClosed(); }), this->windows.end());
}

void Game::processEvents()
{
	ece::Event event;
	for (auto it = this->windows.begin(); it != this->windows.end(); ++it) {
		while (it->get()->pollEvent(event)) {

		}
	}
}

