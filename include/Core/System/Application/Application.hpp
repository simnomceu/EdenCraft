#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <memory>
#include <vector>

#include "Core\Window\Window\BaseWindow.hpp"

namespace ece
{
	class Application
	{
	public:
		Application();
		Application(const Application & copy) = delete;
		Application(Application && move) = delete;

		virtual ~Application() = 0;

		Application & operator=(const Application & copy) = delete;
		Application & operator=(Application && move) = delete;

		void run();
		void stop();

		void addWindow(const WindowSetting & setting);

	protected:
		virtual void render() = 0;
		virtual void update() = 0;
		virtual void processEvents() = 0;
		const bool isRunning() const;

		std::vector<std::unique_ptr<BaseWindow>> windows;
		bool running;

	private:
		void start();
	};
}

#endif // APPLICATION_HPP