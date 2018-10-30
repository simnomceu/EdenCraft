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

#ifndef SLICE_HPP
#define SLICE_HPP

#include "utility/template_expression/vector.hpp"

#include <iostream>
#include <memory>

namespace ece
{
    namespace utility
    {
        namespace template_expression
        {
        	/**
        	 * @class Slice
        	 * @tparam Container The type of container to slice.
        	 * @extends LinearExpression<Slice<Container>>
        	 * @brief A slice of a container.
        	 */
        	template <class Container>
        	class Slice : public LinearExpression<Slice<Container>>
        	{
        	public:
        		constexpr Slice() noexcept = delete;

        		/**
        		 * @fn Slice(Container * container, unsigned int beginning, unsigned int size, unsigned int shift)
        		 * @param[in] container The container to slice.
        		 * @param[in] beginning Where to begin to slice the container.
        		 * @param[in] size The size of the slice.
        		 * @param[in] shift The shift between each element of the slice in the container.
        		 * @brief Build a slice of the container.
        		 * @throw noexcept
        		 */
        		Slice(Container * container, unsigned int beginning, unsigned int size, unsigned int shift) noexcept;

        		/**
        		 * @fn Slice(const Slice & copy) noexcept
        		 * @param[in] copy The Slice to copy from.
        		 * @brief Default copy constructor.
        		 * @throw noexcept
        		 */
        		Slice(const Slice & copy) noexcept = default;

        		/**
        		 * @fn Slice(Slice && move) noexcept
        		 * @param[in] move The Slice to move.
        		 * @brief Default move constructor.
        		 * @throw noexcept
        		 */
        		Slice(Slice && move) noexcept = default;

        		/**
        		 * @fn ~Slice() noexcept
        		 * @brief Default destructor.
        		 * @throw noexcept
        		 */
				~Slice() noexcept = default;

        		/**
        		 * @fn Slice & operator=(const Slice & copy) noexcept
        		 * @param[in] copy The Slice to copy from.
        		 * @return The Slice copied.
        		 * @brief Default copy assignment operator.
        		 * @throw noexcept
        		 */
        		Slice & operator=(const Slice & copy) noexcept = default;

        		/**
        		 * @fn Slice & operator=(Slice && move) noexcept
        		 * @param[in] move The Slice to move.
        		 * @return The Slice moved.
        		 * @brief Default move assignment operator.
        		 * @throw noexcept
        		 */
        		Slice & operator=(Slice && move) noexcept = default;

        		/**
        		 * @fn auto operator[](const unsigned int index) const
        		 * @param[in] index The index of the element to access.
        		 * @return The element wished.
        		 * @brief Get the element at the index.
        		 * @throw
        		 * @see auto Slice<Container>::cell(const unsigned int index) const
        		 */
        		inline auto operator[](const unsigned int index) const;

        		/**
        		 * @fn auto cell(const unsigned int index) const
        		 * @param[in] index The index of the element to access.
        		 * @return The element wished.
        		 * @brief Get the element at the index.
        		 * @throw
        		 * @see auto Slice<Container>::operator[](const unsigned int index) const
        		 */
        		inline auto cell(const unsigned int index) const;

        		/**
        		 * @fn auto & operator[](const unsigned int index)
        		 * @param[in] index The index of the element to access.
        		 * @return The element wished.
        		 * @brief Get the element at the index.
        		 * @throw
        		 * @see auto & Slice<Container>::cell(const unsigned int index)
        		 */
        		inline auto & operator[](const unsigned int index);

        		/**
        		 * @fn auto & cell(const unsigned int index)
        		 * @param[in] index The index of the element to access.
        		 * @return The element wished.
        		 * @brief Get the element at the index.
        		 * @throw
        		 * @see auto & Slice<Container>::operator[](const unsigned int index)
        		 */
        		inline auto & cell(const unsigned int index);

        		/**
        		 * @fn constexpr unsigned int size() const noexcept
        		 * @return The number of element in the expression result.
        		 * @brief Get he number of elements.
        		 * @throw noexcept
        		 */
        		inline constexpr auto size() const noexcept -> unsigned int;

        		/**
        		 * @fn auto begin() noexcept
        		 * @return An iterator to the beginning of the slice.
        		 * @brief Get an iterator to the beginning of the slice.
        		 * @throw noexcept
        		 */
        		inline auto begin() noexcept;

        		/**
        		 * @fn auto end() noexcept
        		 * @return An iterator to the end of the slice.
        		 * @brief Get an iterator to the end of the slice.
        		 * @throw noexcept
        		 */
        		inline auto end() noexcept;

        	protected:
        		/**
        		 * @property _container
        		 * @brief The contaner to slice.
        		 */
        		Container * _container;

        		/**
        		 * @property _beginning
        		 * @brief The beginning of the slice in the container.
        		 */
        		unsigned int _beginning;

        		/**
        		 * @property _size
        		 * @brief The size of the slice.
        		 */
        		unsigned int _size;

        		/**
        		 * @property _shift
        		 * @brief The shift between each element of the slice in the container.
        		 */
        		unsigned int _shift;
        	};
        } // namespace utility
    } // namespace template_expression
} // namespace ece

#include "utility/template_expression/slice.inl"

#endif // SLICE_HPP
