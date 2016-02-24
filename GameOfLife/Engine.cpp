#include "Engine.hpp"

#include <ctime>

using namespace core::eng;
using namespace core::cmn;

Engine::Engine(const bool activeIn, const int fpsIn, const std::string& idAccountIn):
	Account(idAccountIn), Limiter(fpsIn), systems(), active(activeIn)
{
}


Engine::~Engine()
{
}

void Engine::run()
{
	while (this->active) {
		this->begin();

		this->processMessages();
		this->update();
		this->render();

		this->wait();
	}
}
