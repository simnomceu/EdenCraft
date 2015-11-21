#ifndef APPLICATION_HPP_INCLUDED
#define APPLICATION_HPP_INCLUDED

#include <memory>
#include <vector>
#include <SFML/System.hpp>

#include "Office.hpp"
#include "Engine.hpp"

#include "SFML/System.hpp"
class Application
{
    public:
        Application();

        void start();
    private:
// TODO (IsilinBN#1#): Poser un mutex sur la ressource Office.
        std::shared_ptr<Office> office;
        std::vector<std::shared_ptr<Engine>> engines;
        std::vector<std::shared_ptr<sf::Thread>> threads;
};

#endif // APPLICATION_HPP_INCLUDED
