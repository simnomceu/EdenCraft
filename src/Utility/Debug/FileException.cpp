#include "Debug\FileException.hpp"

namespace ece
{
	FileException::FileException(const FileCodeError codeError, const std::string & filename) : std::exception(), content("")
	{
		switch (codeError) {
		case BAD_PATH:
			this->content += "This file doesn't exist: ";
			this->content += filename;
			this->content += ".";
			break;
		case PARSE_ERROR:
			this->content += "Error while trying to parse ";
			this->content += filename;
			this->content += ". Check the content format.";
			break;
		default:
			break;
		}
	}
}