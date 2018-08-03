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

#include "graphic/model/mesh.hpp"

namespace ece
{
	namespace graphic
	{
		namespace model
		{
			Box3D Mesh::getBouncingBox() const
			{
				auto xMin = std::min_element(this->_vertices.begin(), this->_vertices.end(), [](const Vertex &  a, const Vertex & b) { return a._position[0] < b._position[0]; })->_position[0];
				auto xMax = std::max_element(this->_vertices.begin(), this->_vertices.end(), [](const Vertex &  a, const Vertex & b) { return a._position[0] < b._position[0]; })->_position[0];

				auto yMin = std::min_element(this->_vertices.begin(), this->_vertices.end(), [](const Vertex &  a, const Vertex & b) { return a._position[1] < b._position[1]; })->_position[1];
				auto yMax = std::max_element(this->_vertices.begin(), this->_vertices.end(), [](const Vertex &  a, const Vertex & b) { return a._position[1] < b._position[1]; })->_position[1];

				auto zMin = std::min_element(this->_vertices.begin(), this->_vertices.end(), [](const Vertex &  a, const Vertex & b) { return a._position[2] < b._position[2]; })->_position[2];
				auto zMax = std::max_element(this->_vertices.begin(), this->_vertices.end(), [](const Vertex &  a, const Vertex & b) { return a._position[2] < b._position[2]; })->_position[2];

				return Box3D(FloatVector3u{ xMin, yMin, zMin }, FloatVector3u{ xMax, yMax, zMax });
			}

			unsigned int Mesh::addVertex(const Mesh::Vertex & vertex)
			{
				unsigned int index = std::find_if(this->_vertices.begin(), this->_vertices.end(), [vertex](const Mesh::Vertex & lhs) -> bool {
					return vertex._position == lhs._position /*&& vertex._textureCoordinate == lhs._textureCoordinate*/;
				}) - this->_vertices.begin();
				if (index >= this->_vertices.size()) {
					this->_vertices.push_back(vertex);
				}
				else {
					this->_vertices[index]._normal += vertex._normal;
					this->_vertices[index]._normal = this->_vertices[index]._normal.normalize();

					// OBJ uses "normal per face" while common use is "normal per vertex". n = normalize(n1 + n2 + n3) with n1, n2, n3 the face normals for one single vertex, to compute the normal of the vertex.
					// Reverse process: n = normalize(n1 + n2 + n3 + n4) with n1, n2, n3, n4 the normal of the four vertices of a quad, to compute, the normal of the square.
				}
				return index;
			}

			unsigned int Mesh::addVertex(Mesh::Vertex && vertex)
			{
				unsigned int index = std::find_if(this->_vertices.begin(), this->_vertices.end(), [vertex](const Mesh::Vertex & lhs) -> bool {
					return vertex._normal == lhs._position && vertex._textureCoordinate == lhs._textureCoordinate;
				}) - this->_vertices.begin();
				if (index >= this->_vertices.size()) {
					this->_vertices.push_back(vertex);
				}
				else {
					this->_vertices[index]._normal += vertex._normal;
					this->_vertices[index]._normal = this->_vertices[index]._normal.normalize();

					// OBJ uses "normal per face" while common use is "normal per vertex". n = normalize(n1 + n2 + n3) with n1, n2, n3 the face normals for one single vertex, to compute the normal of the vertex.
					// Reverse process: n = normalize(n1 + n2 + n3 + n4) with n1, n2, n3, n4 the normal of the four vertices of a quad, to compute, the normal of the square.
				}
				return index;
			}
		} // namespace model
	} // namespace graphic
} // namespace ece
