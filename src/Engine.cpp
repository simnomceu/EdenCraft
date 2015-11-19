#include "Engine.hpp"
#include <iostream>

Engine::Engine(): office(), queueMessages()
{

}

void Engine::receive(std::shared_ptr<ITransmitable> newMessageIn)
{
    this->queueMessages.push(newMessageIn);
}

void Engine::send(std::shared_ptr<ITransmitable> newMessageIn) const
{
    if (auto spt = this->office.lock()) {
        spt->post(newMessageIn);
    } else {
        throw std::string("You don't registered an office to send messages.\n");
    }
}

void Engine::attachOffice(std::weak_ptr<ICentralizer> officeIn)
{
    this->office = officeIn;
}

