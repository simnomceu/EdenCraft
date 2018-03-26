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

#ifndef VECTOR_EXPRESSION_HPP
#define VECTOR_EXPRESSION_HPP

#include <type_traits>

namespace ece
{
	/**
	 * @class VectorExpression
	 * @tparam E The child template type of the Curiously Reccuring Template Pattern.
	 * @brief
	 */
	template <class E>
	class VectorExpression
	{
	public:
		/**
		 * @fn constexpr VectorExpression() noexcept
		 * @brief Default constructor.
		 * @throw noexcept
		 */
		constexpr VectorExpression() noexcept = default;

		/**
		 * @fn VectorExpression(const VectorExpression & copy) noexcept
		 * @param[in] copy The VectorExpression to copy from.
		 * @brief Default copy constructor.
		 * @throw noexcept
		 */
		VectorExpression(const VectorExpression & copy) noexcept = default;

		/**
		 * @fn VectorExpression(VectorExpression && move) noexcept
		 * @param[in] move The VectorExpression to move.
		 * @brief Default move constructor.
		 * @throw noexcept
		 */
		VectorExpression(VectorExpression && move) noexcept = default;

		/**
		 * @fn ~VectorExpression() noexcept
		 * @brief Default destructor.
		 * @throw noexcept
		 */
		~VectorExpression() noexcept = default;

		/**
		 * @fn VectorExpression & operator=(const VectorExpression & copy) noexcept
		 * @param[in] copy The VectorExpression to copy from.
		 * @return The VectorExpression copied.
		 * @brief Default copy assignment operator.
		 * @throw noexcept
		 */
		VectorExpression & operator=(const VectorExpression & copy) noexcept = default;

		/**
		 * @fn VectorExpression & operator=(VectorExpression && move) noexcept
		 * @param[in] move The VectorExpression to move.
		 * @return The VectorExpression moved.
		 * @brief Default move assignment operator.
		 * @throw noexcept
		 */
		VectorExpression & operator=(VectorExpression && move) noexcept = default;

		/**
		 * @fn auto operator[](const unsigned int index) const
		 * @param[in] index The index of the element to access.
		 * @return The element wished.
		 * @brief Get the element at the index.
		 * @throw
		 */
		inline auto operator[](const unsigned int index) const;

		/**
		 * @fn unsigned int size() const noexcept
		 * @return The number of element in the expression result.
		 * @brief Get he number of elements.
		 * @throw noexcept
		 */
		inline unsigned int size() const noexcept;

		/**
		 * @fn operator E & () noexcept
		 * @return The child class object.
		 * @brief Downcast to the child class.
		 * @throw noexcept
		 */
		inline operator E & () noexcept;

		/**
		* @fn operator const E & () noexcept
		* @return The child class object.
		* @brief Downcast to the child class.
		* @throw noexcept
		*/
		inline operator const E & () noexcept;
	};
}

#include "utility/template_expression/vector_expression.inl"

#endif // VECTOR_EXPRESSION_HPP