#include "Transmitable.hpp"

Transmitable::Transmitable(): recipients(), title(), broadcast(false)
{

}

Transmitable::~Transmitable()
{

}

std::string Transmitable::getRecipient(const int indiceIn) const
{
    return this->recipients[indiceIn];
}

int Transmitable::getNumberOfRecipients() const
{
    return this->recipients.size();
}

std::string Transmitable::getTitle() const
{
    return this->title;
}

bool Transmitable::getBroadcast() const
{
    return this->broadcast;
}


void Transmitable::addRecipient(const std::string& idIn)
{
    this->recipients.push_back(idIn);
}

void Transmitable::setTitle(const std::string& titleIn)
{
    this->title = titleIn;
}
