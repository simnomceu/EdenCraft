/**
 * @file	main.cpp
 *
 * @brief	Implements the main class.
 */

#include "App\Game.hpp"
#include "Core\Core.hpp"

#include <iostream>
#include <exception>

/**
 * @fn	int main()
 *
 * @brief	Main entry-point for this application.
 *
 * @author	PIERRE
 * @date	13/08/2016
 *
 * @return	Exit-code for the process - 0 for success, else an error code.
 */

auto main() -> int
{
	// TODO : error while modules are not inialized explicitly here.
	try {
		ece::Core::init(ece::LOG, ece::SYSTEM | ece::WINDOW | ece::GRAPHIC);
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}

	Game game;

	game.run();

	return EXIT_SUCCESS;
}