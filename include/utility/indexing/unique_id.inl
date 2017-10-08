namespace ece
{
	inline UniqueID::UniqueID() : std::deque<unsigned int>()
	{
		this->push_back(0);
	}

	inline UniqueID::UniqueID(const unsigned int start) : std::deque<unsigned int>()
	{
		this->push_back(start);
	}
}