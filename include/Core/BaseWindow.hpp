/**
 * @file	CustomWindow.h
 *
 * @brief	Declares the custom Windows Form.
 */

#pragma once


#pragma warning(push)
#pragma warning(disable : 4505)
#include "GL\glew.h"
#include "GL\freeglut.h"
#include "GLFW\glfw3.h"
#pragma warning(pop)

#include "Window.inl"
//#include "BaseObject.hpp"
#include "Core/Geom/Rectangle.hpp"

namespace Window
{

	/**
	* @class	BaseWindow
	*
	* @brief	Form for viewing the custom.
	*
	* @author	PIERRE
	* @date	13/08/2016
	*/
	class BaseWindow
	{
	public:
		BaseWindow(const std::string & title, const WindowTag tagOptions, const int monitorId, const Geom::Rectangle<unsigned int> & rect);
		BaseWindow(const BaseWindow & copy) = delete;
		BaseWindow(BaseWindow && copy);	
		~BaseWindow();

		BaseWindow & operator=(const BaseWindow & rightOperand) = delete;
		BaseWindow & operator=(BaseWindow && rightOperand);

		void open();
		void close();
		bool isOpened() const;

		//void draw(BaseObject& object);
		void display();
		void clear();

		void setTitle(const std::string & title);

		void setRect(const Geom::Rectangle<unsigned int> & rectIn);

		void setOptions(const WindowTag tagOptionsIn);
		bool isFullscreenActivated() const;
		bool isResizable() const;
		bool isToolbarActivated() const;

		void attachToMonitor(const int monitorIdIn); // only for fullscreen mode

	private:
		std::string titleWindow;

		short int windowId;
		GLFWmonitor* monitorToFill;

		WindowTag tagOptions;
		int monitorId;

		Geom::Rectangle<unsigned int> rect;
	};
}