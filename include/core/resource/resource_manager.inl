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

#include "core/resource/resource_container.hpp"

namespace ece
{
	namespace core
	{
		namespace resource
		{

			template <class T, class... Args>
			void ResourceManager::loadResource(const std::string & identifier, Args&&... args)
			{
				if (!this->hasResource<T>(identifier)) {
					auto containerId = typeid(T).hash_code();
					if (this->_containers.find(containerId) == this->_containers.end()) {
						this->_containers[containerId] = std::make_shared<ResourceContainer<T>>();
					}
					std::static_pointer_cast<ResourceContainer<T>>(this->_containers[containerId])->add(identifier, std::make_shared<T>(std::forward<Args>(args)...));
				}
			}

			template <class T>
			void ResourceManager::unloadResource(const std::string & identifier)
			{
				auto containerId = typeid(T).hash_code();
				if (this->_containers.find(containerId) != this->_containers.end()) {
					auto id = this->_containers[containerId]->getResourceId(identifier);
					this->_containers[containerId]->remove(id);
				}
			}

			template <class T>
			auto ResourceManager::getResource(ece::size_t id) -> std::weak_ptr<T>
			{
				return std::static_pointer_cast<ResourceContainer<T>>(this->_containers[typeid(T).hash_code()])->getResource(id);
			}

			template <class T>
			auto ResourceManager::getResourceId(const std::string & identifier) -> ece::size_t
			{
				auto containerId = typeid(T).hash_code();
				return this->_containers[containerId]->getResourceId(identifier);
			}

			template <class T>
			auto ResourceManager::hasResource(const std::string & identifier) -> bool
			{
				auto containerId = typeid(T).hash_code();
				if (this->_containers.find(containerId) == this->_containers.end()) {
					return false;
				}
				auto id = this->_containers[containerId]->getResourceId(identifier);
				return this->_containers[containerId]->isResourceLoaded(id);
			}
		} // namespace resource
	} // namespace core
} // namespace ece