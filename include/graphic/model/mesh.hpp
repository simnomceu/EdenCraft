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

#ifndef MESH_HPP
#define MESH_HPP

#include "graphic/config.hpp"
#include "graphic/model/submesh.hpp"
#include "graphic/material/material.hpp"
#include "utility/mathematics.hpp"
#include "core/resource.hpp"
#include "renderer/buffer.hpp"
#include "utility/hash.hpp"

namespace ece
{
	namespace graphic
	{
		namespace model
		{
			using material::Material;

			/**
			 * @class Mesh
			 * @brief
			 */
			class ECE_GRAPHIC_API Mesh
			{
			public:
				using Reference = Resource<Mesh>;

				struct Vertex
				{
					FloatVector3u _position;
					FloatVector3u _normal;
					FloatVector2u _textureCoordinate;
				};

				struct SubmeshData
				{
					Submesh mesh;
					Material::Reference material;
					FloatMatrix4u model;
				};

				/**
				 * @fn Mesh() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				Mesh() noexcept;

				/**
				 * @fn Mesh(const Mesh & copy) noexcept
				 * @param[in] copy The Mesh to copy from.
				 * @brief Default copy constructor.
				 * @throw noexcept
				 */
				Mesh(const Mesh & copy) noexcept = default;

				/**
				 * @fn Mesh(Mesh && move) noexcept
				 * @param[in] move The Mesh to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				Mesh(Mesh && move) = default;

				/**
				 * @fn ~Mesh() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~Mesh() noexcept = default;

				/**
				 * @fn Mesh & operator=(const Mesh & copy) noexcept
				 * @param[in] copy The Mesh to copy from.
				 * @return The Mesh copied.
				 * @brief Default copy assignment operator.
				 * @throw noexcept
				 */
				Mesh & operator=(const Mesh & copy) noexcept = default;

				/**
				 * @fn Mesh & operator=(Mesh && move) noexcept
				 * @param[in] move The Mesh to move.
				 * @return The Mesh moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				Mesh & operator=(Mesh && move) noexcept = default;

				inline void reset();

				/**
				 * @fn std::size_t getNumberOfVertices() const
				 * @return The number of vertices of the mesh.
				 * @brief Get the number of vertices of the mesh.
				 * @throw
				 */
				inline auto size() const -> std::size_t;

				/**
				 * @fn std::size_t getNumberOfFaces() const
				 * @return The number of faces of the mesh.
				 * @brief Get the number of faces of the mesh.
				 * @throw
				 */
				inline auto getNumberOfFaces() const -> std::size_t;

				/**
				 * @fn Box3D getBouncingBox() const
				 * @return The bouncing box of the mesh.
				 * @brief Get the bouncing box of the mesh.
				 * @throw
				 */
				auto getBouncingBox() const;

				inline auto getSubmeshes() -> std::vector<SubmeshData> &;
				inline auto getSubmeshes() const -> const std::vector<SubmeshData> &;

				auto addVertex(const Mesh::Vertex & vertex) -> std::size_t;
				auto addVertex(Mesh::Vertex && vertex) -> std::size_t;
				void insertVertex(std::size_t position, const Mesh::Vertex & vertex);
				void insertVertex(std::size_t position, Mesh::Vertex && vertex);

				inline auto getVertices() -> std::vector<Mesh::Vertex> &;
				inline auto getVertices() const -> const std::vector<Mesh::Vertex> &;

				void update();

				inline auto getVertexBuffer() -> VertexBuffer<SymetricStorage, std::vector<Mesh::Vertex>> &;
				auto getLayout() const -> BufferLayout;

			protected:
				std::vector<SubmeshData> _submeshes;

				/**
				 * @property _vertices
				 * @brief The list of vertices of the mesh.
				 */
				VertexBuffer<SymetricStorage, std::vector<Mesh::Vertex>> _vertices;
			};
		} // namespace model
	} // namespace graphic
} // namespace ece

#include "graphic/model/mesh.inl"

#endif // MESH_HPP
