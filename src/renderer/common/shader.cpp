#include "renderer/common/shader.hpp"

namespace ece
{
	Shader::Shader() : _handle(0)
	{
		this->_handle = OpenGL::createProgram();
	}

	void Shader::setStage(ShaderStage & shader)
	{
		if (shader.isCompilationRequired()) {
			shader.compile();
		}
		OpenGL::attachShader(this->_handle, shader.getHandle());
		shader.terminate();
	}

	void Shader::link()
	{
		OpenGL::linkProgram(this->_handle);
	}

	void Shader::use() const
	{
		OpenGL::useProgram(this->_handle);
	}
}