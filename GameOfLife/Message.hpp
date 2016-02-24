#pragma once

#include "AbstractMessage.hpp"
#include "Message.inl"

namespace core
{
	namespace com
	{
		class Message : public AbstractMessage
		{
		public:
			Message(const app::def::MessageID messageIn);
			~Message();
		};
	}
}