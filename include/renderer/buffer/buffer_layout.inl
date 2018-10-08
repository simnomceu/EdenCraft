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

namespace ece
{
    namespace renderer
    {
        namespace buffer
        {
			inline BufferLayout::BufferLayout(const BufferLayout::Strategy strategy) noexcept: _elements(), _instanceBlockSize(0), _strategy(strategy) {}

            template <class T>
            void BufferLayout::add(const std::size_t size, const bool normalized, const bool ignored, const bool instanced)
            {
				const auto index = this->_elements.size();
				this->_elements.push_back({ OpenGL::dataType<T>(),
											sizeof(T),
											size,
											(index == 0 || this->_strategy == Strategy::CONCATENATED) ? 0 : this->_elements[index - 1]._offset + this->_elements[index - 1]._unitSize * this->_elements[index - 1]._count,
											normalized,
											ignored,
											instanced });
            }

            inline BufferLayout::ElementLayout & BufferLayout::getElement(const std::size_t index) { return this->_elements[index]; }

            inline const BufferLayout::ElementLayout & BufferLayout::getElement(const std::size_t index) const { return this->_elements[index]; }

            inline std::size_t BufferLayout::size() const { return this->_elements.size(); }

			inline void BufferLayout::setInstanceBlockSize(const std::size_t size) noexcept { this->_instanceBlockSize = size; }

			inline std::size_t BufferLayout::getInstanceBlockSize() const noexcept { return this->_instanceBlockSize; }

			inline BufferLayout::Strategy BufferLayout::getStrategy() const noexcept { return this->_strategy; }
        } // namespace buffer
    } // namespace renderer
} // namespace ece
