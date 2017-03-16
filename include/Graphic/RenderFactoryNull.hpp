#ifndef RENDERFACTORYNULL_HPP
#define RENDERFACTORYNULL_HPP

#include "RenderFactory.hpp"

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

#include "RenderFactoryNull.inl"

#endif // RENDERFACTORYNULL_HPP