/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .   
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8   
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo 
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888   
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888   
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 . 
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888" 

															ooooooooooooo                        .            
															8'   888   `8                      .o8            
																 888       .ooooo.   .oooo.o .o888oo  .oooo.o 
																 888      d88' `88b d88(  "8   888   d88(  "8 
																 888      888ooo888 `"Y88b.    888   `"Y88b.  
																 888      888    .o o.  )88b   888 . o.  )88b 
																o888o     `Y8bod8P' 8""888P'   "888" 8""888P' 
                                                                       
                                          
                                     
				This file is part of EdenCraft Engine - Tests.
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

#define CATCH_CONFIG_RUNNER

#include "catch2/catch.hpp"

int main(int argc, char* argv[])
{
	Catch::Session session;

	int returnCode = session.applyCommandLine(argc, argv);
	if (returnCode != 0) {
		return returnCode;
	}

	// writing to session.configData() or session.Config() here 
	// overrides command line args
	// only do this if you know you need to
	int numFailed = session.run();

	return (numFailed < 0xff ? numFailed : 0xff);
}
