namespace ece
{
	inline Application::Application() : running(false) {}

	inline Application::~Application() {}

	void Application::stop() { this->running = false; }

	const bool Application::isRunning() const { return this->running; }
}