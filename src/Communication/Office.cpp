#include "Office.hpp"
#include <iostream>

Office::Office() : accounts(), waitingMessages()
{
}

void Office::post(std::shared_ptr<ITransmitable> newMessageIn)
{
// TODO (IsilinBN#1#): Check integrity of the message.
    if (newMessageIn != nullptr) {
        this->waitingMessages.push(newMessageIn);
    }
}

void Office::registerAccount(std::pair<std::string, std::weak_ptr<ICommunicable>> newAccount)
{
    if (this->accounts.count(newAccount.first) == 0) {
        this->accounts.insert(newAccount);
    } else {
        throw std::string("This account already exists in this office.\n");
    }
}

void Office::distribute()
{
    int nbRecipients = 0;
    std::string recipientName = "";
    while (!this->waitingMessages.empty()) {
        nbRecipients = this->waitingMessages.front()->getNumberOfRecipients() ;
        for(int i = 0; i < nbRecipients ; i++) {
            recipientName = this->waitingMessages.front()->getRecipient(i);
            if (this->accounts.count(recipientName) > 0 || this->waitingMessages.front()->getBroadcast()) {
                if (auto spt = this->accounts[recipientName].lock()) {
                    spt->receive(this->waitingMessages.front());
                } else {
                    throw std::string("This account doesn't exist yet.\n");
                }
            }
        }
        this->waitingMessages.pop();
    }
}
