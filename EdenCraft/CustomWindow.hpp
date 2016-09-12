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
	static const int NO_OPTIONS = 0b000;
	static const int FULLSCREEN = 0b001;
	static const int RESIZABLE = 0b010;
	static const int TOOLBAR = 0b100;

	CustomWindow(const int tagOptions);
	~CustomWindow();

	void initialize();
	void close();

	void draw(BaseObject& object);
	void display();
	void clear();

	void setTitle(std::string title);

	bool isOpened();

private:
	std::string titleWindow;

	GLFWwindow* window;

	int tagOptions;
};

