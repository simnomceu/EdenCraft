#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>

#include "Office.hpp"
#include "Engine.hpp"
#include "Message.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    try {
        std::shared_ptr<Office> office(new Office) ;

        std::shared_ptr<Engine> engine1(new Engine);
        office->registerAccount(std::pair<std::string, std::weak_ptr<ICommunicable>>("engine1", engine1));
        engine1->attachOffice(office);

        std::shared_ptr<Engine> engine2(new Engine);
        office->registerAccount(std::pair<std::string, std::weak_ptr<ICommunicable>>("engine2", engine2));
        engine2->attachOffice(office);

        std::shared_ptr<Message> message(new Message("Coucou"));
        message->addRecipient("engine2");
        engine1->send(message);

        office->distribute();
    } catch(const std::string& e) {
        std::cerr << e << std::endl;
    }

    return 0;
}
