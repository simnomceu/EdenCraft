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

#ifndef VALUE_REFERENCE_HPP
#define VALUE_REFERENCE_HPP

namespace ece
{
	/**
	 * @class ValueReference
	 * @brief
	 */
	template <class E>
	class ValueReference
	{
	public:
		constexpr ValueReference() noexcept = delete;
		
		/**
		 * @fn ValueReference(const E & value)
		 * @param[in] value The value to reference.
		 * @brief Build a referenced value. If it is a temporary value, it creates a stored value.
		 * @throw
		 */
		ValueReference(const E & value);

		/**
		* @fn ValueReference(const E value)
		* @param[in] value The value to reference.
		* @brief Build a referenced value. If it is a temporary value, it creates a stored value.
		* @throw
		*/
		ValueReference(const E value);

		/**
		* @fn ValueReference(E && value)
		* @param[in] value The value to reference.
		* @brief Build a referenced value. If it is a temporary value, it creates a stored value.
		* @throw
		*/
		ValueReference(E && value);

		/**
		 * @fn ValueReference(const ValueReference & copy) noexcept
		 * @param[in] copy The ValueReference to copy from.
		 * @brief Default copy constructor.
		 * @throw noexcept
		 */
		ValueReference(const ValueReference & copy) noexcept = default;

		/**
		 * @fn ValueReference(ValueReference && move) noexcept
		 * @param[in] move The ValueReference to move.
		 * @brief Default move constructor.
		 * @throw noexcept
		 */
		ValueReference(ValueReference && move) noexcept = default;

		/**
		 * @fn ~ValueReference() noexcept
		 * @brief Default destructor.
		 * @throw noexcept
		 */
		~ValueReference() noexcept;

		/**
		 * @fn ValueReference & operator=(const ValueReference & copy) noexcept
		 * @param[in] copy The ValueReference to copy from.
		 * @return The ValueReference copied.
		 * @brief Default copy assignment operator.
		 * @throw noexcept
		 */
		ValueReference & operator=(const ValueReference & copy) noexcept = default;

		/**
		 * @fn ValueReference & operator=(ValueReference && move) noexcept
		 * @param[in] move The ValueReference to move.
		 * @return The ValueReference moved.
		 * @brief Default move assignment operator.
		 * @throw noexcept
		 */
		ValueReference & operator=(ValueReference && move) noexcept = default;

		/**
		 * @fn const E & ref() const
		 * @return The referenced object.
		 * @brief Get the referenced object.
		 * @throw
		 */
		const E & ref() const;

	private:
		E * _value;
		E & _reference;
	};
}

#include "utility/template_expression/value_reference.inl"

#endif // VALUE_REFERENCE_HPP