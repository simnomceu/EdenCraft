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

#ifndef DYNAMIC_2D_ARRAY_HPP
#define DYNAMIC_2D_ARRAY_HPP

#include "utility/config.hpp"
#include "utility/pch.hpp"

namespace ece
{
    namespace utility
    {
        namespace indexing
        {
        	/**
        	 * @class Dynamic2DArray
        	 * @tparam E Type of the data in the array.
        	 * @brief A 2D dynamic array.
        	 */
        	template <class E>
        	class Dynamic2DArray
        	{
        	public:
        		constexpr Dynamic2DArray() noexcept = delete;

        		/**
        		 * @fn Dynamic2DArray(const std::size_t width, const std::size_t height)
        		 * @param width The width of the 2D array to create.
        		 * @param height The height of the 2D array to create.
        		 * @brief Build a two dimensional array of a specifc size.
        		 * @throw
        		 */
        		Dynamic2DArray(const std::size_t width, const std::size_t height);

        		/**
        		 * @fn Dynamic2DArray(const Dynamic2DArray<E> & copy) noexcept
        		 * @param[in] copy The Dynamic2DArray to copy from.
        		 * @brief Default copy constructor.
        		 * @throw noexcept
        		 */
        		Dynamic2DArray(const Dynamic2DArray<E> & copy) noexcept;

        		/**
        		 * @fn Dynamic2DArray(Dynamic2DArray<E> && move) noexcept
        		 * @param[in] move The Dynamic2DArray to move.
        		 * @brief Default move constructor.
        		 * @throw noexcept
        		 */
        		Dynamic2DArray(Dynamic2DArray<E> && move) noexcept = default;

        		/**
        		 * @fn ~Dynamic2DArray() noexcept
        		 * @brief Default destructor.
        		 * @throw noexcept
        		 */
        		inline ~Dynamic2DArray() noexcept;

        		/**
        		 * @fn Dynamic2DArray<E> & operator=(const Dynamic2DArray<E> & copy) noexcept
        		 * @param[in] copy The Dynamic2DArray to copy from.
        		 * @return The Dynamic2DArray copied.
        		 * @brief Default copy assignment operator.
        		 * @throw noexcept
        		 */
        		Dynamic2DArray<E> & operator=(const Dynamic2DArray<E> & copy) noexcept;

        		/**
        		 * @fn Dynamic2DArray<E> & operator=(Dynamic2DArray<E> && move) noexcept
        		 * @param[in] move The Dynamic2DArray to move.
        		 * @return The Dynamic2DArray moved.
        		 * @brief Default move assignment operator.
        		 * @throw noexcept
        		 */
        		Dynamic2DArray<E> & operator=(Dynamic2DArray<E> && move) noexcept = default;

        		/**
        		 * @fn E * operator[](const std::size_t index)
        		 * @param[in] index The index of the line to access.
        		 * @return A pointer to the line in the two dimensional array.
        		 * @brief Get a line of the container.
        		 * @throw
        		 */
        		inline E * operator[](const std::size_t index);

        		/**
        		 * @fn const E * operator[](const std::size_t index) const
        		 * @param[in] index The index of the line to access.
        		 * @return A pointer to the line in the two dimensional array.
        		 * @brief Get a line of the container.
        		 * @throw
        		 */
        		inline const E * operator[](const std::size_t index) const;

        		/**
        		 * @fn E * data()
        		 * @return The array of data.
        		 * @brief Access directly the array of data in memory.
        		 * @throw noexcept
        		 */
        		inline E * data() noexcept;

        		/**
        		 * @fn const E * data() const
        		 * @return The array of data.
        		 * @brief Access directly the array of data in memory.
        		 * @throw noexcept
        		 */
        		inline const E * data() const noexcept;

        		/**
        		 * @fn std::size_t getWidth() const noexcept
        		 * @return The width of the container.
        		 * @brief Get the width of the two dimensional array.
        		 * @throw noexcept
        		 */
        		inline std::size_t getWidth() const noexcept;

        		/**
        		 * @fn std::size_t getHeight() const noexcept
        		 * @return The height of the container.
        		 * @brief Get the height of the two dimensional array.
        		 * @throw noexcept
        		 */
        		inline std::size_t getHeight() const noexcept;

        		/**
        		 * @fn void resize(const std::size_t width, const std::size_t height)
        		 * @param[in] width The new width of the container.
        		 * @param[in] height The new height of the container.
        		 * @brief Resize the two dimensional array.
        		 * If it is smaller, some data are lose, if it is bigger, new data are initialized to the default value.
        		 * @throw
        		 */
        		void resize(const std::size_t width, const std::size_t height);

        	protected:
        		E * _buffer;
				std::size_t _width;
				std::size_t _height;
        	};
        } // namespace indexing
    } // namespace utility
} // namespace ece

#include "utility/indexing/dynamic_2d_array.inl"

#endif // DYNAMIC_2D_ARRAY_HPP
