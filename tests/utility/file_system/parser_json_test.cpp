#include "Catch2/single_include/catch.hpp"

#include "utility/file_system/parser_json.hpp"
#include "utility/debug/exception.hpp"

SCENARIO("ParserJSON", "[Utility][File]")
{
	WHEN("Initializing the parser with no file")
	{
		ece::ParserJSON parser;

		THEN("Accessing the JSON object")
		{
			auto json = parser.getObject();

			REQUIRE_FALSE(json.get());
		}
		AND_THEN("Open a document")
		{
			REQUIRE_NOTHROW(parser.loadFromFile("../tests/resource/parse.json"));
			REQUIRE(parser.getObject().get());
		}
	}
	AND_WHEN("Initializing with an unknown file")
	{
		//REQUIRE_THROWS_AS(ece::ParserJSON("../tests/resource/file_unknown.txt"), ece::FileException);
	}
	AND_WHEN("Initializing with an existing valid file")
	{
		ece::ParserJSON parser;
		parser.loadFromFile("../tests/resource/parse.json");

		THEN("Accessing the JSON object")
		{
			auto json = parser.getObject();

			REQUIRE(json.get());
		}
	}
	AND_WHEN("Initializing with an existing invalid file")
	{
		//REQUIRE_THROWS(ece::ParserJSON("../tests/resource/file.txt"));
	}
}