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

#include "catch2/catch.hpp"

#include "utility/mathematics.hpp"
#include "utility/debug.hpp"

SCENARIO("Matrix4u", "[Utility][Mathematics]")
{
	REQUIRE(ece::IntMatrix4u() == ece::IntMatrix4u{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 });
//	REQUIRE(ece::IntMatrix4u() == ece::IntMatrix4u(ece::IntVector4u(), ece::IntVector4u(), ece::IntVector4u(), ece::IntVector4u()));
//	REQUIRE(ece::IntMatrix4u() == ece::IntMatrix4u(ece::FloatVector4u(), ece::FloatVector4u(), ece::FloatVector4u(), ece::FloatVector4u()));
	REQUIRE(ece::IntMatrix4u::Identity() == ece::IntMatrix4u{ 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 });

	GIVEN("A simple matrix")
	{
		ece::IntMatrix4u matrix{ 2, 4, 6, 8,
								10, 12, 14, 16,
								18, 20, 22, 24,
								26, 28, 30, 32 };

		WHEN("Setting it to the identy matrix")
		{
			REQUIRE(matrix.setIdentity() == ece::IntMatrix4u::Identity());
		}
		AND_WHEN("Multiplying all the members by 2")
		{
			REQUIRE(matrix * 0 == ece::IntMatrix4u());
			REQUIRE(matrix * 2 == ece::IntMatrix4u{ 4, 8, 12, 16, 20, 24, 28, 32, 36, 40, 44, 48, 52, 56, 60, 64 });
			matrix *= 2;
			REQUIRE(matrix == ece::IntMatrix4u{ 4, 8, 12, 16, 20, 24, 28, 32, 36, 40, 44, 48, 52, 56, 60, 64 });
		}
		AND_WHEN("Dividing all the members by 2")
		{
			REQUIRE_THROWS_AS(matrix / 0, ece::DivideByZeroException);
			REQUIRE_THROWS_AS(matrix /= 0, ece::DivideByZeroException);
			REQUIRE(matrix / 2 == ece::IntMatrix4u{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 });
			matrix /= 2;
			REQUIRE(matrix == ece::IntMatrix4u{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 });
		}
		AND_WHEN("Multiplying a 4D vector")
		{
			REQUIRE(matrix * ece::IntVector4u() == ece::IntVector4u());
			REQUIRE(matrix * ece::IntVector4u{ 1, 1, 1, 1 } == ece::IntVector4u{ 20, 52, 84, 116 });
		}
		AND_WHEN("Multiplying a 4D matrix")
		{
			REQUIRE(matrix * ece::IntMatrix4u() == ece::IntMatrix4u());
			REQUIRE(matrix * ece::IntMatrix4u::Identity() == matrix);
			REQUIRE(matrix * matrix == ece::IntMatrix4u{ 360, 400, 440, 480, 808, 912, 1016, 1120, 1256, 1424, 1592, 1760, 1704, 1936, 2168, 2400 });
			matrix *= ece::IntMatrix4u{ 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32 };
			REQUIRE(matrix == ece::IntMatrix4u{ 360, 400, 440, 480, 808, 912, 1016, 1120, 1256, 1424, 1592, 1760, 1704, 1936, 2168, 2400 });
		}
		AND_WHEN("Adding a 4D matrix")
		{
			REQUIRE(matrix + ece::IntMatrix4u() == matrix);
			REQUIRE(matrix + ece::IntMatrix4u::Identity() == ece::IntMatrix4u{ 3, 4, 6, 8, 10, 13, 14, 16, 18, 20, 23, 24, 26, 28, 30, 33 });
			REQUIRE(matrix + matrix == matrix * 2);
			matrix += ece::IntMatrix4u::Identity();
			REQUIRE(matrix == ece::IntMatrix4u{ 3, 4, 6, 8, 10, 13, 14, 16, 18, 20, 23, 24, 26, 28, 30, 33 });
		}
		AND_WHEN("Substracting a 4D matrix")
		{
			REQUIRE(matrix - ece::IntMatrix4u() == matrix);
			REQUIRE(matrix - ece::IntMatrix4u::Identity() == ece::IntMatrix4u{ 1, 4, 6, 8, 10, 11, 14, 16, 18, 20, 21, 24, 26, 28, 30, 31 });
			REQUIRE(matrix - matrix == ece::IntMatrix4u());
			matrix -= ece::IntMatrix4u::Identity();
			REQUIRE(matrix == ece::IntMatrix4u{ 1, 4, 6, 8, 10, 11, 14, 16, 18, 20, 21, 24, 26, 28, 30, 31 });
		}
		AND_WHEN("Getting the negative of the matrix")
		{
//			REQUIRE(-matrix == ece::IntMatrix4u{ -2, -4, -6, -8, -10, -12, -14, -16, -18, -20, -22, -24, -26, -28, -30, -32 });
		}
		AND_WHEN("Getting a column")
		{
			REQUIRE(matrix.column(0) == ece::IntVector4u{ 2, 10, 18, 26 });
			REQUIRE(matrix.column(1) == ece::IntVector4u{ 4, 12, 20, 28 });
			REQUIRE(matrix.column(2) == ece::IntVector4u{ 6, 14, 22, 30 });
			REQUIRE(matrix.column(3) == ece::IntVector4u{ 8, 16, 24, 32 });
//			REQUIRE_THROWS_AS(matrix.column(-1), ece::OutOfRangeException);
			REQUIRE_THROWS_AS(matrix.column(4), ece::OutOfRangeException);
		}
		AND_WHEN("Getting a row")
		{
			REQUIRE(matrix.row(0) == ece::IntVector4u{ 2, 4, 6, 8 });
			REQUIRE(matrix.row(1) == ece::IntVector4u{ 10, 12, 14, 16 });
			REQUIRE(matrix.row(2) == ece::IntVector4u{ 18, 20, 22, 24 });
			REQUIRE(matrix.row(3) == ece::IntVector4u{ 26, 28, 30, 32 });
//			REQUIRE_THROWS_AS(matrix.row(-1), ece::OutOfRangeException);
			REQUIRE_THROWS_AS(matrix.row(4), ece::OutOfRangeException);

			REQUIRE(matrix[0] == ece::IntVector4u{ 2, 4, 6, 8 });
			REQUIRE(matrix[1] == ece::IntVector4u{ 10, 12, 14, 16 });
			REQUIRE(matrix[2] == ece::IntVector4u{ 18, 20, 22, 24 });
			REQUIRE(matrix[3] == ece::IntVector4u{ 26, 28, 30, 32 });
//			REQUIRE_THROWS_AS(matrix[-1], ece::OutOfRangeException);
			REQUIRE_THROWS_AS(matrix[4], ece::OutOfRangeException);
		}
		AND_WHEN("Getting an element")
		{
			REQUIRE(matrix[0][0] == 2);
			REQUIRE(matrix[0][1] == 4);
			REQUIRE(matrix[0][2] == 6);
			REQUIRE(matrix[0][3] == 8);
			REQUIRE(matrix[1][0] == 10);
			REQUIRE(matrix[1][1] == 12);
			REQUIRE(matrix[1][2] == 14);
			REQUIRE(matrix[1][3] == 16);
			REQUIRE(matrix[2][0] == 18);
			REQUIRE(matrix[2][1] == 20);
			REQUIRE(matrix[2][2] == 22);
			REQUIRE(matrix[2][3] == 24);
			REQUIRE(matrix[3][0] == 26);
			REQUIRE(matrix[3][1] == 28);
			REQUIRE(matrix[3][2] == 30);
			REQUIRE(matrix[3][3] == 32);
		}
		AND_WHEN("Getting the determinant")
		{
			REQUIRE(matrix.determinant() == 0);
		}
		AND_WHEN("Getting the transpose matrix")
		{
			REQUIRE(matrix.transpose() == ece::IntMatrix4u{ 2, 10, 18, 26, 4, 12, 20, 28, 6, 14, 22, 30, 8, 16, 24, 32 });
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
				REQUIRE(inverse == ece::DoubleMatrix4u());
			}
		}
	}

	GIVEN("An invertible matrix")
	{
		ece::IntMatrix4u matrix{ 1, 1, 1, 0, 0, 3, 1, 2, 2, 3, 1, 0, 1, 0, 2, 1 };

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
				REQUIRE(inverse == ece::DoubleMatrix4u{ -3.0, -0.5, 1.5, 1.0,
														1.0, 0.25, -0.25, -0.5,
														3.0, 0.25, -1.25, -0.5,
														-3.0, 0.0, 1.0, 1.0 });
			}
		}
	}
}