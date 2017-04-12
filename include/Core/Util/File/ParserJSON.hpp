#ifndef PARSERJSON_HPP
#define PARSERJSON_HPP

#include <string>
#include "Util\JSON\ObjectJSON.hpp"

namespace ece
{
	class ParserJSON
	{
	public:
		ParserJSON() = default;
		ParserJSON(const std::string & pathname);
		ParserJSON(const ParserJSON & copy) = default;
		ParserJSON(ParserJSON && move) = default;
		
		~ParserJSON() = default;

		ParserJSON & operator=(const ParserJSON & copy) = default;
		ParserJSON & operator=(ParserJSON && move) = default;

		void open(const std::string & pathname);

		std::shared_ptr<ObjectJSON> getObject();

	private:
		std::string pathname;
		std::shared_ptr<ObjectJSON> contentJSON;
	};
}

#endif // PARSERJSON_HPP