#include "core/module/module_manager.hpp"

namespace ece
{
	void ModuleManager::initAll()
	{
		for (auto element : this->modules) {
			element->init();
		}
	}

	void ModuleManager::updateAll()
	{
		for (auto element : this->modules) {
			element->update();
		}
	}

	void ModuleManager::terminateAll()
	{
		for (auto element : this->modules) {
			element->terminate();
		}
	}
}