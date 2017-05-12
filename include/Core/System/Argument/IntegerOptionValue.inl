#include <algorithm>
#include <cctype>

namespace ece
{
	inline bool IntegerOptionValue::isValid(const std::string & value) { return std::all_of(value.begin(), value.end(), ::isdigit); }
}