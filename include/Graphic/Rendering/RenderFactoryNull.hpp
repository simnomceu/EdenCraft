#ifndef RENDERFACTORYNULL_HPP
#define RENDERFACTORYNULL_HPP

#include "Rendering\RenderFactory.hpp"

namespace ece
{
	class RenderFactoryNull: public RenderFactory
	{
	public:
		RenderFactoryNull() = default;

		inline virtual Program * createProgram() override;
		inline virtual Shader * createShader(const ShaderType & type) override;
	};
}

#include "Rendering\RenderFactoryNull.inl"

#endif // RENDERFACTORYNULL_HPP