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

namespace ece
{
	inline Application::~Application() {}

	inline void Application::stop() { this->_running = false; }

	inline ArgumentAnalyzer & Application::getArgumentAnalyzer() { return this->getModule<ArgumentAnalyzer>(); }

	template <class T>
	inline T & Application::addModule(const ModuleMethodHandle<T> & init,
		const ModuleMethodHandle<T> & update,
		const ModuleMethodHandle<T> & terminate)
	{ return this->_moduleManager.add<T>(init, update, terminate); }

	template <class T>
	inline void Application::removeModule() { this->_moduleManager.remove<T>(); }

	template <class T>
	inline T & Application::getModule() { return this->_moduleManager.get<T>(); }

	inline void Application::onPreInit(const Listener & listener, const unsigned int slot) { this->_lifecycle->onPreInit(listener, slot); }
	inline void Application::onPostInit(const Listener & listener, const unsigned int slot) { this->_lifecycle->onPostInit(listener, slot); }
	inline void Application::onPreProcess(const Listener & listener, const unsigned int slot) { this->_lifecycle->onPreProcess(listener, slot); }
	inline void Application::onPreUpdate(const Listener & listener, const unsigned int slot) { this->_lifecycle->onPreUpdate(listener, slot); }
	inline void Application::onPostUpdate(const Listener & listener, const unsigned int slot) { this->_lifecycle->onPostUpdate(listener, slot); }
	inline void Application::onPostRender(const Listener & listener, const unsigned int slot) { this->_lifecycle->onPostRender(listener, slot); }
	inline void Application::onPreTerminate(const Listener & listener, const unsigned int slot) { this->_lifecycle->onPreTerminate(listener, slot); }
	inline void Application::onPostTerminate(const Listener & listener, const unsigned int slot) { this->_lifecycle->onPostTerminate(listener, slot); }

	inline const bool Application::isRunning() const { return this->_running; }
}