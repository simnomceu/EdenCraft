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

		const std::vector<float> & getVertices();
		const std::vector<float> & getTextures();
		const std::vector<float> & getNormales();
		const std::vector<int> & getFaces();

	private:
		std::vector<float> vertices;
		std::vector<float> textures;
		std::vector<float> normales;
		std::vector<int> faces;
	};
}

#endif // PARSEROBJ_HPP