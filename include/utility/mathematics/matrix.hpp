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

#ifndef MATRIX_HPP
#define MATRIX_HPP

#ifdef _MSC_VER
#	undef min
#	undef max
#endif

#include <valarray>

#include "utility/mathematics/vector.hpp"

namespace ece
{
	/**
	 * @class Matrix
	 * @extends std::valarray<T>
	 * @tparam T The numeric type of element in this matrix
	 * @tparam M The number of columns.
	 * @tparam N The number of rows.
	 * @tparam enabled Matrix is available only for arithmetic types.
	 * @brief A generic matrix class of any size and any type.
	 * @remark Add static_assert check for templated parameters
	 * @remark Add a constructor with an initialization_list of Vectors.
	 */
	template <class T, unsigned int M, unsigned int N, typename enabled = typename std::enable_if_t<std::is_arithmetic_v<T>>>
	class Matrix: public std::valarray<T>
	{
	public:
		/**
		 * @fn Matrix<T, M, N, enabled> Identity()
		 * @return An identity matrix.
		 * @brief Build an identity matrix.
		 * The matrix is filled with 0, except for the diagonal which is filled with 1.
		 * @throw
		 */
		static inline Matrix<T, M, N, enabled> Identity();

		/**
		 * @fn constexpr Matrix()
		 * @brief Default constructor.
		 * Build a matrix filled with 0.
		 * @throw
		 */
		inline Matrix();
		
		/**
		 * @fn inline Matrix(const T & value)
		 * @param[in] value The value to put in.
		 * @brief Build a matrix filled with the value.
		 * @throw
		 */
		inline Matrix(const T & value);

		/**
		 * @fn Matrix(const std::initializer_list<T> & il)
		 * @param[in] il The list of elements to set in the matrix.
		 * @brief Cast constructor from list of initialization.
		 * @throw
		 */
		inline Matrix(const std::initializer_list<T> & il);

		/**
		 * @fn Matrix(const Matrix<T, M, N, enabled> & copy)
		 * @param[in] copy The matrix to copy from.
		 * @brief Default copy constructor.
		 * @throw
		 */
		Matrix(const Matrix<T, M, N, enabled> & copy) = default;
		
		/**
		 * @fn Matrix(Matrix<T, M, N, enabled> && move) noexcept
		 * @param[in] move The matrix to move.
		 * @brief Default move constructor.
		 * @throw noexcept
		 */
		Matrix(Matrix<T, M, N, enabled> && move) noexcept = default;
		
		/**
		 * @fn Matrix(std::valarray<T> && move)
		 * @param[in] move The array of value to move.
		 * @brief Default move constructor from array to matrix.
		 * @throw
		 */
		inline Matrix(std::valarray<T> && move);

		/**
		 * @fn ~Matrix() noexcept
		 * @brief Default destructor.
		 * @throw noexcept
		 */
		~Matrix() noexcept = default;

		/**
		 * @fn Matrix<T, M, N, enabled> & operator=(const Matrix<T, M, N, enabled> & copy)
		 * @param[in] copy The matrix to copy from.
		 * @return The matrix copied.
		 * @brief Default copy assignment operator.
		 * @throw
		 */
		Matrix<T, M, N, enabled> & operator=(const Matrix<T, M, N, enabled> & copy) = default;
		
		/**
		 * @fn Matrix<T, M, N, enabled> & operator=(Matrix<T, M, N, enabled> && move) noexcept
		 * @param[in] move The matrix to move.
		 * @return The matrix moved.
		 * @brief Default move assignment operator.
		 * @throw noexcept
		 */
		Matrix<T, M, N, enabled> & operator=(Matrix<T, M, N, enabled> && move) noexcept = default;
		
		/**
		 * @fn Matrix<T, M, N, enabled> & operator=(const std::initializer_list<T> & il)
		 * @param[in] il The list of elements to set in the matrix.
		 * @return The matrix set.
		 * @brief Cast assignment operator from list of initialization.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> & operator=(const std::initializer_list<T> & il);

		/**
		 * @fn Matrix<T, M, N, enabled> & setIdentity()
		 * @return This matrix.
		 * @brief Set this matrix as an identity matrix.
		 * The matrix is filled with 0, except for the diagonal which is filled with 1.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> & setIdentity();

		/**
		 * @fn const Vector<T, M> & operator[](const unsigned int index) const
		 * @param[in] index The index of the row to access.
		 * @return A row of the matrix.
		 * @brief Access a specific row of the matrix.
		 * @throw
		 */
		inline Vector<T, M> operator[](const unsigned int index) const;

		/**
		 * @fn Vector<T, M> & operator[](const unsigned int index)
		 * @param[in] index The index of the row to access.
		 * @return A row of the matrix.
		 * @brief Access a specific row of the matrix.
		 * @throw
		 */
		inline Vector<T, M> operator[](const unsigned int index);
		
//		inline Matrix<T, M, N, enabled> operator[](std::slice slicearr) const;

		/**
		 * @fn std::slice_array<T> operator[](std::slice slicearr)
		 */
		inline std::slice_array<T> operator[](std::slice slicearr);

//		inline Matrix<T, M, N, enabled> operator[](std::gslice_array<T> & gslicearr) const;
//		inline std::gslice_array<T> operator[](std::gslice_array<T> & gslicearr);
//		inline Matrix<T, M, N, enabled> operator[](const Matrix<bool, M, N> & maskarr) const;
//		inline std::mask_array<T> operator[](const Matrix<bool, M, N> & maskarr);
//		inline Matrix<T, M, N, enabled> operator[](const Matrix<bool, M, N> & indarr) const;
//		inline std::indirect_array<T> operator[](const Matrix<bool, M, N> & indarr);

		/**
		 * @fn const Vector<T, M> & row(const unsigned int index) const
		 * @param[in] index The index of the row to access.
		 * @return A row of the matrix.
		 * @brief Access a specific row of the matrix.
		 * @throw
		 */ 
		inline Vector<T, M> row(const unsigned int index) const;
		
		/**
		 * @fn Vector<T, M> & row(const unsigned int index)
		 * @param[in] index The index of the row to access.
		 * @return A row of the matrix.
		 * @brief Access a specific row of the matrix.
		 * @throw
		 */
		inline Vector<T, M> row(const unsigned int index);
		
		/**
		 * @fn const Vector<T, M> & column(const unsigned int index) const
		 * @param[in] index The index of the column to access.
		 * @return A column of the matrix.
		 * @brief Access a specific column of the matrix.
		 * @throw
		 */
		inline Vector<T, N> column(const unsigned int index) const;
		
		/**
		 * @fn Vector<T, M> & column(const unsigned int index)
		 * @param[in] index The index of the column to access.
		 * @return A column of the matrix.
		 * @brief Access a specific column of the matrix.
		 * @throw
		 */
		inline Vector<T, N> column(const unsigned int index);

		/**
		 * @fn Matrix<T, M, N, enabled> operator+() const noexcept
		 * @return A matrix of numerical values.
		 * @brief Get numerical values of the matrix content.
		 * @throw noexcept
		 */
		inline Matrix<T, M, N, enabled> operator+() const noexcept;

		/**
		 * @fn Matrix<T, M, N, enabled> operator-() const noexcept
		 * @return A matrix of negative values.
		 * @brief Get negative values of the matrix content.
		 * @throw noexcept
		 */
		inline Matrix<T, M, N, enabled> operator-() const noexcept;

		/**
		 * @fn Matrix<T, M, N, enabled> operator~() const noexcept
		 * @return A matrix of elements with one's complement.
		 * @brief Get the one's complement of the matrix content.
		 * @throw noexcept
		 */
		inline Matrix<T, M, N, enabled> operator~() const noexcept;

		/**
		 * @fn Matrix<T, M, N, enabled> operator!() const noexcept
		 * @return A matrix of elements' negations.
		 * @brief Get the negation of the matrix content.
		 * @throw noexcept
		 */
		inline Matrix<bool, M, N> operator!() const noexcept;

		/**
		 * @fn Matrix<T, M, N, enabled> & operator+=(const Matrix<T, M, N, enabled> & v)
		 * @param[in] v The matrix to add to.
		 * @return The matrix set.
		 * @brief Sum the current matrix with another one.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> & operator+=(const Matrix<T, M, N, enabled> & v);
		
		/**
		 * @fn Matrix<T, M, N, enabled> & operator-=(const Matrix<T, M, N, enabled> & v)
		 * @param[in] v The matrix to subtract to.
		 * @return The matrix set.
		 * @brief Subtract the matrix from the current one.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> & operator-=(const Matrix<T, M, N, enabled> & v);
		
		/**
		 * @fn Matrix<T, M, N, enabled> & operator*=(const Matrix<T, M, N, enabled> & v)
		 * @param[in] v The matrix to multiply to.
		 * @return The matrix set.
		 * @brief Multiply the matrix to the current one.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> & operator*=(const Matrix<T, M, N, enabled> & v);
		
		/**
		 * @fn Matrix<T, M, N, enabled> & operator/=(const Matrix<T, M, N, enabled> & v)
		 * @param[in] v The matrix to divide to.
		 * @return The matrix set.
		 * @brief Divide the current matrix by the other.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> & operator/=(const Matrix<T, M, N, enabled> & v);
		
		/**
		 * @fn Matrix<T, M, N, enabled> & operator%=(const Matrix<T, M, N, enabled> & v)
		 * @param[in] v The matrix of modulo to apply to.
		 * @return The matrix set.
		 * @brief Apply the modulo operation to the matrix with a one-to-one relationship.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> & operator%=(const Matrix<T, M, N, enabled> & v);
		
		/**
		 * @fn Matrix<T, M, N, enabled> & operator&=(const Matrix<T, M, N, enabled> & v)
		 * @param[in] v The right hand side to apply to.
		 * @return The matrix set.
		 * @brief Apply the unary and operation to the matrix with a one-to-one relationship.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> & operator&=(const Matrix<T, M, N, enabled> & v);
		
		/**
		 * @fn Matrix<T, M, N, enabled> & operator|=(const Matrix<T, M, N, enabled> & v)
		 * @param[in] v The right hand side to apply to.
		 * @return The matrix set.
		 * @brief Apply the unary or operation to the matrix with a one-to-one relationship.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> & operator|=(const Matrix<T, M, N, enabled> & v);
		
		/**
		 * @fn Matrix<T, M, N, enabled> & operator^=(const Matrix<T, M, N, enabled> & v)
		 * @param[in] v The right hand side to apply to.
		 * @return The matrix set.
		 * @brief Apply the unary xor operation to the matrix with a one-to-one relationship.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> & operator^=(const Matrix<T, M, N, enabled> & v);
		
		/**
		 * @fn Matrix<T, M, N, enabled> & operator<<=(const Matrix<T, M, N, enabled> & v)
		 * @param[in] v The right hand side to apply to.
		 * @return The matrix set.
		 * @brief Apply the binary shift left operation to the matrix with a one-to-one relationship.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> & operator<<=(const Matrix<T, M, N, enabled> & v);
		
		/**
		 * @fn Matrix<T, M, N, enabled> & operator>>=(const Matrix<T, M, N, enabled> & v)
		 * @param[in] v The right hand side to apply to.
		 * @return The matrix set.
		 * @brief Apply the binary shift right operation to the matrix with a one-to-one relationship.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> & operator>>=(const Matrix<T, M, N, enabled> & v);

		/**
		 * @fn Matrix<T, M, N, enabled> & operator+=(const T & val)
		 * @param[in] val The right hand side to apply to.
		 * @return The matrix set.
		 * @brief Apply the sum operation to the matrix with a one-to-all relationship.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> & operator+=(const T & val);

		/**
		 * @fn Matrix<T, M, N, enabled> & operator-=(const T & val)
		 * @param[in] val The right hand side to apply to.
		 * @return The matrix set.
		 * @brief Apply the subtraction operation to the matrix with a one-to-all relationship.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> & operator-=(const T & val);

		/**
		 * @fn Matrix<T, M, N, enabled> & operator*=(const T & val)
		 * @param[in] val The right hand side to apply to.
		 * @return The matrix set.
		 * @brief Apply the multiplication operation to the matrix with a one-to-all relationship.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> & operator*=(const T & val);

		/**
		 * @fn Matrix<T, M, N, enabled> & operator/=(const T & val)
		 * @param[in] val The right hand side to apply to.
		 * @return The matrix set.
		 * @brief Apply the division operation to the matrix with a one-to-all relationship.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> & operator/=(const T & val);

		/**
		 * @fn Matrix<T, M, N, enabled> & operator%=(const T & val)
		 * @param[in] val The right hand side to apply to.
		 * @return The matrix set.
		 * @brief Apply the modulo operation to the matrix with a one-to-all relationship.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> & operator%=(const T & val);

		/**
		 * @fn Matrix<T, M, N, enabled> & operator&=(const T & val)
		 * @param[in] val The right hand side to apply to.
		 * @return The matrix set.
		 * @brief Apply the unary and operation to the matrix with a one-to-all relationship.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> & operator&=(const T & val);

		/**
		 * @fn Matrix<T, M, N, enabled> & operator|=(const T & val)
		 * @param[in] val The right hand side to apply to.
		 * @return The matrix set.
		 * @brief Apply the unary or operation to the matrix with a one-to-all relationship.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> & operator|=(const T & val);

		/**
		 * @fn Matrix<T, M, N, enabled> & operator^=(const T & val)
		 * @param[in] val The right hand side to apply to.
		 * @return The matrix set.
		 * @brief Apply the unary xor operation to the matrix with a one-to-all relationship.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> & operator^=(const T & val);

		/**
		 * @fn Matrix<T, M, N, enabled> & operator<<=(const T & val)
		 * @param[in] val The right hand side to apply to.
		 * @return The matrix set.
		 * @brief Apply the binary shift left operation to the matrix with a one-to-all relationship.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> & operator<<=(const T & val);

		/**
		 * @fn Matrix<T, M, N, enabled> & operator>>=(const T & val)
		 * @param[in] val The right hand side to apply to.
		 * @return The matrix set.
		 * @brief Apply the binary shift right operation to the matrix with a one-to-all relationship.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> & operator>>=(const T & val);

		/**
		 * @fn Vector<T, M> operator*=(const Vector<T, M> & v) const
		 * @param[in] v The vector to multiply to.
		 * @return The result of the matrix-vector product.
		 * @brief Performs a matrix-vector product.
		 * @throw
		 */
		inline Vector<T, M> operator*=(const Vector<T, M> & v) const;

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

//		inline Matrix<T, M, N, enabled> shift(int count) const;
//		inline Matrix<T, M, N, enabled> cshift(int count) const;

		/**
		 * @fn Matrix<T, M, N, enabled> apply(T func(T)) const
		 * @param[in] func The function to apply.
		 * @return A matrix build from the current one transformed.
		 * @brief Apply a function to all elements of the matrix.
		 * @throw
		 * @remark Should we use an std::function here ?
		 */
		inline Matrix<T, M, N, enabled> apply(T func(T)) const;

		/**
		 * @fn Matrix<T, M, N, enabled> apply(T func(const T &)) const
		 * @param[in] func The function to apply.
		 * @return A matrix build from the current one transformed.
		 * @brief Apply a function to all elements of the matrix.
		 * @throw
		 * @remark Should we use an std::function here ?
		 */
		inline Matrix<T, M, N, enabled> apply(T func(const T &)) const;

		/**
		 * @fn Matrix<T, M, N, enabled> operator+(const Matrix<T, M, N, enabled> & rhs) const
		 * @param[in] rhs The matrix to sum to.
		 * @return The sum of the two matrices.
		 * @brief Sum the current matrix with another one.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> operator+(const Matrix<T, M, N, enabled> & rhs) const;

		/**
		 * @fn Matrix<T, M, N, enabled> operator-(const Matrix<T, M, N, enabled> & rhs) const
		 * @param[in] rhs The matrix to subtract from.
		 * @return The subtraction of the two matrices.
		 * @brief Subtract the current matrix by another one.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> operator-(const Matrix<T, M, N, enabled> & rhs) const;

		/**
		 * @fn Matrix<T, M, N, enabled> operator*(const Matrix<T, M, N, enabled> & rhs) const
		 * @param[in] rhs The matrix to multiply to.
		 * @return The multiplication of the two matrices.
		 * @brief Perform a matrix-matrix multiplication.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> operator*(const Matrix<T, M, N, enabled> & rhs) const;

		/**
		 * @fn Matrix<T, M, N, enabled> operator/(const Matrix<T, M, N, enabled> & rhs) const
		 * @param[in] rhs The matrix to divide from.
		 * @return The division of the two matrices.
		 * @brief Divide the current matrix by another one.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> operator/(const Matrix<T, M, N, enabled> & rhs) const;

		/**
		 * @fn Matrix<T, M, N, enabled> operator%(const Matrix<T, M, N, enabled> & rhs) const
		 * @param[in] rhs The right hand side to apply to.
		 * @return The application of modulo operation on the current matrix.
		 * @brief Apply the modulo operation to the matrix with a one-to-one relationship.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> operator%(const Matrix<T, M, N, enabled> & rhs) const;

		/**
		 * @fn Matrix<T, M, N, enabled> operator&(const Matrix<T, M, N, enabled> & rhs) const
		 * @param[in] rhs The right hand side to apply to.
		 * @return The application of unary and operation on the current matrix.
		 * @brief Apply the unary and operation to the matrix with a one-to-one relationship.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> operator&(const Matrix<T, M, N, enabled> & rhs) const;

		/**
		 * @fn Matrix<T, M, N, enabled> operator|(const Matrix<T, M, N, enabled> & rhs) const
		 * @param[in] rhs The right hand side to apply to.
		 * @return The application of unary or operation on the current matrix.
		 * @brief Apply the unary or operation to the matrix with a one-to-one relationship.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> operator|(const Matrix<T, M, N, enabled> & rhs) const;

		/**
		 * @fn Matrix<T, M, N, enabled> operator^(const Matrix<T, M, N, enabled> & rhs) const
		 * @param[in] rhs The right hand side to apply to.
		 * @return The application of unary xor operation on the current matrix.
		 * @brief Apply the unary xor operation to the matrix with a one-to-one relationship.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> operator^(const Matrix<T, M, N, enabled> & rhs) const;

		/**
		 * @fn Matrix<T, M, N, enabled> operator<<(const Matrix<T, M, N, enabled> & rhs) const
		 * @param[in] rhs The right hand side to apply to.
		 * @return The application of binary shift left operation on the current matrix.
		 * @brief Apply the binary shift left operation to the matrix with a one-to-one relationship.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> operator<<(const Matrix<T, M, N, enabled> & rhs) const;

		/**
		 * @fn Matrix<T, M, N, enabled> operator>>(const Matrix<T, M, N, enabled> & rhs) const
		 * @param[in] rhs The right hand side to apply to.
		 * @return The application of binary shift right operation on the current matrix.
		 * @brief Apply the binary shift right operation to the matrix with a one-to-one relationship.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> operator>>(const Matrix<T, M, N, enabled> & rhs) const;

		/**
		 * @fn Matrix<T, M, N, enabled> operator&&(const Matrix<T, M, N, enabled> & rhs) const
		 * @param[in] rhs The right hand side to apply to.
		 * @return The application of binary and operation on the current matrix.
		 * @brief Apply the binary and operation to the matrix with a one-to-one relationship.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> operator&&(const Matrix<T, M, N, enabled> & rhs) const;

		/**
		 * @fn Matrix<T, M, N, enabled> operator||(const Matrix<T, M, N, enabled> & rhs) const
		 * @param[in] rhs The right hand side to apply to.
		 * @return The application of binary or operation on the current matrix.
		 * @brief Apply the binary or operation to the matrix with a one-to-one relationship.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> operator||(const Matrix<T, M, N, enabled> & rhs) const;

		/**
		 * @fn Matrix<T, M, N, enabled> operator+(const T & rhs) const
		 * @param[in] rhs The right hand side to apply to.
		 * @return The application of addition operation on the current matrix.
		 * @brief Apply the addition operation to the matrix with a one-to-all relationship.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> operator+(const T & rhs) const;

		/**
		 * @fn Matrix<T, M, N, enabled> operator-(const T & rhs) const
		 * @param[in] rhs The right hand side to apply to.
		 * @return The application of subtraction operation on the current matrix.
		 * @brief Apply the subtraction operation to the matrix with a one-to-all relationship.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> operator-(const T & rhs) const;
		
		/**
		 * @fn Vector<T, N> operator*(const Vector<T, N> & rhs) const
		 * @param[in] rhs The right hand side to apply to.
		 * @return The application of multiplication operation on the current matrix.
		 * @brief Apply a matrix - vector multiplication.
		 * @throw
		 */
		inline Vector<T, N> operator*(const Vector<T, N> & rhs) const;

		/**
		 * @fn Matrix<T, M, N, enabled> operator*(const T & rhs) const
		 * @param[in] rhs The right hand side to apply to.
		 * @return The application of multiplication operation on the current matrix.
		 * @brief Apply the multiplication operation to the matrix with a one-to-all relationship.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> operator*(const T & rhs) const;

		/**
		 * @fn Matrix<T, M, N, enabled> operator/(const T & rhs) const
		 * @param[in] rhs The right hand side to apply to.
		 * @return The application of division operation on the current matrix.
		 * @brief Apply the division operation to the matrix with a one-to-all relationship.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> operator/(const T & rhs) const;

		/**
		 * @fn Matrix<T, M, N, enabled> operator%(const T & rhs) const
		 * @param[in] rhs The right hand side to apply to.
		 * @return The application of modulo operation on the current matrix.
		 * @brief Apply the modulo operation to the matrix with a one-to-all relationship.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> operator%(const T & rhs) const;

		/**
		 * @fn Matrix<T, M, N, enabled> operator&(const T & rhs) const
		 * @param[in] rhs The right hand side to apply to.
		 * @return The application of unary and operation on the current matrix.
		 * @brief Apply the unary and operation to the matrix with a one-to-all relationship.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> operator&(const T & rhs) const;

		/**
		 * @fn Matrix<T, M, N, enabled> operator|(const T & rhs) const
		 * @param[in] rhs The right hand side to apply to.
		 * @return The application of unary or operation on the current matrix.
		 * @brief Apply the unary or operation to the matrix with a one-to-all relationship.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> operator|(const T & rhs) const;

		/**
		 * @fn Matrix<T, M, N, enabled> operator^(const T & rhs) const
		 * @param[in] rhs The right hand side to apply to.
		 * @return The application of unary xor operation on the current matrix.
		 * @brief Apply the unary xor operation to the matrix with a one-to-all relationship.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> operator^(const T & rhs) const;

		/**
		 * @fn Matrix<T, M, N, enabled> operator<<(const T & rhs) const
		 * @param[in] rhs The right hand side to apply to.
		 * @return The application of binary shift left operation on the current matrix.
		 * @brief Apply the binary shift left operation to the matrix with a one-to-all relationship.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> operator<<(const T & rhs) const;

		/**
		 * @fn Matrix<T, M, N, enabled> operator>>(const T & rhs) const
		 * @param[in] rhs The right hand side to apply to.
		 * @return The application of binary shift right operation on the current matrix.
		 * @brief Apply the binary shift right operation to the matrix with a one-to-all relationship.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> operator>>(const T & rhs) const;

		/**
		 * @fn Matrix<T, M, N, enabled> operator&&(const T & rhs) const
		 * @param[in] rhs The right hand side to apply to.
		 * @return The application of binary and operation on the current matrix.
		 * @brief Apply the binary and operation to the matrix with a one-to-all relationship.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> operator&&(const T & rhs) const;

		/**
		 * @fn Matrix<T, M, N, enabled> operator||(const T & rhs) const
		 * @param[in] rhs The right hand side to apply to.
		 * @return The application of binary or operation on the current matrix.
		 * @brief Apply the binary or operation to the matrix with a one-to-all relationship.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> operator||(const T & rhs) const;

		/**
		 * @fn bool operator==(const Matrix<T, M, N, enabled> & rhs) const
		 * @param[in] rhs The matrix to compare to.
		 * @return True, if the matrices are equals, false else.
		 * @brief Compare the two matrices to check if they are equals (member to member) or not.
		 * @throw
		 */
		bool operator==(const Matrix<T, M, N, enabled> & rhs) const;

//		Matrix<bool, M, N> operator==(const Matrix<T, M, N, enabled> & rhs);

		/**
		 * @fn Matrix<bool, M, N> operator!=(const Matrix<T, M, N, enabled> & rhs)
		 * @param[in] rhs The matrix to compare to.
		 * @return A matrix of booleans with the following value: true, if the members are not equals, false else.
		 * @brief Compare the two matrices to check if they are different (member to member) or not.
		 * @throw
		 */
		Matrix<bool, M, N> operator!=(const Matrix<T, M, N, enabled> & rhs);
		/**
		 * @fn Matrix<bool, M, N> operator<(const Matrix<T, M, N, enabled> & rhs)
		 * @param[in] rhs The matrix to compare to.
		 * @return A matrix of booleans with the following value: true, if the members are smaller, false else.
		 * @brief Compare the two matrices to check if the current one is smaller (member to member) or not.
		 * @throw
		 */
		Matrix<bool, M, N> operator<(const Matrix<T, M, N, enabled> & rhs);
		
		/**
		 * @fn Matrix<bool, M, N> operator<=(const Matrix<T, M, N, enabled> & rhs)
		 * @param[in] rhs The matrix to compare to.
		 * @return A matrix of booleans with the following value: true, if the members are smaller or equal, false else.
		 * @brief Compare the two matrices to check if the current one is smaller (member to member) or not.
		 * @throw
		 */
		Matrix<bool, M, N> operator<=(const Matrix<T, M, N, enabled> & rhs);
		
		/**
		 * @fn Matrix<bool, M, N> operator>(const Matrix<T, M, N, enabled> & rhs)
		 * @param[in] rhs The matrix to compare to.
		 * @return A matrix of booleans with the following value: true, if the members are greater, false else.
		 * @brief Compare the two matrices to check if the current one is greater (member to member) or not.
		 * @throw
		 */
		Matrix<bool, M, N> operator>(const Matrix<T, M, N, enabled> & rhs);
		
		/**
		 * @fn Matrix<bool, M, N> operator>=(const Matrix<T, M, N, enabled> & rhs)
		 * @param[in] rhs The matrix to compare to.
		 * @return A matrix of booleans with the following value: true, if the members are greater or equal, false else.
		 * @brief Compare the two matrices to check if the current one is greater or equal (member to member) or not.
		 * @throw
		 */
		Matrix<bool, M, N> operator>=(const Matrix<T, M, N, enabled> & rhs);
		
		/**
		 * @fn Matrix<bool, M, N> operator==(const T & rhs)
		 * @param[in] rhs The element to compare to.
		 * @return A matrix of booleans with the following value: true, if the members are equal, false else.
		 * @brief Compare the right hand side to each element of the matrix to check if they are equal or not.
		 * @throw
		 */
		Matrix<bool, M, N> operator==(const T & rhs);
		
		/**
		 * @fn Matrix<bool, M, N> operator!=(const T & rhs)
		 * @param[in] rhs The element to compare to.
		 * @return A matrix of booleans with the following value: true, if the members are different, false else.
		 * @brief Compare the right hand side to each element of the matrix to check if they are different or not.
		 * @throw
		 */
		Matrix<bool, M, N> operator!=(const T & rhs);
		
		/**
		 * @fn Matrix<bool, M, N> operator<(const T & rhs)
		 * @param[in] rhs The element to compare to.
		 * @return A matrix of booleans with the following value: true, if the members are smaller, false else.
		 * @brief Compare the right hand side to each element of the matrix to check if they are smaller or not.
		 * @throw
		 */
		Matrix<bool, M, N> operator<(const T & rhs);
		
		/**
		 * @fn Matrix<bool, M, N> operator<=(const T & rhs)
		 * @param[in] rhs The element to compare to.
		 * @return A matrix of booleans with the following value: true, if the members are smaller or equal, false else.
		 * @brief Compare the right hand side to each element of the matrix to check if they are smaller or equal or not.
		 * @throw
		 */
		Matrix<bool, M, N> operator<=(const T & rhs);
		
		/**
		 * @fn Matrix<bool, M, N> operator>(const T & rhs)
		 * @param[in] rhs The element to compare to.
		 * @return A matrix of booleans with the following value: true, if the members are greater, false else.
		 * @brief Compare the right hand side to each element of the matrix to check if they are greater or not.
		 * @throw
		 */
		Matrix<bool, M, N> operator>(const T & rhs);
		
		/**
		 * @fn Matrix<bool, M, N> operator>=(const T & rhs)
		 * @param[in] rhs The element to compare to.
		 * @return A matrix of booleans with the following value: true, if the members are greater or equal, false else.
		 * @brief Compare the right hand side to each element of the matrix to check if they are greater or equal, or not.
		 * @throw
		 */
		Matrix<bool, M, N> operator>=(const T & rhs);
		
		/**
		 * @fn Matrix<T, M, N, enabled> abs() const
		 * @return A matrix of the absolute value of the members.
		 * @brief Get the matrix with the absolute value of each member.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> abs() const;
		
		/**
		 * @fn Matrix<T, M, N, enabled> exp() const
		 * @return A matrix with the exponential applied on each member.
		 * @brief Apply the exponential to each member of the matrix.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> exp() const;
		
		/**
		 * @fn Matrix<T, M, N, enabled> log() const
		 * @return A matrix with the logarithm applied on each member.
		 * @brief Apply the logarithm to each member of the matrix.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> log() const;
		
		/**
		 * @fn Matrix<T, M, N, enabled> log10() const
		 * @return A matrix with the base 10 logarithm applied on each member.
		 * @brief Apply the base 10 logarithm to each member of the matrix.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> log10() const;
		
		/**
		 * @fn Matrix<T, M, N, enabled> pow(const Matrix<T, M, N, enabled> & exp) const
		 * @param[in] exp The power to apply.
		 * @return A matrix with the power applied on each member.
		 * @brief Apply the power to each member of the matrix.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> pow(const Matrix<T, M, N, enabled> & exp) const;
		
		/**
		 * @fn Matrix<T, M, N, enabled> pow(const T & exp) const
		 * @param[in] exp The power to apply.
		 * @return A matrix with the power applied on each member.
		 * @brief Apply the power to each member of the matrix.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> pow(const T & exp) const;
		
		/**
		 * @fn Matrix<T, M, N, enabled> sqrt() const
		 * @return A matrix with the square root applied on each member.
		 * @brief Apply the square root to each member of the matrix.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> sqrt() const;
		
		/**
		 * @fn Matrix<T, M, N, enabled> sin() const
		 * @return A matrix with the sine applied on each member.
		 * @brief Apply the sine to each member of the matrix.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> sin() const;
		
		/**
		 * @fn Matrix<T, M, N, enabled> cos() const
		 * @return A matrix with the cosine applied on each member.
		 * @brief Apply the cosine to each member of the matrix.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> cos() const;
		
		/**
		 * @fn Matrix<T, M, N, enabled> tan() const
		 * @return A matrix with the tangent applied on each member.
		 * @brief Apply the tangent to each member of the matrix.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> tan() const;
		
		/**
		 * @fn Matrix<T, M, N, enabled> asin() const
		 * @return A matrix with the argument sine applied on each member.
		 * @brief Apply the argument sine to each member of the matrix.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> asin() const;
		
		/**
		 * @fn Matrix<T, M, N, enabled> acos() const
		 * @return A matrix with the argument cosine applied on each member.
		 * @brief Apply the argument cosine to each member of the matrix.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> acos() const;
		
		/**
		 * @fn Matrix<T, M, N, enabled> atan() const
		 * @return A matrix with the argument tangent applied on each member.
		 * @brief Apply the argument tangent to each member of the matrix.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> atan() const;
		
		/**
		 * @fn Matrix<T, M, N, enabled> atan2(const Matrix<T, M, N, enabled> & x) const
		 * @param[in] x The x value to use.
		 * @return A matrix with the argument tangent of m/x applied on each member.
		 * @brief Apply the argument tangent of m/x to each member of the matrix.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> atan2(const Matrix<T, M, N, enabled> & x) const;
		
		/**
		 * @fn Matrix<T, M, N, enabled> atan2(const T & x) const
		 * @param[in] x The x value to use.
		 * @return A matrix with the argument tangent of m/x applied on each member.
		 * @brief Apply the argument tangent of m/X to each member of the matrix.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> atan2(const T & x) const;
		
		/**
		 * @fn Matrix<T, M, N, enabled> sinh() const
		 * @return A matrix with the hyperbolic sine applied on each member.
		 * @brief Apply the hyperbolic sine to each member of the matrix.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> sinh() const;
		
		/**
		 * @fn Matrix<T, M, N, enabled> cosh() const
		 * @return A matrix with the hyperbolic cosine applied on each member.
		 * @brief Apply the hyperbolic cosine to each member of the matrix.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> cosh() const;
		
		/**
		 * @fn Matrix<T, M, N, enabled> tanh() const
		 * @return A matrix with the hyperbolic tangent applied on each member.
		 * @brief Apply the hyperbolic tangent to each member of the matrix.
		 * @throw
		 */
		inline Matrix<T, M, N, enabled> tanh() const;

		/**
		 * @fn T trace() const
		 * @return The trace of the matrix.
		 * @brief Get the trace of the matrix.
		 * @throw
		 */
		inline T trace() const;

		/**
		 * @fn double determinant() const
		 * @return The determinant of the matrix.
		 * @brief Get the determinant of the matrix.
		 * @throw
		 */
		template <typename = std::enable_if_t<M == N>>
		inline double determinant() const;
		
		/**
		 * @fn Matrix<T, M, N, enabled> transpose() const
		 * @return The transpose matrix.
		 * @brief Get the transpose matrix of the current matrix.
		 * @throw
		 */
		template <typename = std::enable_if_t<M == N>>
		inline Matrix<T, M, N, enabled> transpose() const;
		
		/**
		 * @fn Matrix<double, M, N> inverse(bool & invertible) const
		 * @param[out] invertible Flag set to true if the matrix is invertible, false else.
		 * @return The inverse matrix, or an empty matrix.
		 * @brief Get the inverse matrix.
		 * @throw
		 */
		template <typename = std::enable_if_t<M == N>>
		inline Matrix<double, M, N> inverse(bool & invertible) const;

		/**
		 * @fn void fill(const T & value)
		 * @param[in] value The value to put in.
		 * @brief Fill the matrix with this value.
		 * @throw
		 */
		inline void fill(const T & value);

		/**
		 * @remark asinh / acosh / atanh are missing.
		 */
	};

	/**
	* @class determinant
	* @tparam T The type of member in the matrix handled.
	* @tparam M The width of the matrix handled.
	* @tparam N The height of the matrix handled.
	* @brief An helper to computer the determinant.
	*/
	template <class T, unsigned int Size>
	struct determinant
	{
		inline double operator()(const Matrix<T, Size, Size> & matrix) const;
	};

	/**
	 * @class transpose
	 * @tparam T The type of member in the matrix handled.
	 * @tparam Size The size of the square matrix handled.
	 * @brief An helper to compute the transposed matrix.
	 */
	template <class T, unsigned int Size>
	struct transpose
	{
		inline Matrix<T, Size, Size> operator()(const Matrix<T, Size, Size> & matrix) const;
	};

	/**
	* @class transpose
	* @tparam T The type of member in the matrix handled.
	* @tparam Size The size of the square matrix handled.
	* @brief An helper to compute the inverse matrix.
	*/
	template <class T, unsigned int Size>
	struct inverse
	{
		inline Matrix<double, Size, Size> operator()(const Matrix<T, Size, Size> & matrix, bool & invertible) const;
	};
}

#include "utility/mathematics/matrix.inl"

#endif // MATRIX_HPP