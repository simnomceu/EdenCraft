#include "Core\Graphic\Rendering\RenderFactoryGL.hpp"

#include "Core\Graphic\Rendering\ProgramGL.hpp"
#include "Core\Graphic\Rendering\ShaderGL.hpp"

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
		return new ProgramGL();
	}

	Shader * RenderFactoryGL::createShader(const Shader::ShaderType & type)
	{
		return new ShaderGL(type);
	}
}