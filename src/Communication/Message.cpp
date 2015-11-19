#include "Message.hpp"

Message::Message(const std::string& titleIn): Transmitable(), intData(), stringData()
{
    this->title = titleIn;
}

std::string Message::getType() const
{
    return "message";
}

void Message::addIntData(const std::pair<std::string, int>& newDataIn)
{
    this->intData.insert(newDataIn);
}

void Message::addStringData(const std::pair<std::string, std::string>& newDataIn)
{
    this->stringData.insert(newDataIn);
}

int Message::getIntData(const std::string& keyIn)
{
    return this->intData[keyIn];
}

std::string Message::getStringData(const std::string& keyIn)
{
    return this->stringData[keyIn];
}
