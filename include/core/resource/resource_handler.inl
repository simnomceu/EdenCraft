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

#include "core/resource/service_resource.hpp"

namespace ece
{
	namespace core
	{
		namespace resource
		{
			inline ResourceHandler::ResourceHandler() noexcept : _id(), _typeId(), _path() {}

			template <class T>
			inline ResourceHandler::ResourceHandler(const Resource<T> & resource) noexcept : _id(resource.id), _typeId(typeid(T).hash_code()), _path(resource.path) {}

			inline ResourceHandler::ResourceHandler(ece::size_t id, std::size_t typeId, const std::string & path) noexcept : _id(id), _typeId(typeId), _path(path) {}

			inline ResourceHandler::ResourceHandler(const ResourceHandler & copy) noexcept : _id(copy._id), _typeId(copy._typeId), _path(copy._path) {}

			inline ResourceHandler::ResourceHandler(ResourceHandler && move) noexcept : _id(std::move(move._id)), _typeId(std::move(move._typeId)), _path(std::move(move._path)) {}

			inline ResourceHandler::~ResourceHandler() noexcept {}

			inline ResourceHandler & ResourceHandler::operator=(const ResourceHandler & copy) noexcept
			{
				if (&copy != this) {
					this->_id = copy._id;
					this->_typeId = copy._typeId;
					this->_path = copy._path;
				}
				return *this;
			}

			inline ResourceHandler & ResourceHandler::operator=(ResourceHandler && move) noexcept
			{
				if (&move != this) {
					this->_id = std::move(move._id);
					this->_typeId = std::move(move._typeId);
					this->_path = std::move(move._path);
				}
				return *this;
			}

			template <class T>
			inline auto ResourceHandler::is() const noexcept -> bool
			{
				return typeid(T).hash_code() == this->_typeId;
			}

			template <class T>
			inline auto ResourceHandler::get() const -> Resource<T>
			{
				if (!this->is<T>()) {
					throw std::runtime_error("The resource " + this->_path + " is of type " + std::to_string(this->_typeId) + " and you try to access it as a " + std::to_string(typeid(T).hash_code()));
				}
				return Resource<T>{ this->_id, this->_path, ServiceResourceLocator::getService().getResource<T>(this->_id) };
			}

			inline auto ResourceHandler::getID() const noexcept -> ece::size_t { return this->_id; }

			inline auto ResourceHandler::getTypeID() const noexcept -> std::size_t { return this->_typeId; }

			inline auto ResourceHandler::getPath() const noexcept -> const std::string & { return this->_path; }

			inline auto ResourceHandler::isDirty() const noexcept -> bool
			{
				return this->_id == 0 && this->_typeId == 0 && this->_path.empty();
			}
		} // namespace resource
	} // namespace core
} // namespace ece