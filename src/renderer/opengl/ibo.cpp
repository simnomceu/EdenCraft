#include "renderer/opengl/ibo.hpp"

namespace ece
{
	IBO::IBO(): _handle(0)
	{
		OpenGL::genBuffers(this->_handle);
	}
}