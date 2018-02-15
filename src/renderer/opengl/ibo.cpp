#include "renderer/opengl/ibo.hpp"

namespace ece
{
	IBO::IBO(): _handle(0)
	{
		this->_handle = OpenGL::genBuffers();
	}
}