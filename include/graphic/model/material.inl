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

#include <algorithm>

namespace ece
{
	namespace graphic
	{
		namespace model
		{
/*			inline std::vector<std::shared_ptr<BaseUniform>> & Material::getProperties() { return this->_properties;}

			template <class T>
			std::shared_ptr<Uniform<T>> Material::getProperty(const std::string name)
			{
				if (this->hasProperty<T>(name)) {
					return std::static_pointer_cast<Uniform<T>>(*std::find_if(this->_properties.begin(), this->_properties.end(), [name](auto element) { return element->getName() == name; }));
				}
				else {
					return nullptr;
				}
			}

			template <class T>
			bool Material::hasProperty(const std::string name)
			{
				auto element = std::find_if(this->_properties.begin(), this->_properties.end(), [name](auto element) { return element->getName() == name; });
				if (element == this->_properties.end()) {
					return false;
				}
				
				auto cast = std::dynamic_pointer_cast<Uniform<T>>(*element);
				return !!cast;
			}

			template <class T>
			void Material::setProperty(const std::string name, T value)
			{
				auto property = this->getProperty<T>(name);
				if (property) {
					property->setData(value);
				}
			}*/
		} // namespace model
	} // namespace graphic
} // namespace ece