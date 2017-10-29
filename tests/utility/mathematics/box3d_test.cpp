#include "catch/catch.hpp"

#include "mathematics/box3d.hpp"

SCENARIO("Box3D", "[Utility][Mathematics]")
{
	ece::FloatVertex3u a(0.0f, 0.0f, 0.0f);
	ece::FloatVertex3u b(10.0f, 10.0f, 10.0f);

	GIVEN("A 3D box define by 2 points")
	{
		ece::Box3D box(a, b);

		WHEN("Getting the center of the box")
		{
			REQUIRE(box.getCenter() == ece::FloatVertex3u(5.0f, 5.0f, 5.0f));
		}
	}
}