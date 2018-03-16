/*
	
	oooooooooooo       .o8                          .oooooo.                       .o88o.     .   
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8   
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo 
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888   
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888   
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 . 
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888" 

															oooooo   oooooo     oooo  o8o                    .o8                             
															 `888.    `888.     .8'   `"'                   "888                             
															  `888.   .8888.   .8'   oooo  ooo. .oo.    .oooo888   .ooooo.  oooo oooo    ooo 
															   `888  .8'`888. .8'    `888  `888P"Y88b  d88' `888  d88' `88b  `88. `88.  .8'  
																`888.8'  `888.8'      888   888   888  888   888  888   888   `88..]88..8'   
																 `888'    `888'       888   888   888  888   888  888   888    `888'`888'    
																  `8'      `8'       o888o o888o o888o `Y8bod88P" `Y8bod8P'     `8'  `8'    


				This file is part of EdenCraft Engine - Window module.
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

#ifndef WINDOW_ENUM_HPP
#define WINDOW_ENUM_HPP

#include "utility/mathematics/vector3u.hpp"
#include "utility/mathematics/vector4u.hpp"
#include "utility/enum/enum_flags.hpp"

namespace ece
{
	EnumFlagsT(unsigned short int, WindowState)
	{
		NO_OPTIONS = 0b0000,
			VISIBLE = 0b0001,
			FOCUSED = 0b0010,
			ICONIFIED = 0b0100,
			MAXIMIZED = 0b1000
	};

	EnumFlagsT(unsigned short int, WindowTag)
	{
		NO_OPTIONS_BIS = 0b000000,
			FULLSCREEN = 0b000001,
			TOOLBAR = 0b000010,
			RESIZABLE = 0b000100,
			INIT_VISIBLE = 0b001000,
			INIT_FOCUSED = 0b010000,
			INIT_MAXIMIZED = 0b100000
	};

	EnumFlagsT(unsigned short int, WindowUnknownTag)
	{
		AUTO_ICONIFY = 0b0,
			FLOATING = 0b1
	};

	using ColorRGB = ece::IntVector3u;
	using ColorRGBA = ece::IntVector4u;

	enum class ChannelColor : int {
		RED_CHANNEL = 0,
		GREEN_CHANNEL = 1,
		BLUE_CHANNEL = 2,
		ALPHA_CHANNEL = 3
	};
}

#endif // WINDOW_ENUM_HPP