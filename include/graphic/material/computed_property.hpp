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

#ifndef COMPUTED_PROPERTY_HPP
#define COMPUTED_PROPERTY_HPP

#include "graphic/config.hpp"
#include "graphic/pch.hpp"
#include "graphic/material/base_property.hpp"

namespace ece
{
	namespace graphic
	{
		namespace material
		{
			/**
			 * @class Property
			 * @brief
			 */
			template <class T>
			class ECE_GRAPHIC_API ComputedProperty final: public BaseProperty
			{
			public:
				using Function = std::function<T()>;

				ComputedProperty(Function computedValue);

				/**
				 * @fn Property(const Property & copy)
				 * @param[in] copy The Property to copy from.
				 * @brief Default copy constructor.
				 * @throw
				 */
				ComputedProperty(const ComputedProperty<T> & copy) = default;

				/**
				 * @fn Property(Property && move)
				 * @param[in] move The Property to move.
				 * @brief Default move constructor.
				 * @throw
				 */
				ComputedProperty(ComputedProperty<T> && move) = default;

				/**
				 * @fn ~Property() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~ComputedProperty() noexcept = default;

				/**
				 * @fn Property & operator=(const Property & copy)
				 * @param[in] copy The Property to copy from.
				 * @return The Property copied.
				 * @brief Default copy assignment operator.
				 * @throw
				 */
				ComputedProperty<T> & operator=(const ComputedProperty<T> & copy) = default;

				/**
				 * @fn Property & operator=(Property && move)
				 * @param[in] move The Property to move.
				 * @return The Property moved.
				 * @brief Default move assignment operator.
				 * @throw
				 */
				ComputedProperty<T> & operator=(ComputedProperty<T> && move) = default;

				virtual std::shared_ptr<BaseUniform> getUniform(std::string name) override;

			private:
				Function _computedValue;
			};

			template <class T>
			ECE_GRAPHIC_API auto makeComputedProperty(typename ComputedProperty<T>::Function computed = []() -> T { return T(); }) {
				return std::make_shared<ComputedProperty<T>>(std::forward<typename ComputedProperty<T>::Function>(computed));
			}
		} // namespace material
	} // namespace graphic
} // namespace model

#include "graphic/material/computed_property.inl"

#endif // COMPUTED_PROPERTY_HPP