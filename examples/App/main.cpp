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
#include "Rendering\Model\Object.hpp"
#include "Rendering\Model\OldGLSLProgram.hpp"
//#include "Rendering\RenderingService.hpp"
//#include "Rendering\RenderFactoryGL.hpp"

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
	//ece::RenderingServiceLocator::provide(ece::RenderingServiceFactory::build<ece::RenderFactoryGL>());

	Game game;

	game.run();


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