#include "Core\Window\BaseWindow.hpp"

#include "Core\Window\WindowServiceLocator.hpp"

#include <iostream>
#include <memory>

namespace ece
{
	BaseWindow::BaseWindow(const ece::WindowSetting & settings) : Emitter()
	{
		this->addSignal(WINDOW_OPENED);
		this->addSignal(WINDOW_CLOSED);
	}

	BaseWindow::BaseWindow(const ece::WindowSetting & settings, const ece::VideoMode & videoMode) : Emitter()
	{
	}

	BaseWindow::BaseWindow(const BaseWindow & copy) : Emitter()
	{
	}

	BaseWindow::BaseWindow(BaseWindow && copy) : Emitter()
	{
	}

	BaseWindow::~BaseWindow()
	{
		this->close();
	}

	BaseWindow & BaseWindow::operator=(const BaseWindow & rightOperand)
	{
		// TODO: insérer une instruction return ici
	}

	BaseWindow & BaseWindow::operator=(BaseWindow && rightOperand)
	{
		// guard to prevent an assigment from itself to itself.
		if (this != &rightOperand) {
			// If an opened window is going to be overwritten, close it.
			//if (this->isOpened()) {
				this->close();
			//}

			this->windowId = std::move(rightOperand.windowId);
			this->settings = std::move(rightOperand.settings);
		}

		return *this;
	}

	void BaseWindow::open(const ece::VideoMode & videoMode)
	{
		this->windowId = ece::WindowServiceLocator::getService().openWindow();

		//ece::WindowServiceLocator::getService().setBounds(this->windowId, this->settings.getBounds());

		this->emit(WINDOW_OPENED);
	}

	void BaseWindow::close()
	{
		ece::WindowServiceLocator::getService().closeWindow(this->windowId);
		this->emit(WINDOW_CLOSED);
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

	void BaseWindow::applySettings(const ece::WindowSetting & settings)
	{
	}

	const ece::WindowSetting & BaseWindow::getSettings()
	{
		// TODO: insérer une instruction return ici
	}

	void BaseWindow::setTitle(const std::string & title)
	{
		this->settings.setTitle(title);
		//ece::WindowServiceLocator::getService().setTitle(this->windowId, title);
	}

	void BaseWindow::setBounds(const ece::Rectangle<unsigned int>& rectIn)
	{
		//ece::WindowServiceLocator::getService().setBounds(this->windowId, this->settings.getBounds());
	}

	void BaseWindow::setState(const ece::WindowState state)
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