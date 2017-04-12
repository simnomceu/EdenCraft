#include "File\ParserJSON.hpp"

#include "File\File.hpp"
#include "Debug\FileException.hpp"
#include "JSON\ArrayJSON.hpp"

#include <sstream>

namespace ece
{
	ParserJSON::ParserJSON(const std::string & pathname): pathname(), contentJSON()
	{
		this->open(pathname);
	}

	void ParserJSON::open(const std::string & pathname)
	{
		if (this->pathname != pathname) {
			this->pathname = pathname;
			File file;
			try {
				file.open(pathname, std::ios_base::in);
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
							if (currentNode->getType() == TypeNodeJSON::OBJECT) {
								currentNode = std::static_pointer_cast<ObjectJSON>(currentNode)->addObject(currentKey);
							}
							else if (currentNode->getType() == TypeNodeJSON::ARRAY) {
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
						if (currentNode->getType() == TypeNodeJSON::OBJECT) {
							currentNode = std::static_pointer_cast<ObjectJSON>(currentNode)->addArray(currentKey);
						}
						else if (currentNode->getType() == TypeNodeJSON::ARRAY) {
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
							if (currentNode->getType() == TypeNodeJSON::OBJECT) {
								std::static_pointer_cast<ObjectJSON>(currentNode)->addString(currentKey, content.substr(0, content.find_first_of('"')));
							}
							else if (currentNode->getType() == TypeNodeJSON::ARRAY) {
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
								if (currentNode->getType() == TypeNodeJSON::ARRAY) {
									std::static_pointer_cast<ArrayJSON>(currentNode)->addInteger(integer);
								}
								else if (currentNode->getType() == TypeNodeJSON::OBJECT) {
									std::static_pointer_cast<ObjectJSON>(currentNode)->addInteger(currentKey, integer);
								}
								else {

								}
							}
							else {
								content = content.substr(std::to_string(value).size());
								if (currentNode->getType() == TypeNodeJSON::ARRAY) {
									std::static_pointer_cast<ArrayJSON>(currentNode)->addDouble(value);
								}
								else if (currentNode->getType() == TypeNodeJSON::OBJECT) {
									std::static_pointer_cast<ObjectJSON>(currentNode)->addDouble(currentKey, value);
								}
								else {

								}
							}
						}
						else if (key >= 'a' && key <= 'z') {
							if (key == 't' || key == 'f') {
								bool value = (key == 't');
								if (currentNode->getType() == TypeNodeJSON::ARRAY) {
									std::static_pointer_cast<ArrayJSON>(currentNode)->addBoolean(value);
								}
								else if (currentNode->getType() == TypeNodeJSON::OBJECT) {
									std::static_pointer_cast<ObjectJSON>(currentNode)->addBoolean(currentKey, value);
								}
								else {

								}
							}
							else if (key == 'n') {
								if (currentNode->getType() == TypeNodeJSON::ARRAY) {
									std::static_pointer_cast<ArrayJSON>(currentNode)->addNull();
								}
								else if (currentNode->getType() == TypeNodeJSON::OBJECT) {
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

	std::shared_ptr<ObjectJSON> ParserJSON::getObject()
	{
		return this->contentJSON;
	}
}