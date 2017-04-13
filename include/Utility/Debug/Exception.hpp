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
}

#include "Debug\Exception.inl"

#endif // EXCEPTION_HPP