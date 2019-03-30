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
#include "graphic/model/primitives.hpp"

#include "utility/mathematics.hpp"

namespace ece
{
	namespace graphic
	{
		namespace model
		{
			auto makeCircle(const float radius, const size_t numberOfVertices)
			{
				auto result = Mesh();
				result.getSubmeshes().resize(1);
				auto & mesh = result.getSubmeshes()[0].mesh;

				const auto angle = 2.0f * static_cast<float>(PI) / static_cast<float>(numberOfVertices);
				const auto rotation = rotate({ 0.0f, 0.0f, 1.0f }, -angle);

				result.addVertex({ { 0.0f, 0.0f, 0.0f },{ 0.0f, 0.0f, 1.0f },{ 0.0f, 0.0f } });
				auto vertex = Mesh::Vertex{ { radius, 0.0f, 0.0f },{ 0.0f, 0.0f, 1.0f },{ 0.0f, 0.0f } };
				result.addVertex(vertex);

				for (auto i = size_t{ 1 }; i < numberOfVertices; ++i) {
					auto tmpresult = rotation * FloatVector4u{ vertex._position[0], vertex._position[1], vertex._position[2], 1.0f };
					vertex._position = { tmpresult[0], tmpresult[1], tmpresult[2] };
					result.addVertex(vertex);
					mesh.addFace({ 0, static_cast<unsigned int>(i - 1), static_cast<unsigned int>(i) });
				}

				mesh.addFace({ 0, static_cast<unsigned int>(numberOfVertices - 1), 1 });

				return std::move(result);
			}

			auto makeSphere(const float radius, const size_t numberOfVertices)
			{
				auto result = Mesh();
				result.getSubmeshes().resize(1);
				auto & mesh = result.getSubmeshes()[0].mesh;

				result.addVertex({ { 0.0f, 1.0f, 0.0f },{ 0.0f, 1.0f, 0.0f },{ 0.0f, 0.0f } });

				for (auto i = size_t{ 0 }; i < numberOfVertices - 1; ++i) {
					const auto polar = static_cast<float>(PI) * (i + 1) / numberOfVertices;
					const auto sp = std::sin(polar);
					const auto cp = std::cos(polar);
					for (auto j = size_t{ 0 }; j < numberOfVertices; ++j) {
						const auto azimuth = 2.0f * static_cast<float>(PI) * j / numberOfVertices;
						const auto sa = std::sin(azimuth);
						const auto ca = std::cos(azimuth);
						const auto x = sp * ca;
						const auto y = cp;
						const auto z = sp * sa;
						result.addVertex({ { x * radius, y * radius, z * radius },{ x, y, z },{ 0.0f, 0.0f } });
					}
				}
				result.addVertex({ { 0.0f, -1.0f, 0.0f },{ 0.0f, -1.0f, 0.0f },{ 0.0f, 0.0f } });

				for (auto i = std::size_t{ 0 }; i < numberOfVertices; ++i) {
					const auto a = i + 1;
					const auto b = (i + 1) % numberOfVertices + 1;
					mesh.addFace({ 0, static_cast<unsigned int>(b), static_cast<unsigned int>(a) });
				}

				for (auto i = std::size_t{ 0 }; i < numberOfVertices - 2; ++i) {
					const auto aStart = i * numberOfVertices + 1;
					const auto bStart = (i + 1) * numberOfVertices + 1;
					for (auto j = std::size_t{ 0 }; j < numberOfVertices; ++j) {
						const auto a = aStart + j;
						const auto a1 = aStart + (j + 1) % numberOfVertices;
						const auto b = bStart + j;
						const auto b1 = bStart + (j + 1) % numberOfVertices;
						mesh.addFace({ static_cast<unsigned int>(a), static_cast<unsigned int>(a1), static_cast<unsigned int>(b1) });
						mesh.addFace({ static_cast<unsigned int>(a), static_cast<unsigned int>(b1), static_cast<unsigned int>(b) });
					}
				}

				for (auto i = std::size_t{ 0 }; i < numberOfVertices; ++i) {
					const auto a = i + numberOfVertices * (numberOfVertices - 2) + 1;
					const auto b = (i + 1) % numberOfVertices + numberOfVertices * (numberOfVertices - 2) + 1;
					mesh.addFace({ static_cast<unsigned int>(result.getVertices().size() - 1), static_cast<unsigned int>(a), static_cast<unsigned int>(b) });
				}

				return std::move(result);
			}

			auto makeCylinder(const float radius, const float height, const size_t numberOfVertices)
			{
				auto result = Mesh();
				result.getSubmeshes().resize(1);
				auto & mesh = result.getSubmeshes()[0].mesh;

				const auto angle = 2.0f * static_cast<float>(PI) / static_cast<float>(numberOfVertices);
				const auto rotation = rotate({ 0.0f, 0.0f, 1.0f }, -angle);

				result.addVertex({ { 0.0f, 0.0f, height / 2.0f },{ 0.0f, 0.0f, 1.0f },{ 0.0f, 0.0f } });
				auto vertex = Mesh::Vertex{ { radius, 0.0f, height / 2.0f },{ 0.0f, 0.0f, 1.0f },{ 0.0f, 0.0f } };
				result.addVertex(vertex);

				for (auto i = std::size_t{ 0 }; i < numberOfVertices - 1; ++i) {
					auto tmpresult = rotation * FloatVector4u{ vertex._position[0], vertex._position[1], vertex._position[2], 1.0f };
					vertex._position = { tmpresult[0], tmpresult[1], tmpresult[2] };
					result.addVertex(vertex);
					mesh.addFace({ 0, static_cast<unsigned int>(i + 1), static_cast<unsigned int>(i + 2) });
				}

				mesh.addFace({ 0, static_cast<unsigned int>(numberOfVertices), 1 });

				result.addVertex({ { 0.0f, 0.0f, -height / 2.0f },{ 0.0f, 0.0f, 1.0f },{ 0.0f, 0.0f } });
				vertex = { { radius, 0.0f, -height / 2.0f },{ 0.0f, 0.0f, 1.0f },{ 0.0f, 0.0f } };
				result.addVertex(vertex);

				for (auto i = std::size_t{ 0 }; i < numberOfVertices - 1; ++i) {
					auto tmpresult = rotation * FloatVector4u{ vertex._position[0], vertex._position[1], vertex._position[2], 1.0f };
					vertex._position = { tmpresult[0], tmpresult[1], tmpresult[2] };
					result.addVertex(vertex);
					mesh.addFace({ static_cast<unsigned int>(numberOfVertices + 1), static_cast<unsigned int>(i + numberOfVertices + 2), static_cast<unsigned int>(i + numberOfVertices + 3) });
				}

				mesh.addFace({ static_cast<unsigned int>(numberOfVertices + 1), static_cast<unsigned int>(numberOfVertices + numberOfVertices + 1), static_cast<unsigned int>(numberOfVertices + 2) });

				for (auto i = std::size_t{ 0 }; i < numberOfVertices - 1; ++i) {
					mesh.addFace({ static_cast<unsigned int>(numberOfVertices + i + 2), static_cast<unsigned int>(i + 2), static_cast<unsigned int>(i + 1) });
					mesh.addFace({ static_cast<unsigned int>(i + 2), static_cast<unsigned int>(numberOfVertices + i + 2), static_cast<unsigned int>(numberOfVertices + i + 3) });
				}
				mesh.addFace({ static_cast<unsigned int>(numberOfVertices + numberOfVertices + 1), 1, static_cast<unsigned int>(numberOfVertices) });
				mesh.addFace({ 1, static_cast<unsigned int>(numberOfVertices + numberOfVertices + 1), static_cast<unsigned int>(numberOfVertices + 2) });

				return std::move(result);
			}

			auto makeTorus(const float innerRadius, const float outerRadius, const size_t numberOfSlices, const size_t numberOfRings)
			{
				auto result = Mesh();
				result.getSubmeshes().resize(1);
				auto & mesh = result.getSubmeshes()[0].mesh;

				const auto angle = 2.0f * static_cast<float>(PI) / static_cast<float>(numberOfRings);
				const auto ringAngle = 2.0f * static_cast<float>(PI) / static_cast<float>(numberOfSlices);
				const auto rotation = rotate({ 0.0f, 0.0f, 1.0f }, -angle);

				const auto radius = (outerRadius - innerRadius) / 2.0f;
				auto center = FloatVector4u{ (outerRadius + innerRadius) / 2.0f, 0.0f, 0.0f, 1.0f };

				auto startPos = FloatVector4u{ radius, 0.0f, 0.0f, 1.0f };
				auto axis = FloatVector4u{ 0.0f, 1.0f, 0.0f, 1.0f };

				for (auto i = std::size_t{ 0 }; i < numberOfRings; ++i) {
					const auto shift = startPos - center;
					const auto ringRotation = translate({ -shift[0], -shift[1], -shift[2] }) * rotate({ axis[0], axis[1], axis[2] }, -ringAngle) * translate({ shift[0], shift[1], shift[2] });

					auto vertex = Mesh::Vertex{ { startPos[0], startPos[1], startPos[2] }, { startPos[0], startPos[1], startPos[2] }, { 0.0f, 0.0f } };

					for (auto j = std::size_t{ 0 }; j < numberOfSlices; ++j) {
						result.addVertex(vertex);
						if (j < numberOfSlices - 1 && i < numberOfRings - 1) {
							mesh.addFace({ static_cast<unsigned int>((i + 1) * numberOfSlices + j), static_cast<unsigned int>(i * numberOfSlices + j + 1), static_cast<unsigned int>(i * numberOfSlices + j) });
							mesh.addFace({ static_cast<unsigned int>(i * numberOfSlices + j + 1), static_cast<unsigned int>((i + 1) * numberOfSlices + j), static_cast<unsigned int>((i + 1) * numberOfSlices + j + 1) });
						}

						auto tmpresult = ringRotation * FloatVector4u{ vertex._position[0], vertex._position[1], vertex._position[2], 1.0f };
						vertex._position = { tmpresult[0], tmpresult[1], tmpresult[2] };
					}
					if (i < numberOfRings - 1) {
						mesh.addFace({ static_cast<unsigned int>((i + 1) * numberOfSlices + numberOfSlices - 1), static_cast<unsigned int>(i * numberOfSlices), static_cast<unsigned int>(i * numberOfSlices + numberOfSlices - 1) });
						mesh.addFace({ static_cast<unsigned int>(i * numberOfSlices), static_cast<unsigned int>((i + 1) * numberOfSlices + numberOfSlices - 1), static_cast<unsigned int>((i + 1) * numberOfSlices) });
					}

					startPos = rotation * startPos;
					center = rotation * center;
					axis = rotation * axis;
				}

				for (auto j = std::size_t{ 0 }; j < numberOfSlices - 1; ++j) {
					mesh.addFace({ static_cast<unsigned int>((numberOfRings - 1) * numberOfSlices + j), static_cast<unsigned int>(j + 1), static_cast<unsigned int>(j) });
					mesh.addFace({ static_cast<unsigned int>(j + 1), static_cast<unsigned int>((numberOfRings - 1) * numberOfSlices + j), static_cast<unsigned int>((numberOfRings - 1) * numberOfSlices + j + 1) });
				}
				mesh.addFace({ static_cast<unsigned int>(numberOfRings * numberOfSlices - 1), 1, static_cast<unsigned int>(numberOfSlices - 1) });
				mesh.addFace({ 1, static_cast<unsigned int>(numberOfRings * numberOfSlices - 1), static_cast<unsigned int>((numberOfRings - 1) * numberOfSlices) });

				return std::move(result);
			}

			auto makeCone(const float radius, const float height, const size_t numberOfVertices)
			{
				auto result = Mesh();
				result.getSubmeshes().resize(1);
				auto & mesh = result.getSubmeshes()[0].mesh;

				const auto angle = 2.0f * static_cast<float>(PI) / static_cast<float>(numberOfVertices);
				const auto rotation = rotate({ 0.0f, 0.0f, 1.0f }, -angle);

				result.addVertex({ { 0.0f, 0.0f, height / 2.0f },{ 0.0f, 0.0f, 1.0f },{ 0.0f, 0.0f } });
				auto vertex = Mesh::Vertex{ { radius, 0.0f, height / 2.0f },{ 0.0f, 0.0f, 1.0f },{ 0.0f, 0.0f } };
				result.addVertex(vertex);

				for (auto i = std::size_t{ 1 }; i < numberOfVertices; ++i) {
					auto tmpresult = rotation * FloatVector4u{ vertex._position[0], vertex._position[1], vertex._position[2], 1.0f };
					vertex._position = { tmpresult[0], tmpresult[1], tmpresult[2] };
					result.addVertex(vertex);
					mesh.addFace({ 0, static_cast<unsigned int>(i - 1), static_cast<unsigned int>(i) });
				}

				mesh.addFace({ 0, static_cast<unsigned int>(numberOfVertices - 1), 1 });

				result.addVertex({ { 0.0f, 0.0f, height / -2.0f },{ 0.0f, 0.0f, 1.0f },{ 0.0f, 0.0f } });

				for (auto i = std::size_t{ 1 }; i < numberOfVertices; ++i) {
					mesh.addFace({ static_cast<unsigned int>(numberOfVertices + 1), static_cast<unsigned int>(i - 1), static_cast<unsigned int>(i) });
				}

				mesh.addFace({ static_cast<unsigned int>(numberOfVertices + 1), static_cast<unsigned int>(numberOfVertices - 1), 1 });

				return std::move(result);
			}

			auto makeQuad(const float size)
			{
				auto result = Mesh();
				result.getSubmeshes().resize(1);
				auto & mesh = result.getSubmeshes()[0].mesh;

				result.addVertex({ { -size / 2.0f, -size/2.0f, 0.0f },{ 0.0f, 0.0f, 1.0f },{ 0.0f, 1.0f } });
				result.addVertex({ { size / 2.0f, -size / 2.0f, 0.0f },{ 0.0f, 0.0f, 1.0f },{ 1.0f, 0.0f } });
				result.addVertex({ { size / 2.0f, size / 2.0f, 0.0f },{ 0.0f, 0.0f, 1.0f },{ 1.0f, 1.0f } });
				result.addVertex({ { -size / 2.0f, size / 2.0f, 0.0f },{ 0.0f, 0.0f, 1.0f },{ 0.0f, 1.0f } });

				mesh.addFace({ 0, 3, 2 });
				mesh.addFace({ 0, 2, 1 });

				return std::move(result);
			}

			auto makeCube(const float size)
			{
				auto result = Mesh();
				result.getSubmeshes().resize(1);
				auto & mesh = result.getSubmeshes()[0].mesh;

				result.addVertex({ { -size / 2.0f, -size / 2.0f, size / 2.0f },{ -1.0f, -1.0f, 1.0f },{ 0.0f, 0.0f } }); // 0
				result.addVertex({ { size / 2.0f, -size / 2.0f, size / 2.0f },{ 1.0f, -1.0f, 1.0f },{ 1.0f, 0.0f } }); // 1
				result.addVertex({ { size / 2.0f, size / 2.0f, size / 2.0f },{ 1.0f, 1.0f, 1.0f },{ 1.0f, 1.0f } }); // 2
				result.addVertex({ { -size / 2.0f, size / 2.0f, size / 2.0f },{ -1.0f, 1.0f, 1.0f },{ 0.0f, 1.0f } }); // 3

				result.addVertex({ { size / 2.0f, -size / 2.0f, size / 2.0f },{ 1.0f, -1.0f, 1.0f },{ 0.0f, 0.0f } }); // 4
				result.addVertex({ { size / 2.0f, -size / 2.0f, -size / 2.0f },{ 1.0f, -1.0f, -1.0f },{ 1.0f, 0.0f } }); // 5
				result.addVertex({ { size / 2.0f, size / 2.0f, -size / 2.0f },{ 1.0f, 1.0f, -1.0f },{ 1.0f, 1.0f } }); // 6
				result.addVertex({ { size / 2.0f, size / 2.0f, size / 2.0f },{ 1.0f, 1.0f, 1.0f },{ 0.0f, 1.0f } }); // 7

				result.addVertex({ { size / 2.0f, -size / 2.0f, -size / 2.0f },{ 1.0f, -1.0f, -1.0f },{ 0.0f, 0.0f } }); // 8
				result.addVertex({ { -size / 2.0f, -size / 2.0f, -size / 2.0f },{ -1.0f, -1.0f, -1.0f },{ 1.0f, 0.0f } }); // 9
				result.addVertex({ { -size / 2.0f, size / 2.0f, -size / 2.0f },{ -1.0f, 1.0f, -1.0f },{ 1.0f, 1.0f } }); // 10
				result.addVertex({ { size / 2.0f, size / 2.0f, -size / 2.0f },{ 1.0f, 1.0f, -1.0f },{ 0.0f, 1.0f } }); // 11

				result.addVertex({ { -size / 2.0f, -size / 2.0f, -size / 2.0f },{ -1.0f, -1.0f, -1.0f },{ 0.0f, 0.0f } }); // 12
				result.addVertex({ { -size / 2.0f, -size / 2.0f, size / 2.0f },{ -1.0f, -1.0f, 1.0f },{ 1.0f, 0.0f } }); // 13
				result.addVertex({ { -size / 2.0f, size / 2.0f, size / 2.0f },{ -1.0f, 1.0f, 1.0f },{ 1.0f, 1.0f } }); // 14
				result.addVertex({ { -size / 2.0f, size / 2.0f, -size / 2.0f },{ -1.0f, 1.0f, -1.0f },{ 0.0f, 1.0f } }); // 15

				result.addVertex({ { -size / 2.0f, size / 2.0f, size / 2.0f },{ -1.0f, 1.0f, 1.0f },{ 0.0f, 0.0f } }); // 16
				result.addVertex({ { size / 2.0f, size / 2.0f, size / 2.0f },{ 1.0f, 1.0f, 1.0f },{ 1.0f, 0.0f } }); // 17
				result.addVertex({ { size / 2.0f, size / 2.0f, -size / 2.0f },{ 1.0f, 1.0f, -1.0f },{ 1.0f, 1.0f } }); // 18
				result.addVertex({ { -size / 2.0f, size / 2.0f, -size / 2.0f },{ -1.0f, 1.0f, -1.0f },{ 0.0f, 1.0f } }); // 19

				result.addVertex({ { -size / 2.0f, -size / 2.0f, -size / 2.0f },{ -1.0f, -1.0f, -1.0f },{ 0.0f, 0.0f } }); // 20
				result.addVertex({ { size / 2.0f, -size / 2.0f, -size / 2.0f },{ 1.0f, -1.0f, -1.0f },{ 1.0f, 0.0f } }); // 21
				result.addVertex({ { size / 2.0f, -size / 2.0f, size / 2.0f },{ 1.0f, -1.0f, 1.0f },{ 1.0f, 1.0f } }); // 22
				result.addVertex({ { -size / 2.0f, -size / 2.0f, size / 2.0f },{ -1.0f, -1.0f, 1.0f },{ 0.0f, 1.0f } }); // 23

				mesh.addFace({ 0, 3, 2 });
				mesh.addFace({ 0, 2, 1 });

				mesh.addFace({ 4, 7, 6 });
				mesh.addFace({ 4, 6, 5 });

				mesh.addFace({ 8, 11, 10 });
				mesh.addFace({ 8, 10, 9 });

				mesh.addFace({ 12, 15, 14 });
				mesh.addFace({ 12, 14, 13 });

				mesh.addFace({ 16, 19, 18 });
				mesh.addFace({ 16, 18, 17 });

				mesh.addFace({ 20, 23, 22 });
				mesh.addFace({ 20, 22, 21 });

				return std::move(result);
			}

		} // namespace model
	} // namespace graphic
} // namespace ece