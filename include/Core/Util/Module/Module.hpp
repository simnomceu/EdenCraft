#ifndef MODULE_HPP
#define MODULE_HPP

#include "Core\Util\Module\Service.hpp"
#include "Core\Core.inl"

#include <vector>

namespace ece
{
	class Module
	{
	public:
		Module(const ModuleID id);
		virtual ~Module() = 0;
		
		void init(Mode mode = Mode::NONE);

		void setMode(Mode mode);
	
	protected:
		std::vector<Module *> dependencies;
		std::vector<Service *> services;
		Mode modeInitialized;
		ModuleID id;
	};
}

#endif // MODULE_HPP
