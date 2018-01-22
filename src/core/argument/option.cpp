#include "core/argument/option.hpp"

#include <iostream>

namespace ece
{
	bool Option::apply(const std::string & optionName, const std::string & optionValue)
	{
		if (this->_name != optionName.substr(1) || !this->_value->isValid(optionValue)) {
			return false;
		}

		this->_command(optionValue);
		return true;
	}
}