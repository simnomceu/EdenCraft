#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <memory>
#include <vector>

#include "System\Argument\ArgumentAnalyzer.hpp"
#include "System\Module\ModuleManager.hpp"

namespace ece
{
	class Application
	{
	public:
		Application();
		Application(int argc, char * argv[]);
		Application(const Application & copy) = delete;
		Application(Application && move) = delete;

		inline ~Application();

		Application & operator=(const Application & copy) = delete;
		Application & operator=(Application && move) = delete;

		void run();
		inline void stop();

		inline ArgumentAnalyzer & getArgumentAnalyzer();

		template <class T> inline T & addModule(const ModuleMethodHandle<T> & init = ModuleMethod<T>::VOID, const ModuleMethodHandle<T> & update = ModuleMethod<T>::VOID, const ModuleMethodHandle<T> & terminate = ModuleMethod<T>::VOID);
		template <class T> inline void removeModule();
		template <class T> inline T & getModule();

	protected:
		inline virtual void onPreInit();
		inline virtual void onPostInit();
		inline virtual void onPreProcess();
		inline virtual void onPreUpdate();
		inline virtual void onPostUpdate();
		inline virtual void onPostRender();
		inline virtual void onPreTerminate();
		inline virtual void onPostTerminate();

		inline const bool isRunning() const;

		bool running;
		ModuleManager moduleManager;

	private:
		void init();
		void update();
		void processEvents();
		void render();
		void terminate();
	};
}

#include "System\Application\Application.inl"

#endif // APPLICATION_HPP