namespace ece
{
	inline Application::Application() : running(false), moduleManager() {}

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

	inline void Application::onPreInit() {}
	inline void Application::onPostInit() {}
	inline void Application::onPreProcess() {}
	inline void Application::onPreUpdate() {}
	inline void Application::onPostUpdate() {}
	inline void Application::onPostRender() {}
	inline void Application::onPreTerminate() {}
	inline void Application::onPostTerminate() {}

	inline const bool Application::isRunning() const { return this->running; }
}