/**
 * @file	CustomWindow.cpp
 *
 * @brief	Implements the custom Windows Form.
 */

#include "CustomWindow.hpp"

#include "Strings.inl"
#include "Constants.inl"

#include <iostream>
#include <memory>

#pragma warning(push)
#pragma warning(disable : 4505)
#include "GL\glew.h"
#include "GL\freeglut.h"
#pragma warning(pop)

/**
 * @fn	CustomWindow::CustomWindow(): RenderWindow(), modeWindow(sf::VideoMode::getDesktopMode()), titleWindow("EdenCraft"), style(sf::Style::Titlebar | sf::Style::Close), settings()
 *
 * @brief	Default constructor.
 *
 * @author	PIERRE
 * @date	13/08/2016
 */

CustomWindow::CustomWindow(): 
	RenderWindow(),
	modeWindow(sf::VideoMode::getDesktopMode()),
	titleWindow(Strings::APP_TITLE),
	style(sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize),
	settings()
{
	// OpenGL context settings
	this->settings.depthBits = Constants::GL_DEPTH_BITS_EC;
	this->settings.stencilBits = Constants::GL_STENCIL_BITS_EC;
	this->settings.antialiasingLevel = Constants::GL_ANTIALIASING_LEVEL_EC;
	this->settings.majorVersion = Constants::GL_MAJOR_VERSION_EC;
	this->settings.minorVersion = Constants::GL_MINOR_VERSION_EC;
	// Profil fags :
	// Default : compatibility mode active. Requirement when working with OpenGL 3.2+
	// Debug
	// Core : OS X works only with this mode. Then, OS X can only use OpenGL 2.1 and below in an SFML window.
	this->settings.attributeFlags = sf::ContextSettings::Attribute::Default;

	this->modeWindow.height -= 70; // remove the height of application bar and title bar.
}

/**
 * @fn	CustomWindow::~CustomWindow()
 *
 * @brief	Destructor.
 *
 * @author	PIERRE
 * @date	13/08/2016
 */

CustomWindow::~CustomWindow()
{
	this->close();
}

/**
 * @fn	void CustomWindow::initialize()
 *
 * @brief	Initializes this object.
 *
 * @author	PIERRE
 * @date	13/08/2016
 */

void CustomWindow::initialize()
{
	// Create window using parameters.
	this->create(this->modeWindow, this->titleWindow, this->style, this->settings);

	// Set the refreshing rate of window
	this->setVerticalSyncEnabled(false);
	//this->setFramerateLimit(40);
}

void CustomWindow::draw(BaseObject & object)
{
	object.prepareShaders();
	// activate the VAO to use.
	glBindVertexArray(object.getVAO());
	// draw the object
	glDrawArrays(GL_TRIANGLES, 0, 12);
	// deactivate the VAO.
	glBindVertexArray(0);
}
