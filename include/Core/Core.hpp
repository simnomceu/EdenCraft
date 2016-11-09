#ifndef CORE_HPP
#define CORE_HPP

#include "Core\Core.inl"

// TODO manage module
// TODO manage services
// TODO manage mode
// TODO manage dependencies

namespace ece
{
	class Core
	{
	public:
		static void init(const ServiceID services, const ModuleID modules);
	};
}

#endif // CORE_HPP
