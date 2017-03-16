#ifndef SHADEREFFECT_HPP
#define SHADEREFFECT_HPP

namespace ece
{
	class ShaderEffect
	{
	public:
		ShaderEffect() = default;
		ShaderEffect(const ShaderEffect & copy) = default;
		ShaderEffect(ShaderEffect && move) = default;

		~ShaderEffect() = default;

		ShaderEffect & operator=(const ShaderEffect & copy) = default;
		ShaderEffect & operator=(ShaderEffect && move) = default;
	};
}

#endif // SHADEREFFECT_HPP