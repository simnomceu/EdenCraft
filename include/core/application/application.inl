namespace ece
{
	inline Application::~Application() {}

	inline void Application::stop() { this->_running = false; }

	inline ArgumentAnalyzer & Application::getArgumentAnalyzer() { return this->getModule<ArgumentAnalyzer>(); }

	template <class T>
	inline T & Application::addModule(const ModuleMethodHandle<T> & init,
		const ModuleMethodHandle<T> & update,
		const ModuleMethodHandle<T> & terminate)
	{ return this->_moduleManager.add<T>(init, update, terminate); }

	template <class T>
	inline void Application::removeModule() { this->_moduleManager.remove<T>(); }

	template <class T>
	inline T & Application::getModule() { return this->_moduleManager.get<T>(); }

	inline void Application::onPreInit(const Listener & listener, const unsigned int slot) { this->_lifecycle->onPreInit(listener, slot); }
	inline void Application::onPostInit(const Listener & listener, const unsigned int slot) { this->_lifecycle->onPostInit(listener, slot); }
	inline void Application::onPreProcess(const Listener & listener, const unsigned int slot) { this->_lifecycle->onPreProcess(listener, slot); }
	inline void Application::onPreUpdate(const Listener & listener, const unsigned int slot) { this->_lifecycle->onPreUpdate(listener, slot); }
	inline void Application::onPostUpdate(const Listener & listener, const unsigned int slot) { this->_lifecycle->onPostUpdate(listener, slot); }
	inline void Application::onPostRender(const Listener & listener, const unsigned int slot) { this->_lifecycle->onPostRender(listener, slot); }
	inline void Application::onPreTerminate(const Listener & listener, const unsigned int slot) { this->_lifecycle->onPreTerminate(listener, slot); }
	inline void Application::onPostTerminate(const Listener & listener, const unsigned int slot) { this->_lifecycle->onPostTerminate(listener, slot); }

	inline const bool Application::isRunning() const { return this->_running; }
}