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


#ifndef MODULE_MANAGER_HPP
#define MODULE_MANAGER_HPP

#include <vector>
#include <memory>

#include "core/module/module.hpp"

namespace ece
{
	class ModuleManager
	{
	public:
		ModuleManager() = default;
		ModuleManager(const ModuleManager & copy) = default;
		ModuleManager(ModuleManager && move) = default;

		~ModuleManager() = default;

		ModuleManager & operator=(const ModuleManager & copy) = default;
		ModuleManager & operator=(ModuleManager && move) = default;

		template <class T> T & add(const ModuleMethodHandle<T> & init = ModuleMethod<T>::VOID, const ModuleMethodHandle<T> & update = ModuleMethod<T>::VOID, const ModuleMethodHandle<T> & terminate = ModuleMethod<T>::VOID);
		template <class T> void remove();
		template <class T> T & get();

		void initAll();
		void updateAll();
		void terminateAll();

	private:
		std::vector<std::shared_ptr<BaseModule>> _modules;
	};
}

#include "core/module/module_manager.inl"

#endif // MODULE_MANAGER_HPP