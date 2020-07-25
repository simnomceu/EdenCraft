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

#ifndef SUBMESH_HPP
#define SUBMESH_HPP

#include "graphic/config.hpp"
#include "graphic/pch.hpp"
#include "utility/mathematics.hpp"
#include "core/resource.hpp"
#include "renderer/buffer.hpp"

namespace ece
{
	namespace graphic
	{
		namespace model
		{
			/**
			 * @class Submesh
			 * @brief A mesh as defined in 3D modelling.
			 * @remark It has to be refactored soon, as it is redudant with Renderer.
			 */
			class ECE_GRAPHIC_API Submesh
			{
			public:
				using Reference = Resource<Submesh>;

				using Face = std::array<unsigned int, 3>;

				/**
				 * @fn Submesh() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				Submesh() noexcept = default;

				/**
				 * @fn Submesh(const Submesh & copy)
				 * @param[in] copy The Submesh to copy from.
				 * @brief Default copy constructor.
				 * @throw
				 */
				Submesh(const Submesh & copy);

				/**
				 * @fn Submesh(Submesh && move) noexcept
				 * @param[in] move The Submesh to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				Submesh(Submesh && move) noexcept = default;

				/**
				 * @fn ~Submesh() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~Submesh() noexcept = default;

				/**
				 * @fn Submesh & operator=(const Submesh & copy)
				 * @param[in] copy The Submesh to copy from.
				 * @return The Submesh copied.
				 * @brief Default copy assignment operator.
				 * @throw
				 */
				Submesh & operator=(const Submesh & copy);

				/**
				 * @fn Submesh & operator=(Submesh && move) noexcept
				 * @param[in] move The Submesh to move from.
				 * @return The Submesh moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				Submesh & operator=(Submesh && move) noexcept = default;

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
			//	Box3D getBouncingBox() const;

				inline void addFace(const Submesh::Face & face);
				inline void addFace(Submesh::Face && face);

				inline auto getFaces() -> std::vector<Submesh::Face> &;
				inline auto getFaces() const -> const std::vector<Submesh::Face> &;

				inline auto getIndexBuffer() -> IndexBuffer<SymetricStorage, std::vector<Submesh::Face>> &;

				void update();
			private:
                /**
                 * @property _faces
                 * @brief The list of faces using the vertices.
                 */
				IndexBuffer<SymetricStorage, std::vector<Submesh::Face>> _faces;
			};
		} // namespace model
	} // namespace graphic
} // namespace ece

#include "graphic/model/submesh.inl"

#endif // SUBMESH_HPP
