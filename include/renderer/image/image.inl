/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .   
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8   
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo 
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888   
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888   
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 . 
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888" 

															ooooooooo.                               .o8                                        
															`888   `Y88.                            "888                                        
															 888   .d88'  .ooooo.  ooo. .oo.    .oooo888   .ooooo.  oooo d8b  .ooooo.  oooo d8b 
															 888ooo88P'  d88' `88b `888P"Y88b  d88' `888  d88' `88b `888""8P d88' `88b `888""8P 
															 888`88b.    888ooo888  888   888  888   888  888ooo888  888     888ooo888  888     
															 888  `88b.  888    .o  888   888  888   888  888    .o  888     888    .o  888     
															o888o  o888o `Y8bod8P' o888o o888o `Y8bod88P" `Y8bod8P' d888b    `Y8bod8P' d888b   
                                                                       
                                          
                                     
				This file is part of EdenCraft Engine - Renderer module.
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
#include "image.hpp"

namespace ece
{
	template<class E>
	inline constexpr Image<E>::Image() noexcept: Dynamic2DArray<E>(0, 0) {}

	template<class E>
	void Image<E>::flipHorizontally()
	{
		for (size_t j = 0; j < this->_height; ++j) {
			for (size_t i = 0; i < this->_width / 2; ++i) {
				std::swap(this->_buffer[j][i], this->_buffer[j][this->_width - 1 - i]);
			}
		}
	}

	template<class E>
	void Image<E>::flipVertically()
	{
		for (size_t j = 0; j < this->_height / 2; ++j) {
			for (size_t i = 0; i < this->_width; ++i) {
				std::swap(this->_buffer[j][i], this->_buffer[this->_height - 1 - j][i]);
			}
		}
	}

	template<class E>
	void Image<E>::rotateOnRight()
	{
		Dynamic2DArray<E> dirty(this->_buffer);

		this->_buffer.resize(dirty.getHeight(), dirty.getWidth());
		for (size_t j = 0; j < dirty.getHeight(); ++j) {
			for (size_t i = 0; i < dirty.getWidth(); ++i) {
				this->_buffer[i][this->_width - 1 - j] = dirty[j][i];
			}
		}
	}

	template<class E>
	void Image<E>::rotateOnLeft()
	{
		Dynamic2DArray<E> dirty(this->_buffer);

		this->_buffer.resize(dirty.getHeight(), dirty.getWidth());
		for (size_t j = 0; j < dirty.getHeight(); ++j) {
			for (size_t i = 0; i < dirty.getWidth(); ++i) {
				this->_buffer[this->height - 1 - i][j] = dirty[j][i];
			}
		}
	}
}