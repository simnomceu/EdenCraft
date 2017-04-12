#ifndef OUTOFRANGEEXCEPTION_HPP
#define OUTOFRANGEEXCEPTION_HPP

#include <exception>
#include <string>

namespace ece
{
	class OutOfRangeException: std::exception
	{
	public:
		inline OutOfRangeException(const std::string & type, const int id);

		inline virtual char const * what() const override;

	private:
		std::string content;
	};
}

#include "Debug\OutOfRangeException.inl"

#endif
