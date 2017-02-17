#ifndef SHADERGL_HPP
#define SHADERGL_HPP

#include "Core\Graphic\Rendering\Shader.hpp"

namespace ece
{
	class ShaderGL : public Shader
	{
	public:
		ShaderGL() = delete;
		ShaderGL(const Shader::ShaderType & type);
		ShaderGL(ShaderGL && move) = default;

		~ShaderGL();

		ShaderGL & operator=(ShaderGL && move) = default;

		virtual void loadFromFile(const std::string & filename);
		virtual void loadFromString(const std::string & sourceCode);

		virtual void compile();

		virtual void reset();

	private:
		std::string source;
	};
}

#endif // SHADERGL_HPP