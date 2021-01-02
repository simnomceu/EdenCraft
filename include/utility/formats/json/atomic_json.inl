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

namespace ece
{
    namespace utility
    {
		namespace formats
		{
			namespace json
			{
				template<class T>
				inline AtomicJSON<T>::AtomicJSON(const std::string & key, const T & value, const std::weak_ptr<NodeJSON>& parent) :
					NodeJSON(parent), _key(key), _value(value) {}

				template<class T>
				inline auto AtomicJSON<T>::isAtomic() const noexcept -> bool { return true; }

				template<class T>
				inline auto AtomicJSON<T>::getType() const noexcept -> NodeJSON::Type { return NodeJSON::Type::NULL_JSON; }

				template<>
				inline auto BooleanJSON::getType() const noexcept ->NodeJSON::Type { return NodeJSON::Type::BOOLEAN; }

				template<>
				inline auto IntegerJSON::getType() const noexcept ->NodeJSON::Type { return NodeJSON::Type::INTEGER; }

				template<>
				inline auto DoubleJSON::getType() const noexcept ->NodeJSON::Type { return NodeJSON::Type::DOUBLE; }

				template<>
				inline auto StringJSON::getType() const noexcept -> NodeJSON::Type { return NodeJSON::Type::STRING; }

				template<class T>
				inline auto AtomicJSON<T>::getValue() const { return this->_value; }

				template<class T>
				inline void AtomicJSON<T>::setValue(const T & value) { this->_value = value; }

				template<class T>
				inline auto AtomicJSON<T>::getKey() const { return this->_key; }

				template <class T>
				inline auto AtomicJSON<T>::to_string() const noexcept -> std::string { return ""; }

				template <>
				inline auto BooleanJSON::to_string() const noexcept -> std::string { return (this->_value) ? "true" : "false"; }

				template <>
				inline auto IntegerJSON::to_string() const noexcept -> std::string { return std::to_string(this->_value); }

				template <>
				inline auto DoubleJSON::to_string() const noexcept -> std::string { return std::to_string(this->_value); }

				template <>
				inline auto StringJSON::to_string() const noexcept -> std::string { return "\"" + this->_value + "\""; }
			} // namespace json
		} // namespace formats
    } // namespace utility
} // namespace ece
