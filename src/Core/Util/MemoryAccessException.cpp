#include "Core\Util\MemoryAccessException.hpp"

namespace ece
{
	MemoryAccessException::MemoryAccessException(const std::string & target): content("")
	{
		this->content = "Bad access to " + target + ". The pointer has expired.";
	}

	MemoryAccessException::MemoryAccessException(const std::string & target, const std::string & origin) : content("")
	{
		this->content = "Bad access to " + target + " from " + origin + ". The pointer has expired.";
	}

	char const * MemoryAccessException::what()
	{
		return this->content.c_str();
	}
}
