/**
 * @file	BaseWindow.cpp
 *
 * @brief	Implements the custom Windows Form.
 */

#include "BaseWindow.hpp"

#include "Constants.inl"

#include "GLAdapter.hpp"
#include "ColorGL.hpp"

#include <iostream>
#include <memory>

namespace Window
{
	/**
	 * @fn	BaseWindow::BaseWindow(): RenderWindow(), modeWindow(sf::VideoMode::getDesktopMode()), titleWindow("EdenCraft"), style(sf::Style::Titlebar | sf::Style::Close), settings()
	 *
	 * @brief	Default constructor.
	 *
	 * @author	PIERRE
	 * @date	13/08/2016
	 */

	BaseWindow::BaseWindow(const std::string & title, const WindowTag tagOptions, const int monitorId) :
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
	 * @fn	BaseWindow::~BaseWindow()
	 *
	 * @brief	Destructor.
	 *
	 * @author	PIERRE
	 * @date	13/08/2016
	 */

	BaseWindow::BaseWindow(BaseWindow && copy) :
		titleWindow(std::move(copy.titleWindow)),
		window(copy.window),
		monitorToFill(copy.monitorToFill),
		tagOptions(copy.tagOptions),
		monitorId(copy.monitorId)
	{
		copy.window = nullptr;
		copy.monitorToFill = nullptr;
	}

	BaseWindow::~BaseWindow()
	{
		this->close();
	}

	/**
	 * @fn	void BaseWindow::initialize()
	 *
	 * @brief	Initializes this object.
	 *
	 * @author	PIERRE
	 * @date	13/08/2016
	 */

	BaseWindow & BaseWindow::operator=(BaseWindow && rightOperand)
	{
		this->titleWindow = std::move(rightOperand.titleWindow);
		window = rightOperand.window;
		monitorToFill = rightOperand.monitorToFill;
		tagOptions = rightOperand.tagOptions;
		monitorId = rightOperand.monitorId;

		rightOperand.window = nullptr;
		rightOperand.monitorToFill = nullptr;

		return *this;
	}

	void BaseWindow::open()
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

	void BaseWindow::close()
	{
		if (this->window && this->isOpened()) {
			glfwDestroyWindow(this->window);
		}
	}

	bool BaseWindow::isOpened() const
	{
		return this->window && !glfwWindowShouldClose(this->window);
	}

	void BaseWindow::draw(BaseObject & object)
	{
		/*
		object.prepareShaders();
		// activate the VAO to use.
		glBindVertexArray(object.getVAO());
		// draw the object
		glDrawArrays(GL_TRIANGLES, 0, 12);
		// deactivate the VAO.
		glBindVertexArray(0);
		*/
	}

	void BaseWindow::display()
	{
		if (this->window) {
			glfwSwapBuffers(this->window);
		}
	}

	void BaseWindow::clear()
	{
		GLAdapter::clearWindow(Colors::DARK_GRAY);
	}

	void BaseWindow::setTitle(const std::string & title)
	{
		this->titleWindow = title;
		if (this->window) {
			glfwSetWindowTitle(this->window, this->titleWindow.c_str());
		}
	}

	void BaseWindow::setOptions(const WindowTag tagOptionsIn)
	{
		this->tagOptions = tagOptionsIn;

		if (this->isFullscreenActivated()) {
			this->monitorToFill = glfwGetPrimaryMonitor();
		}

		if (this->isResizable()) {
			glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
		}
		else {
			glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
		}

		if (this->isToolbarActivated()) {
			glfwWindowHint(GLFW_DECORATED, GL_TRUE);
		}
		else {
			glfwWindowHint(GLFW_DECORATED, GL_FALSE);
		}
	}

	bool BaseWindow::isFullscreenActivated() const
	{
		return (this->tagOptions & FULLSCREEN) == FULLSCREEN;
	}

	bool BaseWindow::isResizable() const
	{
		return (this->tagOptions & RESIZABLE) == RESIZABLE;
	}

	bool BaseWindow::isToolbarActivated() const
	{
		return (this->tagOptions & TOOLBAR) == TOOLBAR;
	}

	void BaseWindow::attachToMonitor(const int monitorIdIn)
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