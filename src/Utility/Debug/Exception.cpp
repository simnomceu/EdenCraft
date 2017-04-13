#include "Debug\Exception.hpp"

namespace ece
{
	namespace Debug
	{
		FileException makeFileException(const FileCodeError codeError, const std::string & filename)
		{
			switch (codeError) {
			case BAD_PATH:
				return FileException::makeException("Code %. This file doesn't exist: %.", (int)codeError, filename);
				break;
			case PARSE_ERROR:
				return FileException::makeException("Code %. Error while trying to parse %. Check the content format.", (int)codeError, filename);
				break;
			default:
				return FileException::makeException("Code %i. Undefined error on file %.", (int)codeError, filename);
				break;
			}
		}
	}
}
