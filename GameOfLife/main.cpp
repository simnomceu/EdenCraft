#include <iostream>

#include "Game.hpp"

using namespace core;
using namespace app;

// TODO se pencher sur l'utilisation de std::promise, std::future, std::async pour les ressources partagées
// TODO implements factory way with registering needing elements (with using Instanciator <class Base, class Fille>)

int main()
{
	try {
		std::shared_ptr<Application> game(new Game());
		game->initialize();
		game->run();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}