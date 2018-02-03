#ifndef ENHANCED_SHADER_HPP
#define ENHANCED_SHADER_HPP

#include "renderer/common/shader.hpp"

namespace ece
{
	class EnhancedShader: public Shader
	{
	public:
		EnhancedShader() = default;
		EnhancedShader(const EnhancedShader & copy) noexcept = default;
		EnhancedShader(EnhancedShader && move) noexcept = default;

		~EnhancedShader() noexcept = default;

		EnhancedShader & operator=(const EnhancedShader & copy) noexcept = default;
		EnhancedShader & operator=(EnhancedShader && move) noexcept = default;

		virtual void setStage(ShaderStage & shader);
	};
}

#endif // ENHANCED_SHADER_HPP