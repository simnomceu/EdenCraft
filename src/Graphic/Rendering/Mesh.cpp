#include "Rendering\Mesh.hpp"

#include <iostream>

namespace ece
{
	void Mesh::addVertices(const std::vector<float>& vertices, const std::vector<int> & index)
	{
		this->vertices = vertices;
		this->index = index;
		this->computeCenter();
	}

	void Mesh::addColors(const std::vector<float>& colors)
	{
		this->colors = colors;
		if (this->colors.size() == 0) {
			this->colors.insert(this->colors.begin(), this->vertices.size(), 1.0f);
		}
	}

	void Mesh::reset()
	{
		this->vertices.clear();
		this->computeCenter();
	}

	void Mesh::computeCenter()
	{
		// TODO: have a look at mutable variable to move this in the getCenter() const getter, with using a cache to store center computed.
		float xMin = this->vertices[0], xMax = this->vertices[0],
			yMin = this->vertices[1], yMax = this->vertices[1],
			zMin = this->vertices[2], zMax = this->vertices[2];

		int size = (int)this->vertices.size();
		for (int i = 3; i < size; ++i) {
			if (i % 3 == 0) {
				if (this->vertices[i] < xMin) {
					xMin = this->vertices[i];
				}
				if (this->vertices[i] > xMax) {
					xMax = this->vertices[i];
				}
			}
			else if (i % 3 == 1) {
				if (this->vertices[i] < yMin) {
					yMin = this->vertices[i];
				}
				if (this->vertices[i] > yMax) {
					yMax = this->vertices[i];
				}
			}
			else if (i % 3 == 2) {
				if (this->vertices[i] < zMin) {
					zMin = this->vertices[i];
				}
				if (this->vertices[i] > zMax) {
					zMax = this->vertices[i];
				}
			}
		}

		this->center[0] = (xMin + xMax) / 2;
		this->center[1] = (yMin + yMax) / 2;
		this->center[2] = (zMin + zMax) / 2;
	}
}