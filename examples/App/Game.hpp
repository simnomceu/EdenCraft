/**
 * @file	Game.hpp
 *
 * @brief	Declares the game class.
 */

#pragma once

#include <memory>
#include <vector>
#include "System\Application\Application.hpp"
#include "System\Event\Listener.hpp"

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

	void addWindow(const WindowSetting & setting);
	template<class T> T & addWindow();

private:
	virtual void onInit();
	virtual void render();
	virtual void update();
	virtual void processEvents();

	std::vector<std::shared_ptr<BaseWindow>> windows;
};



template<class T>
T & Game::addWindow()
{
	auto windowPtr = std::make_shared<T>(ece::WindowSetting());
	this->windows.push_back(windowPtr);
	return *windowPtr.get();
}
