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

#include "renderer/config.hpp"
#include "renderer/pch.hpp"
#include "renderer/rendering/render_target.hpp"

namespace ece
{
	namespace renderer
	{
		namespace rendering
		{
			EnumFlagsT(unsigned short int, FramebufferBufferBit)
			{
				COLOR = 0b001,
				DEPTH = 0b010,
				STENCIL = 0b100
			};

			class ECE_RENDERER_API Framebuffer
			{
			public:
				enum class Target : unsigned short int
				{
					DRAW,
					READ,
					FRAMEBUFFER
				};

				enum class TargetTexture : unsigned short int
				{
					TEXTURE_RECTANGLE = 0x00,
					TEXTURE_2D = 0x01,
					TEXTURE_2D_MULTISAMPLE = 0x02,
					TEXTURE_2D_MULTISAMPLE_ARRAY = 0x03,
					TEXTURE_3D = 0x04,
					TEXTURE_CUBE_MAP_POSITIVE_X = 0x05,
					TEXTURE_CUBE_MAP_POSITIVE_Y = 0x06,
					TEXTURE_CUBE_MAP_POSITIVE_Z = 0x07,
					TEXTURE_CUBE_MAP_NEGATIVE_X = 0x08,
					TEXTURE_CUBE_MAP_NEGATIVE_Y = 0x09,
					TEXTURE_CUBE_MAP_NEGATIVE_Z = 0x10
				};

				enum class InterpolationFilter : unsigned short int
				{
					NEAREST = 0,
					LINEAR = 1
				};

				enum class AttachmentChannel : unsigned short int
				{
					COLOR0 = 0,
					COLOR1 = 1,
					COLOR2 = 2,
					COLOR3 = 3,
					COLOR4 = 4,
					COLOR5 = 5,
					COLOR6 = 6,
					COLOR7 = 7,
					COLOR8 = 8,
					COLOR9 = 9,
					COLOR10 = 10,
					COLOR11 = 11,
					COLOR12 = 12,
					COLOR13 = 13,
					COLOR14 = 14,
					COLOR15 = 15,
					COLOR16 = 16,
					COLOR17 = 17,
					COLOR18 = 18,
					COLOR19 = 19,
					COLOR20 = 20,
					COLOR21 = 21,
					COLOR22 = 22,
					COLOR23 = 23,
					COLOR24 = 24,
					COLOR25 = 25,
					COLOR26 = 26,
					COLOR27 = 27,
					COLOR28 = 28,
					COLOR29 = 29,
					COLOR30 = 30,
					COLOR31 = 31,
					DEPTH = 32,
					STENCIL = 33,
					DEPTH_STENCIL = 34
				};

				inline friend AttachmentChannel operator+(const AttachmentChannel & left, unsigned short int shift)
				{
					return static_cast<AttachmentChannel>(static_cast<unsigned short int>(left) + shift);
				}

				struct AttachmentSpecification
				{
					Texture::Reference texture;
					TargetTexture target;

				};

				struct Specification
				{
					Target target;

					ece::size_t width;
					ece::size_t height;
					ece::size_t samples;

					std::vector<AttachmentSpecification> colors;
					std::optional<AttachmentSpecification> depth;
					std::optional<AttachmentSpecification> stencil;
					std::optional<AttachmentSpecification> depthStencil;
				};

				Framebuffer(const Specification & specification) noexcept;

				Framebuffer(const Framebuffer & copy) = delete;
				Framebuffer(Framebuffer && move) = default;

				~Framebuffer() noexcept;

				Framebuffer & operator=(const Framebuffer & copy) noexcept = delete;
				Framebuffer & operator=(Framebuffer && move) noexcept = default;

				void bind();
				void unbind();

				void invalidate();
				inline void terminate();

				inline const Specification & getSpecification() const;

				auto checkStatus() -> bool;

			private:
				Handle _handle;
				Specification _specification;
			};
		} // namespace rendering
	} // namespace renderer
} // namespace ece

#include "renderer/rendering/framebuffer.inl"

#endif // FRAMEBUFFER_HPP