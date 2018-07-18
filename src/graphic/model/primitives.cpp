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

#include "graphic/model/primitives.hpp"

#include "utility/mathematics/transform.hpp"
#include "utility/mathematics/vector4u.hpp"

namespace ece
{
	namespace graphic
	{
		namespace model
		{
			using utility::mathematics::rotate;
			using utility::mathematics::FloatVector4u;

			Mesh makeCircle(const float radius, const size_t numberOfVertices)
			{
				Mesh mesh;

				const float angle = 2.0f * static_cast<float>(PI) / static_cast<float>(numberOfVertices);
				const auto rotation = rotate({ 0.0f, 0.0f, 1.0f }, -angle);

				mesh.addVertex({ { 0.0f, 0.0f, 0.0f },{ 1.0f, 1.0f, 1.0f },{ 0.0f, 0.0f, 1.0f },{ 0.0f, 0.0f } });
				Mesh::Vertex vertex = { { radius, 0.0f, 0.0f },{ 1.0f, 1.0f, 1.0f },{ 0.0f, 0.0f, 1.0f },{ 0.0f, 0.0f } };
				mesh.addVertex(vertex);

				for (size_t i = 1; i < numberOfVertices; ++i) {
					auto tmpresult = rotation * FloatVector4u{ vertex._position[0], vertex._position[1], vertex._position[2], 1.0f };
					vertex._position = { tmpresult[0], tmpresult[1], tmpresult[2] };
					mesh.addVertex(vertex);
					mesh.addFace({ 0, i - 1, i });
				}

				mesh.addFace({ 0, numberOfVertices - 1, 1 });

				return std::move(mesh);
			}

			Mesh makeSphere(const float /*radius*/, const size_t /*numberOfVertices*/)
			{
				Mesh mesh;

				return std::move(mesh);
			}

			Mesh makeCylinder(const float radius, const float height, const size_t numberOfVertices)
			{
				Mesh mesh;

				const float angle = 2.0f * static_cast<float>(PI) / static_cast<float>(numberOfVertices);
				const auto rotation = rotate({ 0.0f, 0.0f, 1.0f }, -angle);

				mesh.addVertex({ { 0.0f, 0.0f, height / 2.0f },{ 1.0f, 1.0f, 1.0f },{ 0.0f, 0.0f, 1.0f },{ 0.0f, 0.0f } });
				Mesh::Vertex vertex = { { radius, 0.0f, height / 2.0f },{ 1.0f, 1.0f, 1.0f },{ 0.0f, 0.0f, 1.0f },{ 0.0f, 0.0f } };
				mesh.addVertex(vertex);

				for (size_t i = 0; i < numberOfVertices - 1; ++i) {
					auto tmpresult = rotation * FloatVector4u{ vertex._position[0], vertex._position[1], vertex._position[2], 1.0f };
					vertex._position = { tmpresult[0], tmpresult[1], tmpresult[2] };
					mesh.addVertex(vertex);
					mesh.addFace({ 0, i + 1, i + 2 });
				}

				mesh.addFace({ 0, numberOfVertices, 1 });

				mesh.addVertex({ { 0.0f, 0.0f, -height / 2.0f },{ 1.0f, 1.0f, 1.0f },{ 0.0f, 0.0f, 1.0f },{ 0.0f, 0.0f } });
				vertex = { { radius, 0.0f, -height / 2.0f },{ 1.0f, 1.0f, 1.0f },{ 0.0f, 0.0f, 1.0f },{ 0.0f, 0.0f } };
				mesh.addVertex(vertex);

				for (size_t i = 0; i < numberOfVertices - 1; ++i) {
					auto tmpresult = rotation * FloatVector4u{ vertex._position[0], vertex._position[1], vertex._position[2], 1.0f };
					vertex._position = { tmpresult[0], tmpresult[1], tmpresult[2] };
					mesh.addVertex(vertex);
					mesh.addFace({ numberOfVertices + 1, i + numberOfVertices + 2, i + numberOfVertices + 3 });
				}

				mesh.addFace({ numberOfVertices + 1, numberOfVertices + numberOfVertices + 1, numberOfVertices + 2 });

				for (size_t i = 0; i < numberOfVertices - 1; ++i) {
					mesh.addFace({ numberOfVertices + i + 2, i + 2, i + 1 });
					mesh.addFace({ i + 2, numberOfVertices + i + 2, numberOfVertices + i + 3 });
				}
				mesh.addFace({ numberOfVertices + numberOfVertices + 1, 1, numberOfVertices });
				mesh.addFace({ 1, numberOfVertices + numberOfVertices + 1, numberOfVertices + 2 });

				return std::move(mesh);
			}

			Mesh makeTorus(const float /*innerRadius*/, const float /*outerRadius*/, const size_t /*numberOfVertices*/)
			{
				Mesh mesh;

				return std::move(mesh);
			}

			Mesh makeCone(const float /*radius*/, const float /*height*/, const size_t /*numberOfVertices*/)
			{
				Mesh mesh;

				return std::move(mesh);
			}

			Mesh makeQuad(const float size)
			{
				Mesh mesh;

				mesh.addVertex({ { -size / 2.0f, -size/2.0f, 0.0f },{ 1.0f, 1.0f, 1.0f },{ 0.0f, 0.0f, 1.0f },{ 0.0f, 1.0f } });
				mesh.addVertex({ { -size / 2.0f, size / 2.0f, 0.0f },{ 1.0f, 1.0f, 1.0f },{ 0.0f, 0.0f, 1.0f },{ 0.0f, 0.0f } });
				mesh.addVertex({ { size / 2.0f, size / 2.0f, 0.0f },{ 1.0f, 1.0f, 1.0f },{ 0.0f, 0.0f, 1.0f },{ 1.0f, 0.0f } });
				mesh.addVertex({ { size / 2.0f, -size / 2.0f, 0.0f },{ 1.0f, 1.0f, 1.0f },{ 0.0f, 0.0f, 1.0f },{ 1.0f, 1.0f } });

				mesh.addFace({ 0, 1, 2 });
				mesh.addFace({ 2, 3, 0 });

				return std::move(mesh);
			}

			Mesh makeCube(const float size)
			{
				Mesh mesh;

				mesh.addVertex({ { -size / 2.0f, -size / 2.0f, -size / 2.0f },{ 1.0f, 1.0f, 1.0f },{ -1.0f, -1.0f, -1.0f },{ 0.0f, 1.0f } });
				mesh.addVertex({ { size / 2.0f, -size / 2.0f, -size / 2.0f },{ 1.0f, 1.0f, 1.0f },{ 1.0f, -1.0f, -1.0f },{ 0.0f, 1.0f } });
				mesh.addVertex({ { size / 2.0f, size / 2.0f, -size / 2.0f },{ 1.0f, 1.0f, 1.0f },{ 1.0f, 1.0f, -1.0f },{ 0.0f, 1.0f } });
				mesh.addVertex({ { -size / 2.0f, size / 2.0f, -size / 2.0f },{ 1.0f, 1.0f, 1.0f },{ -1.0f, 1.0f, -1.0f },{ 0.0f, 1.0f } });
				mesh.addVertex({ { -size / 2.0f, -size / 2.0f, size / 2.0f },{ 1.0f, 1.0f, 1.0f },{- 1.0f, -1.0f, 1.0f },{ 0.0f, 1.0f } });
				mesh.addVertex({ { size / 2.0f, -size / 2.0f, size / 2.0f },{ 1.0f, 1.0f, 1.0f },{ 1.0f, -1.0f, 1.0f },{ 0.0f, 1.0f } });
				mesh.addVertex({ { size / 2.0f, size / 2.0f, size / 2.0f },{ 1.0f, 1.0f, 1.0f },{ 1.0f, 1.0f, 1.0f },{ 0.0f, 1.0f } });
				mesh.addVertex({ { -size / 2.0f, size / 2.0f, size / 2.0f },{ 1.0f, 1.0f, 1.0f },{ -1.0f, 1.0f, 1.0f },{ 0.0f, 1.0f } });

				mesh.addFace({ 0, 2, 1 });
				mesh.addFace({ 0, 3, 2 });
				mesh.addFace({ 1, 2, 6 });
				mesh.addFace({ 6, 5, 1 });
				mesh.addFace({ 4, 5, 6 });
				mesh.addFace({ 6, 7, 4 });
				mesh.addFace({ 2, 3, 6 });
				mesh.addFace({ 6, 3, 7 });
				mesh.addFace({ 0, 7, 3 });
				mesh.addFace({ 0, 4, 7 });
				mesh.addFace({ 0, 1, 5 });
				mesh.addFace({ 0, 5, 4 });

				return std::move(mesh);
			}

		} // namespace model
	} // namespace graphic
} // namespace ece