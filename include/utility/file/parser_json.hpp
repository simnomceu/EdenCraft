#ifndef PARSER_JSON_HPP
#define PARSER_JSON_HPP

#include <string>
#include "json\object_json.hpp"

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

#endif // PARSER_JSON_HPP