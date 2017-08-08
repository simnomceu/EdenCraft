#include "locale\locale_loader.hpp"

#include "file\parser_json.hpp"
#include "debug\exception.hpp"
#include "json\atomic_json.hpp"

#include <utility>
#include <iostream>
#include <memory>

namespace ece
{
	std::string LocaleLoader::path = "";

	void LocaleLoader::setPath(const std::string & path)
	{
		LocaleLoader::path = path;
	}

	LocaleLoader::LocaleLoader(const std::string & filename, const Locale & locale): locale(locale), resource(), filename(filename)
	{
		this->locale = locale;
		std::string file = LocaleLoader::path + this->filename + "_" + this->locale.getLanguage() + "_" + this->locale.getCountry() + ".json";
		this->generateResource(file);
	}

	LocaleResource & LocaleLoader::getResource()
	{
		return this->resource;
	}

	void LocaleLoader::changeLocale(const Locale & locale)
	{
		this->locale = locale;
		std::string file = LocaleLoader::path + this->filename + "_" + this->locale.getLanguage() + "_" + this->locale.getCountry() + ".json";
		this->generateResource(file);
	}

	void LocaleLoader::generateResource(const std::string & file)
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