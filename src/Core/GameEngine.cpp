#include "Core/GameEngine.hpp"

GameEngine::GameEngine(): Engine()
{

}

std::string GameEngine::getId() const
{
    return "game";
}

void GameEngine::processMessage(std::shared_ptr<ITransmitable> messageIn)
{
}

void GameEngine::update()
{
}
