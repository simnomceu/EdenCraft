#include "Module.hpp"
namespace ece
{
	template<class T>
	inline Module<T>::Module(const ModuleMethodHandle<T> & init, const ModuleMethodHandle<T> & update, const ModuleMethodHandle<T> & terminate):
		BaseModule(), module(), initHandle(init), updateHandle(update), terminateHandle(terminate) {}

	template<class T> inline T & Module<T>::get() { return this->module; }

	template<class T> inline void Module<T>::init() { this->initHandle(this->module); }

	template<class T> inline void Module<T>::update() { this->updateHandle(this->module); }

	template<class T> inline void Module<T>::terminate() { this->terminateHandle(this->module); }
}