#include "Catch2/single_include/catch.hpp"

#include "utility/file_system/file.hpp"

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