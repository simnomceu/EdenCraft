#ifndef SHADERGL_HPP
#define SHADERGL_HPP

#include "Shader.hpp"

namespace ece
{
	class ShaderGL : public Shader
	{
	public:
		ShaderGL() = delete;
		ShaderGL(const ShaderType & type);
		ShaderGL(ShaderGL && move) = default;

		~ShaderGL();

		ShaderGL & operator=(ShaderGL && move) = default;

		virtual void loadFromFile(const std::string & filename) override;
		virtual void loadFromString(const std::string & sourceCode) override;

		virtual void compile() override;

		virtual void reset() override;

	private:
		std::string source;
	};
}

#endif // SHADERGL_HPP