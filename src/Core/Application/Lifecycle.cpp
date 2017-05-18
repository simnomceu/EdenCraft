#include "Application\Lifecycle.hpp"

namespace ece
{
	Lifecycle::Lifecycle() : Emitter()
	{
		this->addSignal(PRE_INIT);
		this->addSignal(POST_INIT);
		this->addSignal(PRE_PROCESS);
		this->addSignal(PRE_UPDATE);
		this->addSignal(POST_UPDATE);
		this->addSignal(POST_RENDER);
		this->addSignal(PRE_TERMINATE);
		this->addSignal(POST_TERMINATE);
	}
}