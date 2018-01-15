#include "Catch2/single_include/catch.hpp"

#include "utility/mathematics/box3d.hpp"

SCENARIO("Box3D", "[Utility][Mathematics]")
{
	ece::FloatVector3u a{ 0.0f, 0.0f, 0.0f };
	ece::FloatVector3u b{ 10.0f, 10.0f, 10.0f };

	GIVEN("A 3D box define by 2 points")
	{
		ece::Box3D box(a, b);

		WHEN("Getting the center of the box")
		{
			//REQUIRE(box.getCenter() == ece::FloatVector3u{ 5.0f, 5.0f, 5.0f });
		}
	}
}