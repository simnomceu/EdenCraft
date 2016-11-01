#include "Core\Util\UniqueID.hpp"

namespace ece
{
	UniqueID::UniqueID(): std::deque<unsigned int>()
	{
		this->push_back(0);
	}

	UniqueID::UniqueID(const unsigned int start) : std::deque<unsigned int>()
	{
		this->push_back(start);
	}

	unsigned int UniqueID::next()
	{
		int id = this->back();
		this->pop_back();
		if (this->empty()) {
			this->push_back(id + 1);
		}
		return id;
	}

	void UniqueID::restack(const unsigned int value)
	{
		if (value < this->front() && std::find(this->begin(), this->end(), value) == this->end()) {
			this->push_back(value);
		}
	}
}
