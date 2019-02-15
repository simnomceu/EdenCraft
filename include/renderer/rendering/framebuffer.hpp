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

#ifndef FRAMEBUFFER_HPP
#define FRAMEBUFFER_HPP

#include "renderer/rendering/render_target.hpp"
#include "renderer/rendering/framebuffer_attachment.hpp"

namespace ece
{
	namespace renderer
	{
		namespace rendering
		{
			class Framebuffer
			{
			public:
				enum class BufferBit : unsigned short int;

				enum class Target : unsigned short int
				{
					DRAW,
					READ,
					DRAW_AND_READ
				};

				enum class InterpolationFilter : unsigned short int
				{
					NEAREST = 0,
					LINEAR = 1
				};

				Framebuffer() noexcept;

				Framebuffer(const Framebuffer & copy) = delete;
				Framebuffer(Framebuffer && move) = default;

				~Framebuffer() noexcept;

				Framebuffer & operator=(const Framebuffer & copy) noexcept = delete;
				Framebuffer & operator=(Framebuffer && move) noexcept = default;

				void bind(Target target = Target::DRAW_AND_READ);

				void attach(FramebufferAttachment attachment);

				auto checkStatus(Target target = Target::DRAW_AND_READ) -> bool;

				void blit(Rectangle<float> area, Framebuffer & dst, Rectangle<float> dstArea, Framebuffer::BufferBit mask, InterpolationFilter filter);

			private:
				Handle _handle;
			};

			EnumFlagsT(unsigned short int, Framebuffer::BufferBit)
			{
				COLOR = 0b001,
				DEPTH = 0b010,
				STENCIL = 0b100
			};
		} // namespace rendering
	} // namespace renderer
} // namespace ece

#endif // FRAMEBUFFER_HPP