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