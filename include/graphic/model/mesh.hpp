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

#include <vector>
#include <iostream>

#include "utility/mathematics/vector3u.hpp"
#include "utility/mathematics/box3d.hpp"
#include "graphic/renderable/vertex.hpp"

namespace ece
{
	namespace graphic
	{
		namespace model
		{
			using utility::mathematics::FloatVector3u;
			using utility::mathematics::Box3D;
			using renderable::Vertex;

			/**
			 * @class Mesh
			 * @extends Vertex
			 * @brief A mesh as defined in 3D modelling.
			 * @remark It has to be refactored soon, as it is redudnant with Renderer.
			 */
			class Mesh : public Vertex
			{
			public:
				/**
				 * @fn Mesh() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				Mesh() noexcept = default;

				/**
				 * @fn Mesh(const Mesh & copy)
				 * @param[in] copy The Mesh to copy from.
				 * @brief Default copy constructor.
				 * @throw
				 */
				Mesh(const Mesh & copy) = default;

				/**
				 * @fn Mesh(Mesh && move) noexcept
				 * @param[in] move The Mesh to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				Mesh(Mesh && move) noexcept = default;

				/**
				 * @fn ~Mesh() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~Mesh() noexcept = default;

				/**
				 * @fn Mesh & operator=(const Mesh & copy)
				 * @param[in] copy The Mesh to copy from.
				 * @return The Mesh copied.
				 * @brief Default copy assignment operator.
				 * @throw
				 */
				Mesh & operator=(const Mesh & copy) = default;

				/**
				 * @fn Mesh & operator=(Mesh && move) noexcept
				 * @param[in] move The Mesh to move from.
				 * @return The Mesh moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				Mesh & operator=(Mesh && move) noexcept = default;

				/**
				 * @fn bool loadFromFile(const std::string & filename)
				 * @param[in] filename The name of the file to read.
				 * @return True, if the mesh has been loaded successfully, else false.
				 * @brief Load a mesh from a specific file.
				 * @throw
				 */
				bool loadFromFile(const std::string & filename);

				/**
				 * @fn unsigned int size() const
				 * @return The number of vertices of the mesh.
				 * @brief Get the number of vertices of the mesh.
				 * @throw
				 */
				inline unsigned int size() const;

				/**
				 * @fn Box3D getBouncingBox() const
				 * @return The bouncing box of the mesh.
				 * @brief Get the bouncing box of the mesh.
				 * @throw
				 */
				Box3D getBouncingBox() const;

				/**
				 * @fn std::vector<FloatVector3u> getPositions() const
				 * @return The list of vertices of the mesh.
				 * @brief Get the list of vertices of the mesh.
				 * @throw
				 */
				inline virtual std::vector<FloatVector3u> getPositions() const override;

				/**
				 * @fn std::vector<FloatVector3u> getColors() const
				 * @return The list of vertex colors of the mesh.
				 * @brief Get the list of vertex colors of the mesh.
				 * @throw
				 */
				inline virtual std::vector<FloatVector3u> getColors() const override;

				/**
				 * @fn std::vector<FloatVector3u> getNormals() const
				 * @return The list of vertex normals of the mesh.
				 * @brief Get the list of vertex normals of the mesh.
				 * @throw
				 */
				inline virtual std::vector<FloatVector3u> getNormals() const override;

				/**
				 * @fn std::vector<int> getIndices() const
				 * @return The list of indices of the mesh.
				 * @brief Get the list of indices of the mesh.
				 * @throw
				 */
				inline virtual std::vector<int> getIndices() const override;

			private:
				/**
				 * @property _vertices
				 * @brief The list of vertices of the mesh.
				 */
				std::vector<FloatVector3u> _vertices;

				/**
				 * @property _colors
				 * @brief The list of vertex colors of the mesh.
				 */
				std::vector<FloatVector3u> _colors;
			};
		} // namespace model
	} // namespace graphic
} // namespace ece

#include "graphic/model/mesh.inl"

#endif // MESH_HPP
