#include "ColorGL.hpp"

Colors::ColorRGBA Colors::fromRGBtoRGBA(const Colors::Color & color)
{
	Colors::ColorRGBA rgba = { color[0], color[1], color[2], 1.0f };
	return rgba;
}
