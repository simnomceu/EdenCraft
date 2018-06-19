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

#ifndef OBJECT_OBJ_HPP
#define OBJECT_OBJ_HPP

#include "utility/mathematics/vector3u.hpp"
#include "utility/mathematics/vector4u.hpp"

namespace ece
{
	namespace utility
	{
		namespace wavefront
		{
			using mathematics::IntVector3u;
			using mathematics::FloatVector3u;
			using mathematics::FloatVector4u;

			/**
			 * @class ObjectOBJ
			 * @brief
			 */
			class ObjectOBJ
			{
			public:
				struct Vertex
				{
					int _v;
					int _vt;
					int _vn;
				};
				using Face = std::vector<Vertex>;

				ObjectOBJ() noexcept = delete;
				
				/**
				 * @fn ObjectOBJ(const std::string & name) noexcept
				 * @param[in] name The name of the object.
				 * @brief Default constructor.
				 * @throw noexcept
				 */
				inline ObjectOBJ(const std::string & name = "unnamed") noexcept;

				/**
				 * @fn ObjectOBJ(const ObjectOBJ & copy)
				 * @param[in] copy The ObjectOBJ to copy from.
				 * @brief Default copy constructor.
				 * @throw 
				 */
				ObjectOBJ(const ObjectOBJ & copy) = default;

				/**
				 * @fn ObjectOBJ(ObjectOBJ && move) noexcept
				 * @param[in] move The ObjectOBJ to move.
				 * @brief Default move constructor.
				 * @throw noexcept
				 */
				ObjectOBJ(ObjectOBJ && move) noexcept = default;

				/**
				 * @fn ~ObjectOBJ() noexcept
				 * @brief Default destructor.
				 * @throw noexcept
				 */
				~ObjectOBJ() noexcept = default;

				/**
				 * @fn ObjectOBJ & operator=(const ObjectOBJ & copy)
				 * @param[in] copy The ObjectOBJ to copy from.
				 * @return The ObjectOBJ copied.
				 * @brief Default copy assignment operator.
				 * @throw
				 */
				ObjectOBJ & operator=(const ObjectOBJ & copy) = default;

				/**
				 * @fn ObjectOBJ & operator=(ObjectOBJ && move) noexcept
				 * @param[in] move The ObjectOBJ to move.
				 * @return The ObjectOBJ moved.
				 * @brief Default move assignment operator.
				 * @throw noexcept
				 */
				ObjectOBJ & operator=(ObjectOBJ && move) noexcept = default;

				inline const std::string & getName() const;

				inline void addVertex(const FloatVector4u & v);
				inline void addVertex(FloatVector4u && v);

				inline int getNumberOfVertices() const;

				inline void addVertexTexture(const FloatVector3u & vt);
				inline void addVertexTexture(FloatVector3u && vt);

				inline int getNumberOfVerticesTexture() const;

				inline void addVertexNormal(const FloatVector3u & vn);
				inline void addVertexNormal(FloatVector3u && vn);

				inline int getNumberOfVerticesNormal() const;

				inline void addVertexSpaceParameter(const FloatVector3u & vp);
				inline void addVertexSpaceParameter(FloatVector3u && vp);

				inline int getNumberOfVerticesSpaceParameter() const;

				inline void addFace(const Face & f);
				inline void addFace(Face && f);

				inline int getNumberOfFaces() const;
			private:
				std::string _o; // object name

				std::vector<FloatVector4u> _v; // geometric vertices
				std::vector<FloatVector3u> _vt; // texture vertices
				std::vector<FloatVector3u> _vn; // vertex normals
				std::vector<FloatVector3u> _vp; // parameter space vertices

				std::vector<Face> _f; // face
			};
		} // namespace wavefront
	} // namespace utility
} // namespace ece

#include "utility/wavefront/object_obj.inl"

#endif OBJECT_OBJ_HPP