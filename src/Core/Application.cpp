#include "Core/Application.hpp"

#include "Core/GameEngine.hpp"

#include <iostream>

Application::Application(): office(new Office), engines(), threads()
{
    this->engines.push_back(std::shared_ptr<Engine>(new GameEngine()));

    int n = this->engines.size();
    for (int i = 0; i < n; i ++) {
        this->threads.push_back(std::shared_ptr<sf::Thread>(new sf::Thread(&Engine::run, this->engines[i].get())));
    }
}

void Application::start()
{
    for (std::vector<std::shared_ptr<sf::Thread>>::const_iterator it = this->threads.begin(); it != this->threads.end(); ++ it) {
        (*it)->launch();
    }
// TODO (IsilinBN#1#): Traitement de Office dans le thread principal pour éviter les erreurs d'accès concurrents.

    while (1) {
// TODO (IsilinBN#1#): Test de fin de boucle à faire.

    }
}
