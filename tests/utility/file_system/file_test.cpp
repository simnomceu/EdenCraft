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

#include "utility/file_system.hpp"

SCENARIO("File", "[Utility][File]")
{
	WHEN("A file is created empty.")
	{
		ece::File file;
		REQUIRE_FALSE(file.isOpen());
		REQUIRE(file.parseToString().empty());
		REQUIRE(file.parseToVector<char>().empty());

		THEN("Something is writen inside")
		{
			//file << 5; // TODO: should throw an exception ?
			REQUIRE(file.parseToString().empty());
		}
		AND_THEN("Something is read from the file")
		{
			int a = 0;
			file >> a; // TODO: should throw an exception ?
			REQUIRE(a == 0);
		}
		AND_THEN("The file is closed")
		{
			file.close();
			REQUIRE_FALSE(file.isOpen());
		}
		AND_THEN("A new existing file is opened instead of.")
		{
			REQUIRE(file.open("../tests/resource/file.txt", ece::OpenMode::in));
			REQUIRE(file.isOpen());
			REQUIRE_THAT(file.parseToString(), Catch::Contains("test"));
			file.close();
		}
	}
	AND_WHEN("An unknown file is used")
	{
		const std::string path("../tests/resource/unknown_file.txt");
		REQUIRE_FALSE(ece::File::exists(path));

		THEN("We try to open it")
		{
			ece::File file;
			REQUIRE_THROWS_AS(file.open(path, ece::OpenMode::in), ece::FileException);
			REQUIRE_FALSE(file.isOpen());
		}
	}
	AND_WHEN("An existing file is used.")
	{
		const std::string path("../tests/resource/file.txt");
		REQUIRE(ece::File::exists(path));

		ece::File file;

		THEN("We open the file")
		{
			REQUIRE_NOTHROW(file.open(path, ece::OpenMode::in));
			REQUIRE(file.isOpen());
			file.close();
		}
		AND_THEN("We read the file")
		{
			file.open(path, ece::OpenMode::in);
			REQUIRE_THAT(file.parseToString(), Catch::Contains("test"));
			file.close();
		}
		AND_THEN("We write in the file")
		{
			file.open(path, ece::OpenMode::out | ece::OpenMode::app);
			//file << 5;
			file.open(path, ece::OpenMode::in);
			REQUIRE_THAT(file.parseToString(), Catch::Contains("5"));
			file.close();
		}

		file.open(path, ece::OpenMode::in);
		CHECK_THAT(file.parseToString(), Catch::StartsWith("test") && Catch::EndsWith("test"));
		file.close();
	}
}