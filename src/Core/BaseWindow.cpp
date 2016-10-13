/**
 * @file	BaseWindow.cpp
 *
 * @brief	Implements the custom Windows Form.
 */

#include "Core/BaseWindow.hpp"

//#include "Constants.inl"

//#include "GLAdapter.hpp"
//#include "ColorGL.hpp"
#include "Core/WindowServiceLocator.hpp"

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

	BaseWindow::BaseWindow(const std::string & title, const WindowTag tagOptions, const int monitorId, const Geom::Rectangle<unsigned int> & rect) :
		titleWindow(title),
		windowId(-1),
		monitorToFill(nullptr),
		tagOptions(NO_OPTIONS),
		monitorId(0),
		rect(rect)
	{
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
		windowId(copy.windowId),
		monitorToFill(copy.monitorToFill),
		tagOptions(copy.tagOptions),
		monitorId(copy.monitorId),
		rect(std::move(copy.rect))
	{
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
		this->windowId = rightOperand.windowId;
		this->monitorToFill = rightOperand.monitorToFill;
		this->tagOptions = rightOperand.tagOptions;
		this->monitorId = rightOperand.monitorId;
		this->rect = std::move(rightOperand.rect);

		rightOperand.monitorToFill = nullptr;

		return *this;
	}

	void BaseWindow::open()
	{
		// TODO use alse param X and Y of rect.
		//this->windowId = glfwCreateWindow(this->rect.getWidth(), this->rect.getHeight(), this->titleWindow.c_str(), this->monitorToFill, nullptr);
		this->windowId = Utils::WindowServiceLocator::getService().openWindow();
		
		Utils::WindowServiceLocator::getService().setBounds(this->windowId, this->rect);

		/* Make the window's context current */
		//glfwMakeContextCurrent(this->window);

		//GLAdapter::init3D();
	}

	void BaseWindow::close()
	{
		Utils::WindowServiceLocator::getService().closeWindow(this->windowId);
	}

	bool BaseWindow::isOpened() const
	{
		return this->windowId != -1;
	}

	/*void BaseWindow::draw(BaseObject & object)
	{
		object.prepareShaders();
		// activate the VAO to use.
		glBindVertexArray(object.getVAO());
		// draw the object
		glDrawArrays(GL_TRIANGLES, 0, 12);
		// deactivate the VAO.
		glBindVertexArray(0);
	}*/

	void BaseWindow::display()
	{
		/*if (this->window) {
			glfwSwapBuffers(this->window);
		}*/
	}

	void BaseWindow::clear()
	{
		//GLAdapter::clearWindow(Colors::DARK_GRAY);
	}

	void BaseWindow::setTitle(const std::string & title)
	{
		this->titleWindow = title;
		Utils::WindowServiceLocator::getService().setTitle(this->windowId, title);
	}

	void BaseWindow::setRect(const Geom::Rectangle<unsigned int>& rectIn)
	{
		Utils::WindowServiceLocator::getService().setBounds(this->windowId, this->rect);
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
		/*if (monitorId < GLAdapter::getNumberOfMonitors()) {
			this->monitorId = monitorIdIn;
		}

		if (this->isFullscreenActivated()) {
			this->monitorToFill = GLAdapter::getMonitor(this->monitorId);
		}*/

		/*if (this->isOpened() && this->isFullscreenActivated()) {
			this->close();
			this->open();
		}*/
	}
}