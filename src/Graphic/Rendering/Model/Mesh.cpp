#include "Rendering\Model\Mesh.hpp"

#include "Util\File\ParserModelDAT.hpp"
#include "Util\Debug\FileException.hpp"

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

	const Box3D & Mesh::getAABB() const
	{
		auto xMin = std::min_element(this->vertices.begin(), this->vertices.end(), [](const FastVertex3D &  a, const FastVertex3D & b) { return a.x < b.x; })->x;
		auto xMax = std::max_element(this->vertices.begin(), this->vertices.end(), [](const FastVertex3D &  a, const FastVertex3D & b) { return a.x < b.x; })->x;

		auto yMin = std::min_element(this->vertices.begin(), this->vertices.end(), [](const FastVertex3D &  a, const FastVertex3D & b) { return a.y < b.y; })->y;
		auto yMax = std::max_element(this->vertices.begin(), this->vertices.end(), [](const FastVertex3D &  a, const FastVertex3D & b) { return a.y < b.y; })->y;

		auto zMin = std::min_element(this->vertices.begin(), this->vertices.end(), [](const FastVertex3D &  a, const FastVertex3D & b) { return a.z < b.z; })->z;
		auto zMax = std::max_element(this->vertices.begin(), this->vertices.end(), [](const FastVertex3D &  a, const FastVertex3D & b) { return a.z < b.z; })->z;

		return Box3D(FastVertex3D{ xMin, yMin, zMin }, FastVertex3D{ xMax, yMax, zMax });
	}
}