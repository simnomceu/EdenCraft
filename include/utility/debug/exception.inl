#include <sstream>

namespace ece
{
	Exception::Exception() : std::runtime_error(""), message() {}

	template<class ...Args>
	inline void Exception::setMessage(const std::string & message, Args ...args)
	{
		this->message = this->mapString(message, args...);
	}

	inline const char * Exception::what() const noexcept { return this->message.data(); }

	inline std::string Exception::mapString(const std::string & content) { return content; }

	template <class V, class... Args>
	std::string Exception::mapString(const std::string & content, V value, Args... args)
	{
		auto pos = content.find_first_of("%");
		if (pos != std::string::npos) {
			std::stringstream stream;
			stream << value;
			return content.substr(0, pos) + stream.str() + this->mapString(content.substr(pos + 1), args...);
		}
		return content;
	}
}
