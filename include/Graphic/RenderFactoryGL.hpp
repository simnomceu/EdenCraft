#ifndef RENDERFACTORYGL_HPP
#define RENDERFACTORYGL_HPP

#include "RenderFactory.hpp"

namespace ece
{
	class RenderFactoryGL : public RenderFactory
	{
	public:
		RenderFactoryGL() = default;
		~RenderFactoryGL() = default;

		inline virtual Program * createProgram() override;
		inline virtual Shader * createShader(const Shader::ShaderType & type) override;
	};
}

#include "RenderFactoryGL.inl"

#endif // RENDERFACTORY_HPP