#ifndef INITIALIZATIONEXCEPTION_HPP
#define INITIALIZATIONEXCEPTION_HPP

#include <string>
#include <exception>

namespace ece
{
	class InitializationException: public std::exception
	{
	public:
		inline InitializationException(const std::string & target);

		virtual inline char const * what() const override;

	private:
		std::string content;
	};
}

#include "Util\Debug\InitializationException.inl"

#endif // INITIALIZATIONEXCEPTION_HPP