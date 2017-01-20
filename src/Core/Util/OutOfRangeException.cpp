#include "Core\Util\OutOfRangeException.hpp"

namespace ece
{
	OutOfRangeException::OutOfRangeException(const std::string & type, const int id): content()
	{
		this->content = "Out of range access for " + type + " " + std::to_string(id);
	}

	char const * OutOfRangeException::what()
	{
		return this->content.c_str();
	}
}
