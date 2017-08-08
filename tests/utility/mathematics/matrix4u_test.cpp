#include "catch\catch.hpp"

#include "mathematics\matrix4u.hpp"
#include "debug\exception.hpp"

SCENARIO("Matrix4u", "[Utility][Mathematics]")
{
	REQUIRE(ece::IntMatrix4u() == ece::IntMatrix4u(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0));
	REQUIRE(ece::IntMatrix4u() == ece::IntMatrix4u(ece::IntVertex4u(), ece::IntVertex4u(), ece::IntVertex4u(), ece::IntVertex4u()));
	REQUIRE(ece::IntMatrix4u() == ece::IntMatrix4u(ece::FloatVertex4u(), ece::FloatVertex4u(), ece::FloatVertex4u(), ece::FloatVertex4u()));
	REQUIRE(ece::IntMatrix4u::Identity() == ece::IntMatrix4u(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1));

	GIVEN("A simple matrix")
	{
		ece::IntMatrix4u matrix(2, 4, 6, 8,
								10, 12, 14, 16,
								18, 20, 22, 24,
								26, 28, 30, 32);

		WHEN("Setting it to the identy matrix")
		{
			REQUIRE(matrix.setIdentity() == ece::IntMatrix4u::Identity());
		}
		AND_WHEN("Multiplying all the members by 2")
		{
			REQUIRE(matrix * 0 == ece::IntMatrix4u());
			REQUIRE(matrix * 2 == ece::IntMatrix4u(4, 8, 12, 16, 20, 24, 28, 32, 36, 40, 44, 48, 52, 56, 60, 64));
			matrix *= 2;
			REQUIRE(matrix == ece::IntMatrix4u(4, 8, 12, 16, 20, 24, 28, 32, 36, 40, 44, 48, 52, 56, 60, 64));
		}
		AND_WHEN("Dividing all the members by 2")
		{
			REQUIRE_THROWS_AS(matrix / 0, ece::DivideByZeroException);
			REQUIRE_THROWS_AS(matrix /= 0, ece::DivideByZeroException);
			REQUIRE(matrix / 2 == ece::IntMatrix4u(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16));
			matrix /= 2;
			REQUIRE(matrix == ece::IntMatrix4u(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16));
		}
		AND_WHEN("Multiplying a 4D vector")
		{
			REQUIRE(matrix * ece::IntVertex4u() == ece::IntVertex4u());
			REQUIRE(matrix * ece::IntVertex4u(1, 1, 1, 1) == ece::IntVertex4u(20, 52, 84, 116));
		}
		AND_WHEN("Multiplying a 4D matrix")
		{
			REQUIRE(matrix * ece::IntMatrix4u() == ece::IntMatrix4u());
			REQUIRE(matrix * ece::IntMatrix4u::Identity() == matrix);
			REQUIRE(matrix * matrix == ece::IntMatrix4u(360, 400, 440, 480, 808, 912, 1016, 1120, 1256, 1424, 1592, 1760, 1704, 1936, 2168, 2400));
			matrix *= ece::IntMatrix4u(2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32);
			REQUIRE(matrix == ece::IntMatrix4u(360, 400, 440, 480, 808, 912, 1016, 1120, 1256, 1424, 1592, 1760, 1704, 1936, 2168, 2400));
		}
		AND_WHEN("Adding a 4D matrix")
		{
			REQUIRE(matrix + ece::IntMatrix4u() == matrix);
			REQUIRE(matrix + ece::IntMatrix4u::Identity() == ece::IntMatrix4u(3, 4, 6, 8, 10, 13, 14, 16, 18, 20, 23, 24, 26, 28, 30, 33));
			REQUIRE(matrix + matrix == matrix * 2);
			matrix += ece::IntMatrix4u::Identity();
			REQUIRE(matrix == ece::IntMatrix4u(3, 4, 6, 8, 10, 13, 14, 16, 18, 20, 23, 24, 26, 28, 30, 33));
		}
		AND_WHEN("Substracting a 4D matrix")
		{
			REQUIRE(matrix - ece::IntMatrix4u() == matrix);
			REQUIRE(matrix - ece::IntMatrix4u::Identity() == ece::IntMatrix4u(1, 4, 6, 8, 10, 11, 14, 16, 18, 20, 21, 24, 26, 28, 30, 31));
			REQUIRE(matrix - matrix == ece::IntMatrix4u());
			matrix -= ece::IntMatrix4u::Identity();
			REQUIRE(matrix == ece::IntMatrix4u(1, 4, 6, 8, 10, 11, 14, 16, 18, 20, 21, 24, 26, 28, 30, 31));
		}
		AND_WHEN("Getting the negative of the matrix")
		{
			REQUIRE(-matrix == ece::IntMatrix4u(-2, -4, -6, -8, -10, -12, -14, -16, -18, -20, -22, -24, -26, -28, -30, -32));
		}
		AND_WHEN("Getting a column")
		{
			REQUIRE(matrix.getColumn(0) == ece::IntVertex4u(2, 10, 18, 26));
			REQUIRE(matrix.getColumn(1) == ece::IntVertex4u(4, 12, 20, 28));
			REQUIRE(matrix.getColumn(2) == ece::IntVertex4u(6, 14, 22, 30));
			REQUIRE(matrix.getColumn(3) == ece::IntVertex4u(8, 16, 24, 32));
			REQUIRE_THROWS_AS(matrix.getColumn(-1), ece::OutOfRangeException);
			REQUIRE_THROWS_AS(matrix.getColumn(4), ece::OutOfRangeException);
		}
		AND_WHEN("Getting a row")
		{
			REQUIRE(matrix.getRow(0) == ece::IntVertex4u(2, 4, 6, 8));
			REQUIRE(matrix.getRow(1) == ece::IntVertex4u(10, 12, 14, 16));
			REQUIRE(matrix.getRow(2) == ece::IntVertex4u(18, 20, 22, 24));
			REQUIRE(matrix.getRow(3) == ece::IntVertex4u(26, 28, 30, 32));
			REQUIRE_THROWS_AS(matrix.getRow(-1), ece::OutOfRangeException);
			REQUIRE_THROWS_AS(matrix.getRow(4), ece::OutOfRangeException);

			REQUIRE(matrix[0] == ece::IntVertex4u(2, 4, 6, 8));
			REQUIRE(matrix[1] == ece::IntVertex4u(10, 12, 14, 16));
			REQUIRE(matrix[2] == ece::IntVertex4u(18, 20, 22, 24));
			REQUIRE(matrix[3] == ece::IntVertex4u(26, 28, 30, 32));
			REQUIRE_THROWS_AS(matrix[-1], ece::OutOfRangeException);
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
			REQUIRE(matrix.transpose() == ece::IntMatrix4u(2, 10, 18, 26, 4, 12, 20, 28, 6, 14, 22, 30, 8, 16, 24, 32));
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
				REQUIRE(inverse == ece::IntMatrix4u());
			}
		}
	}

	GIVEN("An invertible matrix")
	{
		ece::IntMatrix4u matrix(1, 1, 1, 0, 0, 3, 1, 2, 2, 3, 1, 0, 1, 0, 2, 1);

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
				REQUIRE(inverse == ece::DoubleMatrix4u(-3.0f, -0.5f, 1.5f, 1.0f,
														1.0f, 0.25f, -0.25f, -0.5f,
														3.0f, 0.25f, -1.25f, -0.5f,
														-3.0f, 0.0f, 1.0f, 1.0f));
			}
		}
	}
}