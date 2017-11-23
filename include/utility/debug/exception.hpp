#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <stdexcept>
#include <string>
#include "utility/type.hpp"

namespace ece
{
	class Exception : protected std::runtime_error
	{
	public:
		inline Exception();

		template <class ...Args>
		inline void setMessage(const std::string & message, Args... args);

		inline virtual const char * what() const noexcept override;

	private:
		std::string message;

		inline std::string mapString(const std::string & content);

		template <class V, class... Args>
		std::string mapString(const std::string & content, V value, Args... args);
	};

	class FileException : public Exception
	{
	public:
		FileException(const FileCodeError codeError, const std::string & filename);
	};

	class BadInputException : public Exception
	{
	public:
		BadInputException(const std::string & details);
	};

	class InitializationException : public Exception
	{
	public:
		InitializationException(const std::string & target);
	};

	class MemoryAccessException : public Exception
	{
	public:
		MemoryAccessException(const std::string & target);
		MemoryAccessException(const std::string & target, const std::string & origin);
	};

	class OutOfRangeException : public Exception
	{
	public:
		OutOfRangeException(const std::string & type);
		OutOfRangeException(const std::string & type, const int id);
	};

	class ResourceException : public Exception
	{
	public:
		ResourceException(const std::string & target, const unsigned short int id);
	};

	class DivideByZeroException : public Exception
	{
	public:
		DivideByZeroException(const std::string & origin);
	};
}

#include "utility/debug/exception.inl"

#endif // EXCEPTION_HPP
