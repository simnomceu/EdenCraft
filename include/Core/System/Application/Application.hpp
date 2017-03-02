#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <memory>
#include <vector>

namespace ece
{
	class Application
	{
	public:
		inline Application();
		Application(const Application & copy) = delete;
		Application(Application && move) = delete;

		inline virtual ~Application() = 0;

		Application & operator=(const Application & copy) = delete;
		Application & operator=(Application && move) = delete;

		void run();
		inline void stop();

	protected:
		virtual void onInit() = 0;
		virtual void render() = 0;
		virtual void update() = 0;
		virtual void processEvents() = 0;
		inline const bool isRunning() const;

		bool running;

	private:
		void start();
	};
}

#include "System\Application\Application.inl"

#endif // APPLICATION_HPP