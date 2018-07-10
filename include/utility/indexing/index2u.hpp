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

#ifndef INDEX2U_HPP
#define INDEX2U_HPP

#include "utility/config.hpp"

namespace ece
{
    namespace utility
    {
        namespace indexing
        {
        	/**
        	 * @class Index2u
        	 * @brief A 2D index key to access elements in a 2D container.
        	 * @remark This class need to be refactored to be usable in others classes like Matrix. Have to be compared with std::slice and others.
        	 */
        	class ECE_UTILITY_API Index2u
        	{
        	public:
        		/**
        		 * @fn Index2u()
        		 * @brief Default constructor.
        		 * @throw noexcept
        		 * It initializes the index to (0, 0).
        		 */
        		inline constexpr Index2u() noexcept;

        		/**
        		 * @fn Index2u(const int i, const int j)
        		 * @param[in] i The i position of the index.
        		 * @param[in] j The j position of the index.
        		 * @brief Build a 2d index key and set the position to (i, j).
        		 * @throw noexcept
        		 */
        		inline Index2u(const int i, const int j) noexcept;

        		/**
        		 * @fn Index2u(const Index2u & copy)
        		 * @param[in] copy The index to copy from.
        		 * @brief Default copy constructor.
        		 * @throw noexcept
        		 */
        		Index2u(const Index2u & copy) noexcept = default;

        		/**
        		 * @fn Index2u(Index2u && move)
        		 * @param[in] move The index to move from.
        		 * @brief Default move constructor.
        		 * @throw noexcept
        		 */
        		Index2u(Index2u && move) noexcept = default;

        		/**
        		 * @fn ~Index2u()
        		 * @brief Default destructor.
        		 * @throw noexcept
        		 */
        		~Index2u() noexcept = default;

        		/**
        		 * @fn Index2u & operator=(const Index2u & copy)
        		 * @param[in] copy The index to copy from.
        		 * @return The 2D index copied.
        		 * @brief Default copy assignment operator.
        		 * @throw noexcept
        		 */
        		Index2u & operator=(const Index2u & copy) noexcept = default;

        		/**
        		 * @fn Index2u & operator=(Index2u && move)
        		 * @param[in] move The index to move from.
        		 * @return The 2D index moved.
        		 * @brief Default move assignment operator.
        		 * @throw noexcept
        		 */
        		Index2u & operator=(Index2u && move) noexcept = default;

        		/**
        		 * @fn int get(const int maxI)
        		 * @param[in] maxI Max length of a row.
        		 * @return The 1D position
        		 * @brief Get the 1D position considering the max length of a row.
        		 * @throw noexcept
        		 */
        		inline int get(const int maxI) noexcept;

        		/**
        		 * @fn void set(const int maxI, const int index)
        		 * @param[in] maxI Max length of a row
        		 * @param[in] index 1D index to set.
        		 * @brief Convert a 1D position to a 2D position, considering the max length of a row.
        		 * @throw A division_by_zero exception if the max length is equal to 0.
        		 */
        		inline void set(const int maxI, const int index);

        		/**
        		 * @property _i
        		 * @brief The i position (usually on X-axis) of the index in 2D.
        		 */
        		unsigned int _i;

        		/**
        		 * @property _j
        		 * @brief The j position (usually on Y-axis) of the index in 2D.
        		 */
        		unsigned int _j;
        	};
        } // namespace indexing
    } // namespace utility
} // namespace ece

#include "utility/indexing/index2u.inl"

#endif // INDEX2U_HPP
