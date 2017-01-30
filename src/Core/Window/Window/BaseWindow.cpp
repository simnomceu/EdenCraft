
#include "Core\Window\Window\BaseWindow.hpp"

#include "Core\Window\WindowService.hpp"

#include <iostream>
#include <memory>

namespace ece
{
	BaseWindow::BaseWindow(const ece::WindowSetting & settings) : Emitter(), windowId(-1), settings(), videoMode()
	{
		this->addSignal(WINDOW_OPENED);
		this->addSignal(WINDOW_CLOSED);
		this->addSignal(WINDOW_RESIZED);
		this->addSignal(WINDOW_MOVED);
		this->addSignal(WINDOW_RENAMED);
	}

	BaseWindow::BaseWindow(const ece::WindowSetting & settings, const ece::VideoMode & videoMode) : Emitter(), windowId(-1), settings(), videoMode()
	{
	}

	BaseWindow::BaseWindow(const BaseWindow & copy) : Emitter(), windowId(-1), settings(), videoMode()
	{
	}

	BaseWindow::BaseWindow(BaseWindow && copy) : Emitter(), windowId(-1), settings(), videoMode()
	{
	}

	BaseWindow::~BaseWindow()
	{
		this->close();
	}

	BaseWindow & BaseWindow::operator=(const BaseWindow & rightOperand)
	{
		// TODO: insérer une instruction return ici
		return *this;
	}

	BaseWindow & BaseWindow::operator=(BaseWindow && rightOperand)
	{
		// guard to prevent an assigment from itself to itself.
		if (this != &rightOperand) {
			// If an opened window is going to be overwritten, close it.
			/*if (this->isOpened()) {
				this->close();
			}*/

			this->windowId = std::move(rightOperand.windowId);
			this->settings = std::move(rightOperand.settings);
		}

		return *this;
	}

	void BaseWindow::open(const ece::VideoMode & videoMode)
	{
		ece::WindowServiceLocator::getService().provideVideoMode(videoMode);
		this->windowId = ece::WindowServiceLocator::getService().openWindow();

		//ece::WindowServiceLocator::getService().setBounds(this->windowId, this->settings.getBounds());
		WindowServiceLocator::getService().registerEventHandler(this->windowId);

		this->emit(WINDOW_OPENED);
	}

	void BaseWindow::close()
	{
		ece::WindowServiceLocator::getService().closeWindow(this->windowId);
		this->windowId = -1;
		this->emit(WINDOW_CLOSED);
	}

	bool BaseWindow::shouldClosed() const
	{
		return this->windowId != -1 && WindowServiceLocator::getService().windowShouldClose(this->windowId);
	}

	void BaseWindow::applySettings(const ece::WindowSetting & settings)
	{
		this->setBounds(settings.getBounds());
		this->setTitle(settings.getTitle());
		this->setState(settings.getState());
	}

	const ece::WindowSetting & BaseWindow::getSettings()
	{
		return this->settings;
	}

	void BaseWindow::setTitle(const std::string & title)
	{
		auto lastTitle = this->settings.getTitle();
		this->settings.setTitle(title);
		if (lastTitle != this->settings.getTitle()) {
			this->emit(WINDOW_RENAMED);
		}
		ece::WindowServiceLocator::getService().setTitle(this->windowId, this->settings.getTitle());
	}

	void BaseWindow::setBounds(const ece::Rectangle<unsigned int>& bounds)
	{
		auto lastBounds = this->settings.getBounds();
		this->settings.setBounds(bounds);
		if (lastBounds.getX() != bounds.getX() || lastBounds.getY() != bounds.getY()) {
			this->emit(WINDOW_MOVED);
		}
		if (lastBounds.getWidth() != bounds.getWidth() || lastBounds.getHeight() != bounds.getHeight()) {
			this->emit(WINDOW_RESIZED);
		}
		ece::WindowServiceLocator::getService().setBounds(this->windowId, this->settings.getBounds());
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

	const bool BaseWindow::pollEvent(Event & event)
	{
		WindowServiceLocator::getService().pollEvents(this->windowId, event);
		return false;
	}

	const bool BaseWindow::waitEvent(Event & event)
	{
		WindowServiceLocator::getService().waitEvents(this->windowId, event);
		return false;
	}
}