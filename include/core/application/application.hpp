#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <memory>
#include <vector>

#include "argument\argument_analyzer.hpp"
#include "module\module_manager.hpp"
#include "event\emitter.hpp"
#include "application\lifecycle.hpp"

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

		inline void onPreInit(const Listener & listener, const unsigned int slot);
		inline void onPostInit(const Listener & listener, const unsigned int slot);
		inline void onPreProcess(const Listener & listener, const unsigned int slot);
		inline void onPreUpdate(const Listener & listener, const unsigned int slot);
		inline void onPostUpdate(const Listener & listener, const unsigned int slot);
		inline void onPostRender(const Listener & listener, const unsigned int slot);
		inline void onPreTerminate(const Listener & listener, const unsigned int slot);
		inline void onPostTerminate(const Listener & listener, const unsigned int slot);

	protected:
		inline const bool isRunning() const;

		bool running;
		ModuleManager moduleManager;

	private:
		void init();
		void update();
		void processEvents();
		void render();
		void terminate();

		std::shared_ptr<Lifecycle> lifecycle;
	};
}

#include "application\application.inl"

#endif // APPLICATION_HPP