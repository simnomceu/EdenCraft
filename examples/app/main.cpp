/**
 * @file	main.cpp
 *
 * @brief	Implements the main class.
 */

#include "gl/glew.h"

#include "game.hpp"
#include "log/service_logger.hpp"
#include "log/logger.hpp"
#include "window/window_service.hpp"
#include "window/window_manager_glfw.hpp"
#include "window/base_window.hpp"
#include "graphic_library/service_gl.hpp"
#include "graphic_library/open_gl.hpp"

#include <iostream>
#include <exception>
#include <string>
#include "file/path.hpp"

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
// it could be to check if there is no more than 8-10 methods in a class (with steps: green level (? < 6), orange(6 < ? < 10) and red(? > 10)
// number of parameters by method (no more than 2-3 parameters)
// etc ....
// this could be developped using qt module at the beginning, and then, be replaced by ece designer in the future.
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