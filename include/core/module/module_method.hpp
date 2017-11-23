#ifndef MODULE_METHOD_HPP
#define MODULE_METHOD_HPP

#include <functional>

namespace ece
{
	template <class T> using ModuleMethodHandle = std::function<void(T &)>;

	template <class T>
	class ModuleMethod: protected ModuleMethodHandle<T>
	{
	public:
		static const ModuleMethodHandle<T> VOID;

		ModuleMethod() = delete;
		inline ModuleMethod(const ModuleMethodHandle<T> & copy);
		ModuleMethod(const ModuleMethod & copy) = default;
		ModuleMethod(ModuleMethod && move) = default;

		~ModuleMethod() = default;

		ModuleMethod & operator=(const ModuleMethod & copy) = default;
		ModuleMethod & operator=(ModuleMethod && move) = default;

		using ModuleMethodHandle<T>::operator();
	};
}

#include "core/module/module_method.inl"

#endif // MODULE_METHOD_HPP
