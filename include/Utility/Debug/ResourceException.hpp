#ifndef RESOURCEEXCEPTION_HPP
#define RESOURCEEXCEPTION_HPP

#include <exception>
#include <string>

namespace ece
{
	class ResourceException : public std::exception
	{
	public:
		inline ResourceException(const std::string & target, const unsigned short int id);

		inline virtual char const * what() const override;

	private:
		std::string message;
	};
}

#include "Debug\ResourceException.inl"

#endif // RESOURCEEXCEPTION_HPP