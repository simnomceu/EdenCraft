#ifndef WINDOW_INL
#define WINDOW_INL

#include "Core\System\Event\Event.inl"
#include "Core\Geom\Vector.hpp"

namespace ece
{
	using WindowID = short int;
	using MonitorID = short int;
	using WindowState = unsigned short int;
	using WindowTag = unsigned short int;
	using WindowUnknownTag = unsigned short int;

	const WindowState NO_OPTIONS = 0b0000;
	const WindowState VISIBLE    = 0b0001;
	const WindowState FOCUSED    = 0b0010;
	const WindowState ICONIFIED  = 0b0100;
	const WindowState MAXIMIZED  = 0b1000;

	const WindowTag NO_OPTIONS_BIS  = 0b000000;
	const WindowTag FULLSCREEN      = 0b000001;
	const WindowTag TOOLBAR         = 0b000010;
	const WindowTag RESIZABLE       = 0b000100;
	const WindowTag INIT_VISIBLE    = 0b001000;
	const WindowTag INIT_FOCUSED    = 0b010000;
	const WindowTag INIT_MAXIMIZED  = 0b100000;


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
