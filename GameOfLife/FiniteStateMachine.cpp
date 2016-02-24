#include "FiniteStateMachine.hpp"

#include "HeavyMessage.hpp"

#include "Message.inl"

using namespace core::st;
using namespace core::com;
using namespace app::def;

FiniteStateMachine::FiniteStateMachine(): Account("fsm"), currentState("play")
{
}


FiniteStateMachine::~FiniteStateMachine()
{
}

const std::string& FiniteStateMachine::getCurrentState() const
{
	return this->currentState;
}

void FiniteStateMachine::process(std::shared_ptr<AbstractMessage> messageIn)
{
	if (messageIn->getMessage() == _CHANGE_STATE_) {
		try {
			auto tmpMessage = std::dynamic_pointer_cast<HeavyMessage<std::string>>(messageIn);
			if (this->currentState == "play") {
				this->transitionFromPlay(tmpMessage->getParameter());
			}
			else if (this->currentState == "stop") {
				this->transitionFromPlay(tmpMessage->getParameter());
			}
		}
		catch (const std::exception& e) {
		}
	}
}

void FiniteStateMachine::transitionFromPlay(const std::string& transitionIn)
{
	if (transitionIn == "stop") {
		this->currentState = "stop";
	}
}

void FiniteStateMachine::transitionFromStop(const std::string& transitionIn)
{
}
