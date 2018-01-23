#ifndef WINDOW_ENUM_HPP
#define WINDOW_ENUM_HPP

#include "utility/mathematics/vector3u.hpp"
#include "utility/mathematics/vector4u.hpp"
#include "utility/enum/enum_flags.hpp"

namespace ece
{
	EnumFlagsT(unsigned short int, WindowState)
	{
		NO_OPTIONS = 0b0000,
			VISIBLE = 0b0001,
			FOCUSED = 0b0010,
			ICONIFIED = 0b0100,
			MAXIMIZED = 0b1000
	};

	EnumFlagsT(unsigned short int, WindowTag)
	{
		NO_OPTIONS_BIS = 0b000000,
			FULLSCREEN = 0b000001,
			TOOLBAR = 0b000010,
			RESIZABLE = 0b000100,
			INIT_VISIBLE = 0b001000,
			INIT_FOCUSED = 0b010000,
			INIT_MAXIMIZED = 0b100000
	};

	EnumFlagsT(unsigned short int, WindowUnknownTag)
	{
		AUTO_ICONIFY = 0b0,
			FLOATING = 0b1
	};

	using ColorRGB = ece::IntVector3u;
	using ColorRGBA = ece::IntVector4u;

	enum class ChannelColor : int {
		RED_CHANNEL = 0,
		GREEN_CHANNEL = 1,
		BLUE_CHANNEL = 2,
		ALPHA_CHANNEL = 3
	};
}

#endif // WINDOW_ENUM_HPP