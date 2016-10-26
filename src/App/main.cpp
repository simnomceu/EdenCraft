/**
 * @file	main.cpp
 *
 * @brief	Implements the main class.
 */

#include "App\Game.hpp"
#include "Core\Window\WindowSystem.hpp"

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
	ece::WindowSystem::initWindowService();

	auto game = Game::getInstance();
	auto usableGame = game.lock();

	usableGame->run();

	return EXIT_SUCCESS;
}