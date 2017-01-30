#ifndef PARSEROBJ_HPP
#define PARSEROBJ_HPP

#include <string>

#include "Core\Graphic\Rendering\Object.hpp"

namespace ece
{
	// TODO add parser MKL

	class ParserOBJ
	{
	public:
		ParserOBJ() = default;

		Object open(const std::string & pathname);

	};
}

#endif // PARSEROBJ_HPP