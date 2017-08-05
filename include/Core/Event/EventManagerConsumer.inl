

namespace ece
{
	inline EventManagerConsumer::EventManagerConsumer() : eventManager(EventServiceLocator::getServicePtr(*this)) {}
}