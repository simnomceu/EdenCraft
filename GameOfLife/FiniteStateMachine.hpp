#pragma once

#include "Account.hpp"
#include "Message.hpp"

namespace core
{
	namespace st
	{
		class FiniteStateMachine : public core::com::Account
		{
		public:
			FiniteStateMachine();
			~FiniteStateMachine();

			const std::string& getCurrentState() const;
		protected:
			virtual void process(std::shared_ptr<core::com::AbstractMessage> messageIn);

		private:
			std::string currentState;

			void transitionFromPlay(const std::string& transitionIn);
			void transitionFromStop(const std::string& transitionIn);
		};
	}
}