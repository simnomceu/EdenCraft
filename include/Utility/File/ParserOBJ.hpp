#ifndef PARSEROBJ_HPP
#define PARSEROBJ_HPP

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

#include "File\ParserOBJ.inl"

#endif // PARSEROBJ_HPP