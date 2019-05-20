#include "catch2/catch.hpp"

#include "utility/indexing.hpp"

SCENARIO("Version", "[Utility][Indexing]")
{
	WHEN("Take a random version")
	{
		REQUIRE(ece::Version<2>{ 1, 2 } == ece::Version<2>{ 1, 2 });
		REQUIRE(ece::Version<2>{ 1, 2 } != ece::Version<2>{ 2, 2 });
		REQUIRE(ece::Version<2>{ 1, 2 } < ece::Version<2>{ 1, 3});
		REQUIRE(ece::Version<2>{ 1, 2 } < ece::Version<2>{ 2, 1 });
		REQUIRE(ece::Version<2>{ 1, 2 } < ece::Version<2>{ 2, 2 });
		REQUIRE(ece::Version<2>{ 1, 2 } <= ece::Version<2>{ 1, 3 });
		REQUIRE(ece::Version<2>{ 1, 2 } <= ece::Version<2>{ 2, 1 });
		REQUIRE(ece::Version<2>{ 1, 2 } <= ece::Version<2>{ 2, 2 });
		REQUIRE(ece::Version<2>{ 1, 2 } <= ece::Version<2>{ 1, 2 });
		REQUIRE(ece::Version<2>{ 1, 3 } > ece::Version<2>{ 1, 2 });
		REQUIRE(ece::Version<2>{ 2, 1 } > ece::Version<2>{ 1, 2 });
		REQUIRE(ece::Version<2>{ 2, 2 } > ece::Version<2>{ 1, 2 });
		REQUIRE(ece::Version<2>{ 1, 3 } >= ece::Version<2>{ 1, 2 });
		REQUIRE(ece::Version<2>{ 2, 1 } >= ece::Version<2>{ 1, 2 });
		REQUIRE(ece::Version<2>{ 2, 2 } >= ece::Version<2>{ 1, 2 });
		REQUIRE(ece::Version<2>{ 1, 2 } >= ece::Version<2>{ 1, 2 });
		REQUIRE(ece::min(ece::Version<2>{ 1, 2 }, ece::Version<2>{ 2, 1 }) == ece::Version<2>{ 1, 2 });
		REQUIRE(ece::min(ece::Version<2>{ 2, 1 }, ece::Version<2>{ 1, 2 }) == ece::Version<2>{ 1, 2 });
		REQUIRE(ece::max(ece::Version<2>{ 1, 2 }, ece::Version<2>{ 2, 1 }) == ece::Version<2>{ 2, 1 });
		REQUIRE(ece::max(ece::Version<2>{ 2, 1 }, ece::Version<2>{ 1, 2 }) == ece::Version<2>{ 2, 1 });
	}
}