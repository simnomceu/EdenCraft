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
 * @file utility/json/atomic_json.hpp
 * @author IsilinBN (casa2pir@hotmail.fr)
 * @date January, 16th 2018
 * @copyright ----------
 * @brief Atomic node from a JSON tree.
 */

#ifndef ATOMIC_JSON_HPP
#define ATOMIC_JSON_HPP

#include "utility/json/node_json.hpp"

namespace ece
{
	/**
	 * @class AtomicJSON
	 * @extends NodeJSON
	 * @tparam T
	 * @brief An atomic node of the JSON tree. It is a key/value pair.
	 */
	template <class T>
	class AtomicJSON: public NodeJSON
	{
	public:
		AtomicJSON() = delete;

		/**
		 * @fn AtomicJSON(const std::string & key, const T & value, const std::weak_ptr<NodeJSON> & parent = std::weak_ptr<NodeJSON>())
		 * @param[in] key The key of the node
		 * @param[in] value The value of the node.
		 * @param[in] parent Parent node of the current node.
		 * @brief Default constructor.
		 * @throw
		 */
		inline AtomicJSON(const std::string & key, const T & value, const std::weak_ptr<NodeJSON> & parent = std::weak_ptr<NodeJSON>());

		/**
		 * @fn AtomicJSON(const AtomicJSON & copy)
		 * @param[in] copy The atomic node to copy from.
		 * @brief Default copy constructor.
		 * @throw
		 */
		AtomicJSON(const AtomicJSON & copy) = default;

		/**
		 * @fn AtomicJSON(AtomicJSON && move)
		 * @param[in] move The atomic node to move.
		 * @brief Default move constructor.
		 * @throw noexcept
		 */
		AtomicJSON(AtomicJSON && move) noexcept = default;
		
		/**
		 * @fn ~AtomicJSON()
		 * @brief Default destructor.
		 * @throw noexcept
		 */
		~AtomicJSON() noexcept = default;
		
		/**
		 * @fn AtomicJSON & operator=(const AtomicJSON & copy)
		 * @param[in] copy The atomic node to copy from.
		 * @return The atomic node copied.
		 * @brief Default copy assignment operator.
		 * @throw
		 */
		AtomicJSON & operator=(const AtomicJSON & copy) = default;
		
		/**
		 * @fn AtomicJSON & operator=(AtomicJSON && move)
		 * @param[in] move The atomic node to move.
		 * @return The atomic node moved.
		 * @brief Default move assignment operator.
		 * @throw noexcept
		 */
		AtomicJSON & operator=(AtomicJSON && move) noexcept = default;
		
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
		 * @fn const T & getValue() const
		 * @return The value of the node.
		 * @brief Get the value of the node.
		 */
		inline const T & getValue() const;

		/**
		 * @fn void setValue(const T & value)
		 * @param[in] value The value to set.
		 * @brief Set the value of the node.
		 */
		inline void setValue(const T & value);

		/**
		 * @fn const std::string & getKey() const
		 * @return The key of the node.
		 * @brief Get the key of the node.
		 */
		inline const std::string & getKey() const;

	private:
		/**
		 * @property _key
		 * @brief The key of the node.
		 */
		std::string _key;

		/**
		 * @property _value
		 * @brief The value of the node.
		 */
		T _value;
	};

	using NullJSON = AtomicJSON<void *>;
	using BooleanJSON = AtomicJSON<bool>;
	using IntegerJSON = AtomicJSON<int>;
	using DoubleJSON = AtomicJSON<double>;
	using StringJSON = AtomicJSON<std::string>;
}

#include "utility/json/atomic_json.inl"

#endif // ATOMIC_JSON_HPP