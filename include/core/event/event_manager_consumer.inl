namespace ece
{
	inline EventManagerConsumer::EventManagerConsumer() : _eventManager(EventServiceLocator::getServicePtr(*this)) {}
}