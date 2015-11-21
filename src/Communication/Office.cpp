#include "Office.hpp"
#include <iostream>

Office::Office() : accounts(), waitingMessages()
{
}

void Office::post(std::shared_ptr<ITransmitable> newMessageIn)
{
// TODO (IsilinBN#1#): Check integrity of the message.
    if (newMessageIn != nullptr) {
        int nbRecipients = newMessageIn->getNumberOfRecipients();
        for (int i = 0; i < nbRecipients; i ++) {
            this->accounts[newMessageIn->getRecipient(i)].push(newMessageIn);
        }
// TODO (IsilinBN#1#): Gérer les messages broadcast

    }
}

void Office::registerAccount(const std::string& newAccount)
{
    if (this->accounts.count(newAccount) == 0) {
        this->accounts.insert(std::pair<std::string, std::queue<std::shared_ptr<ITransmitable>>>(newAccount, std::queue<std::shared_ptr<ITransmitable>>()));
    } else {
        throw std::string("This account already exists in this office.\n");
    }
}

bool Office::newMessages(const std::string& accountIn)
{
    return !this->accounts[accountIn].empty() ;
}

std::shared_ptr<ITransmitable> Office::withdraw(const std::string& accountIn)
{
    if (this->newMessages(accountIn)) {
        std::shared_ptr<ITransmitable> message = this->accounts[accountIn].front();
        this->accounts[accountIn].pop();
// TODO (IsilinBN#1#): Vérifier que le message n'est pas supprimé avant d'être transmis.
        return message;
    } else {
        throw std::string("Withdraw but there is no message on this account !");
    }
}
