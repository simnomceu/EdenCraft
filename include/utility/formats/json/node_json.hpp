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

#ifndef NODE_JSON_HPP
#define NODE_JSON_HPP

#include "utility/config.hpp"
#include "utility/pch.hpp"
#include "utility/enumeration.hpp"

namespace ece
{
	namespace utility
	{
		namespace formats
		{
			namespace json
			{
				class NodeJSON;
			}
		}
	}
}

template ECE_UTILITY_EXTERN class ECE_UTILITY_API std::enable_shared_from_this<ece::utility::formats::json::NodeJSON>;

namespace ece
{
    namespace utility
    {
		namespace formats
		{
			namespace json
			{
				/**
				 * @class NodeJSON
				 * @extends std::enable_shared_from_this<NodeJSON>
				 * @brief Generic node of the JSON tree.
				 * @remark Is it possible to remove the usage of std::enable_shared_from_this ?
				 */
				class ECE_UTILITY_API NodeJSON : public std::enable_shared_from_this<NodeJSON>
				{
				public:
					enum class Type : unsigned short int
					{
						NULL_JSON = 0,
						BOOLEAN = 1,
						INTEGER = 2,
						DOUBLE = 3,
						STRING = 4,
						OBJECT = 5,
						ARRAY = 6
					};

					/**
					 * @fn NodeJSON(const std::weak_ptr<NodeJSON> & parent = std::weak_ptr<NodeJSON>())
					 * @param[in] parent The parent node of this node.
					 * @brief Default constructor of a generic node JSON.
					 * @throw noexcept
					 */
					inline NodeJSON(const std::weak_ptr<NodeJSON> & parent = std::weak_ptr<NodeJSON>()) noexcept;

					/**
					 * @fn NodeJSON(const NodeJSON & copy)
					 * @param[in] copy The node to copy from.
					 * @brief Default copy constructor.
					 * @throw noexcept
					 */
					inline NodeJSON(const NodeJSON & copy) noexcept;

					/**
					 * @fn NodeJSON(NodeJSON && move)
					 * @param[in] move The node to move.
					 * @brief Default move constructor.
					 * @throw noexcept
					 */
					inline NodeJSON(NodeJSON && move) noexcept;

					/**
					 * @fn ~NodeJSON()
					 * @brief Default destructor.
					 * @throw noexcept
					 */
					inline ~NodeJSON() noexcept;

					/**
					 * @fn NodeJSON & operator=(const NodeJSON & copy)
					 * @param[in] copy The node to copy from.
					 * @return The node copied.
					 * @brief Default copy assignment operator.
					 * @throw noexcept
					 */
					NodeJSON & operator=(const NodeJSON & copy) noexcept;

					/**
					 * @fn NodeJSON & operator=(NodeJSON && move)
					 * @param[in] move The node to move.
					 * @return The node moved.
					 * @brief Default move assignment operator.
					 * @throw noexcept
					 */
					NodeJSON & operator=(NodeJSON && move) noexcept;

					/**
					 * @fn std::shared_ptr<NodeJSON> getParent()
					 * @return The parent of the node.
					 * @brief Get the parent of the node if it exists. Else, returns an empty pointer.
					 * @throw noexcept
					 */
					inline auto getParent() noexcept;

					/**
					 * @fn bool hasParent() const
					 * @return True if the node has a parent, false else.
					 * @brief Indicates if a node has a parent or not.
					 * @throw noexcept
					 */
					inline auto hasParent() const noexcept;

					template <class T, typename enabled = typename std::enable_if_t<std::is_base_of_v<NodeJSON, T>>>
					static inline auto convertTo(std::shared_ptr<NodeJSON> & node);

					/**
					 * @pure
					 * @fn bool isAtomic() const
					 * @return True if the node is atomic, false else.
					 * @brief Indicates if the node is atomic or not.
					 * Object node and array node are not atomic.
					 * @throw noexcept
					 * @remark Define a property of type and not of the object. It should be a trait.
					 */
					virtual auto isAtomic() const noexcept -> bool = 0;

					/**
					 * @pure
					 * @fn TypeNodeJSON getType() const
					 * @return The type of the node.
					 * @brief Get the type of the node.
					 * It could be atomic (a numeric, a string, or a boolean), an array, or an object.
					 * @throw noexcept
					 * @remark Define a property of type and not of the object. It should be a trait.
					 */
					virtual auto getType() const noexcept -> NodeJSON::Type = 0;

					virtual auto to_string() const noexcept -> std::string = 0;

				private:
					/**
					 * @property _parent
					 * @brief The parent node of the current node.
					 */
					std::weak_ptr<NodeJSON> _parent;
				};
			} // namespace json
		} // namespace formats
    } // namespace utility
} // namespace ece

#include "utility/formats/json/node_json.inl"

#endif // NODE_JSON_HPP
