#include "debug/exception.hpp"

namespace ece
{
	FileException FileException::makeException(const FileCodeError codeError, const std::string & filename)
	{
		switch (codeError) {
		case BAD_PATH:
			return Exception<FileException>::makeException("Code %. This file doesn't exist: %.", (int)codeError, filename);
			break;
		case PARSE_ERROR:
			return Exception<FileException>::makeException("Code %. Error while trying to parse %. Check the content format.", (int)codeError, filename);
			break;
		default:
			return Exception<FileException>::makeException("Code %i. Undefined error on file %.", (int)codeError, filename);
			break;
		}
	}

	BadInputException BadInputException::makeException(const std::string & details)
	{
		return Exception<BadInputException>::makeException("Bad input: %.", details);
	}

	InitializationException InitializationException::makeException(const std::string & target)
	{
		return Exception<InitializationException>::makeException("% has failed to initialize.", target);
	}

	MemoryAccessException MemoryAccessException::makeException(const std::string & target)
	{
		return Exception<MemoryAccessException>::makeException("Bad access to %. The pointer has expired.", target);
	}

	MemoryAccessException MemoryAccessException::makeException(const std::string & target, const std::string & origin)
	{
		return Exception<MemoryAccessException>::makeException("Bad access to % from %. The pointer has expired.", target, origin);
	}

	OutOfRangeException OutOfRangeException::makeException(const std::string & type)
	{
		return Exception<OutOfRangeException>::makeException("Out of range access for %.", type);
	}

	OutOfRangeException OutOfRangeException::makeException(const std::string & type, const int id)
	{
		return Exception<OutOfRangeException>::makeException("Out of range access for % %.", type, id);
	}

	ResourceException ResourceException::makeException(const std::string & target, const unsigned short int id)
	{
		return Exception<ResourceException>::makeException("The resource % with the ID % is not available.", target, id);
	}


	DivideByZeroException DivideByZeroException::makeException(const std::string & origin)
	{
		return Exception<DivideByZeroException>::makeException("A division by zero has been handle in %", origin);
	}
}
