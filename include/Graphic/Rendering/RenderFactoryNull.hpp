#ifndef RENDERFACTORYNULL_HPP
#define RENDERFACTORYNULL_HPP

#include "Core\Graphic\Rendering\RenderFactory.hpp"

namespace ece
{
	class RenderFactoryNull: public RenderFactory
	{
	public:
		RenderFactoryNull() = default;

		virtual Program * createProgram();
		virtual Shader * createShader(const Shader::ShaderType & type);
	};

	inline Program * RenderFactoryNull::createProgram() { return nullptr; }
	inline Shader * RenderFactoryNull::createShader(const Shader::ShaderType & type) { return nullptr; }
}

#endif // RENDERFACTORYNULL_HPP