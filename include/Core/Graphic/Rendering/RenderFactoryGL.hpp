#ifndef RENDERFACTORYGL_HPP
#define RENDERFACTORYGL_HPP

#include "Core\Graphic\Rendering\RenderFactory.hpp"

namespace ece
{
	class RenderFactoryGL : public RenderFactory
	{
	public:
		RenderFactoryGL();
		~RenderFactoryGL();

		virtual Program * createProgram();
		virtual Shader * createShader(const Shader::ShaderType & type);
	};
}

#endif // RENDERFACTORY_HPP