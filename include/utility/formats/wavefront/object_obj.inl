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

namespace ece
{
	namespace utility
	{
		namespace formats
		{
			namespace wavefront
			{
				inline ObjectOBJ::ObjectOBJ(const std::string & name) noexcept : _o(name), _vertexIndexing(),  _faceFormat{ 0, ObjectOBJ::Clockwise::NON_SIGNIFICANT }, 
																				_f(), _groups(), _currentGroups() {}

				inline auto ObjectOBJ::getName() const { return this->_o; }

				inline void ObjectOBJ::setFaceFormat(const FaceFormat & format) { this->_faceFormat = format; }
				inline void ObjectOBJ::setFaceFormat(FaceFormat && format) { this->_faceFormat = std::move(format); }

				inline auto & ObjectOBJ::getFaceFormat() { return this->_faceFormat; }

				inline auto ObjectOBJ::getFaceFormat() const { return this->_faceFormat; }

				inline void ObjectOBJ::addFace(const ObjectOBJ::Face & f)
				{
					std::for_each(f.begin(), f.end(), [this](auto & vertex) {
						this->_vertexIndexing.try_emplace(vertex, this->_vertexIndexing.size());
					});

					this->_f.push_back(f);
					if (this->_currentGroups.empty()) {
						this->addGroup("default");
					}

					std::for_each(this->_currentGroups.begin(), this->_currentGroups.end(), [this](auto group) {
						this->_groups[group].faces.push_back(this->_f.size() - 1);
					});
				}

				inline void ObjectOBJ::addFace(ObjectOBJ::Face && f)
				{
					std::for_each(f.begin(), f.end(), [this](auto & vertex) {
						this->_vertexIndexing.try_emplace(vertex, this->_vertexIndexing.size());
					});

					this->_f.push_back(std::move(f));
					if (this->_currentGroups.empty()) {
						this->addGroup("default");
					}

					std::for_each(this->_currentGroups.begin(), this->_currentGroups.end(), [this](auto group) {
						this->_groups[group].faces.push_back(this->_f.size() - 1);
					});
				}

				inline auto ObjectOBJ::getNumberOfFaces() const { return this->_f.size(); }

				inline auto & ObjectOBJ::getFaces() { return this->_f; }

				inline auto ObjectOBJ::getFaces() const { return this->_f; }

				inline void ObjectOBJ::resetCurrentGroups() { this->_currentGroups.clear(); }

				inline void ObjectOBJ::addGroup(const std::string & group)
				{
					if (this->_groups.find(group) != this->_groups.end()) {
						this->_groups[group] = FaceGroup{ group, "", {} };
					}
					this->_currentGroups.push_back(group);
				}

				inline void ObjectOBJ::setMaterial(const std::string & material)
				{
					if (this->_currentGroups.empty()) {
						this->addGroup("default");
					}
					std::for_each(this->_currentGroups.begin(), this->_currentGroups.end(), [this, material](auto group) {
						this->_groups[group].material = material;
					});
				}

				inline auto ObjectOBJ::getNumberOfGroups() const { return this->_groups.size(); }

				inline auto & ObjectOBJ::getGroups() { return this->_groups; }

				inline auto ObjectOBJ::getGroups() const { return this->_groups; }

				inline auto ObjectOBJ::getVertexIndice(const ObjectOBJ::Vertex & vertex) { return this->_vertexIndexing[vertex]; }
			} // namespace wavefront
		} // namespace formats
	} // namespace utility
} // namespace ece