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
				Copyright(C) 2017 Pierre Casati (@IsilinBN)

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

/**
 * @file utility/json/array_json.hpp
 * @author IsilinBN (casa2pir@hotmail.fr)
 * @date January, 1st 2018
 * @copyright ----------
 * @brief Array node from a JSON tree.
 */

#ifndef ARRAY_JSON_HPP
#define ARRAY_JSON_HPP

#include "utility/json/node_json.hpp"
#include "utility/json/atomic_json.hpp"

#include <vector>

namespace ece
{
	class ObjectJSON;

	/**
	 * @typedef IteratorArrayJSON
	 * @brief An iterator to navigate between node's children.
	 * @see http://en.cppreference.com/w/cpp/concept/RandomAccessIterator
	 */
	using IteratorArrayJSON = std::vector<std::shared_ptr<NodeJSON>>::iterator;

	/**
	 * @class ArrayJSON
	 * @extends NodeJSON
	 * @brief An array node of the JSON tree. It can have multiple children of any type.
	 */
	class ArrayJSON : public NodeJSON
	{
	public:
		ArrayJSON() = delete;

		/**
		 * @fn ArrayJSON(const std::weak_ptr<NodeJSON> & parent = std::weak_ptr<NodeJSON>())
		 * @param[in] parent Parent node of the current node.
		 * @brief Default constructor. The array node is built empty.
		 * @throw
		 */
		inline ArrayJSON(const std::weak_ptr<NodeJSON> & parent = std::weak_ptr<NodeJSON>());

		/**
		 * @fn ArrayJSON(const ArrayJSON & copy)
		 * @param[in] copy The array node to copy from.
		 * @brief Default copy constructor.
		 * @throw
		 */
		ArrayJSON(const ArrayJSON & copy) = default;
		
		/**
		 * @fn ArrayJSON(ArrayJSON && move)
		 * @param[in] move The array node to move.
		 * @brief Default move constructor.
		 * @throw noexcept
		 */
		ArrayJSON(ArrayJSON && move) noexcept = default;

		/**
		 * @fn ~ArrayJSON()
		 * @brief Default destructor.
		 * @throw noexcept
		 */
		~ArrayJSON() noexcept = default;

		/**
		 * @fn ArrayJSON & operator=(const ArrayJSON & copy)
		 * @param[in] copy The array node to copy from.
		 * @return The array node copied.
		 * @brief Default copy assignment operator.
		 * @throw
		 */
		ArrayJSON & operator=(const ArrayJSON & copy) = default;
		
		/**
		 * @fn ArrayJSON & operator=(ArrayJSON && move)
		 * @param[in] move The array node to move.
		 * @return The array node moved.
		 * @brief Default move assignment operator.
		 * @throw noexcept
		 */
		ArrayJSON & operator=(ArrayJSON && move) noexcept = default;

		/**
		 * @fn std::shared_ptr<NodeJSON> addNull()
		 * @return The child node created.
		 * @brief Create a null node and add it as a child to the current node.
		 * @throw
		 * @remark Maybe it should return the exact type of node created.
		 * @remark This method should use emplace_back instead of push_back, with move syntax.
		 */
		std::shared_ptr<NodeJSON> addNull();
		
		/**
		 * @fn std::shared_ptr<NodeJSON> addBoolean(const bool value)
		 * @param[in] value The value of the node to create.
		 * @return The child node created.
		 * @brief Create a boolean atomic node and add it as a child to the current node.
		 * @throw
		 * @remark Maybe it should return the exact type of node created.
		 * @remark This method should use emplace_back instead of push_back, with move syntax.
		 */
		std::shared_ptr<NodeJSON> addBoolean(const bool value);

		/**
		 * @fn std::shared_ptr<NodeJSON> addInteger(const int value)
		 * @param[in] value The value of the node to create.
		 * @return The child node created.
		 * @brief Create an integer atomic node and add it as a child to the current node.
		 * @throw
		 * @remark Maybe it should return the exact type of node created.
		 * @remark This method should use emplace_back instead of push_back, with move syntax.
		 */
		std::shared_ptr<NodeJSON> addInteger(const int value);

		/**
		 * @fn std::shared_ptr<NodeJSON> addDouble(const double value)
		 * @param[in] value The value of the node to create.
		 * @return The child node created.
		 * @brief Create a double atomic node and add it as a child to the current node.
		 * @throw
		 * @remark Maybe it should return the exact type of node created.
		 * @remark This method should use emplace_back instead of push_back, with move syntax.
		 */
		std::shared_ptr<NodeJSON> addDouble(const double value);

		/**
		 * @fn std::shared_ptr<NodeJSON> addString(const std::string & value)
		 * @param[in] value The value of the node to create.
		 * @return The child node created.
		 * @brief Create a string atomic node and add it as a child to the current node.
		 * @throw
		 * @remark Maybe it should return the exact type of node created.
		 * @remark This method should use emplace_back instead of push_back, with move syntax.
		 */
		std::shared_ptr<NodeJSON> addString(const std::string & value);

		/**
		 * @fn std::shared_ptr<NodeJSON> addObject()
		 * @return The child node created.
		 * @brief Create an object node and add it as a child to the current node.
		 * @throw
		 * @remark Maybe it should return the exact type of node created.
		 * @remark This method should use emplace_back instead of push_back, with move syntax.
		 */
		std::shared_ptr<NodeJSON> addObject();

		/**
		 * @fn std::shared_ptr<NodeJSON> addArray()
		 * @return The child node created.
		 * @brief Create an array node and add it as a child to the current node.
		 * @throw
		 * @remark Maybe it should return the exact type of node created.
		 * @remark This method should use emplace_back instead of push_back, with move syntax.
		 */
		std::shared_ptr<NodeJSON> addArray();

		/**
		 * @fn void remove(const std::shared_ptr<NodeJSON> & child)
		 * @param[in] child The child node to remove.
		 * @brief Remove a child from the current node.
		 * If it is not a child of the current node, nothing happen.
		 * @throw
		 */
		void remove(const std::shared_ptr<NodeJSON> & child);

		/**
		 * @fn bool isAtomic() const
		 * @return True if the node is atomic, false else.
		 * @brief Indicates if the node is atomic or not.
		 * Object node and array node are not atomic.
		 * @throw noexcept
		 * @remark Define a property of type and not of the object. It should be a trait.
		 */
		inline virtual bool isAtomic() const noexcept override;
		
		/**
		 * @fn TypeNodeJSON getType() const
		 * @return The type of the node.
		 * @brief Get the type of the node.
		 * It could be atomic (a numeric, a string, or a boolean), an array, or an object.
		 * @throw noexcept
		 * @remark Define a property of type and not of the object. It should be a trait.
		 */
		inline virtual TypeNodeJSON getType() const noexcept override;

		/**
		 * @fn IteratorArrayJSON begin()
		 * @return An iterator pointing to the first child.
		 * @brief Get an iterator pointing to the first child of the current node.
		 * If there is no child, the iterator shall not be dereferenced.
		 * @throw noexcept
		 */
		inline IteratorArrayJSON begin() noexcept;

		/**
		 * @fn IteratorArrayJSON end()
		 * @return An iterator to the element past the end.
		 * @brief Get an iterator pointing to past-the-end child of the current node.
		 * If there is no child, it returns the same as ArrayJSON::begin.
		 * @throw noexcept
		 */
		inline IteratorArrayJSON end() noexcept;

		/**
		 * @fn std::shared_ptr<NodeJSON> operator[](const int key)
		 * @param[in] key The index key of the child to get.
		 * @return The child corresponding to the index key.
		 * @brief Get a specific child of the current node.
		 * @throw out_of_range
		 */
		inline std::shared_ptr<NodeJSON> operator[](const int key);

		/**
		 * @fn void clear()
		 * @brief Erase all the children nodes of the current node.
		 * @throw noexcept
		 */
		inline void clear() noexcept;

		/**
		 * @fn unsigned int size() const
		 * @return The number of children.
		 * @brief Get the number of children nodes of the current node.
		 * @throw noexcept
		 */
		inline unsigned int size() const noexcept;

	private:
		/**
		 * @property children
		 * @brief The list of children nodes of the current children.
		 * Children can be of any type.
		 */
		std::vector<std::shared_ptr<NodeJSON>> children;
	};
}

#include "utility/json/array_json.inl"

#endif // ARRAY_JSON_HPP