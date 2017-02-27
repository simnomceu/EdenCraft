/**
 * @file	main.cpp
 *
 * @brief	Implements the main class.
 */

#include "GL\glew.h"

#include "Game.hpp"
#include "Util\Log\ServiceLogger.hpp"
#include "Util\Log\Logger.hpp"
#include "System\Event\EventService.hpp"
#include "System\Event\EventManager.hpp"
#include "Window\WindowService.hpp"
#include "Window\WindowManagerGLFW.hpp"

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
	/*try {
		ece::Core::init(ece::LOG, ece::SYSTEM | ece::WINDOW | ece::GRAPHIC);
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}*/
	ece::ServiceLoggerLocator::provide(ece::ServiceLoggerFactory::build<ece::Logger>());
	ece::EventServiceLocator::provide(ece::EventServiceFactory::build<ece::EventManager>());
	ece::WindowServiceLocator::provide(ece::WindowServiceFactory::build<ece::WindowManagerGLFW>());

	Game game;

	game.run();

	return EXIT_SUCCESS;
}