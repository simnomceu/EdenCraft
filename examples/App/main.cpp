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
#include "Window\BaseWindow.hpp"
//#include "Rendering\Model\Object.hpp"
//#include "Rendering\Model\Program.hpp"
//#include "Rendering\RenderingService.hpp"
//#include "Rendering\RenderFactoryGL.hpp"

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
	// TODO : error while modules are not inialized explicitly here.
	/*try {
		ece::Core::init(ece::LOG, ece::SYSTEM | ece::WINDOW | ece::GRAPHIC);
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}*/
	try {
		ece::ServiceLoggerLocator::provide(ece::ServiceLoggerFactory::build<ece::Logger>());
		ece::EventServiceLocator::provide(ece::EventServiceFactory::build<ece::EventManager>());
		ece::WindowServiceLocator::provide(ece::WindowServiceFactory::build<ece::WindowManagerGLFW>());
		//ece::RenderingServiceLocator::provide(ece::RenderingServiceFactory::build<ece::RenderFactoryGL>());

		Game game;

		game.run();
	}
	catch (std::exception & e) {
		ece::ServiceLoggerLocator::getService().logError("Uncaught exception: " + std::string(e.what()));
	}

	// ########################################################

	/*ece::BaseWindow * window = new ece::BaseWindow(ece::WindowSetting());
	window->open(ece::VideoMode());
	window->setTitle("Wonderful, it's working!");

	ece::Object object;
	object.buildFromFile("../resource/shader/cube.dat");

	ece::OldGLSLProgram program;
	program.init();
	program.loadShaderFromFile(ece::OldGLSLProgram::FRAGMENT, "../resource/shader/basic.frag");
	program.loadShaderFromFile(ece::OldGLSLProgram::VERTEX, "../resource/shader/basic.vert");

	object.prepare();
	program.link();

	while (!window->shouldClosed()) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		object.render(program, glm::mat4(1.0f), glm::mat4(1.0f));
		glfwPollEvents();
		window->display();
	}
	window->close();*/

	return EXIT_SUCCESS;
}