#include "Core\Graphic\Rendering\Mesh.hpp"

#include <iostream>

namespace ece
{
	Mesh::Mesh(const GLenum mode) : vertices(),
		center{ 0.0f, 0.0f, 0.0f }, modeRender(mode)
	{
	}

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

	const std::vector<float>& Mesh::getVertices()
	{
		return this->vertices;
	}

	const std::vector<int>& Mesh::getVerticesIndex()
	{
		return this->index;
	}

	const std::vector<float>& Mesh::getColors()
	{
		return this->colors;
	}

	const int Mesh::getNumberOfVertices() const
	{
		return (int)this->vertices.size() / 3;
	}

	const int Mesh::getNumberOfIndex() const
	{
		return (int)this->index.size();
	}

	void Mesh::reset()
	{
		this->vertices.clear();
		this->computeCenter();
	}

	GLenum Mesh::getModeRender() const
	{
		return this->modeRender;
	}

	void Mesh::computeCenter()
	{
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