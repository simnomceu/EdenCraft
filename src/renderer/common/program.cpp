#include "renderer/common/program.hpp"

namespace ece
{
	Program::Program() : handle(0)
	{
		this->handle = OpenGL::createProgram();
	}

	void Program::addShader(Shader & shader)
	{
		if (shader.isCompilationRequired()) {
			shader.compile();
		}
		OpenGL::attachShader(this->handle, shader.getHandle());
		shader.terminate();
	}

	void Program::link()
	{
		OpenGL::linkProgram(this->handle);
	}

	void Program::use() const
	{
		OpenGL::useProgram(this->handle);
	}
}