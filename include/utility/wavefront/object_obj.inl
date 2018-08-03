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
		namespace wavefront
		{
			inline ObjectOBJ::ObjectOBJ(const std::string & name) noexcept: _o(name), _v(), _vt(), _vn(), _vp(), _f() {}

			inline const std::string & ObjectOBJ::getName() const { return this->_o; }

			inline void ObjectOBJ::addVertex(const FloatVector4u & v) { this->_v.push_back(v); }

			inline void ObjectOBJ::addVertex(FloatVector4u && v) { this->_v.push_back(std::move(v)); }

			inline int ObjectOBJ::getNumberOfVertices() const { return this->_v.size(); }

			inline std::vector<FloatVector4u> & ObjectOBJ::getVertices() { return this->_v; }

			inline const std::vector<FloatVector4u> & ObjectOBJ::getVertices() const { return this->_v; }

			inline void ObjectOBJ::addVertexTexture(const FloatVector2u & vt) { this->_vt.push_back(vt); }

			inline void ObjectOBJ::addVertexTexture(FloatVector2u && vt) { this->_vt.push_back(std::move(vt)); }

			inline int ObjectOBJ::getNumberOfVerticesTexture() const { return this->_vt.size(); }

			inline std::vector<FloatVector2u> & ObjectOBJ::getVerticesTexture() { return this->_vt; }

			inline const std::vector<FloatVector2u> & ObjectOBJ::getVerticesTexture() const { return this->_vt; }

			inline void ObjectOBJ::addVertexNormal(const FloatVector3u & vn) { this->_vn.push_back(vn); }

			inline void ObjectOBJ::addVertexNormal(FloatVector3u && vn) { this->_vn.push_back(std::move(vn)); }

			inline int ObjectOBJ::getNumberOfVerticesNormal() const { return this->_vn.size(); }

			inline std::vector<FloatVector3u> & ObjectOBJ::getVerticesNormal() { return this->_vn; }

			inline const std::vector<FloatVector3u> & ObjectOBJ::getVerticesNormal() const { return this->_vn; }

			inline void ObjectOBJ::addVertexSpaceParameter(const FloatVector3u & vp) { this->_vp.push_back(vp); }

			inline void ObjectOBJ::addVertexSpaceParameter(FloatVector3u && vp) { this->_vp.push_back(std::move(vp)); }

			inline int ObjectOBJ::getNumberOfVerticesSpaceParameter() const { return this->_vp.size(); }

			inline std::vector<FloatVector3u> & ObjectOBJ::getVerticesSpaceParameter() { return this->_vp; }

			inline const std::vector<FloatVector3u> & ObjectOBJ::getVerticesSpaceParameter() const { return this->_vp; }

			inline void ObjectOBJ::addFace(const ObjectOBJ::Face & f) { this->_f.push_back(f); }

			inline void ObjectOBJ::addFace(ObjectOBJ::Face && f) { this->_f.push_back(std::move(f)); }

			inline int ObjectOBJ::getNumberOfFaces() const { return this->_f.size(); }

			inline std::vector<ObjectOBJ::Face> & ObjectOBJ::getFaces() { return this->_f; }

			inline const std::vector<ObjectOBJ::Face> & ObjectOBJ::getFaces() const { return this->_f; }
		} // namespace wavefront
	} // namespace utility
} // namespace ece
