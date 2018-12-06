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

#ifndef BASE_PROPERTY_HPP
#define BASE_PROPERTY_HPP

#include "graphic/config.hpp"

#include <memory>
#include <string>
#include <functional>

namespace ece
{
	namespace renderer
	{
		namespace shader
		{
			class BaseUniform;
		} // namespace shader
	} // namespace renderer

	namespace graphic
	{
		namespace material
		{
			using renderer::shader::BaseUniform;

			/**
			 * @class BaseProperty
			 * @brief
			 */
			class ECE_GRAPHIC_API BaseProperty
			{
			public:
				/**
				 * @fn constexpr BaseProperty() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				inline BaseProperty() noexcept;

				/**
				 * @fn BaseProperty(const BaseProperty & copy) noexcept
				 * @param[in] copy The BaseProperty to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				BaseProperty(const BaseProperty & copy) noexcept = default;

				/**
				 * @fn BaseProperty(BaseProperty && move) noexcept
				 * @param[in] move The BaseProperty to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				BaseProperty(BaseProperty && move) noexcept = default;

				/**
				 * @fn ~BaseProperty() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~BaseProperty() noexcept = default;

				/**
				 * @fn BaseProperty & operator=(const BaseProperty & copy) noexcept
				 * @param[in] copy The BaseProperty to copy from.
				 * @return The BaseProperty copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				BaseProperty & operator=(const BaseProperty & copy) noexcept = default;

				/**
				 * @fn BaseProperty & operator=(BaseProperty && move) noexcept
				 * @param[in] move The BaseProperty to move.
				 * @return The BaseProperty moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				BaseProperty & operator=(BaseProperty && move) noexcept = default;

				virtual std::shared_ptr<BaseUniform> getUniform(std::string name) = 0;

				inline void enable(bool enabled) noexcept;
				inline bool isEnabled() const noexcept;

			private:
				bool _enabled;
			};
		} // namespace material
	} // namespace graphic
} // namespace model

#include "graphic/material/base_property.inl"

#endif // BASE_PROPERTY_HPP