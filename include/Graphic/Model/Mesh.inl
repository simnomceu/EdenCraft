namespace ece
{
	inline const unsigned int Mesh::size() const { return this->vertices.size(); }

	inline std::vector<FloatVertex3u> Mesh::getPositions() const { return this->vertices; }

	inline std::vector<FloatVertex3u> Mesh::getColors() const { return this->colors; }

	inline std::vector<FloatVertex3u> Mesh::getNormals() const { return std::vector<FloatVertex3u>(); }

	inline std::vector<int> Mesh::getIndices() const { return std::vector<int>(); }
}