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
#include "renderer/image/pixel_data.hpp"
#include "renderer/opengl/enum.hpp"

namespace ece
{
	namespace renderer
	{
		namespace rendering
		{
			using image::PixelData;
			using namespace opengl;

			EnumFlagsT(unsigned short int, FramebufferBufferBit)
			{
				COLOR = 0b001,
				DEPTH = 0b010,
				STENCIL = 0b100
			};

			class ECE_RENDERER_API Framebuffer: public RenderTarget
			{
			public:
				struct AttachmentSpecification
				{
					FramebufferTargetTexture target;
					PixelInternalFormat internalFormat;
				};

				struct Specification
				{
					FramebufferTarget target;

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

				virtual void bind() override;
				void unbind();

				void invalidate();
				inline void terminate();

				inline const Specification & getSpecification() const;

				auto checkStatus() -> bool;

				virtual auto getSize() const -> IntVector2u override;

			private:
				Handle _handle;
				Specification _specification;

				std::vector<Texture::Reference> _colors;
				std::optional<Texture::Reference> _depth;
				std::optional<Texture::Reference> _stencil;
				std::optional<Texture::Reference> _depthStencil;
			};
		} // namespace rendering
	} // namespace renderer
} // namespace ece

#include "renderer/rendering/framebuffer.inl"

#endif // FRAMEBUFFER_HPP