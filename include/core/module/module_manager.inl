namespace ece
{
	template <class T>
	T & ModuleManager::add(const ModuleMethodHandle<T> & init, const ModuleMethodHandle<T> & update, const ModuleMethodHandle<T> & terminate)
	{
		auto element = std::make_shared<Module<T>>(init, update, terminate);
		this->_modules.push_back(element);
		return element->get();
	}

	template <class T>
	void ModuleManager::remove()
	{
		auto it = this->_modules.begin();
		bool found = false;
		while (!found && it != this->_modules.end()) {
			std::shared_ptr<Module<T>> tried = std::static_pointer_cast<Module<T>>(*it);
			if (tried) {
				found = true;
				this->_modules.erase(it);
			}
			++it;
		}
	}

	template <class T>
	T & ModuleManager::get()
	{
		auto it = this->_modules.begin();
		bool found = false;
		while (!found && it != this->_modules.end()) {
			std::shared_ptr<Module<T>> tried = std::static_pointer_cast<Module<T>>(*it);
			if (tried) {
				found = true;
				return tried->get();
			}
			++it;
		}
		throw std::runtime_error("This module does not exist.");
	}
}