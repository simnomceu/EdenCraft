#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <stdexcept>
#include <string>
#include "Type.hpp"

namespace ece
{
	enum class ExceptionType : unsigned int
	{
		FILE_EXCEPTION = 0
	};

	template <ExceptionType T>
	class Exception : protected std::runtime_error
	{
	public:
		using std::runtime_error::what;

		inline Exception(const std::string & whatArg);

		template<class... Args>
		static Exception<T> makeException(const std::string & message, Args... args);

	private:
		inline static std::string mapString(const std::string & content);

		template <class V, class... Args>
		static std::string mapString(const std::string & content, V value, Args... args);
	};

	namespace Debug
	{
		typedef Exception<ExceptionType::FILE_EXCEPTION> FileException;
		FileException makeFileException(const FileCodeError codeError, const std::string & filename);
	}
}

#include "Debug\Exception.inl"

#endif // EXCEPTION_HPP