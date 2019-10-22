/*

	oooooooooooo       .o8                          .oooooo.                       .o88o.     .
	`888'     `8      "888                         d8P'  `Y8b                      888 `"   .o8
	 888          .oooo888   .ooooo.  ooo. .oo.   888          oooo d8b  .oooo.   o888oo  .o888oo
	 888oooo8    d88' `888  d88' `88b `888P"Y88b  888          `888""8P `P  )88b   888      888
	 888    "    888   888  888ooo888  888   888  888           888      .oP"888   888      888
	 888       o 888   888  888    .o  888   888  `88b    ooo   888     d8(  888   888      888 .
	o888ooooood8 `Y8bod88P" `Y8bod8P' o888o o888o  `Y8bood8P'  d888b    `Y888""8o o888o     "888"

															  .oooooo.
															 d8P'  `Y8b
															888           .ooooo.  oooo d8b  .ooooo.
															888          d88' `88b `888""8P d88' `88b
															888          888   888  888     888ooo888
															`88b    ooo  888   888  888     888    .o
															 `Y8bood8P'  `Y8bod8P' d888b    `Y8bod8P'



				This file is part of EdenCraft Engine - Core module.
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

#include "utility/debug.hpp"
#include "core/resource/resource_handler.hpp"

namespace ece
{
	namespace core
	{
		namespace resource
		{
			inline ResourceRef::ResourceRef(const std::string & identifier, std::size_t typeId) noexcept : _identifier(identifier), _typeId(typeId)  {}

			ResourceRef::ResourceRef(const ResourceRef & copy) noexcept : _identifier(copy._identifier), _typeId(copy._typeId) {}

			ResourceRef::ResourceRef(ResourceRef && move) noexcept : _identifier(std::move(move._identifier)), _typeId(move._typeId) {}

			inline ResourceRef::~ResourceRef() noexcept {}

			inline ResourceRef & ResourceRef::operator=(const ResourceRef & copy) noexcept
			{
				if (this != &copy) {
					this->_identifier = copy._identifier;
					this->_typeId = copy._typeId;
				}
				return *this;
			}

			inline ResourceRef & ResourceRef::operator=(ResourceRef && move) noexcept
			{
				if (this != &move) {
					this->_identifier = std::move(move._identifier);
					this->_typeId = move._typeId;
				}
				return *this;
			}

			template <class T>
			auto ResourceRef::is() const -> bool
			{
				return typeid(T).hash_code() == this->_identifierId && dynamic_cast<const ResourceHandler<T> *>(this);
			}

		/*	template <class T>
			auto & ResourceRef::to()
			{
				assert(typeid(T).hash_code() == this->_typeId, "The ResourceRef does not reference this type of resource.");
				return dynamic_cast<ResourceHandler<T> &>(*this);
			}

			template <class T>
			const auto & ResourceRef::to() const
			{
				assert(typeid(T).hash_code() == this->_typeId, "The ResourceRef does not reference this type of resource.");
				return dynamic_cast<const ResourceHandler<T> &>(*this);
			}*/

			template <class T>
			auto ResourceRef::to() const
			{
				assert(typeid(T).hash_code() == this->_typeId, "The ResourceRef does not reference this type of resource.");
				return ServiceResourceLocator::getService().getResource<T>(this->_identifier);
			}

			inline auto ResourceRef::getIdentifier() const noexcept -> const std::string &
			{
				return this->_identifier;
			}
		} // namespace resource
	} // namespace core
} // namespace ece