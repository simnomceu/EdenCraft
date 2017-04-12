#ifndef MEMORYACCESSEXCEPTION_HPP
#define MEMORYACCESSEXCEPTION_HPP

#include <exception>
#include <string>

namespace ece
{
	class MemoryAccessException: public std::exception
	{
	public:
		inline MemoryAccessException(const std::string & target);
		inline MemoryAccessException(const std::string & target, const std::string & origin);

		inline virtual char const * what() const override;
	private:
		std::string content;
	};
}

#include "Debug\MemoryAccessException.inl"

#endif // MEMORYACCESSEXCEPTION_HPP
