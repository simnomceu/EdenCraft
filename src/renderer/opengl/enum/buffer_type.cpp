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
#include "renderer/opengl/enum/buffer_type.hpp"

namespace ece
{
	namespace renderer
	{
		namespace opengl
		{
			BufferType getBufferType(BaseBuffer::Type type)
			{
				switch (type) {
				case BaseBuffer::Type::ARRAY: return BufferType::ARRAY_BUFFER; break;
				case BaseBuffer::Type::ATOMIC_COUNTER: return BufferType::ATOMIC_COUNTER_BUFFER; break;
				case BaseBuffer::Type::COPY_READ: return BufferType::COPY_READ_BUFFER; break;
				case BaseBuffer::Type::COPY_WRITE: return BufferType::COPY_WRITE_BUFFER; break;
				case BaseBuffer::Type::DISPATCH_INDIRECT: return BufferType::DISPATCH_INDIRECT_BUFFER; break;
				case BaseBuffer::Type::DRAW_INDIRECT: return BufferType::DRAW_INDIRECT_BUFFER; break;
				case BaseBuffer::Type::ELEMENT_ARRAY: return BufferType::ELEMENT_ARRAY_BUFFER; break;
				case BaseBuffer::Type::PIXEL_PACK: return BufferType::PIXEL_PACK_BUFFER; break;
				case BaseBuffer::Type::PIXEL_UNPACK: return BufferType::PIXEL_UNPACK_BUFFER; break;
				case BaseBuffer::Type::QUERY: return BufferType::QUERY_BUFFER; break;
				case BaseBuffer::Type::SHADER_STORAGE: return BufferType::SHADER_STORAGE_BUFFER; break;
				case BaseBuffer::Type::TEXTURE: return BufferType::TEXTURE_BUFFER; break;
				case BaseBuffer::Type::TRANSFORM_FEEDBACK: return BufferType::TRANSFORM_FEEDBACK_BUFFER; break;
				case BaseBuffer::Type::UNIFORM: return BufferType::UNIFORM_BUFFER; break;
				default: throw std::runtime_error("Unknown value for BufferType enumeration."); break;
				}
			}

			BaseBuffer::Type getBufferType(BufferType type)
			{
				switch (type) {
				case BufferType::ARRAY_BUFFER: return BaseBuffer::Type::ARRAY; break;
				case BufferType::ATOMIC_COUNTER_BUFFER: return BaseBuffer::Type::ATOMIC_COUNTER; break;
				case BufferType::COPY_READ_BUFFER: return BaseBuffer::Type::COPY_READ; break;
				case BufferType::COPY_WRITE_BUFFER: return BaseBuffer::Type::COPY_WRITE; break;
				case BufferType::DISPATCH_INDIRECT_BUFFER: return BaseBuffer::Type::DISPATCH_INDIRECT; break;
				case BufferType::DRAW_INDIRECT_BUFFER: return BaseBuffer::Type::DRAW_INDIRECT; break;
				case BufferType::ELEMENT_ARRAY_BUFFER: return BaseBuffer::Type::ELEMENT_ARRAY; break;
				case BufferType::PIXEL_PACK_BUFFER: return BaseBuffer::Type::PIXEL_PACK; break;
				case BufferType::PIXEL_UNPACK_BUFFER: return BaseBuffer::Type::PIXEL_UNPACK; break;
				case BufferType::QUERY_BUFFER: return BaseBuffer::Type::QUERY; break;
				case BufferType::SHADER_STORAGE_BUFFER: return BaseBuffer::Type::SHADER_STORAGE; break;
				case BufferType::TEXTURE_BUFFER: return BaseBuffer::Type::TEXTURE; break;
				case BufferType::TRANSFORM_FEEDBACK_BUFFER: return BaseBuffer::Type::TRANSFORM_FEEDBACK; break;
				case BufferType::UNIFORM_BUFFER: return BaseBuffer::Type::UNIFORM; break;
				default: throw std::runtime_error("Unknown value for BaseBuffer::Type enumeration."); break;
				}
			}

			std::string to_string(BufferType type)
			{
				switch (type) {
				case BufferType::ARRAY_BUFFER: return "GL_ARRAY_BUFFER"; break;
				case BufferType::ATOMIC_COUNTER_BUFFER: return "GL_ATOMIC_COUNTER_BUFFER"; break;
				case BufferType::COPY_READ_BUFFER: return "GL_COPY_READ_BUFFER"; break;
				case BufferType::COPY_WRITE_BUFFER: return "GL_COPY_WRITE_BUFFER"; break;
				case BufferType::DISPATCH_INDIRECT_BUFFER: return "GL_DISPATCH_INDIRECT_BUFFER"; break;
				case BufferType::DRAW_INDIRECT_BUFFER: return "GL_DRAW_INDIRECT_BUFFER"; break;
				case BufferType::ELEMENT_ARRAY_BUFFER: return "GL_ELEMENT_ARRAY_BUFFER"; break;
				case BufferType::PIXEL_PACK_BUFFER: return "GL_PIXEL_PACK_BUFFER"; break;
				case BufferType::PIXEL_UNPACK_BUFFER: return "GL_PIXEL_UNPACK_BUFFER"; break;
				case BufferType::QUERY_BUFFER: return "GL_QUERY_BUFFER"; break;
				case BufferType::SHADER_STORAGE_BUFFER: return "GL_SHADER_STORAGE_BUFFER"; break;
				case BufferType::TEXTURE_BUFFER: return "GL_TEXTURE_BUFFER"; break;
				case BufferType::TRANSFORM_FEEDBACK_BUFFER: return "GL_TRANSFORM_FEEDBACK_BUFFER"; break;
				case BufferType::UNIFORM_BUFFER: return "GL_UNIFORM_BUFFER"; break;
				default: throw std::runtime_error("Unknown value for BufferType enumeration."); break;
				}
			}
		} // namespace opengl
	} // namespace renderer
} // namespace ece