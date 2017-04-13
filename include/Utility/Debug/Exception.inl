#include <sstream>

namespace ece
{
	template <ExceptionType T>
	inline Exception<T>::Exception(const std::string & whatArg) : std::runtime_error(whatArg) { }

	template <ExceptionType T>
	template <class ...Args>
	Exception<T> Exception<T>::makeException(const std::string & message, Args ...args)
	{
		return Exception<T>(mapString(message, args...));
	}

	template <ExceptionType T>
	inline std::string Exception<T>::mapString(const std::string & content) { return content; }

	template <ExceptionType T>
	template <class V, class... Args>
	std::string Exception<T>::mapString(const std::string & content, V value, Args... args)
	{
		auto pos = content.find_first_of("%");
		if (pos != std::string::npos) {
			std::stringstream stream;
			stream << value;
			return content.substr(0, pos) + stream.str() + Exception<T>::mapString(content.substr(pos + 1), args...);
		}
		return content;
	}
}