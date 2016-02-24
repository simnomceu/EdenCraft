#include "Office.hpp"

#include <string>
#include <iostream>

using namespace core::com;

Office::Office(): mailbox()
{
}


Office::~Office()
{
}

void Office::registerAccount(const std::string& accountIn)
{
	if (this->mailbox.find(accountIn) != this->mailbox.end()) {
		std::string tmp = "This office account (" + accountIn + ") already exists.";
		throw std::exception(tmp.c_str());
	}
	else {
		this->mailbox.insert(std::pair<std::string, std::queue<std::shared_ptr<AbstractMessage>>>(accountIn, std::queue < std::shared_ptr<AbstractMessage>>()));
	}
}

void Office::distributeMessage(std::shared_ptr<AbstractMessage> messageIn, const std::string& recipientIn)
{
	this->mailbox[recipientIn].push(messageIn);
}

void Office::broadcastMessage(std::shared_ptr<AbstractMessage> messageIn)
{
	for (auto it : this->mailbox) {
		this->distributeMessage(messageIn, it.first);
	}
}

bool Office::isNewMessages(const std::string& accountIn)
{
	return !this->mailbox[accountIn].empty();
}

std::shared_ptr<AbstractMessage> Office::withdrawMessage(const std::string& accountIn)
{
	std::shared_ptr<AbstractMessage> message(this->mailbox[accountIn].front());
	this->mailbox[accountIn].pop();
	return message;
}
