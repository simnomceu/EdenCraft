#ifndef PARSERMODELDAT_HPP
#define PARSERMODELDAT_HPP

#include <vector>
#include "Type.hpp"

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

		//inline const std::vector<float> & getVertices();
		//inline const std::vector<float> & getColors();
		inline const std::vector<FastVertex3D> & getVertices();
		inline const std::vector<FastVertex3D> & getColors();

	private:
		std::vector<FastVertex3D> vertices;
		std::vector<FastVertex3D> colors;
	};
}

#include "File\ParserModelDAT.inl"

#endif // PARSERMODELDAT_HPP