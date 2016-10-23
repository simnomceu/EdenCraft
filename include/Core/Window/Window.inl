#ifndef WINDOW_INL
#define WINDOW_INL

#include "Core\Geom\Vector.hpp"

namespace ece
{
	using WindowID = short int;
	using MonitorID = short int;
	using WindowTag = unsigned short int;

	const WindowTag NO_OPTIONS   = 0b00000000;
	const WindowTag FULLSCREEN   = 0b00000001;
	const WindowTag TOOLBAR      = 0b00000010;
	const WindowTag RESIZABLE    = 0b00000100;
	const WindowTag VISIBLE      = 0b00001000; // initially visible
	const WindowTag FOCUSED      = 0b00010000;
	const WindowTag AUTO_ICONIFY = 0b00100000;
	const WindowTag FLOATING	 = 0b01000000;
	const WindowTag MAXIMIZED    = 0b10000000;


	using ColorRGB = ece::Vector3ui;
	using ColorRGBA = ece::Vector<unsigned int, 4>;

	enum ChannelColor : int {
		RED_CHANNEL = 0,
		GREEN_CHANNEL = 1,
		BLUE_CHANNEL = 2,
		ALPHA_CHANNEL = 3
	};
}

#endif // WINDOW_INL
