#include "debug/exception.hpp"

namespace ece
{
	FileException::FileException(const FileCodeError codeError, const std::string & filename): Exception()
	{
		switch (codeError) {
		case BAD_PATH:
			this->setMessage("Code %. This file doesn't exist: %.", (int)codeError, filename);
			break;
		case PARSE_ERROR:
			this->setMessage("Code %. Error while trying to parse %. Check the content format.", (int)codeError, filename);
			break;
		default:
			this->setMessage("Code %i. Undefined error on file %.", (int)codeError, filename);
			break;
		}
	}

	BadInputException::BadInputException(const std::string & details) : Exception()
	{
		this->setMessage("Bad input: %.", details);
	}

	InitializationException::InitializationException(const std::string & target) : Exception()
	{
		this->setMessage("% has failed to initialize.", target);
	}

	MemoryAccessException::MemoryAccessException(const std::string & target) : Exception()
	{
		this->setMessage("Bad access to %. The pointer has expired.", target);
	}

	MemoryAccessException::MemoryAccessException(const std::string & target, const std::string & origin) : Exception()
	{
		this->setMessage("Bad access to % from %. The pointer has expired.", target, origin);
	}

	OutOfRangeException::OutOfRangeException(const std::string & type) : Exception()
	{
		this->setMessage("Out of range access for %.", type);
	}

	OutOfRangeException::OutOfRangeException(const std::string & type, const int id) : Exception()
	{
		this->setMessage("Out of range access for % %.", type, id);
	}

	ResourceException::ResourceException(const std::string & target, const unsigned short int id) : Exception()
	{
		this->setMessage("The resource % with the ID % is not available.", target, id);
	}

	DivideByZeroException::DivideByZeroException(const std::string & origin) : Exception()
	{
		this->setMessage("A division by zero has been handle in %", origin);
	}
}
