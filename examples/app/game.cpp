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