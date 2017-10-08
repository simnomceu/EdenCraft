#include <algorithm>

namespace ece
{
	inline bool EnumOptionValue::isValid(const std::string & value) { return std::find(this->values.begin(), this->values.end(), value) != this->values.end(); }

	inline void EnumOptionValue::addValue(const std::string & value) { this->values.push_back(value); }
}