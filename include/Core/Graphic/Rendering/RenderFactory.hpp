#ifndef RENDERFACTORY_HPP
#define RENDERFACTORY_HPP

#include "Core\Graphic\Rendering\Shader.hpp"

namespace ece
{
	class Program;

	class RenderFactory
	{
	public:
		virtual ~RenderFactory() = 0;

		virtual Program * createProgram() = 0;
		virtual Shader * createShader(const Shader::ShaderType & type) = 0;
	};

	inline RenderFactory::~RenderFactory() {}
}

#endif // RENDERFACTORY_HPP