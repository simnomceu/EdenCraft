/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .   
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8   
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo 
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888   
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888   
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 . 
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888" 

															  .oooooo.                                
															 d8P'  `Y8b                               
															888           .ooooo.  oooo d8b  .ooooo.  
															888          d88' `88b `888""8P d88' `88b 
															888          888   888  888     888ooo888 
															`88b    ooo  888   888  888     888    .o 
															 `Y8bood8P'  `Y8bod8P' d888b    `Y8bod8P' 
                                          
                                          

				This file is part of EdenCraft Engine - Core module.
				Copyright(C) 2018 Pierre Casati (@IsilinBN)

				This program is free software : you can redistribute it and/or modify
				it under the terms of the GNU General Public License as published by
				the Free Software Foundation, either version 3 of the License, or
				(at your option) any later version.

				This program is distributed in the hope that it will be useful,
				but WITHOUT ANY WARRANTY; without even the implied warranty of
				MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
				GNU General Public License for more details.

				You should have received a copy of the GNU General Public License
				along with this program.If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <memory>
#include <vector>

#include "core/argument/argument_analyzer.hpp"
#include "core/module/module_manager.hpp"
#include "core/event/emitter.hpp"
#include "core/application/lifecycle.hpp"

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

		bool _running;
		ModuleManager _moduleManager;

	private:
		void init();
		void update();
		void processEvents();
		void render();
		void terminate();

		std::shared_ptr<Lifecycle> _lifecycle;
	};
}

#include "core/application/application.inl"

#endif // APPLICATION_HPP