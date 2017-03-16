#ifndef RENDERFACTORY_HPP
#define RENDERFACTORY_HPP

#include "Shader.hpp"

namespace ece
{
	class Program;

	class RenderFactory
	{
	public:
		inline virtual ~RenderFactory() = 0;

		virtual Program * createProgram() = 0;
		virtual Shader * createShader(const ShaderType & type) = 0;
	};
}

#include "Rendering\RenderFactory.inl"

#endif // RENDERFACTORY_HPP