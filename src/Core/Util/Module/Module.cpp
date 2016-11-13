#include "Core\Util\Module\Module.hpp"

#include "Core\Core.hpp"

#include <iostream>

namespace ece
{
	Module::Module(const ModuleID id): dependencies(), services(), modeInitialized(Mode::NOT_INIT), id(id)
	{
	}

	Module::~Module()
	{
	}

	void Module::init(Mode mode)
	{
		if (!Core::isModuleInit(this->id)) {
			for (auto it = this->dependencies.begin(); it != this->dependencies.end(); ++it) {
				(*it)->init(mode);
			}
			for (auto it = this->services.begin(); it != this->services.end(); ++it) {
				(*it)->init(mode);
			}
			Core::initModule(this->id);
		}
	}

	void Module::setMode(Mode mode)
	{
	}
}
