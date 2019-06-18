/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

															oooooo     oooo  o8o
															 `888.     .8'   `"'
															  `888.   .8'   oooo   .ooooo.  oooo oooo    ooo  .ooooo.  oooo d8b
															   `888. .8'    `888  d88' `88b  `88. `88.  .8'  d88' `88b `888""8P
																`888.8'      888  888ooo888   `88..]88..8'   888ooo888  888
																 `888'       888  888    .o    `888'`888'    888    .o  888
																  `8'       o888o `Y8bod8P'     `8'  `8'     `Y8bod8P' d888b

				This file is part of EdenCraft Engine - Viewer sample.
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

#include "systems/render.hpp"

#include "renderer/pipeline.hpp"
#include "renderer/opengl.hpp"
#include "renderer/shader.hpp"
#include "components/graphic.hpp"
#include "graphic/renderable.hpp"

RenderSystem::RenderSystem(ece::World & world, std::weak_ptr<ece::Window> window) noexcept : ece::System(world), _process(std::make_unique<ece::ForwardRendering>()), _scene()
{
	world.onComponentCreated.connect([this](ece::BaseComponent & component) {
		if (component.is<GraphicComponent>()) {
			auto & graphicComponent = component.to<GraphicComponent>();
			this->_scene.addObject(graphicComponent.getRenderable());
		}
	});

	ece::RenderState states;
	states.depthTest = true;
	states.depthFunction = ece::RenderState::DepthFunctionCondition::LESS;
	states.apply(true);

	{
		auto light = ece::makeSpotLight(0.7f, 0.6f, 1.0f, { 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, 3.0f }, { 0.0f, 0.0f, -1.0f }, 1.0f, 0.07f, 0.017f, 50.0f, 100.0f);
		this->_scene.addLight(light);
	}

	{
		auto & camera = this->_scene.getCamera();
		camera.getProjection().setPerspective(45, static_cast<float>(window.lock()->getSize()[0]) / static_cast<float>(window.lock()->getSize()[1]), 0.1, 100.0);
		camera.moveTo(ece::FloatVector3u{ 0.0f, 0.0f, 10.0f });
		camera.lookAt(ece::FloatVector3u{ 0.0f, 0.0f, 0.0f });
	}
	this->_scene.updateCamera();


	ece::RenderPipeline pipeline;

	{
		ece::ShaderStage fsSource;
		fsSource.loadFromFile(ece::ShaderStage::Type::FRAGMENT, "../../resource/shader/phong.frag");
		ece::ShaderStage vsSource;
		vsSource.loadFromFile(ece::ShaderStage::Type::VERTEX, "../../resource/shader/phong.vert");

		auto program = std::make_shared<ece::EnhancedShader>();
		program->setStage(fsSource);
		program->setStage(vsSource);
		program->link();
		pipeline.setProgram(program);
	}

	{
		ece::Viewport viewport;
		viewport.mode = ece::Viewport::Mode::RATIO;
		viewport.area = { 0.0f, 0.0f, 1.0f, 1.0f };
		pipeline.setViewport(std::move(viewport));
	}

	this->_process->setPipeline(std::move(pipeline));
}

void RenderSystem::update(float /*elapsedTime*/)
{
	auto objects = this->_scene.getObjects();
	for (auto object : objects) {
		this->_process->pushObject(*object);
	}
	auto & pipeline = this->_process->getPipeline();
	auto program = pipeline.getProgram();
	auto lights = this->_scene.getLights();
	program->bind(std::make_shared<ece::Uniform<int>>("numberOfLights", static_cast<int>(lights.size())), "numberOfLights");

	int lightId = 0;
	for (auto & light : lights) {
		auto uniforms = light->getUniforms();
		for (auto & uniform : uniforms) {
			program->bind(uniform, "lights[" + std::to_string(lightId) + "]." + uniform->getName());
		}
		++lightId;
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
