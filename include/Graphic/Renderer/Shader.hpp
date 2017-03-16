#ifndef SHADER_HPP
#define SHADER_HPP

namespace ece
{
	class Shader
	{
	public:
		Shader() = default;
		Shader(const Shader & copy) = default;
		Shader(Shader && move) = default;

		~Shader() = default;

		Shader & operator=(const Shader & copy) = default;
		Shader & operator=(Shader && move) = default;
	};
}

#endif // SHADER_HPP