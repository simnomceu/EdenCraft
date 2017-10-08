#ifndef PARSER_OBJ_HPP
#define PARSER_OBJ_HPP

#include <string>
#include <vector>

namespace ece
{
	// TODO add parser MKL

	class ParserOBJ
	{
	public:
		ParserOBJ() = default;

		void open(const std::string & pathname);

		inline const std::vector<float> & getVertices();
		inline const std::vector<float> & getTextures();
		inline const std::vector<float> & getNormales();
		inline const std::vector<int> & getFaces();

	private:
		std::vector<float> vertices;
		std::vector<float> textures;
		std::vector<float> normales;
		std::vector<int> faces;
	};
}

#include "file/parser_obj.inl"

#endif // PARSER_OBJ_HPP