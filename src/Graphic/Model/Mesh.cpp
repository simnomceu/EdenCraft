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
		auto xMin = std::min_element(this->vertices.begin(), this->vertices.end(), [](const FloatVertex3D &  a, const FloatVertex3D & b){ return a.position[X] < b.position[X]; })->position[X];
		auto xMax = std::max_element(this->vertices.begin(), this->vertices.end(), [](const FloatVertex3D &  a, const FloatVertex3D & b) { return a.position[X] < b.position[X]; })->position[X];

		auto yMin = std::min_element(this->vertices.begin(), this->vertices.end(), [](const FloatVertex3D &  a, const FloatVertex3D & b) { return a.position[Y] < b.position[Y]; })->position[Y];
		auto yMax = std::max_element(this->vertices.begin(), this->vertices.end(), [](const FloatVertex3D &  a, const FloatVertex3D & b) { return a.position[Y] < b.position[Y]; })->position[Y];

		auto zMin = std::min_element(this->vertices.begin(), this->vertices.end(), [](const FloatVertex3D &  a, const FloatVertex3D & b) { return a.position[Z] < b.position[Z]; })->position[Z];
		auto zMax = std::max_element(this->vertices.begin(), this->vertices.end(), [](const FloatVertex3D &  a, const FloatVertex3D & b) { return a.position[Z] < b.position[Z]; })->position[Z];

		return Box3D(FloatVertex3D{ xMin, yMin, zMin }, FloatVertex3D{ xMax, yMax, zMax });
	}
}