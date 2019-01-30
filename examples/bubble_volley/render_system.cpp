/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

															oooooooooo.               .o8        .o8       oooo            oooooo     oooo           oooo  oooo
															`888'   `Y8b             "888       "888       `888             `888.     .8'            `888  `888
															 888     888 oooo  oooo   888oooo.   888oooo.   888   .ooooo.    `888.   .8'    .ooooo.   888   888   .ooooo.  oooo    ooo
															 888oooo888' `888  `888   d88' `88b  d88' `88b  888  d88' `88b    `888. .8'    d88' `88b  888   888  d88' `88b  `88.  .8'
															 888    `88b  888   888   888   888  888   888  888  888ooo888     `888.8'     888   888  888   888  888ooo888   `88..8'
															 888    .88P  888   888   888   888  888   888  888  888    .o      `888'      888   888  888   888  888    .o    `888'
															o888bood8P'   `V88V"V8P'  `Y8bod8P'  `Y8bod8P' o888o `Y8bod8P'       `8'       `Y8bod8P' o888o o888o `Y8bod8P'     .8'
																																										   .o..P'
																																										   `Y8P'



				This file is part of EdenCraft Engine - MoreCube sample.
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

#include "render_system.hpp"

#include "renderer/pipeline.hpp"
#include "renderer/opengl.hpp"
#include "renderer/shader.hpp"
#include "graphic_component.hpp"
#include "space_component.hpp"
#include "graphic/renderable.hpp"

RenderSystem::RenderSystem(ece::World & world) noexcept : ece::System(world), _process(std::make_unique<ece::ForwardRendering>()), _scene()
{
	world.onComponentCreated.connect([this](ece::BaseComponent & component) {
		if (component.is<GraphicComponent>()) {
			auto & graphicComponent = component.to<GraphicComponent>();
			this->_scene.addObject(graphicComponent.getSprite(), graphicComponent.getLevel());
		}
	});

	ece::RenderState states;
	states.depthTest = false;
	states.blending = true;
	states.sourceBlend = ece::RenderState::BlendingFactor::SRC_ALPHA;
	states.destinationBlend = ece::RenderState::BlendingFactor::ONE_MINUS_SRC_ALPHA;
	states.apply(true);

	{
		auto & camera = this->_scene.getCamera();
		auto targetSize = ece::Renderer::getCurrentTarget().lock()->getSize();
		camera.getProjection().setOrthographic({ 0.0f, 0.0f, static_cast<float>(targetSize[0]), static_cast<float>(targetSize[1]) }, 0.1f, 100.0f);
		camera.moveTo(ece::FloatVector3u{ 0.0f, 0.0f, 10.0f });
		camera.lookAt(ece::FloatVector3u{ 0.0f, 0.0f, 0.0f });
	}
	this->_scene.updateCamera();


	ece::RenderPipeline pipeline;

	{
		ece::ShaderStage fsSource;
		fsSource.loadFromFile(ece::ShaderStage::Type::FRAGMENT, "../../resource/shader/sprite.frag");
		ece::ShaderStage vsSource;
		vsSource.loadFromFile(ece::ShaderStage::Type::VERTEX, "../../resource/shader/sprite.vert");

		auto program = std::make_shared<ece::EnhancedShader>();
		program->setStage(fsSource);
		program->setStage(vsSource);
		program->link();
		pipeline.setProgram(program);
	}

	{
		ece::Viewport viewport;
		viewport.area = { 0.0f, 0.0f, 1.0f, 1.0f };
		viewport.mode = ece::Viewport::Mode::RATIO;
		pipeline.setViewport(std::move(viewport));
	}

	this->_process->setPipeline(std::move(pipeline));
}

void RenderSystem::update()
{
	
	for (auto & node : *this->_world.getTank<SpaceComponent>()) {
		auto entity = node.getOwner();
		if (this->_world.hasComponent<GraphicComponent>(entity)) {
			auto sprite = this->_world.getComponent<GraphicComponent>(entity).getSprite();
			sprite->moveTo(node.position);
		}
	}

	this->_scene.sortObjects();
	auto objects = this->_scene.getObjects();
	for (auto object : objects) {
		this->_process->pushSprite(*object);
	}

	ece::Staging staging;
	staging._view = this->_scene.getCamera().getView();
	staging._projection = this->_scene.getCamera().getProjection().getMatrix();

	this->_process->clear(ece::BLACK);
	this->_process->draw(staging);
}

ece::Scene & RenderSystem::getScene()
{
	return this->_scene;
}
