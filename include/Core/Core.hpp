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
		static void init(const ece::Module & modules);

		static void setModuleMode(const ece::Module & module, const ece::Mode & mode);

	private:
		static void dispenser(const ece::Module & module, const ece::Mode & mode = DEFAULT);

		static void initEventManager(const ece::Mode & mode = DEFAULT);
		static void initWindowManager(const ece::Mode & mode = DEFAULT);
		static void initLog(const ece::Mode & mode = DEFAULT);

		static bool systemInit;
		static bool windowInit;
		static bool graphicInit;
		static bool ecsInit;
	};
}

#endif // CORE_HPP
