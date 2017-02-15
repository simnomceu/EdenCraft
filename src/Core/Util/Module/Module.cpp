#include "Core\Util\Module\Module.hpp"

#include <iostream>

namespace ece
{
	Module::Module(): dependencies(), services(), initialized(false), modeInitialized(Mode::NOT_INIT)
	{
	}

	Module::~Module()
	{
	}

	void Module::init(Mode mode)
	{
		if (!this->initialized) {
			for (auto it = this->dependencies.begin(); it != this->dependencies.end(); ++it) {
				(*it)->init(mode);
			}
			for (auto it = this->services.begin(); it != this->services.end(); ++it) {
				(*it)->init(mode);
			}

			this->initialized = true;
			this->modeInitialized = mode;
		}
	}

	void Module::setMode(Mode mode)
	{
		if (this->initialized) {
			for (auto it = this->dependencies.begin(); it != this->dependencies.end(); ++it) {
				(*it)->setMode(mode);
			}
			for (auto it = this->services.begin(); it != this->services.end(); ++it) {
				(*it)->setMode(mode);
			}

			this->modeInitialized = mode;
		}
	}
}
