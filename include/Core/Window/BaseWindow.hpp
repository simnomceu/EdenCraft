#pragma once

#pragma warning(push)
#pragma warning(disable : 4505)
#include "GL\glew.h"
#include "GL\freeglut.h"
#include "GLFW\glfw3.h"
#pragma warning(pop)

#include "Core\Geom\Rectangle.hpp"
#include "Core\Window\WindowSetting.hpp"
#include "Core\Window\Window.inl"

namespace Window
{
	class BaseWindow
	{
	public:
		BaseWindow(const ece::WindowSetting & settings);
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

		void setWindow(const ece::WindowSetting & settings);
		ece::WindowSetting & getSettings();

		void setTitle(const std::string & title);

		void setRect(const ece::Rectangle<unsigned int> & rectIn);

		void setOptions(const ece::WindowTag tagOptionsIn);

		void attachToMonitor(const int monitorIdIn);

	private:
		short int windowId;

		ece::WindowSetting settings;
	};
}