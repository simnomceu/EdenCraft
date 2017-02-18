#include "Catch\catch.hpp"

#include "Core\Util\UniqueID.hpp"

#include <ctime>

SCENARIO("UniqueID", "[Core][Util]")
{
	srand((unsigned int)time(nullptr));

	GIVEN("A unique ID queue, with default initialization")
	{
		ece::UniqueID queue;

		THEN("There is only the first value 0 in the queue.")
		{
			REQUIRE(queue.size() == 1);
			REQUIRE(queue.next() == 0);
		}

		WHEN("Getting the next number from the default unmodified queue")
		{
			int value = queue.next();

			THEN("Size of the queue doesn't change.")
			{
				REQUIRE(queue.size() == 1);
			}
			AND_THEN("New value in the queue is the next after the value getted.")
			{
				REQUIRE(queue.next() == value + 1);
			}
		}

		WHEN("Poping N number of time a value from the queue.")
		{
			int nb = rand()%100;
			for (int i = 0; i < nb; ++i) {
				queue.next();
			}

			THEN("The next value is the N-st value and is equal to N.")
			{
				REQUIRE(queue.next() == nb);
			}
		}

		WHEN("Pushing a value not already picked up by the queue.")
		{
			queue.restack(1);

			THEN("Value is not pushed.")
			{
				REQUIRE(queue.size() == 1);
				REQUIRE(queue.next() == 0);
			}
		}

		WHEN("Pushing a value already restacked.")
		{
			queue.next();
			queue.restack(0);
			queue.restack(0);

			THEN("Value is not restacked a second time.")
			{
				REQUIRE(queue.size() == 2);
			}
		}

		WHEN("Poping N time")
		{
			int nb = rand() % 100;
			for (int i = 0; i < nb; ++i) {
				queue.next();
			}
			int m = queue.next(), n = queue.next();
			
			THEN("The last value pop is always different than the following.")
			{
				REQUIRE(m != n);
			}
		}
	}

	GIVEN("A queue initialized with a specific first value")
	{
		ece::UniqueID queue(10);

		THEN("First value delivered is the value chosen while building the queue.")
		{
			REQUIRE(queue.next() == 10);
		}
	}
}
