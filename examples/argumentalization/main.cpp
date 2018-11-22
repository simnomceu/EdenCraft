/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .   
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8   
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo 
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888   
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888   
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 . 
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888" 

		  .o.                                                                                   .             oooo   o8o                           .    o8o                        
		 .888.                                                                                .o8             `888   `"'                         .o8    `"'                        
		.8"888.     oooo d8b  .oooooooo oooo  oooo  ooo. .oo.  .oo.    .ooooo.  ooo. .oo.   .o888oo  .oooo.    888  oooo    oooooooo  .oooo.   .o888oo oooo   .ooooo.  ooo. .oo.   
	   .8' `888.    `888""8P 888' `88b  `888  `888  `888P"Y88bP"Y88b  d88' `88b `888P"Y88b    888   `P  )88b   888  `888   d'""7d8P  `P  )88b    888   `888  d88' `88b `888P"Y88b  
	  .88ooo8888.    888     888   888   888   888   888   888   888  888ooo888  888   888    888    .oP"888   888   888     .d8P'    .oP"888    888    888  888   888  888   888  
	 .8'     `888.   888     `88bod8P'   888   888   888   888   888  888    .o  888   888    888 . d8(  888   888   888   .d8P'  .P d8(  888    888 .  888  888   888  888   888  
	o88o     o8888o d888b    `8oooooo.   `V88V"V8P' o888o o888o o888o `Y8bod8P' o888o o888o   "888" `Y888""8o o888o o888o d8888888P  `Y888""8o   "888" o888o `Y8bod8P' o888o o888o 
							 d"     YD                                                                                                                                             
							 "Y88888P'                                                                                                                                             
                                                                                                                                                                                

				This file is part of EdenCraft Engine - Argumentalization sample.
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
#include "utility/log.hpp"
#include "core/argument.hpp"

int main(int argc, char * argv[])
{
	try {
		std::string name = "";
		int count = 0;

		ece::Application app(argc, argv);

		app.getArgumentAnalyzer().addOption(ece::Option("name",
			std::shared_ptr<ece::OptionValue>(new ece::StringOptionValue()),
			[&name](const std::string & value) {
				name = value;
			}
		));
		app.getArgumentAnalyzer().addOption(ece::Option("c",
			std::shared_ptr<ece::OptionValue>(new ece::IntegerOptionValue()),
			[&count, &name](const std::string & value) {
				count = std::stoi(value);
				for (int i = 0; i < count; ++i) {
					std::cout << "Good morning " << name << "!" << std::endl;
				}
			}
		));

		app.run();
	}
	catch (std::exception & e) {
		ece::ServiceLoggerLocator::getService().logError("Uncaught exception: " + std::string(e.what()));
	}

	return EXIT_SUCCESS;
}