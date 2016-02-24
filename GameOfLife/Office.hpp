#pragma once

#include <map>
#include <queue>
#include <memory>

#include "AbstractMessage.hpp"

namespace core
{
	namespace com
	{
		class Office
		{
		public:
			Office();
			~Office();

			void registerAccount(const std::string& accountIn);
			void distributeMessage(std::shared_ptr<AbstractMessage> messageIn, const std::string& recipientIn);
			void broadcastMessage(std::shared_ptr<AbstractMessage> messageIn);
			bool isNewMessages(const std::string& accountIn);
			std::shared_ptr<AbstractMessage> withdrawMessage(const std::string& accountIn);

		private:
			std::map<std::string, std::queue<std::shared_ptr<AbstractMessage>>> mailbox;
		};
	}
}
