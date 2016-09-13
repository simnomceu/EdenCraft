#pragma once

namespace Window
{
	using WindowTag = unsigned short int;

	static const WindowTag NO_OPTIONS = 0b000;
	static const WindowTag FULLSCREEN = 0b001;
	static const WindowTag RESIZABLE = 0b010;
	static const WindowTag TOOLBAR = 0b100;

	static const int PRIMARY_MONITOR = 0;
}