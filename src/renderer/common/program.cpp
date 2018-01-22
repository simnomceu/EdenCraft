#include "renderer/common/program.hpp"

namespace ece
{
	Program::Program() : _handle(0)
	{
		this->_handle = OpenGL::createProgram();
	}

	void Program::addShader(Shader & shader)
	{
		if (shader.isCompilationRequired()) {
			shader.compile();
		}
		OpenGL::attachShader(this->_handle, shader.getHandle());
		shader.terminate();
	}

	void Program::link()
	{
		OpenGL::linkProgram(this->_handle);
	}

	void Program::use() const
	{
		OpenGL::useProgram(this->_handle);
	}
}