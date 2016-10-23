#include "Catch\catch.hpp"

#include "Core\Window\VideoMode.hpp"
#include "Core\Window\Window.inl"

SCENARIO("VideoMode", "[Core][Window]")
{
	GIVEN("A default VideoMode")
	{
		ece::VideoMode videoMode;

		REQUIRE(videoMode.getRefreshRate() == 60);
		REQUIRE(videoMode.getColorBits()[ece::RED_CHANNEL] == 8);
		REQUIRE(videoMode.getColorBits()[ece::GREEN_CHANNEL] == 8);
		REQUIRE(videoMode.getColorBits()[ece::BLUE_CHANNEL] == 8);
		REQUIRE(videoMode.getColorBits()[ece::ALPHA_CHANNEL] == 8);
		REQUIRE(videoMode.getDepthBits() == 32);
		REQUIRE(videoMode.getStencilBits() == 32);
		REQUIRE(videoMode.getSamples() == 2);
		REQUIRE(videoMode.isDoubleBufferingActivate());
		REQUIRE(videoMode.getSrgbCapable() == 1);

		WHEN("Refresh rate is set to a new value")
		{
			videoMode.setRefreshRate(30);

			THEN("New value is applied.")
			{
				REQUIRE(videoMode.getRefreshRate() == 30);
			}
		}
	}
}