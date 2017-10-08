#define CATCH_CONFIG_RUNNER

#include "catch/catch.hpp"

int main(int argc, char* const argv[])
{
	Catch::Session session;

	int returnCode = session.applyCommandLine(argc, argv);
	if (returnCode != 0) {
		return returnCode;
	}

	// writing to session.configData() or session.Config() here 
	// overrides command line args
	// only do this if you know you need to
	int numFailed = session.run();

	return (numFailed < 0xff ? numFailed : 0xff);
}