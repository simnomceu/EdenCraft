/**
 * @file	Game.hpp
 *
 * @brief	Declares the game class.
 */

#pragma once

#include <memory>
#include <vector>
#include "core/application/application.hpp"
#include "core/event/listener.hpp"
#include "window/window_refactor/window.hpp"
#include "core/event/listener.hpp"

/**
 * @class	Game
 *
 * @brief	A game.
 *
 * @author	PIERRE
 * @date	14/08/2016
 */

class Game: public ece::Application, public ece::Listener
{
public:
	const ece::Slot::SlotID CREATE_WINDOWS = 0;
	const ece::Slot::SlotID CREATE_SCENE = 1;
	const ece::Slot::SlotID ANALYSE_EVENTS = 2;
	const ece::Slot::SlotID CLEAN_WINDOWS = 3;
	const ece::Slot::SlotID REFRESH_DISPLAY = 4;

	Game();
	~Game();

	void addWindow(const ece::WindowSetting & setting);
	template<class T> T & addWindow();

private:
	void createWindows(const ece::Emitter & emitter, const unsigned int signal);
	void createScene(const ece::Emitter & emitter, const unsigned int signal);
	void analyseEvents(const ece::Emitter & emitter, const unsigned int signal);
	void cleanWindows(const ece::Emitter & emitter, const unsigned int signal);
	void refreshDisplay(const ece::Emitter & emitter, const unsigned int signal);

	std::vector<std::shared_ptr<ece::Window>> windows;
};



template<class T>
T & Game::addWindow()
{
	auto windowPtr = std::make_shared<T>(ece::WindowSetting());
	this->windows.push_back(windowPtr);
	return *windowPtr.get();
}
