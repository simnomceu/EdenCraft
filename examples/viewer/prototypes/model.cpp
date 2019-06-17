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

#include "prototypes/model.hpp"

#include "components/graphic.hpp"
#include "core/format.hpp"
#include "graphic/model.hpp"
#include "graphic/material.hpp"

Model::Model(ece::World & world): _handle(world.createEntity())
{
	auto renderable = ece::makeResource<ece::Object>("model");

	{
		auto loader = ece::ServiceFormatLocator::getService().getLoader<ece::LoaderObject>("../../examples/more_cube/assets/cube.obj");
		loader->loadFromFile("../../examples/more_cube/assets/cube.obj");
		renderable->setMesh(loader->getMeshes()[0]);
	}

	renderable->prepare();

	this->_handle.addComponent<GraphicComponent>(renderable);
}

void Model::loadFrom(const std::string & path)
{
	auto renderable = ece::getResource<ece::Object>("model");

	{
		auto loader = ece::ServiceFormatLocator::getService().getLoader<ece::LoaderObject>(path);
		loader->loadFromFile(path);
		renderable->setMesh(loader->getMeshes()[0]);
	}

	renderable->prepare();
}

void Model::update()
{
	auto renderable = this->_handle.getComponent<GraphicComponent>().getRenderable();
	renderable->applyTransformation(ece::rotate(ece::FloatVector3u{ 0.0f, 1.0f, 1.0f }, 0.005f));
}
