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
				Copyright(C) 2017 Pierre Casati (@IsilinBN)

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

/**
 * @file utility/indexing/index3u.inl
 * @author IsilinBN (casa2pir@hotmail.fr)
 * @date January, 16th 2018
 * @copyright ----------
 * @brief A 3D index key.
 *
 */

namespace ece
{
	inline constexpr Index3u::Index3u() noexcept : _i(0), _j(0), _k(0) {}

	inline Index3u::Index3u(const int i, const int j, const int k) noexcept : _i(i), _j(j), _k(k) {}

	inline int Index3u::get(const int maxI, const int maxJ) noexcept { return this->_k * maxI * maxJ + this->_j * maxI + this->_i; }

	inline void Index3u::set(const int maxI, const int maxJ, const int index)
	{
		this->_k = index / (maxI * maxJ);
		this->_j = (index - this->_k * (maxI * maxJ)) / maxI;
		this->_i = index - (this->_j * maxI) - (this->_k * maxI * maxJ);
	}
}