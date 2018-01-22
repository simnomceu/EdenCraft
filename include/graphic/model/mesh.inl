namespace ece
{
	inline const unsigned int Mesh::size() const { return this->_vertices.size(); }

	inline std::vector<FloatVertex3u> Mesh::getPositions() const { return this->_vertices; }

	inline std::vector<FloatVertex3u> Mesh::getColors() const { return this->_colors; }

	inline std::vector<FloatVertex3u> Mesh::getNormals() const { return std::vector<FloatVertex3u>(); }

	inline std::vector<int> Mesh::getIndices() const { return std::vector<int>(); }
}