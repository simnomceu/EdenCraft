#include "Rendering\Model\OldFileException.hpp"

namespace ece
{
	OldFileException::OldFileException(const OldFileException::Type type, const std::string & filename): std::exception(), content("")
    {
        switch (type) {
        case BAD_PATH:
            this->content += "This file doesn't exist: ";
            this->content += filename;
            this->content += ".";
            break;
        default:
            break;
        }
    }

    char const * OldFileException::what() const
    {
        return this->content.c_str();
    }
}
