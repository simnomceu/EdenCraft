#ifndef OUTOFRANGEEXCEPTION_HPP
#define OUTOFRANGEEXCEPTION_HPP

#include <exception>
#include <string>

namespace ece
{
	class OutOfRangeException: std::exception
	{
	public:
		OutOfRangeException(const std::string & type, const int id);

		virtual char const * what();

	private:
		std::string content;
	};
}

#endif
