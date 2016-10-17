#ifndef WINDOW_INL
#define WINDOW_INL

namespace Utils
{
	using WindowID = short int;
	using MonitorID = short int;
	using WindowTag = unsigned short int;

	static const WindowTag NO_OPTIONS = 0b000;
	static const WindowTag FULLSCREEN = 0b001;
	static const WindowTag TOOLBAR    = 0b010;
}

#endif // WINDOW_INL
