#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <memory>
#include <vector>

#include "System\Argument\ArgumentAnalyzer.hpp"

namespace ece
{
	class Application
	{
	public:
		inline Application();
		inline Application(int argc, char * argv[]);
		Application(const Application & copy) = delete;
		Application(Application && move) = delete;

		inline ~Application();

		Application & operator=(const Application & copy) = delete;
		Application & operator=(Application && move) = delete;

		void run();
		inline void stop();

		inline ArgumentAnalyzer & getArgumentAnalyzer();

	protected:
		virtual void onInit();
		inline virtual void render();
		inline virtual void update();
		inline virtual void processEvents();
		inline const bool isRunning() const;

		bool running;
		ArgumentAnalyzer argumentAnalyzer;

	private:
		void start();
	};
}

#include "System\Application\Application.inl"

#endif // APPLICATION_HPP