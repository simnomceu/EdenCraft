#include "Catch2/single_include/catch.hpp"

#include "utility/file_system/path.hpp"

SCENARIO("Path", "[Utility][File]")
{
	WHEN("Getting the current path")
	{
		auto current = ece::Path::currentPath();

		REQUIRE(current.exists());
		REQUIRE(current.getDepth() > 0);
		REQUIRE_THAT(current.getPathname(), Catch::Contains(current.getPath()));
		REQUIRE(current.getFilename().empty());
		REQUIRE_FALSE(current.isFile());
		REQUIRE(current.isFolder());
	}
	AND_WHEN("Getting a valid absolute path")
	{
		ece::Path path(ece::Path::currentPath().getPathname() + "../tests/resource/");

		REQUIRE(path.exists());
		REQUIRE_THAT(path.getPathname(), Catch::StartsWith(ece::Path::currentPath().getPathname()));
	}
	AND_WHEN("Getting a valid relative path")
	{
		ece::Path path("../tests/resource/");

		REQUIRE(path.exists());
		REQUIRE_THAT(path.getPathname(), Catch::StartsWith(ece::Path::currentPath().getPathname()));
	}
	AND_WHEN("Getting an invalid path")
	{
		ece::Path path("../testing/resource/");

		REQUIRE_FALSE(path.exists());
	}
	AND_WHEN("Getting a valid file")
	{
		ece::Path path(ece::Path::currentPath().getPathname() + "../tests/resource/file.txt");

		REQUIRE(path.exists());
		REQUIRE_THAT(path.getPathname(), Catch::StartsWith(ece::Path::currentPath().getPathname()));
		REQUIRE_THAT(path.getFilename(), Catch::EndsWith("file.txt"));
	}
	AND_WHEN("Getting an empty path")
	{
		ece::Path path;

		REQUIRE_FALSE(path.exists());
		REQUIRE(path.getPathname().empty());
	}
}