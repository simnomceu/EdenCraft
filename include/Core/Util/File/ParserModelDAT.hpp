#ifndef PARSERMODELDAT_HPP
#define PARSERMODELDAT_HPP

#include <vector>

namespace ece
{
	class ParserModelDAT
	{
	public:
		ParserModelDAT() = default;
		ParserModelDAT(const ParserModelDAT & copy) = default;
		ParserModelDAT(ParserModelDAT && move) = default;

		~ParserModelDAT() = default;

		ParserModelDAT & operator=(const ParserModelDAT & copy) = default;
		ParserModelDAT & operator=(ParserModelDAT && move) = default;

		void open(const std::string & filename);

		inline const std::vector<float> & getVertices();
		inline const std::vector<float> & getColors();

	private:
		std::vector<float> vertices;
		std::vector<float> colors;
	};
}

#include "Util\File\ParserModelDAT.inl"

#endif // PARSERMODELDAT_HPP