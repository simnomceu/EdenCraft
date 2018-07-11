/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

															ooooo     ooo     .    o8o  oooo   o8o      .
															`888'     `8'   .o8    `"'  `888   `"'    .o8
															 888       8  .o888oo oooo   888  oooo  .o888oo oooo    ooo
															 888       8    888   `888   888  `888    888    `88.  .8'
															 888       8    888    888   888   888    888     `88..8'
															 `88.    .8'    888 .  888   888   888    888 .    `888'
															   `YbodP'      "888" o888o o888o o888o   "888"     .8'
																											.o..P'
																											`Y8P'

				This file is part of EdenCraft Engine - Utility module.
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
	namespace utility
	{
		namespace indexing
		{
			template <class E>
			Dynamic2DArray<E>::Dynamic2DArray(const size_t width, const size_t height) : _buffer(new E[width * height]()), _width(width), _height(height)
			{
				for (size_t i = 0; i < this->_width * this->_height; ++i) {
					this->_buffer[i] = E();
				}
			}

			template<class E>
			Dynamic2DArray<E>::Dynamic2DArray(const Dynamic2DArray<E>& copy) noexcept: _buffer(new E[copy.getWidth() * copy.getHeight()]()), _width(copy.getWidth()), _height(copy.getHeight())
			{
				for (size_t j = 0; j < this->_height; ++j) {
					for (size_t i = 0; i < this->_width; ++i) {
						this->_buffer[j * this->_width + i] = copy[j][i];
					}
				}
			}

			template<class E>
			inline Dynamic2DArray<E>::~Dynamic2DArray() noexcept { delete[] this->_buffer; }

			template<class E>
			inline Dynamic2DArray<E>& Dynamic2DArray<E>::operator=(const Dynamic2DArray<E>& copy) noexcept
			{
				this->_width = copy.getWidth();
				this->_height = copy.getHeight();
				for (size_t j = 0; j < this->_height; ++j) {
					for (size_t i = 0; i < this->_width; ++i) {
						this->_buffer[j * this->_width + i] = copy[j][i];
					}
				}
				return *this;
			}

			template <class E>
			inline E * Dynamic2DArray<E>::operator[](const size_t index) { return this->_buffer + (index * this->_width); }

			template <class E>
			inline const E * Dynamic2DArray<E>::operator[](const size_t index) const { return this->_buffer + (index * this->_width); }

			template<class E>
			inline E * Dynamic2DArray<E>::data() noexcept { return this->_buffer; }

			template<class E>
			inline const E * Dynamic2DArray<E>::data() const noexcept { return this->_buffer; }

			template<class E>
			inline size_t Dynamic2DArray<E>::getWidth() const noexcept { return this->_width; }

			template<class E>
			inline size_t Dynamic2DArray<E>::getHeight() const noexcept { return this->_height; }

			template<class E>
			void Dynamic2DArray<E>::resize(const size_t width, const size_t height)
			{
				auto dirtyBuffer = this->_buffer;

				this->_buffer = new E[width * height]();
				for (size_t i = 0; i < height; ++i) {
					for (size_t j = 0; j < width; ++j) {
						if (i >= this->_height || j >= this->_width) {
							this->_buffer[j + i * width] = E();
						}
						else {
							this->_buffer[j + i * width] = dirtyBuffer[j + i * width];
						}
					}
				}
				
				this->_width = width;
				this->_height = height;
				delete[] dirtyBuffer;
			}
		} // namespace indexing
	} // namespace utility
} // namespace ece
