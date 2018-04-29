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

#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <vector>
#include "utility/mathematics/vector3u.hpp"

namespace ece
{
    using namespace utility::mathematics;
    
	/**
	 * @class Vertex
	 * @brief A vertex of a 3D object.
	 */
	class Vertex
	{
	public:
		/**
		 * @fn constexpr Vertex() noexcept
		 * @brief Default constructor.
		 * @throw noexcept
		 */
		constexpr Vertex() noexcept = default;

		/**
		 * @fn Vertex(const Vertex & copy) noexcept
		 * @param[in] copy The Vertex to copy from.
		 * @brief Default copy constructor.
		 * @throw noexcept
		 */
		Vertex(const Vertex & copy) noexcept = default;

		/**
		 * @fn Vertex(Vertex && move) noexcept
		 * @param[in] move The Vertex to move.
		 * @brief Default move constructor.
		 * @throw noexcept
		 */
		Vertex(Vertex && move) noexcept = default;

		/**
		 * @fn ~Vertex() noexcept
		 * @brief Default destructor.
		 * @throw noexcept
		 */
		~Vertex() noexcept = default;

		/**
		 * @fn Vertex & operator=(const Vertex & copy) noexcept
		 * @param[in] copy The Vertex to copy from.
		 * @return The Vertex copied.
		 * @brief Default copy assignment operator.
		 * @throw noexcept
		 */
		Vertex & operator=(const Vertex & copy) noexcept = default;

		/**
		 * @fn Vertex & operator=(Vertex && move) noexcept
		 * @param[in] move The Vertex to move from.
		 * @return The Vertex moved.
		 * @brief Default move assignment operator.
		 * @throw noexcept
		 */
		Vertex & operator=(Vertex && move) noexcept = default;

		/**
		 * @fn std::vector<FloatVector3u> getPositions() const
		 * @return The positions.
		 * @brief Get the list of vertice positions.
		 * @throw
		 */
		virtual std::vector<FloatVector3u> getPositions() const = 0;

		/**
		 * @fn std::vector<FloatVector3u> getColors() const
		 * @return The colors.
		 * @brief Get the list of vertice colors.
		 * @throw
		 */
		virtual std::vector<FloatVector3u> getColors() const = 0;

		/**
		 * @fn std::vector<FloatVector3u> getNormals() const
		 * @return The normals.
		 * @brief Get the list of vertice normals.
		 * @throw
		 */
		virtual std::vector<FloatVector3u> getNormals() const = 0;

		/**
		 * @fn std::vector<FloatVector3u> getIndices() const
		 * @return The indices.
		 * @brief Get the list of vertice indices.
		 * @throw
		 */
		virtual std::vector<int> getIndices() const = 0;

		/**
		 * @fn bool is indexed() const
		 * @return True if it is indexed, false else.
		 * @brief Check if use the indexed mechanism or not.
		 * @throw
		 */
		inline bool isIndexed() const;
	};
}

#include "graphic/renderable/vertex.inl"

#endif // VERTEX_HPP
