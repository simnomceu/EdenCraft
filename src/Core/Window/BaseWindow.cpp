
#include "Core\Window\BaseWindow.hpp"

#include "Core\Window\WindowServiceLocator.hpp"

#include <iostream>
#include <memory>

namespace Window
{
	BaseWindow::BaseWindow(const ece::WindowSetting & settings) : windowId(-1), settings(settings)
	{
	}

	BaseWindow::BaseWindow(BaseWindow && copy) : windowId(copy.windowId), settings(copy.settings)
	{
	}

	BaseWindow::~BaseWindow()
	{
		this->close();
	}

	BaseWindow & BaseWindow::operator=(BaseWindow && rightOperand)
	{
		// guard to prevent an assigment from itself to itself.
		if (this != &rightOperand) {
			// If an opened window is going to be overwritten, close it.
			if (this->isOpened()) {
				this->close();
			}

			this->windowId = std::move(rightOperand.windowId);
			this->settings = std::move(rightOperand.settings);
		}

		return *this;
	}

	void BaseWindow::open()
	{
		// TODO use alse param X and Y of rect.
		//this->windowId = glfwCreateWindow(this->rect.getWidth(), this->rect.getHeight(), this->titleWindow.c_str(), this->monitorToFill, nullptr);
		this->windowId = ece::WindowServiceLocator::getService().openWindow();
		
		//ece::WindowServiceLocator::getService().setBounds(this->windowId, this->settings.getBounds());

		/* Make the window's context current */
		//glfwMakeContextCurrent(this->window);

		//GLAdapter::init3D();
	}

	void BaseWindow::close()
	{
		ece::WindowServiceLocator::getService().closeWindow(this->windowId);
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

	void BaseWindow::setTitle(const std::string & title)
	{
		this->settings.setTitle(title);
		//ece::WindowServiceLocator::getService().setTitle(this->windowId, title);
	}

	void BaseWindow::setRect(const ece::Rectangle<unsigned int>& rectIn)
	{
		//ece::WindowServiceLocator::getService().setBounds(this->windowId, this->settings.getBounds());
	}

	void BaseWindow::setOptions(const ece::WindowTag tagOptionsIn)
	{

		/*if (this->isFullscreenActivated()) {
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
		}*/
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