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

#ifndef OBJECTJSON_HPP
#define OBJECTJSON_HPP

#include "JSON\NodeJSON.hpp"
#include "JSON\AtomicJSON.hpp"

namespace ece
{
	class ArrayJSON;

	using IteratorObjectJSON = std::map<std::string, std::shared_ptr<NodeJSON>>::iterator;

	class ObjectJSON: public NodeJSON
	{
	public:
		ObjectJSON(const std::weak_ptr<NodeJSON> & parent = std::weak_ptr<NodeJSON>());
		ObjectJSON(const ObjectJSON & copy) = default;
		ObjectJSON(ObjectJSON && move) = default;

		~ObjectJSON() = default;

		ObjectJSON & operator=(const ObjectJSON & copy) = default;
		ObjectJSON & operator=(ObjectJSON && move) = default;

		std::shared_ptr<NodeJSON> addNull(const std::string & key);
		std::shared_ptr<NodeJSON> addBoolean(const std::string & key, const bool value);
		std::shared_ptr<NodeJSON> addInteger(const std::string & key, const int value);
		std::shared_ptr<NodeJSON> addDouble(const std::string & key, const double value);
		std::shared_ptr<NodeJSON> addString(const std::string & key, const std::string & value);
		std::shared_ptr<NodeJSON> addObject(const std::string & key);
		std::shared_ptr<NodeJSON> addArray(const std::string & key);

		void remove(const std::string & key);

		virtual bool isAtomic() const override;
		virtual TypeNodeJSON getType() const override;

		IteratorObjectJSON begin();
		IteratorObjectJSON end();
		std::shared_ptr<NodeJSON> operator[](const std::string & key);
		void clear();

	private:
		std::map<std::string, std::shared_ptr<NodeJSON>> children;
	};
}

#endif // OBJECTJSON_HPP