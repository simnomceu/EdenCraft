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

#ifndef ENTITY_HANDLER_HPP
#define ENTITY_HANDLER_HPP

#include "core/config.hpp"

namespace ece
{
	namespace core
	{
		namespace ecs
		{
			class World;

			/**
			 * @class EntityHandler
			 * @brief
			 */
			class ECE_CORE_API EntityHandler
			{
			public:
				/**
				 * @fn constexpr EntityHandler() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				constexpr EntityHandler() noexcept = delete;

				inline EntityHandler(const unsigned int id, World & world) noexcept;

				/**
				 * @fn EntityHandler(const EntityHandler & copy) noexcept
				 * @param[in] copy The EntityHandler to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				EntityHandler(const EntityHandler & copy) noexcept = default;

				/**
				 * @fn EntityHandler(EntityHandler && move) noexcept
				 * @param[in] move The EntityHandler to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				EntityHandler(EntityHandler && move) noexcept = default;

				/**
				 * @fn ~EntityHandler() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~EntityHandler() noexcept = default;

				/**
				 * @fn EntityHandler & operator=(const EntityHandler & copy) noexcept
				 * @param[in] copy The EntityHandler to copy from.
				 * @return The EntityHandler copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				EntityHandler & operator=(const EntityHandler & copy) noexcept = default;

				/**
				 * @fn EntityHandler & operator=(EntityHandler && move) noexcept
				 * @param[in] move The EntityHandler to move.
				 * @return The EntityHandler moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				EntityHandler & operator=(EntityHandler && move) noexcept = default;

				inline unsigned int getId() const;

				template <class ComponentType, class ... Args> ComponentType & addComponent(Args&&... args);

				template <class ComponentType> bool HasComponent() const;

				template <class ComponentType> ComponentType & getComponent();

			private:
				unsigned int _id;

				World & _world;
			};
		} // namespace ecs
	} // namespace core
} // namespace ece

#include "core/ecs/entity_handler.inl"

#endif // ENTITY_HANDLER_HPP