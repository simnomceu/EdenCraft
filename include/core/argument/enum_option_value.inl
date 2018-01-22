#include <algorithm>

namespace ece
{
	inline bool EnumOptionValue::isValid(const std::string & value) { return std::find(this->_values.begin(), this->_values.end(), value) != this->_values.end(); }

	inline void EnumOptionValue::addValue(const std::string & value) { this->_values.push_back(value); }
}