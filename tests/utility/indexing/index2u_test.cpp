#include "catch/catch.hpp"

#include "indexing/index2u.hpp"

SCENARIO("Index2u", "[Utility][Indexing]")
{
	WHEN("Getting default index")
	{
		ece::Index2u index;
		REQUIRE(index.i == 0);
		REQUIRE(index.j == 0);

		THEN("Get the index")
		{
			REQUIRE(index.get(10) == 0);
		}
		AND_THEN("Set a new index")
		{
			index.set(10, 13);
			REQUIRE(index.i == 3);
			REQUIRE(index.j == 1);
			REQUIRE(index.get(10) == 13);
		}
	}
	AND_WHEN("Getting a specific index")
	{
		ece::Index2u index(3, 1);

		REQUIRE(index.i == 3);
		REQUIRE(index.j == 1);

		THEN("Get the index")
		{
			REQUIRE(index.get(10) == 13);
		}
	}
}