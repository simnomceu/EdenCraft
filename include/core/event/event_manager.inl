namespace ece
{
	inline EventManager::EventManager() : BaseEventManager(), signals(), slots(), signalsAvailable(), slotsAvailable()
	{
	}

	inline const Slot::GlobalSlotID EventManager::getSlotID()
	{
		auto id = this->slotsAvailable.next();
		return id;
	}

	inline const Signal::GlobalSignalID EventManager::getSignalID()
	{
		auto id = this->signalsAvailable.next();
		return id;
	}
}