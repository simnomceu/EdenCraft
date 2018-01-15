#include "Catch2/single_include/catch.hpp"

#include "utility/debug/exception.hpp"

SCENARIO("Exception", "[Utility][Debug]")
{
	GIVEN("A file exception")
	{
		WHEN("Code error is BAD_PATH")
		{
			ece::FileException exception(ece::FileCodeError::BAD_PATH, "test.txt");

			REQUIRE_THAT(exception.what(), Catch::Contains("test.txt"));
			REQUIRE_THAT(exception.what(), Catch::StartsWith("Code 0"));
		}
		AND_WHEN("Code error is PARSE_ERROR")
		{
			ece::FileException exception(ece::FileCodeError::PARSE_ERROR, "test.txt");

			REQUIRE_THAT(exception.what(), Catch::Contains("test.txt"));
			REQUIRE_THAT(exception.what(), Catch::StartsWith("Code 1"));
		}
		AND_WHEN("Code error is anything but an existing code")
		{
			REQUIRE_THAT(ece::FileException(static_cast<ece::FileCodeError>(7), "test.txt").what(),
				Catch::StartsWith("Code 7"));
			REQUIRE_THAT(ece::FileException(static_cast<ece::FileCodeError>(49), "test.txt").what(),
				Catch::StartsWith("Code 49"));
		}
	}

	GIVEN("A bad input exception")
	{
		ece::BadInputException exception("trululu");
		REQUIRE_THAT(exception.what(), Catch::Contains("trululu"));
	}

	GIVEN("An initialization exception")
	{
		ece::InitializationException exception("an integer");
		REQUIRE_THAT(exception.what(), Catch::StartsWith("an integer"));
	}

	GIVEN("A memory access exception")
	{
		WHEN("No access point is defined")
		{
			ece::MemoryAccessException exception("a pointer");
			REQUIRE_THAT(exception.what(), Catch::Contains("a pointer"));
		}
		AND_WHEN("The access point is defined")
		{
			ece::MemoryAccessException exception("a pointer", "a method");
			REQUIRE_THAT(exception.what(), Catch::Contains("a pointer"));
			REQUIRE_THAT(exception.what(), Catch::Contains("a method"));
		}
	}

	GIVEN("An out of range exception")
	{
		WHEN("No id is provided")
		{
			ece::OutOfRangeException exception("an element");
			REQUIRE_THAT(exception.what(), Catch::Contains("an element"));
		}
		AND_WHEN("Any id is provided")
		{
			ece::OutOfRangeException exception("an element", 1);
			REQUIRE_THAT(exception.what(), Catch::Contains("an element"));
			REQUIRE_THAT(exception.what(), Catch::Contains("1"));
		}
	}

	GIVEN("A resource exception")
	{
		WHEN("Any id is provided")
		{
			ece::ResourceException exception("a shader", 10);
			REQUIRE_THAT(exception.what(), Catch::Contains("a shader"));
			REQUIRE_THAT(exception.what(), Catch::Contains("10"));
		}
	}
}