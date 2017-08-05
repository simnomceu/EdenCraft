#ifndef PARSERMODELDAT_HPP
#define PARSERMODELDAT_HPP

#include <vector>
#include "Mathematics\Vertex3u.hpp"

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
		inline const std::vector<FloatVertex3u> & getVertices();
		inline const std::vector<FloatVertex3u> & getColors();

	private:
		std::vector<FloatVertex3u> vertices;
		std::vector<FloatVertex3u> colors;
	};
}

#include "File\ParserModelDAT.inl"

#endif // PARSERMODELDAT_HPP