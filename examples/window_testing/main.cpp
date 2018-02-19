/*
	
	oooooooooooo       .o8                          .oooooo.                       .o88o.     .   
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8   
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo 
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888   
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888   
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 . 
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888" 

							oooooo   oooooo     oooo  o8o                    .o8                             ooooooooooooo                        .    o8o                         
							 `888.    `888.     .8'   `"'                   "888                             8'   888   `8                      .o8    `"'                         
							  `888.   .8888.   .8'   oooo  ooo. .oo.    .oooo888   .ooooo.  oooo oooo    ooo      888       .ooooo.   .oooo.o .o888oo oooo  ooo. .oo.    .oooooooo 
							   `888  .8'`888. .8'    `888  `888P"Y88b  d88' `888  d88' `88b  `88. `88.  .8'       888      d88' `88b d88(  "8   888   `888  `888P"Y88b  888' `88b  
								`888.8'  `888.8'      888   888   888  888   888  888   888   `88..]88..8'        888      888ooo888 `"Y88b.    888    888   888   888  888   888  
								 `888'    `888'       888   888   888  888   888  888   888    `888'`888'         888      888    .o o.  )88b   888 .  888   888   888  `88bod8P'  
								  `8'      `8'       o888o o888o o888o `Y8bod88P" `Y8bod8P'     `8'  `8'         o888o     `Y8bod8P' 8""888P'   "888" o888o o888o o888o `8oooooo.  
																																										d"     YD  
																																										"Y88888P'  


				This file is part of EdenCraft Engine - WindowTesting sample.
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

#include "core/application/application.hpp"
#include "window/common/window.hpp"

#include <iostream>

int main()
{
	ece::Application app;

	std::array<ece::Window, 2> windows;

	ece::WindowSetting settings;
	settings._position = ece::IntVector2u{ 200, 200 };
	int count = 0;
	for (auto & window : windows) {
		settings._title = "WFL window testing" + std::to_string(count);
		settings._position += ece::IntVector2u{ 10, 10 };
		++count;
		window.open();
		window.setSettings(settings);
		window.limitUPS(100);
//		window.enableKeyRepeat(false);
	}

	ece::InputEvent event;
	while (1) {
		for (auto & window : windows) {
			while (window.pollEvent(event)) {
				if (event._doubleTap != ece::InputEvent::DoubleTap::ECE_TAP_NONE) {
					std::cout << "double click !";
				}
				if (event._type == ece::InputEvent::Type::ECE_KEY_PRESSED && event._key >= ece::Keyboard::Key::A && event._key <= ece::Keyboard::Key::Z) {
					std::cout << char(static_cast<int>(event._key) + 34);
				}
				if (event._type == ece::InputEvent::Type::ECE_MOUSE_MOVED) {
					std::cout << event._mousePosition[0] << "|" << event._mousePosition[1] << "  ";
					std::cout << ece::Mouse::getPosition()[0] << "|" << ece::Mouse::getPosition()[1] << std::endl;
				}
			}
		}
	}
//	app.run();

	return 0;
}