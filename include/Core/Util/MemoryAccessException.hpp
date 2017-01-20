#ifndef MEMORYACCESSEXCEPTION_HPP
#define MEMORYACCESSEXCEPTION_HPP

#include <exception>
#include <string>

namespace ece
{
	class MemoryAccessException: public std::exception
	{
	public:
		MemoryAccessException(const std::string & target);
		MemoryAccessException(const std::string & target, const std::string & origin);

		virtual char const * what();
	private:
		std::string content;
	};
}

#endif // MEMORYACCESSEXCEPTION_HPP
