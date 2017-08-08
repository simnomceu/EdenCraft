#include "catch\catch.hpp"

#include "mathematics\matrix2u.hpp"

SCENARIO("Matrix2u", "[Utility][Mathematics]")
{
	REQUIRE(ece::IntMatrix2u() == ece::IntMatrix2u(0, 0, 0, 0));
	REQUIRE(ece::IntMatrix2u() == ece::IntMatrix2u(ece::IntVertex2u(), ece::IntVertex2u()));
	REQUIRE(ece::IntMatrix2u() == ece::IntMatrix2u(ece::FloatVertex2u(), ece::FloatVertex2u()));
	REQUIRE(ece::IntMatrix2u::Identity() == ece::IntMatrix2u(1, 0, 0, 1));

	GIVEN("A simple matrix")
	{
		ece::IntMatrix2u matrix(2, 4, 6, 8);

		WHEN("Setting it to the identy matrix")
		{
			REQUIRE(matrix.setIdentity() == ece::IntMatrix2u::Identity());
		}
		AND_WHEN("Multiplying all the members by 2")
		{
			REQUIRE(matrix * 0 == ece::IntMatrix2u());
			REQUIRE(matrix * 2 == ece::IntMatrix2u(4, 8, 12, 16));
			matrix *= 2;
			REQUIRE(matrix == ece::IntMatrix2u(4, 8, 12, 16));
		}
		AND_WHEN("Dividing all the members by 2")
		{
			REQUIRE_THROWS_AS(matrix / 0, ece::DivideByZeroException);
			REQUIRE_THROWS_AS(matrix /= 0, ece::DivideByZeroException);
			REQUIRE(matrix / 2 == ece::IntMatrix2u(1, 2, 3, 4));
			matrix /= 2;
			REQUIRE(matrix == ece::IntMatrix2u(1, 2, 3, 4));
		}
		AND_WHEN("Multiplying a 2D vector")
		{
			REQUIRE(matrix * ece::IntVertex2u() == ece::IntVertex2u());
			REQUIRE(matrix * ece::IntVertex2u(1, 1) == ece::IntVertex2u(6, 14));
		}
		AND_WHEN("Multiplying a 2D matrix")
		{
			REQUIRE(matrix * ece::IntMatrix2u() == ece::IntMatrix2u());
			REQUIRE(matrix * ece::IntMatrix2u::Identity() == matrix);
			REQUIRE(matrix * matrix == ece::IntMatrix2u(28, 40, 60, 88));
			matrix *= ece::IntMatrix2u(2, 4, 6, 8);
			REQUIRE(matrix == ece::IntMatrix2u(28, 40, 60, 88));
		}
		AND_WHEN("Adding a 2D matrix")
		{
			REQUIRE(matrix + ece::IntMatrix2u() == matrix);
			REQUIRE(matrix + ece::IntMatrix2u::Identity() == ece::IntMatrix2u(3, 4, 7, 8));
			REQUIRE(matrix + matrix == matrix * 2);
			matrix += ece::IntMatrix2u::Identity();
			REQUIRE(matrix == ece::IntMatrix2u(3, 4, 7, 8));
		}
		AND_WHEN("Substracting a 2D matrix")
		{
			REQUIRE(matrix - ece::IntMatrix2u() == matrix);
			REQUIRE(matrix - ece::IntMatrix2u::Identity() == ece::IntMatrix2u(1, 4, 5, 8));
			REQUIRE(matrix - matrix == ece::IntMatrix2u());
			matrix -= ece::IntMatrix2u::Identity();
			REQUIRE(matrix == ece::IntMatrix2u(1, 4, 5, 8));
		}
		AND_WHEN("Getting the negative of the matrix")
		{
			REQUIRE(-matrix == ece::IntMatrix2u(-2, -4, -6, -8));
		}
		AND_WHEN("Getting a column")
		{
			REQUIRE(matrix.getColumn(0) == ece::IntVertex2u(2, 6));
			REQUIRE(matrix.getColumn(1) == ece::IntVertex2u(4, 8));
			REQUIRE_THROWS_AS(matrix.getColumn(-1), ece::OutOfRangeException);
			REQUIRE_THROWS_AS(matrix.getColumn(2), ece::OutOfRangeException);
		}
		AND_WHEN("Getting a row")
		{
			REQUIRE(matrix.getRow(0) == ece::IntVertex2u(2, 4));
			REQUIRE(matrix.getRow(1) == ece::IntVertex2u(6, 8));
			REQUIRE_THROWS_AS(matrix.getRow(-1), ece::OutOfRangeException);
			REQUIRE_THROWS_AS(matrix.getRow(2), ece::OutOfRangeException);

			REQUIRE(matrix[0] == ece::IntVertex2u(2, 4));
			REQUIRE(matrix[1] == ece::IntVertex2u(6, 8));
			REQUIRE_THROWS_AS(matrix[-1], ece::OutOfRangeException);
			REQUIRE_THROWS_AS(matrix[2], ece::OutOfRangeException);
		}
		AND_WHEN("Getting an element")
		{
			REQUIRE(matrix[0][0] == 2);
			REQUIRE(matrix[0][1] == 4);
			REQUIRE(matrix[1][0] == 6);
			REQUIRE(matrix[1][1] == 8);
		}
		AND_WHEN("Getting the determinant")
		{
			REQUIRE(matrix.determinant() == -8);
		}
		AND_WHEN("Getting the transpose matrix")
		{
			REQUIRE(matrix.transpose() == ece::IntMatrix2u(2, 6, 4, 8));
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
				REQUIRE(inverse == ece::IntMatrix2u());
			}
		}
	}
	
	GIVEN("An invertible matrix")
	{
		ece::IntMatrix2u matrix(4, 2, 6, 8);

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
				REQUIRE(inverse == ece::DoubleMatrix2u(0.4, -0.1, -0.3, 0.2));
			}
		}
	}
}