/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .   
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8   
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo 
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888   
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888   
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 . 
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888" 

																  .o.                             
																 .888.                            
																.8"888.     oo.ooooo.  oo.ooooo.  
															   .8' `888.     888' `88b  888' `88b 
															  .88ooo8888.    888   888  888   888 
															 .8'     `888.   888   888  888   888 
															o88o     o8888o  888bod8P'  888bod8P' 
																			 888        888       
																			o888o      o888o     

				This file is part of EdenCraft Engine - App sample.
				Copyright(C) 2018 Pierre Casati (@IsilinBN)

				This program is free software : you can redistribute it and/or modify
				it under the terms of the GNU General Public License as published by
				the Free Software Foundation, either version 3 of the License, or
				(at your option) any later version.

				This program is distributed in the hope that it will be useful,
				but WITHOUT ANY WARRANTY; without even the implied warranty of
				MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
				GNU General Public License for more details.

				You should have received a copy of the GNU General Public License
				along with this program.If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef GAME_HPP
#define GAME_HPP

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

#endif // GAME_HPP