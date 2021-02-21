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
#include "renderer/pipeline/forward_rendering.hpp"

#include "renderer/pipeline/staging.hpp"

namespace ece
{
	namespace renderer
	{
		namespace pipeline
		{
			void ForwardRendering::setPipeline(RenderPipeline pipeline)
			{
				this->_pipeline = std::move(pipeline);
			}

			auto ForwardRendering::getPipeline() -> RenderPipeline &
			{
				return this->_pipeline;
			}

			void ForwardRendering::clear(const Color & color)
			{
				auto target = Renderer::getCurrentTarget().lock();

				auto viewport = this->_pipeline.getViewport().area;
				if (this->_pipeline.getViewport().mode == Viewport::Mode::RATIO) {
					viewport.width *= target->getSize()[0];
					viewport.height *= target->getSize()[1];
				}

				target->bind();
				OpenGL::viewport(static_cast<int>(viewport.x), static_cast<int>(viewport.y), static_cast<int>(viewport.width), static_cast<int>(viewport.height));

				if (this->_pipeline.getScissor() != Scissor()) {
					OpenGL::scissor(static_cast<int>(this->_pipeline.getScissor().x), static_cast<int>(this->_pipeline.getScissor().y), static_cast<int>(this->_pipeline.getScissor().width), static_cast<int>(this->_pipeline.getScissor().height));
					OpenGL::enable(Capability::SCISSOR_TEST);
				}

				if (this->_pipeline.getScissor() == Scissor()) {
					OpenGL::scissor(static_cast<int>(viewport.x), static_cast<int>(viewport.y), static_cast<int>(viewport.width), static_cast<int>(viewport.height));
					OpenGL::enable(Capability::SCISSOR_TEST);
				}

				OpenGL::clearColor(static_cast<float>(color.r) / 255.0f,
					static_cast<float>(color.g) / 255.0f,
					static_cast<float>(color.b) / 255.0f,
					static_cast<float>(color.a) / 100.0f);
				OpenGL::clear(BufferBit::COLOR | BufferBit::STENCIL | BufferBit::DEPTH);
			}

			void ForwardRendering::draw(const Staging & staging)
			{
				// sort queues

				auto program = this->_pipeline.getProgram();
				OpenGL::uniform<float, 4, 4>(glGetUniformLocation(program->getHandle(), "view"), false, staging._view);
				OpenGL::uniform<float, 4, 4>(glGetUniformLocation(program->getHandle(), "projection"), false, staging._projection);

				std::for_each(this->_objects.begin(), this->_objects.end(), [this, &staging](auto & object) {
					this->drawObject(object, staging);
				});

				std::for_each(this->_sprites.begin(), this->_sprites.end(), [this, &staging](auto & sprite) {
					this->drawSprite(sprite, staging);
				});

				this->_objects.clear();
				this->_sprites.clear();
			}

			void ForwardRendering::pushObject(const std::shared_ptr<Drawable> & drawable)
			{
				this->_objects.add(drawable);
			}

			void ForwardRendering::pushSprite(const std::shared_ptr<Drawable> & drawable)
			{
				this->_sprites.add(drawable);
			}

			void ForwardRendering::drawObject(const std::shared_ptr<Drawable> & drawable, const Staging & /*staging*/)
			{
				this->_pipeline.setState(drawable->getState());
				this->_pipeline.apply();

				OpenGL::uniform<float, 4, 4>(glGetUniformLocation(this->_pipeline.getProgram()->getHandle(), "model"), true, drawable->getModel());

				drawable->draw(this->_pipeline.getProgram());
			}

			void ForwardRendering::drawSprite(const std::shared_ptr<Drawable> & drawable, const Staging & /*staging*/)
			{
				this->_pipeline.setState(drawable->getState());
				this->_pipeline.apply();

				drawable->draw(this->_pipeline.getProgram());
			}
		}
	}
}