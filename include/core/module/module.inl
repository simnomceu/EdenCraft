namespace ece
{
	template<class T>
	inline Module<T>::Module(const ModuleMethodHandle<T> & init, const ModuleMethodHandle<T> & update, const ModuleMethodHandle<T> & terminate):
		BaseModule(), _module(), _initHandle(init), _updateHandle(update), _terminateHandle(terminate) {}

	template<class T> inline T & Module<T>::get() { return this->_module; }

	template<class T> inline void Module<T>::init() { this->_initHandle(this->_module); }

	template<class T> inline void Module<T>::update() { this->_updateHandle(this->_module); }

	template<class T> inline void Module<T>::terminate() { this->_terminateHandle(this->_module); }
}