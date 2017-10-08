#ifndef MODULE_HPP
#define MODULE_HPP

#include "module/base_module.hpp"
#include "module/module_method.hpp"

namespace ece
{
	template <class T>
	class Module: public BaseModule
	{
	public:
		Module() = delete;
		inline Module(const ModuleMethodHandle<T> & init = ModuleMethod<T>::VOID, const ModuleMethodHandle<T> & update = ModuleMethod<T>::VOID, const ModuleMethodHandle<T> & terminate = ModuleMethod<T>::VOID);
		Module(const Module & copy) = default;
		Module(Module && move) = default;

		~Module() = default;

		Module & operator=(const Module & copy) = default;
		Module & operator=(Module && move) = default;

		inline T & get();
		inline virtual void init() override;
		inline virtual void update() override;
		inline virtual void terminate() override;

	private:
		T module;
		ModuleMethod<T> initHandle;
		ModuleMethod<T> updateHandle;
		ModuleMethod<T> terminateHandle;
	};
}

#include "module/module.inl"

#endif // MODULE_HPP
