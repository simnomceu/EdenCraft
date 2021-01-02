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

#ifndef CONST_SLICE_HPP
#define CONST_SLICE_HPP

#include "utility/config.hpp"
#include "utility/pch.hpp"
#include "utility/template_expression/vector.hpp"

namespace ece
{
    namespace utility
    {
        namespace template_expression
        {
        	/**
        	 * @class ConstSlice
        	 * @tparam Container The type of container to slice.
        	 * @extends LinearExpression<ConstSlice<Container>>
        	 * @brief A slice of a container.
        	 */
        	template <class Container>
        	class ConstSlice : public LinearExpression<ConstSlice<Container>>
        	{
        	public:
        		constexpr ConstSlice() noexcept = delete;

        		/**
        		 * @fn ConstSlice(const Container & container,, unsigned int beginning, unsigned int size, unsigned int shift)
        		 * @param[in] container The container to slice.
        		 * @param[in] beginning Where to begin to slice the container.
        		 * @param[in] size The size of the slice.
        		 * @param[in] shift The shift between each element of the slice in the container.
        		 * @brief Build a slice of the container.
        		 * @throw noexcept
        		 */
        		ConstSlice(const Container & container, unsigned int beginning, unsigned int size, unsigned int shift) noexcept;

        		/**
        		 * @fn ConstSlice(const ConstSlice & copy) noexcept
        		 * @param[in] copy The ConstSlice to copy from.
        		 * @brief Default copy constructor.
        		 * @throw noexcept
        		 */
        		ConstSlice(const ConstSlice & copy) noexcept = default;

        		/**
        		 * @fn ConstSlice(ConstSlice && move) noexcept
        		 * @param[in] move The ConstSlice to move.
        		 * @brief Default move constructor.
        		 * @throw noexcept
        		 */
        		ConstSlice(ConstSlice && move) noexcept = default;

        		/**
        		 * @fn ~ConstSlice() noexcept
        		 * @brief Default destructor.
        		 * @throw noexcept
        		 */
				~ConstSlice() noexcept = default;

        		/**
        		 * @fn ConstSlice & operator=(const ConstSlice & copy) noexcept
        		 * @param[in] copy The ConstSlice to copy from.
        		 * @return The ConstSlice copied.
        		 * @brief Default copy assignment operator.
        		 * @throw noexcept
        		 */
        		ConstSlice & operator=(const ConstSlice & copy) noexcept = default;

        		/**
        		 * @fn ConstSlice & operator=(ConstSlice && move) noexcept
        		 * @param[in] move The ConstSlice to move.
        		 * @return The ConstSlice moved.
        		 * @brief Default move assignment operator.
        		 * @throw noexcept
        		 */
        		ConstSlice & operator=(ConstSlice && move) noexcept = default;

        		/**
        		 * @fn auto operator[](const unsigned int index) const
        		 * @param[in] index The index of the element to access.
        		 * @return The element wished.
        		 * @brief Get the element at the index.
        		 * @throw
        		 * @see auto ConstSlice<Container>::cell(const unsigned int index) const
        		 */
        		inline auto operator[](const unsigned int index) const;

        		/**
        		 * @fn auto cell(const unsigned int index) const
        		 * @param[in] index The index of the element to access.
        		 * @return The element wished.
        		 * @brief Get the element at the index.
        		 * @throw
        		 * @see auto ConstSlice<Container>::operator[](const unsigned int index) const
        		 */
        		inline auto cell(const unsigned int index) const;

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
        		inline auto begin() const noexcept;

        		/**
        		 * @fn auto end() noexcept
        		 * @return An iterator to the end of the slice.
        		 * @brief Get an iterator to the end of the slice.
        		 * @throw noexcept
        		 */
        		inline auto end() const noexcept;

        	protected:
        		/**
        		 * @property _container
        		 * @brief The contaner to slice.
        		 */
				Container _container;

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

#include "utility/template_expression/const_slice.inl"

#endif // CONST_SLICE_HPP
