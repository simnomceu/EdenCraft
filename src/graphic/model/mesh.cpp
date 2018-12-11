/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

															  .oooooo.                                  oooo         o8o
															 d8P'  `Y8b                                 `888         `"'
															888           oooo d8b  .oooo.   oo.ooooo.   888 .oo.   oooo   .ooooo.
															888           `888""8P `P  )88b   888' `88b  888P"Y88b  `888  d88' `"Y8
															888     ooooo  888      .oP"888   888   888  888   888   888  888
															`88.    .88'   888     d8(  888   888   888  888   888   888  888   .o8
															 `Y8bood8P'   d888b    `Y888""8o  888bod8P' o888o o888o o888o `Y8bod8P'
																							  888
																							 o888o



				This file is part of EdenCraft Engine - Graphic module.
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

#include "graphic/pch.hpp"
#include "graphic/model/mesh.hpp"

namespace ece
{
	namespace graphic
	{
		namespace model
		{
			Mesh::Mesh() noexcept: _submeshes(), _vertices() {}

			Box3D<float> Mesh::getBouncingBox() const
			{
				auto & vertices = this->_vertices.data();

				auto[xMin, xMax] = std::minmax_element(vertices.begin(), vertices.end(), [](const auto & a, const auto & b) { return a._position[0] < b._position[0]; });
				auto[yMin, yMax] = std::minmax_element(vertices.begin(), vertices.end(), [](const auto & a, const auto & b) { return a._position[1] < b._position[1]; });
				auto[zMin, zMax] = std::minmax_element(vertices.begin(), vertices.end(), [](const auto & a, const auto & b) { return a._position[2] < b._position[2]; });

				return Box3D<float>(FloatVector3u{ xMin->_position[0], yMin->_position[1], zMin->_position[2] },
							 FloatVector3u{ xMax->_position[0], yMax->_position[1], zMax->_position[2] });
			}
			std::size_t Mesh::addVertex(const Mesh::Vertex & vertex)
			{
				auto & vertices = this->_vertices.data();
				vertices.push_back(vertex);

				return vertices.size();
			}

			std::size_t Mesh::addVertex(Mesh::Vertex && vertex)
			{
				auto & vertices = this->_vertices.data();
				vertices.push_back(std::move(vertex));

				return vertices.size();
			}

			void Mesh::insertVertex(std::size_t position, const Mesh::Vertex & vertex)
			{
				auto & vertices = this->_vertices.data();
				if (position >= vertices.size()) {
					vertices.push_back(vertex);
				}
				else {
					vertices[position]._normal += vertex._normal;
				}
			}

			void Mesh::insertVertex(std::size_t position, Mesh::Vertex && vertex)
			{
				auto & vertices = this->_vertices.data();
				if (position >= vertices.size()) {
					vertices.push_back(vertex);
				}
				else {
					vertices[position]._normal += vertex._normal;
				}
			}

			void Mesh::update()
			{
				this->_vertices.update();
				for (auto & submesh : this->_submeshes) {
					submesh.mesh.update();
				}
			}

			BufferLayout Mesh::getLayout() const
			{
				BufferLayout layout;
				layout.add<float>(3, false, false, false);
				layout.add<float>(3, false, false, false);
				layout.add<float>(2, false, false, false);

				return std::move(layout);
			}
		} // namespace model
	} // namespace graphic
} // namespace ece
