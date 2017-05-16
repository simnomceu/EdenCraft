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
#include "Window\BaseWindow.hpp"

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

	void addWindow(const ece::WindowSetting & setting);
	template<class T> T & addWindow();

private:
	virtual void onPreInit() override;
	virtual void onPostInit() override;
	virtual void onPreProcess() override;
	virtual void onPreUpdate() override;
	virtual void onPostUpdate() override;
	virtual void onPostRender() override;
	virtual void onPreTerminate() override;
	virtual void onPostTerminate() override;

	std::vector<std::shared_ptr<ece::BaseWindow>> windows;
};



template<class T>
T & Game::addWindow()
{
	auto windowPtr = std::make_shared<T>(ece::WindowSetting());
	this->windows.push_back(windowPtr);
	return *windowPtr.get();
}
