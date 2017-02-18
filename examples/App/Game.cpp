#include "App/Game.hpp"

#include "Core\Window\Window\WindowSetting.hpp"
#include "Core\Window\Window\VideoMode.hpp"
#include "Core\Graphic\Rendering\RenderWindow.hpp"
#include "Core\Graphic\Rendering\Scene.hpp"

#include <algorithm>
#include "Game.hpp"

/**
 * @fn	Game::Game()
 *
 * @brief	Default constructor.
 *
 * @author	PIERRE
 * @date	14/08/2016
 */

Game::Game() : Application(), windows()
{
	auto & firstWindow = this->addWindow<ece::BaseWindow>();
	auto & secondWindow = this->addWindow<ece::RenderWindow>();

	auto scene = std::make_shared<ece::Scene>();
	secondWindow.attachScene(scene);
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
	for (auto it = this->windows.begin(); it != this->windows.end(); ++it) {
		it->get()->close();
	}
	this->windows.clear();
}

void Game::addWindow(const WindowSetting & setting)
{
	this->windows.push_back(std::make_unique<BaseWindow>(setting));
}

void Game::onInit()
{
	for (auto it = this->windows.begin(); it != this->windows.end(); ++it) {
		it->get()->open(VideoMode());
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
	for (auto it = this->windows.begin(); it != this->windows.end(); ++it) {
		it->get()->onRefresh();
		it->get()->display();
	}
}

void Game::update()
{
	this->windows.erase(std::remove_if(this->windows.begin(), this->windows.end(), 
										[](std::shared_ptr<ece::BaseWindow> const & x) -> bool { return x->shouldClosed(); }), this->windows.end());
}

void Game::processEvents()
{
	ece::Event event;
	for (auto it = this->windows.begin(); it != this->windows.end(); ++it) {
		while (it->get()->pollEvent(event)) {

		}
	}
}

