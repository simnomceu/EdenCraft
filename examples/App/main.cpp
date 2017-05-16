/**
 * @file	main.cpp
 *
 * @brief	Implements the main class.
 */

#include "GL\glew.h"

#include "Game.hpp"
#include "Log\ServiceLogger.hpp"
#include "Log\Logger.hpp"
#include "Window\WindowService.hpp"
#include "Window\WindowManagerGLFW.hpp"
#include "Window\BaseWindow.hpp"
#include "GraphicLibrary\ServiceGL.hpp"
#include "GraphicLibrary\OpenGL.hpp"

#include <iostream>
#include <exception>
#include <string>

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

// TODO: create another project in the solution to analize the code smell
// it could be to check if there is no more than 8-10 methods in a class (with step: green level (? < 6), orange(6 < ? < 10) and red(? > 10)
// number of parameters by method (no more than 2-3 parameters)
// etc ....
// thsi could be developped using qt module at the beginning, and then, be replaced by ece designer in the future.
auto main() -> int
{
	try {
		ece::ServiceGLLocator::provide(ece::ServiceGLFactory::build<ece::OpenGL>());
		ece::WindowServiceLocator::provide(ece::WindowServiceFactory::build<ece::WindowManagerGLFW>());
		//ece::RenderingServiceLocator::provide(ece::RenderingServiceFactory::build<ece::RenderFactoryGL>());

		Game game;

		game.run();
	}
	catch (std::exception & e) {
		ece::ServiceLoggerLocator::getService().logError("Uncaught exception: " + std::string(e.what()));
	}

	return EXIT_SUCCESS;
}