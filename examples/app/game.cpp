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

#include "game.hpp"

#include "window/window/window_setting.hpp"
#include "window/window_refactor/video_mode.hpp"
#include "renderer/common_renderer/render_window.hpp"
#include "graphic/model/object.hpp"

#include <algorithm>
#include <memory>

/**
 * @fn	Game::Game()
 *
 * @brief	Default constructor.
 *
 * @author	PIERRE
 * @date	14/08/2016
 */

Game::Game() : Application(), Listener(), windows()
{
	this->addSlot(CREATE_WINDOWS, std::bind(&Game::createWindows, this, std::placeholders::_1, std::placeholders::_2));
	this->addSlot(CREATE_SCENE, std::bind(&Game::createScene, this, std::placeholders::_1, std::placeholders::_2));
	this->addSlot(ANALYSE_EVENTS, std::bind(&Game::analyseEvents, this, std::placeholders::_1, std::placeholders::_2));
	this->addSlot(CLEAN_WINDOWS, std::bind(&Game::cleanWindows, this, std::placeholders::_1, std::placeholders::_2));
	this->addSlot(REFRESH_DISPLAY, std::bind(&Game::refreshDisplay, this, std::placeholders::_1, std::placeholders::_2));

	this->onPreInit(*this, CREATE_WINDOWS);
	this->onPostInit(*this, CREATE_SCENE);
	this->onPreUpdate(*this, ANALYSE_EVENTS);
	this->onPostUpdate(*this, CLEAN_WINDOWS);
	this->onPostRender(*this, REFRESH_DISPLAY);
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
		//it->get()->close();
	}
	this->windows.clear();
}

void Game::addWindow(const ece::WindowSetting & setting)
{
	//this->windows.push_back(std::make_unique<ece::Window>(setting));
	std::cout << "window created" << std::endl;
}

void Game::createWindows(const ece::Emitter & emitter, const unsigned int signal)
{
	//auto & firstWindow = this->addWindow<ece::BaseWindow>();
	//auto & secondWindow = this->addWindow<ece::RenderWindow>();
}

void Game::createScene(const ece::Emitter & emitter, const unsigned int signal)
{
	for (auto it = this->windows.begin(); it != this->windows.end(); ++it) {
		//it->get()->open(ece::VideoMode());
	}

	//auto & scene = std::static_pointer_cast<ece::RenderWindow>(this->windows[0])->getScene();
	//auto object = scene.addObject();

	auto mesh = std::make_shared<ece::Mesh>();
	mesh->loadFromFile("../resource/shader/cube.dat");
	//object->setMesh(mesh);

	auto shaderEffect = std::make_shared<ece::ShaderEffect>();
	auto vs = shaderEffect->addShader();
	vs->loadFromFile(ece::ShaderType::VERTEX_SHADER, "../resource/shader/basic.vert");
	auto fs = shaderEffect->addShader();
	fs->loadFromFile(ece::ShaderType::FRAGMENT_SHADER, "../resource/shader/basic.frag");
	//object->setShaderEffect(shaderEffect);
}

void Game::analyseEvents(const ece::Emitter & emitter, const unsigned int signal)
{
	ece::InputEvent event;
	for (auto it = this->windows.begin(); it != this->windows.end(); ++it) {
		//while (it->get()->pollEvent(event)) {

		//}
	}
}

void Game::cleanWindows(const ece::Emitter & emitter, const unsigned int signal)
{
	//this->windows.erase(std::remove_if(this->windows.begin(), this->windows.end(),
	//	[](std::shared_ptr<ece::BaseWindow> const & x) -> bool { return x->shouldClosed(); }), this->windows.end());
}

void Game::refreshDisplay(const ece::Emitter & emitter, const unsigned int signal)
{
	for (auto it = this->windows.begin(); it != this->windows.end(); ++it) {
		//it->get()->onRefresh();
		//it->get()->display();
	}
}