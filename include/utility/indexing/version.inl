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
	template <unsigned short int level>
	inline Version<level>::Version(const std::initializer_list<unsigned short int> & il) noexcept: std::array<unsigned short int, level>() 
	{
		for (unsigned int i = 0; i < level; ++i) {
			(*this)[i] = *(il.begin() + i);
		}
	}

	template <unsigned short int level>
	bool Version<level>::operator==(const Version<level> & rhs) const noexcept
	{
		bool result = true;
		unsigned int i = 0;
		while (i < this->size() && result) {
			result = result && (*this)[i] == rhs[i];
			++i;
		}
		return result;
	}

	template <unsigned short int level>
	bool Version<level>::operator!=(const Version<level> & rhs) const noexcept
	{
		return !this->operator==(rhs);
	}

	template <unsigned short int level>
	bool Version<level>::operator<(const Version<level> & rhs) const noexcept
	{
		bool instantResult = (*this)[0] < rhs[0];
		bool result = (*this)[0] <= rhs[0];
		unsigned int i = 1;
		while (i < this->size() && result && !instantResult) {
			instantResult = instantResult || ((*this)[i] < rhs[i]);
			result = result && ((*this)[i] <= rhs[i]);
			++i;
		}
		return instantResult && i <= this->size();
	}

	template <unsigned short int level>
	bool Version<level>::operator<=(const Version<level> & rhs) const noexcept
	{
		bool instantResult = (*this)[0] < rhs[0];
		bool result = (*this)[0] <= rhs[0];
		unsigned int i = 1;
		while (i < this->size() && result && !instantResult) {
			instantResult = instantResult || ((*this)[i] < rhs[i]);
			result = result && ((*this)[i] <= rhs[i]);
			++i;
		}
		return (result || instantResult) && i <= this->size();
	}

	template <unsigned short int level>
	bool Version<level>::operator>(const Version<level> & rhs) const noexcept
	{
		bool instantResult = (*this)[0] > rhs[0];
		bool result = (*this)[0] >= rhs[0];
		unsigned int i = 1;
		while (i < this->size() && result && !instantResult) {
			instantResult = instantResult || ((*this)[i] > rhs[i]);
			result = result && ((*this)[i] >= rhs[i]);
			++i;
		}
		return instantResult && i <= this->size();
	}

	template <unsigned short int level>
	bool Version<level>::operator>=(const Version<level> & rhs) const noexcept
	{
		bool instantResult = (*this)[0] > rhs[0];
		bool result = (*this)[0] >= rhs[0];
		unsigned int i = 1;
		while (i < this->size() && result && !instantResult) {
			instantResult = instantResult || ((*this)[i] < rhs[i]);
			result = result && ((*this)[i] >= rhs[i]);
			++i;
		}
		return (result || instantResult) && i <= this->size();
	}

	template <unsigned short int level>
	Version<level> min(const Version<level> & lhs, const Version<level> & rhs) noexcept
	{
		return lhs <= rhs ? lhs : rhs;
	}

	template <unsigned short int level>
	Version<level> max(const Version<level> & lhs, const Version<level> & rhs) noexcept
	{
		return lhs >= rhs ? lhs : rhs;
	}
}