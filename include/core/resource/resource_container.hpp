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

#ifndef RESOURCE_CONTAINER_HPP
#define RESOURCE_CONTAINER_HPP

#include "core/config.hpp"
#include "core/pch.hpp"
#include "core/resource/base_resource_container.hpp"

namespace ece
{
	namespace core
	{
		namespace resource
		{
			template <class Resource>
			class ResourceHandler;

			/**
			 * @class ResourceContainer
			 * @brief
			 */
			template <class Resource>
			class ECE_CORE_API ResourceContainer: public BaseResourceContainer
			{
			public:
				/**
				 * @fn constexpr ResourceContainer()
				 * @brief Default constructor.
				 * @throw
				 */
				constexpr ResourceContainer()= default;

				/**
				 * @fn ResourceContainer(const ResourceContainer & copy) noexcept
				 * @param[in] copy The ResourceContainer to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				ResourceContainer(const ResourceContainer & copy) noexcept = default;

				/**
				 * @fn ResourceContainer(ResourceContainer && move) noexcept
				 * @param[in] move The ResourceContainer to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				ResourceContainer(ResourceContainer && move) noexcept = default;

				/**
				 * @fn ~ResourceContainer() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~ResourceContainer() noexcept = default;

				/**
				 * @fn ResourceContainer & operator=(const ResourceContainer & copy) noexcept
				 * @param[in] copy The ResourceContainer to copy from.
				 * @return The ResourceContainer copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				ResourceContainer & operator=(const ResourceContainer & copy) noexcept = default;

				/**
				 * @fn ResourceContainer & operator=(ResourceContainer && move) noexcept
				 * @param[in] move The ResourceContainer to move.
				 * @return The ResourceContainer moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				ResourceContainer & operator=(ResourceContainer && move) noexcept = default;

				void add(const std::string & identifier, const std::shared_ptr<Resource> & resource);
				void add(const std::vector<std::pair<std::string, std::shared_ptr<Resource>>> & resources);

				virtual void remove(const std::string & key) override;
				virtual void remove(const std::vector<std::string> & keys) override;

				inline virtual void clear() override;

				auto getResource(const std::string & key);

			private:
				struct ResourceWrapper
				{
					std::shared_ptr<Resource> content;

					std::chrono::time_point<std::chrono::system_clock> created;
					std::chrono::time_point<std::chrono::system_clock> lastAccess;

					bool dirty;
				};

				std::unordered_map<std::string, ResourceWrapper> _resources;
			};
		} // namespace resource
	} // namespace core
} // namespace ece

#include "core/resource/resource_container.inl"

#endif // RESOURCE_CONTAINER_HPP