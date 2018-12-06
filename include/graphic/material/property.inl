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

#include "utility/container.hpp"
#include "renderer/shader/uniform.hpp"

namespace ece
{
	namespace graphic
	{
		namespace material
		{
			using renderer::shader::Uniform;

			template <class T, class U>
			Property<T, U>::Property(T value, Function computedValue) : _value(std::move(value)), _computedValue(std::move(computedValue))
			{
			}

			template <class T, class U>
			std::shared_ptr<BaseUniform> Property<T, U>::getUniform(std::string name)
			{
				if constexpr (is_container_v<U>) {
					return std::make_shared<Uniform<std::tuple_element_t<0, U>, std::tuple_size_v<U>>>(name, this->_computedValue(this->_value));
				}
				else {
					return std::make_shared<Uniform<U>>(name, this->_computedValue(this->_value));
				}
			}

			template <class T, class U>
			Property<T, U> & Property<T, U>::operator=(const T & value)
			{
				this->_value = value;
				return *this;
			}

			template <class T, class U>
			Property<T, U> & Property<T, U>::operator=(T && value)
			{
				this->_value = value;
				return *this;
			}

			template <class T, class U>
			inline T & Property<T, U>::get() { return this->_value; }

			template <class T, class U>
			inline const T & Property<T, U>::get() const { return this->_value; }
		} // namespace material
	} // namespace graphic
} // namespace model