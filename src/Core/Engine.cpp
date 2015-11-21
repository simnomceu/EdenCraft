#include "Core/Engine.hpp"
#include <iostream>

Engine::Engine(): office(), queueMessages(), running(false), systems()
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

void Engine::run()
{
    this->running = true;
    int i = 0;
    while(this->isRunning()){
        std::cout << i << std::endl;
        if (!this->office.expired()) {
            this->withdrawMessages();
            this->processQueue();
        }
        this->update();
        i++;
    }
}

void Engine::stop()
{
    this->running = true;
// TODO (IsilinBN#1#): Send a message to the application class.
}

bool Engine::isRunning() const
{
    return this->running;
}

void Engine::withdrawMessages()
{
// TODO (IsilinBN#1#): Lock mutex office ICI
    while (this->office.lock()->newMessages(this->getId())) {
        this->receive(this->office.lock()->withdraw(this->getId()));
    }
}

void Engine::processQueue()
{
    while (!this->queueMessages.empty()) {
        this->processMessage(this->queueMessages.front());
        this->queueMessages.pop();
    }
}
