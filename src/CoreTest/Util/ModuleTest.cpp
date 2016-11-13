#include "Catch\catch.hpp"

#include "Core\Core.hpp"

#include <iostream>

SCENARIO("Service/module system", "[Core][Util][Conflicts]")
{
	GIVEN("Core not initialized.")
	{
		WHEN("Core is initialized by default.")
		{
			ece::Core::init(ece::LOG, ece::SYSTEM);
			THEN("Log service and system module are initialized.")
			{
				REQUIRE(ece::Core::isModuleInit(ece::SYSTEM));
				REQUIRE(ece::Core::isServiceInit(ece::LOG));
				REQUIRE(ece::Core::isServiceInit(ece::EVENT));
			}
		}

		WHEN("Core is initialized with Window module.")
		{
			ece::Core::init(ece::LOG, ece::SYSTEM | ece::WINDOW);
			THEN("Log service, system and window modules ares initialized once and only once.")
			{
				REQUIRE(ece::Core::isModuleInit(ece::SYSTEM));
				REQUIRE(ece::Core::isModuleInit(ece::WINDOW));
				REQUIRE(ece::Core::isServiceInit(ece::LOG));
				REQUIRE(ece::Core::isServiceInit(ece::EVENT));
				REQUIRE(ece::Core::isServiceInit(ece::WINDOW));
			}
		}

		WHEN("Core is initialized with Window module witout dependencies.")
		{
			ece::Core::init(ece::LOG, ece::WINDOW);
			THEN("Log service, window modules ares initialized once and only once. By dependency, System module is also initialized.")
			{
				REQUIRE(ece::Core::isModuleInit(ece::SYSTEM));
				REQUIRE(ece::Core::isModuleInit(ece::WINDOW));
				REQUIRE(ece::Core::isServiceInit(ece::LOG));
				REQUIRE(ece::Core::isServiceInit(ece::EVENT));
				REQUIRE(ece::Core::isServiceInit(ece::WINDOW));
			}
		}
	}
}