/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .   
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8   
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo 
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888   
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888   
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 . 
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888" 

															ooooooooooooo                        .            
															8'   888   `8                      .o8            
																 888       .ooooo.   .oooo.o .o888oo  .oooo.o 
																 888      d88' `88b d88(  "8   888   d88(  "8 
																 888      888ooo888 `"Y88b.    888   `"Y88b.  
																 888      888    .o o.  )88b   888 . o.  )88b 
																o888o     `Y8bod8P' 8""888P'   "888" 8""888P' 
                                                                       
                                          
                                     
				This file is part of EdenCraft Engine - Tests.
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

#include "Catch2/single_include/catch.hpp"

#include "utility/mathematics/matrix3u.hpp"
#include "utility/mathematics/vector3u.hpp"
#include "utility/debug/exception.hpp"

SCENARIO("Matrix3u", "[Utility][Mathematics]")
{
	REQUIRE(ece::IntMatrix3u() == ece::IntMatrix3u{ 0, 0, 0, 0, 0, 0, 0, 0, 0 });
//	REQUIRE(ece::IntMatrix3u() == ece::IntMatrix3u{ ece::IntVector3u(), ece::IntVector3u(), ece::IntVector3u() });
//	REQUIRE(ece::IntMatrix3u() == ece::IntMatrix3u(ece::FloatVector3u(), ece::FloatVector3u(), ece::FloatVector3u()));
	REQUIRE(ece::IntMatrix3u::Identity() == ece::IntMatrix3u{ 1, 0, 0, 0, 1, 0, 0, 0, 1 });

	GIVEN("A simple matrix")
	{
		ece::IntMatrix3u matrix{ 2, 4, 6,
								8, 10, 12,
								14, 16, 18 };

		WHEN("Setting it to the identy matrix")
		{
			REQUIRE(matrix.setIdentity() == ece::IntMatrix3u::Identity());
		}
		AND_WHEN("Multiplying all the members by 2")
		{
			REQUIRE(matrix * 0 == ece::IntMatrix3u());
			REQUIRE(matrix * 2 == ece::IntMatrix3u{ 4, 8, 12, 16, 20, 24, 28, 32, 36 });
			matrix *= 2;
			REQUIRE(matrix == ece::IntMatrix3u{ 4, 8, 12, 16, 20, 24, 28, 32, 36 });
		}
		AND_WHEN("Dividing all the members by 2")
		{
			REQUIRE_THROWS_AS(matrix / 0, ece::DivideByZeroException);
			REQUIRE_THROWS_AS(matrix /= 0, ece::DivideByZeroException);
			REQUIRE(matrix / 2 == ece::IntMatrix3u{ 1, 2, 3, 4, 5, 6, 7, 8, 9 });
			matrix /= 2;
			REQUIRE(matrix == ece::IntMatrix3u{ 1, 2, 3, 4, 5, 6, 7, 8, 9 });
		}
		AND_WHEN("Multiplying a 3D vector")
		{
			REQUIRE(matrix * ece::IntVector3u() == ece::IntVector3u());
			REQUIRE(matrix * ece::IntVector3u{ 1, 1, 1 } == ece::IntVector3u{ 12, 30, 48 });
		}
		AND_WHEN("Multiplying a 3D matrix")
		{
			REQUIRE(matrix * ece::IntMatrix3u() == ece::IntMatrix3u());
			REQUIRE(matrix * ece::IntMatrix3u::Identity() == matrix);
			REQUIRE(matrix * matrix == ece::IntMatrix3u{ 120, 144, 168, 264, 324, 384, 408, 504, 600 });
			matrix *= ece::IntMatrix3u{ 2, 4, 6, 8, 10, 12, 14, 16, 18 };
			REQUIRE(matrix == ece::IntMatrix3u{ 120, 144, 168, 264, 324, 384, 408, 504, 600 });
		}
		AND_WHEN("Adding a 3D matrix")
		{
			REQUIRE(matrix + ece::IntMatrix3u() == matrix);
			REQUIRE(matrix + ece::IntMatrix3u::Identity() == ece::IntMatrix3u{ 3, 4, 6, 8, 11, 12, 14, 16, 19 });
			REQUIRE(matrix + matrix == matrix * 2);
			matrix += ece::IntMatrix3u::Identity();
			REQUIRE(matrix == ece::IntMatrix3u{ 3, 4, 6, 8, 11, 12, 14, 16, 19 });
		}
		AND_WHEN("Substracting a 3D matrix")
		{
			REQUIRE(matrix - ece::IntMatrix3u() == matrix);
			REQUIRE(matrix - ece::IntMatrix3u::Identity() == ece::IntMatrix3u{ 1, 4, 6, 8, 9, 12, 14, 16, 17 });
			REQUIRE(matrix - matrix == ece::IntMatrix3u());
			matrix -= ece::IntMatrix3u::Identity();
			REQUIRE(matrix == ece::IntMatrix3u{ 1, 4, 6, 8, 9, 12, 14, 16, 17 });
		}
		AND_WHEN("Getting the negative of the matrix")
		{
			REQUIRE(-matrix == ece::IntMatrix3u{ -2, -4, -6, -8, -10, -12, -14, -16, -18 });
		}
		AND_WHEN("Getting a column")
		{
			REQUIRE(matrix.column(0) == ece::IntVector3u{ 2, 8, 14 });
			REQUIRE(matrix.column(1) == ece::IntVector3u{ 4, 10, 16 });
			REQUIRE(matrix.column(2) == ece::IntVector3u{ 6, 12, 18 });
			REQUIRE_THROWS_AS(matrix.column(3), ece::OutOfRangeException);
		}
		AND_WHEN("Getting a row")
		{
			REQUIRE(matrix.row(0) == ece::IntVector3u{ 2, 4, 6 });
			REQUIRE(matrix.row(1) == ece::IntVector3u{ 8, 10, 12 });
			REQUIRE(matrix.row(2) == ece::IntVector3u{ 14, 16, 18 });
			REQUIRE_THROWS_AS(matrix.row(3), ece::OutOfRangeException);

			REQUIRE(matrix[0] == ece::IntVector3u{ 2, 4, 6 });
			REQUIRE(matrix[1] == ece::IntVector3u{ 8, 10, 12 });
			REQUIRE(matrix[2] == ece::IntVector3u{ 14, 16, 18 });
//			REQUIRE_THROWS_AS(matrix[-1], ece::OutOfRangeException);
			REQUIRE_THROWS_AS(matrix[3], ece::OutOfRangeException);
		}
		AND_WHEN("Getting an element")
		{
			REQUIRE(matrix[0][0] == 2);
			REQUIRE(matrix[0][1] == 4);
			REQUIRE(matrix[0][2] == 6);
			REQUIRE(matrix[1][0] == 8);
			REQUIRE(matrix[1][1] == 10);
			REQUIRE(matrix[1][2] == 12);
			REQUIRE(matrix[2][0] == 14);
			REQUIRE(matrix[2][1] == 16);
			REQUIRE(matrix[2][2] == 18);
		}
		AND_WHEN("Getting the determinant")
		{
			REQUIRE(matrix.determinant() == 0);
		}
		AND_WHEN("Getting the transpose matrix")
		{
			REQUIRE(matrix.transpose() == ece::IntMatrix3u{ 2, 8, 14, 4, 10, 16, 6, 12, 18 });
		}
		AND_WHEN("Getting the inverse matrix")
		{
			bool invertible = true;
			auto inverse = matrix.inverse(invertible);

			THEN("The matrix is not invertible")
			{
				REQUIRE_FALSE(invertible);
			}
			AND_THEN("A default matrix is returned")
			{
				REQUIRE(inverse == ece::DoubleMatrix3u());
			}
		}
	}

	GIVEN("An invertible matrix")
	{
		ece::IntMatrix3u matrix{ 6, 4, 2, 12, 8, 10, 14, 16, 18 };

		WHEN("Getting the determinant")
		{
			auto determinant = matrix.determinant();

			THEN("Determinant is not null")
			{
				REQUIRE(determinant != 0);
			}
		}
		AND_WHEN("Getting the inverse matrix")
		{
			bool invertible = true;
			auto inverse = matrix.inverse(invertible);

			THEN("The matrix is invertible")
			{
				REQUIRE(invertible);
			}
			AND_THEN("The inverse matrix is returned")
			{
				REQUIRE(inverse == ece::DoubleMatrix3u{ 1.0 / 15.0, 1.0 / 6.0, -0.1,
														19.0 / 60.0, -1.0 / 3.0, 0.15,
														-1.0 / 3.0, 1.0 / 6.0, 0 });
			}
		}
	}
}