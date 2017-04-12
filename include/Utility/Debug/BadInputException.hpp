#ifndef BADINPUTEXCEPTION_HPP
#define BADINPUTEXCEPTION_HPP

#include <exception>
#include <string>

namespace ece
{
	class BadInputException: public std::exception
	{
	public:
		inline BadInputException(const std::string & details);

		virtual inline char const * what() const override;

	private:
		std::string details;
	};
}

#include "Util\Debug\BadInputException.inl"

#endif // BADINPUTEXCEPTION_HPP