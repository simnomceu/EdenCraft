namespace ece
{
	inline Application::Application() : running(false), argumentAnalyzer() {}

	inline Application::Application(int argc, char * argv[]) : running(false), argumentAnalyzer(argc, argv) {}

	inline Application::~Application() {}

	inline void Application::stop() { this->running = false; }

	inline ArgumentAnalyzer & Application::getArgumentAnalyzer() { return this->argumentAnalyzer; }

	inline void Application::render() {}

	inline void Application::update() {}

	inline void Application::processEvents() {}

	inline const bool Application::isRunning() const { return this->running; }
}