/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

															  .oooooo.                                  oooo         o8o
															 d8P'  `Y8b                                 `888         `"'
															888           oooo d8b  .oooo.   oo.ooooo.   888 .oo.   oooo   .ooooo.
															888           `888""8P `P  )88b   888' `88b  888P"Y88b  `888  d88' `"Y8
															888     ooooo  888      .oP"888   888   888  888   888   888  888
															`88.    .88'   888     d8(  888   888   888  888   888   888  888   .o8
															 `Y8bood8P'   d888b    `Y888""8o  888bod8P' o888o o888o o888o `Y8bod8P'
																							  888
																							 o888o



				This file is part of EdenCraft Engine - Graphic module.
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

#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include "graphic/config.hpp"
#include "graphic/pch.hpp"
#include "core/resource.hpp"
#include "graphic/material/base_property.hpp"

namespace ece
{
	namespace renderer
	{
		namespace shader
		{
			class Shader;
		} // namespace shader
	} // namespace renderable

	namespace graphic
	{
		namespace material
		{
			using renderer::shader::Shader;

			/**
			 * @class Material
			 * @brief
			 */
			class ECE_GRAPHIC_API Material
			{
			public:
				using Reference = Resource<Material>;
				class Visitor;

				/**
				 * @fn Material()
				 * @brief Default constructor.
				 * @throw
				 */
				Material() = default;

				/**
				 * @fn Material(const Material & copy) noexcept
				 * @param[in] copy The Material to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				Material(const Material & copy) noexcept = default;

				/**
				 * @fn Material(Material && move) noexcept
				 * @param[in] move The Material to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				Material(Material && move) noexcept = default;

				/**
				 * @fn ~Material() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~Material() noexcept = default;

				/**
				 * @fn Material & operator=(const Material & copy) noexcept
				 * @param[in] copy The Material to copy from.
				 * @return The Material copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				Material & operator=(const Material & copy) noexcept = default;

				/**
				 * @fn Material & operator=(Material && move) noexcept
				 * @param[in] move The Material to move.
				 * @return The Material moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				Material & operator=(Material && move) noexcept = default;

				auto getProperties() -> std::vector<std::shared_ptr<BaseUniform>>;
				auto getProperty(const std::string name) -> std::shared_ptr<BaseProperty>;

				void addProperty(const std::string name, std::shared_ptr<BaseProperty> property);
				auto hasProperty(const std::string name) -> bool;
				void removeProperty(const std::string name);

				template <class T, typename enabled = std::enable_if_t<std::is_base_of_v<Visitor, T>>>
				auto isValid() const;

			protected:
				std::unordered_map<std::string, std::shared_ptr<BaseProperty>> _properties;
			};
		} // namespace material
	} // namespace graphic
} // namespace ece

#include "graphic/material/material.inl"

#endif // MATERIAL_HPP