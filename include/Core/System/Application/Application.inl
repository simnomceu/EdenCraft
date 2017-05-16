namespace ece
{
	inline Application::~Application() {}

	inline void Application::stop() { this->running = false; }

	inline ArgumentAnalyzer & Application::getArgumentAnalyzer() { return this->getModule<ArgumentAnalyzer>(); }

	template <class T>
	inline T & Application::addModule(const ModuleMethodHandle<T> & init,
		const ModuleMethodHandle<T> & update,
		const ModuleMethodHandle<T> & terminate)
	{ return this->moduleManager.add<T>(init, update, terminate); }

	template <class T>
	inline void Application::removeModule() { this->moduleManager.remove<T>(); }

	template <class T>
	inline T & Application::getModule() { return this->moduleManager.get<T>(); }

	inline void Application::onPreInit(const Listener & listener, const unsigned int slot) { this->lifecycle->onPreInit(listener, slot); }
	inline void Application::onPostInit(const Listener & listener, const unsigned int slot) { this->lifecycle->onPostInit(listener, slot); }
	inline void Application::onPreProcess(const Listener & listener, const unsigned int slot) { this->lifecycle->onPreProcess(listener, slot); }
	inline void Application::onPreUpdate(const Listener & listener, const unsigned int slot) { this->lifecycle->onPreUpdate(listener, slot); }
	inline void Application::onPostUpdate(const Listener & listener, const unsigned int slot) { this->lifecycle->onPostUpdate(listener, slot); }
	inline void Application::onPostRender(const Listener & listener, const unsigned int slot) { this->lifecycle->onPostRender(listener, slot); }
	inline void Application::onPreTerminate(const Listener & listener, const unsigned int slot) { this->lifecycle->onPreTerminate(listener, slot); }
	inline void Application::onPostTerminate(const Listener & listener, const unsigned int slot) { this->lifecycle->onPostTerminate(listener, slot); }

	inline const bool Application::isRunning() const { return this->running; }
}