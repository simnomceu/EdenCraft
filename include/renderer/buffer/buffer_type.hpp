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

#ifndef BUFFER_TYPE_HPP
#define BUFFER_TYPE_HPP

#include "renderer/config.hpp"
#include "GL/glcorearb.h"

namespace ece
{
	namespace renderer
	{
		namespace buffer
		{
			enum class BufferType : unsigned short int
			{
				ARRAY_BUFFER = GL_ARRAY_BUFFER,
				ATOMIC_COUNTER_BUFFER = GL_ATOMIC_COUNTER_BUFFER,
				COPY_READ_BUFFER = GL_COPY_READ_BUFFER,
				COPY_WRITE_BUFFER = GL_COPY_WRITE_BUFFER,
				DISPATCH_INDIRECT_BUFFER = GL_DISPATCH_INDIRECT_BUFFER,
				DRAW_INDIRECT_BUFFER = GL_DRAW_INDIRECT_BUFFER,
				ELEMENT_ARRAY_BUFFER = GL_ELEMENT_ARRAY_BUFFER,
				PIXEL_PACK_BUFFER = GL_PIXEL_PACK_BUFFER,
				PIXEL_UNPACK_BUFFER = GL_PIXEL_UNPACK_BUFFER,
				QUERY_BUFFER = GL_QUERY_BUFFER,
				SHADER_STORAGE_BUFFER = GL_SHADER_STORAGE_BUFFER,
				TEXTURE_BUFFER = GL_TEXTURE_BUFFER,
				TRANSFORM_FEEDBACK_BUFFER = GL_TRANSFORM_FEEDBACK,
				UNIFORM_BUFFER = GL_UNIFORM_BUFFER
			};
		} // namespace buffer
	} // namespace renderer
} // namespace ece

#endif // BUFFER_TYPE_HPP