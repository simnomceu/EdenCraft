#ifndef MODULE_MANAGER_HPP
#define MODULE_MANAGER_HPP

#include <vector>
#include <memory>

#include "core/module/module.hpp"

namespace ece
{
	class ModuleManager
	{
	public:
		ModuleManager() = default;
		ModuleManager(const ModuleManager & copy) = default;
		ModuleManager(ModuleManager && move) = default;

		~ModuleManager() = default;

		ModuleManager & operator=(const ModuleManager & copy) = default;
		ModuleManager & operator=(ModuleManager && move) = default;

		template <class T> T & add(const ModuleMethodHandle<T> & init = ModuleMethod<T>::VOID, const ModuleMethodHandle<T> & update = ModuleMethod<T>::VOID, const ModuleMethodHandle<T> & terminate = ModuleMethod<T>::VOID);
		template <class T> void remove();
		template <class T> T & get();

		void initAll();
		void updateAll();
		void terminateAll();

	private:
		std::vector<std::shared_ptr<BaseModule>> _modules;
	};
}

#include "core/module/module_manager.inl"

#endif // MODULE_MANAGER_HPP