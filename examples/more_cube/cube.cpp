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

#include "cube.hpp"

#include "components/graphic.hpp"
#include "gui/imgui.hpp"
#include "imgui.h"

Cube::Cube(ece::World& world, const std::size_t chunkSize) : _handle(world.createEntity()), _speed(1.0f), _pos(), _lastPos(), _chunkSize((int)chunkSize), _lastChunkSize((int)chunkSize), _object()
{
	this->_object = ece::makeResource<ece::Object>("cube");

	{
		auto loader = ece::ResourceLoader();
		auto mesh = loader.loadFromFile("../../examples/more_cube/assets/cube.obj")[0].get<ece::Mesh>();
		this->_object->setMesh(mesh);
	}

	for (std::size_t i = 0; i < this->_chunkSize; ++i) {
		for (std::size_t j = 0; j < this->_chunkSize; ++j) {
			for (std::size_t k = 0; k < this->_chunkSize; ++k) {
				this->_object->addInstance(ece::translate(ece::FloatVector3u{ (this->_chunkSize / -2) + i * 1.5f, -(this->_chunkSize / -2) + j * 1.5f, (this->_chunkSize / -2) + k * 1.5f }));
			}
		}
	}

	this->_object->prepare();

	this->_handle.addComponent<Graphic>(this->_object);

	this->_handle.addComponent<ece::ImguiComponent>([this]() {
		ImGui::Begin("Cubes");
		ImGui::SliderFloat("Speed", &this->_speed, 0.1f, 10.0f);
		ImGui::SliderFloat3("Position", this->_pos.data().data(), -50.0f, 50.0f);
		ImGui::SliderInt("Number", &this->_chunkSize, 1, 50);
		ImGui::End();
	});
}

void Cube::update()
{
	if (this->_chunkSize != this->_lastChunkSize) {
		this->_object->clearInstances();
		for (std::size_t i = 0; i < this->_chunkSize; ++i) {
			for (std::size_t j = 0; j < this->_chunkSize; ++j) {
				for (std::size_t k = 0; k < this->_chunkSize; ++k) {
					this->_object->addInstance(ece::translate(ece::FloatVector3u{ (this->_chunkSize / -2) + i * 1.5f, -(this->_chunkSize / -2) + j * 1.5f, (this->_chunkSize / -2) + k * 1.5f }));
				}
			}
		}
		this->_lastChunkSize = this->_chunkSize;
	}

	this->_object->applyTransformation(ece::rotate(ece::FloatVector3u{ 0.0f, 1.0f, 1.0f }, 0.005f * this->_speed));
	this->_object->applyTransformation(ece::translate(this->_lastPos - this->_pos));
	this->_lastPos = this->_pos;
}
