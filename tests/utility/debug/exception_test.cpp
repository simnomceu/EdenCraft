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

#include "utility/debug/exception.hpp"

SCENARIO("Exception", "[Utility][Debug]")
{
	GIVEN("A file exception")
	{
		WHEN("Code error is BAD_PATH")
		{
			ece::FileException exception(ece::FileCodeError::BAD_PATH, "test.txt");

			REQUIRE_THAT(exception.what(), Catch::Contains("test.txt"));
			REQUIRE_THAT(exception.what(), Catch::StartsWith("Code 0"));
		}
		AND_WHEN("Code error is PARSE_ERROR")
		{
			ece::FileException exception(ece::FileCodeError::PARSE_ERROR, "test.txt");

			REQUIRE_THAT(exception.what(), Catch::Contains("test.txt"));
			REQUIRE_THAT(exception.what(), Catch::StartsWith("Code 1"));
		}
		AND_WHEN("Code error is anything but an existing code")
		{
			REQUIRE_THAT(ece::FileException(static_cast<ece::FileCodeError>(7), "test.txt").what(),
				Catch::StartsWith("Code 7"));
			REQUIRE_THAT(ece::FileException(static_cast<ece::FileCodeError>(49), "test.txt").what(),
				Catch::StartsWith("Code 49"));
		}
	}

	GIVEN("A bad input exception")
	{
		ece::BadInputException exception("trululu");
		REQUIRE_THAT(exception.what(), Catch::Contains("trululu"));
	}

	GIVEN("An initialization exception")
	{
		ece::InitializationException exception("an integer");
		REQUIRE_THAT(exception.what(), Catch::StartsWith("an integer"));
	}

	GIVEN("A memory access exception")
	{
		WHEN("No access point is defined")
		{
			ece::MemoryAccessException exception("a pointer");
			REQUIRE_THAT(exception.what(), Catch::Contains("a pointer"));
		}
		AND_WHEN("The access point is defined")
		{
			ece::MemoryAccessException exception("a pointer", "a method");
			REQUIRE_THAT(exception.what(), Catch::Contains("a pointer"));
			REQUIRE_THAT(exception.what(), Catch::Contains("a method"));
		}
	}

	GIVEN("An out of range exception")
	{
		WHEN("No id is provided")
		{
			ece::OutOfRangeException exception("an element");
			REQUIRE_THAT(exception.what(), Catch::Contains("an element"));
		}
		AND_WHEN("Any id is provided")
		{
			ece::OutOfRangeException exception("an element", 1);
			REQUIRE_THAT(exception.what(), Catch::Contains("an element"));
			REQUIRE_THAT(exception.what(), Catch::Contains("1"));
		}
	}

	GIVEN("A resource exception")
	{
		WHEN("Any id is provided")
		{
			ece::ResourceException exception("a shader", 10);
			REQUIRE_THAT(exception.what(), Catch::Contains("a shader"));
			REQUIRE_THAT(exception.what(), Catch::Contains("10"));
		}
	}
}