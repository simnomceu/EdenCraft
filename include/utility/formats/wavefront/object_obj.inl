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
				inline ObjectOBJ::ObjectOBJ(const std::string & name) noexcept : _o(name), _v(), _vt(), _vn(), _vp(), _faceFormat{ 0, ObjectOBJ::Clockwise::NON_SIGNIFICANT }, _f(), _groups(), _currentGroups() {}

				inline const std::string & ObjectOBJ::getName() const { return this->_o; }

				inline void ObjectOBJ::addVertex(const FloatVector4u & v) { this->_v.push_back(v); }

				inline void ObjectOBJ::addVertex(FloatVector4u && v) { this->_v.push_back(std::move(v)); }

				inline std::size_t ObjectOBJ::getNumberOfVertices() const { return this->_v.size(); }

				inline std::vector<FloatVector4u> & ObjectOBJ::getVertices() { return this->_v; }

				inline const std::vector<FloatVector4u> & ObjectOBJ::getVertices() const { return this->_v; }

				inline void ObjectOBJ::addVertexTexture(const FloatVector2u & vt) { this->_vt.push_back(vt); }

				inline void ObjectOBJ::addVertexTexture(FloatVector2u && vt) { this->_vt.push_back(std::move(vt)); }

				inline std::size_t ObjectOBJ::getNumberOfVerticesTexture() const { return this->_vt.size(); }

				inline std::vector<FloatVector2u> & ObjectOBJ::getVerticesTexture() { return this->_vt; }

				inline const std::vector<FloatVector2u> & ObjectOBJ::getVerticesTexture() const { return this->_vt; }

				inline void ObjectOBJ::addVertexNormal(const FloatVector3u & vn) { this->_vn.push_back(vn); }

				inline void ObjectOBJ::addVertexNormal(FloatVector3u && vn) { this->_vn.push_back(std::move(vn)); }

				inline std::size_t ObjectOBJ::getNumberOfVerticesNormal() const { return this->_vn.size(); }

				inline std::vector<FloatVector3u> & ObjectOBJ::getVerticesNormal() { return this->_vn; }

				inline const std::vector<FloatVector3u> & ObjectOBJ::getVerticesNormal() const { return this->_vn; }

				inline void ObjectOBJ::addVertexSpaceParameter(const FloatVector3u & vp) { this->_vp.push_back(vp); }

				inline void ObjectOBJ::addVertexSpaceParameter(FloatVector3u && vp) { this->_vp.push_back(std::move(vp)); }

				inline std::size_t ObjectOBJ::getNumberOfVerticesSpaceParameter() const { return this->_vp.size(); }

				inline std::vector<FloatVector3u> & ObjectOBJ::getVerticesSpaceParameter() { return this->_vp; }

				inline const std::vector<FloatVector3u> & ObjectOBJ::getVerticesSpaceParameter() const { return this->_vp; }

				inline void ObjectOBJ::setFaceFormat(const FaceFormat & format) { this->_faceFormat = format; }
				inline void ObjectOBJ::setFaceFormat(FaceFormat && format) { this->_faceFormat = std::move(format); }

				inline ObjectOBJ::FaceFormat & ObjectOBJ::getFaceFormat() { return this->_faceFormat; }

				inline const ObjectOBJ::FaceFormat & ObjectOBJ::getFaceFormat() const { return this->_faceFormat; }

				inline void ObjectOBJ::addFace(const ObjectOBJ::Face & f)
				{
					this->_f.push_back(f);
					if (this->_currentGroups.empty()) {
						this->addGroup("default");
					}

					for (auto group : this->_currentGroups) {
						auto it = std::find_if(this->_groups.begin(), this->_groups.end(), [group](auto element) {return element.name == group; });
						it->faces.push_back(this->_f.size() - 1);
					}
				}

				inline void ObjectOBJ::addFace(ObjectOBJ::Face && f)
				{
					this->_f.push_back(std::move(f));
					if (this->_currentGroups.empty()) {
						this->addGroup("default");
					}

					for (auto group : this->_currentGroups) {
						auto it = std::find_if(this->_groups.begin(), this->_groups.end(), [group](auto element) {return element.name == group; });
						it->faces.push_back(this->_f.size() - 1);
					}
				}

				inline std::size_t ObjectOBJ::getNumberOfFaces() const { return this->_f.size(); }

				inline std::vector<ObjectOBJ::Face> & ObjectOBJ::getFaces() { return this->_f; }

				inline const std::vector<ObjectOBJ::Face> & ObjectOBJ::getFaces() const { return this->_f; }

				inline void ObjectOBJ::resetCurrentGroups() { this->_currentGroups.clear(); }

				inline void ObjectOBJ::addGroup(const std::string & group)
				{
					if (std::find_if(this->_groups.begin(), this->_groups.end(), [group](auto element) {return element.name == group; }) == this->_groups.end()) {
						this->_groups.push_back({ group, "", {} });
					}
					this->_currentGroups.push_back(group);
				}

				inline void ObjectOBJ::setMaterial(const std::string & material)
				{
					if (this->_currentGroups.empty()) {
						this->addGroup("default");
					}
					for (auto group : this->_currentGroups) {
						auto it = std::find_if(this->_groups.begin(), this->_groups.end(), [group](auto element) {return element.name == group; });
						it->material = material;
					}
				}

				inline std::size_t ObjectOBJ::getNumberOfGroups() const { return this->_groups.size(); }

				inline std::vector<ObjectOBJ::FaceGroup> & ObjectOBJ::getGroups() { return this->_groups; }

				inline const std::vector<ObjectOBJ::FaceGroup> & ObjectOBJ::getGroups() const { return this->_groups; }
			} // namespace wavefront
		} // namespace formats
	} // namespace utility
} // namespace ece
