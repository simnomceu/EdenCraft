#include "Core\Graphic\Rendering\RenderFactoryGL.hpp"

#include "Core\Graphic\Rendering\ProgramGL.hpp"
#include "Core\Graphic\Rendering\ShaderGL.hpp"

#include <iostream>

namespace ece
{
	RenderFactoryGL::RenderFactoryGL(): RenderFactory()
	{
	}

	RenderFactoryGL::~RenderFactoryGL()
	{
	}

	Program * RenderFactoryGL::createProgram()
	{
		std::cout << "create" << std::endl;
		return new ProgramGL();
	}

	Shader * RenderFactoryGL::createShader(const Shader::ShaderType & type)
	{
		return new ShaderGL(type);
	}
}