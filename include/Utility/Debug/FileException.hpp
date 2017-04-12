#ifndef FILEEXCEPTION_HPP
#define FILEEXCEPTION_HPP

#include <exception>
#include <string>

#include "Type.hpp"

namespace ece
{
	class FileException : public std::exception
	{
	public:
		FileException(const FileCodeError codeError, const std::string & filename);

		inline virtual char const * what() const;
	private:
		std::string content;
	};
}

#include "Debug\FileException.inl"

#endif // FILEEXCEPTION_HPP
