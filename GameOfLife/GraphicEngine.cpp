#include "GraphicEngine.hpp"

#include <iostream>
#include <windows.h>

using namespace sf;
using namespace app::eng;
using namespace core::eng;
using namespace app::def;
using namespace core::com;

GraphicEngine::GraphicEngine(const bool activeIn, const int fpsIn): Engine(activeIn, fpsIn, "graphic"), RenderUser(), screenBuffer(new std::string())
{
}


GraphicEngine::~GraphicEngine()
{
}

void app::eng::GraphicEngine::initialize()
{
	system("mode con lines=40 cols=50");
}

void app::eng::GraphicEngine::process(std::shared_ptr<AbstractMessage> messageIn)
{
	if (messageIn->getMessage() == _CHANGE_RENDER_) {

	}
}

void app::eng::GraphicEngine::update()
{
}

void app::eng::GraphicEngine::render()
{
	// system("cls");

	this->lockRender();
	this->getRender()->clear(sf::Color(0, 0, 0));
	// TODO draw
	this->unlockRender();

	// draw;
}