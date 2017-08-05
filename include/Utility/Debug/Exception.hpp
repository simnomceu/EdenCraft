#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <stdexcept>
#include <string>
#include "Type.hpp"

namespace ece
{
	template <class T>
	class Exception : protected std::runtime_error
	{
	public:
		using std::runtime_error::what;

		inline Exception(const std::string & whatArg);

		template<class... Args>
		static T makeException(const std::string & message, Args... args);

	private:
		inline static std::string mapString(const std::string & content);

		template <class V, class... Args>
		static std::string mapString(const std::string & content, V value, Args... args);
	};

	class FileException : public Exception<FileException>
	{
	public:
		static FileException makeException(const FileCodeError codeError, const std::string & filename);
	};

	class BadInputException : public Exception<BadInputException>
	{
	public:
		static BadInputException makeException(const std::string & details);
	};

	class InitializationException : public Exception<InitializationException>
	{
	public:
		static InitializationException makeException(const std::string & target);
	};

	class MemoryAccessException : public Exception<MemoryAccessException>
	{
	public:
		static MemoryAccessException makeException(const std::string & target);
		static MemoryAccessException makeException(const std::string & target, const std::string & origin);
	};

	class OutOfRangeException : public Exception<OutOfRangeException>
	{
	public:
		static OutOfRangeException makeException(const std::string & type);
		static OutOfRangeException makeException(const std::string & type, const int id);
	};

	class ResourceException : public Exception<ResourceException>
	{
	public:
		static ResourceException makeException(const std::string & target, const unsigned short int id);
	};

	class DivideByZeroException : public Exception<DivideByZeroException>
	{
	public:
		static DivideByZeroException makeException(const std::string & origin);
	};
}

#include "Debug\Exception.inl"

#endif // EXCEPTION_HPP