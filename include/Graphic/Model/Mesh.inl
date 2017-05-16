namespace ece
{
	inline const unsigned int Mesh::size() const { return this->vertices.size(); }

	inline std::vector<FloatVertex3D> Mesh::getPositions() const { return this->vertices; }

	inline std::vector<FloatVertex3D> Mesh::getColors() const { return this->colors; }

	inline std::vector<FloatVertex3D> Mesh::getNormals() const { return std::vector<FloatVertex3D>(); }

	inline std::vector<int> Mesh::getIndices() const { return std::vector<int>(); }
}