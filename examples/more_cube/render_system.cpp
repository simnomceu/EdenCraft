/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

															ooo        ooooo                                .oooooo.                .o8
															`88.       .888'                               d8P'  `Y8b              "888
															 888b     d'888   .ooooo.  oooo d8b  .ooooo.  888          oooo  oooo   888oooo.   .ooooo.
															 8 Y88. .P  888  d88' `88b `888""8P d88' `88b 888          `888  `888   d88' `88b d88' `88b
															 8  `888'   888  888   888  888     888ooo888 888           888   888   888   888 888ooo888
															 8    Y     888  888   888  888     888    .o `88b    ooo   888   888   888   888 888    .o
															o8o        o888o `Y8bod8P' d888b    `Y8bod8P'  `Y8bood8P'   `V88V"V8P'  `Y8bod8P' `Y8bod8P'



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
#include "graphic_component.hpp"
#include "graphic/renderable.hpp"

RenderSystem::RenderSystem(ece::World & world) noexcept : ece::System(world), _process(std::make_unique<ece::ForwardRendering>()), _scene()
{
	world.onComponentCreated.connect([this](ece::BaseComponent & component) {
	//	bool determined = false;
		try {
			auto & graphicComponent = dynamic_cast<GraphicComponent &>(component);
			this->_scene.addObject(graphicComponent.getRenderable());
	//		determined = true;
		} catch (std::bad_cast &) {/* Not a Graphic Component */}
	});

	ece::RenderState states;
	states._depthTest = true;
	states._depthFunction = ece::RenderState::DepthFunctionCondition::LESS;
	states.apply(true);

	{
		auto light = ece::makeSpotLight(1.0f, 0.8f, 1.0f, { 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, 3.0f }, { 0.0f, 0.0f, -1.0f }, 1.0f, 0.14f, 0.07f, 10.0f, 15.0f);
		this->_scene.addLight(light);
	}

	{
		auto & camera = this->_scene.getCamera();
		camera.setPerspective(45, /*window.getSize()[0] / window.getSize()[1]*/1920.0f / 1080.0f, 0.1, 100.0);
		camera.moveTo(ece::FloatVector3u{ 0.0f, 0.0f, 10.0f });
		camera.lookAt(ece::FloatVector3u{ 0.0f, 0.0f, 0.0f });
	}
	this->_scene.updateCamera();
}

void RenderSystem::update()
{
	/*for (auto object : this->_scene.getObjects()) {
		object->prepare();
		this->_process->pushObject(*object);
	}*/

	ece::Staging staging;
	staging._view = this->_scene.getCamera().getView();
	staging._projection = this->_scene.getCamera().getProjection();
	this->_process->draw(staging);

//	this->_scene.prepare();
	this->_scene.draw();
}

ece::Scene & RenderSystem::getScene()
{
	return this->_scene;
}
