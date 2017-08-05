#include "Model\Mesh.hpp"

#include "File\ParserModelDAT.hpp"
#include "Debug\Exception.hpp"

#include <iostream>
#include <algorithm>

namespace ece
{
	bool Mesh::loadFromFile(const std::string & filename)
	{
		// TODO: use a resource manager to load only if not already loaded. 
		// if modification on a resource loaded, copy as a new resource.
		bool result = true;
		ParserModelDAT parser;
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
		}
		return result;
	}

	Box3D Mesh::getAABB() const
	{
		auto xMin = (*std::min_element(this->vertices.begin(), this->vertices.end(), [](const FloatVertex3u &  a, const FloatVertex3u & b){ return a[X] < b[X]; }))[X];
		auto xMax = (*std::max_element(this->vertices.begin(), this->vertices.end(), [](const FloatVertex3u &  a, const FloatVertex3u & b) { return a[X] < b[X]; }))[X];

		auto yMin = (*std::min_element(this->vertices.begin(), this->vertices.end(), [](const FloatVertex3u &  a, const FloatVertex3u & b) { return a[Y] < b[Y]; }))[Y];
		auto yMax = (*std::max_element(this->vertices.begin(), this->vertices.end(), [](const FloatVertex3u &  a, const FloatVertex3u & b) { return a[Y] < b[Y]; }))[Y];

		auto zMin = (*std::min_element(this->vertices.begin(), this->vertices.end(), [](const FloatVertex3u &  a, const FloatVertex3u & b) { return a[Z] < b[Z]; }))[Z];
		auto zMax = (*std::max_element(this->vertices.begin(), this->vertices.end(), [](const FloatVertex3u &  a, const FloatVertex3u & b) { return a[Z] < b[Z]; }))[Z];

		return Box3D(FloatVertex3u(xMin, yMin, zMin), FloatVertex3u(xMax, yMax, zMax));
	}
}