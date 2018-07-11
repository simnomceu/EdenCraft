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

#ifndef INDEX3U_HPP
#define INDEX3U_HPP

#include "utility/config.hpp"

namespace ece
{
    namespace utility
    {
        namespace indexing
        {
        	/**
        	 * @class Index3u
        	 * @brief A 3D index key to access elements in a 3D container.
        	 * @remark This class need to be refactored to be usable in others classes like Matrix. Have to be compared with std::slice and others.
        	 */
        	class ECE_UTILITY_API Index3u
        	{
        	public:
        		/**
        		 * @fn Index3u()
        		 * @brief Default constructor.
        		 * @throw noexcept
        		 * It initializes the index to (0, 0, 0).
        		 */
        		inline constexpr Index3u() noexcept;

        		/**
        		* @fn Index3u(const int i, const int j, const int k)
        		* @param[in] i The i position of the index.
        		* @param[in] j The j position of the index.
        		* @param[in] k The k position of the index.
        		* @brief Build a 3d index key and set the position to (i, j, k).
        		* @throw noexcept
        		*/
        		inline Index3u(const int i, const int j, const int k) noexcept;

        		/**
        		 * @fn Index3u(const Index3u & copy)
        		 * @param[in] copy The index to copy from.
        		 * @brief Default copy constructor.
        		 * @throw noexcept
        		 */
        		Index3u(const Index3u & copy) noexcept = default;

        		/**
        		 * @fn Index3u(Index3u && move)
        		 * @param[in] move The index to move from.
        		 * @brief Default move constructor.
        		 * @throw noexcept
        		 */
        		Index3u(Index3u && move) noexcept = default;

        		/**
        		 * @fn ~Index3u()
        		 * @brief Default destructor.
        		 * @throw noexcept
        		 */
        		~Index3u() noexcept = default;

        		/**
        		 * @fn Index3u & operator=(const Index3u & copy)
        		 * @param[in] copy The index to copy from.
        		 * @return The 3D index copied.
        		 * @brief Default copy assignment operator.
        		 * @throw noexcept
        		 */
        		Index3u & operator=(const Index3u & copy) noexcept  = default;

        		/**
        		 * @fn Index3u & operator=(Index3u && move)
        		 * @param[in] move The index to move from.
        		 * @return The 3D index moved.
        		 * @brief Default move assignment operator.
        		 * @throw noexcept
        		 */
        		Index3u & operator=(Index3u && move) noexcept = default;

        		/**
        		 * @fn int get(const int maxI, const int maxJ)
        		 * @param[in] maxI Max length of an i-axis row.
        		 * @param[in] maxJ Max length of a j-axis row.
        		 * @return The 1D position
        		 * @brief Get the 1D position considering the max size of a slice.
        		 * @throw noexcept
        		 */
        		inline int get(const int maxI, const int maxJ) noexcept;

        		/**
        		 * @fn void set(const int maxI, const int maxJ, const int index)
        		 * @param[in] maxI Max length of an i-axis row
        		 * @param[in] maxI Max length of a j-axis row
        		 * @param[in] index 1D index to set.
        		 * @brief Convert a 1D position to a 3D position, considering the max size of a slice.
        		 * @throw A division_by_zero exception if the max length is equal to 0.
        		 */
        		inline void set(const int maxI, const int maxJ, const int index);

        		/**
        		 * @property _i
        		 * @brief The i position (usually on X-axis) of the index in 3D.
        		 */
        		unsigned int _i;

        		/**
        		 * @property _j
        		 * @brief The j position (usually on Y-axis) of the index in 3D.
        		 */
        		unsigned int _j;

        		/**
        		 * @property _k
        		 * @brief The k position (usually on Z-axis) of the index in 3D.
        		 */
        		unsigned int _k;
        	};
        } // namespace indexing
    } // namespace utility
} // namespace ece

#include "utility/indexing/index3u.inl"

#endif // INDEX3U_HPP
