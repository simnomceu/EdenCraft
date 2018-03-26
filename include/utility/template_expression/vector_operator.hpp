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

#ifndef VECTOR_OPERATOR_HPP
#define VECTOR_OPERATOR_HPP

#include "utility/template_expression/vector_expression.hpp"

namespace ece
{
	/**
	 * @class VectorSum
	 * @tparam E1 The type of the left hand side element of the operation.
	 * @tparam E2 The type of the right hand side element of the operation.
	 * @brief The sum of to vector.
	 */
//	template <class E1, class E2>
//	class VectorSum: public VectorExpression<VectorSum<E1, E2>>
//	{
//	public:
		/**
		 * @fn constexpr VectorSum() noexcept
		 * @brief Default constructor.
		 * @throw noexcept
		 */
//		constexpr VectorSum() noexcept = default;

		/**
		 * @fn VectorSum(const E1 & lhs, const E2 & rhs) noexcept
		 * @param[in] lhs Left hand side of the vector sum operation.
		 * @param[in] rhs Right hand side of the vector sum operation.
		 * @brief Build a vector sum expression from to factors.
		 * @throw noexcept
		 */
//		inline VectorSum(const E1 & lhs, const E2 & rhs) noexcept;

		/**
		 * @fn VectorSum(const VectorSum & copy) noexcept
		 * @param[in] copy The VectorSum to copy from.
		 * @brief Default copy constructor.
		 * @throw noexcept
		 */
//		VectorSum(const VectorSum & copy) noexcept = default;

		/**
		 * @fn VectorSum(VectorSum && move) noexcept
		 * @param[in] move The VectorSum to move.
		 * @brief Default move constructor.
		 * @throw noexcept
		 */
//		VectorSum(VectorSum && move) noexcept = default;

		/**
		 * @fn ~VectorSum() noexcept
		 * @brief Default destructor.
		 * @throw noexcept
		 */
//		~VectorSum() noexcept = default;

		/**
		 * @fn VectorSum & operator=(const VectorSum & copy) noexcept
		 * @param[in] copy The VectorSum to copy from.
		 * @return The VectorSum copied.
		 * @brief Default copy assignment operator.
		 * @throw noexcept
		 */
//		VectorSum & operator=(const VectorSum & copy) noexcept = default;

		/**
		 * @fn VectorSum & operator=(VectorSum && move) noexcept
		 * @param[in] move The VectorSum to move.
		 * @return The VectorSum moved.
		 * @brief Default move assignment operator.
		 * @throw noexcept
		 */
//		VectorSum & operator=(VectorSum && move) noexcept = default;

//		inline auto operator[](const unsigned int index) const;

//		inline unsigned int size() const;

//	protected:
//		const E1 & _lhs;
//		const E2 & _rhs;
//	};

//	template <class E1, class E2>
//	VectorSum<E1, E2> operator+(const E1 & lhs, const E2 & rhs);

#define LXR_OPERATOR(NAME, OPERATOR) \
	template <class E1, class E2> \
	class NAME : public VectorExpression<VectorSum<E1, E2>> \
	{ \
	public: \
		NAME() = delete; \
		inline NAME(const E1 & lhs, const E2 & rhs) noexcept: _lhs(lhs), _rhs(rhs) {} \
		NAME(const NAME & copy) noexcept = default; \
		NAME(NAME && move) noexcept = default; \
		~NAME() noexcept = default; \
		NAME & operator=(const NAME & copy) noexcept = default; \
		NAME & operator=(NAME && move) noexcept = default; \
		inline auto operator[](const unsigned int index) const { return this->_lhs[index] OPERATOR this->_rhs[index]; } \
		inline unsigned int size() const { return this->_lhs.size(); } \
	\
	protected: \
		const E1 & _lhs; \
		const E2 & _rhs; \
	}; \
 \
	template <class E1, class E2> \
	inline NAME<E1, E2> operator OPERATOR (const E1 & lhs, const E2 & rhs) { return NAME<E1, E2>(lhs, rhs); }
}

#include "utility/template_expression/vector_operator.inl"

#endif // VECTOR_OPERATOR_HPP