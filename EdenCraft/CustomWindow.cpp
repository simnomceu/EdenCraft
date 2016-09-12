/**
 * @file	CustomWindow.cpp
 *
 * @brief	Implements the custom Windows Form.
 */

#include "CustomWindow.hpp"

#include "Constants.inl"

#include "GLAdapter.hpp"
#include "ColorGL.hpp"

#include <iostream>
#include <memory>

namespace Window
{
	/**
	 * @fn	CustomWindow::CustomWindow(): RenderWindow(), modeWindow(sf::VideoMode::getDesktopMode()), titleWindow("EdenCraft"), style(sf::Style::Titlebar | sf::Style::Close), settings()
	 *
	 * @brief	Default constructor.
	 *
	 * @author	PIERRE
	 * @date	13/08/2016
	 */

	CustomWindow::CustomWindow(const std::string & title, const WindowTag tagOptions, const int monitorId) :
		titleWindow(title),
		window(nullptr),
		monitorToFill(nullptr),
		tagOptions(NO_OPTIONS),
		monitorId(0)
	{
		// TODO move init out of here, and add a check
		GLAdapter::initGLFW();

		this->setOptions(tagOptions);
		this->attachToMonitor(monitorId);
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

	void CustomWindow::open()
	{
		this->window = glfwCreateWindow(640, 480, this->titleWindow.c_str(), this->monitorToFill, nullptr);
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

	bool CustomWindow::isOpened()
	{
		return this->window && !glfwWindowShouldClose(this->window);
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

	void CustomWindow::display()
	{
		glfwSwapBuffers(this->window);
	}

	void CustomWindow::clear()
	{
		GLAdapter::clearWindow(Colors::DARK_GRAY);
	}

	void CustomWindow::setTitle(std::string title)
	{
		this->titleWindow = title;
		glfwSetWindowTitle(this->window, this->titleWindow.c_str());
	}

	void CustomWindow::setOptions(const WindowTag tagOptionsIn)
	{
		this->tagOptions = tagOptionsIn;

		if (this->isFullscreenActivated()) {
			this->monitorToFill = glfwGetPrimaryMonitor();
		}

		if ((this->tagOptions & RESIZABLE) == RESIZABLE) {
			glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
		}
		else {
			glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
		}

		if ((this->tagOptions & TOOLBAR) == TOOLBAR) {
			glfwWindowHint(GLFW_DECORATED, GL_TRUE);
		}
		else {
			glfwWindowHint(GLFW_DECORATED, GL_FALSE);
		}
	}

	bool CustomWindow::isFullscreenActivated()
	{
		return (this->tagOptions & FULLSCREEN) == FULLSCREEN;
	}

	void CustomWindow::attachToMonitor(const int monitorIdIn)
	{
		if (monitorId < GLAdapter::getNumberOfMonitors()) {
			this->monitorId = monitorIdIn;
		}

		if (this->isFullscreenActivated()) {
			this->monitorToFill = GLAdapter::getMonitor(this->monitorId);
		}

		if (this->isOpened() && this->isFullscreenActivated()) {
			this->close();
			this->open();
		}
	}
}