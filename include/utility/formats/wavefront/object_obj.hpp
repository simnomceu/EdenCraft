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

#include "utility/config.hpp"
#include "utility/pch.hpp"
#include "utility/mathematics.hpp"
#include "utility/hash.hpp"

namespace ece
{
	namespace utility
	{
		namespace formats
		{
			namespace wavefront
			{
				/**
				 * @class ObjectOBJ
				 * @brief
				 */
				class ECE_UTILITY_API ObjectOBJ
				{
				public:
					struct Vertex
					{
						int _v;
						int _vt;
						int _vn;
					};

					using Face = std::vector<Vertex>;

					struct Material
					{
						std::string name;
						std::size_t start;
						std::size_t end;
					};

					struct FaceGroup
					{
						std::string name;
						std::string material;
						std::vector<std::size_t> faces;
					};

					enum class Clockwise : unsigned char
					{
						CW,
						CCW,
						NON_SIGNIFICANT
					};

					struct FaceFormat
					{
						std::size_t size;
						Clockwise clockwise;
					};

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

					inline auto getName() const;

					inline void setFaceFormat(const FaceFormat & format);
					inline void setFaceFormat(FaceFormat && format);

					inline auto & getFaceFormat();
					inline auto getFaceFormat() const;

					inline void addFace(const Face & f);
					inline void addFace(Face && f);

					inline auto getNumberOfFaces() const;
					inline auto & getFaces();
					inline auto getFaces() const;

					inline void resetCurrentGroups();
					inline void addGroup(const std::string & group);
					inline void setMaterial(const std::string & material);

					inline auto getNumberOfGroups() const;
					inline auto & getGroups();
					inline auto getGroups() const;

					inline auto getVertexIndice(const ObjectOBJ::Vertex & vertex);

				private:
					std::string _o; // object name

					struct VertexCompare
					{
						auto operator()(const ObjectOBJ::Vertex & lhs, const ObjectOBJ::Vertex & rhs) const -> bool
						{
							return lhs._v == rhs._v && lhs._vt == rhs._vt;
						}
					};

					struct VertexHash
					{
						auto operator()(const ObjectOBJ::Vertex & vertex) const -> std::size_t
						{
							return hash_combine(std::hash<int>{}(vertex._v), std::hash<int>{}(vertex._vt));
						}
					};

					std::unordered_map<ObjectOBJ::Vertex, std::size_t, ObjectOBJ::VertexHash, ObjectOBJ::VertexCompare> _vertexIndexing;

					FaceFormat _faceFormat;
					std::vector<Face> _f; // face
					std::unordered_map<std::string, FaceGroup> _groups;
					std::vector<std::string> _currentGroups;
				};
			} // namespace wavefront
		} // namespace formats
	} // namespace utility
} // namespace ece

#include "utility/formats/wavefront/object_obj.inl"

#endif // OBJECT_OBJ_HPP
