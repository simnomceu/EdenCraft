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

#include <utility>
#include <type_traits>

#include "utility/template_expression/linear_expression.hpp"
#include "utility/template_expression/filter.hpp"
#include "utility/template_expression/vector.hpp"
#include "utility/template_expression/slice.hpp"

#ifdef _MSC_VER
	#undef min
	#undef max
#endif

namespace ece
{
    namespace utility
    {
        namespace template_expression
        {
        	/**
        	 * @class Matrix
        	 * @tparam E The type of elements in the matrix.
        	 * @tparam M The number of rows of the matrix.
        	 * @tparam N The number of columns of the matrix.
        	 * @extends LinearExpression<Matrix<E, M, N, enabled>>
        	 * @brief A mathematical matrix, that can be handled in row-major order and column-major order.
        	 */
        	template <typename E, unsigned int M, unsigned int N, typename enabled = typename std::enable_if_t<std::is_arithmetic<E>::value>>
        	class Matrix: public LinearExpression<Matrix<E, M, N, enabled>>
        	{
        	public:
        		/**
        		 * @fn Matrix<T, M, N, enabled> Identity()
        		 * @return An identity matrix.
        		 * @brief Build an identity matrix.
        		 * The matrix is filled with 0, except for the diagonal which is filled with 1.
        		 * @throw
        		 */
        		static inline Matrix<E, M, N, enabled> Identity();

        		/**
        		 * @fn constexpr Matrix() noexcept
        		 * @brief Default constructor.
        		 * @throw noexcept
        		 */
        		constexpr Matrix() noexcept;

        		/**
        		 * @fn constexpr Matrix(const E value) noexcept
        		 * @param[in] value The value to fill the matrix with.
        		 * @brief Build a matrix filled with a specific value.
        		 * @throw noexcept
        		 */
        		inline constexpr Matrix(const E value) noexcept;

        		/**
        		 * @fn Matrix(const E2 & rhs) noexcept
        		 * @tparam E2 The type of the linear expression to cast.
        		 * @param[in] rhs The linear expression to cast.
        		 * @brief Cast a linear expression into a matrix (if possible).
        		 * @throw noexcept
        		 */
        		template <class E2, typename enabledBis = typename std::enable_if_t<std::is_base_of_v<LinearExpression<E2>, E2> && !std::is_same_v<E2, Matrix<E, M, N, enabled>>>>
        		Matrix(const E2 & rhs) noexcept;

        		/**
        		 * @fn Matrix(std::initializer_list<E> il) noexcept
        		 * @param[in] il A list of elements to set the matrix.
        		 * @brief Build a matrix from a list of elements.
        		 * @throw noexcept
        		 */
        		Matrix(std::initializer_list<E> il) noexcept;

        		/**
        		 * @fn Matrix(const Matrix<E, M, N, enabled> & copy) noexcept
        		 * @param[in] copy The Matrix to copy from.
        		 * @brief Default copy constructor.
        		 * @throw noexcept
        		 */
        		Matrix(const Matrix<E, M, N, enabled> & copy) noexcept = default;

        		/**
        		 * @fn Matrix(Matrix<E, M, N, enabled> && move) noexcept
        		 * @param[in] move The Matrix to move.
        		 * @brief Default move constructor.
        		 * @throw noexcept
        		 */
        		Matrix(Matrix<E, M, N, enabled> && move) noexcept = default;

        		/**
        		 * @fn ~Matrix() noexcept
        		 * @brief Default destructor.
        		 * @throw noexcept
        		 */
        		~Matrix() noexcept = default;

        		/**
        		 * @fn Matrix<E, M, N, enabled> & operator=(const Matrix<E, M, N, enabled> & copy) noexcept
        		 * @param[in] copy The Matrix to copy from.
        		 * @return The Matrix copied.
        		 * @brief Default copy assignment operator.
        		 * @throw noexcept
        		 */
        		Matrix<E, M, N, enabled> & operator=(const Matrix<E, M, N, enabled> & copy) noexcept = default;

        		/**
        		 * @fn Matrix<E, M, N, enabled> & operator=(Matrix<E, M, N, enabled> && move) noexcept
        		 * @param[in] move The Matrix to move.
        		 * @return The Matrix moved.
        		 * @brief Default move assignment operator.
        		 * @throw noexcept
        		 */
        		Matrix<E, M, N, enabled> & operator=(Matrix<E, M, N, enabled> && move) noexcept = default;

        		/**
        		 * @fn Matrix<E, M, N, enabled> & operator=(const LinearExpression<Matrix<E, M, N, enabled>> & rhs) noexcept
        		 * @param[in] rhs The linear expression to set to.
        		 * @return The matrix modified.
        		 * @brief Set the matrix from another linear expression.
        		 * @throw noexcept
        		 */
        		Matrix<E, M, N, enabled> & operator=(const LinearExpression<Matrix<E, M, N, enabled>> & rhs) noexcept;

        		/**
        		 * @fn Matrix<T, M, N, enabled> & setIdentity()
        		 * @return This matrix.
        		 * @brief Set this matrix as an identity matrix.
        		 * The matrix is filled with 0, except for the diagonal which is filled with 1.
        		 * @throw
        		 */
        		inline Matrix<E, M, N, enabled> & setIdentity();

        		/**
        		 * @fn E & operator[](const unsigned int index)
        		 * @param[in] index The index of the element to access.
        		 * @return The element wished.
        		 * @brief Get the element at the index.
        		 * @throw
        		 */
        		inline Slice<Matrix<E, M, N, enabled>> operator[](const unsigned int index);

        		/**
        		* @fn E & operator[](const unsigned int index) const
        		* @param[in] index The index of the element to access.
        		* @return The element wished.
        		* @brief Get the element at the index.
        		* @throw
        		*/
        		inline Slice<Matrix<E, M, N, enabled>> operator[](const unsigned int index) const;

        		/**
        		 * Slice<Matrix<E, M, N, enabled>> row(const unsigned int index)
        		 * @param[in] index The index of the row to get.
        		 * @return A slice of the matrix which is a row.
        		 * @brief Get a row of the matrix.
        		 * @throw
        		 */
        		inline Slice<Matrix<E, M, N, enabled>> row(const unsigned int index);

        		/**
        		* Slice<Matrix<E, M, N, enabled>> row(const unsigned int index) const
        		* @param[in] index The index of the row to get.
        		* @return A slice of the matrix which is a row.
        		* @brief Get a row of the matrix.
        		* @throw
        		*/
        		inline Slice<Matrix<E, M, N, enabled>> row(const unsigned int index) const;

        		/**
        		 * Slice<Matrix<E, M, N, enabled>> column(const unsigned int index)
        		 * @param[in] index The index of the column to get.
        		 * @return A slice of the matrix which is a row.
        		 * @brief Get a column of the matrix.
        		 * @throw
        		 */
        		inline Slice<Matrix<E, M, N, enabled>> column(const unsigned int index);

        		/**
        		* Slice<Matrix<E, M, N, enabled>> column(const unsigned int index) const
        		* @param[in] index The index of the column to get.
        		* @return A slice of the matrix which is a row.
        		* @brief Get a column of the matrix.
        		* @throw
        		*/
        		inline Slice<Matrix<E, M, N, enabled>> column(const unsigned int index) const;

        		/**
        		 * @fn Filter<Matrix<E, M, N, enabled>, M * N, enabled> operator[](Matrix<bool, M, N, enabled> && filter)
        		 * @param[in] filter The filter to apply.
        		 * @return The matrix filtered.
        		 * @brief Get the matrix filtered.
        		 * @throw
        		 */
        		Filter<Matrix<E, M, N, enabled>, M * N, enabled> operator[](Matrix<bool, M, N, enabled> && filter);

        		/**
        		* @fn Filter<Matrix<E, M, N, enabled>, M * N, enabled> operator[](Matrix<bool, M, N, enabled> && filter) const
        		* @param[in] filter The filter to apply.
        		* @return The matrix filtered.
        		* @brief Get the matrix filtered.
        		* @throw
        		*/
        		Filter<Matrix<E, M, N, enabled>, M * N, enabled> operator[](Matrix<bool, M, N, enabled> && filter) const;

        		Filter<Matrix<E, M, N, enabled>, M * N, enabled> operator[](std::initializer_list<unsigned int> && il);

        		Filter<Matrix<E, M, N, enabled>, M * N, enabled> operator[](std::initializer_list<unsigned int> && il) const;

        		inline E cell(const unsigned int index) const;

				inline E & cell(const unsigned int index);

				inline constexpr E * data() noexcept;

				inline constexpr const E * data() const noexcept;

        		/**
        		 * @fn constexpr unsigned int size() const noexcept
        		 * @return The number of element in the expression result.
        		 * @brief Get he number of elements.
        		 * @throw noexcept
        		 */
        		inline constexpr unsigned int size() const noexcept;

        		inline auto begin() noexcept;
        		inline auto end() noexcept;

        		inline E min() const noexcept;

        		inline E max() const noexcept;

        		inline E sum() const noexcept;

        		inline Matrix<E, M, N, enabled> shift(const int count) const noexcept;

        		inline Matrix<E, M, N, enabled> cshift(const int count) const noexcept;

        		inline Matrix<E, M, N, enabled> apply(E func(E)) const noexcept;

        		inline Matrix<E, M, N, enabled> apply(E func(const E &)) const noexcept;

        		/**
        		 * @fn E trace() const
        		 * @return The trace of the matrix.
        		 * @brief Get the trace of the matrix.
        		 * @throw
        		 */
        		template <typename = std::enable_if_t<M == N>>
        		inline E trace() const;

        		/**
        		 * @fn double determinant() const
        		 * @return The determinant of the matrix.
        		 * @brief Get the determinant of the matrix.
        		 * @throw
        		 */
        		template <typename = std::enable_if_t<M == N>>
        		inline double determinant() const;

        		/**
        		 * @fn Matrix<E, M, N, enabled> transpose() const
        		 * @return The transpose matrix.
        		 * @brief Get the transpose matrix of the current matrix.
        		 * @throw
        		 */
        		template <typename = std::enable_if_t<M == N>>
        		inline Matrix<E, M, N, enabled> transpose() const;

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
        		 * @fn void fill(const E & value)
        		 * @param[in] value The value to put in.
        		 * @brief Fill the matrix with this value.
        		 * @throw
        		 */
        		inline void fill(const E & value);

        	protected:
        		std::array<E, M * N> _elements;
        	};

        	/**
        	 * @class Determinant
        	 * @tparam T The type of member in the matrix handled.
        	 * @tparam M The width of the matrix handled.
        	 * @tparam N The height of the matrix handled.
        	 * @brief An helper to computer the determinant.
        	 */
        	template <class T, unsigned int Size>
        	struct Determinant
        	{
        		inline double operator()(const Matrix<T, Size, Size> & matrix) const;
        	};

        	/**
        	 * @class Transpose
        	 * @tparam T The type of member in the matrix handled.
        	 * @tparam Size The size of the square matrix handled.
        	 * @brief An helper to compute the transposed matrix.
        	 */
        	template <class T, unsigned int Size>
        	struct Transpose
        	{
        		inline Matrix<T, Size, Size> operator()(const Matrix<T, Size, Size> & matrix) const;
        	};

        	/**
        	 * @class Inverse
        	 * @tparam T The type of member in the matrix handled.
        	 * @tparam Size The size of the square matrix handled.
        	 * @brief An helper to compute the inverse matrix.
        	 */
        	template <class T, unsigned int Size>
        	struct Inverse
        	{
        		inline Matrix<double, Size, Size> operator()(const Matrix<T, Size, Size> & matrix, bool & invertible) const;
        	};

            /**
             * @fn Matrix<E1, Size, Size> & operator*=(Matrix<E1, Size, Size> & lhs, const Matrix<E2, Size, Size> & rhs)
             * @tparam E1 The type of the left-hand side linear expression concerned by the operation.
             * @tparam E2 The type of the right-hand side linear expression concerned by the operation.
             * @param[in] lhs The left-hand side linear expression to apply the unary operation to.
             * @param[in] rhs The right-hand side linear expression to apply the unary operation to.
             * @return The left-hand side modified.
             * @brief Apply the multiplication of the two elements, member-to-member into the left-hand side.
             */
        	template <typename E1, typename E2, unsigned int Size>
        	Matrix<E1, Size, Size> & operator*=(Matrix<E1, Size, Size> & lhs, const Matrix<E2, Size, Size> & rhs);

        	/**
        	* @fn Matrix<E1, Size, Size> operator*(const Matrix<E1, Size, Size> & lhs, const Matrix<E2, Size, Size> & rhs)
        	* @tparam E1 The type of the left-hand side linear expression concerned by the operation.
        	* @tparam E2 The type of the right-hand side linear expression concerned by the operation.
        	* @param[in] lhs The left-hand side linear expression to apply the unary operation to.
        	* @param[in] rhs The right-hand side linear expression to apply the unary operation to.
        	* @return The linear operation on the two linear expressions.
        	* @brief Create the linear expression of the multiplication of the two factors.
        	*/
        	template <typename E1, typename E2, unsigned int Size>
        	Matrix<E1, Size, Size> operator*(const Matrix<E1, Size, Size> & lhs, const Matrix<E2, Size, Size> & rhs);

            /**
             * @fn Vector<E1, Size> operator*(const Matrix<E1, Size, Size> & lhs, const Vector<E2, Size> & rhs)
             * @tparam E1 The type of the left-hand side linear expression concerned by the operation.
             * @tparam E2 The type of the right-hand side linear expression concerned by the operation.
             * @param[in] lhs The left-hand side linear expression to apply the unary operation to.
             * @param[in] rhs The right-hand side linear expression to apply the unary operation to.
             * @return The linear operation on the two linear expressions.
             * @brief Create the linear expression of the multiplication of the two factors.
             */
        	template <typename E1, typename E2, unsigned int Size>
        	Vector<E1, Size> operator*(const Matrix<E1, Size, Size> & lhs, const Vector<E2, Size> & rhs);
        } // namespace template_expression
    } // namespace utility
} // namespace ece

#include "utility/template_expression/matrix.inl"

#endif // MATRIX_HPP
