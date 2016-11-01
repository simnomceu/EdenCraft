#include "Core\Util\UniqueID.hpp"

namespace ece
{
	UniqueID::UniqueID(): std::stack<unsigned int>()
	{
		this->push(0);
	}

	UniqueID::UniqueID(const unsigned int start) : std::stack<unsigned int>()
	{
		this->push(start);
	}

	unsigned int UniqueID::next()
	{
		int id = this->top();
		this->pop();
		if (this->empty()) {
			this->push(id + 1);
		}
		return id;
	}

	void UniqueID::restack(const unsigned int value)
	{
		this->push(value);
	}
}
