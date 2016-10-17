#pragma once

#pragma warning(push)
#pragma warning(disable : 4505)
#include "GL\glew.h"
#include "GL\freeglut.h"
#include "GLFW\glfw3.h"
#pragma warning(pop)

#include "Core/Geom/Rectangle.hpp"
#include "WindowSetting.hpp"
#include "Window.inl"

namespace Window
{
	class BaseWindow
	{
	public:
		BaseWindow(const Utils::WindowSetting & settings);
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

		void setOptions(const Utils::WindowTag tagOptionsIn);
		bool isFullscreenActivated() const;
		bool isResizable() const;
		bool isToolbarActivated() const;

		void attachToMonitor(const int monitorIdIn);

	private:
		short int windowId;

		Utils::WindowSetting settings;
	};
}