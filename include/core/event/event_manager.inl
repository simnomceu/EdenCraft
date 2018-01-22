namespace ece
{
	inline EventManager::EventManager() : BaseEventManager(), _signals(), _slots(), _signalsAvailable(), _slotsAvailable()
	{
	}

	inline const Slot::GlobalSlotID EventManager::getSlotID()
	{
		auto id = this->_slotsAvailable.next();
		return id;
	}

	inline const Signal::GlobalSignalID EventManager::getSignalID()
	{
		auto id = this->_signalsAvailable.next();
		return id;
	}
}