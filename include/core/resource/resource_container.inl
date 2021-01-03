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

namespace ece
{
	namespace core
	{
		namespace resource
		{
			template <class T>
			inline constexpr ResourceContainer<T>::ResourceContainer(): _resources(), _ids(1) {}

			template <class T>
			void ResourceContainer<T>::add(const std::string & path, const std::shared_ptr<T> & resource)
			{
				auto loaded = std::find_if(this->_resources.begin(), this->_resources.end(), [path](const auto & el) -> bool { return el.second.path == path; });
				if (loaded == this->_resources.end()) {
					auto wrapper = ResourceWrapper{ this->_ids.next(), path, resource, std::chrono::system_clock::now(), std::chrono::system_clock::now(), false };
					this->_resources.emplace(std::make_pair(wrapper.id, wrapper));
				}
			}
			
			template <class T>
			void ResourceContainer<T>::add(const std::vector<std::pair<std::string, std::shared_ptr<T>>> & resources)
			{
				for (auto [path, resource] : resources) {
					this->add(path, resource);
				}
			}

			template <class T>
			void ResourceContainer<T>::remove(ece::size_t id)
			{
				this->_resources.erase(id);
				this->_ids.restack(id);
			}

			template <class T>
			void ResourceContainer<T>::remove(const std::vector<ece::size_t> & ids)
			{
				for (auto id : ids) {
					this->remove(id);
				}
			}

			template <class T>
			void ResourceContainer<T>::clear()
			{
				this->_resources.clear();
				this->_ids = ece::UniqueID<ece::size_t>();
			}

			template <class T>
			auto ResourceContainer<T>::getResource(ece::size_t id) -> std::weak_ptr<T>
			{
				if (!this->isResourceLoaded(id)) {
					throw std::runtime_error("There is no resource " + std::to_string(id) + " of type " + std::to_string(typeid(T).hash_code()) + ".");
				}
				this->_resources[id].lastAccess = std::chrono::system_clock::now();
				return this->_resources[id].content;
			}

			template <class T>
			auto ResourceContainer<T>::isResourceLoaded(ece::size_t id) const -> bool
			{
				return this->_resources.find(id) != this->_resources.end();
			}

			template <class T>
			auto ResourceContainer<T>::getResourceId(const std::string & path) -> ece::size_t
			{
				auto it = std::find_if(this->_resources.begin(), this->_resources.end(), [path](const auto & el) { return el.second.path == path; });
				return (it != this->_resources.end()) ? it->second.id : std::numeric_limits<ece::size_t>::max();
				// TODO: returning std::numeric_limits<ece::size_t>::max() is working, unless the number of resources reaches this value.
			}
		} // namespace resource
	} // namespace core
} // namespace ece