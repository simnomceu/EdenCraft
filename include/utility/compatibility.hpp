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

#ifndef UTILITY_CONFIGURATIONS_HPP
#define UTILITY_CONFIGURATIONS_HPP

#if __cplusplus >= 199711L || _MSC_VER > 1200 // C++98
#endif
#if __cplusplus >= 201103L  || _MSC_VER >= 1700  // C++11
#	define CONSTEXPR_SPECIFIER
#	define POINTER_LITERAL
#	define NOEXCEPT_SPECIFIER
#	define DEFAULT_INIT
#	define AUTO_SPECIFIER
#	define UNORDERED_CONTAINER
#endif
#if __cplusplus >= 201402L || _MSC_VER >= 1900 // C++14
#endif
#if __cplusplus >= 201703L || _MSC_VER >= 1900 // C++17
#endif
#if __cplusplus > 201703L || _MSC_VER >= 1910 // experimental
#endif

#ifndef CONSTEXPR_SPECIFIER
#	define constexpr 
#endif

#ifndef POINTER_LITERAL
#	define nullptr NULL
#endif

#ifndef NOEXCEPT_SPECIFIER
#	define noexcept throw()
#endif

#ifndef DEFAULT_INIT
#endif

#ifndef AUTO_SPECIFIER
#endif

#ifndef UNORDERED_CONTAINER
#	define unordered_map map
#	define unordered_set set
#	define unordered_multimap multimap
#	define unordered_multiset multiset
#endif

#ifdef _MSC_VER
#	undef min
#	undef max
#endif

#endif // UTILITY_CONFIGURATIONS_HPP