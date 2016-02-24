#pragma once

#include "Communicable.hpp"

namespace core
{
	namespace com
	{
		class Account : public Communicable
		{
		public:
			Account(const std::string& idAccountIn);
			~Account();

			void receiveMessage();
			const std::string& getId() const;

			void processMessages();

		protected:
			virtual void process(std::shared_ptr<AbstractMessage> messageIn) = 0;

		private:
			std::string idAccount;
			std::queue<std::shared_ptr<AbstractMessage>> waitingMessages;
		};
	}
}