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

#include "utility/pch.hpp"
#include "utility/formats/json/parser_json.hpp"

#include "utility/file_system.hpp"
#include "utility/debug.hpp"
#include "utility/formats/json/array_json.hpp"

namespace ece
{
    namespace utility
    {
		namespace formats
		{
			namespace json
			{
				void ParserJSON::load(std::istream & stream)
				{

					auto content = std::string{};
					auto line = std::string{};
					while (stream.good()) {
						std::getline(stream, line);
						content.append(line + "\n");
					}

					auto currentNode = std::shared_ptr<NodeJSON>{};
					auto currentKey = std::string{};
					while (!content.empty()) {
						const auto key = content[0];
						switch (key) {
						case '{':
							if (!currentNode) {
								this->_contentJSON.reset(new ObjectJSON());
								currentNode = this->_contentJSON;
							}
							else {
								if (currentNode->getType() == NodeJSON::Type::OBJECT) {
									currentNode = std::static_pointer_cast<ObjectJSON>(currentNode)->addObject(currentKey);
								}
								else if (currentNode->getType() == NodeJSON::Type::ARRAY) {
									currentNode = std::static_pointer_cast<ArrayJSON>(currentNode)->addObject();
								}
							}
							content = content.substr(1);
							break;
						case '}':
							if (currentNode->hasParent()) {
								currentNode = currentNode->getParent();
							}
							content = content.substr(1);
							break;
						case '[':
							if (currentNode->getType() == NodeJSON::Type::OBJECT) {
								currentNode = std::static_pointer_cast<ObjectJSON>(currentNode)->addArray(currentKey);
							}
							else if (currentNode->getType() == NodeJSON::Type::ARRAY) {
								currentNode = std::static_pointer_cast<ArrayJSON>(currentNode)->addArray();
							}
							content = content.substr(1);
							break;
						case ']':
							currentNode = currentNode->getParent();
							content = content.substr(1);
							break;
						case '"':
							content = content.substr(1);
							if (currentKey.empty()) {
								currentKey = content.substr(0, content.find_first_of('"'));
								content = content.substr(content.find_first_of('"') + 1);
								content = content.substr(content.find_first_of(':') + 1);
							}
							else {
								if (currentNode->getType() == NodeJSON::Type::OBJECT) {
									std::static_pointer_cast<ObjectJSON>(currentNode)->addString(currentKey, content.substr(0, content.find_first_of('"')));
								}
								else if (currentNode->getType() == NodeJSON::Type::ARRAY) {
									std::static_pointer_cast<ArrayJSON>(currentNode)->addString(content.substr(0, content.find_first_of('"')));
								}
								content = content.substr(content.find_first_of('"') + 1);
							}
							break;
						case ' ':
							content = content.substr(1);
							break;
						case ',':
							currentKey = "";
							content = content.substr(1);
							break;
						default:
							if (key >= '0' && key <= '9') {
								auto streamVal = std::istringstream{ content };
								auto value = 0.0;
								streamVal >> value;
								if (value == std::floor(value)) {
									auto integer = static_cast<int>(value);
									content = content.substr(std::min({ content.find_first_of(','), content.find_first_of(']'), content.find_first_of('}') }));
									if (currentNode->getType() == NodeJSON::Type::ARRAY) {
										std::static_pointer_cast<ArrayJSON>(currentNode)->addInteger(integer);
									}
									else if (currentNode->getType() == NodeJSON::Type::OBJECT) {
										std::static_pointer_cast<ObjectJSON>(currentNode)->addInteger(currentKey, integer);
									}
								}
								else {
									content = content.substr(std::min({ content.find_first_of(','), content.find_first_of(']'), content.find_first_of('}') }));
									if (currentNode->getType() == NodeJSON::Type::ARRAY) {
										std::static_pointer_cast<ArrayJSON>(currentNode)->addDouble(value);
									}
									else if (currentNode->getType() == NodeJSON::Type::OBJECT) {
										std::static_pointer_cast<ObjectJSON>(currentNode)->addDouble(currentKey, value);
									}
								}
							}
							else if (key >= 'a' && key <= 'z') {
								if (key == 't' || key == 'f') {
									auto value = (key == 't');
									if (currentNode->getType() == NodeJSON::Type::ARRAY) {
										std::static_pointer_cast<ArrayJSON>(currentNode)->addBoolean(value);
									}
									else if (currentNode->getType() == NodeJSON::Type::OBJECT) {
										std::static_pointer_cast<ObjectJSON>(currentNode)->addBoolean(currentKey, value);
									}
								}
								else if (key == 'n') {
									if (currentNode->getType() == NodeJSON::Type::ARRAY) {
										std::static_pointer_cast<ArrayJSON>(currentNode)->addNull();
									}
									else if (currentNode->getType() == NodeJSON::Type::OBJECT) {
										std::static_pointer_cast<ObjectJSON>(currentNode)->addNull(currentKey);
									}
								}
								content = content.substr(4);
							}
							else {
								content = content.substr(1);
							}
							break;
						}
					}
				}

				void ParserJSON::save(std::ostream & stream)
				{
					auto content = this->_contentJSON->to_string();

					stream << content;
				}
			} // namespace json
		}// namespace formats
    } // namespace utility
} // namespace ece
