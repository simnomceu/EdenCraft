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

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <valarray>
#include <type_traits>

#ifdef _MSC_VER
#	undef min
#	undef max
#endif

namespace ece
{
	/**
	 * @struct HasCrossProduct
	 * @tparam Size The size of the vector class concerned.
	 * @brief Trait of a vector which indicate if the cross product is available or not.
	 */
	template <unsigned int Size>
	struct HasCrossProduct
	{
		static const bool value = false;
	};

	/**
	 * class Vector
	 * @extends std::valarray<T>
	 * @tparam T A vector can be of any numeric type.
	 * @tparam Size The size of the vector.
	 * @tparam enabled Vector is available only for arithmetic types.
	 * @brief A mathematical vector.
	 * @see http://en.cppreference.com/w/cpp/numeric/valarray
	 */
	template <class T, unsigned int Size, typename enabled = typename std::enable_if_t<std::is_arithmetic_v<T>>>
	class Vector : public std::valarray<T>
	{
	public:
		/**
		 * @fn constexpr Vector()
		 * @brief Default constructor.
		 * Build a vector filled with 0.
		 * @throw
		 */
		inline Vector();

		/**
		 * @fn Vector(const Vector<U, Size> & rhs)
		 * @tparam U The type of the elements in the second vector.
		 * @param[in] rhs The vector to cast.
		 * @brief Cast constructor from a vector of another type.
		 * @throw
		 */
		template <class U> inline Vector(const Vector<U, Size> & rhs);

		/**
		 * @fn Vector(const std::initializer_list<T> &  il)
		 * @param[in] il The list of elements to set in the vector.
		 * @brief Cast constructor from list of initialization.
		 * @throw
		 */
		Vector(const std::initializer_list<T> &  il);

		/**
		 * @fn Vector(const Vector<T, Size, enabled> & copy)
		 * @param[in] copy The vector to copy from.
		 * @brief Default copy constructor.
		 * @throw
		 */
		Vector(const Vector<T, Size, enabled> & copy) = default;

		/**
		 * @fn Vector(Vector<T, Size, enabled> && move) noexcept
		 * @param[in] move The vector to move.
		 * @brief Default move constructor.
		 * @throw noexcept
		 */
		Vector(Vector<T, Size, enabled> && move) noexcept = default;

		/**
		 * @fn Vector(std::valarray<T> && move)
		 * @param[in] move The array of value to move.
		 * @brief Default move constructor from array to vector.
		 * @throw
		 */
		inline Vector(std::valarray<T> && move);

		/**
		 * @fn ~Vector()
		 * @brief Default destructor.
		 * @throw noexcept
		 */
		~Vector() noexcept = default;

		/**
		 * @fn Vector<T, Size, enabled> & operator=(const Vector<T, Size, enabled> & copy)
		 * @param[in] copy The vector to copy from.
		 * @return The vector copied.
		 * @brief Default copy assignment operator.
		 * @throw
		 */
		Vector<T, Size, enabled> & operator=(const Vector<T, Size, enabled> & copy) = default;

		/**
		 * @fn Vector<T, Size, enabled> & operator=(Vector<T, Size, enabled> && move) noexcept
		 * @param[in] move The vector to move.
		 * @return The vector moved.
		 * @brief Default move assignment operator.
		 * @throw noexcept
		 */
		Vector<T, Size, enabled> & operator=(Vector<T, Size, enabled> && move) noexcept = default;

		/**
		 * @fn Vector<T, Size, enabled> & operator=(const std::initializer_list<T> & il)
		 * @param[in] il The list of elements to set in the vector.
		 * @return The vector set.
		 * @brief Cast assignment operator from list of initialization.
		 * @throw
		 */
		Vector<T, Size, enabled> & operator=(const std::initializer_list<T> & il);

		/**
		 * @fn const T & operator[](const unsigned int index) const
		 * @param[in] index The index of the element to access.
		 * @return An element of the vector.
		 * @brief Access a specific element of the vector.
		 * @throw
		 */
		inline const T & operator[](const unsigned int index) const;

		/**
		 * @fn T & operator[](const unsigned int index)
		 * @param[in] index The index of the element to access.
		 * @return An element of the vector.
		 * @brief Access a specific element of the vector.
		 * @throw
		 */
		inline T & operator[](const unsigned int index);

		/**
		 * @fn Vector<T, Size, enabled> operator[](std::slice_array<T> slicearr) const
		 * @param[in] slicearr The selector index.
		 * @return Data structure containing references to the selected elements.
		 * @brief Retrieve some elements of the vector.
		 * @throw
		 */
		inline Vector<T, Size, enabled> operator[](std::slice_array<T> slicearr) const;

		/**
		 * @fn std::slice_array<T> operator[](std::slice_array<T> slicearr)
		 * @param[in] slicearr The selector index.
		 * @return Data structure containing references to the selected elements.
		 * @brief Retrieve some elements of the vector.
		 * @throw
		 */
		inline std::slice_array<T> operator[](std::slice_array<T> slicearr);

		/**
		 * @fn Vector<T, Size, enabled> operator[](std::gslice_array<T> & gslicearr) const
		 * @param[in] gslicearr The selector index.
		 * @return Data structure containing references to the selected elements.
		 * @brief Retrieve some elements of the vector.
		 * @throw
		 */
		inline Vector<T, Size, enabled> operator[](std::gslice_array<T> & gslicearr) const;

		/**
		 * @fn std::gslice_array<T> operator[](std::gslice_array<T> & gslicearr)
		 * @param[in] gslicearr The selector index.
		 * @return Data structure containing references to the selected elements.
		 * @brief Retrieve some elements of the vector.
		 * @throw
		 */
		inline std::gslice_array<T> operator[](std::gslice_array<T> & gslicearr);

		/**
		 * @fn Vector<T, Size, enabled> operator[](const Vector<bool, Size> & boolarr) const
		 * @param[in] boolarr The selector index.
		 * @return Data structure containing references to the selected elements.
		 * @brief Retrieve some elements of the vector.
		 * @throw
		 */
//		inline Vector<T, Size, enabled> operator[](const Vector<bool, Size> & boolarr) const;

//		inline std::mask_array<T> operator[](const Vector<bool, Size> & maskarr);
//		inline Vector<T, Size, enabled> operator[](const Vector<bool, Size> & indarr) const;
//		inline std::indirect_array<T> operator[](const Vector<bool, Size> & indarr);

		/**
		 * @fn Vector<T, Size, enabled> operator+() const noexcept
		 * @return A vector of numerical values.
		 * @brief Get numerical values of the vector content.
		 * @throw noexcept
		 */
		inline Vector<T, Size, enabled> operator+() const noexcept;

		/**
		 * @fn Vector<T, Size, enabled> operator-() const noexcept
		 * @return A vector of negative values.
		 * @brief Get negative values of the vector content.
		 * @throw noexcept
		 */
		inline Vector<T, Size, enabled> operator-() const noexcept;

		/**
		 * @fn Vector<T, Size, enabled> operator~() const noexcept
		 * @return A vector of elements with one's complement.
		 * @brief Get the one's complement of the vector content.
		 * @throw noexcept
		 */
		template <typename forward = T, typename = std::enable_if_t<std::is_enum_v<forward> || std::is_integral_v<forward>>>
		inline Vector<T, Size, enabled> operator~() const noexcept;

		/**
		 * @fn Vector<bool, Size> operator!() const noexcept
		 * @return A vector of elements with one's complement.
		 * @brief Get the one's complement of the vector content.
		 * @throw noexcept
		 */
		template <typename forward = T, typename = std::enable_if_t<std::is_enum_v<forward> || std::is_integral_v<forward>>>
		inline Vector<bool, Size> operator!() const noexcept;

		/**
		 * @fn Vector<T, Size, enabled> & operator+=(const Vector<T, Size, enabled> & v)
		 * @param[in] v The vector to add to.
		 * @return The vector set.
		 * @brief Sum the current vector with another one.
		 * @throw
		 */
		inline Vector<T, Size, enabled> & operator+=(const Vector<T, Size, enabled> & v);

		/**
		 * @fn Vector<T, Size, enabled> & operator-=(const Vector<T, Size, enabled> & v)
		 * @param[in] v The vector to subtract to.
		 * @return The vector set.
		 * @brief Subtract the vector from the current one.
		 * @throw
		 */
		inline Vector<T, Size, enabled> & operator-=(const Vector<T, Size, enabled> & v);

		/**
		 * @fn Vector<T, Size, enabled> & operator*=(const Vector<T, Size, enabled> & v)
		 * @param[in] v The vector to multiply to.
		 * @return The vector set.
		 * @brief Multiply the vector to the current one.
		 * @throw
		 */
		inline Vector<T, Size, enabled> & operator*=(const Vector<T, Size, enabled> & v);

		/**
		 * @fn Vector<T, Size, enabled> & operator/=(const Vector<T, Size, enabled> & v)
		 * @param[in] v The vector to divide to.
		 * @return The vector set.
		 * @brief Divide the current vector by the other.
		 * @throw
		 */
		inline Vector<T, Size, enabled> & operator/=(const Vector<T, Size, enabled> & v);

		/**
		 * @fn Vector<T, Size, enabled> & operator%=(const Vector<T, Size, enabled> & v)
		 * @param[in] v The vector of modulo to apply to.
		 * @return The vector set.
		 * @brief Apply the modulo operation to the vector with a one-to-one relationship.
		 * @throw
		 */
		template <typename forward = T, typename = std::enable_if_t<std::is_enum_v<forward> || std::is_integral_v<forward>>>
		inline Vector<T, Size, enabled> & operator%=(const Vector<T, Size, enabled> & v);

		/**
		 * @fn Vector<T, Size, enabled> & operator&=(const Vector<T, Size, enabled> & v)
		 * @param[in] v The right hand side to apply to.
		 * @return The vector set.
		 * @brief Apply the unary and operation to the vector with a one-to-one relationship.
		 * @throw
		 */
		template <typename forward = T, typename = std::enable_if_t<std::is_enum_v<forward> || std::is_integral_v<forward>>>
		inline Vector<T, Size, enabled> & operator&=(const Vector<T, Size, enabled> & v);

		/**
		 * @fn Vector<T, Size, enabled> & operator|=(const Vector<T, Size, enabled> & v)
		 * @param[in] v The right hand side to apply to.
		 * @return The vector set.
		 * @brief Apply the unary or operation to the vector with a one-to-one relationship.
		 * @throw
		 */
		template <typename forward = T, typename = std::enable_if_t<std::is_enum_v<forward> || std::is_integral_v<forward>>>
		inline Vector<T, Size, enabled> & operator|=(const Vector<T, Size, enabled> & v);

		/**
		 * @fn Vector<T, Size, enabled> & operator^=(const Vector<T, Size, enabled> & v)
		 * @param[in] v The right hand side to apply to.
		 * @return The vector set.
		 * @brief Apply the unary xor operation to the vector with a one-to-one relationship.
		 * @throw
		 */
		template <typename forward = T, typename = std::enable_if_t<std::is_enum_v<forward> || std::is_integral_v<forward>>>
		inline Vector<T, Size, enabled> & operator^=(const Vector<T, Size, enabled> & v);

		/**
		 * @fn Vector<T, Size, enabled> & operator<<=(const Vector<T, Size, enabled> & v)
		 * @param[in] v The right hand side to apply to.
		 * @return The vector set.
		 * @brief Apply the binary shift left operation to the vector with a one-to-one relationship.
		 * @throw
		 */
		template <typename forward = T, typename = std::enable_if_t<std::is_enum_v<forward> || std::is_integral_v<forward>>>
		inline Vector<T, Size, enabled> & operator<<=(const Vector<T, Size, enabled> & v);

		/**
		 * @fn Vector<T, Size, enabled> & operator>>=(const Vector<T, Size, enabled> & v)
		 * @param[in] v The right hand side to apply to.
		 * @return The vector set.
		 * @brief Apply the binary shift right operation to the vector with a one-to-one relationship.
		 * @throw
		 */
		template <typename forward = T, typename = std::enable_if_t<std::is_enum_v<forward> || std::is_integral_v<forward>>>
		inline Vector<T, Size, enabled> & operator>>=(const Vector<T, Size, enabled> & v);

		/**
		 * @fn Vector<T, Size, enabled> & operator+=(const T & val)
		 * @param[in] val The right hand side to apply to.
		 * @return The vector set.
		 * @brief Apply the sum operation to the vector with a one-to-all relationship.
		 * @throw
		 */
		inline Vector<T, Size, enabled> & operator+=(const T & val);

		/**
		 * @fn Vector<T, Size, enabled> & operator-=(const T & val)
		 * @param[in] val The right hand side to apply to.
		 * @return The vector set.
		 * @brief Apply the subtraction operation to the vector with a one-to-all relationship.
		 * @throw
		 */
		inline Vector<T, Size, enabled> & operator-=(const T & val);

		/**
		 * @fn Vector<T, Size, enabled> & operator*=(const T & val)
		 * @param[in] val The right hand side to apply to.
		 * @return The vector set.
		 * @brief Apply the multiplication operation to the vector with a one-to-all relationship.
		 * @throw
		 */
		inline Vector<T, Size, enabled> & operator*=(const T & val);

		/**
		 * @fn Vector<T, Size, enabled> & operator/=(const T & val)
		 * @param[in] val The right hand side to apply to.
		 * @return The vector set.
		 * @brief Apply the division operation to the vector with a one-to-all relationship.
		 * @throw
		 */
		inline Vector<T, Size, enabled> & operator/=(const T & val);

		/**
		 * @fn Vector<T, Size, enabled> & operator%=(const T & val)
		 * @param[in] val The right hand side to apply to.
		 * @return The vector set.
		 * @brief Apply the modulo operation to the vector with a one-to-all relationship.
		 * @throw
		 */
		template <typename forward = T, typename = std::enable_if_t<std::is_enum_v<forward> || std::is_integral_v<forward>>>
		inline Vector<T, Size, enabled> & operator%=(const T & val);

		/**
		 * @fn Vector<T, Size, enabled> & operator&=(const T & val)
		 * @param[in] val The right hand side to apply to.
		 * @return The vector set.
		 * @brief Apply the unary and operation to the vector with a one-to-all relationship.
		 * @throw
		 */
		template <typename forward = T, typename = std::enable_if_t<std::is_enum_v<forward> || std::is_integral_v<forward>>>
		inline Vector<T, Size, enabled> & operator&=(const T & val);

		/**
		 * @fn Vector<T, Size, enabled> & operator|=(const T & val)
		 * @param[in] val The right hand side to apply to.
		 * @return The vector set.
		 * @brief Apply the unary or operation to the vector with a one-to-all relationship.
		 * @throw
		 */
		template <typename forward = T, typename = std::enable_if_t<std::is_enum_v<forward> || std::is_integral_v<forward>>>
		inline Vector<T, Size, enabled> & operator|=(const T & val);

		/**
		 * @fn Vector<T, Size, enabled> & operator^=(const T & val)
		 * @param[in] val The right hand side to apply to.
		 * @return The vector set.
		 * @brief Apply the unary xor operation to the vector with a one-to-all relationship.
		 * @throw
		 */
		template <typename forward = T, typename = std::enable_if_t<std::is_enum_v<forward> || std::is_integral_v<forward>>>
		inline Vector<T, Size, enabled> & operator^=(const T & val);

		/**
		 * @fn Vector<T, Size, enabled> & operator<<=(const T & val)
		 * @param[in] val The right hand side to apply to.
		 * @return The vector set.
		 * @brief Apply the binary shift left operation to the vector with a one-to-all relationship.
		 * @throw
		 */
		template <typename forward = T, typename = std::enable_if_t<std::is_enum_v<forward> || std::is_integral_v<forward>>>
		inline Vector<T, Size, enabled> & operator<<=(const T & val);

		/**
		 * @fn Vector<T, Size, enabled> & operator>>=(const T & val)
		 * @param[in] val The right hand side to apply to.
		 * @return The vector set.
		 * @brief Apply the binary shift right operation to the vector with a one-to-all relationship.
		 * @throw
		 */
		template <typename forward = T, typename = std::enable_if_t<std::is_enum_v<forward> || std::is_integral_v<forward>>>
		inline Vector<T, Size, enabled> & operator>>=(const T & val);

		/**
		 * @see http://en.cppreference.com/w/cpp/numeric/valarray/min
		 */
		using std::valarray<T>::min;

		/**
		 * @see http://en.cppreference.com/w/cpp/numeric/valarray/max
		 */
		using std::valarray<T>::max;

		/**
		 * @see http://en.cppreference.com/w/cpp/numeric/valarray/sum
		 */
		using std::valarray<T>::sum;

		/**
		 * @fn Vector<T, Size, enabled> shift(int count) const
		 * @param[in] count The shift to apply.
		 * @return The vector shifted.
		 * @brief Shift all the vector elements on the left.
		 * @throw
		 */
		inline Vector<T, Size, enabled> shift(int count) const;

		/**
		 * @fn Vector<T, Size, enabled> cshift(int count) const
		 * @param[in] count The shift to apply.
		 * @return The vector shifted.
		 * @brief Shift all the vector elements on the right.
		 * @throw
		 */
		inline Vector<T, Size, enabled> cshift(int count) const;

		/**
		 * @fn Vector<T, Size, enabled> apply(T func(T)) const
		 * @param[in] func The function to apply.
		 * @return A vector build from the current one transformed.
		 * @brief Apply a function to all elements of the vector.
		 * @throw
		 * @remark Should we use an std::function here ?
		 */
		inline Vector<T, Size, enabled> apply(T func(T)) const;

		/**
		 * @fn Vector<T, Size, enabled> apply(T func(const T &)) const
		 * @param[in] func The function to apply.
		 * @return A vector build from the current one transformed.
		 * @brief Apply a function to all elements of the vector.
		 * @throw
		 * @remark Should we use an std::function here ?
		 */
		inline Vector<T, Size, enabled> apply(T func(const T &)) const;

		/**
		 * @fn Vector<T, Size, enabled> operator+(const Vector<T, Size, enabled> & rhs) const
		 * @param[in] rhs The vector to sum to.
		 * @return The sum of the two vectors.
		 * @brief Sum the current vector with another one.
		 * @throw
		 */
		inline Vector<T, Size, enabled> operator+(const Vector<T, Size, enabled> & rhs) const;

		/**
		 * @fn Vector<T, Size, enabled> operator-(const Vector<T, Size, enabled> & rhs) const
		 * @param[in] rhs The vector to subtract from.
		 * @return The subtraction of the two vectors.
		 * @brief Subtract the current vector by another one.
		 * @throw
		 */
		inline Vector<T, Size, enabled> operator-(const Vector<T, Size, enabled> & rhs) const;

		/**
		 * @fn Vector<T, Size, enabled> operator*(const Vector<T, Size, enabled> & rhs) const
		 * @param[in] rhs The vector to multiply to.
		 * @return The multiplication of the two vectors.
		 * @brief Perform a vector-vector multiplication.
		 * @throw
		 */
		inline Vector<T, Size, enabled> operator*(const Vector<T, Size, enabled> & rhs) const;

		/**
		 * @fn Vector<T, Size, enabled> operator/(const Vector<T, Size, enabled> & rhs) const
		 * @param[in] rhs The vector to divide from.
		 * @return The division of the two vector.
		 * @brief Divide the current vector by another one.
		 * @throw
		 */
		inline Vector<T, Size, enabled> operator/(const Vector<T, Size, enabled> & rhs) const;

		/**
		 * @fn Vector<T, Size, enabled> operator%(const Vector<T, Size, enabled> & rhs) const
		 * @param[in] rhs The right hand side to apply to.
		 * @return The application of modulo operation on the current vector.
		 * @brief Apply the modulo operation to the vector with a one-to-one relationship.
		 * @throw
		 */
		template <typename forward = T, typename = std::enable_if_t<std::is_enum_v<forward> || std::is_integral_v<forward>>>
		inline Vector<T, Size, enabled> operator%(const Vector<T, Size, enabled> & rhs) const;

		/**
		 * @fn Vector<T, Size, enabled> operator&(const Vector<T, Size, enabled> & rhs) const
		 * @param[in] rhs The right hand side to apply to.
		 * @return The application of unary and operation on the current matrix.
		 * @brief Apply the unary and operation to the matrix with a one-to-one relationship.
		 * @throw
		 */
		template <typename forward = T, typename = std::enable_if_t<std::is_enum_v<forward> || std::is_integral_v<forward>>>
		inline Vector<T, Size, enabled> operator&(const Vector<T, Size, enabled> & rhs) const;

		/**
		 * @fn Vector<T, Size, enabled> operator|(const Vector<T, Size, enabled> & rhs) const
		 * @param[in] rhs The right hand side to apply to.
		 * @return The application of unary or operation on the current vector.
		 * @brief Apply the unary or operation to the vector with a one-to-one relationship.
		 * @throw
		 */
		template <typename forward = T, typename = std::enable_if_t<std::is_enum_v<forward> || std::is_integral_v<forward>>>
		inline Vector<T, Size, enabled> operator|(const Vector<T, Size, enabled> & rhs) const;

		/**
		 * @fn Vector<T, Size, enabled> operator^(const Vector<T, Size, enabled> & rhs) const
		 * @param[in] rhs The right hand side to apply to.
		 * @return The application of unary xor operation on the current vector.
		 * @brief Apply the unary xor operation to the vector with a one-to-one relationship.
		 * @throw
		 */
		template <typename forward = T, typename = std::enable_if_t<std::is_enum_v<forward> || std::is_integral_v<forward>>>
		inline Vector<T, Size, enabled> operator^(const Vector<T, Size, enabled> & rhs) const;

		/**
		 * @fn Vector<T, Size, enabled> operator<<(const Vector<T, Size, enabled> & rhs) const
		 * @param[in] rhs The right hand side to apply to.
		 * @return The application of binary shift left operation on the current vector.
		 * @brief Apply the binary shift left operation to the vector with a one-to-one relationship.
		 * @throw
		 */
		template <typename forward = T, typename = std::enable_if_t<std::is_enum_v<forward> || std::is_integral_v<forward>>>
		inline Vector<T, Size, enabled> operator<<(const Vector<T, Size, enabled> & rhs) const;

		/**
		 * @fn Vector<T, Size, enabled> operator>>(const Vector<T, Size, enabled> & rhs) const
		 * @param[in] rhs The right hand side to apply to.
		 * @return The application of binary shift right operation on the current vector.
		 * @brief Apply the binary shift right operation to the vector with a one-to-one relationship.
		 * @throw
		 */
		template <typename forward = T, typename = std::enable_if_t<std::is_enum_v<forward> || std::is_integral_v<forward>>>
		inline Vector<T, Size, enabled> operator>>(const Vector<T, Size, enabled> & rhs) const;

		/**
		 * @fn Vector<bool, Size> operator&&(const Vector<T, Size, enabled> & rhs) const
		 * @param[in] rhs The right hand side to apply to.
		 * @return The application of binary and operation on the current vector.
		 * @brief Apply the binary and operation to the vector with a one-to-one relationship.
		 * @throw
		 */
		template <typename forward = T, typename = std::enable_if_t<std::is_enum_v<forward> || std::is_integral_v<forward>>>
		inline Vector<bool, Size> operator&&(const Vector<T, Size, enabled> & rhs) const;

		/**
		 * @fn Vector<bool, Size> operator||(const Vector<T, Size, enabled> & rhs) const
		 * @param[in] rhs The right hand side to apply to.
		 * @return The application of binary or operation on the current vector.
		 * @brief Apply the binary or operation to the vector with a one-to-one relationship.
		 * @throw
		 */
		template <typename forward = T, typename = std::enable_if_t<std::is_enum_v<forward> || std::is_integral_v<forward>>>
		inline Vector<bool, Size> operator||(const Vector<T, Size, enabled> & rhs) const;

		/**
		 * @fn Vector<T, Size, enabled> operator+(const Vector<T, Size, enabled> & rhs) const
		 * @param[in] rhs The right hand side to apply to.
		 * @return The application of addition operation on the current vector.
		 * @brief Apply the addition operation to the vector with a one-to-all relationship.
		 * @throw
		 */
		inline Vector<T, Size, enabled> operator+(const T & rhs) const;

		/**
		 * @fn Vector<T, Size, enabled> operator-(const Vector<T, Size, enabled> & rhs) const
		 * @param[in] rhs The right hand side to apply to.
		 * @return The application of subtraction operation on the current vector.
		 * @brief Apply the subtraction operation to the vector with a one-to-all relationship.
		 * @throw
		 */
		inline Vector<T, Size, enabled> operator-(const T & rhs) const;

		/**
		 * @fn Vector<T, Size, enabled> operator*(const Vector<T, Size, enabled> & rhs) const
		 * @param[in] rhs The right hand side to apply to.
		 * @return The application of multiplication operation on the current vector.
		 * @brief Apply the multiplication operation to the vector with a one-to-all relationship.
		 * @throw
		 */
		inline Vector<T, Size, enabled> operator*(const T & rhs) const;

		/**
		 * @fn Vector<T, Size, enabled> operator/(const Vector<T, Size, enabled> & rhs) const
		 * @param[in] rhs The right hand side to apply to.
		 * @return The application of division operation on the current vector.
		 * @brief Apply the division operation to the vector with a one-to-all relationship.
		 * @throw
		 */
		inline Vector<T, Size, enabled> operator/(const T & rhs) const;

		/**
		 * @fn Vector<T, Size, enabled> operator%(const Vector<T, Size, enabled> & rhs) const
		 * @param[in] rhs The right hand side to apply to.
		 * @return The application of modulo operation on the current vector.
		 * @brief Apply the modulo operation to the vector with a one-to-all relationship.
		 * @throw
		 */
		template <typename forward = T, typename = std::enable_if_t<std::is_enum_v<forward> || std::is_integral_v<forward>>>
		inline Vector<T, Size, enabled> operator%(const T & rhs) const;

		/**
		 * @fn Vector<T, Size, enabled> operator&(const Vector<T, Size, enabled> & rhs) const
		 * @param[in] rhs The right hand side to apply to.
		 * @return The application of unary and operation on the current matrix.
		 * @brief Apply the unary and operation to the matrix with a one-to-all relationship.
		 * @throw
		 */
		template <typename forward = T, typename = std::enable_if_t<std::is_enum_v<forward> || std::is_integral_v<forward>>>
		inline Vector<T, Size, enabled> operator&(const T & rhs) const;

		/**
		 * @fn Vector<T, Size, enabled> operator|(const Vector<T, Size, enabled> & rhs) const>
		 * @param[in] rhs The right hand side to apply to.
		 * @return The application of unary or operation on the current vector.
		 * @brief Apply the unary or operation to the vector with a one-to-all relationship.
		 * @throw
		 */
		template <typename forward = T, typename = std::enable_if_t<std::is_enum_v<forward> || std::is_integral_v<forward>>>
		inline Vector<T, Size, enabled> operator|(const T & rhs) const;

		/**
		 * @fn Vector<T, Size, enabled> operator^(const Vector<T, Size, enabled> & rhs) const
		 * @param[in] rhs The right hand side to apply to.
		 * @return The application of unary xor operation on the current vector.
		 * @brief Apply the unary xor operation to the vector with a one-to-all relationship.
		 * @throw
		 */
		template <typename forward = T, typename = std::enable_if_t<std::is_enum_v<forward> || std::is_integral_v<forward>>>
		inline Vector<T, Size, enabled> operator^(const T & rhs) const;

		/**
		 * @fn Vector<T, Size, enabled> operator<<(const Vector<T, Size, enabled> & rhs) const
		 * @param[in] rhs The right hand side to apply to.
		 * @return The application of binary shift left operation on the current vector.
		 * @brief Apply the binary shift left operation to the vector with a one-to-all relationship.
		 * @throw
		 */
		template <typename forward = T, typename = std::enable_if_t<std::is_enum_v<forward> || std::is_integral_v<forward>>>
		inline Vector<T, Size, enabled> operator<<(const T & rhs) const;

		/**
		 * @fn Vector<T, Size, enabled> operator>>(const Vector<T, Size, enabled> & rhs) const
		 * @param[in] rhs The right hand side to apply to.
		 * @return The application of binary shift right operation on the current vector.
		 * @brief Apply the binary shift right operation to the vector with a one-to-all relationship.
		 * @throw
		 */
		template <typename forward = T, typename = std::enable_if_t<std::is_enum_v<forward> || std::is_integral_v<forward>>>
		inline Vector<T, Size, enabled> operator>>(const T & rhs) const;

		/**
		 * @fn Vector<bool, Size> operator&&(const Vector<T, Size, enabled> & rhs) const
		 * @param[in] rhs The right hand side to apply to.
		 * @return The application of binary and operation on the current vector.
		 * @brief Apply the binary and operation to the vector with a one-to-all relationship.
		 * @throw
		 */
		template <typename forward = T, typename = std::enable_if_t<std::is_enum_v<forward> || std::is_integral_v<forward>>>
		inline Vector<bool, Size> operator&&(const T & rhs) const;

		/**
		 * @fn Vector<bool, Size> operator||(const Vector<T, Size, enabled> & rhs) const
		 * @param[in] rhs The right hand side to apply to.
		 * @return The application of binary or operation on the current vector.
		 * @brief Apply the binary or operation to the vector with a one-to-all relationship.
		 * @throw
		 */
		template <typename forward = T, typename = std::enable_if_t<std::is_enum_v<forward> || std::is_integral_v<forward>>>
		inline Vector<bool, Size> operator||(const T & rhs) const;

		/**
		 * @fn bool operator==(const Vector<T, Size, enabled> & rhs) const
		 * @param[in] rhs The vector to compare to.
		 * @return True, if the vectors are equals, false else.
		 * @brief Compare the two vectors to check if they are equals (member to member) or not.
		 * @throw
		 */
		bool operator==(const Vector<T, Size, enabled> & rhs) const;

//		Vector<bool, Size> operator==(const Vector<T, Size, enabled> & rhs);

		/**
		 * @fn bool operator!=(const Vector<T, Size, enabled> & rhs)
		 * @param[in] rhs The vector to compare to.
		 * @return A vector of booleans with the following value: true, if the members are not equals, false else.
		 * @brief Compare the two vectors to check if they are different (member to member) or not.
		 * @throw
		 */
		bool operator!=(const Vector<T, Size, enabled> & rhs);

		/**
		 * @fn Vector<bool, Size> operator<(const Vector<T, Size, enabled> & rhs)
		 * @param[in] rhs The vector to compare to.
		 * @return A vector of booleans with the following value: true, if the members are smaller, false else.
		 * @brief Compare the two vectors to check if the current one is smaller (member to member) or not.
		 * @throw
		 */
		Vector<bool, Size> operator<(const Vector<T, Size, enabled> & rhs);

		/**
		 * @fn Vector<bool, Size> operator<=(const Vector<T, Size, enabled> & rhs)
		 * @param[in] rhs The vector to compare to.
		 * @return A vector of booleans with the following value: true, if the members are smaller or equal, false else.
		 * @brief Compare the two vectors to check if the current one is smaller (member to member) or not.
		 * @throw
		 */
		Vector<bool, Size> operator<=(const Vector<T, Size, enabled> & rhs);

		/**
		 * @fn Vector<bool, Size> operator>(const Vector<T, Size, enabled> & rhs)
		 * @param[in] rhs The vector to compare to.
		 * @return A vector of booleans with the following value: true, if the members are greater, false else.
		 * @brief Compare the two vectors to check if the current one is greater (member to member) or not.
		 * @throw
		 */
		Vector<bool, Size> operator>(const Vector<T, Size, enabled> & rhs);

		/**
		 * @fn Vector<bool, Size> operator>=(const Vector<T, Size, enabled> & rhs)
		 * @param[in] rhs The vector to compare to.
		 * @return A vector of booleans with the following value: true, if the members are greater or equal, false else.
		 * @brief Compare the two vectors to check if the current one is greater or equal (member to member) or not.
		 * @throw
		 */
		Vector<bool, Size> operator>=(const Vector<T, Size, enabled> & rhs);

		/**
		 * @fn Vector<bool, Size> operator==(const T & rhs)
		 * @param[in] rhs The element to compare to.
		 * @return A vector of booleans with the following value: true, if the members are equal, false else.
		 * @brief Compare the right hand side to each element of the vector to check if they are equal or not.
		 * @throw
		 */
		Vector<bool, Size> operator==(const T & rhs);

		/**
		 * @fn Vector<bool, Size> operator!=(const T & rhs)
		 * @param[in] rhs The element to compare to.
		 * @return A vector of booleans with the following value: true, if the members are different, false else.
		 * @brief Compare the right hand side to each element of the vector to check if they are different or not.
		 * @throw
		 */
		Vector<bool, Size> operator!=(const T & rhs);

		/**
		 * @fn Vector<bool, Size> operator<(const T & rhs)
		 * @param[in] rhs The element to compare to.
		 * @return A vector of booleans with the following value: true, if the members are smaller, false else.
		 * @brief Compare the right hand side to each element of the vector to check if they are smaller or not.
		 * @throw
		 */
		Vector<bool, Size> operator<(const T & rhs);

		/**
		 * @fn Vector<bool, Size> operator<=(const T & rhs)
		 * @param[in] rhs The element to compare to.
		 * @return A vector of booleans with the following value: true, if the members are smaller or equal, false else.
		 * @brief Compare the right hand side to each element of the vector to check if they are smaller or equal or not.
		 * @throw
		 */
		Vector<bool, Size> operator<=(const T & rhs);

		/**
		 * @fn Vector<bool, Size> operator>(const T & rhs)
		 * @param[in] rhs The element to compare to.
		 * @return A vector of booleans with the following value: true, if the members are greater, false else.
		 * @brief Compare the right hand side to each element of the vector to check if they are greater or not.
		 * @throw
		 */
		Vector<bool, Size> operator>(const T & rhs);

		/**
		 * @fn Vector<bool, Size> operator>=(const T & rhs)
		 * @param[in] rhs The element to compare to.
		 * @return A vector of booleans with the following value: true, if the members are greater or equal, false else.
		 * @brief Compare the right hand side to each element of the vector to check if they are greater or equal, or not.
		 * @throw
		 */
		Vector<bool, Size> operator>=(const T & rhs);

		/**
		 * @fn Vector<T, Size, enabled> abs() const
		 * @return A vector of the absolute value of the members.
		 * @brief Get the vector with the absolute value of each member.
		 * @throw
		 */
		template <typename forward = T, typename = std::enable_if_t<std::is_signed_v<forward>>>
		inline Vector<T, Size, enabled> abs() const;

		/**
		 * @fn Vector<T, Size, enabled> exp() const
		 * @return A vector with the exponential applied on each member.
		 * @brief Apply the exponential to each member of the vector.
		 * @throw
		 */
		inline Vector<T, Size, enabled> exp() const;

		/**
		 * @fn Vector<T, Size, enabled> log() const
		 * @return A vector with the logarithm applied on each member.
		 * @brief Apply the logarithm to each member of the vector.
		 * @throw
		 */
		inline Vector<T, Size, enabled> log() const;

		/**
		 * @fn Vector<T, Size, enabled> log10() const
		 * @return A vector with the base 10 logarithm applied on each member.
		 * @brief Apply the base 10 logarithm to each member of the vector.
		 * @throw
		 */
		inline Vector<T, Size, enabled> log10() const;

		/**
		 * @fn Vector<T, Size, enabled> pow(const Vector<T, Size, enabled> & exp) const
		 * @param[in] exp The power to apply.
		 * @return A vector with the power applied on each member.
		 * @brief Apply the power to each member of the vector.
		 * @throw
		 */
		inline Vector<T, Size, enabled> pow(const Vector<T, Size, enabled> & exp) const;

		/**
		 * @fn Vector<T, Size, enabled> pow(const T & exp) const
		 * @param[in] exp The power to apply.
		 * @return A vector with the power applied on each member.
		 * @brief Apply the power to each member of the vector.
		 * @throw
		 */
		inline Vector<T, Size, enabled> pow(const T & exp) const;

		/**
		 * @fn Vector<T, Size, enabled> sqrt() const
		 * @return A vector with the square root applied on each member.
		 * @brief Apply the square root to each member of the vector.
		 * @throw
		 */
		inline Vector<T, Size, enabled> sqrt() const;

		/**
		 * @fn Vector<T, Size, enabled> sin() const
		 * @return A vector with the sine applied on each member.
		 * @brief Apply the sine to each member of the vector.
		 * @throw
		 */
		inline Vector<T, Size, enabled> sin() const;

		/**
		 * @fn Vector<T, Size, enabled> cos() const
		 * @return A vector with the cosine applied on each member.
		 * @brief Apply the cosine to each member of the vector.
		 * @throw
		 */
		inline Vector<T, Size, enabled> cos() const;

		/**
		 * @fn Vector<T, Size, enabled> tan() const
		 * @return A vector with the tangent applied on each member.
		 * @brief Apply the tangent to each member of the vector.
		 * @throw
		 */
		inline Vector<T, Size, enabled> tan() const;

		/**
		 * @fn Vector<T, Size, enabled> asin() const
		 * @return A vector with the argument sine applied on each member.
		 * @brief Apply the argument sine to each member of the vector.
		 * @throw
		 */
		inline Vector<T, Size, enabled> asin() const;

		/**
		 * @fn Vector<T, Size, enabled> acos() const
		 * @return A vector with the argument cosine applied on each member.
		 * @brief Apply the argument cosine to each member of the vector.
		 * @throw
		 */
		inline Vector<T, Size, enabled> acos() const;

		/**
		 * @fn Vector<T, Size, enabled> atan() const
		 * @return A vector with the argument tangent applied on each member.
		 * @brief Apply the argument tangent to each member of the vector.
		 * @throw
		 */
		inline Vector<T, Size, enabled> atan() const;

		/**
		 * @fn Vector<T, Size, enabled> atan2(const Vector<T, Size, enabled> & x) const
		 * @param[in] x The x value to use.
		 * @return A vector with the argument tangent of m/x applied on each member.
		 * @brief Apply the argument tangent of m/x to each member of the vector.
		 * @throw
		 */
		inline Vector<T, Size, enabled> atan2(const Vector<T, Size, enabled> & x) const;

		/**
		 * @fn Vector<T, Size, enabled> atan2(const T & x) const
		 * @param[in] x The x value to use.
		 * @return A vector with the argument tangent of m/x applied on each member.
		 * @brief Apply the argument tangent of m/X to each member of the vector.
		 * @throw
		 */
		inline Vector<T, Size, enabled> atan2(const T & x) const;

		/**
		 * @fn Vector<T, Size, enabled> sinh() const
		 * @return A vector with the hyperbolic sine applied on each member.
		 * @brief Apply the hyperbolic sine to each member of the vector.
		 * @throw
		 */
		inline Vector<T, Size, enabled> sinh() const;

		/**
		 * @fn Vector<T, Size, enabled> cosh() const
		 * @return A vector with the hyperbolic cosine applied on each member.
		 * @brief Apply the hyperbolic cosine to each member of the vector.
		 * @throw
		 */
		inline Vector<T, Size, enabled> cosh() const;

		/**
		 * @fn Vector<T, Size, enabled> tanh() const
		 * @return A vector with the hyperbolic tangent applied on each member.
		 * @brief Apply the hyperbolic tangent to each member of the vector.
		 * @throw
		 */
		inline Vector<T, Size, enabled> tanh() const;

		/**
		 * @fn Vector<double, Size> normalize()
		 * @return The vector normalized.
		 * @brief Normalize the vector.
		 * @throw
		 */
		inline Vector<double, Size> normalize();

		/**
		 * @fn double magnitude() const
		 * @return The magnitude (aka the norm) of the vector.
		 * @brief Get the magnitude of the vector.
		 * @throw
		 */
		inline double magnitude() const;

		/**
		 * @fn Vector<T, Size, enabled> cross(const Vector<T, Size, enabled> & rightOperand) const
		 * @param[in] rightOperand The right hand side to use.
		 * @return The cross product of the two vectors.
		 * @brief Apply a cross product operation between the two vectors.
		 * @throw
		 */
		template <unsigned short int forward = Size, typename = std::enable_if_t<HasCrossProduct<forward>::value>>
		inline Vector<T, Size, enabled> cross(const Vector<T, Size, enabled> & rightOperand) const;

		/**
		 * @fn T dot(const Vector<T, Size, enabled> & rightOperand) const
		 * @param[in] rightOperand The right hand side to use.
		 * @return The dot product of the two vectors.
		 * @brief Apply a dot product operation between the two vectors.
		 * @throw
		 */
		inline T dot(const Vector<T, Size, enabled> & rightOperand) const;

		/**
		 * @fn double distanceFrom(const Vector<T, Size, enabled> & rightOperand) const
		 * @param[in] rightOperand The right hand side to use.
		 * @return A distance between the two vectors.
		 * @brief Get the distance between the two vectors.
		 * Formally, distance between vectors does not make sense. It is mostly used, when a vector instance represents a point in spaces,
		 * as it is possible to compute a distance between to points.
		 * @throw
		 */
		inline double distanceFrom(const Vector<T, Size, enabled> & rightOperand) const;
	};
}

#include "utility/mathematics/vector.inl"

#endif // VECTOR_HPP
