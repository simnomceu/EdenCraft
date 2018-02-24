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

#ifndef RESOURCE_MANAGER_HPP
#define RESOURCE_MANAGER_HPP

#include <map>
#include <string>
#include <memory>

#include "core/resource/resource_handler.hpp"
#include "core/resource/resource_loader.hpp"
#include "core/resource/resource_unloader.hpp"

namespace ece
{
	class ResourceManager
	{
	public:
		ResourceManager() = default;
		ResourceManager(const ResourceManager & copy) = delete;
		ResourceManager(ResourceManager && move) = default;

		~ResourceManager() = default;

		ResourceManager & operator=(const ResourceManager & copy) = delete;
		ResourceManager & operator=(ResourceManager && move) = default;

		void loadResource(const std::string & identifier);
		void loadResource(const std::string & identifier, const std::shared_ptr<ResourceLoader> & loader);
		void unloadResource(const std::string & identifier);
		void unloadResource(const std::string & identifier, const std::shared_ptr<ResourceUnloader> & unloader);

		std::weak_ptr<Resource> getResource(const std::string & identifier);

		void clear();

		void registerLoader(const std::string & extension, const std::shared_ptr<ResourceLoader> & loader);
		void registerUnloader(const std::string & extension, const std::shared_ptr<ResourceUnloader> & unloader);

	private:
		std::map<std::string, ResourceHandler> _resources;
		std::map<std::string, std::shared_ptr<ResourceLoader>> _loaders;
		std::map<std::string, std::shared_ptr<ResourceUnloader>> _unloaders;
	};
}

#endif // RESOURCE_MANAGER_HPP