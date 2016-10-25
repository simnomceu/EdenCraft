#ifndef WINDOW_INL
#define WINDOW_INL

#include "Core\Geom\Vector.hpp"

namespace ece
{
	using WindowID = short int;
	using MonitorID = short int;
	using WindowState = unsigned short int;
	using WindowTag = unsigned short int;
	using WindowPreTag = unsigned short int;
	using WindowUnknownTag = unsigned short int;

	const WindowState NO_OPTIONS = 0b0000;
	const WindowState VISIBLE    = 0b0001;
	const WindowState FOCUSED    = 0b0010;
	const WindowState ICONIFIED  = 0b0100;
	const WindowState MAXIMIZED  = 0b1000;

	const WindowTag NO_OPTIONS_BIS = 0b000;
	const WindowTag FULLSCREEN = 0b001;
	const WindowTag TOOLBAR    = 0b010;
	const WindowTag RESIZABLE  = 0b100;

	const WindowPreTag NO_OPTIONS_TER      = 0b000;
	const WindowPreTag INIT_VISIBLE    = 0b001;
	const WindowPreTag INIT_FOCUSED    = 0b010;
	const WindowPreTag INIT_MAXIMIZED  = 0b100;


	const WindowUnknownTag AUTO_ICONIFY = 0b0;
	const WindowUnknownTag FLOATING     = 0b1;


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
