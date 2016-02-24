#include "AbstractMessage.hpp"

using namespace core::com;
using namespace app::def;

AbstractMessage::AbstractMessage(const MessageID messageIn) : message(messageIn)
{
}


AbstractMessage::~AbstractMessage()
{
}

const MessageID AbstractMessage::getMessage() const
{
	return this->message;
}
