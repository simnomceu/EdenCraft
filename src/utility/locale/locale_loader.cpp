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

#include "utility/locale/locale_loader.hpp"

#include "utility/formats/json/parser_json.hpp"
#include "utility/debug/exception.hpp"
#include "utility/formats/json/atomic_json.hpp"

#include <utility>
#include <iostream>
#include <memory>

namespace ece
{
    namespace utility
    {
        using debug::FileException;
        using formats::json::ObjectJSON;
		using formats::json::StringJSON;
        using formats::json::ParserJSON;

        namespace locale
        {
        	std::string LocaleLoader::_path = "";

        	void LocaleLoader::setPath(const std::string & path) noexcept
        	{
        		LocaleLoader::_path = path;
        	}

        	LocaleLoader::LocaleLoader(const std::string & filename, const Localization & locale): _locale(locale), _resource(), _filename(filename)
        	{
        		this->_locale = locale;
        		std::string file = LocaleLoader::_path + this->_filename + "_"
        							+ this->_locale.getLanguage() + "_" + this->_locale.getCountry() + ".json";
        		this->generateResource(file);
        	}

        	void LocaleLoader::changeLocale(const Localization & locale)
        	{
        		this->_locale = locale;
        		std::string file = LocaleLoader::_path + this->_filename + "_"
        							+ this->_locale.getLanguage() + "_" + this->_locale.getCountry() + ".json";
        		this->generateResource(file);
        	}

        	void LocaleLoader::generateResource(const std::string & file)
        	{
        		this->_resource.clear();
        		try {
        			ParserJSON parser;
        			parser.loadFromFile(file);
        			std::shared_ptr<ObjectJSON> jsonObject = parser.getObject();

        			for (auto it = jsonObject->begin(); it != jsonObject->end(); ++it) {
        				if (it->second->getType() == TypeNodeJSON::STRING_JSON) {
        					auto element = std::static_pointer_cast<StringJSON>(it->second);
        					this->_resource.insert(std::pair<std::string, std::string>(element->getKey(), element->getValue()));
        				}
        			}
        		}
        		catch (FileException & e) {
        			std::cerr << e.what() << std::endl;
        		}
        	}
        } // namespace locale
    } // namespace utility
} // namespace ece
