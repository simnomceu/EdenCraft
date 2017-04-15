#include "Locale\ResourceLoader.hpp"

#include "File\ParserJSON.hpp"
#include "Debug\Exception.hpp"
#include "JSON\AtomicJSON.hpp"

#include <utility>
#include <iostream>
#include <memory>

namespace ece
{
	std::string ResourceLoader::path = "";

	void ResourceLoader::setPath(const std::string & path)
	{
		ResourceLoader::path = path;
	}

	ResourceLoader::ResourceLoader(const std::string & filename, const Locale & locale): locale(locale), resource(), filename(filename)
	{
		this->locale = locale;
		std::string file = ResourceLoader::path + this->filename + "_" + this->locale.getLanguage() + "_" + this->locale.getCountry() + ".json";
		this->generateResource(file);
	}

	LocaleResource & ResourceLoader::getResource()
	{
		return this->resource;
	}

	void ResourceLoader::changeLocale(const Locale & locale)
	{
		this->locale = locale;
		std::string file = ResourceLoader::path + this->filename + "_" + this->locale.getLanguage() + "_" + this->locale.getCountry() + ".json";
		this->generateResource(file);
	}

	void ResourceLoader::generateResource(const std::string & file)
	{
		this->resource.clear();
		try {
			ParserJSON parser(file);
			std::shared_ptr<ObjectJSON> jsonObject = parser.getObject();

			for (auto it = jsonObject->begin(); it != jsonObject->end(); ++it) {
				if (it->second->getType() == TypeNodeJSON::NULL_JSON) {
					auto element = std::static_pointer_cast<NullJSON>(it->second);
					this->resource.insert(std::pair<std::string, std::string>(element->getKey(), "null"));
				}
				else if (it->second->getType() == TypeNodeJSON::BOOLEAN) {
					auto element = std::static_pointer_cast<BooleanJSON>(it->second);
					this->resource.insert(std::pair<std::string, std::string>(element->getKey(), std::to_string(element->getValue())));
				}
				else if (it->second->getType() == TypeNodeJSON::INTEGER) {
					auto element = std::static_pointer_cast<IntegerJSON>(it->second);
					this->resource.insert(std::pair<std::string, std::string>(element->getKey(), std::to_string(element->getValue())));
				}
				else if (it->second->getType() == TypeNodeJSON::DOUBLE) {
					auto element = std::static_pointer_cast<DoubleJSON>(it->second);
					this->resource.insert(std::pair<std::string, std::string>(element->getKey(), std::to_string(element->getValue())));
				}
				else if (it->second->getType() == TypeNodeJSON::STRING) {
					auto element = std::static_pointer_cast<StringJSON>(it->second);
					this->resource.insert(std::pair<std::string, std::string>(element->getKey(), element->getValue()));
				}
			}
		}
		catch (FileException & e) {
			std::cerr << e.what() << std::endl;
		}
	}
}