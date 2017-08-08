#ifndef PARSER_MODEL_DAT_HPP
#define PARSER_MODEL_DAT_HPP

#include <vector>
#include "mathematics\vertex3u.hpp"

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

#include "file\parser_model_dat.inl"

#endif // PARSER_MODEL_DAT_HPP