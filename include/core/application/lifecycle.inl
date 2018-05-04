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
	namespace core
	{
		namespace application
		{
			inline void Lifecycle::preInit() { this->emit(PRE_INIT); }

			inline void Lifecycle::postInit() { this->emit(POST_INIT); }

			inline void Lifecycle::preProcess() { this->emit(PRE_PROCESS); }

			inline void Lifecycle::preUpdate() { this->emit(PRE_UPDATE); }

			inline void Lifecycle::postUpdate() { this->emit(POST_UPDATE); }

			inline void Lifecycle::postRender() { this->emit(POST_RENDER); }

			inline void Lifecycle::preTerminate() { this->emit(PRE_TERMINATE); }

			inline void Lifecycle::postTerminate() { this->emit(POST_TERMINATE); }

			inline void Lifecycle::onPreInit(const Listener & listener, const unsigned int slot) { this->connect(PRE_INIT, listener, slot); }

			inline void Lifecycle::onPostInit(const Listener & listener, const unsigned int slot) { this->connect(POST_INIT, listener, slot); }

			inline void Lifecycle::onPreProcess(const Listener & listener, const unsigned int slot) { this->connect(PRE_PROCESS, listener, slot); }

			inline void Lifecycle::onPreUpdate(const Listener & listener, const unsigned int slot) { this->connect(PRE_UPDATE, listener, slot); }

			inline void Lifecycle::onPostUpdate(const Listener & listener, const unsigned int slot) { this->connect(POST_UPDATE, listener, slot); }

			inline void Lifecycle::onPostRender(const Listener & listener, const unsigned int slot) { this->connect(POST_RENDER, listener, slot); }

			inline void Lifecycle::onPreTerminate(const Listener & listener, const unsigned int slot) { this->connect(PRE_TERMINATE, listener, slot); }

			inline void Lifecycle::onPostTerminate(const Listener & listener, const unsigned int slot) { this->connect(POST_TERMINATE, listener, slot); }
		} // namespace application
	} // namespace core
} // namespace ece