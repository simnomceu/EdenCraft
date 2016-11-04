#ifndef CORE_INL
#define CORE_INL

namespace ece
{
	using ServiceID = unsigned short int;
	using ModuleID = unsigned short int;

	const ServiceID NO_SERVICE = 0b000;
	const ServiceID LOG = 0b000;

	const ModuleID NO_MODULE = 0b0000;
	const ModuleID SYSTEM = 0b0001;
	const ModuleID WINDOW = 0b0010;
	const ModuleID GRAPHIC = 0b0100;
	const ModuleID ECS = 0b1000;
}

#endif // CORE_INL
