#include "graphic/model/mesh.hpp"

#include "utility/debug/exception.hpp"

#include <iostream>
#include <algorithm>

namespace ece
{
	bool Mesh::loadFromFile(const std::string & /*filename*/)
	{
		// TODO: use a resource manager to load only if not already loaded. 
		// if modification on a resource loaded, copy as a new resource.
		bool result = true;
		/*ParserModelDAT parser;
		try {
			parser.open(filename);
			this->vertices = parser.getVertices();
			this->colors = parser.getColors();
		}
		catch (FileException & e) {
			std::cerr << e.what() << std::endl;
			this->vertices.clear();
			this->colors.clear();
			result = false;
		}*/
		return result;
	}

	Box3D Mesh::getAABB() const
	{
		auto xMin = (*std::min_element(this->_vertices.begin(), this->_vertices.end(), [](const FloatVector3u &  a, const FloatVector3u & b){ return a[0] < b[0]; }))[0];
		auto xMax = (*std::max_element(this->_vertices.begin(), this->_vertices.end(), [](const FloatVector3u &  a, const FloatVector3u & b) { return a[0] < b[0]; }))[0];

		auto yMin = (*std::min_element(this->_vertices.begin(), this->_vertices.end(), [](const FloatVector3u &  a, const FloatVector3u & b) { return a[1] < b[1]; }))[1];
		auto yMax = (*std::max_element(this->_vertices.begin(), this->_vertices.end(), [](const FloatVector3u &  a, const FloatVector3u & b) { return a[1] < b[1]; }))[1];

		auto zMin = (*std::min_element(this->_vertices.begin(), this->_vertices.end(), [](const FloatVector3u &  a, const FloatVector3u & b) { return a[2] < b[2]; }))[2];
		auto zMax = (*std::max_element(this->_vertices.begin(), this->_vertices.end(), [](const FloatVector3u &  a, const FloatVector3u & b) { return a[2] < b[2]; }))[2];

		return Box3D(FloatVector3u{ xMin, yMin, zMin }, FloatVector3u{ xMax, yMax, zMax });
	}
}