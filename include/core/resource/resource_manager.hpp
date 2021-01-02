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

#include "core/config.hpp"
#include "core/pch.hpp"
#include "utility/types.hpp"
#include "core/resource/base_resource_container.hpp"

namespace ece
{
	namespace core
	{
		namespace resource
		{
			class ResourceHandler;

			/**
			 * @class ResourceManager
			 * @brief Manage all resources, and their loaders/unloaders, regarding the file extension.
			 */
			class ECE_CORE_API ResourceManager
			{
			public:
				/**
				 * @fn ResourceManager()
				 * @brief Default constructor.
				 * @throw
				 */
				ResourceManager() = default;

				ResourceManager(const ResourceManager & copy) = delete;

				/**
				 * @fn ResourceManager(ResourceManager && move)
				 * @param[in] move The manger to move.
				 * @brief Default move constructor.
				 * @throw
				 */
				ResourceManager(ResourceManager && move) noexcept = default;

				/**
				 * @fn ~ResourceManager() noexcept
				 * @brief Default destructor.
				 */
				~ResourceManager() noexcept = default;

				ResourceManager & operator=(const ResourceManager & copy) = delete;

				/**
				 * @fn ResourceManager & operator=(ResourceManager && move)
				 * @param[in] move The manger to move.
				 * @return The manager moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				ResourceManager & operator=(ResourceManager && move) noexcept = default;

				/**
				 * @fn void loadResource(const std::string & identifier)
				 * @param[in] identifier The string that identify a resource. Usually it is the filename of the resource.
				 * @brief Load a resource, using its identifier.
				 * If a resource with this identifier already exist, nothing happen.
				 * @throw
				 */
				template <class T, class... Args>
				void loadResource(const std::string & identifier, Args&&... args);

				/**
				 * @fn void unloadResource(const std::string & identifier)
				 * @param[in] identifier The string that identify a resource. Usually, it is the filename of the resource.
				 * @brief Unload a resource using its identfier.
				 * If the resource with this identifier does not exist, nothing happen.
				 */
				template <class T>
				void unloadResource(const std::string & identifier);

				template <class T>
				auto getResource(ece::size_t id) -> std::weak_ptr<T>;

				template <class T>
				auto getResourceId(const std::string & identifier) -> ece::size_t;

				template <class T>
				auto hasResource(const std::string & identifier) -> bool;

				/**
				 * @fn void clear()
				 * @brief Clear the maanger, to delete all resources, loaders, and unloaders.
				 * @throw
				 */
				void clear();

			private:
				/**
				 * @property _resources
				 * @brief The list of resources currently loaded.
				 */
				std::map<std::size_t, std::shared_ptr<BaseResourceContainer>> _containers;
			};
		} // namespace resource
	} // namespace core
} // namespace ece

#include "core/resource/resource_manager.inl"

#endif // RESOURCE_MANAGER_HPP