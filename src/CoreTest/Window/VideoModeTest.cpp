#include "Catch\catch.hpp"

//#include "Core\Core.hpp"

//#include "Core\Window\Window\VideoMode.hpp"

// TODO add test for stereo property

SCENARIO("VideoMode regression", "[Core][Window][Regression]")
{
	//ece::Core::init(ece::LOG, ece::SYSTEM | ece::WINDOW);
	/*GIVEN("A default VideoMode.")
	{
		ece::VideoMode videoMode;

		CHECK(videoMode.getRefreshRate() == ece::DEFAULT_REFRESH_RATE_ECE);
		CHECK(videoMode.getColorBits()[ece::RED_CHANNEL] == ece::DEFAULT_RED_BITS_ECE);
		CHECK(videoMode.getColorBits()[ece::GREEN_CHANNEL] == ece::DEFAULT_GREEN_BITS_ECE);
		CHECK(videoMode.getColorBits()[ece::BLUE_CHANNEL] == ece::DEFAULT_BLUE_BITS_ECE);
		CHECK(videoMode.getColorBits()[ece::ALPHA_CHANNEL] == ece::DEFAULT_ALPHA_BITS_ECE);
		CHECK(videoMode.getDepthBits() == ece::DEFAULT_DEPTH_BITS_ECE);
		CHECK(videoMode.getStencilBits() == ece::DEFAULT_STENCIL_BITS_ECE);
		CHECK(videoMode.getSamples() == ece::DEFAULT_SAMPLES_ECE);
		CHECK(videoMode.isDoubleBufferingActivate() == ece::DEFAULT_DOUBLE_BUFFERING_ECE);
		CHECK(videoMode.isSrgbCapable() == ece::DEFAULT_SRGB_CAPABLE_ECE);

		WHEN("Refresh rate is set to a new value.")
		{
			videoMode.setRefreshRate(30);

			THEN("New value is applied but the others values are not changed.")
			{
				CHECK(videoMode.getRefreshRate() == 30);
				CHECK(videoMode.getColorBits()[ece::RED_CHANNEL] == ece::DEFAULT_RED_BITS_ECE);
				CHECK(videoMode.getColorBits()[ece::GREEN_CHANNEL] == ece::DEFAULT_GREEN_BITS_ECE);
				CHECK(videoMode.getColorBits()[ece::BLUE_CHANNEL] == ece::DEFAULT_BLUE_BITS_ECE);
				CHECK(videoMode.getColorBits()[ece::ALPHA_CHANNEL] == ece::DEFAULT_ALPHA_BITS_ECE);
				CHECK(videoMode.getDepthBits() == ece::DEFAULT_DEPTH_BITS_ECE);
				CHECK(videoMode.getStencilBits() == ece::DEFAULT_STENCIL_BITS_ECE);
				CHECK(videoMode.getSamples() == ece::DEFAULT_SAMPLES_ECE);
				CHECK(videoMode.isDoubleBufferingActivate() == ece::DEFAULT_DOUBLE_BUFFERING_ECE);
				CHECK(videoMode.isSrgbCapable() == ece::DEFAULT_SRGB_CAPABLE_ECE);
			}
		}

		WHEN("Colors bits is set to a new value.")
		{
			videoMode.setColorBits(ece::ColorRGBA{4, 4, 4, 4});

			THEN("New value is applied but the others values are not changed.")
			{
				CHECK(videoMode.getRefreshRate() == ece::DEFAULT_REFRESH_RATE_ECE);
				CHECK(videoMode.getColorBits()[ece::RED_CHANNEL] == 4);
				CHECK(videoMode.getColorBits()[ece::GREEN_CHANNEL] == 4);
				CHECK(videoMode.getColorBits()[ece::BLUE_CHANNEL] == 4);
				CHECK(videoMode.getColorBits()[ece::ALPHA_CHANNEL] == 4);
				CHECK(videoMode.getDepthBits() == ece::DEFAULT_DEPTH_BITS_ECE);
				CHECK(videoMode.getStencilBits() == ece::DEFAULT_STENCIL_BITS_ECE);
				CHECK(videoMode.getSamples() == ece::DEFAULT_SAMPLES_ECE);
				CHECK(videoMode.isDoubleBufferingActivate() == ece::DEFAULT_DOUBLE_BUFFERING_ECE);
				CHECK(videoMode.isSrgbCapable() == ece::DEFAULT_SRGB_CAPABLE_ECE);
			}
		}

		WHEN("Depth bits is set to a new value.")
		{
			videoMode.setDepthBits(20);

			THEN("New value is applied but the others values are not changed.")
			{
				CHECK(videoMode.getRefreshRate() == ece::DEFAULT_REFRESH_RATE_ECE);
				CHECK(videoMode.getColorBits()[ece::RED_CHANNEL] == ece::DEFAULT_RED_BITS_ECE);
				CHECK(videoMode.getColorBits()[ece::GREEN_CHANNEL] == ece::DEFAULT_GREEN_BITS_ECE);
				CHECK(videoMode.getColorBits()[ece::BLUE_CHANNEL] == ece::DEFAULT_BLUE_BITS_ECE);
				CHECK(videoMode.getColorBits()[ece::ALPHA_CHANNEL] == ece::DEFAULT_ALPHA_BITS_ECE);
				CHECK(videoMode.getDepthBits() == 20);
				CHECK(videoMode.getStencilBits() == ece::DEFAULT_STENCIL_BITS_ECE);
				CHECK(videoMode.getSamples() == ece::DEFAULT_SAMPLES_ECE);
				CHECK(videoMode.isDoubleBufferingActivate() == ece::DEFAULT_DOUBLE_BUFFERING_ECE);
				CHECK(videoMode.isSrgbCapable() == ece::DEFAULT_SRGB_CAPABLE_ECE);
			}
		}

		WHEN("Stencil bits is set to a new value.")
		{
			videoMode.setStencilBits(1);

			THEN("New value is applied but the others values are not changed.")
			{
				CHECK(videoMode.getRefreshRate() == ece::DEFAULT_REFRESH_RATE_ECE);
				CHECK(videoMode.getColorBits()[ece::RED_CHANNEL] == ece::DEFAULT_RED_BITS_ECE);
				CHECK(videoMode.getColorBits()[ece::GREEN_CHANNEL] == ece::DEFAULT_GREEN_BITS_ECE);
				CHECK(videoMode.getColorBits()[ece::BLUE_CHANNEL] == ece::DEFAULT_BLUE_BITS_ECE);
				CHECK(videoMode.getColorBits()[ece::ALPHA_CHANNEL] == ece::DEFAULT_ALPHA_BITS_ECE);
				CHECK(videoMode.getDepthBits() == ece::DEFAULT_DEPTH_BITS_ECE);
				CHECK(videoMode.getStencilBits() == 1);
				CHECK(videoMode.getSamples() == ece::DEFAULT_SAMPLES_ECE);
				CHECK(videoMode.isDoubleBufferingActivate() == ece::DEFAULT_DOUBLE_BUFFERING_ECE);
				CHECK(videoMode.isSrgbCapable() == ece::DEFAULT_SRGB_CAPABLE_ECE);
			}
		}

		WHEN("Samples is set to a new value.")
		{
			videoMode.setSamples(2);

			THEN("New value is applied but the others values are not changed.")
			{
				CHECK(videoMode.getRefreshRate() == ece::DEFAULT_REFRESH_RATE_ECE);
				CHECK(videoMode.getColorBits()[ece::RED_CHANNEL] == ece::DEFAULT_RED_BITS_ECE);
				CHECK(videoMode.getColorBits()[ece::GREEN_CHANNEL] == ece::DEFAULT_GREEN_BITS_ECE);
				CHECK(videoMode.getColorBits()[ece::BLUE_CHANNEL] == ece::DEFAULT_BLUE_BITS_ECE);
				CHECK(videoMode.getColorBits()[ece::ALPHA_CHANNEL] == ece::DEFAULT_ALPHA_BITS_ECE);
				CHECK(videoMode.getDepthBits() == ece::DEFAULT_DEPTH_BITS_ECE);
				CHECK(videoMode.getStencilBits() == ece::DEFAULT_STENCIL_BITS_ECE);
				CHECK(videoMode.getSamples() == 2);
				CHECK(videoMode.isDoubleBufferingActivate() == ece::DEFAULT_DOUBLE_BUFFERING_ECE);
				CHECK(videoMode.isSrgbCapable() == ece::DEFAULT_SRGB_CAPABLE_ECE);
			}
		}

		WHEN("Double buffering is set to a new value.")
		{
			videoMode.setDoubleBuffering(false);

			THEN("New value is applied but the others values are not changed.")
			{
				CHECK(videoMode.getRefreshRate() == ece::DEFAULT_REFRESH_RATE_ECE);
				CHECK(videoMode.getColorBits()[ece::RED_CHANNEL] == ece::DEFAULT_RED_BITS_ECE);
				CHECK(videoMode.getColorBits()[ece::GREEN_CHANNEL] == ece::DEFAULT_GREEN_BITS_ECE);
				CHECK(videoMode.getColorBits()[ece::BLUE_CHANNEL] == ece::DEFAULT_BLUE_BITS_ECE);
				CHECK(videoMode.getColorBits()[ece::ALPHA_CHANNEL] == ece::DEFAULT_ALPHA_BITS_ECE);
				CHECK(videoMode.getDepthBits() == ece::DEFAULT_DEPTH_BITS_ECE);
				CHECK(videoMode.getStencilBits() == ece::DEFAULT_STENCIL_BITS_ECE);
				CHECK(videoMode.getSamples() == ece::DEFAULT_SAMPLES_ECE);
				CHECK(videoMode.isDoubleBufferingActivate() == false);
				CHECK(videoMode.isSrgbCapable() == ece::DEFAULT_SRGB_CAPABLE_ECE);
			}
		}

		WHEN("sRGB capable is set to a new value.")
		{
			videoMode.setSrgbCapable(true);

			THEN("New value is applied but the others values are not changed.")
			{
				CHECK(videoMode.getRefreshRate() == ece::DEFAULT_REFRESH_RATE_ECE);
				CHECK(videoMode.getColorBits()[ece::RED_CHANNEL] == ece::DEFAULT_RED_BITS_ECE);
				CHECK(videoMode.getColorBits()[ece::GREEN_CHANNEL] == ece::DEFAULT_GREEN_BITS_ECE);
				CHECK(videoMode.getColorBits()[ece::BLUE_CHANNEL] == ece::DEFAULT_BLUE_BITS_ECE);
				CHECK(videoMode.getColorBits()[ece::ALPHA_CHANNEL] == ece::DEFAULT_ALPHA_BITS_ECE);
				CHECK(videoMode.getDepthBits() == ece::DEFAULT_DEPTH_BITS_ECE);
				CHECK(videoMode.getStencilBits() == ece::DEFAULT_STENCIL_BITS_ECE);
				CHECK(videoMode.getSamples() == ece::DEFAULT_SAMPLES_ECE);
				CHECK(videoMode.isDoubleBufferingActivate() == ece::DEFAULT_DOUBLE_BUFFERING_ECE);
				CHECK(videoMode.isSrgbCapable() == true);
			}
		}
	}*/
}