#ifndef WINDOW_INL
#define WINDOW_INL

#include "Geom\Vector.hpp"

namespace Utils
{
	using WindowID = short int;
	using MonitorID = short int;
	using WindowTag = unsigned short int;

	static const WindowTag NO_OPTIONS   = 0b00000000;
	static const WindowTag FULLSCREEN   = 0b00000001;
	static const WindowTag TOOLBAR      = 0b00000010;
	static const WindowTag RESIZABLE    = 0b00000100;
	static const WindowTag VISIBLE      = 0b00001000; // initially visible
	static const WindowTag FOCUSED      = 0b00010000;
	static const WindowTag AUTO_ICONIFY = 0b00100000;
	static const WindowTag FLOATING		= 0b01000000;
	static const WindowTag MAXIMIZED    = 0b10000000;


	using ColorRGB = Geom::Vector3ui;
	using ColorRGBA = Geom::Vector<unsigned int, 4>;
}

#endif // WINDOW_INL
