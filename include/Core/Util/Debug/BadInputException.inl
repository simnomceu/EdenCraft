#include "BadInputException.hpp"

namespace ece
{
	inline BadInputException::BadInputException(const std::string & details): std::exception(), details() 
	{
		this->details = "Bad input: " + details;
	}

	inline char const * BadInputException::what() const { return this->details.data();  }
}