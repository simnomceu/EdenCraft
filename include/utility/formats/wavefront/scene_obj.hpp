/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

															ooooo     ooo     .    o8o  oooo   o8o      .
															`888'     `8'   .o8    `"'  `888   `"'    .o8
															 888       8  .o888oo oooo   888  oooo  .o888oo oooo    ooo
															 888       8    888   `888   888  `888    888    `88.  .8'
															 888       8    888    888   888   888    888     `88..8'
															 `88.    .8'    888 .  888   888   888    888 .    `888'
															   `YbodP'      "888" o888o o888o o888o   "888"     .8'
																											.o..P'
																											`Y8P'

				This file is part of EdenCraft Engine - Utility module.
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

#ifndef SCENE_OBJ_HPP
#define SCENE_OBJ_HPP

#include "utility/config.hpp"
#include "utility/pch.hpp"
#include "utility/formats/wavefront/object_obj.hpp"

namespace ece
{
	namespace utility
	{
		namespace formats
		{
			namespace wavefront
			{
				/**
				 * @class SceneOBJ
				 * @brief
				 */
				class ECE_UTILITY_API SceneOBJ
				{
				public:
					/**
					 * @fn constexpr SceneOBJ() noexcept
					 * @brief Default constructor.
					 * @throw noexcept
					 */
					SceneOBJ() = default;

					/**
					 * @fn SceneOBJ(const SceneOBJ & copy) noexcept
					 * @param[in] copy The SceneOBJ to copy from.
					 * @brief Default copy constructor.
					 * @throw noexcept
					 */
					SceneOBJ(const SceneOBJ & copy) noexcept = default;

					/**
					 * @fn SceneOBJ(SceneOBJ && move) noexcept
					 * @param[in] move The SceneOBJ to move.
					 * @brief Default move constructor.
					 * @throw noexcept
					 */
					SceneOBJ(SceneOBJ && move) noexcept = default;

					/**
					 * @fn ~SceneOBJ() noexcept
					 * @brief Default destructor.
					 * @throw noexcept
					 */
					~SceneOBJ() noexcept = default;

					/**
					 * @fn SceneOBJ & operator=(const SceneOBJ & copy) noexcept
					 * @param[in] copy The SceneOBJ to copy from.
					 * @return The SceneOBJ copied.
					 * @brief Default copy assignment operator.
					 * @throw noexcept
					 */
					SceneOBJ & operator=(const SceneOBJ & copy) noexcept = default;

					/**
					 * @fn SceneOBJ & operator=(SceneOBJ && move) noexcept
					 * @param[in] move The SceneOBJ to move.
					 * @return The SceneOBJ moved.
					 * @brief Default move assignment operator.
					 * @throw noexcept
					 */
					SceneOBJ & operator=(SceneOBJ && move) noexcept = default;

					inline void addVertex(const FloatVector4u & v);
					inline void addVertex(FloatVector4u && v);

					inline auto getNumberOfVertices() const;
					inline auto & getVertices();
					inline auto getVertices() const;

					inline void addVertexTexture(const FloatVector2u & vt);
					inline void addVertexTexture(FloatVector2u && vt);

					inline auto getNumberOfVerticesTexture() const;
					inline auto & getVerticesTexture();
					inline auto getVerticesTexture() const;

					inline void addVertexNormal(const FloatVector3u & vn);
					inline void addVertexNormal(FloatVector3u && vn);

					inline auto getNumberOfVerticesNormal() const;
					inline auto & getVerticesNormal();
					inline auto getVerticesNormal() const;

					inline void addVertexSpaceParameter(const FloatVector3u & vp);
					inline void addVertexSpaceParameter(FloatVector3u && vp);

					inline auto getNumberOfVerticesSpaceParameter() const;
					inline auto & getVerticesSpaceParameter();
					inline auto getVerticesSpaceParameter() const;

					inline auto & getObjects();
					inline auto getObjects() const;

					inline auto & getMaterials();
					inline auto getMaterials() const;

					auto addObject(const std::string & name) -> std::vector<ObjectOBJ>::iterator;

				private:
					std::vector<ObjectOBJ> _objects;
					std::vector<ObjectOBJ>::iterator _currentObject;
					std::vector<std::string> _materials;

					std::vector<FloatVector4u> _v; // geometric vertices
					std::vector<FloatVector2u> _vt; // texture vertices
					std::vector<FloatVector3u> _vn; // vertex normals
					std::vector<FloatVector3u> _vp; // parameter space vertices
				};
			} // namespace wavefront
		} // namespace formats
	} // namespace utility
} // namespace ece

#include "utility/formats/wavefront/scene_obj.inl"

#endif // SCENE_OBJ_HPP