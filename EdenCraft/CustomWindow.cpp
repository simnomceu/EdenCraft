/**
 * @file	CustomWindow.cpp
 *
 * @brief	Implements the custom Windows Form.
 */

#include "CustomWindow.hpp"

#include "Strings.inl"
#include "Constants.inl"

#include "GLAdapter.hpp"

#include <iostream>
#include <memory>


/**
 * @fn	CustomWindow::CustomWindow(): RenderWindow(), modeWindow(sf::VideoMode::getDesktopMode()), titleWindow("EdenCraft"), style(sf::Style::Titlebar | sf::Style::Close), settings()
 *
 * @brief	Default constructor.
 *
 * @author	PIERRE
 * @date	13/08/2016
 */

CustomWindow::CustomWindow(const int tagOptions):
	titleWindow(Strings::APP_TITLE),
	window(nullptr),
	tagOptions(tagOptions)
{
}

/**
 * @fn	CustomWindow::~CustomWindow()
 *
 * @brief	Destructor.
 *
 * @author	PIERRE
 * @date	13/08/2016
 */

CustomWindow::~CustomWindow()
{
	if (this->isOpened()) {
		this->close();
	}
}

/**
 * @fn	void CustomWindow::initialize()
 *
 * @brief	Initializes this object.
 *
 * @author	PIERRE
 * @date	13/08/2016
 */

void CustomWindow::initialize()
{
	GLAdapter::initGLFW();

	GLFWmonitor* monitor = nullptr;

	if ((this->tagOptions & FULLSCREEN) == FULLSCREEN) {
		monitor = glfwGetPrimaryMonitor();
	}

	this->window = glfwCreateWindow(640, 480, this->titleWindow.c_str(), monitor, nullptr);
	if (!this->window) {
		std::cerr << "Context cannot be created ..." << std::endl;
		glfwTerminate();
	}
	else {
		/* Make the window's context current */
		glfwMakeContextCurrent(this->window);

		GLAdapter::initGLContext();

		GLAdapter::init3D();

		GLAdapter::displayContextInfos();
	}
}

void CustomWindow::close()
{
	if (this->window) {
		glfwDestroyWindow(this->window);
	}
}

void CustomWindow::draw(BaseObject & object)
{
	object.prepareShaders();
	// activate the VAO to use.
	glBindVertexArray(object.getVAO());
	// draw the object
	glDrawArrays(GL_TRIANGLES, 0, 12);
	// deactivate the VAO.
	glBindVertexArray(0);
}

void CustomWindow::setTitle(std::string title)
{
	glfwSetWindowTitle(this->window, title.c_str());
}

void CustomWindow::display()
{
	glfwSwapBuffers(this->window);
}

bool CustomWindow::isOpened()
{
	return !glfwWindowShouldClose(window);
}
