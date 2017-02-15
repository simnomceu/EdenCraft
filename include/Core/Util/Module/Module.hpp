#ifndef MODULE_HPP
#define MODULE_HPP

#include "Core\Util\Module\Service.hpp"

#include <vector>


// TODO : make this class as a singleton for each derived classes ? Or at list the initialized attribute

namespace ece
{
	class Module
	{
	public:
		Module();
		virtual ~Module() = 0;
		
		void init(Mode mode = Mode::NONE);

		void setMode(Mode mode);
	
	protected:
		std::vector<Module *> dependencies;
		std::vector<Service *> services;
		bool initialized;
		Mode modeInitialized;
	};
}

#endif // MODULE_HPP
