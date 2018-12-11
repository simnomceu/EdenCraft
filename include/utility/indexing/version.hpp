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

#ifndef VERSION_HPP
#define VERSION_HPP

#ifdef _MSC_VER
#	undef min
#	undef max
#endif

#include "utility/config.hpp"
#include "utility/pch.hpp"

namespace ece
{
    namespace utility
    {
        namespace indexing
        {
        	/**
        	 * @class Version
        	 * @tparam level The level of versionning accuracy wished.
        	 * @brief Define a type of version, with some useful operation, like comparison.
        	 * Level of versionning defines if you want version to be represented like X.X or X.X.X or X.X.X.X, etc ...
        	 */
        	template <unsigned short int level>
        	class ECE_UTILITY_API Version: protected std::array<unsigned short int, level>
        	{
        	public:

        		/**
        		 * @fn Version() noexcept
        		 * @brief Default constructor. The version is initialized with all levels set to 0.
        		 * @throw noexcept
        		 */
        		Version() noexcept = default;

        		/**
        		 * @fn Version(const std::initializer_list<unsigned short int> & il) noexcept
        		 * @param[in] il The list to set.
        		 * @brief Constructor from a list of values.
        		 * If the size of the list is not the size of the object, the behaviour is undefined.
        		 * @throw noexcept
        		 */
        		inline Version(const std::initializer_list<unsigned short int> & il) noexcept;

        		/**
        		 * @fn Version(const Version<level> & copy) noexcept
        		 * @param[in] copy The version to copy from.
        		 * @brief Default copy constructor.
        		 * @throw noexcept
        		 */
        		Version(const Version<level> & copy) noexcept = default;

        		/**
        		 * @fn Version(Version<level> && move) noexcept
        		 * @param[in] move The version to move.
        		 * @brief Default move constructor.
        		 * @throw noexcept
        		 */
        		Version(Version<level> && move) noexcept = default;

        		/**
        		 * @fn ~Version() noexcept
        		 * @brief Default destructor.
        		 * @throw noexcept
        		 */
        		~Version() noexcept = default;

        		/**
        		 * @fn Version<level> & operator=(const Version<level> & copy) noexcept
        		 * @param[in] copy The version to copy from.
        		 * @return The version copied.
        		 * @brief Default copy assignment operator.
        		 * @throw noexcept
        		 */
        		Version<level> & operator=(const Version<level> & copy) noexcept = default;

        		/**
        		 * @fn Version<level> & operator=(const Version<level> & copy) noexcept
        		 * @param[in] copy The version to move.
        		 * @return The version moved.
        		 * @brief Default copy assignment operator.
        		 * @throw noexcept
        		 */
        		Version<level> & operator=(Version<level> && move) noexcept = default;

        		/**
        		 * @fn bool operator==(const Version<level> & rhs) const noexcept
        		 * @param[in] rhs The right hand side to compare.
        		 * @return True if they are both equal, false else.
        		 * @brief Compare if the both versions are equal or not.
        		 * @throw noexcept
        		 */
        		bool operator==(const Version<level> & rhs) const noexcept;

        		/**
        		 * @fn bool operator!=(const Version<level> & rhs) const noexcept
        		 * @param[in] rhs The right hand side to compare.
        		 * @return True if they are both different, false else.
        		 * @brief Compare if the both versions are different or not.
        		 * @throw noexcept
        		 */
        		bool operator!=(const Version<level> & rhs) const noexcept;

        		/**
        		 * @fn bool operator<(const Version<level> & rhs) const noexcept
        		 * @param[in] rhs The right hand side to compare.
        		 * @return True if this version is lower than the other, false else.
        		 * @brief Compare if this version is lower than the other or not.
        		 * @throw noexcept
        		 */
        		bool operator<(const Version<level> & rhs) const noexcept;

        		/**
        		 * @fn bool operator<=(const Version<level> & rhs) const noexcept
        		 * @param[in] rhs The right hand side to compare.
        		 * @return True if this version is lower than or equal to the other, false else.
        		 * @brief Compare if this version is lower than or equal to the other or not.
        		 * @throw noexcept
        		 */
        		bool operator<=(const Version<level> & rhs) const noexcept;

        		/**
        		 * @fn bool operator>(const Version<level> & rhs) const noexcept
        		 * @param[in] rhs The right hand side to compare.
        		 * @return True if this version is greater than the other, false else.
        		 * @brief Compare if this version is greater than the other or not.
        		 * @throw noexcept
        		 */
        		bool operator>(const Version<level> & rhs) const noexcept;

        		/**
        		 * @fn bool operator>=(const Version<level> & rhs) const noexcept
        		 * @param[in] rhs The right hand side to compare.
        		 * @return True if this version is greater than or equal to the other, false else.
        		 * @brief Compare if this version is greater than or equal to the other or not.
        		 * @throw noexcept
        		 */
        		bool operator>=(const Version<level> & rhs) const noexcept;

        		/**
        		 * @see http://en.cppreference.com/w/cpp/container/array/operator_at
        		 */
        		using std::array<unsigned short int, level>::operator[];
        	};

        	/**
        	 * @fn Version<level> min(const Version<level> & lhs, const Version<level> & rhs)
        	 * @tparam level The level of versionning accuracy wished.
        	 * @param[in] The left hand side to compare.
        	 * @param[in]The right hand side to compare.
        	 * @return The left hand side if it is the lowest, the right hand side else.
        	 * @brief Get the lowest of both versions.
        	 * @throw noexcept
        	 */
        	template <unsigned short int level>
        	Version<level> min(const Version<level> & lhs, const Version<level> & rhs) noexcept;

        	/**
        	 * @fn Version<level> max(const Version<level> & lhs, const Version<level> & rhs)
        	 * @tparam level The level of versionning accuracy wished.
        	 * @param[in] The left hand side to compare.
        	 * @param[in]The right hand side to compare.
        	 * @return The left hand side if it is the greatest, the right hand side else.
        	 * @brief Get the greatest of both versions.
        	 * @throw noexcept
        	 */
        	template <unsigned short int level>
        	Version<level> max(const Version<level> & lhs, const Version<level> & rhs) noexcept;
        } // namespace indexing
    } // namespace utility
} // namespace ece

#include "utility/indexing/version.inl"

#endif // VERSION_HPP
