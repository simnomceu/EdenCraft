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

#include "utility/file_system/parser_json.hpp"

#include "utility/file_system/file.hpp"
#include "utility/debug/exception.hpp"
#include "utility/json/array_json.hpp"

#include <sstream>
#include <cmath>

#include "utility/json/object_json.hpp"

namespace ece
{
	void ParserJSON::loadFromFile(const std::string & pathname)
	{
		if (this->pathname != pathname) {
			this->pathname = pathname;
			File file;
			try {
				file.open(pathname, OpenMode::in);
				std::string content = file.parseToString();
				
				/*size_t pos = 0;
				std::string search("\n\t"), replace("");
				while ((pos = content.find(search, pos)) != std::string::npos) {
					content.replace(pos, search.length(), replace);
					pos += replace.length();
				}*/

				file.close();
				std::shared_ptr<NodeJSON> currentNode;
				std::string currentKey = "";
				while (!content.empty()) {
					char key = content[0];
					switch (key) {
					case '{':
						if (currentKey.empty()) {
							currentNode.reset(new ObjectJSON());
						}
						else {
							if (currentNode->getType() == TypeNodeJSON::OBJECT_JSON) {
								currentNode = std::static_pointer_cast<ObjectJSON>(currentNode)->addObject(currentKey);
							}
							else if (currentNode->getType() == TypeNodeJSON::ARRAY_JSON) {
								currentNode = std::static_pointer_cast<ArrayJSON>(currentNode)->addObject();
							}
							else {
								// HOHO
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
						if (currentNode->getType() == TypeNodeJSON::OBJECT_JSON) {
							currentNode = std::static_pointer_cast<ObjectJSON>(currentNode)->addArray(currentKey);
						}
						else if (currentNode->getType() == TypeNodeJSON::ARRAY_JSON) {
							currentNode = std::static_pointer_cast<ArrayJSON>(currentNode)->addArray();
						}
						else {
							// HOHO
						}
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
							if (currentNode->getType() == TypeNodeJSON::OBJECT_JSON) {
								std::static_pointer_cast<ObjectJSON>(currentNode)->addString(currentKey, content.substr(0, content.find_first_of('"')));
							}
							else if (currentNode->getType() == TypeNodeJSON::ARRAY_JSON) {
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
							std::istringstream stream(content);
							double value;
							stream >> value;
							if (value == std::floor(value)) {
								int integer = static_cast<int>(value);
								content = content.substr(std::to_string(integer).size());
								if (currentNode->getType() == TypeNodeJSON::ARRAY_JSON) {
									std::static_pointer_cast<ArrayJSON>(currentNode)->addInteger(integer);
								}
								else if (currentNode->getType() == TypeNodeJSON::OBJECT_JSON) {
									std::static_pointer_cast<ObjectJSON>(currentNode)->addInteger(currentKey, integer);
								}
								else {

								}
							}
							else {
								content = content.substr(std::to_string(value).size());
								if (currentNode->getType() == TypeNodeJSON::ARRAY_JSON) {
									std::static_pointer_cast<ArrayJSON>(currentNode)->addDouble(value);
								}
								else if (currentNode->getType() == TypeNodeJSON::OBJECT_JSON) {
									std::static_pointer_cast<ObjectJSON>(currentNode)->addDouble(currentKey, value);
								}
								else {

								}
							}
						}
						else if (key >= 'a' && key <= 'z') {
							if (key == 't' || key == 'f') {
								bool value = (key == 't');
								if (currentNode->getType() == TypeNodeJSON::ARRAY_JSON) {
									std::static_pointer_cast<ArrayJSON>(currentNode)->addBoolean(value);
								}
								else if (currentNode->getType() == TypeNodeJSON::OBJECT_JSON) {
									std::static_pointer_cast<ObjectJSON>(currentNode)->addBoolean(currentKey, value);
								}
								else {

								}
							}
							else if (key == 'n') {
								if (currentNode->getType() == TypeNodeJSON::ARRAY_JSON) {
									std::static_pointer_cast<ArrayJSON>(currentNode)->addNull();
								}
								else if (currentNode->getType() == TypeNodeJSON::OBJECT_JSON) {
									std::static_pointer_cast<ObjectJSON>(currentNode)->addNull(currentKey);
								}
								else {

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
				this->contentJSON = std::static_pointer_cast<ObjectJSON>(currentNode);
			}
			catch (FileException & e) {
				throw e;
			}
		}
	}

	void ParserJSON::loadFromString(const std::string & content)
	{
		/* NOT IMPLEMENTED YET*/
	}

	void ParserJSON::loadFromMemory(const void * content)
	{
		/* NOT IMPLEMENTED YET*/
	}

	void ParserJSON::saveToFile(const std::string & filename)
	{
		/* NOT IMPLEMENTED YET*/
	}

	void ParserJSON::saveToString(std::string & content)
	{
		/* NOT IMPLEMENTED YET*/
	}

	void ParserJSON::saveToMemory(void * content)
	{
		/* NOT IMPLEMENTED YET*/
	}
}
