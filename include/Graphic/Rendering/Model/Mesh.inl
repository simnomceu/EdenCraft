#include "Mesh.hpp"
namespace ece
{
	inline const std::vector<FastVertex3D> & Mesh::getVertices() const { return this->vertices; }

	inline const std::vector<FastVertex3D> & Mesh::getColors() const { return this->colors; }

	inline const unsigned int Mesh::size() const { return this->vertices.size(); }
}