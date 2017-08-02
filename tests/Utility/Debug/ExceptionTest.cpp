#include "Catch\catch.hpp"

#include "Debug\Exception.hpp"

SCENARIO("Exception", "[Utility][Debug]")
{
	GIVEN("A file exception")
	{
		WHEN("Code error is BAD_PATH")
		{
			auto exception = ece::FileException::makeException(ece::FileCodeError::BAD_PATH, "test.txt");

			REQUIRE_THAT(exception.what(), Catch::Contains("test.txt"));
			REQUIRE_THAT(exception.what(), Catch::StartsWith("Code 0"));
		}
		AND_WHEN("Code error is PARSE_ERROR")
		{
			auto exception = ece::FileException::makeException(ece::FileCodeError::PARSE_ERROR, "test.txt");

			REQUIRE_THAT(exception.what(), Catch::Contains("test.txt"));
			REQUIRE_THAT(exception.what(), Catch::StartsWith("Code 1"));
		}
		AND_WHEN("Code error is anything but an existing code")
		{
			REQUIRE_THAT(ece::FileException::makeException(static_cast<ece::FileCodeError>(7), "test.txt").what(),
				Catch::StartsWith("Code 7"));
			REQUIRE_THAT(ece::FileException::makeException(static_cast<ece::FileCodeError>(49), "test.txt").what(),
				Catch::StartsWith("Code 49"));
		}
	}

	GIVEN("A bad input exception")
	{
		auto exception = ece::BadInputException::makeException("trululu");
		REQUIRE_THAT(exception.what(), Catch::Contains("trululu"));
	}

	GIVEN("An initialization exception")
	{
		auto exception = ece::InitializationException::makeException("an integer");
		REQUIRE_THAT(exception.what(), Catch::StartsWith("an integer"));
	}

	GIVEN("A memory access exception")
	{
		WHEN("No access point is defined")
		{
			auto exception = ece::MemoryAccessException::makeException("a pointer");
			REQUIRE_THAT(exception.what(), Catch::Contains("a pointer"));
		}
		AND_WHEN("The access point is defined")
		{
			auto exception = ece::MemoryAccessException::makeException("a pointer", "a method");
			REQUIRE_THAT(exception.what(), Catch::Contains("a pointer"));
			REQUIRE_THAT(exception.what(), Catch::Contains("a method"));
		}
	}

	GIVEN("An out of range exception")
	{
		WHEN("No id is provided")
		{
			auto exception = ece::OutOfRangeException::makeException("an element");
			REQUIRE_THAT(exception.what(), Catch::Contains("an element"));
		}
		AND_WHEN("Any id is provided")
		{
			auto exception = ece::OutOfRangeException::makeException("an element", 1);
			REQUIRE_THAT(exception.what(), Catch::Contains("an element"));
			REQUIRE_THAT(exception.what(), Catch::Contains("1"));
		}
	}

	GIVEN("A resource exception")
	{
		WHEN("Any id is provided")
		{
			auto exception = ece::ResourceException::makeException("a shader", 10);
			REQUIRE_THAT(exception.what(), Catch::Contains("a shader"));
			REQUIRE_THAT(exception.what(), Catch::Contains("10"));
		}
	}
}