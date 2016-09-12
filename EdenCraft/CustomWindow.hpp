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

#include "BaseObject.hpp"

/**
 * @class	CustomWindow
 *
 * @brief	Form for viewing the custom.
 *
 * @author	PIERRE
 * @date	13/08/2016
 */

class CustomWindow
{
public:
	using WindowTag = unsigned short int;

	static const WindowTag NO_OPTIONS = 0b000;
	static const WindowTag FULLSCREEN = 0b001;
	static const WindowTag RESIZABLE = 0b010;
	static const WindowTag TOOLBAR = 0b100;

	CustomWindow(const std::string & title, const WindowTag tagOptions);
	~CustomWindow();

	void initialize();
	void close();

	bool isOpened();

	void draw(BaseObject& object);
	void display();
	void clear();

	void setTitle(std::string title);

	void setOptions(const WindowTag tagOptions);

private:
	std::string titleWindow;

	GLFWwindow* window;
	GLFWmonitor* monitorToFill;
};

