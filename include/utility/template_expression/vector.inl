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

#include <type_traits>
#include <algorithm>

namespace ece
{
	template<typename E, unsigned int Size, typename enabled>
	inline constexpr Vector<E, Size, enabled>::Vector() noexcept: VectorExpression<Vector<E, Size, enabled>>(), _elements() { this->_elements.fill(0); }

	template <typename E, unsigned int Size, typename enabled>
	inline constexpr Vector<E, Size, enabled>::Vector(const E value) noexcept: VectorExpression<Vector<E, Size, enabled>>(), _elements() { this ->_elements.fill(value); }

	template <typename E, unsigned int Size, typename enabled>
	Vector<E, Size, enabled>::Vector(const VectorExpression<Vector<E, Size, enabled>> & rhs) noexcept: VectorExpression<Vector<E, Size, enabled>>(), _elements()
	{
		for (unsigned int i = 0; i < rhs.size(); ++i) {
			this->_elements[i] = rhs[i];
		}
	}

	template <typename E, unsigned int Size, typename enabled>
	Vector<E, Size, enabled>::Vector(std::initializer_list<E> il) noexcept: _elements()
	{
		for (unsigned int i = 0; i < il.size(); ++i) {
			this->_elements[i] = *(il.begin() + i);
		}
	}

	template <typename E, unsigned int Size, typename enabled>
	Vector<E, Size, enabled> & Vector<E, Size, enabled>::operator=(const VectorExpression<Vector<E, Size, enabled>> & rhs) noexcept
	{
		for (unsigned int i = 0; i < rhs.size(); ++i) {
			this->_elements[i] = rhs[i];
		}
		return *this;
	}

	template <typename E, unsigned int Size, typename enabled>
	inline E Vector<E, Size, enabled>::operator[](const unsigned int index) const { return this->_elements[index]; }

	template <typename E, unsigned int Size, typename enabled>
	inline E & Vector<E, Size, enabled>::operator[](const unsigned int index) { return this->_elements[index]; }

	template <typename E, unsigned int Size, typename enabled>
	inline constexpr unsigned int Vector<E, Size, enabled>::size() const noexcept { return Size; }

	template <typename E, unsigned int Size, typename enabled>
	inline E Vector<E, Size, enabled>::min() const noexcept { return std::min_element(this->_elements.begin(), this->_elements.end()); }

	template <typename E, unsigned int Size, typename enabled>
	inline E Vector<E, Size, enabled>::max() const noexcept { return std::max_element(this->_elements.begin(), this->_elements.end()); }

	template <typename E, unsigned int Size, typename enabled>
	inline E Vector<E, Size, enabled>::sum() const noexcept { return std::accumulate(this->_elements.begin(), this->_elements.end(), 0); }

	template <typename E, unsigned int Size, typename enabled>
	inline Vector<E, Size, enabled> Vector<E, Size, enabled>::shift(const int count) const noexcept
	{
		Vector<E, Size, enabled> result;
		for (int i = 0; i < static_cast<int>(Size); ++i) {
			result[i] = count + i < 0 || count + i >= Size ? 0 : this->_elements[count + i];
		}
		return std::move(result);
	}

	template <typename E, unsigned int Size, typename enabled>
	inline Vector<E, Size, enabled> Vector<E, Size, enabled>::cshift(const int count) const noexcept
	{
		Vector<E, Size, enabled> result;
		for (int i = 0; i < static_cast<int>(Size); ++i) {
			result[i] = (count + i < 0 || count + i >= Size) ? (count + i < 0 ? this->_elements[Size + count + i] : this->_elements[(count + i) % (Size)]) : this->_elements[count + i];
		}
		return std::move(result);
	}

	template <typename E, unsigned int Size, typename enabled>
	inline Vector<E, Size, enabled> Vector<E, Size, enabled>::apply(E func(E)) const noexcept
	{
		Vector<E, Size, enabled> result;
		for (unsigned int i = 0; i < Size; ++i) {
			result[i] = func(this->_elements[i]);
		}
		return std::move(result);
	}

	template <typename E, unsigned int Size, typename enabled>
	inline Vector<E, Size, enabled> Vector<E, Size, enabled>::apply(E func(const E &)) const noexcept
	{
		Vector<E, Size, enabled> result;
		for (unsigned int i = 0; i < Size; ++i) {
			result[i] = func(this->_elements[i]);
		}
		return std::move(result);
	}

	template <class E, typename enabled>
	VectorUnaryOperation<E, unary_plus<>> operator+(const E & lhs) { return VectorUnaryOperation<E, unary_plus<>>(lhs); }

	template <class E, typename enabled>
	VectorUnaryOperation<E, std::negate<>> operator-(const E & lhs) { return VectorUnaryOperation<E, std::negate<>>(lhs); }

	template <class E, typename enabled>
	VectorUnaryOperation<E, std::bit_not<>> operator~(const E & lhs) { return VectorUnaryOperation<E, std::bit_not<>>(lhs); }

	template <class E, typename enabled>
	VectorUnaryOperation<E, std::bit_not<>> operator!(const E & lhs) { return VectorUnaryOperation<E, std::logical_not<>>(lhs); }

	template <class E1, class E2, typename enabled>
	E1 & operator+=(E1 & lhs, const E2 & rhs)
	{
		VectorOperation<E1, E2, std::plus<>> result(lhs, rhs);
		for (unsigned int i = 0; i < lhs.size(); ++i) {
			lhs[i] = result[i];
		}
		return lhs;
	}

	template <class E1, class E2, typename enabled>
	E1 & operator-=(E1 & lhs, const E2 & rhs)
	{
		VectorOperation<E1, E2, std::minus<>> result(lhs, rhs);
		for (unsigned int i = 0; i < lhs.size(); ++i) {
			lhs[i] = result[i];
		}
		return lhs;
	}

	template <class E1, class E2, typename enabled>
	E1 & operator*=(E1 & lhs, const E2 & rhs)
	{
		VectorOperation<E1, E2, std::multiplies<>> result(lhs, rhs);
		for (unsigned int i = 0; i < lhs.size(); ++i) {
			lhs[i] = result[i];
		}
		return lhs;
	}

	template <class E1, class E2, typename enabled>
	E1 & operator/=(E1 & lhs, const E2 & rhs)
	{
		VectorOperation<E1, E2, std::divides<>> result(lhs, rhs);
		for (unsigned int i = 0; i < lhs.size(); ++i) {
			lhs[i] = result[i];
		}
		return lhs;
	}

	template <class E1, class E2, typename enabled>
	E1 & operator%=(E1 & lhs, const E2 & rhs)
	{
		VectorOperation<E1, E2, std::divides<>> result(lhs, rhs);
		for (unsigned int i = 0; i < lhs.size(); ++i) {
			lhs[i] = result[i];
		}
		return lhs;
	}

	template <class E1, class E2, typename enabled>
	E1 & operator&=(E1 & lhs, const E2 & rhs)
	{
		VectorOperation<E1, E2, std::bit_and<>> result(lhs, rhs);
		for (unsigned int i = 0; i < lhs.size(); ++i) {
			lhs[i] = result[i];
		}
		return lhs;
	}

	template <class E1, class E2, typename enabled>
	E1 & operator|=(E1 & lhs, const E2 & rhs)
	{
		VectorOperation<E1, E2, std::bit_or<>> result(lhs, rhs);
		for (unsigned int i = 0; i < lhs.size(); ++i) {
			lhs[i] = result[i];
		}
		return lhs;
	}

	template <class E1, class E2, typename enabled>
	E1 & operator^=(E1 & lhs, const E2 & rhs)
	{
		VectorOperation<E1, E2, std::bit_xor<>> result(lhs, rhs);
		for (unsigned int i = 0; i < lhs.size(); ++i) {
			lhs[i] = result[i];
		}
		return lhs;
	}

	template <class E1, class E2, typename enabled>
	E1 & operator<<=(E1 & lhs, const E2 & rhs)
	{
		VectorOperation<E1, E2, bitwise_left_shift<>> result(lhs, rhs);
		for (unsigned int i = 0; i < lhs.size(); ++i) {
			lhs[i] = result[i];
		}
		return lhs;
	}

	template <class E1, class E2, typename enabled>
	E1 & operator>>=(E1 & lhs, const E2 & rhs)
	{
		VectorOperation<E1, E2, bitwise_right_shift<>> result(lhs, rhs);
		for (unsigned int i = 0; i < lhs.size(); ++i) {
			lhs[i] = result[i];
		}
		return lhs;
	}

	template <class E1, class E2, typename enabled>
	VectorOperation<E1, E2, std::plus<>> operator+(const E1 & lhs, const E2 & rhs) { return VectorOperation<E1, E2, std::plus<>>(lhs, rhs); }

	template <class E1, class E2, typename enabled>
	VectorOperation<E1, E2, std::minus<>> operator-(const E1 & lhs, const E2 & rhs) { return VectorOperation<E1, E2, std::minus<>>(lhs, rhs); }

	template <class E1, class E2, typename enabled>
	VectorOperation<E1, E2, std::multiplies<>> operator*(const E1 & lhs, const E2 & rhs) { return VectorOperation<E1, E2, std::multiplies<>>(lhs, rhs); }

	template <class E1, class E2, typename enabled>
	VectorOperation<E1, E2, std::divides<>> operator/(const E1 & lhs, const E2 & rhs) { return VectorOperation<E1, E2, std::divides<>>(lhs, rhs); }

	template <class E1, class E2, typename enabled>
	VectorOperation<E1, E2, std::modulus<>> operator%(const E1 & lhs, const E2 & rhs) { return VectorOperation<E1, E2, std::modulus<>>(lhs, rhs); }

	template <class E1, class E2, typename enabled>
	VectorOperation<E1, E2, std::bit_and<>> operator&(const E1 & lhs, const E2 & rhs) { return VectorOperation<E1, E2, std::bit_and<>>(lhs, rhs); }

	template <class E1, class E2, typename enabled>
	VectorOperation<E1, E2, std::bit_or<>> operator|(const E1 & lhs, const E2 & rhs) { return VectorOperation<E1, E2, std::bit_or<>>(lhs, rhs); }

	template <class E1, class E2, typename enabled>
	VectorOperation<E1, E2, std::bit_xor<>> operator^(const E1 & lhs, const E2 & rhs) { return VectorOperation<E1, E2, std::bit_xor<>>(lhs, rhs); }

	template <class E1, class E2, typename enabled>
	VectorOperation<E1, E2, bitwise_left_shift<>> operator<<(const E1 & lhs, const E2 & rhs) { return VectorOperation<E1, E2, bitwise_left_shift<>>(lhs, rhs); }

	template <class E1, class E2, typename enabled>
	VectorOperation<E1, E2, bitwise_right_shift<>> operator>>(const E1 & lhs, const E2 & rhs) { return VectorOperation<E1, E2, bitwise_right_shift<>>(lhs, rhs); }

	template <class E1, class E2, typename enabled>
	VectorOperation<E1, E2, std::logical_and<>> operator&&(const E1 & lhs, const E2 & rhs) { return VectorOperation<E1, E2, std::logical_and<>>(lhs, rhs); }

	template <class E1, class E2, typename enabled>
	VectorOperation<E1, E2, std::logical_or<>> operator||(const E1 & lhs, const E2 & rhs) { return VectorOperation<E1, E2, std::logical_or<>>(lhs, rhs); }

	template <class E1, class E2, typename enabled>
	VectorOperation<E1, E2, std::equal_to<>> operator==(const E1 & lhs, const E2 & rhs) { return VectorOperation<E1, E2, std::equal_to<>>(lhs, rhs); }

	template <class E1, class E2, typename enabled>
	VectorOperation<E1, E2, std::not_equal_to<>> operator!=(const E1 & lhs, const E2 & rhs) { return VectorOperation<E1, E2, std::not_equal_to<>>(lhs, rhs); }

	template <class E1, class E2, typename enabled>
	VectorOperation<E1, E2, std::greater<>> operator>(const E1 & lhs, const E2 & rhs) { return VectorOperation<E1, E2, std::greater<>>(lhs, rhs); }

	template <class E1, class E2, typename enabled>
	VectorOperation<E1, E2, std::less<>> operator<(const E1 & lhs, const E2 & rhs) { return VectorOperation<E1, E2, std::less<>>(lhs, rhs); }

	template <class E1, class E2, typename enabled>
	VectorOperation<E1, E2, std::greater_equal<>> operator>=(const E1 & lhs, const E2 & rhs) { return VectorOperation<E1, E2, std::greater_equal<>>(lhs, rhs); }

	template <class E1, class E2, typename enabled>
	VectorOperation<E1, E2, std::less_equal<>> operator<=(const E1 & lhs, const E2 & rhs) { return VectorOperation<E1, E2, std::less_equal<>>(lhs, rhs); }
}
