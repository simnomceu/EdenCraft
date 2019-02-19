/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

															ooooooooo.                               .o8
															`888   `Y88.                            "888
															 888   .d88'  .ooooo.  ooo. .oo.    .oooo888   .ooooo.  oooo d8b  .ooooo.  oooo d8b
															 888ooo88P'  d88' `88b `888P"Y88b  d88' `888  d88' `88b `888""8P d88' `88b `888""8P
															 888`88b.    888ooo888  888   888  888   888  888ooo888  888     888ooo888  888
															 888  `88b.  888    .o  888   888  888   888  888    .o  888     888    .o  888
															o888o  o888o `Y8bod8P' o888o o888o `Y8bod88P" `Y8bod8P' d888b    `Y8bod8P' d888b



				This file is part of EdenCraft Engine - Renderer module.
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

#include "renderer/pch.hpp"
#include "renderer/opengl/enum/pixel_format.hpp"

namespace ece
{
	namespace renderer
	{
		namespace opengl
		{
			PixelFormat getPixelFormat(image::PixelFormat format)
			{
				switch (format) {
				case image::PixelFormat::RED: return PixelFormat::RED; break;
				case image::PixelFormat::RG: return PixelFormat::RG; break;
				case image::PixelFormat::RGB: return PixelFormat::RGB; break;
				case image::PixelFormat::BGR: return PixelFormat::BGR; break;
				case image::PixelFormat::RGBA: return PixelFormat::RGBA; break;
				case image::PixelFormat::BGRA: return PixelFormat::BGRA; break;
				case image::PixelFormat::RED_INTEGER: return PixelFormat::RED_INTEGER; break;
				case image::PixelFormat::RG_INTEGER: return PixelFormat::RG_INTEGER; break;
				case image::PixelFormat::RGB_INTEGER: return PixelFormat::RGB_INTEGER; break;
				case image::PixelFormat::BGR_INTEGER: return PixelFormat::BGR_INTEGER; break;
				case image::PixelFormat::RGBA_INTEGER: return PixelFormat::RGBA_INTEGER; break;
				case image::PixelFormat::BGRA_INTEGER: return PixelFormat::BGRA_INTEGER; break;
				case image::PixelFormat::STENCIL_INDEX: return PixelFormat::STENCIL_INDEX; break;
				case image::PixelFormat::DEPTH_COMPONENT: return PixelFormat::DEPTH_COMPONENT; break;
				case image::PixelFormat::DEPTH_STENCIL: return PixelFormat::DEPTH_STENCIL; break;
				default: throw std::runtime_error("Unknown value for FrontFaceMode enumeration."); break;
				}
			}

			std::string to_string(PixelFormat format)
			{
				switch (format) {
				case PixelFormat::RED: return "RED"; break;
				case PixelFormat::RG: return "RG"; break;
				case PixelFormat::RGB: return "RGB"; break;
				case PixelFormat::BGR: return "BGR"; break;
				case PixelFormat::RGBA: return "RGBA"; break;
				case PixelFormat::BGRA: return "BGRA"; break;
				case PixelFormat::RED_INTEGER: return "RED_INTEGER"; break;
				case PixelFormat::RG_INTEGER: return "RG_INTEGER"; break;
				case PixelFormat::RGB_INTEGER: return "RGB_INTEGER"; break;
				case PixelFormat::BGR_INTEGER: return "BGR_INTEGER"; break;
				case PixelFormat::RGBA_INTEGER: return "RGBA_INTEGER"; break;
				case PixelFormat::BGRA_INTEGER: return "BGRA_INTEGER"; break;
				case PixelFormat::STENCIL_INDEX: return "STENCIL_INDEX"; break;
				case PixelFormat::DEPTH_COMPONENT: return "DEPTH_COMPONENT"; break;
				case PixelFormat::DEPTH_STENCIL: return "DEPTH_STENCIL"; break;
				default: throw std::runtime_error("Unknown value for FrontFaceMode enumeration."); break;
				}
			}
		} // namespace opengl
	} // namespace renderer
} // namespace ece