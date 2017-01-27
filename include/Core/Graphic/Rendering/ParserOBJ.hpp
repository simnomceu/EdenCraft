#ifndef PARSEROBJ_HPP
#define PARSEROBJ_HPP

#include <string>

#include "Core\Graphic\Rendering\Mesh.hpp"

namespace ece
{
	// TODO add parser MKL

	class ParserOBJ
	{
	public:
		ParserOBJ() = default;

		Mesh open(const std::string & pathname);

	};
}

#endif // PARSEROBJ_HPP