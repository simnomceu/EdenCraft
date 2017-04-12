namespace ece
{
	inline const std::vector<float>& ParserOBJ::getVertices() { return this->vertices; }

	inline const std::vector<float>& ParserOBJ::getTextures() { return this->textures; }

	inline const std::vector<float>& ParserOBJ::getNormales() { return this->normales; }

	inline const std::vector<int>& ParserOBJ::getFaces() { return this->faces; }
}