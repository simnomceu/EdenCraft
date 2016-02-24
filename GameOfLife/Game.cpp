#include "Game.hpp"

#include <utility>

#include "GraphicEngine.hpp"
#include "LogicEngine.hpp"
#include "SharedElement.hpp"

using namespace app;
using namespace app::def;
using namespace app::eng;
using namespace core;
using namespace core::com;
using namespace core::cmn;
using namespace core::eng;
using namespace core::cmp;

Game::Game(): Application()
{
}

Game::~Game()
{
}

void Game::loadEngineType()
{
	this->registerEngine<GraphicEngine>("graphic");
	this->registerEngine<LogicEngine>("logic");
}

void Game::loadSystemType()
{

}

void Game::loadComponentType()
{
	this->elements["cm"]->lock();
	auto cm = std::static_pointer_cast<SharedElement<ComponentManager>>(this->elements["cm"])->get();
	cm->registerType<int>("health"); // register component's type "health" with data type int.
	cm->addComponent<int>(0, "health", 20);
	cm->removeComponent(0, "health");
	this->elements["cm"]->unlock();
}

void Game::loadEngines()
{
	this->addEngine<GraphicEngine>(true, 1, "graphic");
	this->addEngine<LogicEngine>(true, 1, "logic");
}
