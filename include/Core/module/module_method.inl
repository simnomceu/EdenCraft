namespace ece
{
	template <class T> const ModuleMethodHandle<T> ModuleMethod<T>::VOID = [](T &) {};

	template <class T>
	inline ModuleMethod<T>::ModuleMethod(const ModuleMethodHandle<T> & copy): ModuleMethodHandle<T>(copy) {}
}