/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

																  .o.
																 .888.
																.8"888.     oo.ooooo.  oo.ooooo.
															   .8' `888.     888' `88b  888' `88b
															  .88ooo8888.    888   888  888   888
															 .8'     `888.   888   888  888   888
															o88o     o8888o  888bod8P'  888bod8P'
																			 888        888
																			o888o      o888o

				This file is part of EdenCraft Engine - App sample.
				Copyright(C) 2018 Pierre Casati (@IsilinBN)

				This program is free software : you can redistribute it and/or modify
				it under the terms of the GNU General Public License as published by
				the Free Software Foundation, either version 3 of the License, or
				(at your option) any later version.

				This program is distributed in the hope that it will be useful,
				but WITHOUT ANY WARRANTY; without even the implied warranty of
				MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
				GNU General Public License for more details.

				You should have received a copy of the GNU General Public License
				along with this program.If not, see <http://www.gnu.org/licenses/>.

*/

#include "core/application.hpp"
#include "core/signal.hpp"

#include <string>
#include <iostream>

// TODO: create another project in the solution to analize the code smell
// it could be to check if there is no more than 8-10 methods in a class (with steps: green level (? < 6), orange(6 < ? < 10) and red(? > 10)
// number of parameters by method (no more than 2-3 parameters)
// etc ....
// this could be developped using qt module at the beginning, and then, be replaced by ece designer in the future.

class Button
{
public:
	inline Button(const std::string & name): onButtonPressed(), onButtonReleased(), _name(name) {}

	ece::Signal<const std::string &> onButtonPressed;
	ece::Signal<const std::string &> onButtonReleased;

	void push()
	{
		this->onButtonPressed(this->_name);
		std::cerr << "Pressing " << this->_name << std::endl;
		this->onButtonReleased(this->_name);
	}

	void clear()
	{
		this->onButtonPressed.disconnectAll();
		this->onButtonReleased.disconnectAll();
	}

private:
	std::string _name;
};

class Controller
{
public:
	Controller(Button & button): _connection1(), _connection2()
	{
		this->_connection1 = button.onButtonPressed.connect(*this, &Controller::pressSlot);
		this->_connection2 = button.onButtonReleased.connect(*this, &Controller::releaseSlot);
	}

	void pressSlot(const std::string & name) const { std::cerr << "Starting to press " << name << " in controller." << std::endl; }
	void releaseSlot(const std::string & name) const { std::cerr << "Releasing " << name << " in controller." << std::endl; }

private:
	ece::SecuredConnection<const std::string &> _connection1;
	ece::SecuredConnection<const std::string &> _connection2;
};

auto main() -> int
{
	auto pressSlot = [](std::string name) {
		std::cerr << "Starting to press " << name << " in main." << std::endl;
	};

	auto releaseSlot = [](std::string name) {
		std::cerr << "Releasing " << name << " in main." << std::endl;
	};

	//Controller controller;

	Button buttonA("Button A");
	//auto connection1 = buttonA.onButtonPressed.connect(controller, &Controller::pressSlot);
	//auto connection2 = buttonA.onButtonReleased.connect(controller, &Controller::releaseSlot);
	auto connection1 = buttonA.onButtonPressed.connect(pressSlot);
	auto connection2 = buttonA.onButtonReleased.connect(releaseSlot);

	buttonA.push();

	connection2.disconnect();

	std::cerr << std::endl;
	buttonA.push();

	auto pressSlotDestruction = [&connection2](std::string name) {
		std::cerr << "Deleting connection on " << name << " in main." << std::endl;
		connection2.disconnect();
	};
	connection1 = buttonA.onButtonPressed.connect(pressSlotDestruction);
	connection2 = buttonA.onButtonReleased.connect(releaseSlot);
	std::cerr << std::endl;
	buttonA.push();

	buttonA.clear();
	{
		Controller controller(buttonA);
	}
	std::cerr << std::endl << "Destruction ?" << std::endl;
	buttonA.push();

	return EXIT_SUCCESS;
}
