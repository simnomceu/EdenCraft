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

#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <memory>

#include "renderer/common/renderable.hpp"
#include "graphic/model/mesh.hpp"

namespace ece
{
	namespace graphic
	{
		namespace renderable
		{
			using renderer::common::Renderable;
			using model::Mesh;
            using utility::mathematics::FloatVector3u;

			/**
			 * @class Object
			 * @extends Renderable
			 * @brief A renderable 3D object.
			 */
			class Object: public Renderable
			{
			public:
				/**
				 * @fn Object() noexcept
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				Object() noexcept;

				/**
				 * @fn Object(const Object & copy)
				 * @param[in] copy The Object to copy from.
				 * @brief Default copy constructor.
				 * @throw
				 */
				Object(const Object & copy) = default;

				/**
				 * @fn Object(Object && move) noexcept
				 * @param[in] move The Object to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				Object(Object && move) noexcept = default;

				/**
				 * @fn ~Object() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~Object() noexcept = default;

				/**
				 * @fn Object & operator=(const Object & copy)
				 * @param[in] copy The Object to copy from.
				 * @return The Object copied.
				 * @brief Default copy assignment operator.
				 * @throw
				 */
				Object & operator=(const Object & copy) = default;

				/**
				 * @fn Object & operator=(Object && move) noexcept
				 * @param[in] move The Object to move from.
				 * @return The Object moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				Object & operator=(Object && move) noexcept = default;

				// NOTE: each element should be build externally from this class, and just "linked" to it when required.

				/**
				 * @fn void setMesh(const std::shared_ptr<Mesh> & mesh)
				 * @param[in] mesh The mesh to use.
				 * @brief Set the mesh of the 3D object.
				 * @throw
				 */
				void setMesh(const std::shared_ptr<Mesh> & mesh);

				// NOTE: accessing one of the elements linked to this object should not modify the object itself
				// but it should also not forbid modification on the elements.

				/**
				 * @fn std::shared_ptr<Mesh> getMesh() const
				 * @return The mesh of the object.
				 * @brief Get the mesh of the object.
				 * @throw
				 */
				inline std::shared_ptr<Mesh> getMesh() const;

                void prepare();

			protected:
				/**
				 * @property _mesh
				 * @brief The mesh of the object.
				 */
				std::shared_ptr<Mesh> _mesh;
			};
		} // namespace renderable
	} // namespace graphic
} // namespace ece

#include "graphic/renderable/object.inl"

#endif // OBJECT_HPP
