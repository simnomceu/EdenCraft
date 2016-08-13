/**
 * @file	CustomWindow.cpp
 *
 * @brief	Implements the custom Windows Form.
 */

#include "CustomWindow.hpp"

#include <iostream>

#include "Strings.inl"

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
	style(sf::Style::Titlebar | sf::Style::Close),
	settings()
{
	// OpenGL context settings
	this->settings.depthBits = 24;
	this->settings.stencilBits = 8;
	this->settings.antialiasingLevel = 4;
	this->settings.majorVersion = 3;
	this->settings.minorVersion = 0;

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
	// create window using parameters.
	this->create(
		this->modeWindow,
		this->titleWindow,
		this->style,
		this->settings);
}
