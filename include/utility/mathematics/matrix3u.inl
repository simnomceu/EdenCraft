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

namespace ece
{
    namespace utility
    {
        namespace template_expression
        {
        	template<class T>
        	inline double Determinant<T, 3>::operator()(const Matrix<T, 3, 3> & matrix) const
        	{
        		return matrix[0][0] * matrix[1][1] * matrix[2][2]
        			+ matrix[0][1] * matrix[1][2] * matrix[2][0]
        			+ matrix[0][2] * matrix[1][0] * matrix[2][1]
        			- matrix[0][2] * matrix[1][1] * matrix[2][0]
        			- matrix[0][1] * matrix[1][0] * matrix[2][2]
        			- matrix[0][0] * matrix[1][2] * matrix[2][1];
        	}

        	template<class T>
        	inline Matrix<T, 3, 3> Transpose<T, 3>::operator()(const Matrix<T, 3, 3> & matrix) const
        	{
        		return Matrix<T, 3, 3>{ matrix[0][0], matrix[1][0], matrix[2][0],
        			matrix[0][1], matrix[1][1], matrix[2][1],
        			matrix[0][2], matrix[1][2], matrix[2][2] };
        	}

        	template<class T>
        	inline Matrix<double, 3, 3> Inverse<T, 3>::operator()(const Matrix<T, 3, 3> & matrix, bool & invertible) const
        	{
        		auto det = matrix.determinant();
        		invertible = (det != 0);
        		if (invertible) {
        			double a11 = matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1];
        			double a12 = matrix[0][2] * matrix[2][1] - matrix[0][1] * matrix[2][2];
        			double a13 = matrix[0][1] * matrix[1][2] - matrix[0][2] * matrix[1][1];
        			double a21 = matrix[1][2] * matrix[2][0] - matrix[1][0] * matrix[2][2];
        			double a22 = matrix[0][0] * matrix[2][2] - matrix[0][2] * matrix[2][0];
        			double a23 = matrix[0][2] * matrix[1][0] - matrix[0][0] * matrix[1][2];
        			double a31 = matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0];
        			double a32 = matrix[0][1] * matrix[2][0] - matrix[0][0] * matrix[2][1];
        			double a33 = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];

        			return Matrix<double, 3, 3>{ a11, a12, a13,
        				a21, a22, a23,
        				a31, a32, a33 } *(1.0f / det);
        		}
        		else {
        			return Matrix<double, 3, 3>();
        		}
        	}
        } // namespace mathematics
    } // namespace utility
} // namespace ece
