#ifndef CORE_INL
#define CORE_INL

namespace ece
{
	using Module = unsigned short int;
	using Mode = unsigned short int;

	const Module NONE = 0b0000;
	const Module SYSTEM = 0b0001;
	const Module WINDOW = 0b0010;
	const Module GRAPHIC = 0b0100;
	const Module ECS = 0b1000;

	const Mode OFF = 0b00;
	const Mode DEFAULT = 0b01;
	const Mode CONSOLE = 0b10;
}

#endif // CORE_INL
