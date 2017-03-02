namespace ece
{
	inline Mesh::Mesh(const GLenum mode) : vertices(), center{ 0.0f, 0.0f, 0.0f }, modeRender(mode) {}

	inline const std::vector<float>& Mesh::getVertices() { return this->vertices; }

	inline const std::vector<int>& Mesh::getVerticesIndex() { return this->index; }

	inline const std::vector<float>& Mesh::getColors() { return this->colors; }

	inline const int Mesh::getNumberOfVertices() const { return (int)this->vertices.size() / 3; }

	inline const int Mesh::getNumberOfIndex() const { return (int)this->index.size(); }

	inline GLenum Mesh::getModeRender() const { return this->modeRender; }
}